/*
*	Sum Replacement in Binary Tree | C++ Placement Course | Lecture 27.8
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

class SumReplacement
{
public:
	static int doSumRplmt(Node*& root)
	{
		if(root == nullptr)
			return 0;
		
		root->data = root->data + doSumRplmt(root->left) + doSumRplmt(root->right);

		return root->data;
	}

	static void inorderPrint(Node* root)
    {
        if(root)
        {
        	// cout<< root->data << " ";
            inorderPrint(root->left);
            cout<< root->data << " ";
            inorderPrint(root->right);
        }
    }
};

int main(int argc, char const *argv[])
{
	Node* left 	= new Node(2, new Node(4), new Node(5));
	Node* right = new Node(3, new Node(6), new Node(7));
	Node* root	= new Node(1, left, right);

	SumReplacement::inorderPrint(root);
	printf("\nAfter SumReplacement : ");
	printf("Root Summation : [%d]\n",SumReplacement::doSumRplmt(root));
	SumReplacement::inorderPrint(root);
	printf("\n");

	return 0;
}