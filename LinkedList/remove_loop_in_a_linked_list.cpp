/*
struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
// Problem link - https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
// First check if loop exist using floyd cycle finding algorithm
// if loop present and both pointer meet at head node, then make prev->next = NULL
// prev is the pointer behind slow pointer
// if both pointer do not meet at head then point any one of them to head node(lets slow)
// increment both one at a time keeping prev as previous pointer to fast
// when they meet make prev->next = NULL to break the loop
void removeLoop(Node* head)
{
    if(head == NULL || head->next == NULL)
    return;
    Node *prev = NULL;
    Node *slow = head, *fast = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
        if(slow == fast)
        break;
    }
    if(fast != slow) // no loop found
    return ;
    if(slow == head) // if both pointer meet at head
    {
        prev->next = NULL;
        return ;
    }
    slow = head;
    prev = NULL; // Pointer behind fast pointer
    while(slow != fast)
    {
        prev = fast;
        fast = fast->next;
        slow = slow->next;
    }
    prev->next = NULL;
}