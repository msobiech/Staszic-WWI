#include <iostream>
#include <set>
#include <queue>
using namespace std;

int primes[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

struct num{
    long long val;
    int factor[13];
};


class Compare {
    public:
       bool operator()(const num &a,const num &b){
           return a.val>b.val;
      }
};

inline long long getnum(num a){
    long long dzielniki = 1;
    for(int j = 0;j<13;j++){
        dzielniki*=a.factor[j]+1;
    }
    return dzielniki;
}

priority_queue<num, vector<num>, Compare> Q;
set<long long> odw;

void mnoz(int x){
    if(x==1){
        cout << 1;
        return;
    }
    num num1;
    num1.val = 1;
    for(int j = 0;j<13;j++){
        num1.factor[j] = 0;
    }
    Q.push(num1);
    while(!Q.empty()){
        num v = Q.top();
        if(getnum(v)==x){
            cout << v.val << endl;
            return;
        }
        //cout << v.val << " : wart\n";
        Q.pop();
        for(int j = 0;j<13;j++){
            num b = v;
            b.val*=primes[j];
            b.factor[j]++;
            if(odw.count(b.val)==0 && (j==0 || b.factor[j]<=b.factor[j-1])){
                Q.push(b);
                odw.insert(b.val);
                
            }

        }

    }

}



int main(){
    int x;
    cin >> x;
    mnoz(x);

}