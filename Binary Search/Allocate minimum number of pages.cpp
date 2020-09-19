//Allcate minimum number of pages
//Similar to Painter Partition Problem 
//Video tutorial - https://www.youtube.com/watch?v=2JSQIhPcHQg&t=2116s
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>v;
bool solve(ll mid, ll k)
{
    ll g = 0;
    for(auto s: v)
    {
        g += s;
        if(g > mid)
        {
            k--;
            g = s;
            if(k == 0)
            return false;
        }
    }
    return true;
}
int main()
{
    ll t,n,k,x;
    cin>>t;
    while(t--)
    {
        v.clear();
        cin>>n;
        ll sm = 0;
        for(ll i = 0;i<n;i++)
        {
            cin>>x;
            sm +=x;
            v.push_back(x);
        }
        cin>>k;
        if(n < k)
        {
            cout<<-1<<"\n";
            continue;
        }
        ll l = *max_element(v.begin(),v.end());
        ll r = sm;
        ll res = INT_MAX;
        while(l<=r)
        {
            ll mid = l + (r-l)/2;
            if(solve(mid,k))
            {
                if(mid<res)
                res = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        cout<<res<<"\n";
        
    }
	
	return 0;
}