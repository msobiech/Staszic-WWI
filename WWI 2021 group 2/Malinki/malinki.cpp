#include <iostream>
#include <vector>
using namespace std;

vector <int> G[1000001];
int brac[1000001];
int niebrac[1000001];
int odp = 0;
void dfs(int pos, int father){
    //if(G[pos].size()==1){
    brac[pos] = 1;
    niebrac[pos] = 0;
    //brac[pos] = niebrac[father]+1;
    //niebrac[pos] = max(niebrac[father], brac[father]);
    //odp = max(odp, max(brac[pos],niebrac[pos]));

    for(int i = 0;i<G[pos].size();i++){
        if(G[pos][i]!=father){
            dfs(G[pos][i], pos);
            brac[pos] += niebrac[G[pos][i]];
            //cout << pos << " " << G[pos][i] << " " <<  brac[G[pos][i]] << " " << niebrac[G[pos][i]] << endl;
            niebrac[pos] += max(brac[G[pos][i]],niebrac[G[pos][i]]);
        }
    }
    //cout << pos << " " << brac[pos] << " " << niebrac[pos] << endl;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i<n;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    /*
    int pos;
    int father = 0;
    for(int i = 0;i<G[father].size(),i++){
        pos = G[father][i];
        brac[pos] = niebrac[father]+1;
        niebrac[pos] = max(niebrac[father], brac[father]);
    }*/
    dfs(1,0);
    /*
    for(int i = 0;i<=n;i++){
        cout << "wierzcholek nr. " << i << "\n";
        cout << brac[i] << " brac\n";
        cout << niebrac[i] << " niebrac\n";
    }*/
    cout << max(brac[1],niebrac[1]);

    return 0;
}