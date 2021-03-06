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
#define f first
#define s second

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5+10; // CAMBIAR ESTE

// GJNM
int pres[maxN], ord[maxN];
map<int,int> mp;



int main()
{
	int t;
	ri(t);
	while(t--){
		int n , m;
		rii(n,m);
		FOR(i,0,n){
			ri(pres[n-i-1]);
			mp[pres[n-i-1]] = i;
		}
		FOR(i,0,m){
			ri(ord[i]);
		}
		int mn = -1;
		ll cnt = 0;
		int aux = 0;
		FOR(i,0,m){
			if ( mp[ord[i]] < mn ){
				cnt++;
			}
			else{
				mn = mp[ord[i]];
				cnt += 2*(mn-aux) + 1;
			}
			aux++;
			//printf("%d\n",ord[i] );
			//printf("%d %lld\n", t,cnt);
		}
		printf("%lld\n", cnt);
		mp.clear();
	}

	return 0;
}