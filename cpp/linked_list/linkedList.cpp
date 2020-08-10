#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *link;
};

Node *head;

void printList()
{
   Node *temp;
   temp = head;
   cout << "List :" << endl;
   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->link;
   }
   cout << endl;
}
void insertNode(int data, int pos = 1)
{
   Node *temp1, *temp2;
   temp1 = new Node();
   temp1->data = data;
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

void deleteNodePosition(int pos)
{
   Node *temp1, *temp2;
   temp1 = head;
   if (pos == 1)
   {
      head = temp1->link;
   }
   for (int i = 0; i < pos - 2; i++)
   {
      temp1 = temp1->link;
   }
   temp2 = temp1->link;
   temp1->link = temp2->link;
   delete temp2;
   return;
}

void deleteNodeValue(int x)
{
   Node *temp, *prev;
   temp = head;
   while (temp->data != x)
   {
      prev = temp;
      temp = temp->link;
   }
   prev->link = temp->link;
   delete temp;
   return;
}

void reverseList()
{
   Node *current, *prev, *next;

   current = head;
   prev = NULL;
   while (current != NULL)
   {
      next = current->link;
      current->link = prev;
      prev = current;
      current = next;
   }
   head = prev;
}

void recursionPrintList(Node *p)
{
   if (p == NULL)
   {
      cout << endl;
      return;
   }
   cout << p->data << " ";
   recursionPrintList(p->link);
}

void recursionReversePrint(Node *p)
{
   if (p == NULL)
   {
      cout << endl;
      return;
   }
   recursionReversePrint(p->link);
   cout << p->data << " ";
}

void reverseListRecursion(Node *p)
{
   if (p->link == NULL)
   {
      head = p;
      return;
   }
   reverseListRecursion(p->link);
   p->link->link = p;
   p->link = NULL;
}

int main()
{
   head = NULL;

   insertNode(1);
   insertNode(2, 2);
   insertNode(3, 3);
   insertNode(4, 4);
   insertNode(10, 2);
   insertNode(5, 5);
   printList();
   // deleteNodeValue(5);
   // printList();
   // deleteNodePosition(3);
   // printList();
   // reverseList();
   // printList();
   // recursionPrintList(head);
   reverseListRecursion(head);
   printList();
   // recursionReversePrint(head);

   return 0;
}