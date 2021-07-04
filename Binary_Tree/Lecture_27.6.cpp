#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data):data(data), left(nullptr), right(nullptr){}
	Node(int data, Node* left, Node* right): data(data), left(left), right(right) {}

};

class Solution
{
public:
	static int countNodes(Node* root)
	{
		if(root == nullptr)
			return 0;
		return countNodes(root->left) + countNodes(root->right) + 1;
	}

	static int sumNodes(Node* root)
	{
		if(root == nullptr)
			return 0;
		return sumNodes(root->left) + sumNodes(root->right) + root->data;
	}
};

int main(int argc, char* argv[])
{
	Node* left 	= new Node(2, new Node(4), new Node(5));
	Node* right = new Node(3, new Node(6), new Node(7));
	Node* root	= new Node(1, left, right);

	cout << "Numbers of Nodes : " << Solution::countNodes(root) << endl;
	cout << "Sum of all the Nodes : " << Solution::sumNodes(root) << endl;
	return 0;
}