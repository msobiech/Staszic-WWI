#include <iostream>
using namespace std;

constexpr int MAXN = 200005;
constexpr int mod = 1000000007;


long long w[MAXN];
long long sil[MAXN];

constexpr long long szyb_pot(long long base, int exp){
    long long res = 1;
    for(int t = 1; t < (1<<30); t<<=1){
        if(t & exp){
            res *= base;
            res %= mod;
        }
        base *= base;
        base %= mod;
    }
    return res;
}

constexpr long long odw_mod(int a){
    return szyb_pot(a, mod-2);
}

long long dw_nw(int a, int b){
    return ((sil[a] * odw_mod(sil[b])) % mod * odw_mod(sil[a-b]) ) % mod;
}

inline bool isint(char c){
    if(c >= '0' && c<='9'){
        return true;
    }
    else{
        return false;
    }
}
inline int readint(){
    char c;
    int x = 0;
    while(!isint(c = getchar_unlocked())){
    }
    do{
        x=x*10+int(c-'0');
    }while(isint(c = getchar_unlocked()));
    return x;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sil[0] = 1;
    for(int i = 1; i < MAXN; i++){
        sil[i] = (sil[i-1] * i) % mod;
    }
    long long n, d, k;
    n = readint();
    d = readint();
    k = readint();
    w[d] = (szyb_pot(n,d) - szyb_pot(k,d)) % mod;
    w[d] += mod;
    w[d] %= mod;
    cout << w[d] * odw_mod(szyb_pot(n, d)) % mod << '\n';
    for(long long m = d+1; m <= n; m++){
        w[m] = (n * w[m-1]) % mod;
        w[m] -= ( (dw_nw(m-1,d-1) * szyb_pot(k, d)) % mod ) * szyb_pot(n-k, m-d) % mod;
        w[m] = ((w[m] % mod) + mod) % mod;
        cout <<( w[m] * odw_mod(szyb_pot(n, m)) ) % mod << '\n';
    }
    return 0;

}