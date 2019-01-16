#include <iostream>
#include <map>

using namespace std;

int node_count;
map<char, struct node> m;

struct node
{
	char left = NULL;
	char right = NULL;
};

// root - left - right
void preorder(char current)
{
	if (current != NULL)
	{
		cout << current;
		preorder(m[current].left);
		preorder(m[current].right);
	}
}

// left - root - right
void inorder(char current)
{
	if (current != NULL)
	{
		inorder(m[current].left);
		cout << current;
		inorder(m[current].right);
	}
}

// left - right - root
void postorder(char current)
{
	if (current != NULL)
	{
		postorder(m[current].left);
		postorder(m[current].right);
		cout << current;
	}
}

int main(void)
{
	cin >> node_count;
	for (int i = 0; i < node_count; i++)
	{
		char parent;
		char left, right;
		node new_node;

		cin >> parent >> left >> right;

		if (left != '.')
		{
			new_node.left = left;
		}
		if (right != '.')
		{
			new_node.right = right;
		}
		m[parent] = new_node;
	}

	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	cout << endl;
}