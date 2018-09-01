//source :https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/
// time complexity of this algorithm is O(ElogE) which is the time taken to sort the edges 
#include<bits/stdc++.h>
using namespace std;
int rnk[100005];
int parent[100005];
int find(int u)
{
    if(parent[u]!=u)
        parent[u]=find(parent[u]);
    return parent[u];
}
void merge(int x,int y)
{
    x=find(x);
    y=find(y);
    if(rnk[x]<rnk[y])
    parent[x]=y;
    else
    parent[y]=x;
    if(rnk[x]==rnk[y])
    rnk[y]++;
}
int main()
{
    int n,e,x,y,w;
    cin>>n>>e;// no of nodes and edges
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;// initially each node is a parent of itself
    }
    vector<pair<int,pair<int,int> > >v;// structure to store weights and the vertices corresponding to it
    for(int i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        v.push_back(make_pair(w,make_pair(x,y)));    
    }        
    sort(v.begin(),v.end()); // sort the edges according to the ascending order of weights
    int res=0;
    for(int i=0;i<e;i++)
    {
        int u1=v[i].second.first;
        int u2=v[i].second.second;
        int wt=v[i].first;
        int set_u=find(u1);
        int set_v=find(u2);
        if(set_u!=set_v)// only consider if both the vertices belong to different sets
        {
            res+=wt;
            merge(set_u,set_v);// merge both the sets
        }
    }
    cout<<res<<"\n";// minimum weight of spanning tree
    return 0;
}
