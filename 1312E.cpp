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
const int MAXN = 1010; // CAMBIAR ESTE

// GJNM
int N;
int A[MAXN];
int DP[MAXN][MAXN], DP2[MAXN];

int f(int l, int r) {
    if (DP[l][r] != 0) return DP[l][r];
    if (l == r - 1) return A[l];

    FOR(m, l + 1, r) {
        int lf = f(l, m), rf = f(m, r);
        if (lf == rf && lf > 0) return DP[l][r] = lf + 1;
    }
    return DP[l][r] = -1;
}

int main() {
    ri(N);
    FOR(i, 0, N) ri(A[i]);
    FOR(i, 1, N + 1) DP2[i] = INF;

    FOR(i, 0, N) FOR(j, i + 1, N + 1) if (f(i, j) > 0) DP2[j] = min(DP2[j], DP2[i] + 1);
    printf("%d\n", DP2[N]);
    return 0;
}