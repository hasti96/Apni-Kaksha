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

Node* searchBinarTree(Node*& root, int data)
{
	if(root->data == data)
		return root;

	if(data > root->data)
		return searchBinarTree(root->right, data);
	else
		return searchBinarTree(root->left, data);

	return nullptr;
}

Node* findInorderSucc(Node* root)
{
	Node* curr = root;
	while(curr and curr->left)
	{
		curr = curr->left;
	}
	return curr;
}

Node* searchAndDelete(Node*& root, int data)
{	
	if(data > root->data)
	{
		root->right = searchAndDelete(root->right, data);
		return root->right;
	}
	else if(data < root->data)
	{
		root->left = searchAndDelete(root->left, data);
		return root->left;
	}
	else
	{
		if(root->left == nullptr and root->right == nullptr)
		{
			delete root;
			return nullptr;
		}
		else if(root->left == nullptr or root->right == nullptr)
		{
			Node* tmp = root;
			root = root->right == nullptr ? root->left : root->right;
			delete tmp;
			return root;
		}
		
		Node* temp = findInorderSucc(root->right);
		swap(root->data, temp->data);
		root->right = searchAndDelete(root->right, data);
	}

	return root;
}

int main()
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

	printf("[%d]\n",searchBinarTree(root, 1)->data);
	printf("[%d]\n",searchAndDelete(root, 5)->data);

	return 0;
}