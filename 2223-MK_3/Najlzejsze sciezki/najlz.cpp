#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct kraw {
    int a, b, waga;
};
constexpr int MAXN = 1e3+4;
int n, m, v;
vector<kraw> edges;
int odl[MAXN];
int ojc[MAXN];
constexpr int INF = 1e9;

void solve(int v, int t){
    for(int i = 0;i<MAXN;i++){
        odl[i] = INF;
        ojc[i] = -1;
    }
    vector<int> path;
    odl[v] = 0;
    while(true){
        bool c = false;
        for (auto e : edges)
            if (odl[e.a]<INF)
                if (odl[e.b]>odl[e.a]+e.waga){
                    odl[e.b] = odl[e.a]+e.waga;
                    ojc[e.b] = e.a;
                    c = true;
                }
        if (!c){
            break;
        }
    }
    if (odl[t] == INF){
        cout << "NIE\n";
    }
    else{
        for(int cur = t; cur != -1; cur = ojc[cur]){
            path.push_back(cur);
        }
        cout << odl[t] << " ";
        cout << path.size() << " ";
        for (int i = path.size()-1;i>=0;i--){
            cout << path[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> m >> q;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        kraw x = {a,b,c};
        edges.push_back(x);
    }
    for(int i = 0;i<q;i++){
        int a,b;
        cin >> a >> b;
        solve(a,b);

    }
}