
//引入头文件
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<Windows.h>
#include<time.h>

//定义全局变量
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define Qu 2	//窗口数量

typedef int Status;

//事件和事件表
typedef struct QCuEvent
{
	int OccurTime;
	int NType;
	struct QCuEvent* next;
}QCuEvent, *EventList;

//链表节点
typedef struct LNode
{
	QCuEvent data;
	LNode* next;
}*Link, *Position;

//链表基本信息
struct LinkList
{
	Link head, tail;	//链表头尾
	int len;	//链表长度
};

//队列元素
typedef struct QCuElem
{
	int ArrivalTime;
	int Duration;
	struct QCuElem* next;
}QCuElem, *QEptr;

//队列节点
typedef struct QNode
{
	QCuElem data;
	QNode* next;
}*QueuePtr;

//窗口队列
struct LinkQueue
{
	QueuePtr front, rear;
};

//主要变量声明
typedef LinkList QCuEventList;
QCuEventList ev;
QCuEvent en;
QCuEvent et;
LinkQueue q[Qu];
QCuElem customer;
int TotalTime = 0, CustomerNum = 0;
int CloseTime = 540; int num = 0; int h = 0, m = 0;

Status InitList(LinkList& L)
{
	Link p;
	p = (Link)malloc(sizeof(LNode));
	if (p)
	{
		p->next = NULL;
		L.head = L.tail = p;
		L.len = 0;
		return OK;
	}
	else
		return ERROR;
}

//删除事件表中第一个事件
Status DelFirstEvent(LinkList& L, Link h, Link& q)
{
	q = h->next;
	if (q)
	{
		h->next = q->next;
		if (!h->next)
			L.tail = h;
		L.len--;
		return OK;
	}
	else
		return FALSE;
}

QCuEvent GetCurElem(Link p)
{
	return p->data;
}

Status ListEmpty(LinkList L)
{
	if (L.len)
		return FALSE;
	else
		return TRUE;
}

int ListLength(LinkList L)
{
	return L.len;
}

//获得头元素
Position GetQHead(LinkList L)
{
	return L.head;
}

//按时间顺序插入事件到列表
Status OrderInsert(LinkList& L, QCuEvent e, int(*comp)(QCuEvent, QCuEvent))
{
	Link o, p, q;
	q = L.head;
	p = q->next;
	while (p != NULL && comp(p->data, e) < 0)
	{
		q = p;
		p = p->next;
	}
	o = (Link)malloc(sizeof(LNode));
	o->data = e;
	q->next = o;
	o->next = p;
	L.len++;
	if (!p)
	L.tail = o;
	return OK;
}

//初始化窗口队列
Status InitCuQueue(LinkQueue& Q)
{
	if (!(Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode))))
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

//销毁队列
Status DestoryQueue(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

//求窗口队列长度
int QLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr p;
	p = Q.front;
	while (Q.rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

//获得队列中的第一个元素
Status GetQHead(LinkQueue Q, QCuElem& e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	return OK;
}

//进入队列
Status EnCuQueue(LinkQueue& Q, QCuElem e)
{
	QueuePtr p;
	if (!(p = (QueuePtr)malloc(sizeof(QNode))))
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

//删除队列中的元素
Status DeCuQueue(LinkQueue& Q, QCuElem& e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return OK;
}

//参照《数据结构C语言版》设置cmp函数，根据事件a，b的顺序返回相应的值
int cmp(QCuEvent a, QCuEvent b)
{
	if (a.OccurTime == b.OccurTime)
		return 0;
	else
		return  (a.OccurTime - b.OccurTime) / abs(a.OccurTime - b.OccurTime);
}

//银行开门
void OpenForDay()
{
	int i;
	InitList(ev);
	en.OccurTime = 0;
	en.NType = Qu;
	OrderInsert(ev, en, cmp);
	for (i = 0; i < Qu; ++i)
		InitCuQueue(q[i]);
}

//随机时间
void Random(int& d, int& i)
{
	srand((unsigned)time(0));//设置随机种子与当前时间相关，实现真正的随机
	d = rand() % 30 + 1;
	i = rand() % 5 + 1;
}

//寻找队最短的窗口
int MinCuQueue(LinkQueue Q[])
{
	int t[Qu];
	int i, k;
	for (i = 0; i < Qu; i++)
		t[i] = QLength(Q[i]);
	k = 0;
	for (i = 1; i < Qu; i++)
		if (t[i] < t[0])
		{
			t[0] = t[i];
			k = i;
		}
	return k;
}

//顾客到来
void CustomerArrived(LinkQueue Q[])
{
	QCuElem f;
	int durtime, intertime, i, j;
	//顾客到达处理
	CustomerNum++;
	//调用Random方法获取随机数
	Random(durtime, intertime);
	//插入事件到事件表
	et.OccurTime = en.OccurTime + intertime;
	et.NType = Qu;
	if (et.OccurTime < CloseTime)
		OrderInsert(ev, et, cmp);
	i = MinCuQueue(q);
	f.ArrivalTime = en.OccurTime;
	f.Duration = durtime;
	EnCuQueue(q[i], f);
	//插入离开事件
	if (QLength(q[i]) == 1)
	{
		et.OccurTime = en.OccurTime + durtime;
		et.NType = i;
		OrderInsert(ev, et, cmp);
	}
	h = et.OccurTime / 60 + 8;
	m = et.OccurTime % 60;
	printf("\n时间：%d:%d 客户%d 前往窗口：%d 此时银行内\n", h, m, CustomerNum, i + 1);
	for (i = 0; i < Qu; i++)
	{
		printf("窗口%d: ", i + 1);
		for (j = 0; j < QLength(Q[i]); j++) {
			num = j;
		}
		printf("现有%d人\n", num);
	}
}

//客户离开
void CustomerDeparture()
{
	int i;
	i = en.NType;

	DeCuQueue(q[i], customer);
	TotalTime += en.OccurTime - customer.ArrivalTime;
	if (!DestoryQueue(q[i]))
	{
		GetQHead(q[i], customer);
		et.OccurTime = en.OccurTime + customer.Duration;
		et.NType = i;
		OrderInsert(ev, et, cmp);
	}
}

//开始模拟
void WorkForDay(Link p) {
	while (!ListEmpty(ev))
		{
			DelFirstEvent(ev, GetQHead(ev), p);
			en.OccurTime = GetCurElem(p).OccurTime;
			en.NType = GetCurElem(p).NType;
			if (en.NType == Qu)
				CustomerArrived(q);
			else
				CustomerDeparture();
		}
}

//银行关门
void CloseForDay(Link p)
{
	printf("\n情况总结：\n顾客总数：%d\n所有顾客共耗时：%d 分钟\n平均每人耗时：%d 分钟\n", CustomerNum, TotalTime, TotalTime / CustomerNum);
}

int main()
{
	printf("欢迎来到银行模拟系统\nPowered By JingYu Zhang\n");
	Link p=NULL;
	OpenForDay();
	WorkForDay(p);
	CloseForDay(p);
	return 0;
}