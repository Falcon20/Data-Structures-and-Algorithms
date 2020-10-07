/*this  function serializes 
the binary tree and stores 
it in the vector A*/
void serialize(Node *root,vector<int> &A)
{
    if(root == NULL)
    {
        A.push_back(-1);
        return ;
    }
    A.push_back(root->data);
    serialize(root->left, A);
    serialize(root->right, A);
}

/*this function deserializes
 the serialized vector A*/
 
Node *solve(vector<int> &A, int &idx)
{
    if(A[idx] == -1)
    {
      idx++;
      return NULL;
    }
    Node *temp = new Node(A[idx]);
    idx++;
    temp->left = solve(A,idx);
    temp->right = solve(A,idx);
    return temp;
}
Node * deSerialize(vector<int> &A)
{
    int pt = 0;
    return solve(A, pt);
   
}