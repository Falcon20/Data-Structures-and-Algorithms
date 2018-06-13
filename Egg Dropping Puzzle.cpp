// The following is the complete solution of the famous dynamic programming problem -The Egg Dropping puzzle
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;// no. of egg and no. of floors
		ll a[n+1][k+1];
		for(ll i=0;i<=k;++i)
		{
		a[0][i]=0;// If no of eggs is zero we require zero attempts to find out the floor
		a[1][i]=i;// If no of eggs are one then we need i attempts for ith floor
		
		}
		
		for(ll i=0;i<=n;++i)
		{
			a[i][0]=0;// If no of floors is zero then we require zero attempts
			a[i][1]=1;// If no of floors is one then we require one attempt
		}
		for(ll i=2;i<=n;++i)
		{
			for(ll j=2;j<=k;++j)
			{
				if(i>j)
				a[i][j]=a[i-1][j];
				else
				{
					ll ans=INT_MAX;
					for(ll z=1;z<=k;++z)
					{
						ll res=max(a[i-1][z-1],a[i][j-z]);//a[i-1][z-1] if egg breaks on floor z then we are left with i-1 eggs 
						if(res<ans)// and z-1 floors to work with else if it doesn't break then we are having i eggs and j-z floors
						ans=res;
					}
					a[i][j]=ans+1;
				}
			}
		}
		// to print the complete table
		for(ll i=0;i<=n;++i)
		{
			for(ll j=0;j<=k;++j)
			cout<<a[i][j]<<" ";
			cout<<"\n";
		}
		cout<<a[n][k]<<"\n";// final result
		
	}
	return 0;
}
