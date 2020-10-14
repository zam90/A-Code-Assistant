#include <iostream>	//导入IO库文件
#include <string.h>
#include <assert.h>
#include <stack>
#define DataType int
using namespace std;

typedef struct BSTreeNode
{
	struct BSTreeNode* _left;
	struct BSTreeNode* _right;
	DataType _data;
}BSTreeNode;

BSTreeNode* BuyTreeNode(DataType x) //创建节点
{
	BSTreeNode* node = (BSTreeNode*)malloc(sizeof(BSTreeNode));
	assert(node);

	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;

	return node;
}

int BSTreeNodeInsert(BSTreeNode** pptree, DataType x) //搜索树的插入
{
	BSTreeNode* parent = NULL;
	BSTreeNode* cur = *pptree;
	if (*pptree == NULL)
	{
		*pptree = BuyTreeNode(x);
		return 0;
	}
	while (cur)
	{
		parent = cur;
		if (cur->_data > x)
			cur = cur->_left;
		else if (cur->_data < x)
			cur = cur->_right;
		else
			return -1;
	}

	if (parent->_data > x)
		parent->_left = BuyTreeNode(x);
	else
		parent->_right = BuyTreeNode(x);

	return 0;
}

int BSTreeNodeInsertR(BSTreeNode** tree, DataType x) //搜索树的插入
{
	if (*tree == NULL)
	{
		*tree = BuyTreeNode(x);
		return 0;
	}

	if ((*tree)->_data > x)
		return BSTreeNodeInsertR(&(*tree)->_left, x);
	else if ((*tree)->_data < x)
		return BSTreeNodeInsertR(&(*tree)->_right, x);
	else
		return -1;
}

BSTreeNode* BSTreeNodeFind(BSTreeNode* tree, DataType x) //查找
{
	while (tree)
	{
		if (tree->_data == x)
			return tree;
		else if (tree->_data < x)
			tree = tree->_right;
		else
			tree = tree->_left;
	}

	return NULL;
}

BSTreeNode* BSTreeNodeFindR(BSTreeNode* tree, DataType x) //查找
{
	if (!tree)
		return NULL;

	if (tree->_data > x)
		BSTreeNodeFindR(tree->_left, x);
	else if (tree->_data < x)
		BSTreeNodeFindR(tree->_right, x);
	else
		return tree;
}

int BSTreeNodeDel(BSTreeNode** tree, DataType x) //删除
{

	BSTreeNode* cur = *tree;
	BSTreeNode* parent = *tree;
	BSTreeNode* del = NULL;

	while (cur)
	{
		if (cur->_data > x)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (cur->_data < x)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
		{
			del = cur;

			if (cur->_left == NULL) //1、左孩子为空
			{
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else if (parent->_right == cur)
					parent->_right = cur->_right;
				else if (parent == cur) //没有父亲节点时
					*tree = parent->_right;
			}
			else if (cur->_right == NULL) //2、右孩子为空
			{
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else if (parent->_right == cur)
					parent->_right = cur->_left;
				else if (parent == cur) //没有父亲节点时
					*tree = parent->_left;
			}
			else//3、左右孩子都不为空
			{
				BSTreeNode* sub = cur->_right;
				while (sub->_left)
				{
					parent = sub;
					sub = sub->_left;
				}

				del = sub;
				cur->_data = sub->_data;

				if (parent->_left == sub)
					parent->_left = sub->_right;
				else
					parent->_right = sub->_right;
			}

			free(del);
			del = NULL;
			return 0;

		}
	}

	return -1;
}

int main(){
	return 0;
}