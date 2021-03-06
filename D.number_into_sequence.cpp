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
using u64 = uint64_t;
using u128 = __uint128_t;

u64 binPow(u64 a, u64 b, u64 mod) {
    if (b == 0) return 1;
    if (b & 1) return (u128)a * binPow(a, b ^ 1, mod) % mod;
    return binPow((u128)a * a % mod, b >> 1, mod);
}

bool checkComp(u64 n, u64 a, u64 d, int s) {
    u64 x = binPow(a, d, n);
    if (x == 1 || x == n - 1) return false;
    FOR(r, 1, s) {
        x = (u128)x * x % n;
        if (x == n - 1) return false;
    }
    return true;
}

bool RabinMiller(u64 n) {
    if (n < 2) return false;
    int r = 0;
    u64 d = n - 1;
    while (!(d & 1))
        d >>= 1, r++;
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (checkComp(n, a, d, r)) return false;
    }
    return true;
}

ll mult(ll a, ll b, ll mod) {
    return (__int128)a * b % mod;
}
ll f(ll x, ll cc, ll mod) {
    return (mult(x, x, mod) + cc) % mod;
}
ll rho(ll n) { // Works in O(n^(1/4) * log(n))
    ll x = 2, y = 2, g = 1;
    ll cc = rand() % n + 1;
    while (g == 1) {
        x = f(x, cc, n);
        y = f(y, cc, n);
        y = f(y, cc, n);
        g = __gcd(abs(x - y), n);
    }
    return g == n ? rho(n) : g;
}
map <ll, ll> fact;
void factRho(ll n) {
    if (n == 1) return;
    if (RabinMiller(n)) {
        fact[n]++;
        return;
    }
    ll factor = rho(n);
    factRho(factor);
    factRho(n / factor);
}
void factor(ll n) {
    ll i = 2;
    while (n > 1 && i < 60) {
        while (n % i == 0) fact[i]++, n /= i;
        i++;
    }
    factRho(n);
}

void solve() {
    ll n; rl(n);
    fact.clear();
    factor(n);
    ll ans, cnt_ans = 0;
    for (auto p : fact) {
        if (p.S > cnt_ans) {
            cnt_ans = p.S;
            ans = p.F;
        }
    }
    printf("%lld\n", cnt_ans);
    FOR(i, 0, cnt_ans - 1) {
        printf("%lld ", ans);
        n /= ans;
    }
    printf("%lld\n", n);

}

int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}