// problem link- https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
// Video tutorial - https://www.youtube.com/watch?v=MbN_mhJntHg
// O(total_nodes*log(n)) approach
class compare{
    public:
        int operator()(Node *a, Node *b){
            return b->data<a->data;
        }
};

Node * mergeKLists(Node *arr[], int n)
{
    priority_queue<Node *, vector<Node *>, compare> pq;
    
    for(int i =0;i<n;i++)
    {
        if(arr[i])
        pq.push(arr[i]);
    }
    Node *temp = new Node(0);
    Node *curr = temp, *chk = temp; 
    while(!pq.empty())
    {
        Node *u = pq.top();
        curr->next = u;
        curr = curr->next;
        if(u->next)
        pq.push(u->next);
        pq.pop();
    }
    return chk->next;

}

