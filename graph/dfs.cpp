#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void getDfs(vector<int>adj[], int start, bool visited[]){
    visited[start] = true;
    cout<<start<<" ";
    for(auto i : adj[start]){
        if(visited[i] == false){
            getDfs(adj,i,visited);
        }
    }
}
void bigDfs(vector<int>adj[], int v){
    bool visited[v+1];
    memset(visited,false,v+1);
    for(int i = 0;i<v;i++){
        if(visited[i]!=true){
            getDfs(adj,i,visited);
        }
    }

}

void addedge(vector<int>adj[], int u, int v){
    //adj[v].push_back(u);
    adj[u].push_back(v);
}

void printgraph(vector<int>adj[], int v){
    for(int i = 0;i<v;i++){
        cout<<"["<<i<<"]-->";
        for(auto j: adj[i]){
            cout<<j<<"-->";
        }
        cout<<"NULL"<<endl;
    }
}

int main(){
    vector<int> adj[6];
    addedge(adj,0,2);
    addedge(adj,0,3);
    addedge(adj,0,4);
    addedge(adj,1,2);
    addedge(adj,1,4);
    addedge(adj,2,5);
    printgraph(adj,6);
    cout<<"-------"<<endl;
    bigDfs(adj,6);

}
