#include <bits/stdc++.h>
using namespace std;

class BstNode
{
public:
   int data;
   BstNode *left;
   BstNode *right;
};

BstNode *findMin(BstNode *root)
{
   if (root == NULL)
      return root;
   else if (root->left != NULL)
      root = findMin(root->left);
   return root;
}

BstNode *findNode(BstNode *root, int data)
{
   if (root == NULL)
      return root;
   if (root->data == data)
      return root;
   if (data > root->data)
      root = findNode(root->right, data);
   else
   {
      root = findNode(root->left, data);
   }
   return root;
}

// InOrder Successor in a given BST.
BstNode *getSuccessor(BstNode *root, int data)
{
   BstNode *current, *ancestor, *successor;
   current = findNode(root, data); // Search the Node - O(h)

   if (current == NULL)
      return current;
   if (current->right != NULL) // CASE 1: Node has right subtree (We have to find Min value node in right subtree)
   {
      current = findMin(current->right);
      return current;
   }
   else // CASE 2: No right subtree (We have to find the deepest ancestor in the left subtree)
   {
      successor = NULL;
      ancestor = root;
      while (ancestor != current)
      {
         if (current->data < ancestor->data)
         {
            successor = ancestor; // so far this is the deepest node for which current node is in left.
            ancestor = ancestor->left;
         }
         else
         {
            ancestor = ancestor->right;
         }
      }
      return successor;
   }
}