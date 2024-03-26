#include <bits/stdc++.h>

using namespace std;

const int BASE = 1<<20;
const int MAXN = 250007;

int tree[2*BASE];
vector<int> G[MAXN];
int preorder[MAXN];
int postorder[MAXN];
bool odw[MAXN];
bool odw2[MAXN];
int odl[MAXN];
int x;

void update(int a, int b, int x){
    a += BASE-1;
    b += BASE+1;
    while(b-a > 1){
        if(a%2==0){
            tree[a+1] += x;
        }
        if(b%2==1){
            tree[b-1] += x;
        }
        a >>= 1;
        b >>= 1;
    }
}

int read(int v){
    int result = 0;
    v += BASE;
    while(v){
        result += tree[v];
        v >>= 1;
    }
    return result;
}

void dfs(int v){
    x++;
    preorder[v] = x;
    odw[v] = true;
    for(auto s: G[v]){
        if(!odw[s]){
            dfs(s);
        }
    }
    postorder[v] = x;
}

void bfs(int v){
    queue<int> Q;
    Q.push(v);
    odl[v] = 0;
    odw2[v] = true;
    while(!Q.empty()){
        v = Q.front();
        Q.pop();
        for(int s: G[v]){
            if(!odw2[s]){
                odw2[s] = true;
                odl[s] = odl[v]+1;
                Q.push(s);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b, q;
    char znak;
    cin >> n ;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        G[a].push_back(b);
    }
    dfs(1);
    bfs(1);
    //zaimplementować drzewa
    cin >> m;
    for(int i = 0; i < (m+n-1); i++){
        cin >> znak;
        //cout << znak;
        if(znak == 'W'){
            cin >> a;
            cout << odl[a] - read(preorder[a]) << "\n";
            //cout << "W\n";
        }else{
            cin >> a >> b;
            update(preorder[b], postorder[b], 1);
        }
    }
    return 0;
}