#include<iostream>
#include<vector>
#include<queue>
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



// Level Order Traversal
void kthLevel(Node* root,int k){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int c = 0;

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr==NULL){
            c++;
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }
        else{
            if(c==k){
                cout<<curr->val<<" ";
            }
            
            if(curr->left != nullptr) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
    }
        }

}


// main
int main(){
vector<int> node = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
Node* root = buildTree(node);
// cout<<"Root Node : "<<root->val<<endl;

kthLevel(root,2);


    return 0;
}
