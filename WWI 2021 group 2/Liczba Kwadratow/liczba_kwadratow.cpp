#include <iostream>
using namespace std;
int tab[1001][1001];
int dyn[1001][1001];
int main() {
    int n;
    cin >> n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin >> tab[i][j];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(tab[i][j]==1){
                dyn[i][j]=0;
            }
            else{
                dyn[i][j]=min(dyn[i-1][j],min(dyn[i][j-1],dyn[i-1][j-1]))+1;
            }
        }
    }
    int sum = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
           sum+=dyn[i][j];
        }
    }
    cout << sum;

}