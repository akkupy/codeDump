def countingSort(array):
    size = len(array)

    output, count = [0] * size, [0] * 10

    for i in range(size):
        count[array[i]] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(size - 1, -1, -1):
        output[count[array[i]] - 1] = array[i]
        count[array[i]] -= 1

    return output


data = [4, 2, 2, 8, 3, 3, 1]
print(f"Sorted Array in Ascending Order: {countingSort(data)}")
