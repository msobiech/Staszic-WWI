#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

struct edge{
    int a;
    int id;
};

int n,m;
int id = 1;
constexpr int MAXN = 1e5+5;
constexpr int MAXM = 2e5+5;
bool b1[MAXN];
bool odw[MAXM];
vector<edge> G[MAXN];
vector<int> cycle;
int start[MAXN];

void euler_cycle(int v){
    int siz = G[v].size();
    int star = start[v];
    for(int i = star;i<siz;i++){
        edge u = G[v][i];
        if(!odw[u.id]){
            odw[u.id]=true;
            euler_cycle(u.a);
        }
        start[v]++;
    }
    cycle.push_back(v);
}

int main(){
    int n,m;
    cin >> n >> m;
    int pocz = 1;
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        if(i==0){
            pocz = a;
        }
        b1[a] = !b1[a];
        b1[b] = !b1[b];
        G[a].push_back({b,id});
        G[b].push_back({a,id});
        id++;
    }

    for(int i = 1;i<=n;i++){
        if(b1[i]){
            cout << "NIE\n";
            return 0;
        }
    }
        euler_cycle(pocz);
        cycle.pop_back();
        if(cycle.size()==m){
            cout << "TAK\n";
            for(int i = cycle.size()-1;i>=0;i--){
                cout << cycle[i] << " ";
            }
        }
        else{
            cout << "NIE\n";
        }
}