#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> gcds;
int nwd;
void gcdsg(int a, int b){
    if(b!=0){
        gcds.push_back({a,b});
        gcdsg(b,a%b);
    }
    else{
        nwd = a;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    while(cin>>a){
        if(a==-100){
            return 0;
        }
        int b,c,d;
        cin >> b >> c >> d;
        int g = d-c;
        int x1 = 1;
        int y1 = 0;
        gcdsg(a,b);
        while(!gcds.empty()){
            pair<int,int> para = gcds.back();
            int x2 = y1;
            int y2 = (x1-y1*int(para.first/para.second));
            x1 = x2;
            y1 = y2;
            gcds.pop_back();
        }
        int p1 = int(g/nwd) * nwd;
        int p2 = int(g/nwd) * nwd + nwd;
        int p3 = int(g/nwd) * nwd - nwd;
        if(abs(p1-g) <= abs(p2-g) && abs(p1-g) <= abs(p3-g)){
            cout << x1*(int(g/nwd)) << " " << y1*(int(g/nwd)) << endl;
        }
        else if(abs(p2-g) <= abs(p1-g) && abs(p2-g) <= abs(p3-g)){
            cout << x1*(int(g/nwd)+1) << " " << y1*(int(g/nwd)+1) << endl;
        }
        else{
            cout << x1*(int(g/nwd)-1) << " " << y1*(int(g/nwd)-1) << endl;
        }
        //cout << x1 << " " << y1 << " :: " << nwd << endl;


    }
}


//  x * a + y * b = g
//  x1 * b + y1 * (a%b) = g
//  y1 + a + (x1-y1*floor(a/b)) * b = g
//  ||            ||
//  x              y