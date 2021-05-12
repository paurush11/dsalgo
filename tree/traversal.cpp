#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void printvector(vector<int>v){
    for(auto i:v){
        cout<<i<<" ";
    }
}


class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(){
    this->data = -1;
    this->left = this->right = NULL;
    }

    Node(int val){
    this->data = val;
    this->left = this->right = NULL;
    }
};


Node* insertlevelorder(Node* root, vector<int>v, int index){
    if(index<v.size()){
        if(v[index] == -1){
            return NULL;
        }
        Node* newnode = new Node(v[index]);
        root = newnode;
        root->left = insertlevelorder(root->left, v, 2*index+1);
        root->right = insertlevelorder(root->right, v, 2*index+2);
        return root;
    }
    return NULL;

}
///DFS TRAVERSAL
void preorder(Node* root, vector<int>&v){
    if(root){
        v.push_back(root->data);
        preorder(root->left,v);
        preorder(root->right,v);
    }

}
void inorder(Node* root, vector<int>&v){
    if(root){
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }

}

void postorder(Node* root, vector<int>&v){
    if(root){
        postorder(root->left,v);
        postorder(root->right,v);
        v.push_back(root->data);
    }

}
///BFS TRAVERSAL
void levelordertraversal(Node* root, vector<int>&v){
    if(!root)return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        v.push_back(temp->data);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

void reverselevelordertraversal(Node* root, vector<int>&v){
    if(!root)return;
    stack<int>st;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        st.push(temp->data);

        if(temp->right){
            q.push(temp->right);
        }
        if(temp->left){
            q.push(temp->left);
        }
    }

    while(!st.empty()){
        int val = st.top();
        st.pop();
        v.push_back(val);
    }
}


///Recursive sol -- spiral order

int height(Node* root){
    if(!root)return 0;
    return max(height(root->left), height(root->right))+1;
}

void printgivenlevel(Node* root, int level, vector<int>&v){
    if(!root)return;
    if(level == 0){
        v.push_back(root->data);
        return;
    }
    printgivenlevel(root->left, level-1, v);
    printgivenlevel(root->right, level-1, v);
}

void spirallevelorder(Node* root, vector<int>&v){
    if(!root)return;
    int h = height(root);
    for(int i = 0;i<h;i++){
        vector<int>temp;
        printgivenlevel(root, i, temp);
        if(i&1){
            reverse(temp.begin(), temp.end());
        }
        for(auto j : temp){
            v.push_back(j);
        }
    }
}


int main(){
    Node* root = new Node();
    vector<int>v;
    int arr[] = {1,2,3,4,5,6,7,8,9,-1,-1,-1,-1,10,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i<n;i++){
        v.push_back(arr[i]);
    }
    root = insertlevelorder(root,v,0);
    vector<int>levelorder;
    spirallevelorder(root, levelorder);
    printvector(levelorder);
}
