//Queues using arrays

//including libraries
#include<iostream>
using namespace std;

//declaring class queue
class queueARR{
    public:
    //declaring variables
    int end, front, n;
    //declaring array of size 10 for queue
    int arr[10];
    //constructor to initialize default value to end and front
    queueARR(){
        //index -1 is out of bound for any array declared
        end=-1;
        front=-1;
    }

    //writing function enqueue to insert values in queue
    void enqueue(){
        //declaring variables
        int i;
        //asking user for desired number of elements in queue
        cout<<"Enter number of elements desired to be in queue."<<endl;
        cin>>n;
        //checking if queue will overflow
        if(n>10){
            //accepting values
            for(i=0; i<10; i++){
                cout<<"Enter element in queue."<<endl;
                cin>>arr[i];
            }
            end=9; //end will by default be the last index of array as n>10
        }
        else{
            //accepting values
            for(i=0; i<n; i++){
                end++; //updating end as it would be the index of last element added in array
                cout<<"Enter element in queue."<<endl;
                cin>>arr[i];
            }
        }
        if(n>0) front= 0; //if queue is not empty, front will be zero always, as it represents index of first element added
    }
   
    //writing function dequeue to delete values from queue
    void dequeue(){
        //warning message
        if((n>10 && front>9)|| (n<10 && front>(n-1))) cout<<"Queue already empty."<<endl;
        else{
            //increasing the value of front by one essentially removes the element as the queue is from arr[front] to arr[end]
            front++;
        }
    }

    //function to check size of queue
    int size(){
        //size of queue is essentially end-front+1
        return (end-front+1);
    }

    //function to check if queue is empty
    void isEmpty(){
        //essentially is value of end and front is still -1, then queue is empty
        if(end==-1) cout<<"Queue is empty."<<endl;
        else cout<<"Queue is not empty."<<endl;   
    }

    //function to display queue
    void display(){
        //declaring variables
        int i;
        //the queue is basically from arr[front] to arr[end]
        //displaying the queue
        for(i=end; i>=front; i--) cout<<arr[i]<<"->";
        cout<<"NULL"<<endl;
    }

    //function to display first element of queue
    void frontDisp(){
        //printing value stored in front
        cout<<arr[front]<<endl;
    }
};

//writing main function
int main(){
    //making object of class queue
    queueARR q1;
    //calling function to insert values in queue
    q1.enqueue();
    //declaring variables
    int cn, i;
    //calling function to check if queue is empty
    q1.isEmpty();
    //calling function to get size of queue
    cn=q1.size();
    //displaying size of queue
    cout<<"The size of original queue = "<<cn<<endl;
    //displaying the original queue
    cout<<"The Original Queue :"<<endl;
    q1.display();
    //displaying the top element of queue
    cout<<"The first element of original queue = ";
    q1.frontDisp();
    //calling function to delete elements from queue
    for(i=0; i<cn; i++){
        q1.dequeue();
        //displaying queue after deleting one element
        cout<<"Queue after deleting "<<(i+1)<<" element(s) :"<<endl;
        q1.display();
    }
    //returning integer value to main function
    return 0;
}

