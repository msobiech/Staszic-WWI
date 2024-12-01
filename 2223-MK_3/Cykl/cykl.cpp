#include <iostream>                                                             
#include <iomanip>                                                              
using namespace std;
struct edge {
    int sr;
    int dst;
    long double wg;

};
edge G[10007];
long double dist[105];

long double INF = 2147483647;

int v, e;

inline bool isPos(int src, long double &x) {

    dist[src] = 0;
    int neg;
    for (int i = 0; i < v+1; ++i) {
        neg = -1;
        for (int j = 0; j < e; j++) {
            edge g = G[j];
            g.wg -= x;
            g.wg *= -1;
            if (dist[g.sr] < INF)
                if (dist[g.dst] > dist[g.sr] + g.wg) {
                    dist[g.dst] = max(-INF, dist[g.sr] + g.wg);
                    neg = g.dst;
                }
        }
    }
    if (neg == -1) {
        return false;
    }
    return true;
}

inline double binsearch() {
    long double epsilon = 1e-3;
    long double a = -1 * 1e5;
    long double b = 1e5;
    for (int i = 0; i < 35; i++) {
        long double mid = (a + b) / 2;
        if (isPos(0, mid)) {
            a = mid;
        }
        else
        {
            b = mid + epsilon;
        }
    }

    return a;
}
inline bool isInt(char& c) {

    if (c >= '0' && c <= '9')return true;
    return false;
}

inline int readInt() {

    char c;
    int x = 0;
    int mult = 1;
    while (!isInt(c = getchar_unlocked()) && c != '-') {
    }
    do {
        if (c == '-') {
            mult = -1;
        }
        else {
            x = x * 10 + int(c - '0');
        }

    } while (isInt(c = getchar_unlocked()) || c == '-');
    return x * mult;
}

int main() {
    v = readInt();
    e = readInt();
    for (int i = 0; i < e; i++) {
        int sr, dst, wg;
        sr = readInt(); dst = readInt(); wg = readInt();
        G[i].sr = sr;
        G[i].dst = dst;
        G[i].wg = wg;
    }
    cout << setprecision(4) << fixed << binsearch() << '\n';
}