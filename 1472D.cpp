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
    int n; ri(n);
    priority_queue<int> pq;
    FOR(i, 0, n) {
        int tmp; ri(tmp); pq.push(tmp);
    }
    ll cnt[2] = {0, 0};
    FOR(i, 0, n) {
        ll curr = pq.top(); pq.pop();
        if ((curr & 1) == (i & 1)) cnt[curr & 1] += curr;
    }
    if (cnt[0] > cnt[1]) printf("Alice\n");
    else if (cnt[0] < cnt[1]) printf("Bob\n");
    else printf("Tie\n");
}

int main() {
    int t; ri(t);
    while (t--) solve();

    return 0;
}