#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6+2;
constexpr ll base = 1<<20;
ll Tree[base*2+1];
ll Stars[base*2+1];
ll inf = LLONG_MIN;
ll odp[MAXN];
void push(ll v, ll lf, ll rt){
    if(v<base){
        Tree[lf]+=Stars[v];
        Tree[rt]+=Stars[v];
        Stars[lf]+=Stars[v];
        Stars[rt]+=Stars[v];
        Stars[v]=0;
    }

}
void add(ll v, ll l, ll r, ll p, ll k, ll x){
    //cout << v << " " << l << " " << r << " " << p << " " << k << " " << x << endl;
    if(r<p || l>k){
        return;
    }
    else if(p<=l && r<=k){
        Tree[v]+= x;
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
        Tree[v] = max(Tree[a],Tree[b]);
    }
}


void setpoll(ll y,ll x){
    y+=base;
    Tree[y] = x;
    y/=2;
    while(y>0){
        Tree[y] = max(Tree[y*2],Tree[y*2+1]);
        y/=2;
    }
}

void check(ll v, ll day){
    push(v,v*2,v*2+1);
    if(v>=base){
        odp[v-base]=day;
        setpoll(v-base,inf);
        return;
    }
    else{
        if(Tree[v*2]>=0){
            check(v*2,day);
        }
        if(Tree[v*2+1]>=0){
            check(v*2+1,day);
        }
    }
    return;
}

int main(){
    ll n,q;
    cin >> n >> q;
    for(ll i = 0;i<n;i++){
        odp[i] = -1;
    }
    for(ll i = 0;i<base*2;i++){
        Tree[i] = inf;
    }
    for(ll i = 0;i<n;i++){
        ll x;
        cin >> x;
        setpoll(i,-1*x);
    }
    for(ll i = 0;i<q;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        add(1,0,base-1,a-1,b-1,c);
        check(1,i+1);
    }
    for(ll i = 0;i<n;i++){
        if(odp[i]<0){
            cout << "NIE\n";
        }
        else{
            cout << odp[i] << endl;
        }
    }
}