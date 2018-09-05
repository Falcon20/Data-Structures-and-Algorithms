//https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem
//Floyd Warshall all pair shortest path algorithm
// time complexity is O(V^3) where V is the no of vertices 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll mx=INT_MAX;
    ll n,e;
    cin>>n>>e;
    ll a[n][n],x,y,w,q;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            a[i][j]=mx;// initialize all distance to infinite
    }
    for(ll i=0;i<e;i++)
    {
        cin>>x>>y>>w;// node x ,y and weight w
        a[x-1][y-1]=w;
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);// a simple dp approach for updating the weight
        }
    }
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        if(x==y)
        {
            cout<<0<<"\n";
            continue;
        }
        if(a[x-1][y-1]==mx)
            cout<<-1<<"\n";
        else
            cout<<a[x-1][y-1]<<"\n";
    }
    return 0;
}
