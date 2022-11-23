#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
   char data;
   struct TreeNode *left;
   struct TreeNode *right;
} TreeNode;
/*     -
     /   \
    *     /
   / \   / \ 
  A   B  C  D     */
TreeNode* makeRootNode(char data, TreeNode* leftNode, TreeNode* rightNode)
{
   TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
   root->data = data;
   root->left = leftNode;
   root->right = rightNode;
   
   
   return root;
}

preorder(TreeNode* root){
   if( root != NULL){
      printf("%c", root->data);
      preorder(root->left);
      preorder(root->right);
   }
   
}

inorder(TreeNode* root)
{
   if( root != NULL){
      inorder(root->left);
      printf("%c", root->data);
      inorder(root->right);
   }
   
   
}

postorder(TreeNode* root)
{
   if( root != NULL){
      postorder(root->left);
      postorder(root->right);
      printf("%c", root->data);
   }
   
   
}

void main()
{
   TreeNode* n7 = makeRootNode('D', NULL, NULL);
   TreeNode* n6 = makeRootNode('C', NULL, NULL);
   TreeNode* n5 = makeRootNode('B', NULL, NULL);
   TreeNode* n4 = makeRootNode('A', NULL, NULL);
   TreeNode* n3 = makeRootNode('/', n6, n7);
   TreeNode* n2 = makeRootNode('*', n4, n5);
   TreeNode* n1 = makeRootNode('-', n2, n3);

   printf("preorder  : ");
   preorder(n1);
   
   printf("\ninorder   : ");
   inorder(n1);
   
   printf("\npostorder : ");
   postorder(n1);
   free(n1);free(n2);free(n3);
   free(n4);free(n5);free(n6);
   (n7);
   
}
