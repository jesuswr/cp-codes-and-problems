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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE

// GJNM
int N;
string S;
string SR;
queue<int> Q[MAXN];
int TO[MAXN];

ll BIT[MAXN];
// suma de rangos [0,n-1]
void updBIT(int p, ll val) {
    p++;    // esto es porque el bit esta indexado desde 1
    for (; p < N + 2; p += p & -p) // se puede cambiar maxN por n+1 si hace falta mas velocidad
        BIT[p] += val;
}
ll sumBIT(int p) {
    p++;
    ll ret = 0;
    for (; p; p -= p & -p)
        ret += BIT[p];
    return ret;
}

int main() {
    ri(N);
    cin >> S; SR = S;
    reverse(ALL(SR));
    FOR(i, 0, N) Q[S[i] - 'a'].push(i);
    
    FOR(i, 0, N) {
        TO[ Q[SR[i] - 'a'].front() ] = i;
        Q[SR[i] - 'a'].pop();
    }

    ll ans = 0;
    FOR(i, 0, N) {
        ans += sumBIT(N) - sumBIT(TO[i]);
        updBIT(TO[i], 1);
    }
    printf("%lld\n", ans);
    return 0;
}