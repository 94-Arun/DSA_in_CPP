#include<iostream>
using namespace std;
#include<vector>

struct Node{
    int val;
    Node *left,*right;

    Node(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    // Node(int x) : val(x),left(nullptr),right(nullptr){}
};

// Get Inorder for BST
void getInorder(Node* root, vector<int>& v){
    if(root == NULL) return;

    getInorder(root->left,v);
    v.push_back(root->val);
    getInorder(root->right,v);
}
// printing the nodes in Inorder
void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

// Merge Two Sorted Arrays
void mergeSortedArrays(vector<int> a1,vector<int> a2,vector<int>& ans){

    int i = 0,j=0;

    // if any or the array is empty
    // edge cases
    if(a1.empty()){
        while(j<a2.size()){
            ans.push_back(a2[j++]);
        }
    }
    if(a2.empty()){
        while(i<a1.size()){
            ans.push_back(a1[i++]);
        }
    }

    
    while(i<a1.size() && j<a2.size()){
        if(a1[i] < a2[j]){
            ans.push_back(a1[i++]);
        }else{
            ans.push_back(a2[j++]);
        }
    }

    // if a1 is larger in size
    while(i<a1.size()){
        ans.push_back(a1[i++]);
    }
    // is a2 is larger in size
    while(j<a2.size()){
        ans.push_back(a2[j++]);
    }
}

Node* buildBSTfromSortedArrays(vector<int> merged,int start,int end){
    if(start > end) return NULL;
    
    int mid = start + (end-start)/2;

    Node* curr = new Node(merged[mid]);
    curr->left = buildBSTfromSortedArrays(merged,start,mid-1);
    curr->right = buildBSTfromSortedArrays(merged,mid+1,end);

    return curr;
}

Node* mergeTwoBST(Node* root1,Node* root2){
    vector<int> a1;
    vector<int> a2;
    vector<int> merged;

    // Get Inorder for Both trees
    getInorder(root1,a1);
    getInorder(root2,a2);

    // merge them in single vector/array
    mergeSortedArrays(a1,a2,merged);

    // building tree from single sorted vector/array
    return buildBSTfromSortedArrays(merged,0,merged.size()-1);
}

int main(){
    // BST 1
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);

    // BST 2
    Node* root2 = new Node(5);
    root2->left = new Node(4);
    root2->right = new Node(6);

    Node* final = mergeTwoBST(root1,root2);

    inorder(final);
}