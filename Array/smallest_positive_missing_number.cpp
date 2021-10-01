// Problem link - https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number/0
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i = 0;i<n;i++)
	    cin>>a[i];
	    for(int i =0;i<n;i++)
	    {
	        while((a[i] >= 1 && a[i] <= n) && (a[i] != a[a[i] - 1]))
	        swap(a[i], a[a[i] - 1]);
	    }
	    bool element_found = false;
	    for(int i = 0;i<n;i++)
	    {
	        if(a[i] != i+1)
	        {
	            cout<<i+1<<"\n";
	            element_found = true;
	            break;
	        }
	    }
	    if(!element_found)
	    cout<<n+1<<"\n";
	}
	return 0;
}
