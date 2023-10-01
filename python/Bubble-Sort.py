def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]  # Swap the elements
                swapped = True
        if not swapped:
            break

if __name__ == "__main__":
    arr = [64, 25, 12, 22, 11]
    bubble_sort(arr)
    print("Sorted array is:", arr)
