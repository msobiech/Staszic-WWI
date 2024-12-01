#include <iostream>
#include <vector>
using namespace std;



constexpr int MAXN = 1e4+1;
int dp[MAXN][MAXN];

int main(){
    string in;
    int n;
    cin >> n;
    cin >> in;
    for(int i = 2;i<=n;i++){
        for(int j = 0;j+i-1<n;j++){
            dp[i][j] = min(dp[i-1][j]+1,dp[i-1][j+1]+1);
            if(in[j]==in[j+i-1]){
                dp[i][j] = min(dp[i][j],dp[i-2][j+1]);
            }
        }
    }
    cout << dp[n][0] << endl;
    pair<int,int> cur;
    cur = {n,0};
    //1 - do gory 2-gornyprawy 3- przepisanie z gory 2 do gory
    vector<int> instrukcje;
    while(cur.first>1){
        if(dp[cur.first][cur.second]==dp[cur.first-2][cur.second+1]){
            instrukcje.push_back(3);
            cur.first -=2;
            cur.second+=1;
        }
        else if(dp[cur.first-1][cur.second]<dp[cur.first-1][cur.second+1]){
            instrukcje.push_back(1);
            cur.first -=1;
        }
        else{
            instrukcje.push_back(2);
            cur.first -=1;
            cur.second+=1;
        }
    }
    string ans; ans += in[cur.second];
    for(auto g:instrukcje){
        if(g==3){
            ans+=in[cur.second-1];
            cur.second-=1;
            cur.first+=2;
        }
        else if(g==1){
            cur.first+=1;
        }
        else{
            cur.first+=1;
            cur.second-=1;
        }


    }
    for(int i = ans.size()-1;i>=0;i--){
        cout << ans[i];
    }
    for(int i = 1;i<ans.size();i++){
        cout << ans[i];
    }
}