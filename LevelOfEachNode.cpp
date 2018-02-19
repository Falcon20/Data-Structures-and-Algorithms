#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t,n,m,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<ll>v[n+1];
        for(ll i=0;i<m;++i)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        bool visited[n+1]={0};
        queue<ll>q;
        int level[n+1]={0};
        q.push(1);
        level[1]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto it=v[u].begin();it!=v[u].end();++it)
            {
                if(!visited[*it])
                {
                    visited[*it]=1;
                    q.push(*it);
                    level[*it]=level[u]+1;
                    
                }
            }
        }
    
    cout<<level[n]<<"\n";
    }
    return 0;
}
