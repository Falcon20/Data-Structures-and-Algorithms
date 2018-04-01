// The following is an implementation of Breadth first traversal of a undirected graph
//the time complexity of this algorithm is O(V+E)
/*
	Author -Azad Singh
			NIT Raipur(2015-19)
*/
	
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll t,n,m,a,b;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;// no of nodes and no of edges
		vector<ll>adj[n];// data structure to create adjacency list
		while(m--)
		{
			cin>>a>>b;// input the nodes in 0 based
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		queue<ll>q;
		bool vis[n]={0};// bool array to mark visited nodes
		for(int i=0;i<n;++i)
		{
			if(vis[i]==0)
			{
				q.push(i);
				vis[i]=1;
				cout<<i<<" ";
				while(!q.empty())
				{	
				int u=q.front();
				q.pop();
				vector<ll>:: iterator it;
					for(it=adj[u].begin();it!=adj[u].end();++it)
					{
						if(!vis[*it])
						{
						vis[*it]=1;
						cout<<*it<<" ";
						q.push(*it);
						}
					}
				
				}
				
			}		
		}
		cout<<"\n";
	}
	return 0;
} 
