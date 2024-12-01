#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int p = 997;
const int q = 1213;
constexpr int MAXN = 8e2+4;
constexpr int MOD = 1e9+7;
ll H[MAXN][MAXN];
ll Hkey[MAXN][MAXN];
ll input[MAXN][MAXN];
ll key[MAXN][MAXN];
ll potp[MAXN];
ll potq[MAXN];

void printHash(int n,int m, int a, int b){
	for(int i = 1;i<=a;i++){
		for(int j = 1;j<=b;j++){
			cout << H[i][j] << " ";
		}
		cout << endl;
	}
	cout << " --------KEY-------\n";
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			cout << Hkey[i][j] << " ";
		}
		cout << endl;
	}
}

int Hval(int a,int b, int x, int y){
    int val = H[x][y];
    val = ((val-(H[a-1][y]*potp[x-a+1]))%MOD+MOD)%MOD;
    val = ((val-(H[x][b-1]*potq[y-b+1]))%MOD+MOD)%MOD;
    val = (val+(((H[a-1][b-1]*potp[x-a+1])%MOD)*potq[y-b+1])%MOD)%MOD;
	return val;
}

int Hkeyval(int a,int b, int x, int y){
	int val = Hkey[x][y];
    val = ((val-(Hkey[a-1][y]*potp[x-a+1]))%MOD+MOD)%MOD;
    val = ((val-(Hkey[x][b-1]*potq[y-b+1]))%MOD+MOD)%MOD;
    val = (val+(((Hkey[a-1][b-1]*potp[x-a+1])%MOD)*potq[y-b+1])%MOD)%MOD;
	return val;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	potp[0] = 1;
	potq[0] = 1;
	for(int i = 1;i<MAXN;i++){
		potp[i] = potp[i-1]*p%MOD;
		potq[i] = potq[i-1]*q%MOD;
	}
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		string in1;
		cin >> in1;
		for(int j = 1;j<=m;j++){
			key[i][j] = in1[j-1];
		}
	}
	int a,b;
	cin >> a >> b;
	for(int i = 1;i<=a;i++){
		string in1;
		cin >> in1;
		for(int j = 1;j<=b;j++){
			input[i][j] = in1[j-1];
		}
	}
	for(int i = 1;i<=a;i++){
		for(int j = 1;j<=b;j++){
			H[i][j] = ((((H[i-1][j]*p) - (H[i-1][j-1]*p*q))%MOD)+MOD)%MOD;
			H[i][j] += (H[i][j-1]*q)%MOD;
			H[i][j] += (input[i][j])%MOD;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			Hkey[i][j] = ((((Hkey[i-1][j]*p) - (Hkey[i-1][j-1]*p*q))%MOD)+MOD)%MOD;
			Hkey[i][j] += (Hkey[i][j-1]*q)%MOD;
			Hkey[i][j] += (key[i][j])%MOD;
		}
	}

    //cout << Hkeyval(1,1,2,3) << " " << Hval(3,3,4,5) << endl;


	vector<pair<int,int>> ans;
	for(int i = 1;i+n-1<=a+1;i++){
		for(int j = 1;j+m-1<=b+1;j++){
		    //cout << i << ": " << j << endl;
            //cout << Hkeyval(1,1,n,m) << " "  << Hval(i,j,i+n-1,j+m-1) << endl;
			if(Hkeyval(1,1,n,m)==Hval(i,j,i+n-1,j+m-1)){
				ans.push_back({i,j});
			}
		}
	}
	cout << ans.size() << endl;
	for(auto g:ans){
		cout << g.first << " " << g.second << '\n';
	}
	return 0;
}

/*
2 3
abc
bca
4 5
xxxxx
xxxxx
xxabc
xxbca
*/