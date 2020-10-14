// Problem link - https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair/0
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int dp[100005];
ll solve(ll n)
{
    if(n <= 1)
    {
        dp[n]=1;
        return 1;
    }
    if(dp[n] != -1)
    return dp[n];
    return dp[n] = (solve(n-1) + solve(n-2))%mod;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int res = solve(100004);
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}