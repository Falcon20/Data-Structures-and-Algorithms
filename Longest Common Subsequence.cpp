#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	string st1,st2;
	cin>>t;
	while(t--)
	{
		cin>>st1>>st2;
		int l1=st1.length();
		int l2=st2.length();
		int dp[l1+1][l2+1];
		for(int i=0;i<=l1;++i)
		dp[i][0]=0;
		for(int i=0;i<=l2;++i)
		dp[0][i]=0;
		for(int i=1;i<=l1;++i)
		{
			for(int j=1;j<=l2;++j)
			{
				if(st1[i-1]==st2[j-1])
				{
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else
				{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		for(int i=0;i<=l1;++i)
		{
			for(int j=0;j<=l2;++j)
			cout<<dp[i][j]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
