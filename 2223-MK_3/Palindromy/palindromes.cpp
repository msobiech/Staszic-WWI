#include <iostream>
#include <vector>
using namespace std;

vector<int> manacher(string s, int n) {
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

int main(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    string fin;
    for(auto g: a) {
        fin += string("#") + g;
    }
    fin+="#";
    vector<int> ans = manacher(fin,n*2+1);
    for(int i = 1;i<ans.size()-1;i++){
        cout << ans[i]-1 << " ";
    }
}