#include <bits/stdc++.h>
using namespace std;

class BstNode
{
public:
   int data;
   BstNode *left;
   BstNode *right;
};

int findMax(BstNode *root)
{
   if (root == NULL)
      exit(1);
   while (root->right != NULL)
   {
      root = root->right;
   }
   return root->data;
}

int findMin(BstNode *root)
{
   if (root == NULL)
      exit(1);
   while (root->left != NULL)
   {
      root = root->left;
   }
   return root->data;
}
bool isBST(BstNode *root)
{
   int leftMax = 0;
   int rightMin = 0;
   if (root == NULL)
      return true;
   if (root->left != NULL)
   {
      leftMax = findMax(root->left);
   }
   else
   {
      return true;
   }
   if (root->right != NULL)
   {
      rightMin = findMin(root->right);
   }
   else
   {
      return true;
   }

   if (
       root->data >= leftMax && root->data < rightMin && isBST(root->left) && isBST(root->right))
      return true;
   return false;
}