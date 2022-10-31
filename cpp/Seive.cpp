/* If a number n is not a prime, it can be factored into two factors a and b:

n = a*b

If both a and b were greater than the square root of n, a*b would be greater 
than n. So at least one of those factors must be less or equal to the square
root of n, and to check if n is prime, we only need to test for factors less 
than or equal to the square root.

*/

#include <bits/stdc++.h>
using namespace std;
int arr[10000005];
int main()
{
	int n,i,j;
	cin >> n; // i.e Prime Till n
	memset(arr,0,n*sizeof(int)); // It's better to make bool array.
	for(i=2;i*i<=n;i++)
	{
		if( arr[i] == 0)
		{
			// More efficient
			// Factors less than i*i will already covered by smallers numbers.
			// E.g. say i=7. So, we start from 49 and 14,21,28,35,42 were 
			// already marked as not prime by 2,3,4,5,6 respectively.
			for(j=i*i;j<=n;j+=i)
				arr[j]=1;

			// Less efficient
			// for(j=2;i*j<=n;j++) 
			// 	arr[i*j]=1;
		}
	}
	int count=0;
	for(i=2;i<n;i++)
	{
		if( arr[i] == 0)
		{
			count++;
			cout << i  << " ";
		}

	}
	cout << endl;
	cout << count << endl;
	return 0;
}
