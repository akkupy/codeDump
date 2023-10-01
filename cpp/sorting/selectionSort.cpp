#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[i]) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
}

int main27() {
  int n = 6;
  int arr[6] = {12, 32, 2, 21, 66, 1};
  SelectionSort(arr, n);
}