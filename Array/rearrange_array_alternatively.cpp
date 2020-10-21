// Problem link - https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0/
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
	    for(ll i =0;i<n;i++)
	    cin>>a[i];
	    ll min_idx = 0, max_idx = n-1;
	    ll max_element = a[n-1]+1;
	    for(ll i = 0;i<n;i++)
	    {
	        if(i%2==0)
	        {
	            a[i] += (a[max_idx]% max_element)*max_element;
	            max_idx--;
	        }
	        else
	        {
                a[i] += (a[min_idx]% max_element)*max_element;
                min_idx++;
                
	        }
	    }
	    for(ll i = 0;i<n;i++)
	    {
	        cout<<a[i] / max_element<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}