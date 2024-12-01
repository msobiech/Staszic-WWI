#include <iostream>
using namespace std;
string ciag;

void swapy(int x){
    if(ciag[x-1]=='1'){
        ciag[x-1]='0';
    }
    else{
        ciag[x-1]='1';
    }
}
int main(){

    int n,m;
    cin >> n >> m;
    cin >> ciag;
    char pop = ciag[0];
    int odp = 1;;
    for(int i = 1;i<n;i++){
        if(ciag[i]!=pop){
            odp++;
            pop = ciag[i];
        }
    }
    cout << odp << " ";
    for(int i = 0;i<m;i++){
        int x;
        cin >> x;
        swapy(x);
        if(x==n){
            if(ciag[x-1]==ciag[x-2]){
                odp--;
            }
            else{
                odp++;
            }
        }
        else if(x==1){
            if(ciag[x-1]==ciag[x]){
                odp--;
            }
            else{
                odp++;
            }
        }
        else if(ciag[x-2]==ciag[x] && ciag[x-1]==ciag[x]){
            odp-=2;

        }
        else if(ciag[x-2]==ciag[x] && ciag[x-1]!=ciag[x]){
            odp+=2;
        }
        cout << odp << " ";
    }
}