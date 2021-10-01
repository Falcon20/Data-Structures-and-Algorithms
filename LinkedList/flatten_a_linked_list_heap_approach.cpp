/*
struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;
    
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
    
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
// Problem link - https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
// Heap Approach
struct compare {
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data;
    }
};
 
Node *flatten(Node *root)
{
  if(root == NULL || root->next == NULL)
  return root;
  Node *curr = root;
  priority_queue<Node*, vector<Node*>, compare> pq;
  while(curr)
  {
      pq.push(curr);
      curr = curr->next;
  }
  Node *head = NULL, *start = NULL;
  while(!pq.empty())
  {
      Node *temp = pq.top();
      pq.pop();
      if(temp->bottom != NULL)
      pq.push(temp->bottom);
      if(head == NULL)
      {
          head = temp;
      }
      else
      {
          start->bottom = temp; 
      }
      start = temp;
  }
  return head;
}

