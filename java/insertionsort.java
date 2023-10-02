package com.company.Sorting;

import java.util.Arrays;

public class InsertionSort {

    public static void insertionSort(int [] arr){
        int key, j;
        for (int i = 1; i < arr.length; i++) {
            key = arr[i];
            j = i - 1;
            while (arr[j] > key && j >= 0){
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    public static void main(String[] args) {
        int [] arr = {17,11,5,9,8,35,4};
        System.out.println(Arrays.toString(arr));
        insertionSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}