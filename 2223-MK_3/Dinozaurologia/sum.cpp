#include <iostream>
using namespace std;
constexpr int MAXN = 1e3+3;
int sum2d[MAXN][MAXN];
int main(){
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            int x;
            cin >> x;
            sum2d[i][j] = sum2d[i-1][j]+sum2d[i][j-1]-sum2d[i-1][j-1]+x;
        }
    }
    int q;
    cin >> q;
    for(int i = 0;i<q;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << sum2d[c][d]+sum2d[a-1][b-1]-sum2d[a-1][d]-sum2d[c][b-1] << endl;
    }
}