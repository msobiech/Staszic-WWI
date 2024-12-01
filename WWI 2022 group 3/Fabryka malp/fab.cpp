#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int wers[5][1000003];
int tab[200005];
bool cmp(int a, int b){
    int aprzedb = 0;
    for(int i = 0;i<5;i++){
        if(wers[i][a]<wers[i][b]){
            aprzedb++;
        }
    }
    if(aprzedb>=3){
        return true;
    }
    return false;
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
map<int,int> M;
int orders[1000006];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = readint();
    int order = 1;
    for(int i = 0;i<n;i++){
        int x = readint();;
        M[x]=order;
        tab[i] = order;
        wers[0][order]=i;
        orders[order]=x;
        order++;
    }
    for(int i = 1;i<5;i++){
        for(int j = 0;j<n;j++){
            int x = readint();;
            wers[i][M[x]]=j;
        }
    }
    sort(tab,tab+n,cmp);
    for(int i = 0;i<n;i++){
        cout << orders[tab[i]] << " ";
    }
    return 0;
}