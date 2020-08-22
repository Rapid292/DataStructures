def selectionSort(A, n):
   for i in range(n-1):
      imin = i
      for j in range(i+1, n):
         if A[j] < A[imin]:
            imin = j
      A[imin], A[i] = A[i], A[imin]

A = [7, 9, 5, 2, 3, 0, 100]

if __name__ == "__main__":
   selectionSort(A, 7)
   print(A)