package com.company.Sorting;

import java.util.Arrays;

public class BubbleSort {

    public static void bubbleSort(int [] arr){
        int temp = 0;
        for (int j = 0; j < arr.length; j++)
        {
            for (int i = 0; i < arr.length - 1; i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
        }

    }

    public static void main(String[] args) {
        int [] arr = {17,11,5,9,8,35,4};
        System.out.println(Arrays.toString(arr));
        bubbleSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}