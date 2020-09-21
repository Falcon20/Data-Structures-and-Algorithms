/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
//BFS approach
//From each node check if there exist a adjacent node which is visited and is not the parent of the curent node
bool isCyclic(vector<int> g[], int V)
{
    vector<int>parent(V, -1);
    bool vis[V];
    memset(vis, false, sizeof(vis));
    for(int i = 0;i<V;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            queue<int>q;
            q.push(i);
            while(!q.empty())
            {
                int u = q.front();
                q.pop();
                for(auto s: g[u])
                {
                    if(!vis[s])
                    {
                        vis[s] = true;
                        parent[s] = u;
                        q.push(s);
                    }
                    else
                    {
                        if(s != parent[u])
                        return true;
                    }
                }
            }
        }
    }
    return false;
    
}