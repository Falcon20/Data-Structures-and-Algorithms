/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

int solve(Node *root, int &res)
{
    if(root == NULL)
    return 0;
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    if(root->left && root->right)
    {
        int temp = max(l,r)+ root->data;
        res = max(res, l+r+root->data);
        return temp;
    }
    if(root->left)
    return root->data + l;
    if(root->right)
    return root->data + r;
    return root->data;
}
int maxPathSum(Node* root)
{ 
    int res = INT_MIN;
    int k = solve(root, res);
    return res;
}