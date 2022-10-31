#include <bits/stdc++.h>
using namespace std;

struct edge // Edge Template
{
	int u,v,w;
};

int dsu[5000005];
int find(int u)
{
	while(dsu[u]!=-1)
	{
		u = dsu[u];
	}
	return u;  // root 
}

void Union(int u,int v)
{
	u=find(u) ; v=find(v); // now u contain parent of u and v contains the parent of v
	if(u==v) // if both has same parent 
		return ;
	else
		dsu[u]=v; // u become child of v
}

bool cmp(edge i1,edge i2)  // Comparator function
{
	if(i1.w==i2.w)
		return (i1.w+i1.u+i1.v < i2.w+i2.u+i2.v); // Just remember (a<b) sort in ascending order 
	else
		return (i1.w<i2.w); // i.e swap occurs only if i1.w > i2.w ....
}
int main()
{
	int i,n,m,w,u,v,ans=0;
	edge E[500005]; // show 1000 edges
	cin>>n>>m; // n is no. of vertices and m is the no. of edges 

	for(i=0;i<m;i++)
		cin >>E[i].u >>E[i].v >>E[i].w;

	for(i=1;i<=n;i++)
		dsu[i]=-1; // shows that vertex has no parent

	sort(E,E+m,cmp); // sort the edges on the basis of (u+v+w)

	for(i=0;i<m;i++)
	{
		u=find(E[i].u); v=find(E[i].v);// root of u and v

		if(u!=v)
			ans += E[i].w;

		Union(E[i].u,E[i].v);
	}
	printf("%d\n",ans);
	return 0;
}