/*
	Nodes at Distance K in Binary Tree | C++ Placement Course | Lecture 27.14

	Difficulty : Hard
*/

#include <bits/stdc++.h>

using namespace std;

static std::vector<int> nodes = {};

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data): data(data), left(nullptr), right(nullptr) {}
	Node(int data, Node* left, Node* right): data(data), left(left), right(right) {}
};

///case 1 
void printSubtreeNodes(Node* root, int k)
{
	if(root == nullptr)
		return;

	if(k == 0) 
	{
		cout<< root->data << " "<< endl;
		return;
	}

	printSubtreeNodes(root->left, k-1);
	printSubtreeNodes(root->right, k-1);
}

int printNodesAtk(Node* root, Node* target, int k)
{
	if(root == nullptr)
		return -1;

	if(root == target) {
		printSubtreeNodes(root, k);
		return 0;
	}

	int ld = printNodesAtk(root->left, target, k);

	if(ld != -1)
	{
		if(ld + 1 == k)
		{
			cout<< root->data << " ";
		}
		else
		{
			printSubtreeNodes(root->right, k-ld-2);
		}
		return 1+ld;
	}

	int rd = printNodesAtk(root->right, target, k);
	if(rd != -1)
	{
		if(rd + 1 == k)
		{
			cout<< root->data << " ";
		}
		else
		{
			printSubtreeNodes(root->right, k-rd-2);
		}
		return 1+rd;
	}

	return -1;
}

Node* findGivenNode(Node* root, Node* node)
{
	if(root == nullptr)
		return nullptr;
	else if(root == node)
		return root;

	Node* left = findGivenNode(root->left, node);
	Node* right = findGivenNode(root->right, node);

	if(left == node)
		return left;

	if(right == node)
		return right;

	return nullptr;
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

	// kdistNode(root, 1);

	// for(auto i: nodes)
	// 	printf("%d ", i);

	printNodesAtk(root, root->left->left, 2);
	
	return 0;
}