#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int A[], int n)
{
   for (int i = 0; i < n; i++)
   {
      int flag = 0;
      for (int j = 0; j < n - i - 1; j++)
      {
         if (A[j] > A[j + 1])
         {
            int temp = A[j];
            A[j] = A[j + 1];
            A[j + 1] = temp;
            flag = 1;
         }
      }
      if (flag == 0)
         break;
   }
}
int main()
{
   int A[] = {4,
              5,
              78,
              9,
              420,
              33};
   int n = 6;
   bubbleSort(A, n);
   for (int i = 0; i < n; i++)
   {
      cout << A[i] << " ";
   }

   return 0;
}