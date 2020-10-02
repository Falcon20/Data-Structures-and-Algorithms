// Problem link - https://practice.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \ 
   20       30 */
// Iterative solution
int countLeaves(Node* root)
{
  if(root == NULL)
  return 0;
  int res = 0;
  queue<Node *>q;
  q.push(root);
  while(!q.empty())
  {
      Node *u = q.front();
      q.pop();
      if(u->left == NULL && u->right == NULL)
      {
          res++;
          continue;
      }
      if(u->left)
      q.push(u->left);
      if(u->right)
      q.push(u->right);
  }
  return res;
}
