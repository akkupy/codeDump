#include<bits/stdc++.h>
using namespace std;
#define f(x) x*x*x-5*x*-7*x-17

long double bis(long  double x,long  double y)
{
	while(abs(x-y)>0.000000001)
	{
		long double temp=(x+y)/2.0;
		if(f(temp)>0)
		{
			y=temp;
		}
		else if (f(temp)==0)
		{
			return temp;
		}
		else{
			x=temp;
		}
	}
	return x;
}

void solve()
{
	long  double ans=bis(-100,100);
	cout<<ans<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}