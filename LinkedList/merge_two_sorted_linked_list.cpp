/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Problem link - https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    if(head_A == NULL && head_B == NULL)
    return NULL;
    if(head_A == NULL)
    return head_B;
    if(head_B == NULL)
    return head_A;
    Node *temp = new Node(-1);
    Node *ptr = temp;
    Node *curr_A = head_A;
    Node *curr_B = head_B;
    while(curr_A && curr_B)
    {
        if(curr_A-> data < curr_B->data)
        {
            temp->next = curr_A;
            temp = curr_A;
            curr_A = curr_A->next;
        }
        else
        {
            temp->next = curr_B;
            temp = curr_B;
            curr_B = curr_B->next;
        }
    }
    if(curr_A)
    temp->next= curr_A;
    if(curr_B)
    temp->next = curr_B;
    Node *q = ptr->next;
    free(ptr);
    return q;
}