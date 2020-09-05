// Problem link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0
//video tutorial - https://www.youtube.com/watch?v=ntCGbPMeqgg
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,W;
    cin>>t;
    while(t--)
    {
        cin>>n>>W;
        int val[n],wt[n], dp[n+1][W+1];
        for(int i=0;i<n;i++)
        cin>>val[i];
        for(int i=0;i<n;i++)
        cin>>wt[i];
        for(int i =0;i<=W;i++)
        dp[0][i] = 0;
        for(int i =0;i<=n;i++)
        dp[i][0] = 0;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=W;j++)
            {
                if(wt[i-1] <= j)
                {
                    dp[i][j] = max(dp[i-1][j], val[i-1]+ dp[i-1][j-wt[i-1]]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout<<dp[n][W]<<"\n";
    }
    return 0;
}