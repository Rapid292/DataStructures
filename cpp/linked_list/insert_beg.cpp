#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
   int data;
   Node *next;
};

void insertBeg(int e, Node **head)
{
   Node *temp;
   temp = new Node();
   temp->data = e;
   temp->next = *head;
   *head = temp;
}

void printList(Node *head)
{
   cout << "Your list is: ";
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}

int main()
{
   Node *head;
   head = NULL;
   int e, n;
   cout << "Number of elements ?" << endl;
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cout << "Insert element: " << endl;
      cin >> e;
      insertBeg(e, &head);
      printList(head);
   }

   return 0;
}
