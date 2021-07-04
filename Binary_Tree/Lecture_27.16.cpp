/*
	Max Sum Path from One Node to Another in Binary Tree | C++ Placement Course | Lecture 27.16
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

int maxSumPath(Node* root)
{
	if(root == nullptr || root->data < 0)
		return 0;

	return root->data + max(maxSumPath(root->left), maxSumPath(root->right));
}

int main(int argc, char* argv[])
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

	cout<< maxSumPath(root) << endl;
	return 0;
}