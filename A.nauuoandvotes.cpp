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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a);
#define rii(a,b) scanf("%d %d", &a, &b);
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c);
#define rl(a) scanf("%lld", &a);
#define rll(a,b) scanf("%lld %lld", &a, &b);

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM

int main()
{
	int x, y, z;
	riii(x,y,z);
	int ans = 0;
	if ( x > y)
	{
		if ( x - y > z) printf("+\n");
		else printf("?\n");
	}
	else if ( x < y )
	{
		if ( y - x > z) printf("-\n");
		else printf("?\n");
	}
	else
	{
		if ( z == 0) printf("0\n");
		else printf("?\n");
	}
	return 0;
}