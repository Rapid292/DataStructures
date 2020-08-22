def bubbleSort(A, n):
   for i in range(n):
      flag = 0
      for j in range(n-i-1):
         if A[j] > A[j+1]:
            A[j], A[j+1] = A[j+1], A[j]
            flag = 1

      if(flag == 0):
         break

if __name__ == "__main__":
    A = [0, 8, 90, 890, 4, 45, 7]
    n = 7
    bubbleSort(A, n)
    print(A)
