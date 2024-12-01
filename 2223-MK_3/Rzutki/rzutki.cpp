#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point{
    ll x;
    ll y;
};
point rel;

inline bool isInt(char c){
    if(c>='0' && c<='9')return true;
    return false;
}

inline int readInt(){
    char c;
    int x = 0;
    int mult = 1;
    while(!isInt(c = getchar_unlocked()) && c!='-'){
    }
    do{
        if(c=='-'){
            mult=-1;
        }
        else{
            x=x*10+int(c-'0');
        }

    }while(isInt(c = getchar_unlocked()) || c=='-');
    return x*mult;
}

ll iw(point a, point b, point c){
    return ((a.x - c.x) * (b.y - c.y)) - ((a.y - c.y) * (b.x - c.x));
}

bool cmp(point a, point b){
    if(iw(a, b, rel) != 0)
        return iw(a, b, rel) < 0;
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

void create_otoczka(vector<point>& in, vector<point>& otoczka){
    in.push_back(in[0]);
    point a = in[0], b = in[1];
    otoczka.push_back(a);
    for(size_t i = 2; i < in.size(); i++){
        while(iw(b, in[i], a) > 0){
            b = a;
            otoczka.pop_back();
            if(otoczka.empty())
                break;
            a = otoczka[otoczka.size()-1];
        }
        otoczka.push_back(b);
        a = b;
        b = in[i];
    }
    in.pop_back();
}

int binsearch(vector<point>& pts, point x){
    int a = 2, b = pts.size() - 1, mid;
    ll v1 = iw(x, pts[1], pts[0]);
    ll v2 = iw(x, pts[pts.size()-1], pts[0]);
    if(v1 == 0 || v2 == 0) return 0;
    if(v1 < 0 || v2 > 0) return -1;

    while(a < b){
        mid = (a+b)/2;
        if(iw(x, pts[mid], pts[0]) > 0) a = mid + 1;
        else b = mid;
    }
    return a;
}
bool turn (point a0, point a1, point b){
    if(!(min(a0.x, a1.x) <= b.x && b.x <= max(a0.x, a1.x)))
        return 0;
    if(!(min(a0.y, a1.y) <= b.y && b.y <= max(a0.y, a1.y)))
        return 0;
    return 1;

}

int countwotoczce(vector<point>& V, vector<point>& F){
    rel = V[0];
    sort(V.begin()+1, V.end(), cmp);
    vector<point>otoczka;
    create_otoczka(V, otoczka);
    int ans = 0;
    for(point e : F){
        int b = binsearch(otoczka, e);
        if(b == -1) continue;
        if(b == 0){
            if(turn(otoczka[0], otoczka[1], e) || turn(otoczka[0], otoczka[otoczka.size() - 1], e))
                ans++;
        }
        else{
            if((iw(otoczka[b], e, otoczka[b-1]) <= 0) && (iw(otoczka[b-1], e, otoczka[b]) >= 0)){
                ans++;
            }
        }
    }

    return ans;
}

int main(){
    int n;
    n = readInt();
    vector<point>Vas(n), Far(n);
    int start1 = 0, start2 = 0;
    Vas[0].x = readInt();
    Vas[0].y = readInt();
    for(int i = 1; i < n; i++){
        Vas[i].x= readInt(); Vas[i].y = readInt();
        if(Vas[i].x < Vas[start1].x || (Vas[i].x == Vas[start1].x && Vas[i].y < Vas[start1].y))
            start1 = i;
    }
    swap(Vas[0], Vas[start1]);
    Far[0].x = readInt();
    Far[0].y = readInt();;
    for(int i = 1; i < n; i++){
        Far[i].x = readInt();
        Far[i].y = readInt();;
        if(Far[i].x < Far[start2].x || (Far[i].x == Far[start2].x && Far[i].y < Far[start1].y))
            start2 = i;
    }
    swap(Far[0], Far[start2]);

    int ans1 = countwotoczce(Vas, Far);
    int ans2 = countwotoczce(Far, Vas);
    cout << ans1 << " " << ans2 << "\n";
}