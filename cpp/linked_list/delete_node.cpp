#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *link;
};

Node *head;

void insert(int element, int position = 1)
{
   Node *temp1, *temp2;
   temp1 = new Node();
   temp1->data = element;

   if (position == 1)
   {
      temp1->link = head;
      head = temp1;
      return;
   }
   temp2 = head;
   for (int i = 0; i < position - 2; i++)
   {
      temp2 = temp2->link;
   }
   temp1->link = temp2->link;
   temp2->link = temp1;
}

void printList()
{
   Node *temp;
   temp = head;
   cout << "List : ";
   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->link;
   }
   cout << "\n";
}

void deleteNode(int position)
{
   Node *temp1, *temp2;
   temp1 = head;
   if (position == 1)
   {
      head = temp1->link;
      delete temp1;
   }
   for (int i = 0; i < position - 2; i++)
   {
      temp1 = temp1->link;
   }
   temp2 = temp1->link;
   temp1->link = temp2->link;

   delete temp2;
}

int main()
{
   int pos;
   head = NULL;

   insert(4);
   insert(5);
   insert(9);
   insert(20, 4);
   printList();

   cout << "Enter the position you want to delete: " << endl;
   cin >> pos;

   deleteNode(pos);
   printList();

   return 0;
}