/*
	Author :-Azad Singh
	NIT RAIPUR (2015-19)
*/
// The logic is to find the farthest node form any node using bfs (lets say farthest node be x)
// then find the farthest node from that node(x) (lets say farthest node be y)
// then maximum path will be from x->y
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll t,n,x,y,w;
	cin>>t;
	while(t--)
	{
		cin>>n;
		//data structure to store the undirected graph
		vector<vector<pair<ll,ll> > >v(n+1);
		vector<vector<pair<ll,ll> > >:: iterator it;
		for(int i=1;i<n;++i)
		{
			cin>>x>>y>>w;
			v[x].push_back(make_pair(y,w));
			v[y].push_back(make_pair(x,w));
			
		}
		bool vis[n+1]={0};
		ll dis[n+1]={0};
		queue<ll>q;
		q.push(1);
		dis[1]=0;
		vis[1]=1;
		while(!q.empty())
		{
			ll u=q.front();
			vis[u]=1;
			q.pop();
			for( auto it=v[u].begin();it!=v[u].end();++it)
			{
				if(!vis[(*it).first])
				{
				
				dis[(*it).first]=dis[u]+((*it).second);
				q.push((*it).first);
				}
			}	
		}
		ll mx=dis[1],j=1;
		for(ll i=2;i<=n;++i)
		{
			if(dis[i]>mx){
				mx=dis[i];
				j=i;
			}
		}
		// first farthest node found is j
		bool vis1[n+1]={0};
		ll dis1[n+1]={0};
		q.push(j);
		dis1[j]=0;
		vis1[j]=1;
		while(!q.empty()){
			ll u=q.front();
			vis1[u]=1;
			q.pop();
			for(auto it=v[u].begin();it!=v[u].end();++it)
			{
				if(!vis1[(*it).first])
				{
				
				dis1[(*it).first]=dis1[u]+((*it).second);
				q.push((*it).first);
				}
			}
		}
		ll ans=dis1[j];
		for(ll i=1;i<=n;++i)
		{
			if(dis1[i]>ans)
			ans=dis1[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
