#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct node{
	ll suma;
	ll maxleft;
	ll maxright;
	ll maxi;
};

const int base  = 1<<18;
node tree[base<<1];

void update(int y, int w){
	y += base;
	ll zer = 0;
	tree[y].suma += w;
    tree[y].maxleft = max(tree[y].suma, zer);
	tree[y].maxright = max(tree[y].suma, zer);
	tree[y].maxi = max(tree[y].suma, zer);
	y/=2;
	while (y != 0){
		tree[y].suma = tree[y*2].suma + tree[y*2+1].suma;
		tree[y].maxleft = max(tree[y*2].maxleft, tree[y*2].suma + tree[y*2+1].maxleft);
		tree[y].maxright = max(tree[y*2+1].maxright, tree[y*2+1].suma + tree[y*2].maxright);
		tree[y].maxi = max(tree[y*2].maxi, tree[y*2+1].maxi);
		tree[y].maxi = max(tree[y].maxi, tree[y*2].maxright + tree[y*2+1].maxleft);
		y/=2;
	}
}

int main(){
    ll n,m,k,d;
    cin >> n >> m >> k >> d;
	for(int i = 0; i <= n-d; i++){
        update(i, -1*k);
	}
	for(int i = 0;i<m;i++){
		int a,b;
		cin >> a >> b;
		update(a, b);
		if (tree[1].maxi <= d*k)
			puts("TAK");
		else
			puts("NIE");
	}
}