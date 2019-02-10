//Stacks using arrays

//including libraries
#include<iostream>
using namespace std;

//declaring class Stack
class stackARR{
    public:
    //declaring variables
    int top;
    //constructor to assign default value to top
    stackARR(){
        top=-1; //index out of bounds for any array declared.
    }
    //declaring array of size 10 as our stack
    int arr[10];
   
    //writing function push to input value in the stack
    void push(){
        //declaring variables
        int n, i;
        //asking user for the desired number of elements in stack
        cout<<"Enter the number of elements desired in stack."<<endl;
        cin>>n;
        //checking if stack will overflow
        if(n>10){
            //accepting values from user
            for(i=0; i<10; i++){
                cout<<"Enter element of stack."<<endl;
                cin>>arr[i];
            }
            //warning message
            cout<<"No more elements allowed as stack will overflow."<<endl;
            top=9; //top is the index of last element in array, as n>10
        }
        else{
            //accepting values from user
            for(i=0; i<n;i++){
                top++; //incrementing top
                cout<<"Enter element of stack."<<endl;
                cin>>arr[i];
            }
        }
    }

    //writing function pop to delete value from stack
    void pop(){
        //shifting top by one index would essentially delete the element as it would move out of the stack
        top--;
    }

    //function to check size of stack
    int size(){
        //size of stack is essentially top+1
        return (top+1);
    }

    //function to check if stack is empty
    void isEmpty(){
        //essentially is value of top is still -1, then stack is empty
        if(top==-1) cout<<"Stack is empty."<<endl;
        else cout<<"Stack is not empty."<<endl;   
    }

    //function to display stack
    void display(){
        //declaring variables
        int i;
        //the stack is basically from arr[top] to arr[0]
        //displaying the stack
        for(i=top; i>=0; i--) cout<<arr[i]<<"->";
        cout<<"NULL"<<endl;
    }

    //function to display element in top of stack
    void topDisp(){
        //printing value stored in top
        cout<<arr[top]<<endl;
    }
};

//writing main function
int main(){
    //making object of class stack
    stackARR s1;
    //calling function to insert values in stack
    s1.push();
    //declaring variables
    int cn, i;
    //calling function to check if stack is empty
    s1.isEmpty();
    //calling function to get size of stack
    cn=s1.size();
    //displaying size of stack
    cout<<"The size of original stack = "<<cn<<endl;
    //displaying the original stack
    cout<<"The Original Stack :"<<endl;
    s1.display();
    //displaying the top element of stack
    cout<<"The top element of original stack = ";
    s1.topDisp();
    //calling function to delete elements from stack
    for(i=0; i<cn; i++){
        s1.pop();
        //displaying stack after deleting one element
        cout<<"Stack after deleting "<<(i+1)<<" element(s) :"<<endl;
        s1.display();
    }
    //returning integer value to main function
    return 0;
}
