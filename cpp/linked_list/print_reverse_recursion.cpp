#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
   int data;
   Node *link;
};

Node *insertNode(int x, Node *h, int pos = 1)
{
   Node *temp1, *temp2;
   temp1 = new Node();
   temp1->data = x;
   if (pos == 1)
   {
      temp1->link = h;
      h = temp1;
      return h;
   }
   temp2 = h;
   for (int i = 0; i < pos - 2; i++)
   {
      temp2 = temp2->link;
   }
   temp1->link = temp2->link;
   temp2->link = temp1;

   return h;
}

void printList(Node *h)
{
   if (h == NULL)
   {
      cout << endl;
      return;
   }
   cout << h->data << " ";
   printList(h->link);
}
void printReverseList(Node *h)
{
   if (h == NULL)
   {
      return;
   }
   printReverseList(h->link);
   cout << h->data << " ";
}

int main()
{
   Node *head;
   head = NULL;
   head = insertNode(8, head);
   head = insertNode(0, head);
   head = insertNode(34, head, 1);
   head = insertNode(89, head, 2);
   head = insertNode(2, head, 5);
   cout << "In forward order: ";
   printList(head);
   cout << "In reverse order: ";
   printReverseList(head);

   return 0;
}