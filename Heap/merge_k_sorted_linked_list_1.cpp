/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
// problem link- https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1
// O(total_nodes*n) approach
Node * mergeKLists(Node *arr[], int n)
{
       Node *ptr[n];
       for(int i = 0;i<n;i++)
       ptr[i] = arr[i];
       Node *tmp = new Node(0);
       Node *curr = tmp, *chk = tmp;
       while(1)
       {
           int mx = INT_MAX;
           for(int i = 0;i<n;i++)
           {
               if(arr[i])
               {
                   if(arr[i]->data < mx)
                   mx = arr[i]->data;
               }
           }
           if(mx == INT_MAX)
           break;
           for(int i =0;i<n;i++)
           {
               if(arr[i])
               {
                   if(arr[i]->data == mx)
                   {
                      curr->next = arr[i];
                      curr = curr->next;
                      arr[i] = arr[i]->next;
                      break;
                   }
               }
           }
       }
       return chk->next;
}

