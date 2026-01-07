//Lab_Task 09
//Scenario: 
//You are a software developer working for a customer support center of a large  
//company. Customers submit service tickets when they need assistance. Since  
//multiple tickets can be submitted at the same time, the system must process  
//requests in the order they arrive (FIFO - First In, First Out). 
//To ensure smooth handling of customer issues, you need to implement a queue-based  
//system that manages service tickets efficiently. 
//Requirements: 
//• Add a customer ticket (enqueue). 
//• Process the next customer ticket (dequeue). 
//• Display all pending tickets. 
//• Check if the queue is empty or full. 
//• Allow a customer to cancel their ticket (advanced challenge). 
//Submission Requirements 
//• Submit the report and source file, with comments explaining each function. 
//• Ensure the code compiles and runs without errors. 
//• Write test cases demonstrating all operations in the program. 
//Course Learning Outcome 
//Implement data structures such as linked list
#include<iostream>
using namespace std;
struct Ticket{
	int id;
	Ticket*next;
};
Ticket*front=NULL;
Ticket*rear=NULL;

bool isEmpty(){
	return front==NULL;
}
bool isFULL(){
	return false;
}
void enqueue(int ticketID){
	Ticket*newTicket=new Ticket();
	newTicket->id=ticketID;
	newTicket->next=NULL;
	if(isEmpty()){
		front=rear=newTicket;
	}else{
		rear->next=newTicket;
		rear=newTicket;
	}
	cout<<"Ticket added :"<<ticketID<<endl;
}
void dequeue(){
	if(isEmpty()){
		cout<<"No ticket to process"<<endl;
		return ;
	}
	Ticket*temp=front;
	cout<<"Procssing ticket"<<temp->id<<endl;
	front=front->next;
	delete temp;
	if(front==NULL)
	rear=NULL;
}
void display(){
	if(isEmpty()){
		cout<<"No pending tickets"<<endl;
		return;
	}
	Ticket*temp=front;
		cout<<"No pending Tickets (FIFO)"<<endl;
		while(temp!=NULL){
			cout<<temp->id<<endl;
			temp=temp->next;
		}
	}
	
	void cancelTicket(int ticketID){
		if(isEmpty()){
			cout<<"Queue is Empty"<<endl;
			return;
		}
		Ticket*temp=front;
		Ticket*prv=NULL;
		while(temp!=NULL && temp->id !=ticketID ){
			prv=temp;
			temp=temp->next;
		}
		if(temp==NULL){
			cout<<"Ticket not Found"<<endl;
			return;
		}
		if(temp==front)
		front=front->next;
		else
		prv->next=temp->next;
		if(temp==rear)
		rear=prv;
		delete temp;
		cout<<"Ticket Cancelled"<<ticketID<<endl;
	}
		int main(){
			enqueue(101);
			enqueue(102);
			enqueue(103);
			cout<<endl;
			display();
			cout<<endl;
			dequeue();
			cout<<endl;
			display();
			cout<<endl;
			cancelTicket(102);
			cout<<endl;
			display();
			if(isEmpty()){
				cout<<"Queue is Empty"<<endl;
				}else{
					cout<<"Queue is Not Empty"<<endl;
					}
					return 0;
			}
