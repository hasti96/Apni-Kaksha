/*
* Building Tre from Postorder and Inorder......
*/

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data): data(data), left(nullptr), right(nullptr) {};
};

class Solution
{
public:

	static Node* buildTree(int postorder[], int inorder[], int start, int end)
	{
		static int indx = 4;
		
		if(start > end)
			return nullptr;

		int curr = postorder[indx];
		indx--;

		Node* node = new Node(curr);

		if(start == end)
			return node;

		int pos = search(inorder, start, end, curr);

		node->right = buildTree(postorder, inorder, pos+1, end);
		node->left = buildTree(postorder, inorder, start, pos-1);
		

		return node;
	}

	static int search(int inorder[], int start, int end, int curr)
    {
        for(int i=start; i <= end; i++)
        {
            if(inorder[i] == curr)
                return i;
        }

        return -1;
    }

    static void inorderPrint(Node* root)
    {
        if(root)
        {
            inorderPrint(root->left);
            cout<< root->data << " ";
            inorderPrint(root->right);
        }
    }
};

int main(int argc, char* argv[])
{
	int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};

    Node* root = Solution::buildTree(postorder, inorder, 0, 4);

    Solution::inorderPrint(root);

	return 0;
}