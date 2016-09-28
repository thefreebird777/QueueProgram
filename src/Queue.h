#ifndef QUEUE_H_
#define QUEUE_H_

struct node
{
  int data;
  node *next;
};

class Queue
{
  public:
    Queue();
    Queue(int n);
    ~Queue();

    void push(int n);
    int pop();
    int length();
    bool isEmpty();
  private:
    int count;
    node *f; // front of queue
    node *r; // rear of queue
    node *temp; // temp node for removing a value
    node *nNode; // new node for adding a value
};

#endif
