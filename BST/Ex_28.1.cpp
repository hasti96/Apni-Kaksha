/*
	Binary Search Trees | Introduction & Build | C++ Placement Course | Lecture 28.1
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

void buildBST(Node*& root, int n)
{
	if(root == nullptr)
		root = new Node(n);

	if(n < root->data)
		buildBST(root->left, n);

	if(n > root->data)
		buildBST(root->right, n);
}

int main(int argc, char* argv[])
{	
	/*
		5
	   / \
	  1   7
	   \ 
	    3
	   / \ 
	  2   4

	*/

	vector<int> arr = {5,1,3,4,2,7};
	Node* root = nullptr;

	for(auto i: arr)
		buildBST(root, i);

	cout<< root->right->data << endl;

	return 0;
}