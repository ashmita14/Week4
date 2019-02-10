//Quick Sort

//including libraries
#include<iostream>
using namespace std;

//declaring function partition
int partition(int arr[],int pivot, int low, int high){
	//declaring variables
	int temp;
	//variable to store index position of pivot as it moves across array
	int j=high;
	//loop to move across array from pivot to first element
	for(int i=high-1; i>=low; i--){
		//if any element is greater than pivot it is moved to the right of pivot
		if(arr[i]>pivot){
			//swapping element with pivot
			temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
			j--; //updating position of new pivot
		}
	}
	//returning the index value of pivot to caller function
	return j;
}

//declaring class quick sort
void quick(int arr[], int low, int high){
	//declaring and initializing variables
	int m, l, h;	
	l=low;
	h=high;
	//declaring and initializing pivot
	int pivot=arr[high];
	//calling partition function to create a partition, m stored the value of position of pivot in array
	m=partition(arr,pivot, l, h);
	//condition to create further partitions on the left hand side of pivot
	if((m-1)>=l && (m+1)<=h){
		quick(arr, l, m-1); //recursively calling quick sort function
		//condition to create further partitions on the right hand side of pivot
		quick(arr, m+1, h); //recursively calling quick sort function
	}
}

//declaring main function
int main(){
	//declaring variables
	int i, n;
	//asking user for size of array
	cout<<"Enter the desired size of array."<<endl;
	cin>>n;
	//declaring array of required size
	int arr[n];
	//accepting value of elements of array from user
	cout<<"Enter value of elements in the array."<<endl;
	for(i=0; i<n; i++){
		cout<<"Enter value."<<endl;
		cin>>arr[i];
	}
	//calling quick sort function
	quick(arr, 0, n-1);
	//printing sorted array
	cout<<"Printing sorted array."<<endl;
	for(i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	//returning integer value to main function
	return 0;
}

	
