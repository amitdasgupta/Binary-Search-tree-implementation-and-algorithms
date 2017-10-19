#include <iostream>

using namespace std;
class Bst{
/****************tree defination*/////////////////////////
public:
    int data;
    Bst* left;
    Bst* right;
    Bst(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
/********************function for inserting into tree*///////////////////////////
void insertIntoBinaryTree(Bst* &root,int data)
{
    if(!root||root->data==data)
    {
        root=new Bst(data);
    }else
    if(data<root->data)
       insertIntoBinaryTree(root->left,data);
    else
      insertIntoBinaryTree(root->right,data);


}
/*************************************code for finding minimum element in bst*/////////////////////
Bst* findMinimuminBst(Bst* root)
{
    if(!root->left)
        return root;
    else
        return findMinimuminBst(root->left);
}
/***************************************doin inorde traversal*/////////////////////////////////
void inOrderTraversal(Bst* root)
{
    if(!root)
        return;
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
/*************************************checking presence of node with given data*/////////////////////
bool findNodeInBst(Bst* root,int data)
{
    if(!root)
        return false;
    else
        return root->data==data||findNodeInBst(root->left,data)||findNodeInBst(root->right,data);
}
/*************************************code for finding maximum element in bst*/////////////////////
Bst* findMaxNodeInBst(Bst* root)
{
    if(!root->right)
        return root;
    else
        return findMaxNodeInBst(root->right);
}
/******************************finding pointer of given node*///////////////////////
Bst* findNode(Bst* root,int data)
{
    if(!root)
        return NULL;
    else
        if(root->data==data)
        return root;
    else
        if(root->data>data)
        return findNode(root->left,data);
    else
        return findNode(root->right,data);
}
/*********************************************finding inOrder prdesessor and succesor of any given node*//////////////////////
void inOrderPredesecceorandsuccesor(Bst* root,Bst* &mi,Bst* &ma,int data)
{
    if(!root)
        return;
    else
    {
        Bst* root1=findNode(root,data);
        mi=findMaxNodeInBst(root1->left);
        ma=findMinimuminBst(root1->right);
        //cout<<mi->data<<" "<<ma->data;
    }
}
/*************************************code for deleting a node*/////////////////////////////////////////////////
void deleteNodeInBst(Bst* &root,int data)
{
    if(!root)
        return;
    else
        if(!root->left&&!root->right)
    {
        if(root->data==data)
       {
            free(root);
        root=NULL;
       }
       return;
    }
    else
        if(root->data==data)
        {  // cout<<root->data<<" ";
            if(root->left&&root->right)
            {
                Bst* maxleft=findMaxNodeInBst(root->left);
                root->data=maxleft->data;
                deleteNodeInBst(root,maxleft->data);
            }
            else
            {
                root->data=root->left?root->left->data:root->right->data;
                deleteNodeInBst(root,root->left?root->left->data:root->right->data);
            }

        }
        else
        {
            deleteNodeInBst(root->left,data);
            deleteNodeInBst(root->right,data);
        }
}
int main()
{
   Bst* root=NULL;
   insertIntoBinaryTree(root,10);
   insertIntoBinaryTree(root,6);
   insertIntoBinaryTree(root,16);
   insertIntoBinaryTree(root,4);
   insertIntoBinaryTree(root,9);
   insertIntoBinaryTree(root,13);
   insertIntoBinaryTree(root,7);
   inOrderTraversal(root);
   cout<<"\n";
   int data;
   cin>>data;
   if(findNodeInBst(root,data))
    cout<<"element is found";
   else
    cout<<"element is not found";
    cout<<"\n minimum is:"<<findMinimuminBst(root)->data<<"\n";
    cout<<findMaxNodeInBst(root)->data;*///////////////
    Bst* mi=NULL;
    Bst* ma=NULL;
    int data;
    cin>>data;
    inOrderPredesecceorandsuccesor(root,mi,ma,data);
    cout<<mi->data<<" "<<ma->data;
    int data;
    cin>>data;
    deleteNodeInBst(root,data);
    inOrderTraversal(root);
    return 0;
}
