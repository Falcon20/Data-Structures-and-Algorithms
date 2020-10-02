/* Should return true if trees with roots as r1 and 
   r2 are identical */
//Problem link - https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
// Iterative Solution
bool isIdentical(Node *r1, Node *r2)
{
    if(r1 == NULL && r2 == NULL)
    return true;
    if(r1 == NULL || r2 == NULL)
    return false;
    queue<Node *>q1;
    queue<Node *>q2;
    q1.push(r1);
    q2.push(r2);
    while((!q1.empty()) && (!q2.empty()))
    {
        Node *u1 = q1.front();
        Node *u2 = q2.front();
        q1.pop();
        q2.pop();
        if(u1->data != u2->data)
        return false;
        
        if(u1->left && u2->left)
        {
            q1.push(u1->left);
            q2.push(u2->left);
        }
        
        else if(u1->left || u2->left)
        return false;
        
        if(u1->right && u2->right)
        {
            q1.push(u1->right);
            q2.push(u2->right);
        }
        
        else if(u1->right || u2->right)
        return false;
    }
    return true;
}
