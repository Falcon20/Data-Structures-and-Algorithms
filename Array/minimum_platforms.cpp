// Problem link - https://practice.geeksforgeeks.org/problems/minimum-platforms/0
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
        vector<string>dep(n);
        vector<string>arr(n);
        for(int i = 0;i<n;i++)
        cin>>arr[i];
        for(int i = 0;i<n;i++)
        cin>>dep[i];
        sort(dep.begin(),dep.end());
        sort(arr.begin(),arr.end());
        int res = 1,c = 1;
        int i = 1,j= 0;
        while(i<n && j<n)
        {
            if(arr[i] <= dep[j])
            {
                i++;
                c++;
            }
            else
            {
                j++;
                c--;
            }
            res = max(c,res);
        }
        cout<<res<<"\n";
    }
    return 0;
}