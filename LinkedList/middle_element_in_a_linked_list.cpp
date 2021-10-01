/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */
//Problem link- https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1#
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   if(head == NULL)
   return -1;
   if(head->next == NULL)
   return head->data;
   Node *slow = head, *fast = head;
   while(fast && fast->next)
   {
       fast = fast->next->next;
       slow = slow->next;
   }
   return slow->data;
   
}
