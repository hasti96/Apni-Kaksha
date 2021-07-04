/* 
* Build Tree from PreOrder and Inorder.........
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
    static Node* buildTree(int preorder[], int inorder[], int start, int end)
    {
        static int idx = 0;

        if(start > end)
            return nullptr;

        int curr = preorder[idx];
        idx++;
        Node* node = new Node(curr);

        if(start == end) 
        {
            return node;
        }

        int pos = search(inorder, start, end, curr);

        node->left = buildTree(preorder, inorder, start, pos-1);
        node->right = buildTree(preorder, inorder, pos+1, end);

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
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};

    Node* root = Solution::buildTree(preorder, inorder, 0, 4);

    Solution::inorderPrint(root);
    return 0;
}