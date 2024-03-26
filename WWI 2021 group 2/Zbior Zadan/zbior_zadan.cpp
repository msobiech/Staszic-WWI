#include <iostream>
#include <algorithm>
using namespace std;
int dl[1000002];
int inf = 2147000000;
int main(){
    dl[0] = -inf;
    for(int i = 1;i<=1000001;i++){
        dl[i]=inf;
    }
    int n;
    cin >> n;
    int maxi = 0;
    int x;
    cin >> x;
    dl[1]=x;
    for(int i = 1;i<n;i++){
        cin >> x;
        int lower = lower_bound(dl,dl+n,x)-dl;
        //cout << "lower " << lower << " " << x << endl;
        /*
        if(dl[lower=x){
            if(dl[lower-1]>=x){
                cout << "zmieniam " << lower-1 << " na " << x << endl;
                dl[lower-1]=x;
                maxi = max(lower-1,maxi);
            }

        }*/
        if(dl[lower]>=x){
            //cout << "zmieniam " << lower << " na " << x << endl;
            dl[lower]=x;
            maxi = max(lower ,maxi);
        }
    }
    /*
    for(int i = 0;i<n;i++){
        cout << dl[i] << " ";

    }*/
    cout << maxi;
}