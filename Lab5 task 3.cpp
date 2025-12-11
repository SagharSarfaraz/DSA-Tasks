//Lab5 linear search and binear search part 2
//Q No.3 : Write a C++ program that:
//• Takes an array of student roll numbers.
//• If the entered roll number is even, perform Binary Search in ascending order.
//• If the entered roll number is odd, perform Binary Search in descending order.
//• Display the position of the roll number if found, otherwise show an appropriate message.
#include<iostream>
using namespace std;
int main(){
	int n,key;
	//Number of Student
	cout<<"Enter the num of student"<<endl;
	cin>>n;
	int result=-1;
	//If user enter the Even Number
	//Bineary Search in Assending Order
	if(n%2==0){
		cout<<"you enter a Even number"<<endl;
		cout<<"Now Binery Search in Assending order"<<endl;
	//Loop for rollno of student
			int rollno[n];
		for(int i=0;i<n;i++){
			rollno[i]=i+1;
			cin>>rollno[i];
		}cout<<endl;
		//Key for searching the rollno
		cout<<"Enter the key"<<endl;
		cin>>key;
		int st=0,end=n-1,mid;
		while(st<=end){
			mid=(st+end)/2;
			if(rollno[mid]==key){
				result=mid;
				break;
			}else if(rollno[mid]<key){
				st=mid+1;
			}else{
				end=mid-1;
			}
		}
		if(result!=-1){
			cout<<"key"<<" "<<key<<" "<<"key found at position"<<result+1<<endl;
		}else{
			cout<<"Record not found"<<endl;
		}
		//IF user enter the odd number
		//Bineary Search in Desending order
	}else if(n%2!=0){
				cout<<"you enter a odd number"<<endl;
		cout<<"Now Binery Search in dessending order"<<endl;
		int rollno[n];
		//Loop for rollno of Student
		
		for(int i=0;i<n;i++){
			rollno[i]=n-i;
			cout<<rollno[i]<<" ";
		}
		cout<<endl;
		//Key fo Searching the rollno
		cout<<"Enter the key"<<endl;
		cin>>key;
		int st=0,end=n-1,mid;
		while(st<=end){
			mid=(st+end)/2;
			if(rollno[mid]==key){
				result=mid;
				break;
			}else if(rollno[mid]>key){
				st=mid+1;
			}else{
				end=mid-1;
			}
		}	if(result!=-1){
			cout<<"key"<<" "<<key<<" "<<"found at position"<<" "<<result+1<<endl;
		}else{
			cout<<"Record not found"<<endl;
		}
		return 0;
	}
}
