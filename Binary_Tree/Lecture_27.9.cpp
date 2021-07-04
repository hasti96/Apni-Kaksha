/*
*Find if the binary tree is height balanced......
*/

#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data):data(data), left(nullptr), right(nullptr) {}
	Node(int data, Node* left, Node* right):data(data), left(left), right(right) {}
};

class Solution
{
public:
	static bool isBalance(Node* root, int* height)
	{
		if(root == nullptr)
		{
			*height = 0;
			return true;
		}

		int lh = 0 ; int rh = 0;

		if(!isBalance(root->left, &lh))
			return false;

		if(!isBalance(root->right, &rh))
			return false;

		*height = max(lh, rh) + 1;

		return abs(lh - rh <= 1);
	}
};

int main(int argc, char const *argv[])
{
	Node* left 	= new Node(2, new Node(4), new Node(5));
	Node* right = new Node(3, new Node(6), new Node(7));
	Node* root	= new Node(1, left, right);

	int height = 0;

	left->left->left = new Node(8, new Node(9), nullptr);

	if(Solution::isBalance(root, &height))
	{
		cout << "Balanced Tree" << endl;
	}
	else
	{
		cout << "unBalanced Tree" << endl;	
	}

	return 0;
}