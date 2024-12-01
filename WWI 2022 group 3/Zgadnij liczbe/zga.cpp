#include <iostream>
#include <cmath>
#include "zga.h"
#include <stack>
using namespace std;
const int MAXN = 1000006;
//int tab[7] = {1,3,2,4,7,5,6};
stack<int> jedynki[21];
stack<int> zera[21];
/*
int zapytaj(int n, int i){
    //cout << "pytanie o bit " << i << " liczby " << tab[n] << endl;
    //cout << ((tab[n] >> i) & 1) << endl;
    //cout << (tab[i]&1 << i) << endl;
    return ((tab[n] >> i) & 1);
}*/
int main() {
    int n = init();
    //cout << ((2 >> 1) & 1) << endl;
    int maxi = (int)log2(n)+1;
    //cout << maxi << "\n";
    int ans = 0;

    for(int i = 0;i<n-1;i++){
        int res = zapytaj(i,0);
        if(res){
            jedynki[0].push(i);
        }
        else{
            zera[0].push(i);
        }
    }
    int pat = 0;
    int doliczaczero = 1;
    if(n%2==0){
        if(zera[0].size()>jedynki[0].size()){
            int mask=(1<<0);
            ans=ans|mask;
            //cout << "na bicie 0 mam " << 1 << endl;
            pat = 1;
            doliczaczero = 0;
        }
        else{
            int mask=(0<<0);
            ans=ans|mask;
            //cout << "na bicie 0 mam " << 0 << endl;
            pat = 0;
            //doliczaczero = 0;
        }
    }
    else{
        if(zera[0].size()>=jedynki[0].size()){
            int mask=(1<<0);
            ans=ans|mask;
            //cout << "na bicie 0 mam " << 1 << endl;
            pat = 1;
            doliczaczero = 0;
        }
        else{
            int mask=(0<<0);
            ans=ans|mask;
            //cout << "na bicie 0 mam " << 0 << endl;
            pat = 0;
        }
    }

    for(int i = 1;i<maxi;i++){
        if(pat){
            while(!jedynki[i-1].empty()){
                int top = jedynki[i-1].top();
                jedynki[i-1].pop();
                int res = zapytaj(top,i);
                if(res){
                    jedynki[i].push(top);
                }
                else{
                    zera[i].push(top);
                }
            }

        }
        else{
            //int siz = zera[i-1].size();
            while(!zera[i-1].empty()){
                int top = zera[i-1].top();
                zera[i-1].pop();
                int res = zapytaj(top,i);
                if(res){
                    jedynki[i].push(top);
                }
                else{
                    zera[i].push(top);
                }
            }

        }
        if(n%2==0){
            if(zera[i].size()+doliczaczero>jedynki[i].size()){
                int mask=(1<<i);
                ans=ans|mask;
                //cout << "na bicie " << i << " mam " << 1 << endl;
                pat = 1;
                doliczaczero = 0;
            }
            else{
                int mask=(0<<i);
                ans=ans|mask;
                //cout << "na bicie " << i << " mam " << 0 << endl;
                pat = 0;
            }
        }
        else{
            if(zera[i].size()+doliczaczero>=jedynki[i].size()){
                int mask=(1<<i);
                ans=ans|mask;
                //cout << "na bicie " << i << " mam " << 1 << endl;
                pat = 1;
                doliczaczero = 0;
            }
            else{
                int mask=(0<<i);
                ans=ans|mask;
                //cout << "na bicie " << i << " mam " << 0 << endl;
                pat = 0;
            }
        }

    }
    odpowiedz(ans);
}