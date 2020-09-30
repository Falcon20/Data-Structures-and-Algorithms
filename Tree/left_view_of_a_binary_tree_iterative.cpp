// iterative version
// Problem link - https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
vector<int> leftView(Node *root)
{
   vector<int>v;
   if(root == NULL)
   return v;
   queue<Node*>q;
   q.push(root);
   q.push(NULL);
   v.push_back(root->data);
   while(!q.empty())
   {
       Node *u = q.front();
       q.pop();
       if(u == NULL)
       {
           if(!q.empty())
           {
            v.push_back(q.front()->data);
            q.push(NULL);
           }
           continue;
       }
       if(u->left)
       q.push(u->left);
       if(u->right)
       q.push(u->right);
       
   }
   return v;
}
