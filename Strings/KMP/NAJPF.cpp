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
vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        j += s[i] == s[j];
        pi[i] = j;
    }
    return pi;
}

void solve() {
    string big, small;
    cin >> big >> small;
    int big_sz = SZ(big), small_sz = SZ(small);
    small = small + "?" + big;
    auto pre_f = prefix_function(small);
    vi ans;
    FOR(i, 0, big_sz) {
        if (pre_f[small_sz + 1 + i] == small_sz) {
            ans.pb(i + 2 - small_sz);
        }
    }
    if (ans.empty())
        printf("Not Found\n");
    else {
        printf("%d\n", SZ(ans));
        for (auto x : ans) {
            printf("%d ", x);
        } printf("\n");
    }
    printf("\n");
}

int main() {
    int t;
    ri(t);
    while (t--)
        solve();

    return 0;
}