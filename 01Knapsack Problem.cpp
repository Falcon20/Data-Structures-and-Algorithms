// 0/1 Knapsack Problem 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll t,n,W;
	cin>>t;// test cases
	while(t--)
	{
		cin>>n>>W;// no of items and bag capacity
 		ll val[n+1],wt[n+1];// arrays to store the value and weight of items 
 		val[0]=0,wt[0]=0;
		for(ll i=1;i<=n;++i)
		{
			cin>>val[i];	
		}
		for(ll i=1;i<=n;++i)
		{
			cin>>wt[i];	
		}
		ll dp[n+1][W+1];
		for(int i=0;i<=n;++i)
		dp[i][0]=0;
		for(int i=0;i<=W;++i)
		dp[0][i]=0;
		for(int i=1;i<=n;++i)
		{
			for(ll j=1;j<=W;++j)
			{
				if(j<wt[i])
				dp[i][j]=dp[i-1][j];
				else
				{
					dp[i][j]=max(dp[i-1][j],val[i]+dp[i-1][j-wt[i]]);
					// if we are not selecting the current item than dp[i-1][j]
					// else we select that item and add its value val[i] with the best ,thus dp[i-1][j-wt[i]]; 
				}
			}
		}
		cout<<dp[n][W]<<"\n";
		
	}
	return 0;
}
