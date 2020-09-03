//Problem link - https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n][n];
	    int source, dest;
	    for(int i = 0;i<n;i++)
	    {
	        for(int j = 0;j<n;j++)
	        {
	            cin>>a[i][j];
	            if(a[i][j] == 1)
	            source = i*n+j;
	            else if(a[i][j] == 2)
	            dest = i*n+j;
	        }
	    }
	    if(source == dest)
	    {
	        cout<<1<<"\n";
	        continue;
	    }
	    vector<int>v[n*n];
	    for(int i = 0;i<n;i++)
	    {
	        for(int j = 0;j<n;j++)
	        {
	            if(a[i][j] !=0)
	            {
	                if(i+1 < n && a[i+1][j] !=0)
	                {
	                    v[i*n+j].push_back((i+1)*n+j);
	                    v[(i+1)*n+j].push_back(i*n+j);
	                }
	                if(j+1 < n && a[i][j+1] !=0)
	                {
	                    v[i*n+j].push_back((i)*n+j+1);
	                    v[(i)*n+j+1].push_back(i*n+j);
	                }
	            }
	        }
	    }
	    queue<int>q;
	    q.push(source);
	    bool vis[n*n];
	    memset(vis,false,sizeof(vis));
	    vis[source] = true;
	    bool chk = false;
	    while(!q.empty())
	    {
	        int u = q.front();
	        q.pop();
	        for(auto s: v[u])
	        {
	            if(!vis[s])
	            {
	                vis[s] = true;
	                if(s == dest)
	                {
	                    chk = true;
	                    break;
	                }
	                q.push(s);
	            }
	        }
	    }
	    cout<<chk<<"\n";
	}
	return 0;
}