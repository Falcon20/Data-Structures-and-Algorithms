// Problem link - https://www.interviewbit.com/problems/diagonal-traversal/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void fun(TreeNode*A, map<int,vector<int> >&m, int key)
 {
     if(A == NULL)
     return;
     m[key].push_back(A->val);
     fun(A->left, m, key+1);
     fun(A->right, m, key);
 }
vector<int> Solution::solve(TreeNode* A) {
    map<int,vector<int> >m;
    vector<int>v;
    fun(A, m, 0);
    for(auto s: m)
    {
        for(auto d: s.second)
        v.push_back(d);
    }
    return v;
}
