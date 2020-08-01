#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
};

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

   return 0;
}