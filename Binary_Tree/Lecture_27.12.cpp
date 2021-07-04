/*
* Find the minimum distance between two Node
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

Node* LCA(Node* root, int n1, int n2)
{
	if(root == nullptr)
		return nullptr;

	if(root->data == n1 || root->data == n2)
		return root;

	Node* left = LCA(root->left, n1, n2);
	Node* right = LCA(root->right, n1, n2);

	if(left != nullptr and right != nullptr)
		return root;
	else
		return left?left:right;
}

int findDist(Node* root, int k, int dist)
{
	if(root == nullptr)
		return -1;

	if(root->data == k)
		return dist;

	int left = findDist(root->left, k, dist+1);
	if(left != -1)
		return left;
	
	return findDist(root->right, k, dist+1);

}

int calcDistance(Node* root, int n1, int n2)
{
	Node* lca = LCA(root, n1, n2);

	int d1 = findDist(lca, n1, 0);
	int d2 = findDist(lca, n2, 0);

	return d1+d2;
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

	cout<< calcDistance(root, 4, 7) << endl;
	return 0;
}