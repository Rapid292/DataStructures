#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
};

Node *head;

void printList()
{
   Node *temp;
   temp = head;
   cout << "List : ";
   while (temp != NULL)
   {
      cout << temp->data << " ";
      temp = temp->next;
   }
   cout << endl;
}

void insertNth(int element, int position = 1)
{
   Node *temp1, *temp2;
   temp1 = new Node();
   temp1->data = element;
   if (position == 1)
   {
      temp1->next = head;
      head = temp1;
   }
   else
   {
      temp2 = head;
      for (int i = 0; i < position - 2; i++)
      {
         temp2 = temp2->next;
      }
      temp1->next = temp2->next;
      temp2->next = temp1;
   }
   return;
}

int main()
{
   int n, e, p;
   head = NULL;
   cout << "Number of elements ?" << endl;
   cin >> n;

   for (int i = 0; i < n; i++)
   {
      cout << "Insert element: " << endl;
      cin >> e;
      if (i >= 1)
      {
         cout << "Position: " << endl;
         cin >> p;

         while (p > i + 1)
         {
            cout << "please enter a valid position: ";
            cin >> p;
         }
         insertNth(e, p);
      }
      else
      {
         insertNth(e);
      }

      printList();
   }

   return 0;
}
