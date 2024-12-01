#include <iostream>
using namespace std;

constexpr int base = 1<<18;
int tree[base<<1];
bool stars[base<<1];


inline void push(int v, int l, int mid , int r){
    int lf = v*2;
    int rt = v*2+1;
    if(v<base && stars[v]!=0){
        tree[lf] = mid-l+1-tree[lf];
        tree[rt] = r-mid-tree[rt];
        stars[lf] = !stars[lf];
        stars[rt] = !stars[rt];
        stars[v]=0;
    }
}

void update(int v, int l, int r, int p, int k){
    if(p<=l && r<=k){
        //cout << v << endl;
        tree[v]=(r-l+1)-tree[v];
        stars[v] = !stars[v];
    }
    else{
        int a = v*2; int b = (v*2)+1; int mid = (l+r)/2;
        push(v,l,mid,r);
        if(p<=mid){
            update(a,l,mid,p,k);
        }
        if(k>mid){
            update(b,mid+1,r,p,k);
        }
        tree[v]=tree[v*2]+tree[v*2+1];
    }
}

int query(int v, int l, int r, int p, int k){
    if(p<=l && r<=k){
        //cout << v;
        return tree[v];
    }
    else{
        int a = v*2; int b = (v*2)+1; int mid = (l+r)/2;
        push(v,l,mid,r);
        int leftson = 0;int rightson = 0;
        if(p<=mid){
            leftson = query(a,l,mid,p,k);
        }
        if(k>mid){
            rightson = query(b,mid+1,r,p,k);
        }
        return leftson+rightson;

    }
}

void printtree(int base){
    for(int i = base;i<base*2;i++){
        cout << tree[i] << " ";
    }
    cout << endl;
    for(int i = base/2;i<base;i++){
        cout << tree[i] << " ";
    }
    cout << endl;
    cout << tree[1] << endl;
    for(int i = base;i<base*2;i++){
        cout << stars[i] << " ";
    }
    cout << endl;
    for(int i = base/2;i<base;i++){
        cout << stars[i] << " ";
    }
    cout << endl;
    cout << stars[1] << endl;

}
int main(){
    for(int i = base;i<base*2;i++){
        tree[i] = 1;
    }
    for(int i = base-1;i>0;i--){
        tree[i] = tree[i*2]+tree[i*2+1];
    }
    //printtree(4);

    int n,q;
    cin >> n >> q;
    for(int i = 0;i<q;i++){
        char z;
        cin >> z;
        int a,b;
        cin >> a >> b;
        a--;b--;
        if(z=='?'){
            cout << query(1,0,base-1,a,b) << endl;
        }
        else{
            update(1,0,base-1,a,b);
        }
        //printtree(4);

    }

}