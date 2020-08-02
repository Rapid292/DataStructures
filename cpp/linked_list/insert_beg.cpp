#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
};

Node *head;

void insertBeg(int e)
{
   Node *temp;
   temp = new Node();
   temp->data = e;
   temp->next = head;
   head = temp;
}

void printList()
{
   cout << "Your list is: ";
   Node *temp1 = head;
   while (temp1 != NULL)
   {
      cout << temp1->data << " ";
      temp1 = temp1->next;
   }
   cout << "\n";
}

int main()
{
   head = NULL;
   int e, n;
   cout << "Number of elements ?" << endl;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cout << "Insert element: " << endl;
      cin >> e;
      insertBeg(e);
      printList();
   }

   return 0;
}
