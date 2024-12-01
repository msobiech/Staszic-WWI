#include <iostream>
using namespace std;

const int base = 1<<20;
long long tree[2*base+1];//trzymam wartosc we mnie
long long stars[2*base+1];//pushuje info do synow

void push(int v, int lf, int rt){
    if(v*2>=base){
        tree[lf]=stars[v];
        tree[rt]=stars[v];
        stars[v]=0;
        return;
    }
    if(stars[v]!=0){
        tree[lf] = 0;
        tree[rt] = 0;
    }
    stars[lf] = stars[v];
    stars[rt] = stars[v];
    stars[v]=0;
}

void set(int v, int a, int b,int l, int r, int x){//wierzcholek, jego zasieg(a,b), zasieg dodania(l,r), wartosc dodawana x
    if(v>=base && v-base>=l && v-base<=r){
        tree[v]=x;
        //cout << "zawieram sie jako lisc\n";
        return;
    }
    if(b<l || a>r){
        //cout << "nie zawieram sie " << a << " " << b << endl;
        return;

    }
    else if(a>=l && b<=r){
        //cout << "zawieram sie calkowicie" << a << " " << b << endl;
        tree[v] = 0;
        stars[v] = x;
    }
    else{
        //cout << "czesciowo  " << a << " " << b << endl;
        int lf=v*2,rt=v*2+1,mid=(a+b)/2;
        if(stars[v]!=0){
            push(v,lf,rt);
        }
        //cout << lf << " " << rt << endl;
        set(lf,a,mid,l,r,x);
        set(rt,mid+1,b,l,r,x);
        tree[v]=tree[lf]^tree[rt];

    }
}
//set(1,0,base-1,p,k,x)

long long query(int v, int a , int b, int l, int r){//wierzcholek, jego zasieg(a,b), zasieg przedzialu(l,r),
    if(b<l || a>r){
        //cout << "nie zawieram sie " << a << " " << b << " " << v << endl;
        return 0;
    }
    else if(a>=l && b<=r){
        //cout << "zawieram sie calkowicie " << a << " " << b << " " << v <<  endl;
        //cout << tree[v] << endl;
        return tree[v];
    }
    else{
        //cout << "zawieram sie czesciowo " << a << " " << b << " " <<  v << endl;
        int lf=v*2,rt=v*2+1,mid=(a+b)/2;
        if(stars[v]!=0){
            push(v,lf,rt);
        }
        int ans = query(lf,a,mid,l,r)^query(rt,mid+1,b,l,r);
        //cout << a << " " <<  b << " " << v << " "<< ans << endl;
        return ans;

    }
}

void init(int v){
    if(v>=base){
        return;
    }
    else{
        init(v*2);
        init(v*2+1);
        tree[v]=tree[v*2]^tree[v*2+1];
        //cout << tree[v] << " " << v << endl;
    }



}
int main() {
   // cout << (5^5);
   //cout << "BASE: " << base << endl;
    int n,q;
    cin >> n >> q;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        tree[base+i] = x;
    }
    init(1);
    for(int i = 0;i<q;i++){
        int t;
        cin >> t;
        if(t){
            int l,r;
            cin >> l >> r;
            cout << query(1,0,base-1,l-1,r-1) << endl;
        }
        else{
            int l,r,x;
            cin >> l>>r>>x;
            set(1,0,base-1,l-1,r-1,x);
        }
    }
    return 0;
}