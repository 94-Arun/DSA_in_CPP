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

    void insert(int val,int pos){
        Node* newnode = new Node(val);
        Node* temp = head;

        for(int i = 0;i<pos-1;i++){
            if(temp==NULL){
                cout<<"Invalid Position:";
                return;

            }
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;   
    }

    void pop_front(){
        Node* temp = head;
        if(temp == NULL) cout<<"List Dosnt Exist";
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
};



int main(){ 

    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.display();
    // cout<<endl;
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);
    ll.display();
    // cout<<endl;
    ll.insert(10,3);
    ll.insert(7,6);
    ll.display();
    ll.pop_front();
    ll.display();
}
 