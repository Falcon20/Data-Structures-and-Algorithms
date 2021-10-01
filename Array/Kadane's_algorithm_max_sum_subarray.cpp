// Problem link - https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
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
        ll a[n];
        for(int i = 0;i<n;i++)
        cin>>a[i];
        int res = *max_element(a,a+n);
        if(res <= 0)
        {
            cout<<res<<"\n";
            continue;
        }
        int mx=0, mx_so_far=0;
        for(int i = 0;i<n;i++)
        {
            mx_so_far += a[i];
            if(mx_so_far < 0)
            mx_so_far = 0;
            mx = max(mx, mx_so_far);
        }
        cout<<mx<<"\n";
        
    }
    return 0;
}