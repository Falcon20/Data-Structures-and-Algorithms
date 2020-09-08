// Problem link - https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
//Video tutorial - https://www.youtube.com/watch?v=g_hIx4yn9zg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=20
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[105][105];
int lcs(string s1, string s2, int n, int m)
{
    if(n == 0 || m == 0)
    return 0;
    if(dp[n][m] != -1)
    return dp[n][m];
    if(s1[n-1] == s2[m-1])
    {
        return dp[n][m] = 1+ lcs(s1, s2, n-1,m-1);
    }
    else
    return dp[n][m] = max(lcs(s1, s2, n-1,m), lcs(s1, s2, n,m-1));
}
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        memset(dp, -1,sizeof(dp));
        string s1,s2;
        cin>>n>>m;
        cin>>s1>>s2;
        cout<<lcs(s1,s2,n,m)<<"\n";
    }
	
	return 0;
}