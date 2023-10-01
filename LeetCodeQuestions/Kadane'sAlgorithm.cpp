#include <bits/stdc++.h>
using namespace std;

/*Given an integer array arr, find the 
subarray with the largest sum, and return its sum.*/

long long maxSubarraySum(int arr[], int n)
{
    long long int ans=0, sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<0)
            sum=0;
        ans = max(ans, sum);
    }
    return ans;
}

int main()
{
    cout<<"Enter the number of elements:"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the elements:"<<endl;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    long long answer = maxSubarraySum(arr, n);
    cout<<"The maximum subarray sum is:"<<endl;
    cout<<answer<<endl;
}