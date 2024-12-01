#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <iomanip>
using namespace std;

constexpr int MAXN = 3e5+7;

constexpr int inf = INT_MAX;

double dp[MAXN];

struct cmp {
  bool operator () (const int& x,const int& y) const {
    if (dp[x] != dp[y]) return dp[x] < dp[y];
    return x < y;
  }
};


vector<int> G[MAXN];
set<int, cmp> S;
bool vis[MAXN];
int count[MAXN];
double sum[MAXN];

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1;i<n;i++){
        dp[i] = inf;
    }
    dp[n]=0;
    S.insert(n);
    while(!S.empty()){
        int u = *S.begin();
        S.erase(S.begin());
        vis[u] = true;
        for (int g: G[u]) {
            if (!vis[g]) {
                S.erase(g);
                count[g]++;
                sum[g] += dp[u];
                dp[g] = (sum[g] + G[g].size()) / count[g];
                S.insert(g);
            }
        }
    }
    cout << setprecision(10) << fixed << dp[1];


}