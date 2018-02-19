#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,q,x,y,z,k;
	cin>>n>>k;
	ll a[n];
	vector<ll>v;
	vector<ll>:: iterator it;
	ll m=sqrt(n)+1;
	ll m1=m,d=0;
	ll arr[m][m];
	for(ll i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for(ll i=0;i<m;++i)
	{
		for(ll j=0;j<m;++j)
		{
			d++;
			if(d<=n)
			arr[i][j]=a[d-1];
			else 
			arr[i][j]=0;
		}
	}

	for(ll i=0;i<m;++i)
	{
		ll c=0;
		for(ll j=0;j<m;++j)
		{
			if(arr[i][j]>k)
			c++;
		}
		v.push_back(c);
		
	}
	cin>>q;
	while(q--)
	{
		cin>>x>>y>>z;
		if(x==1)
		{
			ll g=y/m;
			if(z<k&&a[y]>k)
			v[g]--;
			else if(z>k&&a[y]<k)
			v[g]++;
			a[y]=z;
		}
		else
		{
			ll ans=0;
			ll h3=y/m,h4=z/m;
			//y and z
			ll h1=y,h2=z;
			if(h3==h4)
			{
				for(ll i=y;i<=z;++i)
				{
					if(a[i]>k)
					ans++;
				}
				cout<<ans<<"\n";
				continue;
			}
				while(1)
				{
					if(a[h1]>k)
					ans++;
					h1++;
					if(h1%m==0)
					break;
				}
			while(1)
			{
				if(a[h2]>k)
				ans++;
				if(h2%m==0)
				break;
				h2--;
			}
			
			for(ll i=h3+1;i<h4;++i)
			ans+=v[i];
			cout<<ans<<"\n";
		}
	}
	return 0;
}
