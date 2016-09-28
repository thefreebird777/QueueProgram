#include <iostream>
#include "Queue.h"

Queue::Queue()
{
  count = 0;
  f = NULL;
  r = NULL;
  temp = NULL;
  nNode = NULL;
}

Queue::Queue(int n)
{
  count = 0;
  push(n);
}

Queue::~Queue()
{
  delete f;
  delete r;
  delete temp;
  delete nNode;
}

void Queue::push(int n)
{
  count++;

  nNode = new node;
  nNode->data = n;
  nNode->next = NULL;

  if (f == NULL)
  {
    f = r = nNode;
    r->next = NULL;
  }
  else
  {
    r->next = nNode;
    r = nNode;
    r->next = NULL;
  }
}

int Queue::pop()
{
  int t;

  if (f == NULL)
  {
   std::cout << "There is no value to pop, as the queue is empty.";
  }
  else
  {
    count--;

    temp = f;
    t = temp->data;
    f = f->next;
    delete temp;
    return t;
  }
}

int Queue::length()
{
  return count;
}

bool Queue::isEmpty()
{
  if(count == 0)
    return true;
  else
    return false;
}
