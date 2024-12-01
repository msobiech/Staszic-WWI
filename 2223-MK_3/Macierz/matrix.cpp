#include <iostream>
using namespace std;
long long dp[200004][3];
int main(){
    int n;
    cin >> n;
    int pop1, pop2,pop3;
    cin >> dp[0][0];
    pop1 = dp[0][0];
    cin >> dp[0][1];
    pop2 = dp[0][1];
    cin >> dp[0][2];
    pop3 = dp[0][2];
    for(int i = 1;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a;
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b;
        dp[i][2]=max(dp[i-1][1],dp[i-1][0])+c;
    }
    cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));

}