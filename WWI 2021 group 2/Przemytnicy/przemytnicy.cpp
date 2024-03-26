#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1000000 + 7;
const int INF = 1000000000 + 7;
vector<pair<int, int>> G[MAXN];
int odl[MAXN];
bool odw[MAXN];
int n,m;

void Dijkstra(int start)
{
    for(int i = 1; i <= n; i++)
    {
        odl[i] = INF;
        odw[i] = false;
    }
    // .first -> odleglosc, .second -> v
    priority_queue<pair<int, int>> kol;
    kol.push({0, start});
    odl[start] = 0;
    while(!kol.empty())
    {
        pair<int, int> tmp = kol.top();
        int v = tmp.second;
        kol.pop();
        if(odw[v])
            continue;
        odw[v] = true;
        for(int i = 0; i < G[v].size(); i++)
        {
            pair<int, int> kraw = G[v][i];
            int u = kraw.first;
            int waga = kraw.second;
            if(odl[u] > odl[v] + waga)
            {
                odl[u] = odl[v] + waga;
                kol.push({-1*odl[u], u});
            }
        }
    }
}



int main() {
    cin >> n;

    int x;
    for(int i = 1; i <= n; i++){
        cin >> x;
        G[i].push_back({i+n, x/2});
    }
    cin >> m;
    int a,b,c;
    for(int i = 1; i <= m; i++){
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[a+n].push_back({b+n, c});
    }
    n*=2;
    Dijkstra(1);
    /*
    for(int i =0;i<=2*n;i++){
        cout << odl[i] << " ";
    }*/
    cout << odl[(n/2)+1];
}