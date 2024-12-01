#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 200005;
pair<int,int> intervals[MAXN];

bool comp(pair<int,int>a,pair<int,int>b){
        if(a.second<b.second){
            return true;
        }
        else if(a.second == b.second){
            return (a.first<b.first);
        }
        return false;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        int start,ending;
        cin >> start >> ending;
        intervals[i] = {start,ending};
    }
    sort(intervals,intervals+n,comp);
    int k = intervals[0].second;
    int ans = 1;
    for(int i = 1;i<n;i++){
        if(intervals[i].first>=k){
            ans++;
            k=intervals[i].second;
        }
    }
    cout << ans;
}