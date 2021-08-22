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

// GJNM
typedef int tf;
typedef int tc;
const tf INFFLOW = 1e8;
const tc INFCOST = 1e8;
struct MCF {
    int n;
    vector<tc> prio, pot; vector<tf> curflow; vector<int> prevedge, prevnode;
    priority_queue<pair<tc, int>, vector<pair<tc, int>>, greater<pair<tc, int>>> q;
    struct edge {int to, rev; tf f, cap; tc cost;};
    vector<vector<edge>> g;
    MCF(int _n): n(_n), prio(_n), curflow(_n), prevedge(_n), prevnode(_n),  pot(_n), g(_n) {}

    void add_edge(int s, int t, tf cap, tc cost) {
        // printf("%d -> %d / (cap, cst) = (%d, %d)\n", s, t, cap, cost);
        g[s].pb((edge) {t, SZ(g[t]), 0, cap, cost});
        g[t].pb((edge) {s, SZ(g[s]) - 1, 0, 0, -cost});
    }

    pair<tf, tc> get_flow(int s, int t) {
        tf flow = 0; tc flowcost = 0;
        while (1) {
            q.push({0, s});
            fill(ALL(prio), INFCOST);
            prio[s] = 0; curflow[s] = INFFLOW;
            while (!q.empty()) {
                auto cur = q.top();
                tc d = cur.F;
                int u = cur.S;
                q.pop();
                if (d != prio[u]) continue;
                for (int i = 0; i < SZ(g[u]); ++i) {
                    edge &e = g[u][i];
                    int v = e.to;
                    if (e.cap <= e.f) continue;
                    tc nprio = prio[u] + e.cost + pot[u] - pot[v];
                    if (prio[v] > nprio) {
                        prio[v] = nprio;
                        q.push({nprio, v});
                        prevnode[v] = u; prevedge[v] = i;
                        curflow[v] = min(curflow[u], e.cap - e.f);
                    }
                }
            }
            if (prio[t] == INFCOST) break;
            FOR(i, 0, n) pot[i] += prio[i];
            tf df = min(curflow[t], INFFLOW - flow);
            flow += df;
            for (int v = t; v != s; v = prevnode[v]) {
                edge &e = g[prevnode[v]][prevedge[v]];
                e.f += df; g[v][e.rev].f -= df;
                flowcost += df * e.cost;
            }
        }
        return {flow, flowcost};
    }
};

int n;
int in(int r, int c) {
    return 2 * (n * r + c);
}
int out(int r, int c) {
    return in(r, c) + 1;
}

int DR[4] = {1, -1, 0, 0};
int DC[4] = {0, 0, 1, -1};

int main() {
    while (ri(n), n != 0) {
        MCF mcf(n * 10 + 7);
        int s = n * 10 + 5, t = n * 10 + 6;
        FOR(r, 0, 5) {
            scanf("%*c");
            FOR(c, 0, n) {
                char ch; scanf("%c", &ch);
                int cst = ch - '0';

                mcf.add_edge(in(r, c), out(r, c), 1, 0);

                // nodo incial
                if (ch == '@') {
                    mcf.add_edge(s, in(r, c), 1, 0);
                    cst = 0;
                }

                // mov horizontal o vert
                FOR(i, 0, 4) {
                    int new_r = r + DR[i], new_c = c + DC[i];
                    if (min(new_r, new_c) >= 0 && new_r < 5 && new_c < n){
                        mcf.add_edge(out(new_r, new_c), in(r, c), 1, cst);
                    }
                }

                // ultima fila
                if (c == n - 1)
                    mcf.add_edge(out(r, c), t, 1, 0);
            }
        }
        // printf("%d %d\n", s, t);
        printf("%d\n", mcf.get_flow(s, t).S);
    }

    return 0;
}