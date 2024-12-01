#include <iostream>
using namespace std;

constexpr int MOD = 1e9+7;

long long qp(long long a, long long b){
	long long ans = 1;
	while(b>0){
		if(b%2 == 1)
			ans = (ans*a)%MOD;
		a = (a*a)%MOD;
		b/=2;
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        cout << qp(a,b) << endl;
    }

}