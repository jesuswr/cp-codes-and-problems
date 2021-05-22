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

using namespace std;

typedef long long ll;
typedef double ld;
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
const int MAXN = 1e6 + 10; // CAMBIAR ESTE

// GJNM
double ANS[MAXN];

int main() {
    int n;
    stack< pair<double, double> > st;

    ri(n);
    FOR(i, 0, n) {
        int trash; ri(trash);
        ld ai = trash;
        ld cnt = 1;
        while (!st.empty() && ai <= st.top().F) {
            ai = (ai * cnt + st.top().F * st.top().S) / (cnt + st.top().S);
            cnt += st.top().S;
            st.pop();
        }
        st.push({ai, cnt});
    }

    for (int i = n - 1; i >= 0; --i) {
        auto p = st.top(); st.pop();
        ANS[i] = p.F;
        p.S--;
        if (p.S > 0) st.push(p);
    }
    FOR(i, 0, n) printf("%.10lF\n", ANS[i]);
    return 0;
}