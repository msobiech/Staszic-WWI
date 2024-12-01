#include <iostream>
#include <set>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

int cur = 0;
int pop = 1;
constexpr int MAXN = 1e6+6;
constexpr int INF = -1*1e6;;
int KMR[MAXN][2];
ordered_set S[21];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string input;
    cin >> input;
    int curpow = 1;
    for(int i = 0;i<n;i++){
        KMR[i][cur] = input[i]-'a';
    }
    int curset = 0;
    while(curpow*2<=n && curset<21) {
        swap(pop,cur);
        curpow*=2;
        for(int i = 0;i<n;i++){
            if(i+(curpow/2)<n){
                S[curset].insert({KMR[i][pop],KMR[i+(curpow/2)][pop]});
            }
            else{
                S[curset].insert({KMR[i][pop],INF});
            }
        }
        for(int i = 0;i<n;i++){
            if(i+(curpow/2)<n){
                KMR[i][cur] = S[curset].order_of_key({KMR[i][pop],KMR[i+(curpow/2)][pop]}) + 1;
            }
            else{
                KMR[i][cur] = S[curset].order_of_key({KMR[i][pop],INF})+1;
            }
        }
        curset++;
        //cout << curpow << endl;
    }
    int maximum = -1;
    int ans = -1;
    for(int i = 0;i<n;i++){
        if(maximum<KMR[i][cur]){
            maximum=KMR[i][cur];
            ans = i+1;
        }
    }
    cout << ans << endl;


    return 0;
}