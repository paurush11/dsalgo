#include<iostream>
#include<bits/stdc++.h>
#define f(i,a,b) for(int i = a;i<b;i++)
using namespace std;
void usdin(int n){
    int i = 1;
    while(i<n+1){
        char k = (char)('A' + n-i);
        int j = n-i;
        while(j<n){
            cout<<k<<"";
            k++;
            j++;
        }
        i++;
        cout<<endl;
    }
}
void nayadinpalin(int n){
    int i = 0;
    f(i,1,n){
        f(j,i,n-1){
            cout<<" ";
        }
        int k = i, k2 = i;
        f(j,n-i,n){
          cout<<k<<"";
          k++;
        }
        k2 = k-2;
        f(j,n-i,n-1){
            cout<<k2<<"";
            k2--;
        }
        cout<<endl;
    }

}

int main(){
    int n;
    cin>>n;
    cout<<"----"<<endl;
    f(i,1,n){
        f(j,i,n-1){
            cout<<" ";
        }
        int k = i, k2 = i;
        f(j,n-i,n){
          cout<<"*";
          k++;
        }
        k2 = k-2;
        f(j,n-i,n-1){
            cout<<"*";
            k2--;
        }
        cout<<endl;
    }
    f(i,1,n){
        f(j,0,i){
            cout<<" ";
        }
        int k = i, k2 = i;
        f(j,i,n-1){
          cout<<"*";
          k++;
        }
        k2 = k-2;
        f(j,i,n-2){
            cout<<"*";
            k2--;
        }
        cout<<endl;

    }

}
