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
const int maxN = 1e6 + 1; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM

ll fact[maxN];

ll bpow(int x, ll e) {
	if ( e == 0 )
		return 1LL;
	ll res = bpow(x, e / 2LL);
	if ( e & 1LL )
		return (((res * res) % MOD) * x) % MOD;
	else
		return (res * res) % MOD;
}


ll pick(ll n, ll k) {
	ll num = fact[n];
	ll den = (fact[k] * fact[n - k]) % MOD;
	return num * bpow(den, MOD - 2LL) % MOD;
}

int main() {
	fact[0] = 1;
	FOR(i, 1, maxN) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	int n;
	ri(n);
	ll ans = fact[n];
	FOR(i, 0, n) {
		ans = (ans - pick(n - 1, i) + MOD) % MOD;
	}
	printf("%lld\n", ans);

	return 0;
}