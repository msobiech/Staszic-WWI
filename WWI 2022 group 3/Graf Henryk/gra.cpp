#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>
using namespace std;

struct edge{
    int neighbour;
    int id;
    int original;
};

struct sccedge{
    int sccid;
    int id;
    int realorigin;
    int realneighbour;
};

const int MAXN = 400004;
bool odw[MAXN];
vector<edge> G[MAXN];
bool edges[MAXN];
bool used[MAXN];
pair<int,int> originals[MAXN];
int maxsilnia = 0;
int ans = 0;
pair<int,int> last[MAXN];
bool set[MAXN];
//rzeczy do scc
bool vis[MAXN];
vector<int> G2[MAXN];
vector<sccedge> G3[MAXN];
vector<int> T[MAXN];
vector<int> post;
int ssc[MAXN];
int licznik = 0;
int sizeofscc[MAXN];

//koniec rzeczy do scc

//algo do scc
void dfs(int v){
    vis[v] = true;
    for(int s: G2[v]){
        if(!vis[s]){
            dfs(s);
        }
    }
    post.push_back(v);
}
inline bool isint(char c){
    if(c >= '0' && c<='9'){
        return true;
    }
    else{
        return false;
    }
}
inline int readint(){
    char c;
    int x = 0;
    while(!isint(c = getchar_unlocked())){
    }
    do{
        x=x*10+int(c-'0');
    }while(isint(c = getchar_unlocked()));
    return x;

}
void DFS_scc(int v, int x){
    ssc[v] = x;
    sizeofscc[x]++;
    if(maxsilnia<sizeofscc[x]){
        ans = x;
        maxsilnia = sizeofscc[x];
    }
    for(int s: T[v]){
        if(ssc[s] == 0){
            DFS_scc(s, x);
        }
    }
}
//koniec algo do scc
void dfs_routing(int v){
    odw[v]=true;
    for(auto i:G[v]){
        if(used[i.id]){
            continue;
        }
        used[i.id] = true;
        if(!odw[i.neighbour]){
            dfs_routing(i.neighbour);
        }
        if (i.original == 0) {
            edges[i.id] = false;
        } else {
            edges[i.id] = true;
        }
    }
}

void lastdfs(int v, int oj){
    //cout << "jestem w wierzcholku " << v << endl;
    for(auto g:G3[v]){
        //cout << g.sccid << " " << g.id << " " << g.realorigin << " " <<g.realneighbour << endl;
        if(g.sccid!=oj){
            last[g.id] = {g.realneighbour,g.realorigin};
            set[g.id]= true;
            lastdfs(g.sccid,v);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = readint();
    int m = readint();
    //cout << n << " " << m << endl;
    for(int i = 0;i<m;i++){
        int x = readint();
        int y = readint();
        //cin >> x >> y;
        edge temp = {y,i,1};
        G[x].push_back(temp);
        temp.neighbour = x;
        temp.original = 0;
        G[y].push_back(temp);
        originals[i] = {x,y};
    }
    for(int i = 1;i<=n;i++){
        if(!odw[i]){
            dfs_routing(i);
        }
    }
    for(int i = 0;i<m;i++){
        if(edges[i]){
            G2[originals[i].first].push_back(originals[i].second);
            T[originals[i].second].push_back(originals[i].first);
        }
        else{
            G2[originals[i].second].push_back(originals[i].first);
            T[originals[i].first].push_back(originals[i].second);
        }
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    for(int i = post.size()-1; i >= 0; i--){
        if(ssc[post[i]] == 0){
            DFS_scc(post[i], ++licznik);
        }
    }
    cout << maxsilnia << endl;
    for(int i = 1;i<=n;i++){
        for(auto g:G[i]){
            int a = i;
            int b = g.neighbour;
            int id = g.id;
            //cout << a << " " << b << endl;
            if(ssc[a]!=ssc[b]){
                //cout << "krawedz z " << ssc[a] << " do " << ssc[b] << " " << id << " " << a << " " << b << endl;
                G3[ssc[a]].push_back({ssc[b],id,a,b});
                //G3[ssc[b]].push_back({ssc[a],id,b,a});
            }
        }
    }
    //cout << "zbudowano\n";
    lastdfs(ans,ans);
    for(int i = 0;i<m;i++){
        //cout << "edge: " << i << " | " << edges[i] << endl;
        if(!set[i]){
            if (edges[i]) {
                cout << originals[i].second << " " << originals[i].first << endl;
                //cout << '>'
            } else {
                cout << originals[i].first << " " << originals[i].second << endl;
                //cout << '<';
            }
        }
        else{
            cout << last[i].first << " " << last[i].second << endl;
        }

    }

}