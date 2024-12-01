#include <iostream>
#include <set>
#include <math.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
constexpr int MAXN = 2e5+7;
int KMR[MAXN][19];
ordered_set S[21];
int powers[21];
int curlvl = 0;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
	int tmp = 1;
	powers[0] = tmp;
	for(int i = 1;i<21;i++){
		tmp*=2;
		powers[i] = tmp;
	}
    string input;
    cin >> input;
    n = input.size();
    for(int i = 0;i<n;i++){
        KMR[i][curlvl] = input[i]-'a'+1;
    }
    int curset = 0;
    int curpow = 1;
    int pop = n;
    int cur = n;
    while(curpow*2<=n && curset<21){
    	curpow*=2;
    	curlvl++;
    	cur = 0;
    	//cout << curlvl << " : " << curpow << endl;
    	for(int i = 0;i<n;i++){
            if(i+(curpow/2)<pop){
            	cur++;
                S[curset].insert({KMR[i][curlvl-1],KMR[i+(curpow/2)][curlvl-1]});
            	//cout << "{ " << KMR[i][curlvl-1] << " ; " << KMR[i+(curpow/2)][curlvl-1] << " } , ";
            }
        }
        for(int i = 0;i<n;i++){
            if(i+(curpow/2)<pop){
                KMR[i][curlvl] = S[curset].order_of_key({KMR[i][curlvl-1],KMR[i+(curpow/2)][curlvl-1]}) + 1;
            }
        }
        //cout << endl;
        pop = cur;
        curset++;
    }
    /*
    curpow = 1;
    curset = 0;
    pop = n;
    cur = n;
    while(curpow<=n){
    	cur = 0;
    	for(int i = 0;i<n;i++){
            if(i+(curpow/2)<pop){
            	cur++;
                cout << KMR[i][curset] << " ";
            }
            else{
            	cout << "# ";
            }
        }
        pop = cur;
        cout << endl;
        curpow*=2;
        curset++;
    }*/
    int q;
    cin >> q;
    for(int i = 0;i<q;i++){
    	int l1, l2, r;
    	cin >> l1 >> l2 >> r;
    	l1--;l2--;
    	int r1 = l1+r-1;
    	int r2 = l2+r-1;
    	int k = log2(r);
    	pair<int,int> a = {KMR[l1][k], KMR[r1-powers[k]+1][k]};
    	pair<int,int> b = {KMR[l2][k], KMR[r2-powers[k]+1][k]};
    	if(a<b){
    		cout << "<\n";
    	}
    	else if(a==b){
    		cout << "=\n";
    	}
    	else{
    		cout << ">\n";
    	}
    }
	
}