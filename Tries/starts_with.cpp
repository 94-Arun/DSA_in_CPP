#include<iostream>
#include<vector>
#include<map>
#include<string>
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
    
    // Insertion
    void insert(string key){
        Node* temp = root;
        for(int i = 0;i<key.size();i++){
            if(temp->child.count(key[i]) == 0){
                temp->child[key[i]] = new Node();
            }
            temp = temp->child[key[i]];
        }
        temp->endofword = true;
    }

    // searching
    bool search(string key){
        Node* temp = root;
        for(int i = 0;i<key.size();i++){
            if(temp->child.count(key[i]) == 0){
                return false;
            }
            temp = temp->child[key[i]];
        }
        return temp->endofword;
    }

    // find prefix / starts with problem
    bool prefixSearch(string key){
        Node* temp = root;
        for(int i = 0;i<key.size();i++){
            if(temp->child.count(key[i]) == 0){
                return false;
            }
            temp = temp->child[key[i]];
        }
        return true;
    }
};


int main(){
    vector<string> words = {"apple","app","mango","man","woman"};
    Tries trie;
    string pre = "appm";

    for(auto& w : words){
        trie.insert(w);
    }

    cout<<trie.prefixSearch(pre);

}