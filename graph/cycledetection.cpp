#include<iostream>
#include<bits/stdc++.h>

using namespace std;
bool dfsdgraph(vector<int>adj[], int start, bool visited[],bool seen[]){
    visited[start] = true;
    seen[start] = true;
    for(auto i: adj[start]){
        if(!visited[i]){
                if(dfsdgraph(adj,i,visited,seen)){
            return true;
                }
        }else if(seen[i]){
            return true;
        }
    }
    seen[start] = false;
    return false;

}
bool detectcycledgraph(vector<int>adj[], int V){
    bool visited[V+1];
    bool seen[V+1];
    memset(visited, false, V+1);
    memset(seen, false, V+1);
    for(int i = 0;i<V;i++){
        if(!visited[i] && dfsdgraph(adj,i,visited,seen))return true;
        }

    return false;

}

bool dfsidgraph(vector<int>adj[], int start, bool visited[], int parent){
    visited[start] = true;
    for(auto i: adj[start]){
        if(!visited[i] && dfsidgraph(adj,i,visited,start)){
            return true;
        }else if( i!=parent || i == start){
            return true;
        }
    }
    return false;

}

bool detectcycleidgraph(vector<int>adj[], int V){
    bool visited[V+1];
    memset(visited, false, V+1);
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            if(dfsidgraph(adj,0,visited,-1))return true;
        }
    }
    return false;

}
void addedged(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
}
void addedgeid(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
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

int main(){
    ///2 types of graph
    ///1 -- Directed
    ///2 -- Indirected
    vector<int>adjd[6];
    vector<int>adjid[6];
    addedged(adjd,0,1);
    addedged(adjd,0,2);
    addedged(adjd,2,5);
    addedged(adjd,1,5);
    addedged(adjd,1,4);
    addedged(adjd,2,4);
    addedged(adjd,4,5);
    displayGraph(adjd,6);
   // addedged(adjd,4,0);

    cout<<"cycle ==== ";
    cout<<detectcycledgraph(adjd,6)<<endl;
    addedgeid(adjid,0,1);
    addedgeid(adjid,0,2);
    addedgeid(adjid,1,3);
    addedgeid(adjid,1,4);
    addedgeid(adjid,2,4);
    addedgeid(adjid,4,5);

    cout<<"------------------"<<endl;
    displayGraph(adjid,6);

    cout<<"cycle ==== ";
    cout<<detectcycleidgraph(adjid,6);

}
