//Video tutorial - https://www.youtube.com/watch?v=Zuwp40mT66c
// Problem link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// DFS approach, check if there is a visited node present in the current recursion stack
bool solve(int u, vector<int>adj[], vector<bool>&vis, vector<bool> &rec)
{
    vis[u] = true;
    rec[u] = true;
    for(auto s: adj[u])
    {
        if(!vis[s])
        {
            if(solve(s, adj, vis, rec))
            return true;
        }
        else
        {
            if(rec[s])
            return true;
        }
    }
    rec[u] = false;
    return false;
    
}
bool isCyclic(int V, vector<int> adj[])
{
   vector<bool>rec(V, false);
   vector<bool>vis(V, false);
   for(int i = 0;i<V;i++)
   {
       if(!vis[i])
       {
           if(solve(i, adj, vis, rec))
           return true;
       }
   }
   return false;
}