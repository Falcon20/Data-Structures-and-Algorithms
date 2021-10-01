// return the Height of the given Binary Tree
// Recursive solution
// Problem link - https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
int height(Node* root)
{
    if(root == NULL)
    return 0;
    return 1 + max(height(root->left), height(root->right));
}
