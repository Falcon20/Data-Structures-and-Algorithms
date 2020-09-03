//problem-link - https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1 
vector <int> bfs(vector<int> g[], int N) {
    bool vis[N];
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(0);
    vis[0] = true;
    vector<int>v;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        v.push_back(u);
        for(auto s: g[u])
        {
            if(!vis[s])
            {
                vis[s] = true;
                q.push(s);
            }
        }
    }
    return v;
    
}