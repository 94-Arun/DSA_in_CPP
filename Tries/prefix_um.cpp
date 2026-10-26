#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Node{
public:    
    unordered_map<char,Node*> child;
    bool endofword;
    int freq;

    Node(){
        endofword = false;
    }    
};

class Tries{
    Node* root;
public:
    Tries(){
        root = new Node();
        root->freq = -1;
    }

    // insertion in tries
    void insert(string key){
        Node* temp = root;

        for(int i  = 0;i<key.size();i++){
            if(temp->child.count(key[i]) == 0){ // add the char if dosent exist
                temp->child[(key[i])] = new Node(); // new node inserted
                temp->child[(key[i])]->freq = 1;
            }else{
                temp->child[(key[i])]->freq++;
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

    string getprefix(string s){
        int n = s.size();
        Node* temp = root;
        string ans = "";

        for(int i = 0;i<n;i++){
            ans += s[i];
            if(temp->child[s[i]]->freq == 1){
                break;
            }
            temp = temp->child[s[i]];
        }
        return ans;
    }

};

void Prefix(vector<string> & dict){
    Tries trie;

    for(auto &t : dict){
        trie.insert(t);
    }

    for(int i = 0;i<dict.size();i++){
        cout<<trie.getprefix(dict[i])<<endl;
    }

}


int main(){
    vector<string> words = {"zebra","dog","duck","dove"};
    Prefix(words);
}
