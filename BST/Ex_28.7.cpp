/*
	Zig Zag Traversal Binary Search Tree | C++ Placement Course | Lecture 28.7
*/

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data): data(data), left(nullptr), right(nullptr) {}
	Node(int data, Node* left, Node* right): data(data), left(left), right(right) {}

};

void zigzagTraversal(Node* root)
{
	if(root)
	{
		stack<Node*> s1;
		stack<Node*> s2; 

		stack<Node*>* curLevel = &s1;
		stack<Node*>* nextLevel = &s2;
		
		curLevel->push(root);
		bool leftToRight = true;

		while(!curLevel->empty())
		{
			Node* node = curLevel->top();
			curLevel->pop();
			cout<< node->data << " ";

			if(leftToRight)
			{
				if(node->left)
					nextLevel->push(node->left);

				if(node->right)
					nextLevel->push(node->right);
			}
			else
			{
				if(node->right)
					nextLevel->push(node->right);
				if(node->left)
					nextLevel->push(node->left);
			}

			if(curLevel->empty())
			{
				leftToRight = !leftToRight;
				swap(curLevel, nextLevel);
			}
		}
	}
}

int main()
{
	/*
		1
	   / \
	  2   3
	 / \ / \
	4  5 6  7

	*/

	Node* left 	= new Node(2, new Node(4), new Node(5));
	Node* right = new Node(3, new Node(6), new Node(7));
	Node* root	= new Node(1, left, right);

	zigzagTraversal(root);

	return 0;
}