#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> G[1000001];
bool odw[1000001];
bool odw2[1000001];
bool jestCykl;


void dfs(int v, int x){
    odw[v] = true;
    odw2[v] = true;
    for(auto s: G[v]){
        if(s.second <= x){
            if(!odw[s.first] && !odw2[s.first]){
                dfs(s.first, x);
            }
            else if(odw2[s.first]){
                jestCykl = true;
            }
        }
    }
    odw2[v] = false;
}

void cykl(int n, int s){
    jestCykl = false;
    for(int i = 1; i <= n; i++){
        odw[i] = false;
        odw2[i] = false;
    }
    dfs(1, s);
    for(int i = 1; i <= n; i++){
        if(!odw[i]){
            dfs(i, s);
        }
    }
}

int binsearch(int n, int m){
    int a = 0;
    int b = m+1;
    int s;
    while(b-a > 1){
        s = (a+b)/2;
        cykl(n, s);
        if(jestCykl){
            b = s;
        }else{
            a = s;
        }
    }
    cykl(n, a);
    if(jestCykl){
        return a;
    }else{
        return b;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back({b,i});
    }
    //odp(4);
    int odp = binsearch(n,m);
    cykl(n, odp);
    if(jestCykl){
        cout << odp;
    }else{
        cout << "NIE\n";
    }

    return 0;
}