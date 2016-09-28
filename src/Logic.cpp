#include <iostream>
#include <cstdlib>
#include "Queue.cpp"
using namespace std;


int maxInterval = 0;
int serviceTime = 0;
int arrivalTime = 0;
int customer = 1;
int currentTime = 0;
int lastCustWait = 0;
int longestWait = 0;
int longestQueue = 0;
int firstCustomerWait = 0;
int first = 0;
Queue *q = new Queue();

void newCustomer();
void service();
void run();


int main(){
	run();
	return 0;
}

void newCustomer(){
	arrivalTime = rand() % maxInterval + 1;
	q->push(arrivalTime);
	if (q->length() > longestQueue){
		longestQueue = q->length();
	}
}

void service(){
	cout << "Customer " << customer << " arrived at " << currentTime << "." << endl;
	serviceTime = rand() % maxInterval + 1;
	lastCustWait += serviceTime;
	if (customer == 1){
		firstCustomerWait = serviceTime;
	}
	if (lastCustWait > longestWait){
		longestWait = lastCustWait;
	}
	
}

void run(){
	cout << "Please enter the max interval for an incoming customer: " << endl;
	cin >> maxInterval;
	newCustomer();
	first = arrivalTime;
	while (currentTime != 720){
		if (arrivalTime == currentTime){
			newCustomer();
		}
		if (currentTime >= first){
		if (serviceTime == 0){
			if (customer != 1){
				cout << "Customer " << customer << " left at " << currentTime << "." << endl;
			customer++;
			}
			lastCustWait = q->pop();
			service();
		}}
		if (firstCustomerWait == 0){
			cout << "Customer " << customer << " left at " << currentTime << "." << endl;
			customer++;
		}
		firstCustomerWait--;
		serviceTime--;
		currentTime++;
	}
	cout << "The longest queue was: " << longestQueue << "." << endl;
	cout << "The longest wait was: " << longestWait << "." << endl;
}
