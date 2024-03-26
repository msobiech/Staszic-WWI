#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>G[100001];
bool odw[100001];
int prz[100001][21];//prz[v][i] skok z v o 2^i w gore
int poz[100001];
bool odw2[100001];

void dfs(int w,int oj){
    if(odw2[w]){
        return;
    }
    prz[w][0]=oj;
    for(int i = 1;i<=20;i++){
        prz[w][i] = prz[prz[w][i-1]][i-1];
    }
    odw2[w] = true;
    for(int i = 0;i<G[w].size();i++){
        dfs(G[w][i],w);
    }
}

void bfs(int start){
    queue <int> Q;
    Q.push(start);
    poz[start] = 0;
    odw[start] = true;
    while(!Q.empty()){
        int w = Q.front();
        //cout << w << " bfs " << poz[w] << endl;
        Q.pop();
        for(int sas: G[w]){
            //int sas = G[w][i];
            if(!odw[sas]){
                poz[sas] = poz[w] + 1;
                odw[sas] = true;
                Q.push(sas);

            }


        }
    }

}

int lca(int a,int b){
    if(poz[a]<poz[b]){
        swap(a,b);
    }
    //dopasowywanie poziomow
    for(int i = 20;i>=0;i--){
        if(poz[prz[a][i]]>=poz[b]){
            a = prz[a][i];
        }
    }
    if(a==b){
        return a;
    }
    for(int i = 20;i>=0;i--){
        if(prz[a][i]!=prz[b][i]){
            a = prz[a][i];
            b = prz[b][i];
        }
    }
    return prz[a][0];
}


int main() {
    int n;
    cin >> n;
    for(int i = 0;i<n-1;i++){
        //cout << i << endl;
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    //cout << "LCAAAAAA";
    bfs(1);
    dfs(1,1);
    /*
    for(int i = 0;i<=n;i++){
        cout << i << " ";
        for(int j = 0;j<=5;j++){
            cout << prz[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0;i<=n;i++){
        cout << poz[i] << " ";
    }
    cout << endl;*/

    int m;
    cin >> m;
    for(int i = 0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
       // cout << lca(a,b) << endl;
        int x = lca(a,b);
        if(lca(x, c) == x && (lca(c, a) == c || lca(c, b) == c)){
            cout << "TAK\n";
        }
        else{
            cout << "NIE\n";
        }
    }
    return 0;
}