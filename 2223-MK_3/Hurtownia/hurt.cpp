#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 25e4+4;
int dos[MAXN];
int zam[MAXN];
priority_queue<int> zamow;
int main(){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> dos[i];
    }
    for(int i = 0;i<n;i++){
        cin >> zam[i];
    }
    long long licz = 0;
    for(int i = 0;i<n;i++){
        licz+=dos[i];
        if(licz>=zam[i]){
            licz-=zam[i];
            zamow.push(zam[i]);
        }
        else{
            if(!zamow.empty()){
                if(zamow.top()>zam[i]){
                    licz+=zamow.top();
                    zamow.pop();
                    licz-=zam[i];
                    zamow.push(zam[i]);
                }
            }
        }
    }
    cout << zamow.size() << endl;
}