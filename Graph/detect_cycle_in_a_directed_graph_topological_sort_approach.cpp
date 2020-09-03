// Problem link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// topological sort approach
bool isCyclic(int V, vector<int> adj[])
{
    int indeg[V];
    memset(indeg, 0, sizeof(indeg));
    for(int i=0;i<V;i++)
    {
        for(auto s: adj[i])
        indeg[s]++;
    }
    queue<int>q;
    for(int i = 0;i<V;i++)
    {
        if(indeg[i] == 0)
        q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto s: adj[u])
        {
            indeg[s]--;
            if(indeg[s] == 0)
            q.push(s);
        }
    }
    for(int i =0;i<V;i++)
    {
        if(indeg[i])
        return true;
    }
    return false;
    
}