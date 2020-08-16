// Using Recursion.

#include <bits/stdc++.h>
using namespace std;

class BstNode
{
public:
   int data;
   BstNode *left;
   BstNode *right;
};

BstNode *GetNewNode(int data)
{
   BstNode *temp = new BstNode();
   (*temp).data = data;
   (*temp).left = NULL;
   (*temp).right = NULL;

   return temp;
}

int FindMin(BstNode *root)
{
   if (root == NULL)
   {
      cout << "Error: Tree is Empty!!!\n";
      return -1;
   }
   else if (root->left == NULL)
      return root->data;

   return FindMin(root->left);
}

int FindMax(BstNode *root)
{
   if (root == NULL)
   {
      cout << "Error: Tree is Empty!!!\n";
      return -1;
   }
   else if (root->right == NULL)
      return root->data;

   return FindMax(root->right);
}

bool Search(BstNode *root, int data)
{
   if (root == NULL)
      return false;
   else if (root->data == data)
      return true;
   else if (data <= root->data)
      return Search(root->left, data);
   else
      return Search(root->right, data);
}

BstNode *Insert(BstNode *root, int data)
{
   if (root == NULL)
   {
      BstNode *newNode = GetNewNode(data);
      root = newNode;
   }
   else if (data <= root->data)
   {
      root->left = Insert(root->left, data);
   }
   else if (data > root->data)
   {
      root->right = Insert(root->right, data);
   }
   return root;
}

int height(BstNode *root)
{
   if (root == NULL)
      return -1;
   int left = height(root->left);
   int right = height(root->right);
   int height = max(left, right) + 1;

   return height;
}

int main()
{
   BstNode *root = NULL;
   root = Insert(root, 15);
   root = Insert(root, 20);
   root = Insert(root, 10);
   root = Insert(root, 25);
   root = Insert(root, 200);
   root = Insert(root, 17);
   root = Insert(root, 8);
   root = Insert(root, 2);
   root = Insert(root, 12);
   root = Insert(root, 13);
   root = Insert(root, 11);

   Search(root, 13)
       ? cout << "13 Found\n"
       : cout << "13 Not Found\n";
   Search(root, 113)
       ? cout << "113 Found\n"
       : cout << "113 Not Found\n";
   int min = FindMin(root);
   int max = FindMax(root);
   int h = height(root);
   cout << "Minimum key in the tree is: " << min << "\n";
   cout << "Maximum key in the tree is: " << max << "\n";
   cout << "Height of the tree is: " << h << "\n";

   return 0;
}