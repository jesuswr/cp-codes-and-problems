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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 5e5; // CAMBIAR ESTE

// GJNM
int n, k;
int a[MAXN];

int pre[MAXN];

void solve() {
    rii(n, k);
    FOR(i, 0, n) {
        ri(a[i]);
    }
    FOR(i, 0, 2 * k + 5) {
        pre[i] = 0;
    }

    FOR(i, 0, n / 2) {
        int mn = min(a[i], a[n - 1 - i]);
        int mx = max(a[i], a[n - 1 - i]);

        pre[2] += 2, pre[mn + 1] += -1;
        pre[mx + k + 1] += 1, pre[2 * k + 1] +=  - 2;

        pre[mn + mx] += -1;
        pre[mn + mx + 1] += 1;
    }
    FOR(i, 1, 2 * k + 1) {
        pre[i] += pre[i - 1];
    }
    int ans = 1e9;
    FOR(i, 2, 2 * k + 1) {
        ans = min(ans, pre[i]);
    }
    printf("%d\n", ans);

}



int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}