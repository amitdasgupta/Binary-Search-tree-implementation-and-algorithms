#include <iostream>
#include<math.h>
#include<map>
#include<deque>
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
/****************************Linked list defination
class Linked
{
public:
    int data;
    Linked* next;
    Linked(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
*//////////////////////////////
<<<<<<< HEAD

=======
>>>>>>> bd69340aa03e2cb7649cfb0df7c1eeef3b69781b
/**************************************************function to print linked list
void prinLinkedList(Linked* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
*////////////////////////////////
/*****************************function to insert into linked list
void insertIntoLinkedList(Linked* &head,int data)
{
    if(!head)
    {
        head=new Linked(data);
    }
    else
    {
       Linked* temp=head;
        while(temp->next)
        {
            temp=temp->next;
        }
        temp->next=new Linked(data);
    }
}
*///////////////////////////////////////////////
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
/*************************preorder traversal*//////////////////////////////
void preOrderTraversal(Bst* root)
{
    if(!root)
        return;
    else
    {
        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
/*************************************checking presence of node with given data
bool findNodeInBst(Bst* root,int data)
{
    if(!root)
        return false;
    else
        return root->data==data||findNodeInBst(root->left,data)||findNodeInBst(root->right,data);
}*/////////////////////
/****************************************************
finding maximum node in Bst
Bst* findMaxNodeInBst(Bst* root)
{
    if(!root->right)
        return root;
    else
        return findMaxNodeInBst(root->right);
}
/////////////////////////////////////////
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

/*************************void conversionFromBstToDoublyLinkedList(Bst* root,Bst* &last,Bst* &headpointer)
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

}*////////////////////////////////////////////////////////////////////////////////////
/****************function to give bst from sorted array
Bst* givingBstFromSortedArray(int arr[10000],int start,int ending)
{
if(start>ending)
    return NULL;
else
    if(start==ending)
{
    Bst* temp=new Bst(arr[start]);
    return temp;
}
else
{
    int mid=(ending-start+1)/2;
   // cout<<arr[(ending-start+1)/2]<<" ";
    Bst* temp=new Bst(arr[mid]);
    temp->left=givingBstFromSortedArray(arr,start,mid-1);
    temp->right=givingBstFromSortedArray(arr,mid+1,ending);
    return temp;
}
}*///////////////////////////////////////////////////////////////////////////////
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
/************************************function to conver linked list to binary search tree*
Bst* conversionFromLinkedListToBinarySearchTree(Linked* &head,int n)
{
    if(n<=0)
        return NULL;
    else
    {
        Bst* left=conversionFromLinkedListToBinarySearchTree(head,n/2);
        Bst* newnode=new Bst(head->data);
        newnode->left=left;
        head=head->next;
        newnode->right=conversionFromLinkedListToBinarySearchTree(head,n-n/2-1);
        return newnode;
    }
}*/
/*******************************function to find Kth smallest element
int giveKthSmallestElement(Bst* root,int k,int &temp)
{   if(!root)
return 0;
    else
{
    int left=giveKthSmallestElement(root->left,k,temp);
    if(left)
        return left;
    temp=temp+1;
    if(temp==k)
        return root->data;
    int right=giveKthSmallestElement(root->right,k,temp);
    if(right)
        return right;
    return 0;
}
*////////////////////
/********************************************************
Bst* floorOfBST(Bst* root,int data)
{
    if(!root)
        return NULL;
    else
        if(root->data==data)
    {
        return root;
    }
    else
        if(root->data>data)
        {
           return floorOfBST(root->left,data);
        }
        else
        {
            Bst* right=floorOfBST(root->right,data);
            if(right)
                return right;
            else
                return root;
        }
}
*//////////////////////////////////////////////////////////////////////
Bst* ceilOfBst(Bst* root,int data)
{
    if(!root)
        return NULL;
    else
        if(root->data==data)
        return root;
    else
        if(data<root->data)
    {
        Bst* left=ceilOfBst(root->left,data);
        if(left)
            return left;
        else
            return root;
    }
    else
        return ceilOfBst(root->right,data);
<<<<<<< HEAD
}*////////////////////////////////////////////////////////////////////////
/**************************************************
Linked* mergeAndSort(Linked* head1,Linked* head2)
{
    if(!head1&&!head2)
        return NULL;
    else
        if(!head1||!head2)
        return head1?head1:head2;
    else
    {   Linked* head=NULL;
        if(head1->data<head2->data)
        {
            head=head1;
            head->next=mergeAndSort(head1->next,head2);
        }
        else
           // if(head1->data<head2->data)
        {
            head=head2;
           head->next= mergeAndSort(head1,head2->next);
        }
            return head;
    }
}
Linked* mergeSort(Linked* head,int n)
{
    if(!head||!head->next)
        return head;
    else
    {
        Linked *temppointer=head,*previoustemp,*start,*last;
      int temp=n/2;
      while(temp--)
        {
            previoustemp=temppointer;
            temppointer=temppointer->next;
        }
      previoustemp->next=NULL;
      start=mergeSort(head,n/2);
      last=mergeSort(temppointer,n-n/2);
      return mergeAndSort(start,last);


    }
}*//////////////////////////////////////////
/*********************************
finding intersection of bst
void insertIntoMapUsingInorderTraversal(Bst* root,map<int,int> &map_)
{
    if(!root)
        return;
   else
    {
        insertIntoMapUsingInorderTraversal(root->left,map_);
        //cout<<root->data<<" ";
         map_.insert(pair <int,int>(root->data,0));
        insertIntoMapUsingInorderTraversal(root->right,map_);

    }
}
void getIntersectionOfBst(Bst* root,map<int,int> map_,deque<int> &deque_)
{
    if(!root)
        return;
    else
    {
        getIntersectionOfBst(root->left,map_,deque_);
        if(map_.find(root->data)!=map_.end())
        {
            deque_.push_back(root->data);
        }
        getIntersectionOfBst(root->right,map_,deque_);
    }
}**/
/***************************************************************
finding unio of two bst
void insertIntoMapUsingInorderTraversal(Bst* root,map<int,int> &map_,deque<int> &deque_)
{
    if(!root)
        return;
   else
    {
        insertIntoMapUsingInorderTraversal(root->left,map_,deque_);
        //cout<<root->data<<" ";
         map_.insert(pair <int,int>(root->data,0));
         deque_.push_back(root->data);
        insertIntoMapUsingInorderTraversal(root->right,map_,deque_);

    }
}
void getUnionOfBst(Bst* root,map<int,int> &map_,deque<int> &deque_)
{
    if(!root)
    return;
    else
    {
        getUnionOfBst(root->left,map_,deque_);
        if(map_.find(root->data)==map_.end())
            deque_.push_back(root->data);
        getUnionOfBst(root->right,map_,deque_);
    }

}
*///////////////////////////////////////////////////////////////
int main()
{ /*********************/////////////////////////////////////////////
=======
}
int main()
{
>>>>>>> parent of 6ed3929... addition of merge sort of two linked list
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
    /********************Bst* head=NULL;
    Bst* last=NULL;
    conversionFromBstToDoublyLinkedList(root,last,head);
   // printDoublyLinkedList(head);
    Bst* converted=conversionFromDoublyLinkedListToBst(head);
    cout<<"\n";
    inOrderTraversal(converted);*///////////////////////////////////
 /********************************   int arr[100000],n,temp,i;
    cout<<"enter the number of elements in array";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>temp;
        arr[i]=temp;
    }
    Bst* root=givingBstFromSortedArray(arr,0,n-1);
    inOrderTraversal(root);
    cout<<"\n";
    preOrderTraversal(root);*///////////////////////////////////
  /**********************  Linked* head=NULL;
    int n;
    cin>>n;
    int i=n,temp;
    while(i--)
    {
        cin>>temp;
        insertIntoLinkedList(head,temp);
    }
    prinLinkedList(head);
    Bst* headgotfromlinkedlist=conversionFromLinkedListToBinarySearchTree(head,n);
    cout<<"\nInorder traversal:";
    inOrderTraversal(headgotfromlinkedlist);
    cout<<"\npreOrder traversal:";
    preOrderTraversal(headgotfromlinkedlist);
    *////////////////////////////////////////////////
  /***************************************  int k,temp=0;
    cin>>k;
    cout<<giveKthSmallestElement(root,k,temp);
    *////////////////////////
/**********************    int ceildata;
    cin>>ceildata;
    Bst* result=floorOfBST(root,ceildata);
    if(!result)
        cout<<"floor does not exist";
    else
        cout<<result->data;*////////////////////////////////////////////
        int ceildata;
    cin>>ceildata;
    Bst* result=ceilOfBst(root,ceildata);
    if(!result)
        cout<<"ciel does not exist";
    else
        cout<<result->data;
<<<<<<< HEAD
    *////////////////////////////////////////////
  /**************************  Linked *head1=NULL,*head2=NULL;
    int m,n;
    cin>>m;
    int i=m,temp;
    while(i--)
    {
        cin>>temp;
        insertIntoLinkedList(head1,temp);
    }*////////////////////////////////////////////////////
    /************i=n;
    while(i--)
    {
        cin>>temp;
        insertIntoLinkedList(head2,temp);
    }*////////////////////////////
  //  prinLinkedList(head1);
   // cout<<"\n";
    /******prinLinkedList(head2);
    Linked* sorte=mergeAndSort(head1,head2);
    cout<<"\n";*//////////////////////
   /*************** Linked* sorte=mergeSort(head1,m);
    prinLinkedList(sorte);*////////////////////////////
/*********************************    Bst* root2=NULL;

   insertIntoBinaryTree(root2,10);
   insertIntoBinaryTree(root2,15);
   insertIntoBinaryTree(root2,20);
   insertIntoBinaryTree(root2,4);
   insertIntoBinaryTree(root2,9);
   insertIntoBinaryTree(root2,13);
   insertIntoBinaryTree(root2,50);
   inOrderTraversal(root2);
   cout<<"\n";
   map<int,int> map_;
   deque<int> deque_;

   insertIntoMapUsingInorderTraversal(root,map_,deque_);*/////////////////////////////
  /*************** cout<<"Giving union of the given trees\n";
   deque<int> deque_;
   getIntersectionOfBst(root2,map_,deque_);
   int temp;
   while(!deque_.empty())
   {

       cout<<deque_.front()<<" ";
       deque_.pop_front();
   }
*////////////////////////////////////////////////////////////////
//insertIntoMapUsingInorderTraversal(root,map_);
/******  getUnionOfBst(root2,map_,deque_);
  while(!deque_.empty())
   {

       cout<<deque_.front()<<" ";
       deque_.pop_front();
   }
<<<<<<< HEAD
   return 0;*/////////////////////////////////
=======
   return 0;
=======

    return 0;
>>>>>>> parent of 6ed3929... addition of merge sort of two linked list
>>>>>>> bd69340aa03e2cb7649cfb0df7c1eeef3b69781b

}
