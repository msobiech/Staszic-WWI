#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	ll n;
    cin >> n;
    ll sum = 0;
    cin >> sum;
    ll x;
    cin >> x;
    sum-=x;
    for(int i = 2;i<n;i++){
        cin >> x;
        sum+=max(x,-x);
    }
    cout << sum;
}