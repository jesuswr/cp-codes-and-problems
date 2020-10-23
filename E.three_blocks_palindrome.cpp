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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
int n;
int a[MAXN];
int pre[MAXN][200];
vi indxs[210];

int query(int l, int r) {
    int mx = 0;
    FOR(i, 1, 201) {
        mx = max(mx, pre[r][i] - (l > 0 ? pre[l - 1][i] : 0));
    }
    return mx;
}


void solve() {
    ri(n);
    FOR(i, 0, n) {
        int a; ri(a);
        indxs[a].pb(i);
        pre[i][a] = 1;
    }
    FOR(i, 1, n) {
        FOR(j, 1, 201) {
            pre[i][j] += pre[i - 1][j];
        }
    }
    int ans = query(0, n - 1);
    FOR(i, 1, 201) {
        int l = 0, r = indxs[i].size() - 1;
        while (l < r) {
            ans = max(ans, l + 1 + (int)indxs[i].size() - r + query(indxs[i][l] + 1, indxs[i][r] - 1));
            l++; r--;
        }
        indxs[i].clear();
    }

    printf("%d\n", ans);

    FOR(i, 0, n) {
        FOR(j, 0, 200) {
            pre[i][j + 1] = 0;
        }
    }
}


int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}