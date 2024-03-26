#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<long long,bool> possible;
unordered_map<long long,bool> possible2;
int p = 997;//p = 997;
constexpr int mod = 1e9  + 9;
constexpr int mod2 = 1e9  + 7;
long long potp[100001];
long long potp2[100001];
long long hs[1000001];
long long hsk[1000001];
long long hs2[1000001];
long long hsk2[1000001];

int sum(int a, int b){
    if(a>0){
        return (hs[b]-hs[a-1]*potp[b-a+1]%mod+mod)%mod;
    }
    else{
        return hs[b];
    }

}

int sum2(int a, int b){
    if(a>0){
        return (hs2[b]-hs2[a-1]*potp2[b-a+1]%mod2+mod2)%mod2;
    }
    else{
        return hs2[b];
    }

}

void IsPossible(int dlk, int dls){//dlk - dlugosc klucza    dls - dlugosc slowa pierwotnego credit to Jan Ancuta za pomysl na mape
    for(int i = 0;i<dls-dlk+1;i++){
        possible[sum(i,i+dlk-1)] = true;
        possible2[sum2(i,i+dlk-1)] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    potp[0]=1;
    potp2[0]=1;
    for(int i = 1;i<100001;i++){
        potp[i]=potp[i-1]*p%mod;
        potp2[i]=potp2[i-1]*p%mod2;
    }
    string slowo;
    cin >> slowo;
    int ssiz = slowo.size();
    hs[0]=int(slowo[0]);
    hs2[0]=int(slowo[0]);
    for(int i = 1;i<ssiz;i++){
        hs[i]=(hs[i-1]*p+int(slowo[i]))%mod;
        hs2[i]=(hs2[i-1]*p+int(slowo[i]))%mod2;
    }
    int n;
    cin >> n;
    for(int u=0;u<n;u++){
        string key;
        int m;
        cin >> m;
        for(int j = 0;j<m;j++){
            int ksiz;
            if(j==0){
                cin >> key;
                ksiz = key.size();
                IsPossible(ksiz, ssiz);
            }
            else{
                cin >> key;
            }

            //int ksiz = key.size();
            hsk[0] = int(key[0]);
            hsk2[0] = int(key[0]);
            //cout << hsk[0] << " ";
            for(int i = 1;i<ksiz;i++){
                hsk[i]=(hsk[i-1]*p+int(key[i]))%mod;
                hsk2[i]=(hsk2[i-1]*p+int(key[i]))%mod2;
                //cout << hsk[i] << " ";
            }
            //cout << endl;
            bool c = false;
            if(possible[hsk[ksiz-1]]==true && possible2[hsk2[ksiz-1]]==true){
                cout << "OK\n";
            }
            else{
                cout << "NIE\n";
            }
        }

    }



    return 0;
}