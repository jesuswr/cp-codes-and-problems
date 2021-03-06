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
const int maxN = 1e5+5; // CAMBIAR ESTE

// GJNM
char arr[maxN];
int n;
unordered_map<string, bool> mp;
unordered_map<string, bool> vis;

void bfs ( string s )
{
	vis[s] = true;
	queue<string> q;
	q.push(s);
	string aux;
	while (!q.empty())
	{
		aux = q.front();
		q.pop();
		if ( mp.find( aux ) == mp.end() && aux != "")
		{
			cout<< aux.length() << " " << aux << "\n";
			return;
		}
		else
		{
			FOR(i,0,10)
			{
				string aux2 = aux + char( (int)'0' + i);
				if ( vis.find(aux2) == vis.end() )
				{
					vis[aux2] = true;
					q.push(aux2);
				}
			}
		}
	}
}


int main()
{
	int t;
	ri(t);
	while(t--)
	{
		int n;
		ri(n);
		scanf("%s",arr);
		FOR(i,0,n)
		{
			int j = i;
			string aux ="";
			while ( j<n && i+5 > j)
			{
				aux += arr[j];
				mp[aux] = true;
				j++;
			}
		}
		
		bfs("");
		mp.clear();
		vis.clear();
	}

}