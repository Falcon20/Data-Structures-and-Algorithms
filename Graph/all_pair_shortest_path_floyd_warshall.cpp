// Floyd-Warshall Algorithm
// Problem link - https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall/0

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll str_to_int(string str)
{
    if(str == "INF" || str == "10000000")
    return 10000000;
    ll n = str.length();
    ll res = 0,k = 1;
    for(ll i = n-1;i>=0;i--)
    {
        ll d = int(str[i]-48);
        res+= d*k;
        k*=10;
    }
    return res;
}
int main()
{
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll a[n][n];
        string str;
        for(ll i =0;i<n;i++)
        {
            for(ll j = 0;j<n;j++)
            {
                cin>>str;
                a[i][j] = str_to_int(str);
            }
        }
        for(ll i =0;i<n;i++)
        {
            for(ll j = 0;j<n;j++)
            {
                for(ll k = 0;k<n;k++)
                {
                    a[j][k] = min(a[j][k], a[j][i]+a[i][k]);
                }
            }
        }
        for(ll i = 0;i<n;i++)
        {
            for(ll j = 0;j<n;j++)
            {
                if(a[i][j] == 10000000)
                cout<<"INF ";
                else
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
	
}