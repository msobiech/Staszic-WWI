#include <iostream>
using namespace std;

const int MAXN = 1e3+1;

int sum[MAXN+1][MAXN+1];
int tab[MAXN+1][MAXN+1];

bool correct(int i, int j, int x){
    int sum2 = sum[i][j]-sum[i-x][j]-sum[i][j-x]+sum[i-x][j-x];
    return (sum2==0);
}

int maxsize(int i, int j){
    //cout << i << " " << j << endl;
    int kon = min(i,j);
    int pocz = 0;
    long long mid = 0;
    //cout << pocz << " " << kon << " " << mid << endl;
    while(kon-pocz>1){
        mid = (pocz+kon)/2;
        //cout << pocz << " " << kon << " " << mid << endl;
        if(correct(i,j,mid)){
            pocz = mid;
            //cout << "popr\n";
            //cout << pocz << " " << kon << " " << mid << endl;
        }
        else{
            kon = mid;
        }
    }
    if(correct(i,j,kon)){
        return kon;
    }
    else{
        return pocz;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> tab[i][j];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+tab[i][j];
        }
    }
    /*
    cout << "----\n";
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }*/
    //cout << maxsize(2,4);

    int ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            ans=max(maxsize(i,j),ans);
        }
    }
    cout << ans << " ";
}