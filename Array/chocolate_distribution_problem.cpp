// Problem link - https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n];
        ll res = LONG_LONG_MAX;
        for(ll i = 0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>m;
        sort(a,a+n);
        for(ll i = m-1;i<n;i++)
        {
            res = min(res, a[i] - a[i-m+1]);
        }
        cout<<res<<"\n";
    }
    return 0;
}