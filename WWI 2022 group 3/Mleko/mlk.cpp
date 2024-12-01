//Wchodzi na 52 Trzeba dodac optymalizacje macierzami zeby weszlo na 100 
#include <iostream>
using namespace std;
const long long MAXN = 1000006;
long long a[MAXN];
long long b[MAXN];
const long long mod = 1000000007;
int main() {
    a[1] = 0;
    b[1] = 2;
    a[0] = 1;
    b[0] = 0;
    long long n;
    cin >> n;
    long long res = 12;
    for(long long i = 2;i<=n;i++){
        a[i] = 2*a[i-1]+4*a[i-2]+2*b[i-1]+4*b[i-2];
        a[i] = a[i]%mod;
        b[i] = b[i-1]*2;
        b[i] = b[i]%mod;
        //cout << a[i] << ' ' << b[i] << ' ' << res << '\n';
        if(i<n-1){
            res+=(2*a[i]+2*b[i]);
            res=res%mod;
        }
        if(i < n)res*=2;
        res=res%mod;
    }
    res+=2*a[n]+b[n];
    res=res%mod;
    if(n==1){
        res=2;
    }
    if(n==2){
        res = 24;
    }
    cout << res;
    return 0;
}