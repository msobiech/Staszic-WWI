#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 1e3+2;
long long magic[MAXN][MAXN];
long long plansza[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n,m,u;
    cin >> n >> m;
    for(int i = 1;i<n;i++){
        magic[0][i] = -999999;
    }
    for(int i = 1;i<m;i++){
        magic[i][0] = -999999;
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> u;
            plansza[i][j] = u;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(i==1 && j==1){
                magic[i][j] = plansza[1][1];
            }
            else{
                magic[i][j] = max(magic[i][j-1] + plansza[i][j],magic[i-1][j] + plansza[i][j]);
            }
        }
    }
    if(magic[n][m]>=0){
        cout << magic[n][m];
    }
    else{
        cout << 0;
    }
}