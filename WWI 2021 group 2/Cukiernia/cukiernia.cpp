#include <iostream>
using namespace std;

int tab[1000001];
int main() {
    int n;
    int k;
    cin >> n >> k;
    for(int i = 0;i<n;i++){
        int weight,price;
        cin >> weight >> price;
        for(int j = k;j>=0;j--){
            if(tab[j]!=0 || j==0) {
                tab[j+weight]=max(tab[j+weight],tab[j]+price);
            }
        }

    }
    /*
    for(int i = 0;i<=k+20;i++){
        cout << tab[i] << " ";
    }*/
    int max = 0;
    for(int i = 0;i<=k;i++){
        if(tab[i]>max){
            max = tab[i];
        }
    }
    cout << max;
    return 0;
}