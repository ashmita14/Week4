//Stacks using Linked List

//including libraries
#include<iostream>
using namespace std;

//class Node
class Node{
    public:
    //declaring class variable to store value in node
    int data;
    //declaring pointer of the node used to point to next node
    Node *next;    
    //default constructor to assign default value to next pointer.
    Node(){
        next=NULL;
    }
};

//Linked List class
class lnlist{
    public:
    //declaring pointer of node type to popint to first element of linked list
    Node *head;
    //default constructor
    lnlist(){
        head=NULL;
    }
    
    //writing function to insert at any point
    void insertAt(int value,int pos){
        //creating new pointer of Node type and a new Node which the temp points to
        Node *temp= new Node;
        //checking if the linked list is empty
        if(head==NULL){
            head=temp; //head now points to the new node created, which becomes the first node
            head->data=value; //value stored in first node
            head->next=NULL; //pointer of the first node points to NULL
        }
        //if linked list is not empty
        else{
            //storing the address of head in temp's next, thus it now points to the original head
            temp->next=head;
            //updating head, as the new element is the head, because insertion only allowed from top
            temp->data=value;
            head=temp;
        }
    }

    //writing function to delete at any point
    void delAt(int pos){
        //creating pointer of Node type to point to the first Node which needs to be deleted
        Node *current=head; 
        //warning message
        if(head==NULL) cout<<"Cannot pop out of empty stack."<<endl;
        else{
            //to delete the first element making head point to the next Node so that the linked list is not lost
            head=current->next;
            //deleting current
            delete current;
        }
    }

    //writing function to count the number of items
    int countItems(){
        //creating a new pointer of Node type to move across the linked list, starting from head
        Node *current=head;
        //declaring counter variable
        int c=0;
        while(current!=NULL){
            c++;
            current=current->next; //moving one Node forward
        }
        //returning counter variable to caller function
        return c;
    }

    //writing function to display the linked list
    void display(){
        //creating a new pointer of Node type to move across the linked list, starting from head
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

//declaring class for creating stacks using linked list
class stackLL{
    public:
    //creating object of class linked list
    lnlist l1;
    //declaring variables 
    int cn;
    //writing push function
    void push(){    
        //declaring variables 
        int n, i, x;
        //asking user for the size of desired stack
        cout<<"Enter the required size of stack."<<endl;
        cin>>n;
        //asking user for the elements of stack
        for(i=0; i<n; i++){
            cout<<"Enter value of element."<<endl;
            cin>>x;
            //passing value to function
            l1.insertAt(x, 1);
            x=0;
        }
    }

    //writing function to calculate size
    int size(){
        //calling function to count number of items in stack
        cn=l1.countItems();
        //displaying the size of stack
        cout<<"Size of stack = "<<cn<<endl;
        return cn;
    }

    //writing function to check if stack is empty
    void isEmpty(){
        //declaring variables
        int cc;
        //calling count function to count the number of elements in stack
        cc=l1.countItems();
        if(cc==0) cout<<"Empty Stack."<<endl;
        else cout<<"Stack is not empty."<<endl;
    }

    //writing function to delete elements from stack
    void pop(){
        //calling delete function
        l1.delAt(1);
    }

    //writing function to display the top element of stack
    void top(){
        //calling function to display Top of stack
        cout<<"Top of stack = ";
        l1.displayTop();
    }
    
    //writing function to display the stack
    void Display(){
        //calling display function
        l1.display();
    }
};

//writing main function
int main(){
    //creating object of class stackLL
    stackLL s1;
    //declaring variables
    int c, i;
    //calling push function to input value into stack
    s1.push();
    //checking if original stack is empty by calling isEmpty function
    s1.isEmpty();
    //counting the number of elements in stack by calling size function
    c=s1.size();
    //calling function to display the original stack
    cout<<"Original Stack."<<endl;
    s1.Display();
    //calling function to display top element of original stack
    cout<<"Top element of original stack = ";
    s1.top();
    //running loop to delete elements from stack and displaying the changed stack
    for(i=0; i<c; i++){
        //calling pop function to delete element from top
        s1.pop();
        //displaying changed stack 
        cout<<"Stack after deleting "<<i+1<<" element(s)."<<endl;
        s1.Display();
    }
    //returning integer value to main function
    return 0;
}
