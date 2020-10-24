
/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
// Problem link - https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* segregate(Node *head) {
    if(head == NULL || head->next == NULL)
    return head;
    Node *t0 = new Node(-1);
    Node *t1 = new Node(-1);
    Node *t2 = new Node(-1);
    Node *p0 = t0, *p1 = t1, *p2 = t2, *curr = head;
    while(curr)
    {
        if(curr->data == 0)
        {
            t0->next = curr;
            t0 = curr;
        }
        else if(curr->data == 1)
        {
            t1->next = curr;
            t1 = curr;
        }
        else
        {
            t2->next = curr;
            t2 = curr;    
        }
        curr = curr->next;
    }
    if(p1->next)
    t0->next = p1->next;
    else
    t0->next = p2->next;
    t1->next = p2->next;
    t2->next = NULL;
    Node *chk = p0->next;
    delete p0,p1,p2;
    return chk;
    
}
