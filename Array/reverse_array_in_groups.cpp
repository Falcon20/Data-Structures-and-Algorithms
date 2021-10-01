// Problem link - https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll t,n,k;
	cin>>t;
	while(t--)
	{
	    cin>>n>>k;
	    ll a[n];
	    for(ll i =0;i<n;i++)
	    cin>>a[i];
	    for(int i = 0;i<n;i+=k)
	    {
	        int l =i;
	        int r = min(n-1,i+k-1);
            while(l<r)
            {
                swap(a[l], a[r]);
                l++;
                r--;
            }
	    }
	    for(int i = 0;i<n;i++)
	    cout<<a[i]<<" ";
	    cout<<"\n";
	}
	return 0;
}