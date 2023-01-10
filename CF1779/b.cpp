#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dasdas;

#define FOR(i,n,m) for(int i = n; i < (int)m; i++)
#define ROF(i,n,m) for(int i = n; i > (int)m; i--)
#define ms(obj,val) memset(obj,val,sizeof(obj))
#define ri(a) dasdas=scanf("%d", &a)
#define rii(a,b) ri(a), ri(b)
#define lri(a) dasdas=scanf("%lld", &a)
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


int main(){
	int t; ri(t);
	while(t--) {
		int n; ri(n);
		if (n == 3) cout << "NO" << endl;
		else if (n % 2 == 0) {
		 	cout << "YES" << endl;
			for(int i = 0; i < n; i += 2) {
				cout << 1 << " " << -1 << " ";
			}
			cout << endl;
		}
		else {
			int a = INF, b = INF;
			n = n / 2;
			for(int i = -5000; i <= 5000; ++i) {
				if ( ((n - 1 ) * i) % n == 0) {
					a = i;
					b = (-1 * (n-1) * i) / n;
					if (b <= 5000 && b >= -5000 && a != 0 && b != 0)
						break;
					else{
						a = b = INF;
					}
				}
			}
			if (a == INF) {
				cout << "NO" << endl;
				break;
			}
		 	cout << "YES" << endl;
			cout << b << " ";
			for(int i = 0; i < n; ++i) {
				cout << a << " " << b << " ";
			}
			cout << endl;
		}
	}

	return 0;
}