#include <algorithm>
#include <iostream>
using namespace std;

const int MAXN=1e5+5;

int n;
char dostawy[MAXN];
int dp[2][4][4][4];

inline int ore (int a, int b, int c) {
  int sol = 0;
  if (a == 1 || b == 1 || c == 1) sol++;
  if (a == 2 || b == 2 || c == 2) sol++;
  if (a == 3 || b == 3 || c == 3) sol++;
  return sol;
}

int main() {
    int n;
    cin >> n;
    string input;
    cin >> input;
    for(int i = 0;i<n;i++){
        if(input[i]=='F'){
            dostawy[i] = 1;
        }
        else if(input[i]=='M'){
            dostawy[i] = 2;
        }
        else{
            dostawy[i] = 3;
        }
    }
    int now = 0, prev = 1;
    for (int k=n-1; k>=0;k--){
       for (int a=0; a<=3;a++){
          for (int b=0; b<=3;b++){
             for (int c=0;c<=3;c++){
                int fir = ore(dostawy[k], dostawy[k-1], a) + dp[prev][dostawy[k-1]][b][c];
                int sec = ore(dostawy[k], b, c) + dp[prev][b][dostawy[k-1]][a];
                dp[now][a][b][c] = max(sec, fir);
             }
          }
       }
       swap(now, prev);
    }
    printf("%d\n", dp[prev][0][0][0]);
    return 0;
}