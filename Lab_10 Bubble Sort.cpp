//Lab _10 Bubble Sort
//Array Format: saleries of perment employ is sortd Array'
//To genrate a payroll report,the company need the salery data in Ascending order  
//Your task is to implement bubble sorted algorthim to sort both datasets,ensuring the final output
//is presented in sorted order with at least 10 saleries values

//Submission Requirment
//Submit the report and source file,with comments explaning each function
//Ensure the complies and run without errors
//write test case demonstrateing all opreation in the program. 
#include<iostream>
using namespace std;
//Function to Perfrom Bubble Sort
void Bubblesort(int salery[],int n){
	int temp;
	//Loop for bubble Sort
	for(int i=0;i<n-1;i++){
		//Loop for Comparsion 
		for(int j=0;j<n-i-1;j++){
			//
			if(salery[j]>salery[j+1]){
			//Swap if in worng order	
			temp=salery[j];
			salery[j]=salery[j+1];
			salery[j+1]=temp;	
				
			}
		}
	}
} 
//Function for Display array
void display(int salery[],int n){
	for(int i=0;i<n;i++){
		cout<<salery[i]<<" ";
	}
	cout<<endl;
}
int main(){
	//Aray for Employe saleries 
	int salery[10]={55000,42000,36000,72000,57000,80000,31000,87000,100000,11000};
	int n=10;
	cout<<"Origenal salery Data"<<endl;
	display(salery,n);
	//Sorted saleries
	Bubblesort(salery,n);
	cout<<"Sorted Salery data"<<endl;
	display(salery,n);
	return 0;
}