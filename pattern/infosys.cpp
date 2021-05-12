#include<iostream>
#include<bits/stdc++.h>
#define f(i,a,b) for(int i = a;i<b;i++)

using namespace std;

int getres(vector<int>q){
    int n = q.size();
    priority_queue<int>heap;
    f(i,0,n){
        heap.push(q[i]);
    }
    int sam = 0;
    bool check = false;
    while(!heap.empty()){
        int val = heap.top();
        heap.pop();
        if(!check){
            sam+=val;
        }
        check = !check;
        if(val!=1){
            val/=2;
            heap.push(val);
        }
    }
    return sam;
}

int main(){
    int n;
    cin>>n;
    vector<int>value;
    f(i,0,n){
        int x;
        cin>>x;
        value.push_back(x);
    }
    cout<<getres(value)<<endl;
}
