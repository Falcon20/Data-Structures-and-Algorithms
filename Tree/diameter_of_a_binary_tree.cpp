/* Computes the diameter of binary tree with given root.  */
int solve(Node *root, int &res)
{
    if(root == NULL)
    return 0;
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    int temp = max(l,r)+1;
    int ans = max(l+r+1, temp);
    res = max(res, ans);
    return temp;
    
}
int diameter(Node* node) {
    int res = 0;
    int k = solve(node, res);
    return res;
}
