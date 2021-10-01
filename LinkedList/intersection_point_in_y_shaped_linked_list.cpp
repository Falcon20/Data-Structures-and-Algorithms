/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
// Stack Approach
int intersectPoint(Node* head1, Node* head2)
{
    Node *s1[10005],*s2[10005];
    int s1_idx = 0, s2_idx = 0; 
    Node *curr1 = head1, *curr2 = head2;
    while(curr1)
    {
        s1[s1_idx++] = curr1;;
        curr1 = curr1->next;
    }
    while(curr2)
    {
        s2[s2_idx++] = curr2;
        curr2 = curr2->next;
    }
    Node *prev = new Node(-1);
    s1_idx--;
    s2_idx--;
    while(s1_idx >=0 && s2_idx >=0)
    {
        if(s1[s1_idx] != s2[s2_idx])
        {
            return prev->data;
        }
        prev = s1[s1_idx];
        s1_idx--;
        s2_idx--;
    }
    return -1;
}
