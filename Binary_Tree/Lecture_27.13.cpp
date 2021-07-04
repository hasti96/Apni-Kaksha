#include <bits/stdc++.h>

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

Node* flattenBinaryTree(Node*& root)
{
	if(root == nullptr)
		return nullptr;

	Node* left = flattenBinaryTree(root->left);
	Node* right = flattenBinaryTree(root->right);
	
	if(right == nullptr and left != nullptr)
	{
		root->right = root->left;
		root->left = nullptr;
	}
	else if (left != nullptr and right != nullptr)
	{
		Node* tmp = root->right;
		root->right = root->left;
		root->left = nullptr;

		Node* t = root->right;
		while(t->right != nullptr)
			t = t->right;
		t->right = tmp;
	}

	return root;
}

void flatten(Node* root)
{
	if(root->left != nullptr)
	{
		flatten(root->left);

		Node* tmp = root->right;
		root->right = root->left;
		root->left = nullptr;
		root->right->right = tmp;

	}
}

void displayFlattenBinaryTree(Node* root)
{	
	printf("Flattend Tree : [");
	while(root)
	{
		printf("%d ", root->data);
		root = root->right;
	}
	printf("]\n");
}

void preOrderPrint(Node* root)
{
	if(root)
	{
		printf("%d ", root->data);
		preOrderPrint(root->left);
		preOrderPrint(root->right);
	}
}

int main(int argc, char const *argv[])
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

	printf("PreOrder Seq :"); preOrderPrint(root);printf("\n");
	displayFlattenBinaryTree(flattenBinaryTree(root));

	return 0;
}