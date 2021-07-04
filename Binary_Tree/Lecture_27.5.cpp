/*
* Level order traversal of the Binary tree......
*/

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data):data(data), left(nullptr), right(nullptr){}
	Node(int data, Node* left, Node* right):data(data), left(left), right(right){}
};

class Solution
{
public:
	static void printLevelOrder(Node* root)
	{
		if(root)
		{
			queue<Node*> node_q;
			node_q.push(root);
			node_q.push(nullptr);

			while(!node_q.empty())
			{
				Node* curr = node_q.front();
				node_q.pop();

				if(curr)
				{
					cout << curr->data << " ";
					if(curr->left)
						node_q.push(curr->left);
					if(curr->right)
						node_q.push(curr->right);
				}
				else if(!node_q.empty())
				{
					node_q.push(nullptr);
				}
			}
		}
		printf("\n");
	}

	static void sumAtKthLevel(Node* root, int K)
	{
		int level = 0;
		int sum = 0;

		if(root)
		{
			queue<Node*> node_q;
			node_q.push(root);
			node_q.push(nullptr);

			while(!node_q.empty())
			{
				Node* curr = node_q.front();
				node_q.pop();

				if(curr)
				{
					// cout << curr->data << " ";
					sum += curr->data;

					if(curr->left)
						node_q.push(curr->left);
					if(curr->right)
						node_q.push(curr->right);
				}
				else 
				{
					if(level == K)
						printf("Sum of Node at Level [%d] is [%d]\n", level, sum);

					sum = 0;
					level++;

					if(!node_q.empty())
						node_q.push(nullptr);
				}
				
			}
		}
	}
};

int main(int argc, char* argv[])
{

	Node* left 	= new Node(2, new Node(4), new Node(5));
	Node* right = new Node(3, new Node(6), new Node(7));
	Node* root	= new Node(1, left, right);

	Solution::printLevelOrder(root);
	Solution::sumAtKthLevel(root, 1);

	return 0;
}