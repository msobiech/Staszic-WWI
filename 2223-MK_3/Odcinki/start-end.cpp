#include <iostream>
using namespace std;

const long long base = 1<<20;
long long tree[base*2];

void dodaj(long long x, long long dod){
    x+=base;
    //cout << "dodaje " << x << " " << dod<< endl;
    tree[x]+=dod;
    x/=2;
    while(x){
        tree[x] = tree[x*2]+tree[x*2+1];
        //cout << "dodaje " << x << " " << dod<< endl;
        x/=2;
    }

}

long long przed(long long a,long long b){
    long long wyn = 0;
    a+=base-1;
    b+=base+1;
    while(int(a/2)!=int(b/2)){
        //cout << "przegladam przedzial: "<< a << " " << b << endl;
        if(a%2==0){
            wyn+=tree[a+1];
            //cout << "dla przedzialu " << a << " " << b << endl;
            //cout << tree[a+1] << endl;
        }
        if((b+1)%2==0){
            wyn+=tree[b-1];
            //cout << "dla przedzialu " << a << " " << b << endl;
            //cout << b-1 << " " << tree[b-1] << endl;
        }
        a/=2;
        b/=2;
    }
    return wyn;

}
int main(){
    ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
    long long n,m;
    cin >> n >> m;
    string in;
    cin >> in;
    long long odp = 0;
    long long p = 0;
    for(long long i = 0;i<n;i++){
        if(in[i]=='P'){
            p++;
            dodaj(i,1);
        }
        else{
            odp+=p;
        }
    }
    cout << odp << "\n";
    for(long long i = 0;i<m;i++){
        long long a;
        cin >> a;
        a--;
        if(in[a]=='P'){
            in[a]='K';
            odp+=przed(0,a-1);
            //cout << "nastepna linia" << endl;
            odp-=(n-1-a)-przed(a+1,n-1);
            dodaj(a,-1);
            cout << odp << endl;
        }
        else{
            in[a]='P';
            odp-=przed(0,a-1);
            //cout << "nastepna linia" << endl;
            odp+=(n-1-a)-przed(a+1,n-1);
            dodaj(a,1);
            cout << odp << endl;
        }
    }
}