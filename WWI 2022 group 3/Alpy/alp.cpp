#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <queue>
using namespace std;

struct question{
    int v;
    int maxh;
    int id;
};

const int MAXN = 500005;
int heights[MAXN];
int sizeofunion[MAXN];
int root[MAXN];
pair<int,int> sortedheights[MAXN];
vector<int> Graph[MAXN];
vector<question> questions;
vector<int> heightstosearch;
int ans[MAXN];

struct node {int h, v;};
auto cmp = [](node a, node b){return a.h > b.h;};
priority_queue<node, vector<node>, decltype(cmp)>Q(cmp);

bool cmp2(question a, question b){
    return a.maxh<b.maxh;
}

int Find (int a) {
    if (root[a]==a){
        return a;
    }
    root[a] = Find (root[a]);
    return (root[a]);
}

void Union(int a, int b){
    int x, y;
    x = Find(a);
    y = Find(b);
    if(x == y){
        return;
    }
    sizeofunion[y] =sizeofunion[x]+sizeofunion[y];
    sizeofunion[x] = sizeofunion[x]+sizeofunion[y];
    root[x] = root[y];
}

inline bool isint(char c){
    if(c >= '0' && c<='9'){
        return true;
    }
    else{
        return false;
    }
}
inline int readint(){
    char c;
    int x = 0;
    while(!isint(c = getchar_unlocked())){
    }
    do{
        x=x*10+int(c-'0');
    }while(isint(c = getchar_unlocked()));
    return x;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    n = readint();
    m = readint();
    //cin >> n >> m;
    //int maxi = 0;
    //int mini = INT_MAX;
    for(int i = 1;i<=n;i++){
        int height = readint();;
        //cin >> height;
        heightstosearch.push_back(height);
        root[i]=i;
        sizeofunion[i]=1;
        heights[i] = height;
        Q.push({height,i});
        //sortedheights[i] = {height,i};
    }
    //sort(sortedheights+1,sortedheights+n+1);
    //graph info
    for(int i=0;i<m;i++){
        int vertice_a = readint();int vertice_b = readint();;
        //cin >> vertice_a >> vertice_b;
        Graph[vertice_a].push_back(vertice_b);//connecting both vertices;
        Graph[vertice_b].push_back(vertice_a);
    }
    int q = readint();//number of questions
    //cin >> q;
    for(int i = 0;i<q;i++){
        int v = readint(); int maxh = readint();;
        //cin >> v >> maxh;
        //heightstosearch.push_back(maxh);
        questions.push_back({v,maxh,i});//from where, how high can i get, which question it is
    }

    heightstosearch.erase(unique( heightstosearch.begin(), heightstosearch.end()), heightstosearch.end());
    sort(questions.begin(),questions.end(),cmp2);
    sort(heightstosearch.begin(),heightstosearch.end());
    //for(auto e:heightstosearch){
    //    cout << e << " ";
    //}
   // cout << endl;
    //cout << "posortach";
    queue<int> tounion;
    int whichquestion = 0;
    int siz = questions.size();
    for(auto curheight : heightstosearch){
        while(whichquestion < siz && questions[whichquestion].maxh<curheight){
            ans[questions[whichquestion].id]=sizeofunion[Find(questions[whichquestion].v)];
            whichquestion++;
        }
        while(Q.size() and Q.top().h == curheight){
            node nd = Q.top();
            for(auto s : Graph[nd.v])
                if(heights[s] <= curheight)
                    Union(nd.v, s);
                Q.pop();
        }
        while(whichquestion < siz && questions[whichquestion].maxh==curheight){
            ans[questions[whichquestion].id]=sizeofunion[Find(questions[whichquestion].v)];
            whichquestion++;
        }
        /*
        //cout << curheight << endl;
        int start = lower_bound(sortedheights+1,sortedheights+n+1,make_pair(curheight,numeric_limits<int>::min()))-sortedheights;//starting iterator to start searching for vertices to union
        if(sortedheights[start].first==curheight){
            while(sortedheights[start].first == curheight){
                tounion.push(sortedheights[start].second);
                start++;
            }
            while(!tounion.empty()){
                int cur = tounion.front();//currently unioned element
                for(int g: Graph[cur]){
                    if(heights[g]<=heights[cur]){
                        //cout << "union of " << g << " and " << cur << endl;
                        Union(g,cur);
                    }
                }
                tounion.pop();
            }
        }*/

    }
    while(whichquestion < siz && questions[whichquestion].maxh>heightstosearch[heightstosearch.size()-1]){
        ans[questions[whichquestion].id]=sizeofunion[Find(questions[whichquestion].v)];
        whichquestion++;
    }
    for(int i = 0;i<q;i++){
        cout << ans[i] << "\n";
    }


    return 0;
}