#include <iostream>
#include <climits>
#include <queue>
using namespace std;

constexpr int MAXN = 1e4+6;
vector<pair<int,int>> G[MAXN];
vector<int> input;

bool odw[MAXN];
long long odl[MAXN];
 
 
void Dijkstra(long long start){
	for(long long i = 1;i<MAXN;i++){
		odl[i] = LLONG_MAX;
		odw[i] = false;
	}
	odw[start] = true;
	odl[start] = 0;
	priority_queue<pair<long long,long long>> Q;
	Q.push({0,start});
	while(!Q.empty()){
		pair<long long,long long> tmp = Q.top();
		long long u = tmp.second;
		long long odlg = -1*tmp.first;
		Q.pop();
		for(auto g:G[u]){
			if(odw[g.first]){
				continue;
			}
			if(odl[g.first] > odlg + g.second){
				odl[g.first] = odlg+g.second;
				Q.push({-1*odl[g.first],g.first});
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
	int n;
	cin >> n;
	int mini = INT_MAX;
	for(int i = 0;i<n;i++){
		int x;
		cin >> x;
		mini = min(mini,x);
		input.push_back(x);
	}
	for(auto g:input){
		for(int i = 0;i<mini;i++){
			if(g!=mini){
				G[i].push_back({(i+g)%mini,int((g+i)/mini)});
			}
			
		}
	}
	Dijkstra(0);
	int q;
	cin >> q;
	for(int i = 0;i<q;i++){
		int x;
		cin >> x;
		if(int(x/mini)>=odl[x%mini]){
			cout << "TAK\n";
		}
		else{
			cout << "NIE\n";
		}
	}
}