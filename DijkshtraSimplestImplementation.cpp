//The following is the simplest implementation of Dijkshtra algorithm for undirected graph
// Time complexity of this algorithm is O(|E|.log|V|)
#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f	
using namespace std;
int main()
{
	int n,m,source,u,v,w;
	cin>>n>>m;
	// n is the number of vertices and m represent the number of edges
	vector< pair<int,int> > g[n];// data structure to store the graph
	for(ll i=0;i<m;++i)
	{
		cin>>u>>v>>w; // input the node in 0 based
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	cin>>source;// source node
	vector<int> D(n);// distance vector to store the minimum distance from source
	for(ll i=0;i<n;++i)
	{
		D[i]=INF;// Initialize all the distance to infinite
	}
	D[source]=0;// distance of source from source is zero
	set< pair<int,int> >Q;
	Q.insert(make_pair(0,source));// a set is used to always extract the minimum element from it
	while(!Q.empty())
	{
		auto top=Q.begin();
		ll u=top->second;
		Q.erase(top);
		for(auto next:g[u])
		{
			 int v=next.first;
			 int wt=next.second;
			if(D[v]>D[u]+wt){
				if(Q.find({D[v],v})!=Q.end())
					Q.erase({D[v],v});
					D[v]=D[u]+wt;
					Q.insert({D[v],v});
			}
		}
	}
	for(int i=0;i<n;++i)
	cout<<D[i]<<" ";// resultant minumum distance from the source node
	return 0;
}
