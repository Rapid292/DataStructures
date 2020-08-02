#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *link;
};

Node *head;

void insertNode(int x, int pos = 1)
{
   Node *temp1, *temp2;
   temp1 = new Node();
   temp1->data = x;
   if (pos == 1)
   {
      temp1->link = head;
      head = temp1;
      return;
   }
   temp2 = head;
   for (int i = 0; i < pos - 2; i++)
   {
      temp2 = temp2->link;
   }
   temp1->link = temp2->link;
   temp2->link = temp1;
   return;
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

void reverseList(Node *p)
{
   if (p->link == NULL)
   {
      head = p;
      return;
   }
   reverseList(p->link);
   // Node *q;
   // q = p->link;
   // q->link = p;
   p->link->link = p;
   p->link = NULL;
   return;
}

int main()

{
   head = NULL;
   insertNode(2);
   insertNode(4, 2);
   insertNode(6, 3);
   insertNode(8, 4);
   cout << "List : ";
   printList(head);
   reverseList(head);
   cout << "List : ";
   printList(head);

   return 0;
}