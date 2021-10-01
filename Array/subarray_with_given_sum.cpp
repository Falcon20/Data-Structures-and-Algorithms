// Problem link - https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int sm = 0,idx = 0,l = -1, r = -1;
        for(int i =0;i<n;i++)
        {
            sm+= a[i];
            if(sm > k)
            {
                while(1)
                {
                    sm -= a[idx];
                    idx++;
                    if(sm <= k)
                    break;
                }
            }
            if(sm == k)
            {
                l = idx;
                r = i;
                break;
            }
        }
        if(l == -1)
        cout<<-1<<"\n";
        else
        cout<<l+1<<" "<<r+1<<"\n";
        
    }
    return 0;
}