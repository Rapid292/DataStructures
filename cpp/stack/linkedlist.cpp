#include <bits/stdc++.h>

using namespace std;

class Node
{
private:
   int data;
   Node *link;

public:
   Node *top;
   void push(int x)
   {
      Node *temp;
      temp = new Node();

      if (!temp)
      {
         cout << "\nStack OverFlow";
      }
      temp->data = x;
      temp->link = top;
      top = temp;
      return;
   }

   bool isEmpty()
   {
      return (top == NULL);
   }

   int peek()
   {
      if (isEmpty())
      {
         exit(1);
      }
      return top->data;
   }

   int pop()
   {
      if (isEmpty())
      {
         cout << "Stack UnderFlow\n";
         exit(1);
      }
      Node *temp = top;
      top = top->link;
      int data = temp->data;
      delete temp;
      return data;
   }

   void display()
   {
      if (top == NULL)
      {
         cout << "Stack UnderFlow\n";
         exit(1);
      }
      Node *temp = top;
      cout << "Your Stack is :\n";
      while (temp != NULL)
      {
         cout << temp->data << " ";
         temp = temp->link;
      }
      cout << "\n";
   }
};

int main()
{
   Node S;
   S.top = NULL;
   S.push(11);
   S.push(22);
   S.push(33);
   S.push(44);
   S.display();
   int a = S.pop();
   int b = S.pop();
   cout << "Popped elements are :" << a << " " << b << "\n";
   S.display();
   cout << "\nTop element is :\n"
        << S.peek();
   return 0;
}