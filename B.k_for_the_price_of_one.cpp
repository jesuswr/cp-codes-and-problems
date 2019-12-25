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
const int maxN = 2e5+5; // CAMBIAR ESTE

// GJNM
ll n, p, k;
ll arr[maxN];


int main()
{
	int t;
	ri(t);
	while(t--){
		rll(n,p);
		rl(k);
		FOR(i,0,n) 
			rl(arr[i]);
		sort(arr,arr+n);
		ll prev = 0;
		ll ans = 0;
		FOR(i,0,k){
			ll cnt = prev;
			ll num = i;
			if ( cnt > p )
				break;
			for( int j = k + i - 1 ; j < n ; j += k ){
				if ( cnt + arr[j] > p ) 
					break;
				num += k;
				cnt += arr[j];
			}
			ans = max( num , ans);
			prev += arr[i];
		}
		printf("%lld\n", ans);
	}
		
	return 0;
}