/*
* Left View of Binary Tree | C++ Placement Course | Lecture 27.10
*/

#include <bits/stdc++.h>

using namespace std;

class Node 
{
public:

	/*
		1
	   / \
	  2   3
	 / \ / \
	4  5 6  7

	*/
	int data;
	Node* left;
	Node* right;

	Node(int data) : data(data), left(nullptr), right(nullptr) {}
	Node(int data, Node* left, Node* right): data(data), left(left), right(right) {}
};

class BinaryTreeView
{
public:

	static void leftView(Node* root)
	{
		if(root)
		{
			queue<Node*> node_q;
			node_q.push(root);

			while(!node_q.empty())
			{
				int n = node_q.size();
				for(int i = 1; i <= n; i++)
				{
					Node* curr = node_q.front();
					node_q.pop();

					if(i == 1)
					{
						printf("%d ", curr->data);
					}

					if(curr)
					{
						// printf("%d ", curr->data);
						if(curr->left)
							node_q.push(curr->left);
						if(curr->right)
							node_q.push(curr->right);
					}
					else if(!node_q.empty())
					{
						node_q.push(nullptr);
					}
				}
			}
			printf("\n");
		}
	}
};


int main(int argc, char* argv[])
{	

	Node* left 	= new Node(2, new Node(4), new Node(5));
	Node* right = new Node(3, new Node(6), new Node(7));
	Node* root	= new Node(1, left, right);

	left->left->left = new Node(8, new Node(9), new Node(10));

	BinaryTreeView::leftView(root);

	return 0;
}