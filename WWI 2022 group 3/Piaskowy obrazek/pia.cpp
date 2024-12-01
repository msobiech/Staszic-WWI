#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 5000007;
const int base = 1<<20;
vector<int> G[MAXN];
int preorder[MAXN];
int postorder[MAXN];
int order = 0;
int tree[base*2+1];
int tree2[base*2+1];

int read1(int a){
    int maxi = 0;
    a+=base;
    maxi=max(maxi,tree[a]);
    a/=2;
    while(a>=1){
        maxi=max(tree[a],maxi);
        a/=2;
    }
    return maxi;
}

void update1(int a, int b, int x){
    a += base-1;
    b += base+1;
    while(b/2!=a/2){
        if(a%2==0){
            tree[a+1]=x;
        }
        if(b%2==1){
            tree[b-1]=x;
        }
        a/=2;b/=2;
    }
}

int read2(int a, int b){
    a += base-1;
    b += base+1;
    int maxi = 0;
    while(b/2!=a/2){
        if(a%2==0){
            maxi = max(tree2[a+1],maxi);
        }
        if(b%2==1){
            maxi = max(tree2[b-1],maxi);
        }
        a/=2;b/=2;
    }
    return maxi;
}
void update2(int a,int x){
    a+=base;
    tree2[a]=max(tree2[a],x);
    a/=2;
    while(a>=1){
        tree2[a]=max(tree2[a],x);
        a/=2;
    }
}
void dfs(int v, int ojc,int odlg){
    order++;
    preorder[v]=order;
    for(auto g:G[v]){
        if(g==ojc)continue;
        dfs(g,v,odlg+1);
    }
    postorder[v]=order;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        //cout << a << b;
    }
    dfs(1,1,0);
    //for(int i = 1;i<=n;i++){
    //    cout << preorder[i] << " " << postorder[i] << " odl: " << odl[i] << " " << i << endl;
    //}
    int m,q;
    cin >> m;
    for(int i = 1;i<=m;i++){
        cin >> q;
        if(q==1){
            int v;
            cin >> v;
            update1(preorder[v]-1,postorder[v]-1,i);
            //cout << "update dosypania na " << preorder[v]-1 << " " << postorder[v]-1 << " " << i << endl;
         }
        else if(q==2){
            int v;
            cin >> v;
            update2(preorder[v]-1,i);
            //cout << "update odsypania na " << preorder[v]-1 << " " << i << endl;
        }
        else{
            int v;
            cin >> v;
            //cout << preorder[v]-1
            int r1 = read1(preorder[v]-1);
            int r2 = read2(preorder[v]-1,postorder[v]-1);
            //cout << r1 << " " << r2 << endl;
            if(r1>r2){
                cout << "TAK\n";
            }
            else{
                cout << "NIE\n";
            }
            //if(ans>0)cout << "TAK\n";else cout << "NIE\n";
        }
        // for(int i = 1;i<=n;i++){
        //   cout << state[i]  << " ";
        //}
    }
}