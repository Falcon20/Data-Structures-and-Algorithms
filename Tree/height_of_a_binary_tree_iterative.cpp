// return the Height of the given Binary Tree
// Iterative solution
// Problem link - https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
int height(Node* root)
{
    if(root == NULL)
    return 0;
    int mx = 1;
    unordered_map<Node *, int>level;
    level[root] = 1;
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        Node *u = q.front();
        q.pop();
        if(u->left)
        {
            q.push(u->left);
            level[u->left] = level[u]+1;
            if(level[u->left] > mx)
            mx = level[u->left];
        }
        if(u->right)
        {
            q.push(u->right);
            level[u->right] = level[u]+1;
            if(level[u->right] > mx)
            mx = level[u->right];
        }
    }
    return mx;
}
