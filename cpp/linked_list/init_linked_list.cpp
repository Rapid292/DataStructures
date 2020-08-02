#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
};

void insert(int x, Node *head)
{

   Node *temp;
   temp->data = x;
   temp->next = head;

   head = temp;
}

void print(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << endl;
      head = head->next;
   }
}

int main()
{
   Node *head = NULL;
   Node *second = NULL;
   Node *third = NULL;

   head = new Node();
   second = new Node();
   third = new Node();

   head->next = second;
   head->data = 1;
   second->next = third;
   second->data = 2;
   third->next = NULL;
   third->data = 3;

   print(head);

   return 0;
}