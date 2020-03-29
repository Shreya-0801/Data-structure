#include <stdio.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node* left;
     struct node* right;
};

struct node* new(int value)
{
     struct node* temp= (struct node*) malloc(sizeof(struct node));
     temp->data= value;
     temp->left = NULL;
     temp->right = NULL;

     return(temp);
}
//Insertion of binary search tree
struct node*insert(struct node*node,int value)
{
	if(node==NULL)
		return new(value);
	if(value<node->data)
		node->left=insert(node->left,value);
	if(value>node->data)
		node->right=insert(node->right,value);
	return node;
}
//Inorder traversal
void inorder(struct node*root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void main()
{
	struct node*root=NULL;
	root=insert(root,50);
	root=insert(root,30);
	root=insert(root,20);
	root=insert(root,40);
	root=insert(root,70);
	root=insert(root,60);
	root=insert(root,80);
	printf("IN-ORDER:\n");
	inorder(root);
}

