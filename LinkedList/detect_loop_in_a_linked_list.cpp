
/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
// Problem link - https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
// Floyd - Cycle finding algorithm
bool detectLoop(Node* head)
{
    if(head == NULL || head->next == NULL)
    return false;
    Node *slow = head, *fast = head;
    while(fast&& fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast)
        return true;
    }
    return false;
}
