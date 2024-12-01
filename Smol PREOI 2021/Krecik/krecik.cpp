#include <iostream>
#include <vector>
using namespace std;


const int MAXM = 1000004;
const int MAXN = 200004;
vector<int> G[MAXN];
vector<int> T[MAXN];
vector<int> S[MAXN];
bool vis[MAXN];
vector<int> post;
int scc[MAXN];
int licznik = 1;
int ilewspj[MAXN];
int dyn[MAXN];
int dzdz[MAXN];
int dzdzn[MAXN];

void DFS_post (int v){

    vis[v] = true;
    for(auto i: G[v]){
        if(!vis[i])
            DFS_post(i);
    }
    post.push_back(v);
}

void DFS_scc (int v){
    scc[v] = licznik;
    ilewspj[licznik]++;
    for(auto i: T[v]){
        if(vis[i] && !scc[i])
            DFS_scc(i);
    }
}
int bestofme(int x){
    if(dyn[x]==-1){
        int siz = S[x].size();
        int maks = 0;
        for(int i = 0;i<siz;i++){
            maks = max(bestofme(S[x][i]),maks);
        }
        dyn[x] = maks+dzdzn[x];
        return dyn[x];
    }
    else{
        return dyn[x];
    }
}


int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> dzdz[i];
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        T[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            DFS_post(i);
            while(!post.empty()){
                int tmp = post[post.size() - 1];
                post.pop_back();
                if(scc[tmp] == 0){
                    DFS_scc(tmp);
                    licznik++;
                }
            }

        }
    }
    licznik--;

    for(int i = 1;i<=n;i++){
        dzdzn[scc[i]] += dzdz[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<G[i].size();j++){
            if(scc[G[i][j]]!=scc[i]){
                S[scc[G[i][j]]].push_back(scc[i]);
            }
        }
    }
    for(int i = 1;i<=licznik;i++){
        dyn[i]=-1;
    }
    for(int i = 1;i<=licznik;i++){
        if(dyn[i]==-1){
            dyn[i] = bestofme(i);
        }
    }
    int odp = 0;
    for(int i = 1;i<=licznik;i++){
        if(dyn[i]>=odp){
            odp=dyn[i];
        }
    }
    cout << odp;

}