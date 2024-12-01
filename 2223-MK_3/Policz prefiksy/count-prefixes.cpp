#include <iostream>
using namespace std;

typedef long long ll;
constexpr ll MAXN = 2e5+7;

ll trie[MAXN][26];
ll konce[MAXN];

ll licz = 0, res = 0;

void dfs(ll v){
	licz += konce[v];
	for(ll i = 0; i <= 25; i++){
		if(trie[v][i] != -1){
            dfs(trie[v][i]);
		}
	}
	res += licz * konce[v];
	licz -= konce[v];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(ll i = 0; i<MAXN; i++){
        for(ll j = 0; j <= 25; j++){
            trie[i][j] = -1;
        }
    }
    ll q, v = 1;
    string in;
    cin>>q;
    for(ll i = 0; i < q; i++){
        cin>>in;
		ll pos = 0;
        for(auto g : in){
			if(trie[pos][g-'a'] == -1){
				trie[pos][g-'a'] = v;
				pos = v;
				v++;
			}else{
				pos = trie[pos][g-'a'];
			}
        }
		konce[pos]++;
    }
	dfs(0);
	cout<<res<<'\n';
    return 0;
}