def bubble_sort(arr):
    n = len(arr)
    # Traverse through all array elements
    for i in range(n):
        # Last i elements are already in place, so we don't need to check them again
        for j in range(0, n-i-1):
            # Swap if the element found is greater than the next element
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

# Example usage:
if __name__ == "__main__":
    # Sample input array
    arr = [64, 34, 25, 12, 22, 11, 90]
    
    print("Original array:", arr)
    
    bubble_sort(arr)  # Call the bubble_sort function to sort the array
    
    print("Sorted array:", arr)
