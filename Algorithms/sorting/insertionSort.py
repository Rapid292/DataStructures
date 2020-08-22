def insertionSort(A, n):
    for i in range(1, n):
        key = i - 1
        value = A[i]
        while key >= 0 and A[key] > value:
            A[key + 1] = A[key]
            key -= 1
        A[key + 1] = value


if __name__ == "__main__":
    A = [7, 1, 5, 2, 3, 0, 100]
    n = 7
    insertionSort(A, n)
    print(A)
