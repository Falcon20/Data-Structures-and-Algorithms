
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
// Problem link - https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
Node *reverse(Node *root)
{
    Node *prev = NULL, *curr = root, *next = NULL;
    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int length(Node *root)
{
    int l = 0;
    while(root)
    {
        l++;
        root = root->next;
    }
    return l;
}
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    if(first == NULL && second == NULL)
    return NULL;
    if(first == NULL)
    return second;
    if(second == NULL)
    return first;
    int l1 = length(first);
    int l2 = length(second);
    if(l1<l2)
    {
        for(int i = 0;i<(l2-l1);i++)
        {
            Node *temp = new Node(0);
            temp->next = first;
            first =temp;
        }
    }
    else if (l1> l2)
    {
        for(int i = 0;i<(l1-l2);i++)
        {
            Node *temp = new Node(0);
            temp->next = second;
            second =temp;
        }
    }
    Node *l = reverse(first);
    Node *r = reverse(second);
   int carry = 0;
   Node *curr = NULL, *head = NULL;
   while(l && r)
   {
       int sm = l->data + r->data + carry;
       Node *n_node = new Node(sm%10);
       carry = sm/10;
       if(curr == NULL)
       {
           curr = n_node;
           head = curr;
       }
       else
       {
           curr->next = n_node;
           curr = n_node;
       }
       l = l->next;
       r = r->next;
   }
   if(carry)
   {
      Node *n_node = new Node(carry);
      curr->next = n_node;
   }
   return reverse(head);
}
