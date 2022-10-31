#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,arr[100],temp,i,j;
	cin >> n; // No. of integers
	for(i=0;i<n;i++)
		cin >> arr[i];

	for(i=1;i<n;i++)
	{
		temp = arr[i];
		j=i-1;
		while(j>=0 && arr[j] > temp )
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}

	for(i=0;i<n;i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
	return 0;
}