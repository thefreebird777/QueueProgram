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
}

void service(){
	serviceTime = rand() %  maxInterval + 1;
	lastCustWait += serviceTime;
	if (lastCustWait > longestWait){
		longestWait = lastCustWait;
	}
	
}

void run(){
	cout << "Please enter the max interval for an incoming customer: " << endl;
	cin >> maxInterval;
	newCustomer();
	while (currentTime != 720){
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
			
		//starts the service process once previous customer finishes	
		if (serviceTime == 0 ) {
			if(!q->isEmpty()){
				cout << "Customer " << customerDepart << " left at " << currentTime << "." << endl;
				customerDepart++;
				lastCustWait = currentTime - q->pop();
			}
			service();
		}
	
		serviceTime--;
		currentTime++;
	}	
	
	cout << "The longest queue was: " << longestQueue << "." << endl;
	cout << "The longest wait was: " << longestWait << "." << endl;
}
