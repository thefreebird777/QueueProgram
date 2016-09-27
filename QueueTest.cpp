#include <iostream>
#include "Queue.cpp"

int main()
{
  Queue *q = new Queue(); // initialize

  // test isEmpty()
  if (q->isEmpty())
    std::cout << "The queue is empty (as it should be).\n";
  else
    std::cout << "Something is horribly wrong if the queue isn't empty here.";

  // test push() and length()
  q->push(1);
  std::cout << "The queue has " << q->length() << " values in it.\n";
  q->push(5);
  std::cout << "The queue has " << q->length() << " values in it.\n";
  q->push(22);
  std::cout << "The queue has " << q->length() << " values in it.\n\n";
  
  // test pop() and length()
  std::cout << "The queue pops the value: " << q->pop() << ".\n";
  std::cout << "The queue has " << q->length() << " values in it.\n";
  std::cout << "The queue pops the value: " << q->pop() << ".\n";
  std::cout << "The queue has " << q->length() << " values in it.\n";
  std::cout << "The queue pops the value: " << q->pop() << ".\n";
  std::cout << "The queue has " << q->length() << " values in it.\n";
  
  if (q->isEmpty())
    std::cout << "The queue is empty (as it should be).";
  else
    std::cout << "Something is horribly wrong if the queue isn't empty here.";

  return 0;
}
