#include <iostream>
#include <climits>
using namespace std;

long long n,m;
const long long base = 1<<17;
int tree[4][base*2+1];
long long input[base+1];
void add(int y, int x, int id){
    y+=base;
    tree[id][y] += x;
    y/=2;
    while(y>=1){
        tree[id][y] = tree[id][y*2]+tree[id][y*2+1];
        y/=2;
    }
}

int read(int a, int b,int id){
    a+=base-1;
    b+=base+1;
    int sum = 0;
    while(b-a>1){
        if(!(a&1)){
            sum+=tree[id][a+1];
        }
        if(b&1){
            sum+=tree[id][b-1];
        }
        a/=2;b/=2;
    }
    return sum;


}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    long long n,q;
    cin >> n >> q;
    for(int i = 0;i<n;i++){
    	for(int j = 0;j<=3;j++){
            add(i,1,j);
    	}
    }
    while(q--){
        string z;
        cin >> z;
        if(z[0]=='D'){
            int a,b;
            cin >> a >> b;
            a--;
            long long pop = input[a];
            input[a]+=b;
            for(int i = 2;i<=5;i++){
                if(input[a]%i==0){
                    if(pop%i!=0){
                        add(a,1,i-2);
                    }
                }
                else{
                    if(pop%i==0){
                        add(a,-1,i-2);
                    }
                }
            }
        }
        else{
            int a,b,id;
            cin >> a >> b >> id;
            a--;b--;id-=2;
            if(id>=0){
                 cout << read(a,b,id) << endl;
            }
            else{
                cout << b-a+1 << endl;
            }

        }
    }
}