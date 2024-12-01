#include <iostream>
using namespace std;


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
    long long a,b,m;
    cin >> a >> b >> m;
    long long x,y;
    long long g;
    g = gcd(a,m,x,y);
    if(b%g!=0){
        cout << "NIE\n";
    }
    else{
        a/=g;
        b/=g;
        m/=g;
        //cout << a << " " << b << " " << m << endl;
        cout << (((b*x)%m)+m)%m << endl;
    }
}