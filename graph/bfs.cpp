#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void bfs(vector<int>adj[],bool visited[],int start){
    queue<int>q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int val = q.front();
        cout<<val<<" ";
        q.pop();
        for(auto i : adj[val]){
            if(visited[i]!= true){
            q.push(i);
            visited[i] = true;
          }
        }

    }
}

void ncbfs(vector<int>adj[], int v){
    bool visited[v+1];
    memset(visited,false,v+1);
    for(int i = 0;i<v;i++){
        if(visited[i]==false){
            bfs(adj,visited,i);
        }
    }


}

void addedge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
}

void displaygraph(vector<int>adj[], int v){
    for(int i = 0;i<v;i++){
        cout<<"["<<i<<"]-->";
        for(auto j : adj[i]){
            cout<<j<<"-->";
        }
        cout<<"Null"<<endl;
    }
}

int main(){
    vector<int>adj[6];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,0,3);
    addedge(adj,1,2);
    addedge(adj,1,5);
    addedge(adj,2,3);
    addedge(adj,2,1);
    addedge(adj,4,5);
    addedge(adj,5,3);
    addedge(adj,5,2);
    displaygraph(adj,6);
    cout<<"---------"<<endl;
    ncbfs(adj,6);
}
