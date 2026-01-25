#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;


    Node(int val){
        data = val;
        next = NULL;
    }

    // ~Node(){
    //     cout<<"~Node "<<data<<endl;
    //     if(next != NULL){
    //         delete next;
    //         next = NULL;
    //     }
    // }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = NULL;
        tail = NULL;
    } 

    // ~List(){
    //     cout<<"~List"<<endl;
    //     if(head != NULL){
    //         delete head;
    //         head = NULL;
    //     }
    // }
    
    // operations on linked list
    
    void push_front(int data){
        Node* newnode = new Node(data);

        if (head == NULL){
            head = tail = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }

    }

    void display(){
        Node* temp = head;
        if(head == NULL) cout<<"Empty List:"<<endl;
        else{
            while(temp!=NULL){
                cout<<temp->data<<"->";
                temp = temp->next;
            } 
            cout<<"NULL";
            cout<<endl;
            
        }
    }

    void push_back(int val){
        Node* newnode = new Node(val);
        if (head == NULL){
            head = tail = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    int getSize(){
        Node* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void removeNth(int n){
        int size = getSize();

        // For Invalid Position
        if(n<0 || n>size){
            cout<<"Invalid Position";
            return ;
        }

        // if the node is head
        
        if(n == size){
            Node* temp = head;
            head = temp->next;
            delete temp;
        }


        Node* prev = head;

        for(int i = 1;i<(size-n);i++){
            prev = prev->next;
        }
        Node* todelete = prev->next;
        prev->next = todelete->next;

        delete todelete;
    }  
};

int main(){ 

    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);

    ll.display();
    // cout<<ll.getSize();
    ll.removeNth(3);
    ll.display();



}
 