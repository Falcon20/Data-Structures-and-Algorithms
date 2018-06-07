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
	    ll a[n+1],s=0;
	    a[0]=0;
	    for(ll i=1;i<=n;++i)
	    {
	        cin>>a[i];
	        s+=a[i];
	    }
	    if(s%2!=0)
	    {
	        cout<<"NO\n";
	        continue;
	    
	    }
	    s/=2;
	   bool dp[n+1][s+1];
	    for(ll i=0;i<=s;++i)
	    {
	        dp[0][i]=0;
	    }
	    for(ll i=0;i<=n;++i)
	    {
	        dp[i][0]=1;
	    }
	    for(ll i=1;i<=n;++i)
	    {
	        for(ll j=1;j<=s;++j)
	        {
	            if(a[i]>j)
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	            else
	            {
	                dp[i][j]=(dp[i-1][j]||dp[i-1][j-a[i]]);
	            }
	        }
	    }
	    for(ll i=0;i<=n;++i)
	    {
	    	for(ll j=0;j<=s;++j)
	    	cout<<dp[i][j]<<" ";
	    	cout<<"\n";
		}
	    if(dp[n][s])
	    cout<<"YES\n";
	    else
	    cout<<"NO\n";
	    
	    
	}
	return 0;
}
