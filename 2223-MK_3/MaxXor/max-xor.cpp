#include <iostream>
#include <climits>
using namespace std;

struct node{
	int val;
	node* child[2];
	node(){
		this->val = 0;
		this->child[0] = nullptr;
		this->child[1] = nullptr;
	}
};

class trie{

public:
	node root;
	///INSERT
	void insert(int p){
		node* temp = &this->root;
		for(int i = 31; i >= 0; i--){
			bool cur = p & (1 << i);
			if(temp->child[cur] == nullptr){
                temp->child[cur] = new node();
			}
			temp = temp->child[cur];
		}
		temp->val = p;
	}


	///QUERY
	int query(int p){
		node* temp = &this->root;
		for(int i = 31; i >= 0; i--){
			bool cur = p & (1 << i);
			if(temp->child[!cur] != nullptr){
				temp = temp->child[!cur];
			}
			else if(temp->child[cur] != nullptr){
				temp = temp->child[cur];
			}

		}
		return p ^ temp->val;
	}

};

inline bool isint(char c){
    if(c >= '0' && c<='9'){
        return true;
    }
    else{
        return false;
    }
}
inline int readint(){
    char c;
    int x = 0;
    while(!isint(c = getchar_unlocked())){
    }
    do{
        x=x*10+int(c-'0');
    }while(isint(c = getchar_unlocked()));
    return x;

}

int res = INT_MIN;
int pre = 0;

int main(){
	int n, x;
	n = readint();
	trie tree;
	tree.insert(0);

	for(int i = 0;i<n; i++){
		x = readint();
		pre ^= x;
		tree.insert(pre);
		res = max(tree.query(pre),res);
	}
	cout << res << '\n';
}