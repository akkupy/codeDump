#include<stdio.h>
void readarr();
void MergeSort(int first,int last);
void Merge(int first,int mid,int last);
void printarr();
int arr[100],size;

void main() {
    printf("Enter the Size of the Array : ");
    scanf("%d",&size);
    readarr();
    MergeSort(0,size-1);
    printarr(size);
}

void readarr() {   
    printf("Enter the Elements of the Array : ");
    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);
}

void MergeSort(int first, int last) {  
    int mid;
    if(first < last) {
        mid = (first + last)/2;
        MergeSort(first,mid);
        MergeSort(mid+1,last);
        Merge(first,mid,last);
    }
}

void Merge(int first, int mid, int last) {
    int temp[size];
    int i = first, k = first, j = mid+1;
    while( i <= mid && j <= last) {
        if(arr[i] >= arr[j])
            temp[k++] = arr[j++];
        else 
            temp[k++] = arr[i++];
    }

    while( i<= mid)
        temp[k++] = arr[i++];
    while( j <= last)
        temp[k++] = arr[j++];

    for(i=first;i<=last;i++)
        arr[i] = temp[i]; 
}

void printarr() {   
    printf("The Sorted Array is : ");
    for(int j =0; j<size; j++)
        printf("%d ",arr[j]);
}
