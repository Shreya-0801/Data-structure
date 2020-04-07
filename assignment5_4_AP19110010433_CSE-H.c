//INSERTION AND DELETION IN BST
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *left;
struct node *right;
};

struct node *insert(struct node *,int);
struct node *deletion(struct node *,int);

struct node *root=NULL;
struct node *temp=NULL;
void main()
{
int choice,value,s,x,c=0;
while(1)
{
printf("\n****************MENU**************\n");
printf("\n1.insertion\n2.deletion\n3.exit\n");
printf("enter your choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("enter value to be input::");
scanf("%d",&value);
root=insert(root,value);
c++;
break;

case 2:
printf("enter value you want to delete in tree::");
scanf("%d",&x);
deletion(root,x);
break;
case 3:
exit(0);
default:
printf("wrong input entered");
}
}
}

//MINIMUM
struct node*minimum(struct node*root)
{
	if(root==NULL)
		return NULL;
	if(root->left)
		return minimum(root->left);
	else
		return root;
}


//INSERTION OF NODES IN A TREE
struct node *insert(struct node *root,int value)
{
if(root==NULL)
{
root=(struct node *)malloc(sizeof(struct node));
root->left=NULL;
root->right=NULL;
root->data=value;
return root;
}
else
{
if(value < root->data)
root->left=insert(root->left,value);
else
root->right=insert(root->right,value);
}
return root;
}


//Deletion
struct node*deletion(struct node*root,int x)
{
	if(root==NULL)

return NULL;
if (x>root->data)
root->right = deletion(root->right, x);
else if(x<root->data)
root->left = deletion(root->left, x);
else
{
//No Children
if(root->left ==NULL && root->right==NULL)
{
free(root);
return NULL;
}
//One Child
else if(root->left==NULL || root->right==NULL)
{
struct node *temp;
if(root->left==NULL)
temp = root->right;
else
temp = root->left;
free(root);
return temp;
}
//Two Children
else
{
struct node *temp = minimum(root->right);
root->data = temp->data;
root->right = deletion(root->right, temp->data);
}
}
return root;
}


