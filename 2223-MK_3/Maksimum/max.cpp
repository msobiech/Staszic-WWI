#include <iostream>
using namespace std;

int n,m;
const int base = 262144;
int tree[base*2+1];

void update(int x, int y){
    y+=base;
    tree[y] = x;
    y/=2;
    while(y>=1){
        tree[y] = max(tree[y*2],tree[y*2+1]);
        y/=2;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        update(x,i);
    }
    cout << tree[1] << endl;
    for(int i = 0;i<m;i++){
        int a,b;
        cin >> a >> b;
        update(b,a-1);
        cout << tree[1] << endl;
    }
}