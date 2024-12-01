#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct cukiernia{
    int lr;
    int rr;
    int wyb;
};

const int MAXN = 200005;
int inf = INT_MAX;
cukiernia cukiernie[MAXN];
const int base = 1<<20;
int tree[base*2];
pair<int,int> tree2[base*2];
pair<int,int> smak[MAXN];


bool cmp(cukiernia a,cukiernia b){
    return a.rr-a.lr<b.rr-b.lr;
}
int read(int a, int b){
    a += base-1;
    b += base+1;
    int sum = 0;
    while(b/2!=a/2){
        if(a%2==0){
            sum += tree[a+1];
            //tree2[a+1]=max(tree2[a+1],x);
        }
        if(b%2==1){
            sum += tree[b-1];
            //tree2[b-1]=max(tree2[b-1],x);
        }
        a/=2;b/=2;
    }
    return sum;
}

void update(int a, int x){
    a+=base;
    tree[a]+=x;
    a/=2;
    while(a>=1){
        tree[a]+=x;
        a/=2;
    }

}

pair<int,int> read2(int a, int b){
    a += base-1;
    b += base+1;
    pair<int,int> mini = {inf,inf};
    while(b/2!=a/2){
        if(a%2==0){
            if(mini.first>tree2[a+1].first){
                mini = {tree2[a+1].first,tree2[a+1].second};
            }
        }
        if(b%2==1){
            if(mini.first>tree2[b-1].first){
                mini = {tree2[b-1].first,tree2[b-1].second};
            }
        }
        a/=2;b/=2;
    }
    return mini;
}

void update2(int a, int x){
    int pos = a;
    a+=base;

    tree2[a].first=x;
    tree2[a].second=pos;
    a/=2;
    while(a>=1){
        if(tree2[a*2].first<tree2[a*2+1].first){
            tree2[a].first=tree2[a*2].first;
            tree2[a].second=tree2[a*2].second;
        }
        else{
            tree2[a].first=tree2[a*2+1].first;
            tree2[a].second=tree2[a*2+1].second;
        }
        a/=2;
    }
}

priority_queue <int, vector<int>, greater<int> > ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(pair<int,int> & i : tree2){
        i.first=inf;
        i.second=inf;
    }
    long long sum = 0;
    int n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> smak[i].first;
        update2(i,smak[i].first);
        smak[i].second = i;
    }
    int m;
    cin >> m;
    for(int i = 0;i<m;i++){
        cin >> cukiernie[i].lr >> cukiernie[i].rr >> cukiernie[i].wyb;
    }
    sort(cukiernie, cukiernie+m, cmp);
    for(int i = 0;i<m;i++){
        int ilz = cukiernie[i].wyb-read(cukiernie[i].lr-1,cukiernie[i].rr-1);
        for(int j = 0;j<ilz;j++){
            pair<int,int>mini = read2(cukiernie[i].lr-1,cukiernie[i].rr-1);
            ans.push(mini.second);
            sum+=mini.first;
            update2(mini.second,inf);
            update(mini.second,1);
        }
    }
    cout << sum << endl;
    cout << ans.size() << endl;
    while(!ans.empty()){
        cout << ans.top()+1 << " " ; ans.pop();
    }

}
/*
8
15 8 2 20 4 9 3 10
4
1 8 5
2 4 2
5 6 1
5 8 2
 */

/*
5
3 5 4 1 2
6
4 5 1
1 5 2
1 3 2
1 2 2
1 1 1
2 2 1
 */