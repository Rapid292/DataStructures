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
         return root;
         */
      }
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
// BFS - LevelOrderTraversal
void levelOrder(BstNode *root)
{
   queue<BstNode *> q;
   q.push(root);
   if (root == NULL)
      return;
   while (!q.empty())
   {
      BstNode *current = q.front();
      if (current->left != NULL)
         q.push(current->left);
      if (current->right != NULL)
         q.push(current->right);
      cout << current->data << " ";
      q.pop();
   }
   cout << "\n\n";
}

// DFS Algorithms
// PreOrder Traversal - DLR

void preOrder(BstNode *root)
{
   if (root == NULL)
      return;
   cout << root->data << " ";
   preOrder(root->left);
   preOrder(root->right);
}

// InOrder Traversal - LDR
void inOrder(BstNode *root)
{
   if (root == NULL)
      return;
   inOrder(root->left);
   cout << root->data << " ";
   inOrder(root->right);
}

// PostOrder Traversal - LRD
void postOrder(BstNode *root)
{
   if (root == NULL)
      return;
   postOrder(root->left);
   postOrder(root->right);
   cout << root->data << " ";
}

// Is tree is BST or Not

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
//

int main()
{
   BstNode *root = NULL;
   root = Insert(root, 6);
   root = Insert(root, 3);
   root = Insert(root, 9);
   root = Insert(root, 1);
   root = Insert(root, 5);
   root = Insert(root, 7);
   root = Insert(root, 10);
   root = Insert(root, 4);
   root = Insert(root, 8);

   Search(root, 10)
       ? cout << "10 Found\n"
       : cout << "10 Not Found\n";
   Search(root, 113)
       ? cout << "113 Found\n"
       : cout << "113 Not Found\n";
   int min = FindMin(root);
   int max = FindMax(root);
   int h = height(root);
   cout << "Minimum key in the tree is: " << min << "\n";
   cout << "Maximum key in the tree is: " << max << "\n";
   cout << "Height of the tree is: " << h << "\n";

   cout << "PreOrder Traversal :\n";
   preOrder(root);
   cout << "\n\n";

   cout << "InOrder Traversal :\n";
   inOrder(root);
   cout << "\n\n";

   cout << "PostOrder Traversal :\n";
   postOrder(root);
   cout << "\n\n";

   cout << "LevelOrder Traversal :\n";
   levelOrder(root);

   checkBST(root) ? cout << "It is a Binary Search Tree\n\n" : cout << "Not a BST\n\n";

   root = Delete(root, 1);
   cout << "InOrder Traversal :\n";
   inOrder(root);
   cout << "\n\n";

   root = Insert(root, 200);
   cout << "InOrder Traversal :\n";
   inOrder(root);
   cout << "\n\n";

   return 0;
}