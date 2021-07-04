/*
	Identical Binary Search Tree | C++ Placement Course | Lecture 28.8
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

bool isIdentical(Node* root1, Node* root2)
{
	if(root1 == nullptr and root2 == nullptr)
		return true;

	if(root1 != nullptr and root2 != nullptr)
	{
		if(root1->data == root2->data)
			return isIdentical(root1->left, root2->left)
			 	and isIdentical(root1->right, root2->right); 
		else 
			return false;
	}
	else
		return false;
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

	Node* left1 	= new Node(2, new Node(4), new Node(5));
	Node* right1	= new Node(3, new Node(6), new Node(7));
	Node* root1		= new Node(1, left1, right1);

	cout << isIdentical(root, root1);

	return 0;
}