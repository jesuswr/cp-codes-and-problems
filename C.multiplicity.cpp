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
const int maxN = 1e6 + 10; // CAMBIAR ESTE
const ll MOD = 1e9 + 7;

// GJNM
int dp[maxN];
int n;
vi divs[100000];

int f() {
	dp[0] = 1;
	FOR(i, 0, n) {
		for (auto d : divs[i]) {
			int act = -d;
			dp[act] += dp[act - 1];
			dp[act] %= MOD;
		}

	}
	int ans = 0;
	FOR(i, 1, maxN) {
		ans += dp[i];
		ans %= MOD;
	}
	return ans;

}

int main() {
	ri(n);
	FOR(i, 0, n) {
		int aux;
		ri(aux);
		divs[i].reserve(100);
		for (int j = 1; j * j <= aux; ++j) {
			if ( aux % j == 0 ) {
				divs[i].pb(-j);
				if ( j != aux / j)
					divs[i].pb(-aux / j);
			}
		}
		sort(divs[i].begin(), divs[i].end());
	}

	printf("%d\n", f());

	return 0;
}