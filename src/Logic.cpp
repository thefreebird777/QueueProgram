#include <iostream>
#include <cstdlib>
#include "Queue.cpp"
using namespace std;


int maxInterval = 0;
int serviceTime = 0;
int arrivalTime = 0;
int customerArrive = 1;
int customerDepart = 1;
int currentTime = 0;
int lastCustWait = 0;
int longestWait = 0;
int longestQueue = 0;
int firstCustomerWait = 100;
bool first = false;
Queue *q = new Queue();

void newCustomer();
void service();
void run();


int main(){
	run();
	return 0;
}

void  newCustomer(){
	arrivalTime = rand() % maxInterval + 1;
	arrivalTime += currentTime;
//	cout << "Customer " << customerArrive << " arrived at " << arrivalTime << "." << endl;
//	customerArrive++;
//	q->push(arrivalTime);
//	if (q->length() > longestQueue){
//		longestQueue = q->length();
//	}
}

void service(){
//	cout << "Customer " << customer << " arrived at " << currentTime << "." << endl;
	serviceTime = rand() %  maxInterval + 1;
	lastCustWait += serviceTime;
	if (customerDepart == 1){
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
	first = true;
	while (currentTime != 720){
		//starts service for first customer
		if(q->isEmpty() && first == true){
			if (arrivalTime == currentTime){
				first == false;
				cout << "Customer " << customerArrive << " arrived at " << arrivalTime << "." << endl;
				customerArrive++;
				service();
			}
		}
		
		//gets next customers arrival once one arrives and stores arrived customer in queue
		if( arrivalTime == currentTime){
			cout << "Customer " << customerArrive << " arrived at " << arrivalTime << "." << endl;
			customerArrive++;
			newCustomer();
			q->push(arrivalTime);
			if (q->length() > longestQueue){
				longestQueue = q->length();
			}	
		}

		//TODO for some reason the seviceTime == 0 and the !q-isEmpty() work fine on their own but do not work together
		//also, the variable first always is true here despite being changed to false after the first customer

		//starts the service process once previous customer finishes	
		if (serviceTime == 0 && !q->isEmpty() && first == false) {
			cout << "Customer " << customerDepart << " left at " << currentTime << "." << endl;
			customerDepart++;
			lastCustWait = q->pop();
			service();
			}
	
		firstCustomerWait--;
		serviceTime--;
		currentTime++;
	}	
	
	cout << "The longest queue was: " << longestQueue << "." << endl;
	cout << "The longest wait was: " << longestWait << "." << endl;
}
