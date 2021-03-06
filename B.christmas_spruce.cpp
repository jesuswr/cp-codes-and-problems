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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM
vi g[maxN];
bool ans = true;
bool leaf[maxN];

void dfs(int x){
	int child = 0;
	int leaf_child = 0;
	for(auto y : g[x]){
		child++;
		dfs(y);
		if ( leaf[y] )
			leaf_child++;
	}
	if ( child == 0 )
		leaf[x] = true;
	
	if ( child > 0 && leaf_child < 3 )
		ans = false;
}

int main(){
	int n;
	ri(n);
	FOR(i,1,n){
		int aux;
		ri(aux);
		aux--;
		g[aux].pb(i);
	}
	dfs(0);
	if ( ans )
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}