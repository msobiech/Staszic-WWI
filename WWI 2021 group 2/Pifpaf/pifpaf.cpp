#include <bits/stdc++.h>
using namespace std;

vector<int> PifPaf;
int potp[1000001];
long long hs[1000001];
int p =31;
int mod = 10000009;
long long fragment(long long a, long long b){
    if(a>0){
        return (hs[b]-hs[a-1]*potp[b-a+1]%mod+mod)%mod;
    }
    else{
        return hs[b];
    }

}
void decToBinary(int n){
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        PifPaf.push_back(binaryNum[j]);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    string S;
    cin >> n >> S;
    PifPaf.push_back(0);
    for(int i = 0; PifPaf.size()<1000000;i++){
        decToBinary(i);
    }
    potp[0]=1;
    for(long long i = 1;i<1000001;i++){
        potp[i]=potp[i-1]*p%mod;
    }
    int siz = S.size();
    hs[0]=S[0]-'a'+1;
    for(long long i = 1;i<siz;i++){
        hs[i]=(hs[i-1]*p+(S[i]-'a'+1))%mod;
    }
    for(int d = 1; d*2 <= n; d++)
    {
        bool ok = true;
        for(int i = 2*d, ib = 2; i < n && ok; i += d, ib++)
        {
            bool b = PifPaf[ib];
            int over;
            if (i + d > n) {
                over = i + d - n;
            } else {
                over = 0;
            }
            if(fragment(b*d, b*d + d - (over+1)) != fragment(i, i+d-(over+1))){
                ok = false;
            }
        }
        if(ok)
        {
            cout << (n+d-1)/d;
            return 0;
        }
    }
    cout << 2;
}