#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> G[500*1000+10];
map<string,int> M;
int id = 1;
bool odw[100001];
int poz[1000001];
int pozlca[1000001];
int prz[100001][21];//prz[v][i] skok z v o 2^i w gore

void init(string nazwa){
    M[nazwa]=id;
    id++;

}

void nowa_osada(string nowa, string stara, int dlugosc){
    M[nowa] = id;
    id++;
    int id_new = M[nowa];
    int id_old = M[stara];
    pozlca[id_new] = pozlca[id_old]+1;
    poz[id_new] = poz[id_old]+dlugosc;
    prz[id_new][0]=id_old;
    for(int i = 1;i<=20;i++){
        prz[id_new][i] = prz[prz[id_new][i-1]][i-1];
    }
}




int lca(int a,int b){
    if(pozlca[a]<pozlca[b]){
        swap(a,b);
    }
    //dopasowywanie poziomow
    for(int i = 20;i>=0;i--){
        if(pozlca[prz[a][i]]>=pozlca[b]){
            a = prz[a][i];
        }
    }
    if(a==b){
        return a;
    }
    for(int i = 20;i>=0;i--){
        if(prz[a][i]!=prz[b][i]){
            a = prz[a][i];
            b = prz[b][i];
        }
    }
    return prz[a][0];
}


int odleglosc(string pierwsza, string druga){
    int id_first = M[pierwsza];
    int id_second = M[druga];
    int odp = poz[id_first]+poz[id_second]-2*(poz[lca(id_first,id_second)]);
    return odp;
}