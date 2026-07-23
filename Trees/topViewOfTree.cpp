#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

// node structure
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

static int idx = -1;

Node* buildTree(vector<int> node){
    idx++;

    if(node[idx] == -1) return nullptr;

    Node* currnode = new Node(node[idx]);
    currnode->left = buildTree(node);
    currnode->right = buildTree(node);

    return currnode;
}

void topView(Node* root){
    map<int,int> m; 
    if(root==NULL) {cout<<"0";return; };

    queue<pair<Node*,int>> Q;
    Q.push(make_pair(root,0));

    while(!Q.empty()){
        pair<Node*,int> curr = Q.front();
        Q.pop();

        if(m.find(curr.second) == m.end()){
            m[curr.second] = curr.first->val;
        }    
        if(curr.first->left != NULL) Q.push(make_pair(curr.first->left, curr.second - 1));
        if(curr.first->right != NULL) Q.push(make_pair(curr.first->right, curr.second + 1));
        
    }
    for(auto it:m){
        cout<<it.second<<" ";
    }
}



// main
int main(){
    vector<int> node = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = buildTree(node);

    topView(root);
    cout<<endl;
    return 0;
}
