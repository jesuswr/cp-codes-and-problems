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
#define FOR(i,n,m) for(unsigned int i=n; i<m; i++)
#define ROF(i,n,m) for(ll i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE

// GJNM

void solve() {
	unsigned int n;
	scanf("%u", &n);

	set<unsigned int> st;
	FOR(i, 0, 28) {
		unsigned int aux_n = (n >> i);

		st.insert( aux_n & 31);
	}

	n = (n << 4) | ( n >> (32 - 4));

	FOR(i, 0, 10) {
		unsigned int aux_n = (n >> i);

		st.insert( aux_n & 31);
	}

	
	if ( st.size() == 32 )
		printf("yes\n");
	else
		printf("no\n");
}

int main() {
	int t;
	ri(t);
	while (t--) {
		solve();
	}

	return 0;
}