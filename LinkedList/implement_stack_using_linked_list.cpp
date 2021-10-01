
/*
The structure of the node of the stack is
struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

// And this is structure of MyStack
class MyStack {
private:
StackNode *top;
public :
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};

/* The method push to push element
   into the stack */
// Problem link - https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1
void MyStack ::push(int x) {
    StackNode *temp = new StackNode(x);
    if(top == NULL)
    top = temp;
    else
    {
        temp->next = top;
        top = temp;
    }
}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop() {

    if(top == NULL)
    return -1;
    StackNode *temp = top;
    int k = temp->data;
    top= top->next;
    free(temp);
    return k;
}
