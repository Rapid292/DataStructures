#include <bits/stdc++.h>

using namespace std;
#define MAX_SIZE 101

class Stack
{
private:
   int arr[MAX_SIZE];
   int top;

public:
   Stack()
   {
      top = -1;
   }

   void push(int x)
   {
      if (top == MAX_SIZE - 1)
      {
         cout << "Error : Stack OverFlow" << endl;
         return;
      }
      arr[++top] = x; // top = top + 1; arr[top] = x;
   }

   int pop()
   {
      if (top == -1)
      {
         cout << "No Element in the Stack " << endl;
         return top;
      }
      return arr[top--];
   }

   int topValue()
   {
      return arr[top];
   }

   bool isEmpty()
   {
      if (top == -1)
         return true;
      return false;
   }

   bool isFull()
   {
      if (top == MAX_SIZE - 1)
         return true;
      return false;
   }

   void print()
   {
      cout << "Stack : ";
      for (int i = 0; i <= top; i++)
      {
         cout << arr[i] << " ";
      }
      cout << endl;
   }
};

int main()
{
   Stack S;
   S.push(2);
   S.print();
   S.push(5);
   S.print();
   S.push(9);
   S.print();
   S.push(12);
   S.print();
   int y = S.pop();
   cout << "Popped Out: " << y << endl;
   S.print();
   int x = S.topValue();
   cout << "Top: " << x << endl;
   cout << S.isEmpty() << endl;
   cout << S.isFull() << endl;
}