
// return true/false denoting whether the tree is Symmetric or not
// Iterative Solution
// Problem link - https://practice.geeksforgeeks.org/problems/symmetric-tree/1
bool isSymmetric(struct Node* root)
{
    if(root == NULL)
    return true;
    queue<Node *>q;
    q.push(root);
    q.push(root);
    while(!q.empty())
    {
        Node *l = q.front();
        q.pop();
        Node *r = q.front();
        q.pop();
        if(l->data != r->data)
        return false;
        if(l->left && r->right)
        {
            q.push(l->left);
            q.push(r->right);
        }
        else if(l->left || r->right)
        return false;
        if(l->right && r->left)
        {
            q.push(l->right);
            q.push(r->left);
        }
        else if(l->right || r->left)
        return false;
        
    }
    return true;
    
}
