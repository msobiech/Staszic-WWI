#include <iostream>
using namespace std;

struct node{
    long long p;
    long long k;
    long long w;
};

node add(node l, node r){
    node ans;
    ans.p = l.p+r.p;
    ans.k = l.k+r.k;
    ans.w = l.w+r.w+(l.p*r.k);
    return ans;
}

const long long base = 1<<18;
node tree[base<<1];

void update(long long y){
    y+=base;
    tree[y].p = !tree[y].p;
    tree[y].k = !tree[y].k;
    y/=2;
    while(y!=0){
        tree[y] = add(tree[y*2],tree[y*2+1]);
        y/=2;
    }
}

node query(long long v, long long l, long long r, long long p, long long k){
    if(p<=l && r<=k){
        return tree[v];
    }
    node ans = {0,0,0};
    int mid = (l+r)/2;
    if(p<=mid){
        ans = add(ans,query(v*2,l,mid,p,k));
    }
    if(k>mid){
        ans = add(ans,query(v*2+1,mid+1,r,p,k));
    }
    return ans;
}

node setup(char x){
    node ans = {0,0,0};
    if(x=='P')ans.p=1;
    else ans.k=1;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(long long i = 0;i<base*2;i++){
        tree[i] = {0,0,0};
    }
    long long n,q;
    cin >> n >> q;
    string input;
    cin >> input;
    for(long long i = 0;i<n;i++){
        tree[base+i]=setup(input[i]);
    }
    for (long long i = base-1; i>0; i--) {
        tree[i] = add(tree[i*2], tree[i*2+1]);
    }
    for(long long i = 0;i<q;i++){
        char z;
        cin >> z;
        if(z == '?'){
            long long a,b;
            cin >> a >> b;
            cout << query(1,0,base-1,a-1,b-1).w << endl;
        }
        else{
            long long a;
            cin >> a;
            a--;
            update(a);
        }
    }

}