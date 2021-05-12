#include<iostream>
#include<bits/stdc++.h>

using namespace std;
///In a directed Graph

void addedge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
}
void displayGraph(vector<int>adj[], int V){
     for(int i = 0;i<V;i++){
        cout<<"["<<i<<"]--->";
        for(auto j : adj[i]){
            cout<<j<<"-->";
        }
        cout<<"Null"<<endl;
    }
}

vector<int> topological_sort(vector<int>adj[], int V){
    vector<int>result;
    vector<int>indeg(V);
    for(int i = 0;i<V;i++){
        for(auto j : adj[i]){
            indeg[j]++;
        }
    }
    queue<int>q;
    for(int i = 0;i<V;i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        result.push_back(x);
        q.pop();
        for(auto i : adj[x]){
            indeg[i]--;
            if(indeg[i] == 0){
                q.push(i);
            }
        }
    }

    return result;
}

int main(){
    vector<int>adj[5];
    addedge(adj,0,1);
    addedge(adj,0,2);
    addedge(adj,1,2);
    addedge(adj,3,2);
    addedge(adj,3,4);
    addedge(adj,4,2);
    displayGraph(adj,5);
    cout<<"----------------"<<endl;
    vector<int>v = topological_sort(adj,5);
    for(auto i:v){
        cout<<i<<"  ";
    }
}
