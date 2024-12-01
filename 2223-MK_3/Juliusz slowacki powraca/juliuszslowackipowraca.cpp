#include <iostream>
#include <vector>
#include <tuple>
#include "slo.h"
using namespace std;
struct edge{
    int s;//sasiad
    int w;//weight //w opisie krawedzi w edges to sa wierzcholki ktore krawedz laczy
};
const int MAXN = 1e5+5;
vector<edge> G[MAXN];
edge edges[MAXN];

bool odw[MAXN];
int odl[MAXN];
int jump[MAXN][21];
int pozlca[MAXN];
int preorder[MAXN];
int postorder[MAXN];
const int base = 1<<17;
int tree[base<<1];
int order = 0;
int zmiana[MAXN];

void dfs(int v, int oj, int dl){
    if(odw[v]){
        return;
    }
    order++;
    preorder[v]=order;
    jump[v][0] = oj;
    odl[v] = odl[oj]+dl;
    pozlca[v] = pozlca[oj]+1;
    for(int i = 1;i<=20;i++){
        jump[v][i] = jump[jump[v][i-1]][i-1];
    }
    odw[v] = true;
    for(auto i:G[v]){
        dfs(i.s , v , i.w);
    }
    postorder[v] = order;
}

void update(int a, int b, int x){
    a += base-1;
    b += base+1;
    while(b/2!=a/2){
        if(a%2==0){
            tree[a+1]+=x;
        }
        if(b%2==1){
            tree[b-1]+=x;
        }
        a/=2;b/=2;
    }
}

int read(int a){
    int sum = 0;
    a+=base;
    sum+=tree[a];
    a/=2;
    while(a>=1){
        sum+=tree[a];
        a/=2;
    }
    return sum;
}

void change(int a, int b, int x){
    if(pozlca[a]>pozlca[b]){swap(a,b);}
    int dl = 0;
    for(auto v: G[a]){
        if(v.s==b){
            dl = v.w;
            break;
        }
    }
    dl = x-dl;
    if(zmiana[b]!=0){
        update(preorder[b]-1,postorder[b]-1,-zmiana[b]);
    }
    zmiana[b] = dl;
    update(preorder[b]-1,postorder[b]-1,dl);
}

int lca(int a, int b){
    if(pozlca[a]>pozlca[b]){
        swap(a,b);
    }
    for(int i = 20;i>=0;i--){
        if(pozlca[jump[b][i]]>=pozlca[a]){
            b = jump[b][i];
        }
    }
    if(a==b){
        return b;
    }
    for(int i = 20;i>=0;i--){
        if(jump[b][i]!=jump[a][i]){
            a = jump[a][i];
            b = jump[b][i];
        }
    }
    return jump[a][0];
}

int distance(int a, int b){
    int lcaa = lca(a,b);
    int odp = odl[a]+read(preorder[a]-1)+odl[b]+read(preorder[b]-1)-2*(odl[lcaa]+read(preorder[lcaa]-1));
    return odp;
}

void init(vector<tuple<int, int, int>> edges){
    for(auto i:edges){
        int a = get<0>(i);
        int b = get<1>(i);
        int c = get<2>(i);
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    dfs(1,1,0);
}
/*
int main() {
    init({{1,2,3},{1,3,4},{2,5,1},{2,4,3},{3,6,10}});
        cout << distance(4, 6) << endl;//20
        change(1, 2, 1);
        cout << distance(4, 6) << endl;//18
        change(3, 6, 2);
        cout << distance(4, 6) << endl;//10
        change(2,5,80);
        cout << distance(5,6) << endl;//87
        change(1,2,60);
        change(1,2,8);
        cout << distance(4,6)<< endl;//17

}*/