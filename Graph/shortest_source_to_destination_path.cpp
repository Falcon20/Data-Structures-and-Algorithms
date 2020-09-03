// Problem link - https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path/0
// find the level of destination to the source node
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,n,m,x,y;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    int a[n][m];
	    for(int i = 0;i<n;i++)
	    {
	        for(int j = 0;j<m;j++)
	        cin>>a[i][j];
	    }
	    cin>>x>>y;
	    if(x>=n || y>=m)
	    {
	        cout<<-1<<"\n";
	        continue;
	    }
	    if(x == 0 && y == 0)
	    {
	        cout<<((a[0][0]) ? 0 : -1)<<"\n";
	        continue;
	    }
	    vector<int>v[n*m];
	    for(int i = 0;i<n;i++)
	    {
	        for(int j = 0;j<m;j++)
	        {
	            if(a[i][j])
	            {
	                if((i+1 < n) && a[i+1][j])
	                {
	                    v[i*m+j].push_back((i+1)*m+j);
	                    v[(i+1)*m+j].push_back((i)*m+j);
	                }
	                if((j+1 < m) && a[i][j+1])
	                {
	                    v[i*m+j].push_back((i)*m+j+1);
	                    v[(i)*m+j+1].push_back((i)*m+j);
	                }
	            }
	        }
	    }
	    vector<bool>vis(n*m, false);
	    int des = x*m+y;
	    vector<int>level(n*m, 0);
	    queue<int>q;
	    q.push(0);
	    vis[0] = true;
	    level[0] = 0;
	    int res = -1;
	    while(!q.empty())
	    {
	        int u = q.front();
	        q.pop();
	        for(auto s: v[u])
	        {
	            if(!vis[s])
	            {
	                if(s == des)
	                {
	                    res = level[u]+1;
	                    break;
	                }
	                vis[s] = true;
	                level[s] = level[u] + 1;
	                q.push(s);
	            }
	        }
	        if(res != -1)
	        break;
	    }
	    cout<<res<<"\n";
	}
	return 0;
}