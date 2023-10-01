
#include <bits/stdc++.h>

using namespace std;

vector < int > FindUnionOfTwoArray(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

int main()

{
  int n,  m ;
  cout<<"Enter two numbers(size of arrays): ";
  cin>>n>>m;
  cout<<"Enter first array elements ";
  int arr1[n];
  int arr2[m];
  for(int i=0; i<n; i++){
      cin>>arr1[i];
  }
  cout<<"Enter second array elements ";
  for(int i=0; i<m; i++){
      cin>>arr2[i];
  }

  vector < int > Union = FindUnionOfTwoArray(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}
