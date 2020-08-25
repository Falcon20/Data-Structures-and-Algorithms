// Problem link - https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0
// time complexity - O(log(n))
// video tutorial - check tech dose video
// Iterative solution
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i =0;i<n;i++)
        cin>>a[i];
        cin>>k;
        int l = 0, r = n-1;
        bool chk = false;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(a[mid] == k)
            {
                chk = true;
                cout<<mid<<"\n";
                break;
            }
            if(a[mid]>a[l])
            {
                if(k>= a[l] && k<= a[mid])
                r = mid-1;
                else
                l = mid+1;
            }
            else
            {
                if(k>=a[mid] && k<=a[r])
                l = mid+1;
                else
                r = mid-1;
            }
        }
        if(!chk)
        cout<<-1<<"\n";
    }
    return 0;
}