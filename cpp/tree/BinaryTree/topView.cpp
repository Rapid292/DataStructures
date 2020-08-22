#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
   int data;
   Node *left;
   Node *right;
   Node(int d)
   {
      data = d;
      left = NULL;
      right = NULL;
   }
};

class Solution
{
public:
   Node *insert(Node *root, int data)
   {
      if (root == NULL)
      {
         return new Node(data);
      }
      else
      {
         Node *cur;
         if (data <= root->data)
         {
            cur = insert(root->left, data);
            root->left = cur;
         }
         else
         {
            cur = insert(root->right, data);
            root->right = cur;
         }

         return root;
      }
   }

   /*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
   void topView(Node *root)
   {
      if (root == NULL)
         return;
      queue<pair<int, Node *>> q;
      map<int, Node *> m;

      q.push(make_pair(0, root));
      while (q.size())
      {
         pair<int, Node *> p = q.front();
         int hd = p.first;
         Node *current = p.second;

         if (m.count(hd) == 0)
         {
            // m.insert(p);
            m[p.first] = p.second;
         }
         if (current->left)
            q.push(make_pair(hd - 1, current->left));
         if (current->right)
            q.push(make_pair(hd + 1, current->right));
         q.pop();
      }
      for (auto i = m.begin(); i != m.end(); i++)
         cout << (*i).second->data << " ";
   }

}; //End of Solution

int main()
{

   Solution myTree;
   Node *root = NULL;

   myTree.insert(root, 100);
   myTree.insert(root, 2);
   myTree.insert(root, 5);
   myTree.insert(root, 3);
   myTree.insert(root, 6);
   myTree.insert(root, 4);
   // myTree.insert(root, 12);
   // myTree.insert(root, 13);
   // myTree.insert(root, 11);

   myTree.topView(root);
   return 0;
}
