#include <iostream>
#include <cmath>
using namespace std;
constexpr int MAXN = 1e6+10;
pair<long long,long long> tab[MAXN];
long long dyn[MAXN][2];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(a<b){
            swap(a,b);
        }
        tab[i] = {a,b};
    }
    dyn[0][1] = tab[0].second+tab[0].first;
    dyn[0][0] = tab[0].second+tab[0].first;
    for(int i = 1;i<n;i++){
        dyn[i][1] = max(abs(tab[i-1].first-tab[i].first)+dyn[i-1][1]+tab[i].second,  abs(tab[i-1].second-tab[i].first)+dyn[i-1][0]+tab[i].second);
        dyn[i][0] = max(abs(tab[i-1].first-tab[i].second)+dyn[i-1][1]+tab[i].first,  abs(tab[i-1].second-tab[i].second)+dyn[i-1][0]+tab[i].first);
    }
    dyn[n-1][0]+=tab[n-1].second;
    dyn[n-1][1]+=tab[n-1].first;
    cout << max(dyn[n-1][0],dyn[n-1][1]);
}