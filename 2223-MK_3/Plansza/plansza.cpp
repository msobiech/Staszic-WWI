#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 2e5 + 7;

struct edge{
    int a;
    int b;
    int wart;
};


vector<int> G[MAX_N*2];
edge edges[MAX_N*3];

int st[MAX_N * 2];
int pocz[MAX_N * 2];

int akt = 1;
int pop = -1;

void dfs(int v){
	for(int i = pocz[v];i<G[v].size();i++){
		i = max(i, pocz[v]);
		if(edges[G[v][i]].wart == 0){
			edges[G[v][i]].wart = akt;
			swap(akt, pop);
			if(edges[G[v][i]].a != v){
                dfs(edges[G[v][i]].a);
			}
			else{
                dfs(edges[G[v][i]].b);
			}
		}
		pocz[v] = i;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin>> n >> m;
    for(int i = 0; i<m;i++){
        cin>>a>>b;
        b += MAX_N;
        edges[i] = {a,b,0};
        G[a].push_back(i);
        G[b].push_back(i);
        st[a]++;st[b]++;
    }

    int s1 = MAX_N*2 -5;
    int s2 = MAX_N*2 -4;
    int temp = m;
    for(int i = 1; i<= n; i++){
        if(st[i]%2!=0){
            G[i].push_back(temp);
            G[s1].push_back(temp);
            st[i]++;
            st[s1]++;
            edges[temp] = {s1, i, 0};
            temp++;

        }
    }
    for(int i = MAX_N+1;i<=n+MAX_N;i++){
        if(st[i]%2!=0){
            G[i].push_back(temp);
            G[s2].push_back(temp);
            st[i]++;
            st[s2]++;
            edges[temp] = {s2,i,0};
            temp++;

        }
    }
    if(st[s1]%2!=0 && st[s2]%2!=0){
        G[s1].push_back(temp);
        G[s2].push_back(temp);
        st[s1]++;
        st[s2]++;
        edges[temp] = {s1, s2, 0};
        temp++;

    }
    for(int i = 0; i<temp; i++){
        if(st[i]%2!=0){
            cout<<"NIE\n";
            return 0;
        }
    }
    int i = 1;
    while(G[i].empty()){
            i++;
    }
    dfs(i);
    cout<<"TAK\n";
    for(int i = 0; i < m; i++){
        cout<<edges[i].wart<<'\n';
    }
}