#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

struct point{
    long long x;
    long long y;
    long long id;
};

const long long MAXN = 200005;
point points[MAXN];
long long sum[MAXN];
const long long base = 1<<20;
long long tree[base*2];
unsigned long long ans[MAXN];
long long inf = 40000000000000;
map<int,int>sk[4];
void update(long long x, long long val){
    x+=base;
    tree[x]=val;
    //maxi=max(maxi,tree[x]);
    x/=2;
    while(x>=1){
        tree[x]=max(tree[x*2],tree[x*2+1]);
        x/=2;
    }
}

long long read(long long a, long long b){
    a += base-1;
    b += base+1;
    long long maxi = -1*inf;
    while(b/2!=a/2){
        //cout << maxi << " ";
        if(a%2==0){
            maxi= max(tree[a+1],maxi);
        }
        if(b%2==1){
            maxi= max(tree[b-1],maxi);
        }
        a/=2;b/=2;
    }
    //cout << maxi << " ";
    //cout << endl;
    return maxi;
}

bool cmp(point a, point b){
    if(a.x==b.x && a.y==b.y){
        ans[b.id]=0; ans[a.id] = 0;
    }
    if(a.y<b.y){
        return true;
    }
    else if(a.y==b.y){
        return a.x<b.x;
    }
    else{
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    priority_queue<int> pq;
    for(long long i = 0;i<n;i++){
        cin >> points[i].x >> points[i].y;
        points[i].id=i;
        sum[i]=points[i].x+points[i].y;
        pq.push(points[i].x);
    }
    for(long long & i : tree){
        i=-1*inf;
    }
    //cout << endl;
    for(long long i = 0;i<MAXN;i++){
        ans[i] = inf;
    }
    for(long long i = 0;i<4;i++){
        //cout << i << endl;
        sort(points,points+n,cmp);
        long long xorder = pq.size()+1;
        long long last = pq.top();
        sk[i][pq.top()] = xorder;
        xorder--;
        pq.pop();
        while(!pq.empty()){
            long long top = pq.top();
            sk[i][top] = xorder;
            if(last!=top){
                xorder--;
            }
            pq.pop();
        }
        //cout << "posortowal\n";
        for(long long j = 0;j<n;j++){
            //cout << "punkt: "<< points[j].x << " " << points[j].y << " " << points[j].id << endl;
            long long maxi = read(0,sk[i][points[j].x]-1);
            //cout << 0 << " " << sk[i][points[j].x]-1 << " " << maxi << endl;
            //cout << maxi << endl;
            update(sk[i][points[j].x]-1,sum[points[j].id]);
            //cout << sk[i][points[j].x]-1 << " " << sum[points[j].id] << '\n';
            //cout << read(0,sk[i][points[j].x]-1) << endl;
            if(maxi!=-1*inf){
                long long x = ans[points[j].id];
                ans[points[j].id]=min(x,sum[points[j].id]-maxi);
            }
            //cout << ans[points[j].id] << endl;
        }
        if(i<3){
            for(long long j = 0;j<n;j++){
                points[j].x *=-1;
                swap(points[j].x,points[j].y);
                sum[points[j].id]=points[j].x+points[j].y;
                pq.push(points[j].x);
                //cout << points[j].x << " " << points[j].y << endl;
            }
            for(long long & g : tree){
                g=-1*inf;
            }
        }

    }
    //cout << "ans\n";
    for(long long i = 0;i<n;i++){
        cout << ans[i] << endl;
    }
    return 0;
}
/*
 *
6
-2 -1
3 3
-3 2
0 0
4 3
2 2
 */
/*
2
-1000000000 -1000000000
1000000000 1000000000
 */