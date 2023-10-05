#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n=5;
    int arr[n]={12,4,32,2,23};
    int profit;
    int x=0;
    int buy=arr[0];
    for (int i = 0; i <n; i++)
    {
        profit=arr[i]-buy;
        buy=min(arr[i],buy);
        x=max(x,profit);
    }
    cout<<x;
    return 0;
}
