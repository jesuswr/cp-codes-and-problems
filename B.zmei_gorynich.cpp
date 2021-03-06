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

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM

int main()
{
	int t;
	ri(t);
	while(t--)
	{
		int n, x;
		rii(n,x);
		int aux1, aux2, maxH=0, maxD=0;
		FOR(i,0,n)
		{
			rii(aux1,aux2);
			maxH = max(maxH,aux1);
			maxD = max(maxD,aux1-aux2);
		}
		int ans = 1;
		if ( maxH >= x )
		{
			printf("1\n");
		}
		else
		{
			if ( maxD <= 0 )
			{
				printf("-1\n");
			}
			else
			{
				x -= maxH;
				ans += x/maxD + ( x%maxD == 0 ? 0 : 1 );
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}