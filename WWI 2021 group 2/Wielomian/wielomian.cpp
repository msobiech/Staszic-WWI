#include <bits/stdc++.h>

using namespace std;

double a0,a1,a2,a3,a4,a5,p,k,sr,actual_w;
bool odp=true;

double bin(double x){
    double suma;
    double act=1;
    suma+=a0;
    act*=x;
    suma+=a1*act;
    act*=x;
    suma+=a2*act;
    act*=x;
    suma+=a3*act;
    act*=x;
    suma+=a4*act;
    act*=x;
    suma+=a5*act;
    return suma;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a5>>a4>>a3>>a2>>a1>>a0;
    if (a5<0){
        a5*=-1;
        a4*=-1;
        a3*=-1;
        a2*=-1;
        a1*=-1;
        a0*=-1;
    }
    p=-10;
    k=10;
    while(true){
        sr=(p+k)/2;
        //cout<<p<<" "<<k<<" "<<sr<<" "<<bin(sr)<<" "<<endl;
        actual_w=bin(sr);
        if(actual_w<0.0001 && actual_w>-0.0001){
            cout<<sr;
            break;
        } else if(actual_w>=0.0001){
            k=sr;
        }else{
            p=sr;

        }
    }


}