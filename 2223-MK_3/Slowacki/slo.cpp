#include <iostream>
#include <vector>
using namespace std;
constexpr long long MAXN = 5e5+5;
long long pozlca[MAXN];
long long odlg[MAXN];
const long long log = 21;
long long jumppointer[MAXN][log];
vector<pair<long long,long long>> G[MAXN];
void dfs(long long v, long long ojc, long long odl){
	odlg[v] = odl;
	pozlca[v] = pozlca[ojc]+1;
	jumppointer[v][0] = ojc;
	for(long long i = 1;i<log;i++){
		jumppointer[v][i] = jumppointer[jumppointer[v][i-1]][i-1];
	}
	for(auto g:G[v]){
		if(g.first!=ojc){
			dfs(g.first,v,(odl+g.second));
		}
	}
}

long long lca(long long a,long long b){
	if(pozlca[a] < pozlca[b]){
		swap(a,b);
	}
	for(long long i = log-1;i>=0;i--){
		if(pozlca[jumppointer[a][i]]>=pozlca[b]){
			a = jumppointer[a][i];
		}
	}
	if(a==b){
		return a;
	}
	for(long long i = log-1;i>=0;i--){
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
        long long a,b,c;
        cin >> a >> b >> c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    dfs(1,1,0);
    long long a,b;
    while(true){
        cin >> a;
        if(a==-1){
            return 0;
        }
        cin >> b;
        long long lc = lca(a,b);
        //cout << liczodl(a,b,lc) << endl;
        cout << odlg[a]+odlg[b]-2*odlg[lc] << endl;
    }
}