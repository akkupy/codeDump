import java.util.Arrays;

public class SortColors {
    public static void main(String[] args) {
        int[] arr = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};
        System.out.println("Original color array:- " + Arrays.toString(arr));
//        bruteSortColors(arr);
        sortColors(arr);
        System.out.println("Sorted color array:- " + Arrays.toString(arr));
    }

    // Brute Approach:-
    /*
     Taking a count of 0, 1, 2
     Like how many of them are there
     and then
     mark iteratively according to their count
     for ex:- if 0 appears 2 times in an array
     if 1 appears 3 times in an array
     and 2 appears 4 times in an array
     then in the original array
     run the loop for 2times
     and make the 1st 2 elements 0
     similarly do it for 1st and 2nd
    */
    static void bruteSortColors(int[] nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        for (int i = 0; i < nums.length; i++){
            if(nums[i] == 0) count0++;
            else if(nums[i] == 1) count1++;
            else count2++;
        }

        for(int i = 0; i < count0; i++) nums[i] = 0;
        for (int i = count0; i < count0 + count1; i++) nums[i] = 1;
        for (int i = count0 + count1; i < nums.length; i++) nums[i] = 2;
    }

    // Optimal Approach:-
    // Dutch National Flag Algorithm
    /*
        The problem was posed with three colors, here `0′, `1′ and `2′.
        The array is divided into four sections:
            arr[1] to arr[low – 1]
            arr[low] to arr[mid – 1]
            arr[mid] to arr[high – 1]
            arr[high] to arr[n]
        If the ith element is 0 then swap the element to the low range.
        Similarly, if the element is 1 then keep it as it is.
        If the element is 2 then swap it with an element in high range.
     */
    static void sortColors(int[] nums) {
        int n = nums.length;

        // these are pointers
        int low = 0;
        int mid = 0;
        int high = n - 1;


        while(high >= mid) {
            if (nums[mid] == 0){
                swap(nums, low, mid);
                low++;
                mid++;
            }
            else if (nums[mid] == 1){
                mid++;
            }
            else {
                swap(nums, mid, high);
                high--;
            }
        }
    }
    // swap function
    static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}
