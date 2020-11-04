
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
// Problem link - https://practice.geeksforgeeks.org/problems/largest-bst/1
struct Info {
    int sz;
    int res;
    int mn;
    int mx;
    bool isBST; 
};
Info solve(Node *root)
{
    if(root == NULL)
    return {0, 0, INT_MAX, INT_MIN, true}; // assign INT_MAX to mn and INT_MIN to mx
    if(root->left == NULL && root->right == NULL)
    return {1, 1, root->data, root->data, true};
    Info l = solve(root->left);
    Info r = solve(root->right);
    if(l.isBST && r.isBST)
    {
        if(root->data > l.mx && root->data < r.mn)
        {
            Info temp;
            temp.isBST = true;
            temp.sz = l.sz + r.sz +1;
            temp.mn = min(l.mn, root->data); // to handle the case of NULL node
            temp.mx = max(r.mx, root->data); // to handle the case of NULL node
            temp.res = temp.sz;
            return temp;
        }
    }
    Info temp;
    temp.isBST = false;
    temp.res = max(l.res, r.res);
    return temp;
}
int largestBst(Node *root)
{
    Info k = solve(root);
    return k.res;
}
