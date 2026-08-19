#include<iostream>
using namespace std;
#include<vector>

class Node{
public:    
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insert(Node* root, int val){
    // Node* newnode = new Node(val);
    if(root == NULL){
        return new Node(val);
    }
    if(root->data > val){
        root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }
    return root;
}

void buildBST(Node* root,vector<int>& v){
    for(int i = 1; i<v.size();i++){
        insert(root,v[i]);
    }
}



void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    vector<int> arr = {8,5,3,1,4,6,10,11,14};
    Node* root = new Node(arr[0]);
    buildBST(root,arr);
    inorder(root);

} 


