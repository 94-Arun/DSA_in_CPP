#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Node{
public:    
    unordered_map<char,Node*> child;
    bool endofword;

    Node(){
        endofword = false;
    }    
};

class Tries{
    Node* root;
public:
    Tries(){
        root = new Node();
    }

    // insertion in tries
    void insert(string key){
        Node* temp = root;

        for(int i  = 0;i<key.size();i++){
            if(temp->child.count(key[i]) == 0){ // add the char if dosent exist
                temp->child[(key[i])] = new Node(); // new node inserted
            }
            temp = temp->child[key[i]];
        }
        temp->endofword = true;
    }

    // searching
    bool search(string key){ // O(L)
        Node* temp = root;
        for(int i = 0;i<key.size();i++){
            if(temp->child.count(key[i]) == 0){
                return false;
            }
            temp = temp->child[key[i]];    
        }
        return temp->endofword;
    }

};


int main(){
    vector<string> words = {"the","a","there","any","their","three"};
    Tries t;
    
    for(int i = 0;i<words.size();i++){
        t.insert(words[i]);
    }

    cout<<"Does key exists : "<<t.search("three")<<endl;
    cout<<"Does key exists : "<<t.search("thre")<<endl;
}