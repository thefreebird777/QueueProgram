# QueueProgram

TODO:
  - Develop a queue class using a linked list repressentation and integer data
  
    > program to simulate a check-out line at a supermarket
    
    > customers arrive in random integer interval of 1 to x minutes
    
    > customer serviced in random integer interval of 1 to x minutes

    > request value for x at the beginning of the run
    
    > run for 720 minutes
    
  - Choose a random integer between 1 and x to determine the minute the first customer arrives
  
  - At first customer's arrival time:
  
    > print arrival message

    > determine custom's service time (random integer from 1 to x)
    
    > begin servicing customer
    
    > schedule the arrival time of the next customer ( random integer from 1 to x added to the current time)
    
  - For each subsequent minute of the day:
  
    > if next customer arrives:

      > - print arrival message
      
      > - enqueue the customer
      
      > - schedule arrival time of the next customer
      
    > if service was completed for the last customer
    
      > - print a departure message
      
      > - dequeue the next customer to be serviced
      
      > - determine customer's service completion time
      
  - End
    
    > print maximum number of customers in the queue at any one time

    > print longest wait any one customer had
