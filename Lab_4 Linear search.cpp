//Q. No.1: Include Definition and Algorithm of Binary search.
//Q No.2 : You are hired as a junior software developer in a university’s IT department.
//Your supervisor assigns you to develop a student record search system that allows efficient
//retrieval of student roll numbers from stored arrays.
//Some classes maintain records in random order, while others are sorted for faster lookup.
//To support both situations, you are required to implement two searching methods — Linear
///Search (for unsorted arrays) and Binary Search (for sorted arrays).
//Your task is to design a C++ program that can perform both searches based on user selection,
//and display results clearly and accurately.

//Q No.3 : Write a C++ program that:
//• Takes an array of student roll numbers.
//• If the entered roll number is even, perform Binary Search in ascending order.
//• If the entered roll number is odd, perform Binary Search in descending order.
//• Display the position of the roll number if found, otherwise show an appropriate message.
#include<iostream>
using namespace std;
int main(){
	//Student Rollno and Marks of Three Books
	int rollno[30]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	int PF[30]={1,22,33,14,25,36,47,48,59,10,11,42,14,17,45,66,77,48,49,40,61,42,43,54,45,56,47,48,29,30};
	int OOP[30]={31,52,53,44,35,46,27,38,49,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	int DSA[30]={45,42,33,24,45,56,67,68,49,56,17,62,53,44,65,46,67,48,59,40,51,62,43,44,45,46,24,29,39,50};

	int key,total;
	float percentage;
	//key for Searching Rollno
	cout<<"Enter the rollno for Search"<<endl;
	cin>>key;
	
	for(int i=0;i<30;i++){
		if(rollno[i]==key){
			key=rollno[i];
			total=PF[i]+OOP[i]+DSA[i];
			percentage=total*100/300;
		cout<<"Student Record Found"<<endl;
		cout<<"PF Marks"<<PF[i]<<endl;
		cout<<"OOP Marks"<<OOP[i]<<endl;
		cout<<"DSA Marks"<<DSA[i]<<endl;
		cout<<"Total"<<total<<"/300"<<endl;
		cout<<"Percentege"<<percentage<<endl;
		if(percentage>90 && percentage< 100){
			cout<<" Grade A"<<endl;
		}else if(percentage>80 && percentage< 90){
			cout<<" Grade B"<<endl;
		}else if(percentage>70 && percentage< 80){
			cout<<" Grade C"<<endl;
		}else if(percentage>60 && percentage< 70){
			cout<<" Grade D"<<endl;
		}else if(percentage>50 && percentage< 60){
			cout<<" Grade E"<<endl;
		}else if(percentage>0 && percentage< 50){
			cout<<" Grade F"<<endl;
		}
		}
	}
	
	if(key<1){
		cout<<"Record not Found"<<endl;
	}else if(key>30){
		cout<<"Record not Found"<<endl;
	}return 0;

}
