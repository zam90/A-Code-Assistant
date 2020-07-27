// Honer Code
// ����ϵر�֤��
// ���Լ��������������������ӷ�������Ƶ���������й�����
// ��������������У���������ʲô���Ѷ�������ˣ���ô���ҽ��ڳ���ʵϰ������
// ��ϸ���о��������������⣬�Լ����˸��ҵ���ʾ��
// �ҵĳ������з������õ�����������ĵ�֮����
// ����̲ġ����ñʼǡ����ϵ�Դ�����Լ������ο����ϵĴ����,
// �Ҷ��Ѿ��ڳ����ע����������ע�������õĳ�����
// �Ҵ�δû��Ϯ�����˵ĳ���Ҳû�е��ñ��˵ĳ���
// �������޸�ʽ�ĳ�Ϯ����ԭ�ⲻ���ĳ�Ϯ��
// �ұ�д������򣬴���û�����Ҫȥ�ƻ���������������ϵͳ��������ת��
// ǩ���ˣ�����1801 �ž��� 2018011140

// �����ĵ�
// �ļ����ƣ�graph.cpp
// ��Ŀ���ƣ�Graph
// �����ߣ��ž���
// ����ʱ�䣺2019.11.19
// ����޸�ʱ�䣺2019.11.21
// ���ܣ�ͼ�Ĺ��������������

#include <queue>
#include <stack>
#include <iostream>
using namespace std;

//�ڵ�������
enum visitCondition
{
	no,    //δ����
	visiting,    //���ڷ��ʣ��ڽӵ㻹û������
	yes    //�������
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

	//���ͼ����Ϣ
	void Display()
	{
		for (int i = 0; i < m_vertexNum; ++i)
		{
			cout << "��" << i + 1 << "���ڵ�Ϊ" << m_vertices[i].data << " �ڽӱ�Ϊ��";
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
		cout << "ͼ�Ĺ�����ȱ���Ϊ��";
		BFS(&m_vertices[0]);
		cout << endl;
	}

	void DFS()
	{
		for (int i = 0; i < m_vertexNum; ++i)
		{
			m_vertices[i].visitconditions = no;
		}
		cout << "ͼ��������ȱ���Ϊ��";
		DFS(&m_vertices[0]);
		cout << endl;
	}

	//����������Ȩͼ
	void Create()
	{
		InitVertices();
		cout << "��ֱ�����ÿ���ߵ���ʼ�ڵ����ֹ�ڵ�:" << endl;
		int head, tail;
		while (cin >> head >> tail)
		{
			//����ͼhead->tail tail->head��������
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
		int vertexIndex;        //��·��ָ��Ķ���λ��
		struct ArcNode* next;    //ָ����һ��·��
		InfoType info;            //��·���������Ϣ����Ȩ�ص�
	};

	struct Vertex
	{
		VertexType data;    //������Ϣ
		ArcNode* firstArc;    //ָ���һ�������ýڵ�·����ָ��
		visitCondition visitconditions;    //�������
	};

	//��󶥵���
	static const int MAX_VERTEX_NUM = 20;
	Vertex m_vertices[MAX_VERTEX_NUM];    //�����б�
	int m_vertexNum;    //��ǰ��������
	int m_arcNum;        //��ǰ·������
private:
	//��ʼ�������б�
	void InitVertices()
	{
		cout << "������ÿ������Ĺؼ���" << endl;
		VertexType data;
		for (int i = 0; i < m_vertexNum; ++i)
		{
			cin >> data;
			m_vertices[i].data = data;
		}
	}
	//����һ����ڵ�
	void Insert(int headVertex, int tailVertex, InfoType info)
	{
		//����һ���ڽӱ�ڵ㣬������һ��·��
		ArcNode* newNode = new ArcNode;
		newNode->info = info;
		newNode->next = nullptr;
		newNode->vertexIndex = tailVertex;

		//�ҵ��ڽӱ�����һ���ڵ�
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
	cout << "������Ҫ������ͼ�Ľڵ�����";
	cin >> vertexNum;
	Graph<char, int> g(vertexNum);
	g.Create();
	g.Display();
	g.BFS();
	g.DFS();
	//cout << "������������ҪѰ�Ҽ�·���������ص�v1 v2��·������k��";
	//cin >> v1 >> v2 >> k;
	//g.FindMinRoad(v1, v2, k);
}