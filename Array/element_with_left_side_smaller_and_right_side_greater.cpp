// Problem link-Find the element before which all the elements are smaller than it, and after which all are greater
// Another approach with O(1) space is also there
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
        int r[n];
        r[n-1] = a[n-1];
        for(ll i = n-2;i>=0;i--)
        {
            r[i] = min(a[i], r[i+1]);
        }
        int res = -1,mx = a[0];
        for(int i =1;i<n-1;i++)
        {
            if(a[i] >= mx)
            {
                if(r[i+1] >= a[i])
                {
                    res = a[i];
                    break;
                }
                mx = a[i];
                
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}