#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int>keymap;
const int BASE = 1 << 20;
int tree[2 * BASE + 1];
int tab[BASE];
int input[BASE];
int n;

void update(int v, int a){

    v += BASE;
    int b = tree[v];

    while(v){

        tree[v] += a;
        v/=2;
    }
}

int read(int l, int r){

    int solve = 0;

    l += BASE - 1;
    r += BASE + 1;

    while(r - l > 1){

        if(!(l&1))  solve += tree[l+1];
        if(r&1)     solve += tree[r-1];

        l/=2; r/=2;
    }

    return solve;
}

void parseinput(){

    int a;

    for(int i = 0; i < n; i++){
        cin >> a;
        tab[i] = a;
        input[i] = a;
    }
    sort(tab, tab + n);
    for(int i = 0; i < n; i++){
        if(!keymap[tab[i]]) keymap[tab[i]] = i;
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie();

    int q, a, b;
    cin >> n;

    parseinput();

    for(int i = 0; i < n; i++){
        cout << read(0, keymap[input[i]] - 1) << "\n";
        update(keymap[input[i]], 1);
    }
}