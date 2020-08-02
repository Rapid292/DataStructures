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
   Node *temp = head;
   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->link;
   }
   cout << endl;
}

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
}

void reverseList()
{
   Node *prev, *current, *next;
   prev = NULL;
   current = head;

   while (current != NULL)
   {
      // cout << "Reversing..." << endl;
      next = current->link;
      current->link = prev;
      prev = current;
      current = next;
   }
   head = prev;
}

int main()
{
   head = NULL;
   insertNode(4);
   insertNode(5);
   insertNode(2);
   insertNode(49, 4);
   printList();
   reverseList();
   printList();

   return 0;
}