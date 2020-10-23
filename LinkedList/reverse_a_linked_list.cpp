/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/
//Problem link - https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
// Should reverse list and return new head.
struct Node* reverseList(struct Node *head)
{
    if(head == NULL || head->next == NULL)
    return head;
    Node *curr = head, *prev = NULL, *next = NULL;
    while(curr)
    {
        next= curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
