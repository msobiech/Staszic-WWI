#include <iostream>
#include <climits>
using namespace std;
constexpr long long base = 1<<18;
long long Tree[base*2+1];
long long Stars[base*2+1];
long long inf = LLONG_MAX;
void push(long long v, long long lf, long long rt){
    Tree[lf]+=Stars[v];
    Tree[rt]+=Stars[v];
    Stars[lf] += Stars[v];
    Stars[rt] += Stars[v];
    Stars[v]=0;
}

void add(long long v, long long l, long long r, long long p, long long k, long long x){
    //cout << v << " " << l << " " << r << " " << p << " " << k << " " << x << endl;
    if(r<p || l>k){
        return;
    }
    else if(p<=l && r<=k){
        Tree[v]+= x;
        Stars[v]+= x;
    }
    else{
        long long a = v*2; long long b = (v*2)+1; long long mid = (l+r)/2;
        push(v,a,b);
        add(a,l,mid,p,k,x);
        add(b,mid+1,r,p,k,x);
        Tree[v] = min(Tree[a],Tree[b]);
    }
}
long long query(long long v, long long l, long long r, long long p, long long k){
    if(r<p || l>k){
        return inf;
    }
    else if(p<=l && r<=k){
        return Tree[v];
    }
    else{
        long long a = v*2; long long b = (v*2)+1; long long mid = (l+r)/2;
        push(v,a,b);
        return min(query(a,l,mid,p,k),query(b,mid+1,r,p,k));
    }
}

int main(){
    long long n,q;
    cin >> n >> q;
    for(long long i = 0;i<n;i++){
        long long x;
        cin >> x;
        add(1,0,base-1,i,i,x);
    }
    for(long long i = 0;i<q;i++){
        char z;
        cin >> z;
        if(z=='+'){
            long long a,b,c;
            cin >> a >> b >> c;
            add(1,0,base-1,a-1,b-1,c);
        }
        else{
            long long a,b;
            cin >> a >> b;
            cout << query(1,0,base-1,a-1,b-1) << endl;
        }
    }
}