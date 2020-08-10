#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
   Node *prev;
};

Node *head;

Node *getNewNode(int x)
{
   Node *temp = new Node();
   temp->data = x;
   temp->next = NULL;
   temp->prev = NULL;

   return temp;
}

void printList()
{
   Node *temp = head;
   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }
   cout << endl;
}

void printReverseList()
{
   Node *temp;
   temp = head;
   if(temp==NULL) return;
   
   while (temp->next != NULL)
   {
      temp = temp->next;
   }
   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->prev;
   }
   cout << endl;
}

void insertNode(int x, int pos = 1)
{
   Node *newNode, *temp;
   newNode = getNewNode(x);
   if (head == NULL)
   {
      head = newNode;
      return;
   }
   else if (pos == 1)
   {
      head->prev = newNode;
      newNode->next = head;
      head = newNode;
      return;
   }
   temp = head;
   for (int i = 0; i < pos - 2; i++)
   {
      temp = temp->next;
   }
   newNode->prev = temp;
   newNode->next = temp->next;
   temp->next = newNode;
   if (newNode->next != NULL)
   {
      newNode->next->prev = newNode;
   }
}

int main()
{
   head = NULL;
   insertNode(4);
   insertNode(8, 2);
   insertNode(10, 3);
   printList();
   insertNode(1, 3);
   printList();
   printReverseList();

   return 0;
}