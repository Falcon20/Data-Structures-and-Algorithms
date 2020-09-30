// Problem link - https://practice.geeksforgeeks.org/problems/mirror-tree/1
// Iterative solution
void mirror(Node* node) 
{
     if(node == NULL)
     return;
     queue<Node *>q;
     q.push(node);
     while(!q.empty())
     {
         Node *u = q.front();
         q.pop();
         swap(u->left, u->right);
         if(u->left)
         q.push(u->left);
         if(u->right)
         q.push(u->right);
     }
}