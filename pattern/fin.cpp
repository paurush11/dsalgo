#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>> n;
    if(n == 0)cout<<"0"<<endl;
    if(n == 1)cout<<"1"<<endl;
    int a = 0;
    int b = 1;
    int c = 0;
    for(int i = 2;i<=n;i++){
        c = a+b;
        a = b;
        b = c;
    }
    cout<<c<<endl;


}
