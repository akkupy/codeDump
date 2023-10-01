#include<iostream>
using namespace std;
// Bubble Sort
int main()
{
    int n;
    cout<<"enter the size of the array ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int counter=1,temp;
    while(counter<=n-1)
    {
        for(int i=0;i<n-counter;i++)
        {
            if(a[i]>a[i+1])
            {
                 temp=a[i];
                 a[i]=a[i+1];
                 a[i+1]=temp;
            }
        }
        counter++;
    }
    cout<<"The sorted array is "<<endl;
    for(int j=0;j<n;j++)
    {
        cout<<a[j]<<" ";
    }
}