//Stack using two queues

//including libraries
#include<iostream>
using namespace std;

//declaring class Node to creating elements of queue
class Node{
    public:
    //declaring variable to store data in 
    int data;
    //declaring pointer of node type 
    Node *next;
    //constuctor to initialize pointer as NULL
    Node(){
        next=NULL;
    }
};

//declaring class queue
class Queue{
    public:
    //creating end pointer of node type to mark the last element of queue
    Node *end;
    //creating front pointer of node type to mark the first element of queue
    Node *front;
    //constructor to intialize NULL value to both end and front
    Queue(){
        end=NULL;
        front=NULL;
    }
    
    //writing function to insert elements in the queue
    void enqueue(int value){
        //creating new Node and pointer of node type to point to the created node
        Node *temp=new Node;
        //checking if queue is empty
        if(end==NULL and front==NULL){
            temp->data=value; //storing data in the node
            temp->next=NULL; //making the pointer of node point to NULL
            //making end and front point at temp, making it the first elemnt of queue
            end=temp; 
            front=temp;
        }
        ///when queue is not empty
        else{
            //any new element is added to the 1st position, so the front will remain same, end pointer will change.

            temp->data=value; //storing data in new node-
            temp->next=end; //making temp's next point to the previous end, to add it in the queue after the previous end
            end=temp; //making temp the new end (the last element)
        }
    }

    //writing function to delete elements from the front of the queue
    int dequeue(){
        //the first element added to the queue is deleted first, so front changes with each delete, but end remains the same
        
        //creating new pointer of node type, which starts from end, and goes upto the node just before front
        Node *current=end;
        while(current->next!=front && current->next!=NULL){
            current=current->next; //updating current
        }
        //warning message
        if(current==NULL){ cout<<"No elements to delete, queue is empty."<<endl; return 0;}
        //if the last element is left
        if(current==end && current==front){
            //making both end and front NULL to signify empty queue
            end=NULL; 
            front=NULL;
            return current->data; //passing value of the last element
        }
        //for all other elements
        else{
            //updating front to be the element just before the previous front
            front=current;
            
            current=current->next; //making current the node to be deleted
	    front->next=NULL;
            return current->data; //passing value of the last node
        }
    }

    //writing function to display the elements of queue
    void display(){
        //making new pointer of node type to move across queue from end to front
        Node *current=end;
        while(current!=NULL){
            //displaying element
            cout<<current->data<<"->";
            //updating current
            current=current->next;
        }
        cout<<"NULL"<<endl;
    }

    //writing function to count the number of elements in queue
    int countItems(){
        //making new pointer of node type to move across queue from front to end
        Node *current=end;
        //declaring variables
        int cn=0;
        while(current!=NULL){
            cn++; //incrementing counter variable
            current=current->next; //updating current
        }
        //returning value of cn
        return cn;
    }

};

//writing class stack
class Stack{
	public:
	//making obejcts of class Queue
	Queue q1;	
	Queue q2;
	//declaring variables 
	int n;
	
	//writing function to push values into stack
	void push(){
		//declaring variables
        int i, x;
        //asking user for number of desired elements in stack
        cout<<"Enter number of elements desired in stack."<<endl;
        cin>>n;
        //accepting value
        for(i=0; i<n; i++){
            cout<<"Enter value in stack."<<endl;
            cin>>x;
            //calling function push to pass value in first stack
            q1.enqueue(x);
            x=0;
        }
    }
   
    //writing function to delete elements from stack
    void pop(){
        //declaring variable i as store of size of stack
        int i=q1.countItems()-1;
        int c;
        //popping values from queue 1 and pushing into queue 2 till last element of queue 1 reached
        while(i>0){
            q2.enqueue(q1.dequeue());
            i--; //decremting i
        }
        //deleting the last element left from queue 1, which is originally the last value of stack
        c=q1.dequeue();
        //pushing back values from stack2 to stack1
        i=q2.countItems();
        while(i>0){
            q1.enqueue(q2.dequeue());
            i--; //decrementing i
        }
    }

    //displaying stack
    void Disp(){
        //calling display function
        q1.display();
    }

    //counting size of stack
    int size(){
        //declaring variables
        int cn;
        //calling function to count
        cn=q1.countItems();
        //displaying value
        cout<<"Number of elements = "<<cn<<endl;
        return cn;
    }

    //checking if empty
    void isEmpty(){
        //declaring variables
        int cn;
        //calling function
        cn=q1.countItems();
        //checking cn
        if(cn==0) cout<<"Empty Stack."<<endl;
        else cout<<"Stack is not empty."<<endl;
    }
};

//writing main function
int main(){
    //creating object of class Stack
    Stack s1;
    //declaring variables
    int i, cc;
    //calling function to input values
    s1.push();
    //calling function to check if stack is empty
    s1.isEmpty();
    //calling function to display size of satck
    cc=s1.size();
    //displaying original queue
    cout<<"The Original Stack :"<<endl;
    s1.Disp();
    //running loop to delete elements from stack
    for(i=0; i<cc; i++){
        s1.pop(); //declaring function to delete
        //displaying stack after each deletion
        cout<<"Stack after deleting "<<i<<" element(s)."<<endl;
        s1.Disp();
    }
    //returning integer value to main function
    return 0;
}
	
