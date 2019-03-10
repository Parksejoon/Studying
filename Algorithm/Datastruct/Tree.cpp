#include <stdio.h>
#include <queue>
#include <malloc.h>

#define MAX_SIZE 50

using namespace std;

typedef struct Node
{
	int value;
	Node* left = NULL;
	Node* right = NULL;
} Node;

typedef struct Tree
{
	int size = 0;
	Node* root = NULL;
} Tree;

Tree tree;

void insert(int n)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->value = n;
	new_node->left = NULL;
	new_node->right = NULL;

	if (tree.root == NULL)
	{
		tree.root = new_node;

		return;
	}

	queue<Node*> q;

	q.push(tree.root);
	while (true)
	{
		Node* cur_node = q.front(); q.pop();

		if (cur_node->left == NULL)
		{
			cur_node->left = new_node;

			return;
		}
		else
		{
			q.push(cur_node->left);
		}

		if (cur_node->right == NULL)
		{
			cur_node->right = new_node;

			return;
		}
		else
		{
			q.push(cur_node->right);
		}
	}
}

void pre_order(Node* node)
{
	if (node != NULL)
	{
		printf("%d ", node->value);
		pre_order(node->left);
		pre_order(node->right);
	}
}

void in_order(Node* node)
{
	if (node != NULL)
	{
		in_order(node->left);
		printf("%d ", node->value);
		in_order(node->right);
	}
}

void post_order(Node* node)
{
	if (node != NULL)
	{
		post_order(node->left);
		post_order(node->right);
		printf("%d ", node->value);
	}
}

void level_order()
{
	if (tree.root == NULL)
	{
		printf("Empty\n");
		return;
	}

	queue<Node*> q;

	q.push(tree.root);
	while (!q.empty())
	{
		Node* cur_node = q.front(); q.pop();

		printf("%d ", cur_node->value);

		if (cur_node->left)
		{
			q.push(cur_node->left);
		}

		if (cur_node->right)
		{
			q.push(cur_node->right);
		}
	}

	printf("\n");
}

int main(void)
{
	insert(0);
	insert(1);
	insert(2);
	insert(3);
	insert(4);

	level_order();

	pre_order(tree.root);
	printf("\n");
	in_order(tree.root);
	printf("\n");
	post_order(tree.root);
	printf("\n");
}