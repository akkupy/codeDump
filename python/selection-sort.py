def selection_sort(arr):
    for i in range(len(arr)-1):
        min_index =i
        for j in range(i+1,len(arr)):
            if arr[j] < arr[min_index]:
                min_index=j

        if i!=min_index:
            temp=arr[i]
            arr[i]=arr[min_index]
            arr[min_index]=temp



arr=[2,34,1,25,7,8]
print(arr , end="\n")
selection_sort(arr)
print(arr)