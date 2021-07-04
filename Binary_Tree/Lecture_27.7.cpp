/*
* Find the height of Binary Tree....
* Find the Diameter of Binary Tree....
*/

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data):data(data), left(nullptr), right(nullptr) {}
	Node(int data, Node* left, Node* right): data(data), left(left), right(right) {}	
};

class Solution
{
public:
	static int getHeight(Node* root)
	{
		if(root == nullptr)
			return 0;

		return max(getHeight(root->left), getHeight(root->right)) + 1;
	}

	static int getDiameter(Node* root) // O(n^2)
	{
		if(root == nullptr)
			return 0;

		int lheight = getHeight(root->left); 
		int rheight = getHeight(root->right);
		int currDiameter = lheight + rheight + 1;

		int ldiameter = getDiameter(root->left);
		int rdiameter = getDiameter(root->right);

		return max(currDiameter, max(ldiameter, rdiameter));
	}

	static int calcDiameter(Node* root, int* height) // O(n)
	{
		if(root == nullptr)
		{
			*height = 0;
			return 0;
		}	

		int lh = 0, rh = 0;
		int lDiameter = calcDiameter(root->left, &lh);
		int rDiameter = calcDiameter(root->right, &rh);

		int currDiameter = lh + rh + 1;
		*height = max(lh, rh) + 1;

		return max(currDiameter, max(lDiameter, rDiameter));
	}
};

int main(int argc, char const *argv[])
{
	Node* left 	= new Node(2, new Node(4), new Node(5));
	Node* right = new Node(3, new Node(6), new Node(7));
	Node* root	= new Node(1, left, right);

	left->left->left = new Node(8);

	cout<< "Height of the Binary Tree is : " << Solution::getHeight(root) << endl;

	cout<< "Diameter of the Binary Tree is : " << Solution::getDiameter(root) << endl;

	int height = 0;

	cout<< Solution::calcDiameter(root, &height) << endl;;

	return 0;
}