#include <iostream>
using namespace std;

int kmp[4000010];

int main() {
    string key;
    string slowo;
    int n;
    cin >> key >> slowo;
    int m = key.size();

    slowo = "#"+ key +"$"+slowo;
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
    int odp = 0;
    for(int i = 0;i<=n;i++){
        if(kmp[i]==m){
            odp++;
        }
    }
    cout << odp;
    return 0;
}