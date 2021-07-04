/*
	Check for BST
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

bool isBST(Node*& root, int min, int max)
{
	if(root)
	{	
		if(root->data > min and root->data < max)
			return isBST(root->left, min, root->data) and
					isBST(root->right, root->data, max);
		else
			return false;
	}

	return true;
}

int main()
{
	/*
			4
		   / \
		  2   7
		 /   / \
		1   3   8
	*/
	Node* left = new Node(2, new Node(1), nullptr);
	Node* right = new Node(7, new Node(3), new Node(8));
	Node* root = new Node(4, left, right);

	cout<< isBST(root, INT_MIN, INT_MAX) << endl;


	/*
			3
		   / \
		  2   7
		 /   / \
		1   4   8
	*/
	Node* left1 = new Node(2, new Node(1), nullptr);
	Node* right1 = new Node(7, new Node(4), new Node(8));
	Node* root1 = new Node(3, left1, right1);

	cout<< isBST(root1, INT_MIN, INT_MAX) << endl;

	return 0;
}