#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 1000*1000 + 7;
const int INF = 1000*1000*1000 + 7; // wartosc, wieksza od kazdej mozliwej

// .first -> v, .second -> waga
vector<pair<int, int>> G[MAXN];
int odl[MAXN];
bool odw[MAXN];
int odl2[MAXN];
bool odw2[MAXN];
int n, m;

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

void Dijkstra2(int start)
{
    for(int i = 1; i <= n; i++)
    {
        odl2[i] = INF;
        odw2[i] = false;
    }
    // .first -> odleglosc, .second -> v
    priority_queue<pair<int, int>> kol;
    kol.push({0, start});
    odl2[start] = 0;
    while(!kol.empty())
    {
        pair<int, int> tmp = kol.top();
        int v = tmp.second;
        kol.pop();
        if(odw2[v])
            continue;
        odw2[v] = true;
        for(int i = 0; i < G[v].size(); i++)
        {
            pair<int, int> kraw = G[v][i];
            int u = kraw.first;
            int waga = kraw.second;
            if(odl2[u] > odl2[v] + waga)
            {
                odl2[u] = odl2[v] + waga;
                kol.push({-1*odl2[u], u});
            }
        }
    }
}
/*
void odzyskaj_sciezke(int v)
{
    if(odl[v] == INF)
    {
        return;
    }
    vector<int> sciezka;
    sciezka.push_back(v);
    while(poprz[v] != -1)
        {
        sciezka.push_back(poprz[v]);
        v = poprz[v];
        }
    for(int i = sciezka.size()-1; i >= 0; i--)
    {
        cout << sciezka[i] << '\n';
    }
    cout << '\n';
}
*/
int main()
{
    // n - liczba wierzcholkow, m - liczba krawedzi
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    Dijkstra(1);
    Dijkstra2(n);
    int odleglosc = odl[n];
    for(int i = 0;i<=n;i++){
        if(odl[i]+odl2[i]==odleglosc){
            cout << i << "\n";
        }
    }
    return 0;
}