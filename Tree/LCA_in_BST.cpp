/*The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Returns the LCA of the nodes with values n1 and n2
// in the BST rooted at 'root' 
// LCA will be the first node whose value is between these two nodes
// Problem link - https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
Node* LCA(Node *root, int n1, int n2)
{
   if(root == NULL)
   return NULL;
   
   if(root->data > n1 && root->data > n2)
   return LCA(root->left, n1, n2);
   
   if(root->data < n1 && root->data < n2)
   return LCA(root->right, n1, n2);
   
   return root;
}
