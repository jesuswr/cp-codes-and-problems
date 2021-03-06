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
const int MAXN = 30010; // CAMBIAR ESTE

// GJNM
int N, a[MAXN];


void solve() {
    ri(N);
    FOR(i, 0, N) {
        ri(a[i]);
    }

    ll rem_l = 0;
    FOR(i, 0, N - 1) {
        rem_l += max(0, a[i] - a[i + 1]);
    }
    if (rem_l <= a[0])
        printf("YES\n");
    else
        printf("NO\n");
}


int main() {
    int t;
    ri(t);
    while (t--) {
        solve();
    }

    return 0;
}