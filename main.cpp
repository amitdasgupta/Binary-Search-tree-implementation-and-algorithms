#include <iostream>
#include<math.h>
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
/*************************defination of doubly linked list
class Dll
{
public:
    int data;
    Dll* next;
    dll* prev;
    Dll(int data)
    {
        this.data=data;
        this.next=NULL;
        this.prev=NULL;
    }
};*/////////////////////////
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
/*************************************checking presence of node with given data
bool findNodeInBst(Bst* root,int data)
{
    if(!root)
        return false;
    else
        return root->data==data||findNodeInBst(root->left,data)||findNodeInBst(root->right,data);
}*/////////////////////
/***************************************************
Bst* findMaxNodeInBst(Bst* root)
{
    if(!root->right)
        return root;
    else
        return findMaxNodeInBst(root->right);
}*/////////////////////////////////////////
/******************************finding pointer of given node
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
}*///////////////////////
/*********************************************finding inOrder prdesessor and succesor of any given node
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
}*//////////////////////
/*************************************code for deleting a node
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
}*////////////////////////////////////////
/******************************
int LeastCommonAncessorInBst(Bst* root,int a,int b)
{
    if(!root)
        return 0;
    if(((a<root->data&&root->data<b)||(b<root->data&&root->data<a)))
    {
        return root->data;
    }
    else
        return (LeastCommonAncessorInBst(root->left,a,b)?LeastCommonAncessorInBst(root->left,a,b):LeastCommonAncessorInBst(root->right,a,b))?(LeastCommonAncessorInBst(root->left,a,b)?LeastCommonAncessorInBst(root->left,a,b):LeastCommonAncessorInBst(root->right,a,b)):(root->data==a?a:b);
}
*//////////////////////////////////////////////////
/**************************************
bool isBinarySearchTree(Bst* root)
{
    if(!root||!root->left&&!root->right)
        return true;
    else
       return ((root->left?root->data>findMaxNodeInBst(root->left)->data:true)&&(root->right?root->data<findMinimuminBst(root->right)->data:true)&&isBinarySearchTree(root->left)&&isBinarySearchTree(root->right)?true:false);
}*////////////////////////////////////
/**********************
int numberOftreesPossibleWithNnodes(int n)
{
    if(n==0)
        return 1;
    else
    {   int sum=0;
        for(int i=1;i<=n;i++)
         { //  cout<<sum;
             sum+=numberOftreesPossibleWithNnodes(i-1)*numberOftreesPossibleWithNnodes(n-i);
         }
        return sum;
    }
}*///////////////////////////////////////////////////
/************************************************************
int leastCommonanAncesstorOfTwoNodes(Bst* root,int a,int b)
{
    if(!root)
        return 0;
    if(root->data==a||root->data==b)
        return root->data;
    else
        if(leastCommonanAncesstorOfTwoNodes(root->left,a,b)&&leastCommonanAncesstorOfTwoNodes(root->right,a,b))
        return root->data;
    else
        return leastCommonanAncesstorOfTwoNodes(root->left,a,b)?leastCommonanAncesstorOfTwoNodes(root->left,a,b):leastCommonanAncesstorOfTwoNodes(root->right,a,b);
}*//////////////////////////////////////////////////////////////////////////

void conversionFromBstToDoublyLinkedList(Bst* root,Bst* &last,Bst* &headpointer)
{
    if(!root)
        return;
    else
    {
        conversionFromBstToDoublyLinkedList(root->left,last,headpointer);
        if(!last)
            headpointer=root;
        else
            last->right=root;
        root->left=last;
        last=root;
        conversionFromBstToDoublyLinkedList(root->right,last,headpointer);
    }
}
void printDoublyLinkedList(Bst* root)
{
    while(root)
    {
        cout<<root->data<<" ";
        root=root->right;
    }
}
int findLengthOfLinkedList(Bst* head)
{
    int n=0;
    while(head)
    {
        n++;
        head=head->right;
    }
    return n;
}
Bst* conversionFromDoublyLinkedListToBst(Bst* root)
{
    if(!root||!root->right)
        return root;
    else
    {   Bst *temp=root,*p=root,*q;
        int len=findLengthOfLinkedList(root)/2;
        while(len--)
        {
            temp=temp->right;
        }
        while(p->right!=temp)
            p=p->right;
        q=temp->right;
        p->right=NULL;
        q->left=NULL;
        temp->left=conversionFromDoublyLinkedListToBst(root);
        temp->right=conversionFromDoublyLinkedListToBst(q);
                return temp;
    }

}
/**************
Dll* convesrionFromBstToDll(Bst* root,Dll* head)
{
    if(!root)
        return null;
        {
            head=new Dll(root->data);
            head->prev=convesrionFromBstToDll(root->left,head);
            head->next=convesrionFromBstToDll(root->righ,)
        }
}*///////////////////////////////////
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
    /*********************
    implementation of basic algorithms
     int data;
    cin>>data;
    if(findNodeInBst(root,data))
    cout<<"element is found";
    else
    cout<<"element is not found";
    cout<<"\n minimum is:"<<findMinimuminBst(root)->data<<"\n";
    cout<<findMaxNodeInBst(root)->data;
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
    int dataForLcs1,dataForLcs2;
    cin>>dataForLcs1>>dataForLcs2;
    cout<<LeastCommonAncessorInBst(root,dataForLcs1,dataForLcs2);*///////////////////////////////////////
/***  if(isBinarySearchTree(root))
        cout<<"yes";*/
     /************   int numberofnodes;
        cin>>numberofnodes;
        cout<<numberOftreesPossibleWithNnodes(numberofnodes);*//////////////////
 /**********************int a,b;
    cin>>a>>b;
    cout<<leastCommonanAncesstorOfTwoNodes(root,a,b);*////////////////////////////
    Bst* head=NULL;
    Bst* last=NULL;
    conversionFromBstToDoublyLinkedList(root,last,head);
   // printDoublyLinkedList(head);
    Bst* converted=conversionFromDoublyLinkedListToBst(head);
    cout<<"\n";
    inOrderTraversal(converted);
    return 0;
}
