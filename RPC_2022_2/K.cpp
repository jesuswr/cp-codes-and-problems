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
const int MAXN = 1010; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N;
string S[MAXN];

bool V[MAXN];
int C[MAXN];
int CNT[2];
vi g[MAXN];
void dfss(int u) {
    V[u] = 1;
    CNT[C[u]]++;
    for (int v : g[u]) {
        if (!V[v]) {
            C[v] = C[u] ^ 1;
            dfss(v);
        }
    }
}

// A from 1 to A
// B from A+1 to A+B < MAXN
vi G[MAXN]; // edges A->B  //clear G for several test cases
int A, B, match[MAXN], dist[MAXN];
bool bfs() {
    queue<int> q;
    FOR(i, 1, A + 1) {
        if (match[i] == 0) {
            dist[i] = 0;
            q.push(i);
        } else dist[i] = INF;
    }
    dist[0] = INF;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (v != 0) {
            FOR(i, 0, G[v].size()) {
                int u = G[v][i];
                if (dist[match[u]] == INF) {
                    dist[match[u]] = dist[v] + 1;
                    q.push(match[u]);
                }
            }
        }
    }
    return (dist[0] != INF);
}
bool dfs(int v) {
    if (v != 0) {
        FOR(i, 0, G[v].size()) {
            int u = G[v][i];
            if (dist[match[u]] == dist[v] + 1) {
                if (dfs(match[u])) {
                    match[u] = v;
                    match[v] = u;
                    return true;
                }
            }
        }
        dist[v] = INF;
        return false;
    }
    return true;
}
int HK() {
    memset(match, 0, sizeof(match));
    int MBM = 0;
    while (bfs())
        FOR(i, 1, A + 1)
        if (match[i] == 0 && dfs(i))
            MBM++;
    return MBM;
}


int main() {
    ri(N);
    FOR(i, 0, N) cin >> S[i];
    FOR(i, 0, N) FOR(j, i + 1, N) {
        int cnt = 0;
        FOR(k, 0, SZ(S[i])) cnt += S[i][k] != S[j][k];
        if (cnt == 2) {
            g[i].pb(j);
            g[j].pb(i);
        }
    }

    FOR(i, 0, N) if (!V[i])
        dfss(i);

    FOR(i, 0, N) FOR(j, i + 1, N) {
        int cnt = 0;
        FOR(k, 0, SZ(S[i])) cnt += S[i][k] != S[j][k];
        if (cnt == 2) {
            if (C[i] == 0)
                G[i + 1].pb(N + 1 + j);
            else
                G[1 + j].pb(N + i + 1);
        }
    }
    A = B = N;
    printf("%d\n", N - HK());
    return 0;
}