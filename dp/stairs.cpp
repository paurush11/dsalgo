//This problem is to give details about the climbing stairs . We only have two choices.

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
        dp[i] = dp[i+1] + dp[i-1];
    }
    return dp[n];
}
int calval(int n){
    if(n == 0){
        return 1;
    }
    int total = 0;
    for(int i = 1;i<=2;i++){
        if(n-i>=0)
        total += calval(n-i);
    }
    return total;
}
int calvaldp(int n){
    if(n == 0){
        return 1;
    }
    int dp[n+1];
    dp[0] = 1;
    for(int i = 1;i<=n;i++){
        int total = 0;
        for(int j =1;j<=2;j++){
            if(i-j>=0){
                total+=dp[i-j];
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
    cout<<calvaldp(number)<<endl;
}
