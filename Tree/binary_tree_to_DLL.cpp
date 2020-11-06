// Problem link - https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
void solve(Node *root, Node* &head, Node* &prev)
{
    if(root == NULL)
    return;
    solve(root->left, head, prev);
    if(prev == NULL)
    {
        head = root;
        prev = root;
        prev->left = NULL;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    solve(root->right, head, prev);
}
// This function should return head to the DLL
Node * bToDLL(Node *root)
{
    if(root == NULL)
    return NULL;
    Node *prev = NULL;
    Node *head = NULL;
    solve(root, head, prev);
    return head;
}

