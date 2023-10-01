#include <iostream>
using namespace std;

int search(int arr[],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==num)
        return i;
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Enter number of array elements: ";
    cin>>n;
      cout<<"Enter array elements: ";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

  cout<<"enter element to search for: ";
    int num;
    cin>>num;

    int val = search(arr,n,num);
   cout<<"Element is found at index: "<< val;
}
