/*
	Largest Binary Search Tree in BT | C++ Placement Course | Lecture 28.10
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

class Info
{
public:

	int m_size;
	int m_max;
	int m_min;
	int m_ans;
	bool m_isBst;

	Info(): m_min(0), m_max(0), m_size(0), m_ans(0), m_isBst(false) {}
	Info(int min, int max, int size, int ans, bool isBst):
		m_min(min), m_max(max), m_size(size), m_ans(ans), m_isBst(isBst) {}
};

Info largestBSTinBT(Node* root)
{
	if(root == nullptr)
	{
		return {0, INT_MIN, INT_MAX, 0, true};
	}

	if(root->left == nullptr and root->right == nullptr)
	{
		return {1, root->data, root->data, 1, true};
	}

	Info leftInfo = largestBSTinBT(root->left);
	Info rightInfo = largestBSTinBT(root->right);

	Info curr;
	curr.m_size = (1 + leftInfo.m_size + rightInfo.m_size);

	if(leftInfo.m_isBst and rightInfo.m_isBst and 
		leftInfo.m_max < root->data and rightInfo.m_min > root->data)
	{
		curr.m_min = min(leftInfo.m_min, min(rightInfo.m_min, root->data));
		curr.m_max = max(rightInfo.m_max, min(leftInfo.m_max, root->data));

		curr.m_ans = curr.m_size;
		curr.m_isBst = true;

		return curr;
	}

	curr.m_ans = max(leftInfo.m_ans, rightInfo.m_ans);
	curr.m_isBst = false;

	return curr;
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

	return 0;
}