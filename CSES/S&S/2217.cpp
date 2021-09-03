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
const int MAXN = 2e5 + 10; // CAMBIAR ESTE
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int A[MAXN], IND[MAXN];

int main() {
    IND[0] = INF;
    int n, m; rii(n, m);
    FOR(i, 1, n + 1) {
        ri(A[i]);
        IND[A[i]] = i;
    }

    int ans = 0;
    FOR(i, 1, n + 1) if (IND[A[i]] < IND[A[i] - 1])
        ans++;

    while (m--) {
        int i, j; rii(i, j);
        {
            if (IND[A[i]] > IND[A[i] - 1])
                ans++;
            if (IND[A[i] + 1] > IND[A[i]])
                ans++;
            IND[A[i]] = j;
            if (IND[A[i]] > IND[A[i] - 1])
                ans--;
            if (IND[A[i] + 1] > IND[A[i]])
                ans--;
        }
        {
            if (IND[A[j]] > IND[A[j] - 1])
                ans++;
            if (IND[A[j] + 1] > IND[A[j]])
                ans++;
            IND[A[j]] = i;
            if (IND[A[j]] > IND[A[j] - 1])
                ans--;
            if (IND[A[j] + 1] > IND[A[j]])
                ans--;
        }
        swap(A[i], A[j]);
        printf("%d\n", ans);
    }

    return 0;
}