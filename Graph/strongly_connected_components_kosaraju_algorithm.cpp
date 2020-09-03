/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/
stack<int>st;
vector<int>v[5004]; // reversed_graph
vector<bool>vis(5003, false);// visited_array
vector<bool>vis_r(5003, false); // visited_array for reversed_graph

void dfs(int u, vector<int> adj[])
{
    vis[u] = true;
    for(auto s: adj[u])
    {
        if(!vis[s])
        {
            dfs(s, adj);
        }
    }
    st.push(u);
}

void reverse_dfs(int u)
{
    vis_r[u] = true;
    for(auto s: v[u])
    {
        if(!vis_r[s])
        {
            reverse_dfs(s);
        }
    }
}

int kosaraju(int V, vector<int> adj[])
{
    while(!st.empty())
    {
        st.pop();
    }
    for(int i = 0;i<V;i++)
    {
        v[i].clear();
        vis[i] = false;
        vis_r[i] = false;
    }
    for(int i =0;i<V;i++)
    {
        for(auto s: adj[i])
        {
            v[s].push_back(i); // make reverse graph
        }
    }

    for(int i = 0;i<V;i++)
    {
        if(!vis[i])
        {
            dfs(i,adj);
        }
    }
    int c = 0;
    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        if(!vis_r[node])
        {
            c++;
            reverse_dfs(node);
        }
    }
    return c;
}