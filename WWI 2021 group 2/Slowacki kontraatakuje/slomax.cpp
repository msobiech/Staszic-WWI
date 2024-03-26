#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//vector<int> G[500*1000+10];
int maxi[1000001][21];
int pozlca[1000001];
int prz[1000001][21];//prz[v][i] skok z v o 2^i w gore
int inf = 2147483647;
vector<pair<int,int>> G[1000001];
bool odw[1000001];

void dfs(int w,int oj, int odl){
    if(odw[w]){
        return;
    }
    maxi[w][0]= odl;//odleglosc od w do ojca;
    prz[w][0]=oj;
    pozlca[w] = pozlca[oj]+1;
    for(int i = 1;i<=20;i++){
        prz[w][i] = prz[prz[w][i-1]][i-1];
        maxi[w][i] = max(maxi[w][i-1],maxi[prz[w][i-1]][i-1]);//maxi[maxi[w][i-1]][i-1];
    }
    odw[w] = true;
    for(int i = 0;i<G[w].size();i++){

        dfs(G[w][i].first,w,G[w][i].second);

    }
}

int lca(int a,int b){
    //cout << "START " << a << " " << b << endl;

    if(pozlca[a]<pozlca[b]){
        swap(a,b);
    }
    int odp = -inf;
    //dopasowywanie poziomow
    for(int i = 20;i>=0;i--){
        if(pozlca[prz[a][i]]>=pozlca[b]){
            odp = max(maxi[a][i],odp);
            a = prz[a][i];
            //cout << a << " " << i << "\n";
        }
    }
    if(a==b){
        //return a;
        if(odp!=(-inf)){
            return odp;
        }
        else{
            return 0;
        }

    }
    for(int i = 20;i>=0;i--){
        if(prz[a][i]!=prz[b][i]){
            odp = max({odp,maxi[a][i],maxi[b][i]});
            a = prz[a][i];
            b = prz[b][i];
        }
    }
    odp = max({odp,maxi[a][0],maxi[b][0]});
    return odp;
    //return prz[a][0];
}
/*int lca(int a,int b){
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
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a,b,c;
    for(int i = 0;i<n-1;i++){
        cin >> a >> b >> c;
        pair<int,int> firs = {a,c};
        pair<int,int> seco = {b,c};
        G[a].push_back(seco);
        G[b].push_back(firs);
    }
    dfs(1,1,-inf);
    /*
    for(int i = 0;i<=n;i++){
        cout << pozlca[i] << " ";
    }
    cout << endl;
    cout << "PRZESKOKI\n";
    for(int i = 0;i<=n;i++){
        cout << i << " ";
        for(int j = 0;j<=5;j++){
            cout << prz[i][j] << " ";
        }
        cout << endl;
    }
    cout << "MAXY\n";
    for(int i = 0;i<=n;i++){
        cout << i << " ";
        for(int j = 0;j<=5;j++){
            cout << maxi[i][j] << " ";
        }
        cout << endl;
    }
*/
    int x,y;
    while(cin >> x){
        if(x!=-1){
            cin >> y;
            cout << lca(x,y) << endl;
            //cout << x << " " << y << endl;
        }
        else{
            return 0;
        }
    }
    return 0;
}