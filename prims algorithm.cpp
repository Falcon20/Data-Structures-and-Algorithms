//Prims algorithm
// time complexity is O(ElogV)
#include<bits/stdc++.h>
using namespace std;
int mx=INT_MAX;
int main()
{
	int n,e,x,y,w,source;
	cin>>n>>e;
	vector<pair<int,int> >v[n];// data structure to store the graph
	for(int i=0;i<e;i++)
	{
		cin>>x>>y>>w;// two vertives and edge weight
		v[x].push_back({y,w});// the graph is undirected
		v[y].push_back({x,w});
	}
	cin>>source;// source node
	bool inMST[n];// to check if a node is already in MST
	int parent[n];// to find out the parent of each node in MST
	int key[n];// To store the key value of each node
	for(int i=0;i<n;i++)
	{
		parent[i]=-1;// initialize the parent of each node to -1
		key[i]=mx;// key is maximum
		inMST[i]=0;// no node is in MST yet
	}
	priority_queue<pair<int,int>, vector<pair<int,int> >,greater<pair<int,int>  > >pq;// min heap to find the node with minimum edge weight
	pq.push({0,source});
	key[source]=0;
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		inMST[u]=1;
		for(auto s: v[u])
		{
			int x=s.first;
			int wt=s.second;
			if(!inMST[x]&&key[x]>wt)// if node is not in MST and its key is greater than the wt of the current edge then update the weight
			{
				key[x]=wt;
				parent[x]=u;
				pq.push({key[x],x});
			}
			
		}
	}
	for(int i=1;i<n;i++)
	cout<<parent[i]<<" "<<i<<"\n";
	return 0;	
}
/*
7 12
0 1 4
0 2 5
0 3 2
1 2 4
4 6 9 
6 5 6
5 2 1
4 3 3
6 3 7
5 3 4
3 2 8
1 3 1
0
*/
