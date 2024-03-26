#include <iostream>
using namespace std;
int base = 1<<20;
int drz[1<<21+1];
bool bulbs[1000001];
//do zapisywania zakresow sr = (A+B)/2  lewy syn A - sr ||  prawy syn sr+1 - B
bool read(int x){
    x+=base;
    int amount_of_changes=0;
    while (x>1){
        amount_of_changes+=drz[x];
        x/=2;
    }
    if(amount_of_changes%2==0){
        return false;
    }
    else{
        return true;
    }
}
void sum(int x, int xa, int xb, int za, int zb){
    if(za<=xa && xb<=zb){
        drz[x]++;
        return;
    }
    int sr=(xa+xb)/2;
    if(za<=sr){
        sum(2*x,xa,sr,za,zb);
    }
    if(sr+1<=zb){
        sum(2*x+1,sr+1,xb,za,zb);
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    string states;
    cin >> states;
    for(int i = 1;i<=n;i++){
        if(states[i-1]=='x'){
            bulbs[i]=false;
        }
        else{
            bulbs[i]=true;
        }
    }
    char question;
    for(int i = 0;i<m;i++){
        cin >> question;
        if(question=='Q'){
            int a;
            cin >> a;
            if(read(a)){
                if(!bulbs[a]){
                    cout << "ON\n";
                }
                else{
                    cout << "OFF\n";
                }
            }
            else{
                if(bulbs[a]){
                    cout << "ON\n";
                }
                else{
                    cout << "OFF\n";
                }
            }
        }
        else{
            int a,b;
            cin >> a >> b;
            sum(1,0,base-1,a,b);
        }
    }
    return 0;
}