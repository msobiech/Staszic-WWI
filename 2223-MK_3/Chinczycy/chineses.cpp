#include <iostream>
using namespace std;

 typedef long long ll;
long long gcd(long long a, long long b, long long &x, long long &y){
    if(b==0){
        x = 1;
        y = 0;
        return a;
    }
    long long g = gcd(b, a%b, x, y);
    long long y1 = y;
    y = x-(y*(a/b));
    x = y1;
    return g;
}


int main(){
    long long n1,n2, r1,r2;
    cin >> n1 >> n2 >> r1 >> r2;
    ll x,y;
    ll g = gcd(n1,n2,x,y);
    ll n3 = n1*n2;
    //ll x3 = ((r2-r1)*x)%n3;
    ll x2 = (((x*r2)%n2 - (x*r1)%n2)+n2)%n2;
    //cout << x3 << "   " << x2 << endl;
    cout << (ll(r1+x2*n1)%n3+n3)%n3;
}