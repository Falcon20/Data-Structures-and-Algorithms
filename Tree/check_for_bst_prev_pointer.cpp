// return true if the given tree is a BST, else return false
// Problem link - https://practice.geeksforgeeks.org/problems/check-for-bst/1
bool solve(Node *&prev, Node *root)
{
    if(root == NULL)
    return true;
    if(!solve(prev, root->left))
    return false;
    if(prev && prev->data >= root->data)
    return false;
    prev = root;
    return solve(prev, root->right);
}
bool isBST(Node* root) {
    if(root == NULL)
    return true;
    Node *prev = NULL;
    return solve(prev, root);
}