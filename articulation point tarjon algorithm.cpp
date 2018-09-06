//problem link : https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/rhezo-and-destructive-mind/
// tutorial link: https://www.hackerearth.com/practice/notes/nj/
// video tutorial : https://www.youtube.com/watch?v=2kREIkF9UAs&t=165s
#include<bits/stdc++.h>
using namespace std;
int n,e,x,y,q;
bool vis[100005];// boolean visited array to avoid infinite loop in dfs
vector<int>v[100005];
int disc[100005];// discover time
int low[100005]; // minimum time 
int tme;
int parent[100005];// parent array used to check for root node
bool ap[100005]; // bool array to check articulation point 
void dfs(int u)
{
	int children=0;
	tme++;
	disc[u]=low[u]=tme;// initialize the time
	vis[u]=1;
	for(auto s: v[u])
	{
		if(!vis[s])
		{	
		    children++;
			parent[s]=u;
			dfs(s);
			low[u]=min(low[u],low[s]);
			if(parent[u]==-1&&children>1)// if root node and childrens is atleast 2
			ap[u]=1;
			if(parent[u]!=-1&&low[s]>=disc[u])// if not root node then check if visited time<=low time of any adj vertex
			ap[u]=1;
		}
		else if(s!=parent[u])
		{
			low[u]=min(low[u],disc[s]);// update time to minimum
		}
	}
}
int main()
{
	cin>>n>>e;
	for(int i=0;i<n;i++)
	parent[i]=-1;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
	    if(!vis[i])
	    dfs(i);
	}
	cin>>q;
	while(q--)
	{
	    cin>>x;
	    if(ap[x])
	    cout<<"Satisfied "<<v[x].size()<<"\n";
	    else
	    cout<<"Not Satisfied\n";
	}
	return 0;	
}
