// Problem link - https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
// Iterative solution
vector<int> verticalOrder(Node *root)
{
    unordered_map<Node *, int>m; // store LR value (vertical distance) of node
    map<int, vector<int> >mp; // store the node values according to vertical distance vector
    vector<int>v;
    if(root == NULL)
    return v;
    queue<Node *>q;
    q.push(root);
    m[root] = 0;
    while(!q.empty())
    {
        Node *u = q.front();
        q.pop();
        mp[m[u]].push_back(u->data);
        if(u->left)
        {
            q.push(u->left);
            m[u->left] = m[u]-1;
        }
        if(u->right)
        {
            q.push(u->right);
            m[u->right] = m[u] +1;
        }
        
    }
    for(auto s: mp)
    {
        for(auto d: s.second)
        {
            v.push_back(d);
        }
    }
    return v;
    
}

