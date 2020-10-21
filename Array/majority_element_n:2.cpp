// Moore Voting algorithm
// video tutorial - https://www.youtube.com/watch?v=AoX3BPWNnoE
// Problem link - https://practice.geeksforgeeks.org/problems/majority-element/0
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i = 0;i<n;i++)
	    cin>>a[i];
	    // find a possible candidate using Moore Voting algorithm
	    int ct =0, el = a[0];
	    for(int i =0;i<n;i++)
	    {
	        if(ct == 0)
	        {
	            el = a[i];
	        }
	        if(el == a[i])
	        ct++;
	        else
	        ct--;
	    }
	    // check if the candidate el is a majority element or not
	    int el_count = 0;
	    for(int i= 0;i<n;i++)
	    {
	        if(a[i] == el)
	        el_count++;
	    }
	    if(el_count > (n/2))
	    cout<<el<<"\n";
	    else
	    cout<<-1<<"\n";
	}
	return 0;
}