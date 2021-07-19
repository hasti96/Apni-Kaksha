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

map<int, vector<int>> vertical {};

void verticalOrder(Node* root, int hd)
{
	if(root == nullptr)
		return;

	vertical[hd].push_back(root->data);
	verticalOrder(root->left, hd-1);
	verticalOrder(root->right, hd+1);	
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

	verticalOrder(root, 0);

	for(auto i: vertical)
		for(auto j: i.second)
			printf("%d ", j);

	printf("\n");

	for(auto i: vertical) 
	{	
		printf("%d : ", i.first);
		for(auto j: i.second) 
		{

			printf("%d ",j);
		}
	printf("\n");
	}

	return 0;
}