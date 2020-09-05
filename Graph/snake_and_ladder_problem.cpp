// Snake and ladder problem 
// Problem link- https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0
// solution - find the shortest path from source node to end considering each move
//Video tutorial - https://www.youtube.com/watch?v=OutDY_ICb80&t=648s
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,n,x,y;
	cin>>t;
	while(t--)
	{
	    unordered_map<int,int>m;
	    for(int i =1;i<=30;i++)
	    m[i] = i;
	    cin>>n;
	    for(int i = 0;i<n;i++)
	    {
	        cin>>x>>y;
	        m[x] = y;
	    }
	    queue<pair<int,int> >q;
	    q.push({1,0});
	    bool vis[31];
	    memset(vis,false,sizeof(vis));
	    vis[1] = true;
	    int res = -1;
	    while(!q.empty())
	    {
	        pair<int,int>u = q.front();
	        q.pop();
	        int node = u.first;
	        int dist= u.second;
	        for(int i =1;i<=6;i++)
	        {
	            if(node+i<=30 && !vis[node+i])
	            {
	                vis[node+i] = true;
	                vis[m[node+i]] = true;
	                q.push({m[node+i],dist+1});
	                if(m[node+i] == 30)
	                {
	                    res = dist +1;
	                    break;
	                }
	            }
	        }
	        if(res != -1)
	        break;
	    }
	    cout<<res<<"\n";
	    
	}
	return 0;
}