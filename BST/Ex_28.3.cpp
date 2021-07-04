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

class pair
{
public:
	int min;
	int max;

	pair(): min(INT_MIN), max(INT_MAX) {}
	pair(int min, int max): min(min), max(max) {}

};

Node* buildBSTFromPreOrder(int preorder[], int* preorderIdx, 
	int key, int min, int max, int n)
{
	if(*preorderIdx >= n)
	{
		return nullptr;
	}

	Node* root = nullptr;
	if(key > min and key < max)
	{
		root = new Node(key);
		*preorderIdx +=1;

		if(*preorderIdx < n)
		{
			root->left = buildBSTFromPreOrder(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
		}

		if(*preorderIdx < n)
		{
			root->right = buildBSTFromPreOrder(preorder, preorderIdx, preorder[*preorderIdx],key, max, n);
		}
	}

	return root;
}

int main()
{

	/*
			10
		   /  \
		  2   13
		 /    /
		1    11

	*/

	int preorder[] = {10,2,1,13,11};
	int n = 5;
	int preorderIdx = 0;

	Node* root = buildBSTFromPreOrder(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
	
	return 0;
}