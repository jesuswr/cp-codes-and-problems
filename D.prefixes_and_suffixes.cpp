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

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int cnt[MAXN];
bool match[MAXN];

int main() {
    string s; cin >> s;
    auto zf = z_function(s);
    FOR(i, 0, SZ(zf)) {
        cnt[ zf[i] ]++;
    }
    for (int i = SZ(s); i >= 0; i--)
        cnt[i] += cnt[i + 1];

    int ans_c = 0;
    FOR(i, 0, SZ(zf)) {
        if (zf[i] == SZ(s) - i) {
            ans_c++;
            match[zf[i]] = true;
        }
    }
    printf("%d\n", ans_c + 1);
    FOR(i, 1, SZ(s)) {
        if (match[i]) {
            printf("%d %d\n", i, cnt[i] + 1);
        }
    }
    printf("%d %d\n", SZ(s), 1);

    return 0;
}