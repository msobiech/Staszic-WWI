#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

const int MAXN = 1000003;

vector<int> G[MAXN];
int st[MAXN];
int ways[MAXN];
int mod = 1e9 + 9;
void toposort(int n){
    set<int> Q;
    vector<int> sorted;
    for(int i = 1; i <= n; i++){
        if(st[i] == 0){
            Q.insert(i);
        }
    }
    while(!Q.empty()){
        int v = *Q.begin();
        sorted.push_back(v);
        Q.erase(Q.begin());
        for(auto s: G[v]){
            st[s]--;
            ways[s]+=ways[v];
            ways[s] %= mod;
            if(st[s] == 0){

                Q.insert(s);
            }
        }
    }
    //return sorted;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, start, goal;
    cin >> n >> m >> start >> goal;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        st[b]++;
    }
    ways[start] = 1;
    toposort(n);
    cout << ways[goal];
}