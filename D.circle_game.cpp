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

using namespace std;

typedef long long ll;
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

// GJNM
void solve() {
    ll dd, kk; rll(dd, kk);

    __int128 d = dd, k = kk;
    __int128 lo = 0, hi = d;
    while (lo < hi) {
        __int128 mi = lo + (hi - lo + 1) / 2;

        __int128 x = 2 * (mi * k) * (mi * k);

        if (x <= d * d)
            lo = mi;
        else
            hi = mi - 1;
    }
    if ( ((lo + 1)*k) * ((lo + 1)*k) + (lo * k) * (lo * k) <= d * d)
        printf("Ashish\n");
    else
        printf("Utkarsh\n");
}

int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}