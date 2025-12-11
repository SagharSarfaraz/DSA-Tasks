//Lab 5_Linear search code part 1

//Q. No.1: Include Definition and Algorithm of Binary search.
//Q No.2 : You are hired as a junior software developer in a university’s IT department.
//Your supervisor assigns you to develop a student record search system that allows efficient
//retrieval of student roll numbers from stored arrays.
//Some classes maintain records in random order, while others are sorted for faster lookup.
//To support both situations, you are required to implement two searching methods — Linear
//Search (for unsorted arrays) and Binary Search (for sorted arrays).
//Your task is to design a C++ program that can perform both searches based on user selection,
//and display results clearly and accurately.
#include<iostream>
using namespace std;
int main(){
	int n,key,choice;
	//Number of Student
	cout<<"Enter the number of Student"<<endl;
	cin>>n;
	//Loop for entering the Student one by one
	int rollno[n];
	cout<<"Enter the rollno"<<endl;
	for(int i=0;i<n;i++){
		cin>>rollno[i];
	}
	//Linear Search for Unsorted
	//Binery Search For Sorted
	cout<<"1.Linear Search"<<endl;
	cout<<"2. Binery Search"<<endl;
	cout<<"Enter your Choice"<<endl;
	cin>>choice;
	//Key for Searching the Rsult
	cout<<"Enter the key for Search"<<endl;
	cin>>key;
	int result=-1;
	if(choice==1){
		//Linear Search
		for(int i=0;i<n;i++){
			if(rollno[i]==key){
			result=i;
				break;
			}
		}
}else if(choice==2){
	//Bineary Search
int st=0,end=n-1,mid;
while(st<=end){
	mid=(st+end)/2;
	if(rollno[mid] ==key){
		result=mid;
		break;
	}else if(rollno[mid]<key){
		st=mid+1;
	}else{
		end=mid-1;
	}
}
}else{
	//If user enter choice which not in the code
	cout<<"Invalid Choice"<<endl;
return 0;
}


    if (result != -1)
        cout << "Roll number " << key << " found at position " << result + 1 << endl;
    else
        cout << "Roll number not found!" << endl;

    return 0;

}
