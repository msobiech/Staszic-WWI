#include <iostream>
#include <climits>
using namespace std;

long long n,m;
const long long base = 1<<20;
long long tree[base*2+1];

void update(long long x, long long y){
    y+=base;
    tree[y] += x;
    y/=2;
    while(y>=1){
        tree[y] = max(tree[y*2],tree[y*2+1]);
        y/=2;
    }
}

long long read(long long a, long long b){
    a+=base-1;
    b+=base+1;
    long long maks = INT_MIN;
    while(b-a>1){
        if(!(a&1)){
            maks = max(maks,tree[a+1]);
        }
        if(b&1){
            maks = max(maks,tree[b-1]);
        }
        a/=2;b/=2;
    }
    return maks;


}
int main(){
    ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
    long long n,q;
    cin >> n >> q;
    for(long long i = 0;i<n;i++){
        long long x;
        cin >> x;
        update(x,i+1);
    }
    while(q--){
        char z;
        cin >> z;
        long long a,b;
        if(z=='?'){
            cin >> a >> b;
            cout << read(a,b) << endl;
        }
        else if(z=='+'){
            cin >> a >> b;
            update(b,a);
        }
    }
}