
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

int solve(Node *root, int &res)
{
    if(root == NULL)
    return 0;
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    int temp = max(l,r)+1;
    res = max(l+r+1, res);
    return temp;
}
/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    if(node == NULL)
    return 0;
    int res = INT_MIN;
    int k = solve(node, res);
    return res;
}
