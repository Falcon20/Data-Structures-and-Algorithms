#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,u,v,q1,x;
	cin>>n;
	vector<ll>adj[n+1];
	bool vis[n+1]={0};
	for(ll i=0;i<n-1;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<ll>v1;
	cin>>q1;
	for(ll i=0;i<q1;++i)
	{
		cin>>x;
		v1.push_back(x);
	}
	sort(v1.begin(),v1.end());
	ll level[n+1]={0};
	queue<ll>q;
	q.push(1);
	vis[1]=true;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(auto it=adj[x].begin();it!=adj[x].end();++it)
		{
			ll k=(*it);
			if(!vis[k])
			{
				vis[k]=true;
				level[k]=level[x]+1;
				q.push(k);
			}
		}
	}
	ll mx=n,res;
	for(ll i=0;i<q1;++i)
	{
		if(level[v1[i]]<mx)
		{
			mx=level[v1[i]];
			res=v1[i];
		}
	}
	cout<<res<<"\n";
	return 0;
	
	
}
