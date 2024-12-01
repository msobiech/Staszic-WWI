#include <iostream>
using namespace std;
struct mac{
    long long x11;
    long long x12;
    long long x21;
    long long x22;
};

mac mnoz(mac W, mac Q){
    mac P;
    P.x11 = (W.x11*Q.x11 + W.x12 * Q.x21)%123456789;
    P.x12 = (W.x11*Q.x12 + W.x12 * Q.x22)%123456789;
    P.x21 = (W.x21*Q.x11 + W.x22 * Q.x21)%123456789;
    P.x22 = (W.x21*Q.x12 + W.x22 * Q.x22)%123456789;
    return P;
}

mac pot_szybkie(mac a,long long b)
{
    if(b==0){
        mac zer;
        zer.x11 = zer.x22 = 1;
        zer.x12 = zer.x21 = 0;
        return zer;
    }
	else if(b%2==0){
        mac w = pot_szybkie(a,b/2);
        return mnoz(w,w) ;
	}
	else{
        return mnoz(a,pot_szybkie(a,b-1));
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    //cin >> n;
    mac start;
    start.x11 = start.x12 = start.x21 = 1;
    start.x22 = 0;
   // mac wyn = mnoz(start,start);
  //  cout << wyn.x11 << " " << wyn.x12 << endl;
   // cout << wyn.x21 << " " << wyn.x22 << endl;
   /*
   mac wyn = pot_szybkie(start,3);
   cout << wyn.x11 << " " << wyn.x12 << endl;
   cout << wyn.x21 << " " << wyn.x22 << endl;*/
    cin >> n;
    cout << pot_szybkie(start,n).x12;
}