// Problem link - https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0
// Video tutorial - https://www.youtube.com/watch?v=823Grn4_dCQ
// Solution- length(s1) + length(s2) - LCS(s1,s2)

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int lcs(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
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
}
int main()
{
	int t;
	string s1,s2;
	cin>>t;
	while(t--)
	{
	    cin>>s1>>s2;
	    cout<<s1.length() + s2.length() - lcs(s1,s2)<<"\n";
	}
	return 0;
}