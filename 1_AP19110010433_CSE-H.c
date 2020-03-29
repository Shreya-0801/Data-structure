#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
     int value; 
     struct node* left; 
     struct node* right; 
}; 
  
struct node* new(int value) 
{ 
     struct node* node = (struct node*) malloc(sizeof(struct node)); 
     node->value= value; 
     node->left = NULL; 
     node->right = NULL; 
  
     return(node); 
} 
  
//Postorder traversal.
void postorder(struct node* node) 
{ 
     if (node == NULL) 
        return; 
  
     // Traverse  left subtree 
     postorder(node->left); 
  
     //Then, traverse right subtree 
     postorder(node->right); 
  
     //Finally,traverse the root 
     printf("%d ", node->value); 
} 
  
//Inorder traversal.
void inorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
  
     //Traverse left subtree 
     inorder(node->left); 
  
     //Then,, traverse the root
     printf("%d ", node->value);   
  
     //Finally, traverse right subtree 
     inorder(node->right); 
} 
  
//Preorder traversal
void preorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
  
     //Traverse the root
     printf("%d ", node->value);   
  
     //Then, traverse the  left sutree
     preorder(node->left);   
  
     //Finally, traverse the right subtree 
     preorder(node->right); 
}     
  
int main() 
{ 
     struct node *root  = new(68); 
     root->left         = new(92); 
     root->right        = new(23); 
     root->left->left   = new(45); 
     root->left->right  = new(56);  
  
     printf("\nPreorder : \n"); 
     preorder(root); 
  
     printf("\nInorder : \n"); 
     inorder(root);   
  
     printf("\nPostorder :\n"); 
     postorder(root); 
  
      
     return 0; 
} 

