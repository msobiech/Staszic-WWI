#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int slowo1[2003];
int slowo2[2003];
int n,m;
int dp[2003];
int poprz[2003];

int LCIS(){
    int dp[m], poprz[m];
    for(int j = 0;j<m;j++){
        dp[j] = 0;
    }
    for(int i = 0;i<n;i++){
        int cur = 0,last = -1;
        for(int j = 0;j<m;j++){
            if(slowo1[i] == slowo2[j]){
                if(cur + 1 > dp[j]){
                    dp[j] = cur + 1;
                    poprz[j] = last;
                }
            }
            if(slowo1[i] > slowo2[j]){
                if (dp[j] > cur){
                    cur = dp[j];
                    last = j;
                }
            }
        }
    }
    int result = 0, id = -1;
    for(int i=0; i<m; i++){
        if(dp[i] > result){
           result = dp[i];
           id = i;
        }
    }

    for (int i=0; id != -1; i++){
        ans.push_back(slowo2[id]);
        id = poprz[id];
    }
    return result;
}
int main()
{
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        cin >>slowo1[i];
    }
    for(int i = 0;i<m;i++){
        cin >>slowo2[i];
    }
    cout << LCIS() << endl;
    reverse(ans.begin(),ans.end());
    int anssiz = ans.size();
    for(int i = 0;i<anssiz;i++){
        cout << ans[i] << " ";
    }
    return (0);
}