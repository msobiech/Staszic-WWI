#include <iostream>
#include <iomanip>
using namespace std;
int ciag[1000001];

int n;
bool odp(int x){
    int h = ciag[0]-x;
    //cout << "start " << h << endl;
    for(int i = 1;i<n;i++){
        int akt = ciag[i]+x;
        //cout << "aktualne " << akt << endl;
        if(h>akt){
            return false;
        }
        else{
            akt=ciag[i]-x;
            h=max(h,akt);
        }
    }
    return true;

}

int bsearch(int l, int p){
    int sr;
    while(p-l>1){

        sr = (l + p)/2;
        //cout << l << " " << p << " " << sr << endl;

        if(odp(sr)){
            p=sr;
        }
        else{
            l=sr;
        }
    }
    if(odp(l)){
        return l;
    }
    else{
        return p;
    }
}

int main() {
    cin >> n;
    for(int i = 0;i<n;i++){
        int a;
        cin >> a;
        ciag[i]=a*2;
    }
    double help = bsearch(0,2000001);
    double ans = help/2;
    //cout << odp(3);
    cout << setprecision(3) << fixed <<  ans << '\n';
    double u = ciag[0]/2;
    cout << setprecision(3) << fixed <<  u-ans << '\n';
    double poprzedni = u-ans;
    for(int i = 1;i<n;i++){
        if(double(ciag[i]/2)<poprzedni){
            double u = ciag[i]/2;
            cout << setprecision(3) << fixed <<  u+ans << '\n';
            poprzedni = u+ans;
        }
        else if(double(ciag[i]/2)==poprzedni){
            cout << setprecision(3) << fixed <<  poprzedni << '\n';
        }
        else{
            double u = ciag[i]/2;
            cout << setprecision(3) << fixed <<  u-ans << '\n';
            poprzedni = u-ans;
        }
    }

}