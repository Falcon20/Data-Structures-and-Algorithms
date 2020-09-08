// Problem is similar to lps, just take the second string as reverse of first string

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    string s1;
    cin>>t;
    while(t--)
    {
        cin>>n>>s1;
        string s2 =s1;
        reverse(s1.begin(),s1.end());
        int dp[n+1][n+1];
        for(int i =0;i<=n;i++)
        {
        	dp[i][0] = 0;
        	dp[0][i] = 0;
        }

        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                if(s1[i-1] != s2[j-1])
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
                else
                dp[i][j] = dp[i-1][j-1] +1;
            }
        }
        cout<<dp[n][n]<<"\n";
    }
    return 0;
}