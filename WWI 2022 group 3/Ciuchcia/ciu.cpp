#include <iostream>
using namespace std;
const long long MAXN = 1e6+5;
long long w[MAXN];
pair<long long,long long> dp[MAXN];
pair<long long,long long >minimum(pair<long long,long long> a, pair<long long,long long> b){
    if(a.first<b.first){
        return a;
    }
    else if(b.first<a.first){
        return b;
    }
    else{
        if(a.second<b.second){
            return a;
        }
        return b;
    }
}
bool check(long long mid, long long k, long long n){

    dp[1] = {k+1,mid+1};
    dp[2] = {1,w[1]+w[2]};
    for(long long i = 3;i<=n;i++){
        if(w[i]+w[i-1]<=mid && dp[i-1].second + w[i]<=mid){
            dp[i] = minimum({dp[i-2].first+1,w[i]+w[i-1]},{dp[i-1].first,dp[i-1].second+w[i]});
        }
        else if(w[i]+w[i-1]<=mid && dp[i-1].second + w[i]>mid){
            dp[i] = {dp[i-2].first+1,w[i]+w[i-1]};

        }
        else if(w[i]+w[i-1]>mid && dp[i-1].second + w[i]<=mid){
            dp[i] = {dp[i-1].first,dp[i-1].second+w[i]};
        }
        else{
            dp[i] = {k+1,mid+1};
        }
    }
    if(dp[n].first<=k){
        for(auto i:dp){
            i = {0,0};
        }
        return true;
    }
    else{
        for(auto i:dp){
            i = {0,0};
        }
        return false;
    }
}

long long minimumtwo(long long n){
    long long maxi1 = 0;
    for(long long i = 1;i<=n;i++){
        if(i==1){
            maxi1 = max(maxi1, w[i]+w[i+1]);
        }
        else if(i==n){
            maxi1 = max(maxi1, w[i]+w[i-1]);
        }
        else{
            maxi1 = max(maxi1, w[i]+min(w[i-1],w[i+1]));
        }

    }
    return maxi1;
}
long long binsearch(long long n, long long k){
    long long pocz = minimumtwo(n);
    long long kon = 0;
    for (long long i = 1; i <= n; i++) {
        kon += w[i];
    }
    long long answer = 0;
    while (pocz <= kon) {
        long long mid = (pocz + kon)/2;
        if (check(mid, k, n)) {
            answer = mid;
            kon = mid - 1;
        }
        else {
            pocz = mid + 1;
        }
    }

    return answer;
}
int main() {
    long long n,k;
    cin >> n >> k;
    //string ans1 = ""+n+','+k+",";
    //string x;
    for(long long i = 1;i<=n;i++){
    //while(cin >> x){
        //cin >> x;
        //ans1=ans1+x+',';
        cin >> w[i];
    }
    //cout << ans1;
    cout << binsearch(n,k);
    return 0;
}
/*
10 3
525908799 625331936 176848852 657067119 163032115 692885889 42631439 893138098 98031939 834076990
 */
//1825247027