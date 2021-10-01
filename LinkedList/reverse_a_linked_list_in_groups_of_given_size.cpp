/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/
// Problem link - https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
struct node *reverse (struct node *head, int k)
{ 
    node* curr = head, *prev = NULL, *next = NULL;
    int count = 0;
    while(curr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    
    if(next != NULL)
    {
        head->next = reverse(next, k);
    }
    
    return prev;
}
