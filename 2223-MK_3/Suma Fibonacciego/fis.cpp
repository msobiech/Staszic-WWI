#include <iostream>
#include <array>
using namespace std;
constexpr int siz = 3;
typedef long long ll;
array<array<ll,siz>,siz> root;
const int mod = 1e9+7;
 
array<array<ll,siz>,siz> mnoz(array<array<ll,siz>,siz> a, array<array<ll,siz>,siz> b){
    array<array<ll,siz>,siz> c;
    for(ll i = 0;i<siz;i++){
        for(ll j = 0;j<siz;j++){
            ll sum = 0;
            for(ll w = 0;w<siz;w++){
                sum+=(a[i][w]%mod*b[w][j]%mod)%mod;
            }
            c[i][j] = sum%mod;
        }
    }
    return c;
}
 
array<array<ll,siz>,siz> fast_power(array<array<ll,siz>,siz> base, ll power) {
    array<array<ll,siz>,siz> result = base;
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
array<array<ll,siz>,siz> pot_szybkie(array<array<ll,siz>,siz> a,ll b)
{
    if(b==1){
        return a;
    }
	else if(b%2==0){
        array<array<ll,siz>,siz> w = pot_szybkie(a,b/2);
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
 
ll readInt(){
    char c;
    ll x = 0;
    ll mult = 1;
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
 
    root[0] = {1,1,0};
    root[1] = {1,0,0};
    root[2] = {1,1,1};
    ll a,b;
    cin >> a >> b;
    array<array<ll,siz>,siz> c;
    c = fast_power(root,a-1);
    ll sum = (c[2][0]%mod + c[2][2]%mod -1)%mod;
    c = fast_power(root,b);
    ll sum2 = (c[2][0]%mod + c[2][2]%mod -1)%mod;
    if(a==0 || a==1)sum = 0;
    if(b==0)sum2 = 0;
    cout << (sum2-sum+mod)%mod<< endl;
}