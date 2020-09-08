// Problem link - https://practice.geeksforgeeks.org/problems/longest-common-substring/0
// Video Tutorial - https://www.youtube.com/watch?v=HrybPYpOvz0
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t,n,m;
    string s1, s2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>s1>>s2;
        int dp[n+1][m+1];
        for(int i = 0;i<=n;i++)
        dp[i][0] = 0;
        for(int i = 0;i<=m;i++)
        dp[0][i] = 0;
        int res = 0;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                    res = max(res, dp[i][j]);
                }
                else
                dp[i][j] = 0;
            }
        }
        cout<<res<<"\n";
    }
	return 0;
}