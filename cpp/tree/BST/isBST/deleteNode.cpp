#include <bits/stdc++.h>
using namespace std;

class BstNode
{
public:
   int data;
   BstNode *left;
   BstNode *right;
};
BstNode *findMax(BstNode *root)
{
   if (root == NULL)
      return root;
   else if (root->right != NULL)
      root = findMax(root->right);
   return root;
}

BstNode *findMin(BstNode *root)
{
   if (root == NULL)
      return root;
   else if (root->left != NULL)
      root = findMin(root->left);
   return root;
}

BstNode *Delete(BstNode *root, int data)
{
   if (root == NULL)
      return root;
   else if (data < root->data)
      root->left = Delete(root->left, data);
   else if (data > root->data)
      root->right = Delete(root->right, data);
   else
   {
      // Case 1 - No Node.
      if (root->left == NULL && root->right == NULL)
      {
         delete root;
         root = NULL;
      }
      // Case 2 - Only 1 Node.
      else if (root->left == NULL)
      {
         BstNode *temp = root;
         root = root->right;
         delete temp;
      }
      else if (root->right == NULL)
      {
         BstNode *temp = root;
         root = root->left;
         delete temp;
      }
      // Case 3 - 2 Nodes
      else
      {
         BstNode *temp;
         temp = findMin(root->right);
         root->data = temp->data;
         root->right = Delete(root->right, temp->data);

         /*
         OR

         BstNode *temp;
         temp = findMax(root->left);
         root->data = temp->data;
         root->left = Delete(root->left, temp->data);
         
         */
      }
   }
   return root;
}