class Solution {
public:
    int find_parent(int u, vector<int>&parent)
    {
        if(parent[u] == u)
            return u;
        return parent[u] = find_parent(parent[u], parent);
    }
    void make_union(int u, int v, vector<int>&rank, vector<int>&parent)
    {
        u = find_parent(u,parent);
        v = find_parent(v,parent);
        if(u != v)
        {
            if(rank[u] < rank[v])
            {
                parent[u] = v;
            }
            else if(rank[u] > rank[v])
                parent[v] = u;
            else
            {
                parent[v] = u;
                rank[u]++;
            }
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int>parent(n);
        vector<int>rank(n);
        for(int i= 0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
        for(int i = 0;i<pairs.size();i++)
        {
            make_union(pairs[i][0], pairs[i][1], rank, parent);
        }
        map<int, string>mp;
        for(int i =0;i<n;i++)
        {
            int par = find_parent(i, parent);
            mp[par].push_back(s[i]);
        }
        for(auto it: mp)
        {
            string temp = it.second;
            sort(temp.rbegin(), temp.rend());
            mp[it.first] = temp;
        }
        string result = "";
        for(int i = 0;i<n;i++)
        {
            int par = find_parent(i, parent);
            result.push_back(mp[par].back());
            mp[par].pop_back();
        }
        return result;
    }
};