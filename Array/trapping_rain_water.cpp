// Problem link - https://practice.geeksforgeeks.org/problems/trapping-rain-water/0
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n], l[n], r[n];
        for(ll i = 0;i<n;i++)
        cin>>a[i];
        l[0] = a[0];
        r[n-1] = a[n-1];
        for(ll i = 1;i<n;i++)
        {
            l[i] = max(l[i-1], a[i]);
        }
        for(ll i = n-2;i>=0;i--)
        {
            r[i] = max(r[i+1], a[i]);
        }
        ll res = 0;
        for(int i =1;i<n-1;i++)
        {
            ll wt =  min(l[i-1],r[i+1]) - a[i];
            if(wt > 0)
            res += wt;
        }
        cout<<res<<"\n";
    }
    return 0;
}