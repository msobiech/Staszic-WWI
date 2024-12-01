#include <iostream>
#include <vector>
using namespace std;
constexpr int MAXN = 1e6+4;
int S[MAXN];

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

void sito(){
    int lim = 1000000;
	for(int i = 2;i<=lim;i++){
	    if(S[i]==0){
	        for(int j = i*2;j<=lim;j+=i){
	            S[j] = i;
	        }
	    }
	}
}

int main(){
    int n,u;
    n = readint();
    vector<int> dzielniki;
    sito();
    for(int k = 0;k<n;k++){
        u = readint();
        int licz = u;
        while(S[licz]!=0){
            dzielniki.push_back(S[licz]);
            licz = licz/S[licz];
        }
        dzielniki.push_back(licz);
        if(u!=1){
            int siz = dzielniki.size();
            for(int i = siz-1;i>=0;i--){
                cout << dzielniki[i] << " ";
              
            }
        }
        dzielniki.clear();
        cout << "\n";
    }
}