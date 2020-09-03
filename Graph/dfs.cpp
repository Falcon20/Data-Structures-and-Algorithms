// Problem link - https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
vector<int>v;
bool vis[100005] = {0};
void solve(int u, vector<int>g[])
{
    vis[u] = true;
    v.push_back(u);;
    for(auto s: g[u])
    {
        if(!vis[s])
        {
            solve(s,g);
        }
    }
}
vector <int> dfs(vector<int> g[], int N)
{
    v.clear();
    memset(vis,false,sizeof(vis));
    solve(0,g);
    return v;

}