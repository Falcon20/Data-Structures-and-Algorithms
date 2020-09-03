// Dijkshtra implementation
// Problem link - https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// To delete a random element in min heap is linear. So each updated distance is inserted into min_heap
// everytime get_min is performed, check if the current dis in the heap is min distance till now.
vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    vector<bool>vis(V, false);
    vector<int>dis(V, INT_MAX);
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater< pair<int,int>> > pq;// min_heap
    for(int i = 0;i<V;i++)
    {
        if(i!=src)
        {
            pq.push({INT_MAX,i});
        }
    }
    pq.push({0,src});
    dis[src] = 0;
    int node;
    while(!pq.empty())
    {
        pair<int,int>u = pq.top();
        pq.pop();
        node = u.second;
        if(dis[node] != u.first)
        continue;
        vis[node] = true;
        for(int i =0;i<V;i++)
        {
            if(g[node][i] && (!vis[i]))
            {
                if(dis[i] > dis[node] + g[node][i])
                {
                    dis[i] = dis[node]+ g[node][i];
                    pq.push({dis[i],i});
                }
            }
        }
    }
    return dis;

}