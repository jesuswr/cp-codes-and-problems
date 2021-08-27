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
const int MAXN = 1e5; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
bool is_comp[1000];
void pre() {
    is_comp[1] = true;
    FOR(i, 2, 1000) {
        if (is_comp[i])
            continue;
        int j = i + i;
        while (j < 1000) {
            is_comp[j] = true;
            j += i;
        }
    }
}

void solve() {
    int n; ri(n);
    string s; cin >> s;

    FOR(i, 0, n) {
        int x = s[i] - '0';
        if (is_comp[x]) {
            printf("%d\n%d\n", 1, x);
            return;
        }
    }

    FOR(i, 0, n) FOR(j, i + 1, n) {
        int x = 10 * (s[i] - '0') + (s[j] - '0');
        if (is_comp[x]) {
            printf("%d\n%d\n", 2, x);
            return;
        }
    }

    FOR(i, 0, n) FOR(j, i + 1, n) FOR(k, j + 1, n) {
        int x = 100 * (s[i] - '0') + 10 * (s[j] - '0') + (s[k] - '0');
        if (is_comp[x]) {
            printf("%d\n%d\n", 3, x);
            return;
        }
    }

}


int main() {
    pre();
    int t; ri(t);
    while (t--) solve();
    return 0;
}