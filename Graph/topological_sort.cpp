// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
// Problem- link - https://practice.geeksforgeeks.org/problems/topological-sort/1
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int>v;
    int indeg[V];
    memset(indeg,0,sizeof(indeg));
    for(int i = 0;i<V;i++)
    {
        for(auto s: adj[i])
        {
            indeg[s]++;
        }
    }
    queue<int>q;
    for(int i =0;i<V;i++)
    {
        if(indeg[i] == 0)
        q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        v.push_back(u);
        for(auto s: adj[u])
        {
            indeg[s]--;
            if(indeg[s] == 0)
            q.push(s);
        }
    }
    return v;
}
