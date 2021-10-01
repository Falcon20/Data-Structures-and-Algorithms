
/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

/* The method push to push element into the queue*/
// Problem link - https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1#
void MyQueue:: push(int x)
{
    QueueNode *temp = new QueueNode(x);
    if(front == NULL && rear == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
    if(front == NULL && rear == NULL)
    return -1;
    QueueNode *temp = front;
    front = front->next;
    if(front == NULL)
    {
        rear = NULL;
    }
    int k = temp->data;
    free(temp);
    return k;
}
