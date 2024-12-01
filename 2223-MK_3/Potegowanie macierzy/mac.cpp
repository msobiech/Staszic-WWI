#include <iostream>
#include <array>
using namespace std;
long long n,m;
constexpr int siz = 102;
array<array<long long,siz>,siz> root;
const int mod = 1e9+7;

array<array<long long,siz>,siz> mnoz(array<array<long long,siz>,siz> a, array<array<long long,siz>,siz> b){
    array<array<long long,siz>,siz> c;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            long long sum = 0;
            for(int w = 0;w<n;w++){
                sum+=(a[i][w]*b[w][j])%mod;
            }
            c[i][j] = sum%mod;
        }
    }
    return c;
}

array<array<long long,siz>,siz> fast_power(array<array<long long,siz>,siz> base, long long power) {
    array<array<long long,siz>,siz> result = base;
    power--;
    while(power > 0) {
        if(power & 1) {
            result = mnoz(result,base);
        }
        base = mnoz(base,base);
        power = power>>=1;
    }
    return result;
}


/*
array<array<long long,siz>,siz> pot_szybkie(array<array<long long,siz>,siz> a,long long b)
{
    if(b==1){
        return a;
    }
	else if(b%2==0){
        array<array<long long,siz>,siz> w = pot_szybkie(a,b/2);
        return mnoz(w,w) ;
	}
	else{
        return mnoz(a,pot_szybkie(a,b-1));
	}
}*/
/*
bool isInt(char c){
    if(c>='0' && c<='9')return true;
    return false;
}

long long readInt(){
    char c;
    long long x = 0;
    long long mult = 1;
    while(!isInt(c = getchar_unlocked()) && c!='-'){
    }
    do{
        if(c=='-'){
            mult=-1;
        }
        else{
            x=x*10+int(c-'0');
        }

    }while(isInt(c = getchar_unlocked()) || c=='-');
    return x*mult;
}*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;// = readInt();
    cin >> m;// = readInt();
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> root[i][j];// = readInt();
        }
    }
    array<array<long long,siz>,siz> c;
    c = fast_power(root,m);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}
/*
3
2 3 2
2 1 2
5 3 2*/