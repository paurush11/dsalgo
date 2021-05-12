///ajd matrix is given and we have to find path bw 2 vertices

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void addedge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
}
void printgraph(vector<int>adj[], int V){
    for(int i = 0;i<V;i++){
    cout<<"["<<i<<"]-->";
        for(auto j: adj[i]){
            cout<<j<<"-->";
        }
        cout<<"NULL"<<endl;
    }
}
///-------------------------///
bool findpath(int source, int destination, vector<int>adj[], vector<bool>&visited){
    if(source == destination){
        return true;
    }
    visited[source] = true;
    for(auto j : adj[source]){
        if(!visited[j] && findpath(j,destination,adj,visited)){
            return true;
        }
    }
    return false;
}

///------------------------///
int findtotalpath(int source, int destination, vector<int>adj[], vector<bool>&visited){
    if(source == destination){
        return 1;
    }
    visited[source] = true;
    int val = 0;
    for(auto i: adj[source]){
        if(!visited[i]){
            val+= findtotalpath(i,destination,adj,visited);
        }
    }
    return val;
}
///-------------------------///
void storepaths(int source, int destination,vector<int>adj[], vector<bool>&visited, vector<int>temp_paths, vector<vector<int>>&paths)
{
    if(source == destination){
        temp_paths.push_back(source);
        paths.push_back(temp_paths);
        return ;
    }
    visited[source] = true;
    temp_paths.push_back(source);
    int val = 0;
    for(auto i: adj[source]){
        if(!visited[i]){
           findtotalpath(i,destination,adj,visited,temp_paths,paths);
        }
    }

}
int main(){
    int V = 5;
    vector<int>adj[5];
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int x,y;
        cin>>x>>y;
        addedge(adj,x,y);
    }
    printgraph(adj,V);
    vector<bool>visited(V, false);
    cout<<"choose path"<<endl;
    int x ,y;
    cin>>x>>y;
    cout<<"Total Paths  -- "<<findtotalpath(x,y,adj,visited)<<endl;
    fill(visited.begin(), visited.end(), false);
    if(!findpath(x,y,adj,visited)){
        cout<<"False"<<endl;
    }else{
        cout<<"True"<<endl;
    }



}
