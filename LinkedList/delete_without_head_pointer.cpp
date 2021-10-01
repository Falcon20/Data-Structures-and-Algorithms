
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/
// Problem link - https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1
// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node)
{
    if(node == NULL)
    return;
    Node *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    free(temp);
}

