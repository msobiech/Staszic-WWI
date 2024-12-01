#include <iostream>
#include <climits>
#include <stdio.h>
using namespace std;
typedef long long ll;
constexpr ll base = 1<<18;
ll Tree[base*2+1][2];
ll Stars[base*2+1];
ll inf = LLONG_MIN;
ll odp[2];
ll porownanie = 0;
inline void push(ll v, ll lf, ll rt){
    if(Stars[v]!=0){
        if(v<base){
            Tree[lf][0]+=Stars[v];
            Tree[lf][1]+=Stars[v];
            Tree[rt][0]+=Stars[v];
            Tree[rt][1]+=Stars[v];
            Stars[lf]+=Stars[v];
            Stars[rt]+=Stars[v];
            Stars[v]=0;
        }
    }

}
void add(ll v, ll l, ll r, ll p, ll k, ll x){
    if(r<p || l>k){
        return;
    }
    else if(p<=l && r<=k){
        Tree[v][0]+= x;
        Tree[v][1]+= x;
        Stars[v]+= x;
    }
    else{
        ll a = v*2; ll b = (v*2)+1; ll mid = (l+r)/2;
        push(v,a,b);
        if(p<=mid){
            add(a,l,mid,p,k,x);
        }
        if(k>mid){
            add(b,mid+1,r,p,k,x);
        }
        Tree[v][0] = max(Tree[a][0],Tree[b][0]);
        Tree[v][1] = max(Tree[a][1],Tree[b][1]);
    }
}


inline void setpoll(ll y,ll x,ll id){
    y+=base;
    Tree[y][id] = x;
    y/=2;
    while(y>0){
        Tree[y][id] = max(Tree[y*2][id],Tree[y*2+1][id]);
        y/=2;
    }
}

void check(ll v, ll id){
    push(v,v*2,v*2+1);
    //cout << v << endl;
    if(v>=base){
        //cout <<  id << "++\n";
        setpoll(v-base,inf,id);
        odp[id]++;
        return;
    }
    else{
        if(Tree[v*2][id]>=porownanie){
            check(v*2,id);
        }
        if(Tree[v*2+1][id]>=porownanie){
            check(v*2+1,id);
        }
    }
    return;
}
inline bool isll(char c){
    if(c >= '0' && c<='9'){
        return true;
    }
    else{
        return false;
    }
}
inline ll readll(){
    char c;
    ll x = 0;
    while(!isll(c = getchar_unlocked())){
    }
    do{
        x=x*10+ll(c-'0');
    }while(isll(c = getchar_unlocked()));
    return x;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,q,g1,g2;
    n=readll();    q=readll();    g2=readll();    g1=readll();

    //cin >> n >> q >> g2 >> g1;
    //cout << n << " " << q << " " << g1 << " " << g2 << endl;
    for(ll i = 0;i<base*2;i++){
        Tree[i][0] = inf;
        Tree[i][1] = inf;
    }
    for(ll i = 0;i<n;i++){
        ll x;
        x = readll();
        //cout << x << " ";
        //cin >> x;
        setpoll(i,(-1*g1)+x,0);
        setpoll(i,(-1*g2)+x,1);
    }
    //cout << endl;
    for(ll i = 0;i<q;i++){
        ll a,b,c;
        a = readll();
        b= readll();
        c = readll();
        //cout << a << " " << b << " " << c << endl;
        //cin >> a >> b >> c;
        porownanie--;
        add(1,0,base-1,a-1,b-1,c);
        //cout << "sprawdzanie zajebistych\n";
        check(1,0);
        //cout << "sprawdzanie chujowych\n";
        check(1,1);
        cout << odp[0] << " " << odp[1]-odp[0] << endl;
    }
}