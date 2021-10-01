// Problem link - https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
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
        int a[n-1];
        int x = 0;
        for(int i = 0;i<n-1;i++)
        {
            cin>>a[i];
            x = x^a[i];
        }
        for(int i = 0;i<n;i++)
        {
            x = x^(i+1);
        }
        cout<<x<<"\n";
        
    }
    return 0;
}