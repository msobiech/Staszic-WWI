#include <iostream>
using namespace std;

int dp[5002][5002];
string s,t;
int procedure(int ida, int idb){
    if(s[ida]==t[ida] && s[idb]==t[idb] && t[ida]!=t[idb]){
        return -2;
    }
    else if(s[ida]==t[ida] && s[idb]==t[idb]){
        return 0;
    }
    else if(s[ida]==t[ida] || s[idb]==t[idb]){
        if(s[ida] != s[idb]&& t[ida]!=t[idb]){
            return -1;
        }
        else{
            return 0;
        }
    }
    else if(s[ida]==t[idb] && s[idb]==t[ida]){
        return 2;
    }
    else if(s[ida]==t[idb]||s[idb]==t[ida]){
        return 1;
    }
    else{
        return 0;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    cin >> s >> t;
    int sum = 0;

    for(int i = 0;i<n;i++){
        if(s[i]==t[i]){
            sum++;
        }
    }
    int ans = sum;
    pair<int,int>idans = {0,0};
    for(int i = 0;i<n;i++){
        dp[i][i]=sum;

    }
    for(int i = 0;i<n-1;i++){
        if(s[i]==t[i] && s[i+1]==t[i+1] && t[i]!=t[i+1]){
            dp[i][i+1]=dp[i][i]-2;
            if(dp[i][i+1]>ans){
                ans = dp[i][i+1];
                idans = {i,i+1};
            }
        }
        else if(s[i]==t[i] && s[i+1]==t[i+1]){
            dp[i][i+1]=dp[i][i];
            if(dp[i][i+1]>ans){
                ans = dp[i][i+1];
                idans = {i,i+1};
            }
        }
        else if(s[i]==t[i] || s[i+1]==t[i+1]){
            if(s[i] != s[i+1] && t[i]!=t[i+1]){
                dp[i][i+1]=dp[i][i]-1;
            }
            else{
                dp[i][i+1]=dp[i][i];
            }
            if(dp[i][i+1]>ans){
                ans = dp[i][i+1];
                idans = {i,i+1};
            }
        }
        else if(s[i]==t[i+1] && s[i+1]==t[i]){
            dp[i][i+1]=dp[i][i]+2;
            if(dp[i][i+1]>ans){
                ans = dp[i][i+1];
                idans = {i,i+1};
            }
        }
        else if(s[i]==t[i+1]||s[i+1]==t[i]){
            dp[i][i+1]=dp[i][i]+1;
            if(dp[i][i+1]>ans){
                ans = dp[i][i+1];
                idans = {i,i+1};
            }
        }
        else{
            dp[i][i+1]=dp[i][i];
            if(dp[i][i+1]>ans){
                ans = dp[i][i+1];
                idans = {i,i+1};
            }
        }
    }
/*
    for(int i = 0;i<n-1;i++){
        cout << i << " " << i+1 << " " << dp[i][i+1] << endl;
    }*/
    for(int len = 3;len<=n;len++){
        //cout << len << " : \n";
        for(int i = 0;i<=n-len;i++){
            int p = i; int k = i+len-1;
            dp[p][k]=dp[p+1][k-1]+procedure(p,k);
            //cout << p << " " << k << " " << dp[p][k] << endl;
            if(dp[p][k]>ans){
                ans = dp[p][k];
                idans = {p,k};
            }

        }
    }
    cout << ans << endl;
    cout << idans.first+1 << " " << idans.second+1;
    return 0;
}