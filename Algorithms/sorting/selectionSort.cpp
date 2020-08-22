/*Selection Sort(A, n) 
   {
      for i=0 to n-2
      {
        imin = i
         for j=i+1 to n-1
         {
          check(A[j] < A[imin])
            imin = j
         }
         swap(A[imin], A[j])
      }
   }
*/

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int A[], int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      int imin = i;
      for (int j = i + 1; j < n; j++)
      {
         if (A[j] < A[imin])
         {
            imin = j;
         }
      }
      int temp = A[i];
      A[i] = A[imin];
      A[imin] = temp;
   }
}

int main()
{
   int A[] = {7, 9, 3, 4, 0, 1};
   selectionSort(A, 6);
   for (int i = 0; i < 6; i++)
   {
      cout << A[i] << " ";
   }

   return 0;
}