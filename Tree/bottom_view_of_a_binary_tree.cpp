// Problem link - https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
   vector<int>res; // final result
    map<int, int>m; // vertical distance and value
    unordered_map<Node *, int>dis; //vertical distance
    queue<Node *>q;
    q.push(root);
    dis[root] = 0;
    while(!q.empty())
    {
        Node *u = q.front();
        q.pop();
        m[dis[u]] = u->data;
        if(u->left)
        {
            q.push(u->left);
            dis[u->left]  = dis[u] - 1;
        }
        if(u->right)
        {
            q.push(u->right);
            dis[u->right] = dis[u] + 1;
        }
    }
    for(auto s: m)
    {
        res.push_back(s.second);
    }
    return res;
}

