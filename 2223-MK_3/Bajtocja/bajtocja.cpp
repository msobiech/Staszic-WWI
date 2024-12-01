#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct triple{
    int first;
    int second;
    int third;
    int id;
};

bool cmp(triple a, triple b){
    return a.third < b.third;
}


int root[200001];
triple krawedzie[300001];
string odp[300001];
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
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        root[i] = i;
    }
    for(int i = 0;i<m;i++){
        cin >> krawedzie[i].first;
        cin >> krawedzie[i].second;
        cin >> krawedzie[i].third;
        krawedzie[i].id = i;
    }
    sort(krawedzie,krawedzie+m,cmp);
    /*
    for(int i = 0;i<m;i++){
        cout << krawedzie[i].first << " " <<  krawedzie[i].second << " " << krawedzie[i].third << endl;
    }*/

    vector <int> ram;
    int aktdl = krawedzie[0].third;
    for(int i = 0;i<m;i++){
        //cout << "Przegladam krawedz pomiedzy " << krawedzie[i].first << " i " << krawedzie[i].second << endl;
        if(krawedzie[i].third==aktdl){
          //  cout << "Rooty tych punktow to " << Find(krawedzie[i].first) << " i " << Find(krawedzie[i].second) << endl;
            if(Find(krawedzie[i].first)!=Find(krawedzie[i].second)){
                odp[krawedzie[i].id]="TAK";
                ram.push_back(i);
            }
            else{
                odp[krawedzie[i].id]="NIE";
            }

        }
        else{
          //  cout << "Rooty tych punktow to " << Find(krawedzie[i].first) << " i " << Find(krawedzie[i].second) << endl;
            int siz = ram.size();
            for(int j = 0;j<siz;j++){
              //  cout << "Lacze " << krawedzie[ram[j]].first << " " << krawedzie[ram[j]].second << endl;
                Union(krawedzie[ram[j]].first,krawedzie[ram[j]].second);
            }
            ram.clear();
            aktdl = krawedzie[i].third;
            if(Find(krawedzie[i].first)!=Find(krawedzie[i].second)){
                odp[krawedzie[i].id]="TAK";
                ram.push_back(i);
            }
            else{
                odp[krawedzie[i].id]="NIE";
            }
        }
    }
    for(int i = 0;i<m;i++){
        cout << odp[i] << endl;
    }


    return 0;
}