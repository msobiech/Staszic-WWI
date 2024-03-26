#include <iostream>
using namespace std;

int kmp[4000010];

int main() {
    //string key;
    string slowo;
    int n;
    cin >> slowo;

    slowo = "$"+slowo;
    n = slowo.size();
    kmp[0]=-1;
    kmp[1]=0;
    for(int nr = 2;nr<=n;nr++){
        int pos = kmp[nr-1];
        while(slowo[pos+1]!=slowo[nr] && pos>-1){
            pos=kmp[pos];
        }
        kmp[nr]=pos+1;

    }
    //int odp = 0;
    for(int i = 1;i<=n-1;i++){
        if(kmp[i]!=0){
            cout << 1;
        }
        else{
            cout << 0;
        }
        //cout << kmp[i];
    }
    //cout << odp;
    return 0;
}