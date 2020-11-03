/* A binary tree node structure

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

// This function should return tree if passed  tree 
// is balanced, else false. 
int solve(Node *root, bool &res)
{
    if(root == NULL)
    return 0;
    int l = solve(root->left, res);
    int r = solve(root->right , res);
    if(abs(l-r)>1)
    res = false;
    return max(l,r)+1;
}
bool isBalanced(Node *root)
{
    if(root == NULL)
    return true;
    bool res = true;
    int k = solve(root, res);
    return res;
}
