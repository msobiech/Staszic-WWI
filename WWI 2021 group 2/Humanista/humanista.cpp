#include <iostream>
using namespace std;

int base = 1<<20;
int drz[(1<<21)+1];

void zmien(int x, int naco){
    x+=base;
    drz[x]=naco;
    while(x>1){
        x/=2;
        drz[x]=drz[2*x]^drz[2*x+1];
    }
}

int sum(int x, int xa, int xb, int za, int zb){
    if(za<=xa && xb<=zb){
        return drz[x];
    }
    int sr=(xa+xb)/2;
    int wyn=0;
    if(za<=sr){
        wyn^=sum(2*x,xa,sr,za,zb);
    }
    if(sr+1<=zb){
        wyn^=sum(2*x+1,sr+1,xb,za,zb);
    }
    return wyn;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 1;i<=n;i++){
        cin >> drz[base+i];
    }
    string polecenie;
    for(int i = base-1;i>=1;i--){
        drz[i]=drz[i*2]^drz[i*2+1];
    }
    for(int i = 0;i<q;i++){
        cin >> polecenie;
        if(polecenie[0]=='c'){
            int a,b;
            cin >> a >> b;
            cout << sum(1,0,base-1,a,b) << "\n";
        }
        else{
            int a,b;
            cin >> a >> b;
            int c = drz[base+a];
            zmien(a,drz[base+b]);
            zmien(b, c);
        }

    }
    return 0;
}