// Problem link - https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
// Video tutorial - https://www.youtube.com/watch?v=hR3s9rGlMTU&t=6s
#include<bits/stdc++.h>
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
        for(int i =0;i<=n;i++)
        dp[i][0] = 0;
        for(int i=0;i<=m;i++)
        dp[0][i] = 0;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                if(s1[i-1] != s2[j-1])
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
                else
                dp[i][j] = dp[i-1][j-1] +1;
            }
        }
        cout<<dp[n][m]<<"\n";
    }
    return 0;
}