#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN = 6e5+10;
int p[MAXN];

int main() {
	int m;
	cin >> m;
	string in1;
	string in2;
	cin >> in1 >> in2;
	string patt = "#" + in2 + "&" + in1 + in1;
	//cout << patt << endl;
	int n = patt.size();
	p[0] = -1;
	p[1] =  0;
	for(int i = 2;i<=n;i++){
        int pos = p[i-1];
        while(patt[pos+1]!=patt[i] && pos>-1){
            pos=p[pos];
        }
        p[i]=pos+1;
    }
    int odp = 0;
    vector<int> dl;
    for(int i = 0;i<=n;i++){
        if(p[i]==m){
            odp++;
            dl.push_back(i-m-1-m);
        }
    }
    cout << odp << endl;
    for(auto g:dl){
    	cout << g << " ";
    }
	return 0;
}