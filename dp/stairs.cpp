//This problem is to give details about the climbing stairs . We only have two choices.
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int noofwaystoclimb(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int calval(int n, vector<int>steps){
    if(n == 0 || n == 1){
        return 1;
    }
    int total = 0;
    for(int i = 0;i<steps.size();i++){
        if(n - steps[i]>=0){
            total+= calval(n-steps[i], steps);
        }
    }
    return total;
}
int calvaldp(int n, vector<int>stairs){
    if(n == 0){
        return 1;
    }
    int dp[n+1];
    dp[0] = 1;
    for(int i = 1;i<=n;i++){
        int total = 0;
        for(int j = 0;j<stairs.size();j++){
            if(i - stairs[j]>=0){
                total += dp[i - stairs[j]];
            }
        }
        dp[i] = total;
    }
    return dp[n];
}
int main(){
    int number;
    cout<<"Enter the number of stairs"<<endl;
    cin>>number;
    vector<int>stairs;
    stairs.push_back(1);
    stairs.push_back(2);
    cout<<calvaldp(number,stairs);
}
