#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int p = n;
    int length = 0;
    int k = n;
    while(n>=10){
        n/=10;
        length++;
    }
    length++;
    int sum = 0;
    while(k>=10){
        int r = k%10, vl = length, nc = 1 ;
        //cout<<r<<" ";
        while(vl--){
            nc*=r;
        }
        k/=10;
        sum+=nc;
    }
    int r = k, vl = length, nc = 1;
    while(vl--){
            nc*=r;
    }
    sum+=nc;

    if(sum == p){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }



}
