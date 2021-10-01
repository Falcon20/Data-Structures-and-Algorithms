// your task is tp complete this function
// function should return the length of the longestConsecutive
// sequence
// Problem link - https://practice.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1
int res;
void solve(Node *root, int expected, int c)
{
    if(root == NULL)
    return;
    if(root->data == expected)
    {
        c++;
    }
    else
    c = 1;
    res = max(res,c);
    solve(root->left, root->data+1, c);
    solve(root->right, root->data+1, c);
}
int longestConsecutive(Node* root)
{
    if(root == NULL)
    return -1;
    res = 0;
    solve(root, root->data, 0);
    if( res <= 1 )
    return -1;
    return res;
}