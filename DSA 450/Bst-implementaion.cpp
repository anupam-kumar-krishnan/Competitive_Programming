//implementation of BST
#include<bits/stdc++.h>
#include <queue>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root,*head;

//function declaration
void inorder(struct node *node);
void preorder(struct node *node);
void postorder(struct node *node);
struct node* insertnode(int key,struct node *Node);
struct node * newnode(int key);
struct node* minnode(struct node *node);
struct node *maxnode(struct node *node);
struct node* searchnode(struct node *Node,int key);
struct node* deletenode(struct node *Node,int key);//important
void count_leaves(struct node *node,int *count,int *total);
int height_bst(struct node *node);
void levelorder(struct node *node);
//function definition of bst
void levelorder(struct node *node)
{
    if(node==NULL)
    return;
    else{
    //  int h=height_bst(node);
      queue<struct node*> q;
      q.push(node);
      struct node *curr=NULL;
     
    //  h=h+1;
      while(!q.empty())
      {
          curr=q.front();
          cout<<curr->data<<" ";
          q.pop();
          if(curr->left!=NULL)
          q.push(curr->left);
          if(curr->right!=NULL)
          q.push(curr->right);
      }
      cout<<endl;
    }
}
int height_bst(struct node *node)
{
    if(node==NULL)
    return 0;
    else{
        if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = height_bst(node->left);
        int rDepth = height_bst(node->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
    }

}
void count_leaves(struct node *node, int *count,int *total)
{
    
    if(node!=NULL)
    {
         *total=*total+1;
       // cout<<"root:"<<node->data<<endl;
        if(node->left==NULL && node->right==NULL)
        {
            *count=*count+1;
            cout<<"lead node:"<<node->data<<endl;
        }
        count_leaves(node->left,count,total);
        count_leaves(node->right,count,total);
    }
}
 //struct node 
 struct node* deletenode(struct node *node,int key)
 {
     //if there is no node.
    if(node==NULL)
    return node;
    
    //if deleted node is smaller than root
     if(node->data>key)
     node->left=deletenode(node->left,key);
     //if deleted node is greater than root
     else if(node->data<key)
     node->right=deletenode(node->right,key);
     else
     {
         if(node->left==NULL)
         {
             struct node *temp;
             temp=node->right;
             free(node);
             return temp;
         }
         else if(node->right)
         {
             struct node *temp;
             temp=node->left;
             free(node);
             return temp;
         }
         else
         {
             struct node *temp;
             temp=minnode(node->right);
             node->data=temp->data;
            node->right=deletenode(node->right,temp->data);
         }
     }
   return node;

 }
 struct node *minnode(struct node *node)
{
    if(node->left==NULL)
    {
        return node;
    }
    return minnode(node->left);
        

    //else 
    //cout<<"Min:"<<node->data<<endl;
    
}
struct node* searchnode(struct node *node,int key)
{
    if(node->data==key || node==NULL)
    return node;
    if(node->data>key)
    node->left=searchnode(node->left,key);
    if(node->data<key)
    node->right=searchnode(node->right,key);
}
struct node *maxnode(struct node *node)
{
    if(node->right==NULL)
    {
      return node;
    }
    maxnode(node->right);
}
//inorder also sort the bst,we don't need new function.
void inorder(struct node *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
    
}
void preorder(struct node *node)
{
    if(node!=NULL)
    {
        cout<<node->data<<" ";
        inorder(node->left);
        inorder(node->right);
    }
    
}
void postorder(struct node *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        inorder(node->right);
         cout<<node->data<<" ";
    }
    
}
struct node * newnode(int key)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
// insert in bst
struct node* insertnode(int key,struct node *node)
{
    if(node==NULL)
    {
        head=newnode(key);
        return head;
    }

    if(node->data>key)
    node->left=insertnode(key,node->left);

    if(node->data<key)
    node->right=insertnode(key,node->right);
    return node;
  
}
int main()
{
    int option,key,count=0,total=0,h;
    struct node *minm,*maxm,*fn;
    do
    {
        cout << "\nEnter the option:\n1)insert\n2)Print\n3)Min value\n4)Maxm value\n5)Preorder\n6)Postorder\n7)search\n8)Delete\n9)count_leaves\n10)height\n11)level order traversal\n";
        cin >> option;
        switch (option)
        {
        case 1:
           cout<<"Enter node:";
           cin>>key;
            root=insertnode(key,root); 
            break;
        case 2:
            inorder(root);
            break;
        case 3:
        //cout<<"head="<<head->data<<endl;
        //cout<<"root="<<root->data<<endl;
            minm=minnode(root);
           cout<<minm->data<<endl;
             break;
        case 4:
           maxm=maxnode(root);
          cout<<maxm->data<<endl;
            break;
            case 5:
            preorder(root);
            break;
            case 6:
            postorder(root);
            break;
            case 7:
            cout<<"Enter element:";
           cin>>key;
            fn=searchnode(root,key);
            if(fn==NULL)
            cout<<"not found\n"<<endl;
            else
            cout<<"found\n";
            break;
            case 8:
            cout<<"Enter element:";
           cin>>key;
            deletenode(root,key);
            break;
            case 9:
            count_leaves(root,&count,&total);
            cout<<"total number of leaf nodes:"<<count<<endl;
            cout<<"total number of nodes:"<<total<<endl;
            count=0;total=0;
            break;
            case 10:
            h=height_bst(root);
            cout<<"Height:"<<h<<endl;
            break;
            case 11:
            levelorder(root);
            cout<<endl;
            break;
        default:
            break;
        }
    } while (option != 0);
}
