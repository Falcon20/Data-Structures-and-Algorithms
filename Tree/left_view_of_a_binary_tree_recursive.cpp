// Recursive
// Problem link - https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
int mx_level = -1;
void solve(Node *root, int level, vector<int>&v)
{
    if(root == NULL)
    return; 
    if(level > mx_level)
    {
        mx_level = level;
        v.push_back(root->data);
    }
    solve(root->left,level+1, v);
    solve(root->right,level+1, v);
}

vector<int> leftView(Node *root)
{
    mx_level = -1;
    vector<int>v;
    if(root == NULL)
    return v;
    solve(root, 0,v);
    return v;
}
