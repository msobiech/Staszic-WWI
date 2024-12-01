#include <iostream>
#include <cstdio>
using namespace std;
constexpr int MAXN = 2e3+3;
int sum1[MAXN];
int sum2[MAXN];
int dp[MAXN][MAXN];
bool isInt(char c){
    if(c>='0' && c<='9')return true;
    return false;
}

int readInt(){
    char c;
    int x = 0;
    int mult = 1;
    while(!isInt(c = getchar_unlocked()) && c!='-'){
    }
    do{
        if(c=='-'){
            mult=-1;
        }
        else{
            x=x*10+int(c-'0');
        }

    }while(isInt(c = getchar_unlocked()) || c=='-');
    return x*mult;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    n = readInt();
    m = readInt();
    for(int i = 1;i<=n;i++){
        int x;
        x = readInt();
        sum1[i] = sum1[i-1]+x;
    }
    for(int i = 1;i<=m;i++){
        int x;
        x = readInt();
        sum2[i] = sum2[i-1]+x;
    }
    for(int i = 1;i<=n;i++){
        dp[i][0] = sum1[i]-dp[i-1][0];
    }
    for(int i = 1;i<=m;i++){
        dp[0][i] = sum2[i]-dp[0][i-1];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            dp[i][j] = max(sum1[i]+sum2[j]-dp[i-1][j],sum1[i]+sum2[j]-dp[i][j-1]);
        }
    }
    cout << dp[n][m];

}