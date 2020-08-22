#include <bits/stdc++.h>
using namespace std;

class BstNode
{
public:
   int data;
   BstNode *left;
   BstNode *right;
};

bool isBST(BstNode *root, int min, int max)
{
   if (root == NULL)
      return true;
   if (root->data > max || root->data < min)
      return false;
   return (isBST(root->left, min, root->data - 1) && isBST(root->right, root->data + 1, max));
}

bool checkBST(BstNode *root)
{
   return isBST(root, INT_MIN, INT_MAX);
}

int main()
{
   return 0;
}