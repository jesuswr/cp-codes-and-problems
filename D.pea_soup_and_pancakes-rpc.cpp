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


int main(){
	int n;
	ri(n);
	FOR(i,0,n){
		int x;
		ri(x);
		scanf("%*c");
		string name;
		getline(cin, name);
		bool soup = false, panc = false;
		FOR(i,0,x){
			string aux;
			getline(cin,aux);
			if ( aux.compare("pea soup") == 0 )
				soup = true;
			else if ( aux.compare("pancakes") == 0 )
				panc = true;

		}
		if ( soup && panc ){
			cout << name << endl;
			return 0;
		}
	}
	printf("Anywhere is fine I guess\n");
	return 0;
}