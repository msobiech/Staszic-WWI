#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
double dp[2002][2002];

inline double liczdp(int i, int dl){
    int left = dl-1;
    int right = 1;
    double maxi = 0;
    while(left>0){
        double temp = (dp[i][left]+dp[i+left][right])/2;
        maxi = max(temp,maxi);
        left--;
        right++;
    }
    return maxi;
}

inline bool isInt(char c){
    if(c>='0' && c<='9')return true;
    return false;
}

inline int readInt(){
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
    int n;
    n = readInt();
    for(int i = 0;i<n;i++){
        dp[i][1] = readInt();
    }
    for(int i = 2;i<=n;i++){
        for(int j = 0;j<n;j++){
            dp[j][i] = liczdp(j,i);
            //cout << dp[j][i] << " ";
        }
        //cout << endl;
    }
    printf("%.7lf\n", dp[0][n]);
    //cout << fixed << setprecision(7) << dp[0][n] << '\n';


}