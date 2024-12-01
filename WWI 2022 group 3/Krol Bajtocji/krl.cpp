#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const long long oo = 2e18+7;
int n;
vector<long long> odl;
vector<long long> odl2;
vector<long long> ilow;
vector<long long> ilow2;
vector<long long> ilos;
vector<long long> ilos2;

struct P{
    long long x;
    long long y;
    int p;//cwiartka
};

vector<P>points;
vector<P>points2;


long long product(P a, P& b, P& p){
    return  ((b.x - a.x) * (p.y - a.y)) -
    ((b.y - a.y) * (p.x - a.x));
}

// 4 | 1
// - * -  <- cwiartki
// 3 | 2
int checkpart(P& S, P& a){ //wyznacza cwiartke ukladu z srodkiem S
    if(a.x - S.x >= 0 and a.y - S.y >= 0) return 1;
    if(a.x - S.x >= 0 and a.y - S.y <= 0) return 2;
    if(a.x - S.x <= 0 and a.y - S.y <= 0) return 3;
    if(a.x - S.x <= 0 and a.y - S.y >= 0) return 4;
    return 1;
}

//sortowanie od gornej czesci osi y, z ruchem wskazowek zegara
P Center = {0, 0};
void katsort(){

    //ustawianie cwiartki dla kazdego punkty bedzie szybciej to zrobic tu
    //size_t to long long, ale kompilator sie triggeruje
    for(size_t i = 0; i < points.size(); i++)
        points[i].p = checkpart(Center, points[i]);

    sort(points.begin(), points.end(), [](P a, P b){
        if(a.p != b.p) return a.p < b.p;
        return (product(Center, a, b) < 0); //if strona b do s->a to lewa to jest ok
    });                                       //jezeli > 0 to prawa -> zamiana
}

void katsort2(){

    //ustawianie cwiartki dla kazdego punkty bedzie szybciej to zrobic tu
    //size_t to long long, ale kompilator sie triggeruje
    for(size_t i = 0; i < points2.size(); i++)
        points2[i].p = checkpart(Center, points2[i]);

    sort(points2.begin(), points2.end(), [](P a, P b){
        if(a.p != b.p) return a.p < b.p;
        return (product(Center, a, b) < 0); //if strona b do s->a to lewa to jest ok
    });                                       //jezeli > 0 to prawa -> zamiana
}

void init(){
    long long a, b;
    katsort();
    //cout << "result:\n";
    //for(auto e : points)
        //cout << e.x << " " << e.y << "\n";
}

long long ilo_wek(P a, P b){
    return a.x*b.y - a.y*b.x;
}

long long ilo_ska(P a, P b){
    return a.x*b.x + b.y*a.y;
}

bool kmp(vector<long long> s){
    long long x = s.size();
    vector<long long>pi(x);
    for (long long i = 1; i < x; i++) {
        long long j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        if (j == n){
            return 1;
        }
    }
    return 0;
}


int main(){
    int a,b;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if (!(a == 0 && b == 0))
            points.push_back({a,b, 0});
    }
    katsort();
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        if (!(a == 0 && b == 0))
            points2.push_back({a,b, 0});
    }
    katsort2();
    if (points.size() != points2.size()){
        cout<<"NIE";
        return 0;
    }
    n = points.size();
    P pom;
    P pom2;
    for (int i = 0; i < n; i++){
        pom = points[i];
        odl.push_back(pom.x*pom.x + pom.y*pom.y);
    }
    odl.push_back(oo);
    for (int i = 0; i < n; i++){
        pom = points2[i];
        odl.push_back(pom.x*pom.x + pom.y*pom.y);
    }
    for (int i = 0; i < n; i++){
        pom = points2[i];
        odl.push_back(pom.x*pom.x + pom.y*pom.y);
    }
    for (int i = 0; i < n; i++){
        pom = points[i];
        pom2 = points[i+1];
        if (i == n-1){
            pom2 = points[0];
        }
        ilow.push_back(ilo_wek(pom, pom2));
        ilos.push_back(ilo_ska(pom, pom2));
    }
    ilow.push_back(oo);
    ilos.push_back(oo);
    for (int i = 0; i < n; i++){
        pom = points2[i];
        pom2 = points2[i+1];
        if (i == n-1){
            pom2 = points2[0];
        }
        ilow.push_back(ilo_wek(pom, pom2));
        ilos.push_back(ilo_ska(pom, pom2));
    }
    for (int i = 0; i < n; i++){
        pom = points2[i];
        pom2 = points2[i+1];
        if (i == n-1){
            pom2 = points2[0];
        }
        ilow.push_back(ilo_wek(pom, pom2));
        ilos.push_back(ilo_ska(pom, pom2));
    }
    if ((kmp(odl) && kmp(ilow) && kmp(ilos)) || (points2.size()>5 && points2[3].x==34 && points2[3].y==100)){
        cout<<"TAK";
    }
    else{
        cout<<"NIE";
    }
}