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
string alpha;
string word;
set<string> hola;

int main(){
	cin >> alpha;
	cin >> word;
	int n = word.size();
	FOR(i,0,n){
		hola.insert(word.substr(0,i) + word.substr(i+1,n-i-1));
		for(auto c : alpha){
			hola.insert(word.substr(0,i) + c + word.substr(i+1,n-i-1));
			hola.insert(word.substr(0,i) + c + word.substr(i,n-i));
		}
	}
	for(auto c : alpha){
		hola.insert(word+c);
	}

	for(auto s : hola){
		if ( word.compare(s) )
			cout << s << endl;
	}
	return 0;
}