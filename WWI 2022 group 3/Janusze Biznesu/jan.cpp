#include <iostream>
using namespace std;
struct edge{
    int sr;
    int dst;
    int wg;
};
edge G[4007];
int dist[2007];
int inf = 2147483647;
int v,e;


bool isNeg(int src){
    //for(int i = 0;i<=v;i++){
    //    dist[i]=inf;
    //}
    dist[src] = 0;
    for (int i = 1; i<=v-1; i++){
        for (int j = 0; j<e; j++){
            int u = G[j].sr;
            int v = G[j].dst;
            int weight = G[j].wg;
            if (dist[u] != inf && dist[u]+weight<dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i = 0; i < e; i++) {
        int u = G[i].sr;
        int v = G[i].dst;
        int weight = G[i].wg;
        if (dist[u] != inf && dist[u]+weight<dist[v])
            return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> v >> e;
    for(int i = 0;i<e;i++){
        int sr,dst,wg;
        cin >> sr>>dst>>wg;
        wg*=-1;
        G[i].sr=sr;
        G[i].dst=dst;
        G[i].wg=wg;
    }
    for(int i = e;i<e*2;i++){
        int sr,dst,wg;
        sr=0;
        dst=i-e+1;
        wg=0;
        G[i].sr=sr;
        G[i].dst=dst;
        G[i].wg=wg;
    }
    if (isNeg(0)){
        cout << "TAK\n";
        return 0;
    }
    cout << "NIE\n";
    return 0;
}