
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
// problem link - https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1
void connect(Node *p)
{
   if(p== NULL)
   return ;
   queue<Node *>q;
   q.push(p);
   q.push(NULL);
   Node *prev = NULL;
   while(!q.empty())
   {
       Node *u = q.front();
       q.pop();
       if(prev)
       {
           prev->nextRight = u;
       }
       prev = u;
       if(u == NULL)
       {
           if(!q.empty())
           q.push(NULL);
           continue;
       }
       if(u->left)
       q.push(u->left);
       if(u->right)
       q.push(u->right);
   }
   
}
