#include <iostream>
#include <vector>
using namespace std;
struct edge{
    long long s;//sasiad
};
const long long MAXN = 5e5+5;
const long long log = 19;
long long jumppointer[MAXN][log+1];
long long pozlca[MAXN];
vector<edge> G[MAXN];
int preorder[MAXN];
int postorder[MAXN];
int order = 1;
void dfs(long long v,long long oj){
    preorder[v] = order;
    pozlca[v]=pozlca[oj]+1;
    jumppointer[v][0]=oj;
    for(long long i = 1;i<=log;i++){
        jumppointer[v][i] = jumppointer[jumppointer[v][i-1]][i-1];
    }
    for(auto e:G[v]){
        if(e.s!=oj){
            order++;
            dfs(e.s , v);
        }
    }
    postorder[v] = order;
}

long long lca(long long a,long long b){
    if(pozlca[a]<pozlca[b]){
        swap(a,b);
    }
    //dopasowywanie poziomow
    for(long long i = log;i>=0;i--){
        if(pozlca[jumppointer[a][i]]>=pozlca[b]){
            a = jumppointer[a][i];
        }
    }
    if(a==b){
        return a;
    }
    for(long long i = log;i>=0;i--){
        if(jumppointer[a][i]!=jumppointer[b][i]){
            a = jumppointer[a][i];
            b = jumppointer[b][i];
        }
    }
    return jumppointer[a][0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    for(long long i = 1;i<n;i++){
        long long a,b;
        cin >> a >> b;
        G[a].push_back({b});
        G[b].push_back({a});
    }
    dfs(1,1);
    long long a,b,c;
    int q;
    cin >> q;
   for(int i = 1;i<=q;i++){
        cin >> a >> b >> c;
        if(pozlca[b] > pozlca[a]){
               swap(a,b);
        }
        long long lac = lca(a,c);
        long long lbc = lca(b,c);
        long long lab = lca(a,b);
        if(!((postorder[c]>=postorder[a] && preorder[c]<=preorder[a]) || (postorder[c]>=postorder[b] && preorder[c]<=preorder[b]))){
            cout << "NIE\n";
        }
        else if(lac==lab || lbc==lab){
            cout << "TAK\n";
        }
        else{
            cout << "NIE\n";
        }
    }
}
/*
5
1 2
1 3
3 4
3 5
6
3 4 1
1 4 3
5 3 1
1 5 1
2 1 3
2 3 1
*/
/*
NIE
TAK
NIE
TAK
NIE
TAK
*/