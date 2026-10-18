#include<iostream>
#include<vector>
using namespace std;

class Node{
public:    
    string key;
    int value;
    Node* next;

    Node(string key,int value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }    
};

class HashTable{
    int totalsize;
    int currsize;
    Node** table;

    int HashFunction(string key){
        int idx = 0;
        for(int i = 0;i<key.size();i++){
            idx = (idx+key[i]*key[i])%totalsize;
        }
        return idx;
    }
    void rehashing(){
        int oldsize = totalsize;
        Node** oldtable = table;
        
        totalsize = totalsize*2;
        currsize = 0;
        table = new Node*[totalsize];

        for(int i = 0;i<totalsize;i++){
            table[i] = NULL;
        }

        // copy old values
        for(int i = 0;i<oldsize;i++){
            Node* temp = oldtable[i];
            while(temp != NULL){
                insert(temp->key,temp->value);
                temp = temp->next;
            }
        }

        for(int i = 0;i<oldsize;i++){
            Node* temp = oldtable[i];
            while(temp != NULL){
                Node* nextnode = temp->next;
                delete temp;
                temp = nextnode;
            }
        }

        delete[] oldtable;

    }

public:
    HashTable(int totalsize = 5){
        this->totalsize = totalsize;
        this->currsize = 0;

        table = new Node*[totalsize];// dynamically created array

        for(int i = 0;i<totalsize;i++){
            table[i] = NULL; // NULL assigned to array elements
        }
    }   
    
    void insert(string key,int value){
        int idx = HashFunction(key);

        Node* newnode = new Node(key,value); 

        newnode->next = table[idx];
        table[idx]= newnode;

        currsize++;

        double lamda = currsize/(double)totalsize;
        if(lamda > 1.0){
            rehashing();
        }
    }

    int remove(string key){
        int idx = HashFunction(key);
        Node* temp = table[idx];
        Node* prevNode = NULL;    

        // find the node
        while(temp->next != NULL && temp->key != key){
            prevNode = temp;
            temp = temp->next;
        }

        // key dosent exist
        if(temp == NULL) return -1;

        int r = temp->value;

        if(prevNode == NULL){
            table[idx] = temp->next;
        }else{
            prevNode->next = temp->next;
        }
        delete temp;
        return r;
    }

    int search(string key){
        int idx = HashFunction(key);
        Node* temp = table[idx];
        while(temp != NULL){
            if(temp->key == key) return temp->value;
            temp = temp->next;
        }    
        return -1;
    }

    void print(){
        for(int i = 0;i<totalsize;i++){
            cout<<"idx "<<i<<" : ";
            Node* temp = table[i];
            while(temp != NULL){
                cout<<"{"<<temp->key<<","<<temp->value<<"} -> ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    ~HashTable() {
    for (int i = 0; i < totalsize; i++) {
        Node* temp = table[i];

        while (temp != nullptr) {
            Node* nextnode = temp->next;
            delete temp;
            temp = nextnode;
        }
    }

    delete[] table;
}

};

int main(){
    HashTable ht;
    ht.insert("Arun",100);
    ht.insert("Patrick",65);
    ht.insert("Red Jone",10);
    ht.insert("Jhon",190);
    ht.insert("Bond",9000);
    ht.insert("James",110);
    ht.insert("Bhem",12);
    ht.insert("Eagel",123);
    ht.insert("Kabooter",8765);

    // ht.print();

    cout<<ht.remove("Jhon");
    ht.print();

}