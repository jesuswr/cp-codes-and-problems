#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) scanf("%lld", &a)
#define lrii(a,b) lri(a), lri(b)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define S second
#define F first

const int INF = 0x3f3f3f3f;
const ll INFLL = 1e18;
const int MOD = 1e9+7;
const int MAXN = 2e5+5;

void fastIO() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long double sq(int dx, int dy) {
	return sqrt(dx * dx + dy * dy);
}

long double go1(int x, int y, int ax, int ay) {
	return max(
		sq( x-ax, y-ay ),
		sq( ax, ay )
	);
}

long double go2(int x, int y, int ax, int ay, int bx, int by) {
	return max({
		sq(ax - bx, ay - by) / 2,
		min( sq(ax, ay), sq(bx, by) ),
		min( sq(ax - x, ay - y), sq(bx - x, by - y) )
	});
}

void solve() {
	int px, py, ax, ay, bx, by;
	cin >> px >> py >> ax >> ay >> bx >> by;
	long double dst = min({
		go1(px, py, ax, ay),
		go1(px, py, bx, by),
		go2(px, py, ax, ay, bx, by)
	});
	printf("%.12Lf\n", dst);
}

int main(){
	int t; cin >> t;
	while(t--) solve();
	return 0;
}