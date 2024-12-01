#include <iostream>
using namespace std;
const int base = 1<<20;
int tree[base*2+7];
int stars[base*2+7];

void push(int v, int lf, int rt){
    if(v*2>=base){
        tree[lf]=stars[v];
        tree[rt]=stars[v];
        stars[v]=0;
        return;
    }
    if(stars[v]!=0){
        tree[lf] = stars[v];
        tree[rt] = stars[v];
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
        tree[v] = x;
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
        tree[v]=max(tree[lf],tree[rt]);

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
        int ans = max(query(lf,a,mid,l,r),query(rt,mid+1,b,l,r));
        //cout << a << " " <<  b << " " << v << " "<< ans << endl;
        return ans;

    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d,n;
    cin >> d >> n;
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        swap(a,b);
        b +=a;
        //cout << "zapytanie " << a << " " << b-1 << endl;
        int maxi = query(1,0,base-1,a,b-1);

        set(1,0,base-1,a,b-1,maxi+1);

        //cout << "ustawiam na przedziale " << a << " " << b-1 << " " << maxi+1 << endl;
        /*
        for(int j = 0;j<d;j++){
            cout << query(1,0,base-1,j,j) << " " ;
        }
        cout << endl;
        //cout << '\n';*/
    }
    cout << query(1,0,base-1,0,d-1);
}
/*
5 5
2 0
3 2
2 1
3 3
1 0
 */