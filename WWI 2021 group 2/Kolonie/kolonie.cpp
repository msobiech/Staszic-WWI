#include <bits/stdc++.h>
using namespace std;
int root[1000010];
int masa[1000010];
int maxIQ[1000010];
int minIQ[1000010];

int Find (int a) {
    if (root[a]==a){
        return a;
    }
    root[a] = Find (root[a]);
    return (root[a]);
}

void Union(int a, int b){
    int x, y;
    x = Find(a);
    y = Find(b);
    if(x == y){
        return;
    }
    root[x] = root[y];
    maxIQ[y] = max(maxIQ[y], maxIQ[x]);
    minIQ[y] = min(minIQ[y], minIQ[x]);
    masa[y] = masa[y] + masa[x];
}

int main(){
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     int n;
     int bakteria1, bakteria2;
     int rootb1, rootb2;
     string polecenie;

     cin >> n;

     for (int i = 1; i <= n; i++)
        root[i] = i;

     for (int i = 1; i <= n; i++) {
        cin  >> masa[i] >> minIQ[i];
        maxIQ[i] = minIQ[i];
     }

     while(cin>>polecenie){
           if(polecenie[0]=='J'){
              cin >> bakteria1 >> bakteria2;
              Union(bakteria1, bakteria2);
           }
           if(polecenie[0]=='M'){
              cin >> bakteria1;
              rootb1 = Find(bakteria1);
              cout << masa[rootb1] << "\n";
           }
           if(polecenie[0]=='I'){
              cin >> bakteria1;
              rootb1 = Find(bakteria1);
              if(polecenie[4]=='A')
                 cout << maxIQ[rootb1] << "\n";
              else
                 cout << minIQ[rootb1] << "\n";
           }
     }
}