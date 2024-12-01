#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct bio{
    int jj;
    int w;
    int h;
};

bool cmp(bio a, bio b){
    return a.w > b.w;
}

inline bool isint(char c){
    if(c >= '0' && c<='9'){
        return true;
    }
    else{
        return false;
    }
}
inline int readint(){
    char c;
    int x = 0;
    while(!isint(c = getchar_unlocked())){
    }
    do{
        x=x*10+int(c-'0');
    }while(isint(c = getchar_unlocked()));
    return x;

}
constexpr int MAXW = 1e8+2;
bio smurfs[100000];
int dp[MAXW];
int ans = 0;
int main() {
    int n,d;//amount of smurfs and height of the hole
    //cin >> n >> d;
    n = readint();
    d = readint();
    for(int i = 1;i<=n;i++){
        bio smurf;
        smurf.jj = readint();
        smurf.w = readint();
        smurf.h = readint();
        //cin >> smurf.jj >> smurf.w >> smurf.h;
        smurfs[i]=smurf;
    }
    sort(smurfs+1, smurfs+n+1,cmp);
    /*
    for(int i = 1;i<=n;i++){
        cout << smurfs[i].w << " ";
    }*/
    //cout << endl;
    int lim_b = min(MAXW-1,(smurfs[1].w*2)+1);
    for(int  i = 1;i<=n;i++){
        //cout << smurfs[i].w << endl;
        //cout << endl;
        lim_b = min(lim_b,smurfs[i].w*2+1);
        if(ll(dp[smurfs[i].w])+ll(smurfs[i].jj)>d){
            ans++;
            //dp[lim_b-1] = d+1;
        }
        for(int j = smurfs[i].w;j<=lim_b;j++){
            int j2 = min(j-smurfs[i].w,smurfs[i].w-1);
            //cout << j2 << endl;
            if(j2>0){
                dp[j2] = max(dp[j2],dp[j]+smurfs[i].h);
            }
        }
        for(int j = lim_b-1;j>=smurfs[i].w;j--){
            dp[j] = max(dp[j+1],dp[j]);
            if(dp[j]>d){
                dp[j]=d+1;
            }
        }
        /*
        for(int l = 0;l<lim_b;l++){
            cout << dp[l] << " ";
        }*/
        //cout << endl;
    }
    cout << n-ans;
    return 0;
}