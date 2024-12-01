#include <iostream>
#include <bitset>
using namespace std;
const short MAXN = 2001;
bitset<MAXN> station[MAXN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    short n,m,k;
    cin >> n >> m >> k;
    for(short i = 0;i<k;i++){
        short t;
        cin >> t;
        if(t==1){
            short a,b;
            cin >> a >> b;
            station[a][b]=true;
            //cout << station[a].count() << endl;
        }
        else{
            short a,b;
            cin >>a >> b;
            station[a]|=station[b];
            station[b]=station[a];
        }
    }
    for(short i = 0;i<n;i++){
        cout << station[i+1].count() << " " ;
    }
    return 0;
}