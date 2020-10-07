
// Should return  right view of tree
// Problem link - https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
void solve(Node *root, vector<int>&v, int level, int &mx_level)
{
    if(root == NULL)
    return ;
    if(level > mx_level)
    {
        mx_level = level;
        v.push_back(root->data);
    }
    solve(root->right, v, level+1, mx_level);
    solve(root->left, v, level+1, mx_level);
}
vector<int> rightView(Node *root)
{
   vector<int>v;
   int mx_level = -1;
   solve(root, v, 0, mx_level);
   return v;
}

