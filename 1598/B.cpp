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
#include <bitset>

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
const int MAXN = 1010; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM


void solve() {
    int n; ri(n);
    bitset<MAXN> can[5];
    FOR(i, 0, 5) can[i].reset();
    FOR(i, 0, n) FOR(b, 0, 5) {
        int on; ri(on);
        can[b][i] = on;
    }
    FOR(i, 0, 5) FOR(j, i + 1, 5) {
        if (can[i].count() >= n / 2 && can[j].count() >= n / 2 && (can[i] | can[j]).count() == n) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}


int main() {
    int t; ri(t);
    while (t--) solve();
    return 0;
}