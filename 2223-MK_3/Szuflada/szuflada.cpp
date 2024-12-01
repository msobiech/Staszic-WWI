#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

void z_function(string s,int Z[]) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i<=r){
            Z[i]=min(r-i+1,Z[i-l]);
        }
        while (i+ Z[i] < n && s[Z[i]] == s[i + Z[i]]){
            Z[i]++;
        }
        if (i+Z[i]-1>r){
            l=i,r=i+Z[i]-1;
        }
    }
}
const int MAXN = 2e6+6;
int prefx[MAXN];
int sufx[MAXN];
int sha[MAXN];
int sumy[MAXN];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
    int n,m;
    string s,t;
    cin >> t >> s;
    n = s.size();m = t.size();
    z_function(s,sha);
    int mult = 1;
    for(int i = 0;i<n;i++){
        if(sha[i]+i==n){
            mult=n/i;
            break;
        }
    }
    string s2 = s+'$'+t;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    string s3 = s+'$'+t;
    z_function(s2,prefx);
    z_function(s3,sufx);
    reverse(sufx,sufx+n+m+1);
    vector<int> nsufx;
    for(int i = n+1;i<n+m+1;i++){
        nsufx.push_back(prefx[i]);
    }
    /*
    cout << "sufx\n";
    for(int i = 0;i<n+m+1;i++){
        cout << sufx[i] << " ";
    }
    cout << "\nnsufx\n";
    for(auto i:nsufx){
        cout << i << " ";
    }
    cout << endl;
    cout << "prefx\n";
    for(int i = 0;i<n+m+1;i++){
        cout << prefx[i] << " ";
    }
    cout << endl;*/
    if(nsufx[0]>=n){
        sumy[0] = 1;
        sumy[nsufx[0]-n+1] = -1;
    }
    for(int i = 1;i< int(nsufx.size());i++){
        //cout << sufx[i] << " + " << prefx[i+1] << endl;
        if(sufx[i-1]+nsufx[i]>=n){
            int pocz = i-sufx[i-1];
            int kon = i+nsufx[i]-n+1;
            //cout << pocz << " --- " << pocz+dlprz << endl;
            sumy[pocz]+=1;
            sumy[kon]-=1;
        }
    }
    for(int i = 1;i<m;i++){
        sumy[i] = sumy[i-1]+sumy[i];
    }
    for(int i = 0;i<m;i++){
        if(sumy[i]){
            cout << "TAK\n";return 0;
        }
        
    }
    cout << "NIE\n";
    //reverse(s.begin(),s.end());
    //z_function(s,sufi);
    return 0;
}