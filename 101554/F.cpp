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
#include <assert.h>
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 1e5; // CAMBIAR ESTE
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
vector<string> NUMS = {
    "**** ** ** ****",
    "  *  *  *  *  *",
    "***  *****  ***",
    "***  ****  ****",
    "* ** ****  *  *",
    "****  ***  ****",
    "****  **** ****",
    "***  *  *  *  *",
    "**** ***** ****",
    "**** ****  ****"
};

int f(string s) {
    FOR(i, 0, 10) if (NUMS[i] == s)
        return i;
    return -1;
}
void g(string s) {
    cout << s << endl << endl;
    FOR(i, 0, 15) {
        printf("%c", s[i]);
        if (i % 3 == 2)
            printf("\n");
    }
    printf("\n");
}


int main() {
    string INP[5];
    FOR(i, 0, 5) getline(cin, INP[i]);
    int num = 0;
    int j = 0;
    while (j < SZ(INP[0])) {
        string aux;
        FOR(i, 0, 5) {
            aux += INP[i][j];
            aux += INP[i][j + 1];
            aux += INP[i][j + 2];
        }
        // g(aux);
        int digit = f(aux);
        if (digit == -1) {
            printf("BOOM!!\n");
            return 0;
        }
        num = 10 * num + digit;
        // if (num % 6 == 0) {
        //     printf("BEER!!\n");
        //     return 0;
        // }

        j += 4;
    }
    if (num % 6 == 0)
        printf("BEER!!\n");
    else
        printf("BOOM!!\n");
    return 0;
}