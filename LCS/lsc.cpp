#include<iostream>
#include<bits/stdc++.h>
use namespace std;

int findLCS(string a, string b, int alength, int blength,vector<vector<int>&dp){
        for(int i = 0;i<=blength;i++){
            dp[0][i] = 0;
        }
        for(int i = 0;i<=alength;i++){
            dp[i][0] = 0;
        }
        for(int i = 0;i<=alength;i++){
            for(int j = 0;j<=blength;j++){
                if(a[alength - i] == b[blength - j]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[alength][blength];
}
int main(){
    string a, b;
    cin>>a>>b;
    vector<vector<int>>dp(a.size()+1, vector<int>(b.size()+1, -1));
    cout<<findLCS(a,b,alength,blength,

}
