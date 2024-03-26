#include <iostream>
using namespace std;
int tab[5001][5001];
int dir[5001][5001];
int main() {
    string a,b;
    cin >> a >> b;
    a="@"+a;
    b="#"+b;
    int as = a.size();
    int bs = b.size();
    //1 - strzalka z gory 2-strzalka z lewo 3-wjazd z ukosu
    for(int i = 1;i<bs;i++){
        for(int j = 1;j<as;j++){
            int lewo = tab[i][j-1];
            int gora = tab[i-1][j];
            int skos = tab[i-1][j-1];
            if(a[j]==b[i]){
                int maksimum = max(lewo,max(gora,skos+1));
                if(maksimum == skos+1){
                    tab[i][j] = skos+1;
                    dir[i][j] = 3;
                }
                else{
                    if(gora<lewo){
                        tab[i][j]=lewo;
                        dir[i][j]=2;
                    }
                    else{
                        tab[i][j]=gora;
                        dir[i][j]=1;
                    }
                }
            }
            else{
                if(gora<lewo){
                    tab[i][j]=lewo;
                    dir[i][j]=2;
                }
                else{
                    tab[i][j]=gora;
                    dir[i][j]=1;
                }
            }
        }
    }
    string odp;
    int pozy = bs-1;
    int pozx = as-1;
    while(pozy != 0 && pozx!=0){
        if(dir[pozy][pozx]==3){
            odp+=a[pozx];
            pozy--;
            pozx--;

        }
        else if(dir[pozy][pozx]==1){
            pozy--;
        }
        else{
            pozx--;
        }
    }

/*
    for(int i = 1;i<bs;i++){
        for(int j = 1;j<as;j++){
            cout << dir[i][j] << " ";

        }
        cout << endl;
    }*/
    cout << tab[bs-1][as-1] << endl;
    for(int i = odp.size()-1;i>=0;i--){
        cout << odp[i];
    }
    //cout << odp;
}