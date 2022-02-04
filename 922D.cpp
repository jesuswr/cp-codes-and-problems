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
const int MAXN = 1e5 + 10; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
string S[MAXN];
int CNT[MAXN][2];
int ORD[MAXN];

bool comp(int i, int j) {
    if (CNT[j][1] == 0) return 0;
    if (CNT[i][1] == 0) return 1;
    return (1.0 * CNT[i][0]) / CNT[i][1] > (1.0 * CNT[j][0]) / CNT[j][1];
}

int main() {
    ri(N);
    FOR(i, 0, N) cin >> S[i];
    FOR(i, 0, N) for (auto c : S[i]) CNT[i][c == 'h']++;
    FOR(i, 0, N) ORD[i] = i;
    sort(ORD, ORD + N, comp);
    int cnt = 0;
    ll ans = 0;
    FOR(_i, 0, N) {
        int i = ORD[_i];
        for (auto c : S[i]) {
            if (c == 's')
                cnt++;
            else
                ans += cnt;
        }
    }
    printf("%lld\n", ans);
    return 0;
}