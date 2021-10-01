// return true/false denoting whether the tree is Symmetric or not
// Recursive Solution
// Problem link - https://practice.geeksforgeeks.org/problems/symmetric-tree/1
bool solve(Node *r1, Node *r2)
{
    if(r1 == NULL && r2 == NULL)
    return true;
    if(r1 == NULL || r2 == NULL)
    return false;
    if(r1->data != r2->data)
    return false;
    return (solve(r1->left, r2->right) && solve(r1->right, r2->left));
}
bool isSymmetric(struct Node* root)
{
    return solve(root, root);
}