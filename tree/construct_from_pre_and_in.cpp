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
}
