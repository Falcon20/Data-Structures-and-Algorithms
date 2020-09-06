//Problem link - https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0
// Video tutorial - https://www.youtube.com/watch?v=aycn9KO8_Ls
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[1005][1005];
int solve(vector<int>val, vector<int>wt, int W, int n)
{
    if(n == 0|| W == 0)
    return 0;
    if(dp[n][W] != -1)
    return dp[n][W];
    if(wt[n-1] <= W)
    return dp[n][W] = max(val[n-1] + solve(val,wt, W-wt[n-1], n), solve(val,wt, W,n-1));
    return dp[n][W] = solve(val,wt,W,n-1);
}
int main()
{
    int t,n,W;
    cin>>t;
    while(t--)
    {
        cin>>n>>W;
        vector<int>val(n);
        vector<int>wt(n);
        for(int i =0;i<n;i++)
        cin>>val[i];
        for(int i=0;i<n;i++)
        cin>>wt[i];
        for(int i =0;i<=n;i++)
        {
            for(int j = 0;j<=W;j++)
            dp[i][j] = -1;
        }
        cout<<solve(val,wt,W,n)<<"\n";
    }
	return 0;
}