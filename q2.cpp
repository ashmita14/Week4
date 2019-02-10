//Queue using two stacks

//including library
#include<iostream>
using namespace std;

//declaring class Node
class Node{
    public:
    //declaring variables to store variable in node
    int data;
    //declaring pointer to point to next Node
    Node *next;
    //constructor to give default value to next
    Node(){
        next=NULL;
    }
};

//declaring class Stack
class Stack{
    public:
    //declaring pointer of node type to point to first element of stack
    Node *head;
    //default constructor
    Stack(){
        head=NULL;
    }

    //writing function to insert at first
    void push(int value){
        //creating new pointer of Node type and a new Node which the temp points to
        Node *temp= new Node;
        //checking if the stack is empty
        if(head==NULL){
            head=temp; //head now points to the new node created, which becomes the first node
            head->data=value; //value stored in first node
            head->next=NULL; //pointer of the first node points to NULL
        }
        //if stack is not empty
        else{
            //storing the address of head in temp's next, thus it now points to the original head
            temp->next=head;
            //updating head, as the new element is the head, because insertion only allowed from top
            temp->data=value;
            head=temp;
        }
    }

    //writing function to delete at first point
    int pop(){
        //creating pointer of Node type to point to the first Node which needs to be deleted
        Node *current=head;
        //warning message
        if(head==NULL) cout<<"Cannot pop out of empty stack."<<endl;
        else{
            //to delete the first element making head point to the next Node so that the stack is not lost
            head=current->next;
            //returning current's data
            return current->data;
        }
    }

    //writing function to count the number of items
    int countItems(){
        //creating a new pointer of Node type to move across the stack, starting from head
        Node *current=head;
        //declaring counter variable
        int c=0;
        while(current!=NULL){
            c++;
            current=current->next; //moving one Node forward
        }
        //returning value to caller function
        return c;
    }

    //writing function to display the stack
    void display(){
        //creating a new pointer of Node type to move across the stack, starting from head
        Node *current=head;
        //displaying items
        while(current!=NULL){
            cout<<current->data<<"->";
            current=current->next; //moving one Node forward
        }
        cout<<"NULL"<<endl;
    }

    //writing function to display first element
    void displayTop(){
        cout<<head->data<<endl;
    }
};

//creating class queue
class Queue{
    public:
    //creating object of class stack
    Stack s1;
    Stack s2;
    //declaring variables
    int n;
    //writing function to insert values in queue
    void enqueue(){
        //declaring variables
        int i, x;
        //asking user for number of desired elements in queue
        cout<<"Enter number of elements desired in queue."<<endl;
        cin>>n;
        //accepting value
        for(i=0; i<n; i++){
            cout<<"Enter value in queue."<<endl;
            cin>>x;
            //calling function push to pass    value in first stack
            s1.push(x);
            x=0;
        }
    }
   
    //writing function to delete elements from queue
    void dequeue(){
        //declaring variable i as store of size of queue
        int i=s1.countItems();
        int c;
        //popping values from stack 1 and pushing into stack 2 till last element of stack 1 reached
        while(i>0){
            s2.push(s1.pop());
            i--; //decremting i
        }
        //deleting the top element of stack 2, which is originally the first value of queue
        c=s2.pop();
        //pushing back values from stack2 to stack1
        i=s2.countItems();
        while(i>0){
            s1.push(s2.pop());
            i--; //decrementing i
        }
    }

    //displaying queue
    void Disp(){
        //calling display function
        s1.display();
    }

    //counting size of queue
    int size(){
        //declaring variables
        int cn;
        //calling function to count
        cn=s1.countItems();
        //displaying value
        cout<<"Number of elements = "<<cn<<endl;
        return cn;
    }

    //checking if empty
    void isEmpty(){
        //declaring variables
        int cn;
        //calling function
        cn=s1.countItems();
        //checking cn
        if(cn==0) cout<<"Empty queue."<<endl;
        else cout<<"Queue is not empty."<<endl;
    }
};

//writing main function
int main(){
    //creating object of class Queue
    Queue q1;
    //declaring variables
    int i, cc;
    //calling function to input values
    q1.enqueue();
    //calling function to check if queue is empty
    q1.isEmpty();
    //calling function to display size of queue
    cc=q1.size();
    //displaying original queue
    cout<<"The Original Queue :"<<endl;
    q1.Disp();
    //running loop to delete elements from queue
    for(i=0; i<cc; i++){
        q1.dequeue(); //declaring function to delete
        //displaying queue after each deletion
        cout<<"Queue after deleting "<<i<<" element(s)."<<endl;
        q1.Disp();
    }
    //returning integer value to main function
    return 0;
}


