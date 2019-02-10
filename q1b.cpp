//Queues using linked list

//including libraries
#include<iostream>
using namespace std;

//declaring class Node to creating elements of linked list
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

//declaring class linked list
class lnlist{
    public:
    //creating end pointer of node type to mark the last element of queue
    Node *end;
    //creating front pointer of node type to mark the first element of queue
    Node *front;
    //constructor to intialize NULL value to both end and front
    lnlist(){
        end=NULL;
        front=NULL;
    }
    
    //writing function to insert elements in the queue
    void insertAt(int value, int pos){
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
    void del(){
        //the first element added to the queue is deleted first, so front changes with each delete, but end remains the same
        
        //creating new pointer of node type, which starts from end, and goes upto the node just before front
        Node *current=end;
        while(current->next!=front && current->next!=NULL){
            current=current->next; //updating current
        }
        //warning message
        if(current==NULL) cout<<"No elements to delete, queue is empty."<<endl;
        //if the last element is left
        if(current==end && current==front){
            //making both end and front NULL to signify empty queue
            end=NULL; 
            front=NULL;
            delete current; //deleting the last element
        }
        //for all other elements
        else{
            //updating front to be the element just before the previous front
            front=current;
            front->next=NULL;
            current=current->next; //making current the node to be deleted
            delete current; //deleting the required node
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
    
    //writing function to check if queue is empty
    void Empty(){
        //checking if both end and front point to NULL, as then the queue is empty and displaying message accordingly
        if(end==NULL && front==NULL)
            cout<<"The queue is empty."<<endl;
        else cout<<"The queue is not empty."<<endl;
    }

    //writing function to display the first and last element of queue
    void topdis(){
        //displaying first element of queue
        cout<<"The first element is = "<<front->data<<endl;
        //displaying the last element of queue
        cout<<"The last element is = "<<end->data<<endl;
    }

};

//declaring class Queue
class QueueLL{
    public:
    //making object of class lnlist
    lnlist l1;
    //writing function enqueue to add elements to queue
    void enqueue(){
        //declaring variables
        int n, i, x;
        //asking user for the desired number if elements in queue
        cout<<"Enter the number of elements in queue."<<endl;
        cin>>n;
        //accepting elements of queue from user
        for(i=0; i<n; i++){
            cout<<"Enter element of queue."<<endl;
            cin>>x;
            //passing value to insert function
            l1.insertAt(x,1);
            x=0;
        }
    }
    
    //writing function to calculate size
    int size(){
        //declaring variables
        int cn1;
        //calling function to count number of items in queue
        cn1=l1.countItems();
        //displaying the size of queue
        cout<<"Size of stack = "<<cn1<<endl;
        return cn1;
    }

    //writing function to check if queue is empty
    void isEmpty(){
        //calling empty function to check if queue is empty
        l1.Empty();
    }

    //writing function to delete elements from queue
    void dequeue(){
        //calling delete function
        l1.del();
    }

    //writing function to display the first and last element of queue
    void top(){
        //calling function to display first and last element of queue
        l1.topdis();
    }
    
    //writing function to display the queue
    void Display(){
        //calling display function
        l1.display();
    }
};

//writing main function
int main(){
    //creating object of class QueueLL
    QueueLL q1;
    //declaring variables
    int c, i;
    //calling enqueue function to input value into queue
    q1.enqueue();
    //checking if original queue is empty by calling isEmpty function
    q1.isEmpty();
    //counting the number of elements in queue by calling size function
    c=q1.size();
    //calling function to display the original queue
    cout<<"Original Queue."<<endl;
    q1.Display();
    //calling function to display first and last elements of original queue
    cout<<"For the Original Queue :-"<<endl;
    q1.top();
    //running loop to delete elements from queue and displaying the changed queue
    for(i=0; i<c; i++){
        //calling pop function to delete element from top
        q1.dequeue();
        //displaying changed stack 
        cout<<"Queue after deleting "<<i+1<<" element(s)."<<endl;
        q1.Display();
    }
    //returning integer value to main function
    return 0;
}

