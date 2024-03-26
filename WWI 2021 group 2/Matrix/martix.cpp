#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int root[1000010];
int il[10000010];

struct triple{
    int first;
    int second;
    int third;
};

bool cmp(triple a, triple b){
    return a.third > b.third;
}

int Find (int a) {
    if (root[a]==a){
        return a;
    }
    root[a] = Find (root[a]);
    return (root[a]);
}

void Union(int a,int b){
    int x, y;
    x = Find(a);
    y = Find(b);
    if(x == y){
        return;
    }
    root[x] = root[y];
    il[y]=il[y]+il[x];
}


triple Street[1000001];
vector<int> questions;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // n-ogolna ilosc wierzcholkow m-krawedzie k-ilosc wierzcholkow zainteresowania
    int n,m,k;
    cin >> n >> m >> k;
    if(k==1){
        cout << "KEEP CALM AND FOLLOW THE WHITE RABBIT";
        return 0;
    }
    for (int i = 1; i <= n; i++){
        root[i] = i;
    }
    for(int i = 0 ;i<k;i++){
        int x;
        cin >> x;
        il[x]=1;
        questions.push_back(x);
    }
    for(int i = 0;i<m;i++){
        cin >> Street[i].first;
        cin >> Street[i].second;
        cin >> Street[i].third;
    }
    sort(Street,Street+m,cmp);
    /*wypisywanie posortowanych drog
    for(int i = 0;i<m;i++){
        cout << Street[i].first << " ";
        cout << Street[i].second << " ";
        cout << Street[i].third << "\n";
    }
    */
    for(int i=0;i<m;i++){

        Union(Street[i].first,Street[i].second);
        if(il[Find(questions[0])]==k){
            cout << Street[i].third-1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}