#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1e6+3;
long long table[MAXN];

long long lower_boundd(long long x,long long n){
	long long a = 0;
	long long b = n;
	while(a<b){
       long long mid = (a+b)/2;
            if(table[mid]>=x){
                b = mid;
            }
            else
            {
                a = mid + 1;
            }
        }
        --a;
        return a;
}
long long upper_boundd(long long x,long long n){
	long long a = 0;
	long long b = n;
	while(a<b){
       long long mid = (a+b)/2;
            if(table[mid]>x){
                b = mid;
            }
            else
            {
                a = mid + 1;
            }
    }
        --a;
        return a;
}
int main() {
	ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
	long long n;
	cin >> n;
	for(long long i = 0;i<n;i++){
		cin >> table[i];
	}
	sort(table,table+n);
	long long q;
	cin >> q;
	for(long long i = 0;i<q;i++){
		long long x;
		cin >> x;
		cout << upper_boundd(x,n)-lower_boundd(x,n) << endl;
	}
	return 0;
}