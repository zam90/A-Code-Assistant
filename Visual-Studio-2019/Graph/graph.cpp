#include <queue>
#include <stack>
#include <iostream>
using namespace std;

//节点遍历情况
enum visitCondition
{
	no,    //未访问
	visiting,    //正在访问，邻接点还没访问完
	yes    //访问完毕
};

template<typename VertexType, typename InfoType>
class Graph
{
public:
	Graph(int vertexNum) :m_vertexNum(vertexNum), m_arcNum(0)
	{
		for (int i = 0; i < MAX_VERTEX_NUM; ++i)
		{
			m_vertices[i].firstArc = nullptr;
		}
	}

	//输出图的信息
	void Display()
	{
		for (int i = 0; i < m_vertexNum; ++i)
		{
			cout << "第" << i + 1 << "个节点为" << m_vertices[i].data << " 邻接表为：";
			ArcNode* node = m_vertices[i].firstArc;
			while (node)
			{
				cout << "->" << m_vertices[node->vertexIndex].data;
				node = node->next;
			}
			cout << endl;
		}
	}

	void BFS()
	{
		for (int i = 0; i < m_vertexNum; ++i)
		{
			m_vertices[i].visitconditions = no;
		}
		cout << "图的广度优先遍历为：";
		BFS(&m_vertices[0]);
		cout << endl;
	}

	void DFS()
	{
		for (int i = 0; i < m_vertexNum; ++i)
		{
			m_vertices[i].visitconditions = no;
		}
		cout << "图的深度优先遍历为：";
		DFS(&m_vertices[0]);
		cout << endl;
	}

	//创建无向无权图
	void Create()
	{
		InitVertices();
		cout << "请分别输入每条边的起始节点和终止节点:" << endl;
		int head, tail;
		while (cin >> head >> tail)
		{
			//无向图head->tail tail->head插入两次
			Insert(head, tail, 0);
			Insert(tail, head, 0);
		}
	}

	void FindMinRoad(int v1, int v2, int k)
	{

	}

private:
	struct ArcNode
	{
		int vertexIndex;        //该路径指向的顶点位置
		struct ArcNode* next;    //指向下一个路径
		InfoType info;            //该路径的相关信息，如权重等
	};

	struct Vertex
	{
		VertexType data;    //顶点信息
		ArcNode* firstArc;    //指向第一条依附该节点路径的指针
		visitCondition visitconditions;    //访问情况
	};

	//最大顶点数
	static const int MAX_VERTEX_NUM = 20;
	Vertex m_vertices[MAX_VERTEX_NUM];    //顶点列表
	int m_vertexNum;    //当前顶点数量
	int m_arcNum;        //当前路径数量
private:
	//初始化顶点列表
	void InitVertices()
	{
		cout << "请输入每个顶点的关键字" << endl;
		VertexType data;
		for (int i = 0; i < m_vertexNum; ++i)
		{
			cin >> data;
			m_vertices[i].data = data;
		}
	}
	//插入一个表节点
	void Insert(int headVertex, int tailVertex, InfoType info)
	{
		//构造一个邻接表节点，即创建一条路径
		ArcNode* newNode = new ArcNode;
		newNode->info = info;
		newNode->next = nullptr;
		newNode->vertexIndex = tailVertex;

		//找到邻接表的最后一个节点
		ArcNode* lastNode = m_vertices[headVertex].firstArc;
		if (lastNode == nullptr)
			m_vertices[headVertex].firstArc = newNode;
		else
		{
			while (lastNode->next)
			{
				lastNode = lastNode->next;
			}
			lastNode->next = newNode;
		}
		++m_arcNum;
	}

	void BFS(Vertex* vertex)
	{
		vertex->visitconditions = visiting;
		queue<Vertex*> vertices;
		vertices.push(vertex);
		while (!vertices.empty())
		{
			Vertex* curVertex = vertices.front();
			vertices.pop();
			cout << curVertex->data << "->";
			ArcNode* node = curVertex->firstArc;
			while (node)
			{
				Vertex* tmpVertex = &m_vertices[node->vertexIndex];
				if (tmpVertex->visitconditions == no)
				{
					tmpVertex->visitconditions = visiting;
					vertices.push(tmpVertex);
				}
				node = node->next;
			}
			curVertex->visitconditions = yes;
		}
	}

	void DFS(Vertex* vertex)
	{
		vertex->visitconditions = visiting;
		stack<Vertex*> vertices;
		vertices.push(vertex);
		while (!vertices.empty())
		{
			Vertex* curVertex = vertices.top();
			vertices.pop();
			cout << curVertex->data << "->";
			ArcNode* node = curVertex->firstArc;
			while (node)
			{
				Vertex* tmp = &m_vertices[node->vertexIndex];
				if (tmp->visitconditions == no)
				{
					tmp->visitconditions = visiting;
					vertices.push(tmp);
				}
				node = node->next;
			}
			curVertex->visitconditions = yes;
		}
	}
};

int main()
{
	int  vertexNum, v1, v2 , k;
	cout << "请输入要创建的图的节点数：";
	cin >> vertexNum;
	Graph<char, int> g(vertexNum);
	g.Create();
	g.Display();
	g.BFS();
	g.DFS();
	//cout << "请依次输入需要寻找简单路径的起点和重点v1 v2和路径长度k：";
	//cin >> v1 >> v2 >> k;
	//g.FindMinRoad(v1, v2, k);
}