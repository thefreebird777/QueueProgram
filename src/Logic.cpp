#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;


int maxInterval = 0;
int serviceTime = 0;
int arrivalTime = 0;
int customer = 1;
int time = 0;
int lastCustWait = 0;
int longestWait = 0;
int longestQueue = 0;
queue <int> queue;

cout << "Please enter the max interval for an incoming customer: ";

cin << maxInterval;

public void newCustomer(){
	arrivalTime = rand() % maxInterval + 1;
	queue.push(arrivalTime);
	if (queue.size() > longestQueue){
		longestQueue = queue.size();
	}
}


public void service(){
	cout << "Customer " << customer << " arrived at " << time << ".";
	serviceTime = rand() % maxInterval + 1;
	lastCustWait += serviceTime;
	if (lastCustWait > longestWait){
		longestWait = lastCustWait;
	}
	
}


public void run(){
	newCustomer();
	while (time != 720){
		if (arrivalTime == time){
			newCustomer();
		}
		if (serviceTime == 0){
			cout << "Customer " << customer << " left at " << time << ".";
			customer++;
			lastCustWait = queue.pop();
			service();
		}
		serviceTime--;
		time++;
	}
}