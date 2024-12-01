#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;
#define MAXN 100005
#define MAXM 1000005


int ile = 1;
int n, m, a, b;
int st[MAXN];
int licz;
bool c,d;
bool vis[MAXN];

list<pair<int, int>> kraw[MAXN];
list<pair<int,int>>::iterator it[2 * MAXM];
stack<int> S;
vector<int> cykl;
vector<int> tmp;
vector<int> ans;
vector<int> dlg;


void print(){
	int akt;
	for(auto i = cykl.begin();i!=cykl.end();++i){
		if(vis[*i]){
			ans.push_back(*i);
			licz = 1;
			while(vis[*i]){
				akt = tmp.back();
				tmp.pop_back();
				ans.push_back(akt);
				licz++;
				vis[akt] = false;
			}	
			ans.push_back(0); // push przerwania cyklu
			dlg.push_back(licz);
		}
		tmp.push_back(*i);
		vis[*i] = true;
	}
	akt = 0;
	cout << dlg.size() << endl;
	for(auto g:dlg){
		cout << g-1 << " ";
		while(ans[akt]){
			cout << ans[akt] << " ";
			akt++;
		}
		cout << endl;
		akt++;
	}
}

void go(int x){
	int y;
	while(kraw[x].begin() != kraw[x].end()){
		S.push(x);
		y = kraw[x].begin()->first;
		kraw[y].erase(it[kraw[x].begin()->second]);
		kraw[x].pop_front();
		x = y;
	}	
}
inline bool isInt(char& c) {

    if (c >= '0' && c <= '9')return true;
    return false;
}

inline int readInt() {

    char c;
    int x = 0;
    int mult = 1;
    while (!isInt(c = getchar_unlocked()) && c != '-') {
    }
    do {
        if (c == '-') {
            mult = -1;
        }
        else {
            x = x * 10 + int(c - '0');
        }

    } while (isInt(c = getchar_unlocked()) || c == '-');
    return x * mult;
}

int main(){
	n=readInt(); m=readInt();
	for(int i = 0;i<m;i++){
		a=readInt();b=readInt();c=readInt();d=readInt();
		if(c != d){
			kraw[a].push_front({b,ile});
			kraw[b].push_front({a,ile+1});
			it[ile++] = kraw[b].begin(); it[ile++] = kraw[a].begin();
			st[a]++;st[b]++;
		}	
	}
	for(int i = 1; i<=n; i++){
		if(st[i] & 1){
			cout << "NIE\n";
			return false;
		}
	}
	for(int i = 1;i<=n;i++){
		if(kraw[i].begin() != kraw[i].end()){
			S.push(i);
			while(!S.empty()){
				int x = S.top(); 
				S.pop();
				cykl.push_back(x);
				go(x);
			}
		}
	}
	print();
	return 0;
}