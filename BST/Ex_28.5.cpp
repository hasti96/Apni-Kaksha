/*
	Build Balanced BST from Sorted Array | C++ Placement Course | Lecture 28.5
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

Node* buildBSTFromSortedArray(int arr[], int start, int end)
{
	if(start > end)
		return nullptr;

	int mid = (start + end) / 2;
	Node* root = new Node(arr[mid]);

	root->left = buildBSTFromSortedArray(arr, start, mid - 1);
	root->right = buildBSTFromSortedArray(arr, mid + 1, end);

	return root;
}

void inorderPrint(Node* root)
{
	if(root)
	{
		inorderPrint(root->left);
		cout<< root->data << " ";
		inorderPrint(root->right);
	}
}
int main()
{
	int arr[] = {3,4,5,6,7,8,9,10,11};

	Node* root = buildBSTFromSortedArray(arr, 0, 8);

	inorderPrint(root);

	return 0;
}