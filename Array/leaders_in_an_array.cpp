// Problem link - https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
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
        vector<int>v;
        for(int i = 0;i<n;i++)
        cin>>a[i];
        int mx = INT_MIN;
        for(int i = n-1;i>=0;i--)
        {
            if(a[i] >= mx)
            {
                mx = a[i];
                v.push_back(mx);
            }
        }
        for(auto it = v.rbegin(); it!= v.rend(); it++)
        {
            cout<<*it<<" ";
        }
        cout<<"\n";
    }
    return 0;
}