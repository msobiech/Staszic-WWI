#include <iostream>
#include <stdio.h>
using namespace std;

constexpr int base = 1<<18;
int tree[base<<1][10];
long long stars[base<<1];
int pom[10];
typedef long long ll;
inline void roll(int v,int x){
    for(int i = 0;i<10;i++){
        pom[(i+x)%10]=tree[v][i];
    }
    for(int i = 0;i<10;i++){
        tree[v][i]=pom[i];
    }
}

inline ll sum(int v){
    ll ans = 0;
    for(int i = 1;i<10;i++){
        ans+=(tree[v][i]*i);
    }
    return ans;
}

inline void addsons(int v){
    for(int i = 0;i<10;i++){
        tree[v][i]=tree[v*2][i]+tree[v*2+1][i];
    }
}

inline void setpoint(int v,int x){
    v+=base;
    tree[v][x]=1;
    v/=2;
    while(v>0){
        tree[v][x]++;
        v/=2;
    }
}

inline void push(int v, int lf, int rt){
    if(v<base){
        roll(lf,stars[v]);
        roll(rt,stars[v]);
        stars[lf]+=stars[v];
        stars[rt]+=stars[v];
        stars[v]=0;
    }
}

void add(int v, int l, int r, int p, int k, int x){
    if(r<p || l>k){
        return;
    }
    if(p<=l && r<=k){
        roll(v,x);
        stars[v]+= x;
    }
    else{
        int a = v*2; int b = (v*2)+1; int mid = (l+r)/2;
        push(v,a,b);
        if(p<=mid){
            add(a,l,mid,p,k,x);
        }
        if(k>mid){
            add(b,mid+1,r,p,k,x);
        }
        addsons(v);
    }
}

ll query(int v, int l, int r, int p, int k){
    if(r<p || l>k){
        return 0;
    }
    else if(p<=l && r<=k){
        //cout << v;
        return sum(v);
    }
    else{
        int a = v*2; int b = (v*2)+1; int mid = (l+r)/2;
        push(v,a,b);
        ll leftson = 0;ll rightson = 0;
        if(p<=mid){
            leftson = query(a,l,mid,p,k);
        }
        if(k>mid){
            rightson = query(b,mid+1,r,p,k);
        }
        return ll(leftson+rightson);

    }
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
    int n,q;
    n=readll();
    q=readll();
    //cin >> n >> q;
    for(int i = 0;i<n;i++){
        int x;
        x=readll();
        //cin >> x;
        setpoint(i,x%10);
    }
    for(int i = 0;i<q;i++){
        char z;
        cin >> z;
        if(z=='?'){
            int a,b;
            a = readll();
            b = readll();
            //cin >> a >> b;
            cout << query(1,0,base-1,a-1,b-1) << endl;
        }
        else{
            int a,b,x;
            a = readll();
            b = readll();
            x = readll();
            //cin >> a >> b >> x;
            add(1,0,base-1,a-1,b-1,x);
        }
    }
}