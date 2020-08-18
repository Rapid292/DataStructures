#include <bits/stdc++.h>
using namespace std;

class BstNode
{
public:
   int data;
   BstNode *left;
   BstNode *right;
};

bool checkBST(BstNode *root)
{
   int prev = INT_MIN, current = 0;

   if (root == NULL)
      return true;
   if (!checkBST(root->left))
      return false;
   current = root->data;
   if (prev > current)
      return false;
   prev = current;
   return checkBST(root->right);
}
