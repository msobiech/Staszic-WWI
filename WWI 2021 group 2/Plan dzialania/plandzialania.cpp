#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

const int MAXN = 1e5+7;

vector<int> G[MAXN];
int st[MAXN];

vector<int> toposort(int n){
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
            if(st[s] == 0){
                Q.insert(s);
            }
        }
    }
    return sorted;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        st[b]++;
    }
    vector<int> odp = toposort(n);
    if(odp.size() != n){
        cout << "NIE\n";
        return 0;
    }
    cout << "TAK\n";
    for(int i: odp){
        cout << i << " ";
    }
    return 0;
}