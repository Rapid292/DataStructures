#include <bits/stdc++.h>
using namespace std;

void insertionSort(int A[], int n)
{
   for (int i = 0; i < n; i++)
   {
      int key = i - 1;
      int value = A[i];

      while (key >= 0 && A[key] > value)
      {
         A[key + 1] = A[key];
         key--;
      }
      A[key + 1] = value;
   }
}
int main()
{
   int A[] = {7, 9, 5, 2, 3, 0, 100};
   int n = 7;
   insertionSort(A, n);
   for (int i = 0; i < n; i++)
   {
      cout << A[i] << " ";
   }

   return 0;
}