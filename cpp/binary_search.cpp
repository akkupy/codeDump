#include <bits/stdc++.h>
using namespace std;


// Binary search function
int binary_search(const vector<int>& arr, int tar) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == tar) {
            return mid;
        } else if (arr[mid] < tar) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tar = 5;

    int result = binary_search(arr, tar);

    if (result != -1) {
        cout << "Element " << tar << " found at index " << result << endl;
    } else {
        cout << "Element " << tar << " not found in the given array." << endl;
    }

    return 0;
}
