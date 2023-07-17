
/* A cpp program to build a binary tree using postorder and 
inorder sequences */
#include<bits/stdc++.h>
using namespace std;
class node // node structure
{
    public:
    int data;
    node* left;
    node* right;
    node(int val) // constructor to create a new node
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
// serach function to find element position in inorder sequence
int search(int inorder[], int start, int end, int curr) 
{                                                      
    for( int i = start; i <= end; i++)
    {
        if(inorder[i] == curr)
            return i;
    }
    return -1;
}
// function to build tree from inorder and post order sequence
node* buildTree(int postorder[] ,int inorder[], int start, int end)
{
    static int idx = end;

    if(start > end )
        return NULL;

    int curr = postorder[idx];
    idx --;
    node *n = new node(curr);
        
    int pos = search(inorder, start, end, curr);
    if(start == end)
        return n;
    n->right = buildTree(postorder, inorder,pos+1,end);
    n->left = buildTree(postorder, inorder, start, pos-1);

    return n;
}
// inorder traversal function
void inOrder(node* root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    
}
// Driver code
int main()
{
    int inorder[]={4,2,5,1,6,3,7};
    int postorder[] = {4,5,2,6,7,3,1};

    node * root = buildTree(postorder,inorder,0 ,6);

    inOrder(root);
    cout << endl;
}
