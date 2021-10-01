// Problem link - https://practice.geeksforgeeks.org/problems/maximum-path-sum/1
int solve(Node* root, int &res)
{
    if(root == NULL)
    return 0;
    if(root->left == NULL && root->right == NULL)
    return root->data;
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    if(root->left && root->right)
    {
        int temp = max(l,r)+ root->data;
        res = max(res, l+r+root->data);
        return temp;
    }
    if(root->left)
    return l+ root->data;
    if(root->right)
    return r+ root->data;
}
int maxPathSum(Node* root)
{ 
    int res = INT_MIN;
    int k = solve(root, res);
    return res;
}