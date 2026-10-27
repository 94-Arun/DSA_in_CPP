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

    int countHelper(Node* root){
        int ans = 0;

        for(pair<char,Node*> p : root->child){
            ans += countHelper(p.second);
        }
        return ans+1;
    }

    // count trie nodes
    int countNodes(){
        return countHelper(root); // beacues countNodes dosent ahve access to node 
    }

};


int uniquesbstr(string s){
    Tries trie;
    for(int i = 0;i<s.size();i++){
        string suffix = s.substr(i);
        trie.insert(suffix);
    }
    return trie.countNodes();
}


int main(){
    Tries trie;
    string s = "ababa";
    
    cout<<uniquesbstr(s);

}