#include <bits/stdc++.h>

using namespace std;

class BstNode
{
public:
   int data;
   BstNode *left;
   BstNode *right;
};

BstNode *getNewNode(int data)
{
   BstNode *temp = new BstNode();
   temp->data = data;
   temp->left = NULL;
   temp->right = NULL;
   return temp;
}
int FindMin(BstNode *root)
{
   if (root == NULL)
   {
      cout << "Error: Tree is Empty!!!\n";
      return -1;
   }
   while (root->left != NULL)
   {
      root = root->left;
   }
   return root->data;
}

int FindMax(BstNode *root)
{
   if (root == NULL)
   {
      cout << "Error: Tree is Empty!!!\n";
      return -1;
   }
   while (root->right != NULL)
   {
      root = (*root).right;
   }
   return root->data;
}

bool Search(BstNode *root, int data)
{
   BstNode *temp = root;
   while (temp->data != data)
   {
      if (temp->data >= data)
      {
         temp = temp->left;
      }
      else
      {
         temp = temp->right;
      }
      if (temp == NULL)
      {
         return false;
      }
   }
   return true;
}

BstNode *Insert(BstNode *root, int data)
{
   BstNode *newNode = getNewNode(data);

   if (root == NULL)
   {
      root = newNode;
      return root;
   }
   BstNode *parent = NULL, *current = root;
   while (current != NULL)
   {
      parent = current;
      if (current->data >= data)
      {
         current = current->left;
      }
      else
      {
         current = current->right;
      }
   }
   if (parent->data >= data)
   {
      parent->left = newNode;
   }
   else
   {
      parent->right = newNode;
   }
   return root;
}

int main()
{
   BstNode *root = NULL;
   root = Insert(root, 15);
   root = Insert(root, 20);
   root = Insert(root, 10);
   root = Insert(root, 25);
   root = Insert(root, 17);
   root = Insert(root, 8);
   root = Insert(root, 12);
   root = Insert(root, 13);
   root = Insert(root, 11);

   Search(root, 24)
       ? cout << "24 Found\n"
       : cout << "24 Not Found\n";
   Search(root, 11)
       ? cout << "11 Found\n"
       : cout << "11 Not Found\n";
   int min = FindMin(root);
   int max = FindMax(root);
   cout << "Minimum key in the tree is: " << min << "\n";
   cout << "Maximum key in the tree is: " << max << "\n";
   return 0;
}