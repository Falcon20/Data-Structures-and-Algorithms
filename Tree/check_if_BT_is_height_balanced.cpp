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
int solve(Node *root, bool &chk, int height)
{
    if(root == NULL)
    return true;
    int l = solve(root->left, chk, height+1);
    int r = solve(root->right, chk, height+1);
    if(abs(l-r)>1)
    {
        chk = false;
    }
    return max(l,r)+1;
}
bool isBalanced(Node *root)
{
    bool chk = true;
    int k = solve(root, chk, 0);
    return chk;
}
