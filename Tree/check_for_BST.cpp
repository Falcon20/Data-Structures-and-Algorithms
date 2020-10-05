/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return true if the given tree is a BST, else return false
bool solve(Node *root, int l, int r)
{
    if(root == NULL)
    return true;
    if(root->data <= l || root->data >= r)
    return false;
    return solve(root->left, l, root->data) && solve(root->right, root->data, r);
}
bool isBST(Node* root) {
    return solve(root, INT_MIN, INT_MAX);
}
