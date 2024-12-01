#include <iostream>
using namespace std;

constexpr int MAXN = 2e5+7;
int p[MAXN];

int main() {
	string input;
	cin >> input;
	int n = input.size();
	for(int i = 1;i < n;i++) {
        int j = p[i-1];
        while(j > 0 && input[i] != input[j]){
        	j = p[j-1];
        }
		if (input[i] == input[j]){
        	j++;
        }
            
        p[i] = j;
    }
    for(int i = 0;i<n;i++){
    	cout << p[i] << " ";
    }
}