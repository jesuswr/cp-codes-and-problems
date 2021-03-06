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
#define all(s) s.begin(),s.end()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5 + 10; // CAMBIAR ESTE

// GJNM
ll a[MAXN], b[MAXN];

int main() {
    int n;
    ri(n);
    FOR(i, 0, n) {
        rl(a[i]);
    }
    FOR(i, 0, n) {
        rl(b[i]);
    }

    ll sm[3] = {0, 0, 0};
    FOR(i, 0, n) {
        sm[i % 3] += b[i];
    }

    ll ans[3] = {0, 0, 0};
    FOR(i, 0, n) {
        ans[i % 3] += a[i] * sm[0];
        ans[(i + 1) % 3] += a[i] * sm[1];
        ans[(i + 2) % 3] += a[i] * sm[2];
    }

    printf("%lld %lld %lld\n", ans[1], ans[2], ans[0]);

    return 0;
}