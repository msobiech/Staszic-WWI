#include <iostream>
#include <climits>
using namespace std;
int INF = INT_MAX;
int odl[501][501];
bool neg[501][501];
int main() {
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i==j){
                odl[i][j]=0;
            }
            else{
                odl[i][j]=INF;
            }
        }
    }


    for(int i = 0;i<m;i++){
        int a,b,g;
        cin >> a >> b >> g;
        odl[a][b]=min(odl[a][b],g);
    }
    for(int k = 1; k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1; j<=n;j++){
                if((odl[k][j] != INF && odl[i][k] != INF) && (odl[i][j] > (odl[i][k] + odl[k][j])))
                    odl[i][j] = odl[i][k] + odl[k][j];
            }
        }
    }
    for(int k = 1; k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1; j<=n;j++){
                if((odl[k][j] != INF && odl[i][k] != INF) && (odl[i][j] > (odl[i][k] + odl[k][j])))
                    neg[i][j] = true;
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(odl[i][j]==INF){
                cout << "*";
            }
            else if(neg[i][j] || odl[i][j]<-50000){
                cout << "-oo";
            }
            else{
                cout << odl[i][j];
            }
            cout << " ";
        }
        cout << endl;
    }
}