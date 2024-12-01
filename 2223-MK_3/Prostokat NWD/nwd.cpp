#include <iostream>
using namespace std;

constexpr int MAXN = 1e6+5;
long long ile[MAXN];
int main(){
    long long odp = 0;
    long long n,m;cin >> n >> m;
    long long start = max(n,m);
    for(long long i = start;i>=1;i--){
            //cout << "licznie " << i << endl;
        ile[i]+=(n/i)*(m/i);
        long long j = i;
        while(j<=start){
            if(j!=i){
                //cout << "odejmuje " << j << endl;
                ile[i]-=ile[j];
            }
            j+=i;
        }
        //cout << " i :" << i << " : " << ile[i] << endl;
        odp+=ile[i]*i;
    }
    cout << odp << endl;
}