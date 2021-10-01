
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
bool hasPathSum(Node *root, int sum) {
    if(root == NULL)
    return sum == 0;
    if(root->left == NULL && root->right == NULL)
    {
        return root->data == sum;
    }
    return (hasPathSum(root->left, sum -root->data) || hasPathSum(root->right, sum -root->data));
}