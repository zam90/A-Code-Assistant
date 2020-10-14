
//����ͷ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<Windows.h>
#include<time.h>

//����ȫ�ֱ���
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define Qu 2	//��������

typedef int Status;

//�¼����¼���
typedef struct QCuEvent
{
	int OccurTime;
	int NType;
	struct QCuEvent* next;
}QCuEvent, *EventList;

//����ڵ�
typedef struct LNode
{
	QCuEvent data;
	LNode* next;
}*Link, *Position;

//���������Ϣ
struct LinkList
{
	Link head, tail;	//����ͷβ
	int len;	//������
};

//����Ԫ��
typedef struct QCuElem
{
	int ArrivalTime;
	int Duration;
	struct QCuElem* next;
}QCuElem, *QEptr;

//���нڵ�
typedef struct QNode
{
	QCuElem data;
	QNode* next;
}*QueuePtr;

//���ڶ���
struct LinkQueue
{
	QueuePtr front, rear;
};

//��Ҫ��������
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

//ɾ���¼����е�һ���¼�
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

//���ͷԪ��
Position GetQHead(LinkList L)
{
	return L.head;
}

//��ʱ��˳������¼����б�
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

//��ʼ�����ڶ���
Status InitCuQueue(LinkQueue& Q)
{
	if (!(Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode))))
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}

//���ٶ���
Status DestoryQueue(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

//�󴰿ڶ��г���
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

//��ö����еĵ�һ��Ԫ��
Status GetQHead(LinkQueue Q, QCuElem& e)
{
	QueuePtr p;
	if (Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;
	e = p->data;
	return OK;
}

//�������
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

//ɾ�������е�Ԫ��
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

//���ա����ݽṹC���԰桷����cmp�����������¼�a��b��˳�򷵻���Ӧ��ֵ
int cmp(QCuEvent a, QCuEvent b)
{
	if (a.OccurTime == b.OccurTime)
		return 0;
	else
		return  (a.OccurTime - b.OccurTime) / abs(a.OccurTime - b.OccurTime);
}

//���п���
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

//���ʱ��
void Random(int& d, int& i)
{
	srand((unsigned)time(0));//������������뵱ǰʱ����أ�ʵ�����������
	d = rand() % 30 + 1;
	i = rand() % 5 + 1;
}

//Ѱ�Ҷ���̵Ĵ���
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

//�˿͵���
void CustomerArrived(LinkQueue Q[])
{
	QCuElem f;
	int durtime, intertime, i, j;
	//�˿͵��ﴦ��
	CustomerNum++;
	//����Random������ȡ�����
	Random(durtime, intertime);
	//�����¼����¼���
	et.OccurTime = en.OccurTime + intertime;
	et.NType = Qu;
	if (et.OccurTime < CloseTime)
		OrderInsert(ev, et, cmp);
	i = MinCuQueue(q);
	f.ArrivalTime = en.OccurTime;
	f.Duration = durtime;
	EnCuQueue(q[i], f);
	//�����뿪�¼�
	if (QLength(q[i]) == 1)
	{
		et.OccurTime = en.OccurTime + durtime;
		et.NType = i;
		OrderInsert(ev, et, cmp);
	}
	h = et.OccurTime / 60 + 8;
	m = et.OccurTime % 60;
	printf("\nʱ�䣺%d:%d �ͻ�%d ǰ�����ڣ�%d ��ʱ������\n", h, m, CustomerNum, i + 1);
	for (i = 0; i < Qu; i++)
	{
		printf("����%d: ", i + 1);
		for (j = 0; j < QLength(Q[i]); j++) {
			num = j;
		}
		printf("����%d��\n", num);
	}
}

//�ͻ��뿪
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

//��ʼģ��
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

//���й���
void CloseForDay(Link p)
{
	printf("\n����ܽ᣺\n�˿�������%d\n���й˿͹���ʱ��%d ����\nƽ��ÿ�˺�ʱ��%d ����\n", CustomerNum, TotalTime, TotalTime / CustomerNum);
}

int main()
{
	printf("��ӭ��������ģ��ϵͳ\nPowered By JingYu Zhang\n");
	Link p=NULL;
	OpenForDay();
	WorkForDay(p);
	CloseForDay(p);
	return 0;
}