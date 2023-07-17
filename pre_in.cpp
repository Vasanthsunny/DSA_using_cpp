
/* A cpp program to build a binary tree using preorder and 
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
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == curr);
            return i;
    }
    return -1;
}
// function to build tree from inorder and preorder sequence
node* buildTree( int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if(start > end)
    {
       return NULL;
    }
        

    int curr = preorder[idx];
    idx++;
    node *n = new node(curr);
    if(start == end)
    {
        return n;
    }
        
    int pos = search(inorder, start, end, curr);
    n->left = buildTree(preorder, inorder, start, pos-1);
    n->right = buildTree(preorder,inorder,pos+1,end); 
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
    int preorder[] = {1,2,4,5,3,6,7};

    node * root = buildTree(preorder,inorder,0 ,6);

    inOrder(root);
    cout << endl;
}
