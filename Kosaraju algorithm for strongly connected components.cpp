//Kosaraju's algorithm for finding all strongly connected components
#include<bits/stdc++.h>
using namespace std;
bool vis1[100005];// initial visited array
bool vis2[100005];//second pass bool visited array
vector<int>v1[100005];// initial graph
vector<int>v2[100005];// graph with reversed edges
int n,e,x,y;
stack<int>st;
void dfs1(int u)// initial dfs
{
	vis1[u]=1;
	for(auto s: v1[u])
	{
		if(!vis1[s])
		dfs1(s);
	}
	st.push(u);
}
void dfs2(int u)// dfs for reversed edges
{
	vis2[u]=1;
	cout<<u<<" ";
	for(auto s: v2[u])
	{
		if(!vis2[s])
		dfs2(s);
	}
	
}
int main()
{
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		v1[x].push_back(y);
		v2[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis1[i])
		dfs1(i);
	}
	while(!st.empty())
	{
		int u=st.top();
		st.pop();
		if(!vis2[u])
		dfs2(u);
		else
		continue;
		cout<<"\n";
	}
	return 0;	
	
}
/*
11 13
3 1
1 2
2 3
2 4
4 5
5 6
6 4 
7 6
7 8
8 9
9 10
10 7
10 11
*/
