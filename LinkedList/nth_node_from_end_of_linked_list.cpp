/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
// Problem link - https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1#
int getNthFromLast(Node *head, int n)
{
    if(head == NULL)
    return -1;
    Node *curr = new Node(0);
    curr->next = head;
    Node *fast = curr, *slow = curr;
    for(int i = 0;i<n;i++)
    {
        fast = fast->next;
        if(fast == NULL)
        return -1;
    }
    while(fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}

