#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int q;
    cout << "Enter number of queries : ";
    cin >> q;
    while (q > 0) {
        int n;
        cout << "Enter number of elements in the array: ";
        cin >> n;
        int a[n];
        cout << "Now enter the elements: "; 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << "Before sorting, arrar is : ";
        for (auto it : a) cout << it << " ";
        cout << endl;
        insertion_sort(a, n);
        cout << "Affter sorting, array is : ";
        for (auto it : a) cout << it << " ";
        cout << endl << endl;
        q--;
    }
    return 0;
}