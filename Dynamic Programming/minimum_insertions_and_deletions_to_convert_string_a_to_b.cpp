// Problem link - https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions/0
// Video tutorial - https://www.youtube.com/watch?v=-fx6aDxcWyg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=25
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int lcs(string s1, string s2, int n , int m)
{
    int dp[n+1][m+1];
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=m;j++)
        {
            if(i == 0 || j == 0)
            dp[i][j] = 0;
            else
            {
                if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
                else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
	    string s1,s2;
	    cin>>n>>m>>s1>>s2;
	    int len = lcs(s1,s2,n,m);
	    cout<<s1.length() - len + s2.length() - len<<"\n";
	}
	return 0;
}