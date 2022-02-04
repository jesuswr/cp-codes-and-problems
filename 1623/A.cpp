#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM


void solve() {
    int n, m, x, y, gx, gy;
    riii(n, m, x), riii(y, gx, gy);
    int dx = 1, dy = 1;
    FOR(i, 0, 6969) {
        if (dx == 1 && x == n) dx = -1;
        else if (dx == -1 && x == 1) dx = 1;
        if (dy == 1 && y == m) dy = -1;
        else if (dy == -1 && y == 1) dy = -1;
        if (x == gx || y == gy) {
            printf("%d\n", i);
            return;
        }
        x += dx;
        y += dy;
    }
}


int main() {
    int t = 1;
    ri(t);
    while (t--)
        solve();
    return 0;
}