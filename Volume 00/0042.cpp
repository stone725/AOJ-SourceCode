#include <bits/stdc++.h>
using namespace std;
#define FOR(i, s, n) for(int i = s; i < (int)n; i++)
#define per(i, n) for(int i = n; i >= 0; i--)
#define ROF(i, s, n) for(int i = s; i >= (int)n; i--)
#define FORIT(i, A) for (auto i : A)
#define PRINT(x) cout << (x) << "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MP make_pair
#define EACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define SZ(a) int((a).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define CLR(a) memset((a), 0 ,sizeof(a))
#define NCLR(a) memset((a), -1 ,sizeof(a))
#define sq(n) (n) * (n)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef priority_queue<int> maxpq;
typedef priority_queue< int, vector<int>, greater<int> > minpq;
typedef complex<double> P;
static const double EPS = 1e-10;
static const double PI = acos( -1.0 );
static const int mod = 1000000007;
static const int INF = 1 << 29;
static const LL LL_INF = 1ll << 60;
static const int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
static const int dy[] = { 0, -1, 0, 1, 1, 1, -1, -1 };

#ifdef WIN32
#define dump(x) cout << #x << " = " << (x) << "\n"
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << "\n"
#else
#define dump(x)
#define debug(x)
#endif

int w, n, now = 0;
vector<PII> v;
PII dp[ 1001 ][ 1001 ];

PII dfs( int now, int g ) {
	if ( now == n ) {
		return MP( 0, w - g );
	}
	if ( dp[ now ][ g ].first >= 0 ) {
		return dp[ now ][ g ];
	}
	PII res = MP( -1, -1 );
	if ( g >= v[ now ].second ) {
		PII tmp = dfs( now + 1, g - v[ now ].second );
		tmp.first += v[ now ].first;
		res = tmp;
	}
	PII tmp = dfs( now + 1, g );
	if ( tmp.first > res.first || ( tmp.first == res.first && tmp.second < res.second ) ) {
		res = tmp;
	}
	return dp[ now ][ g ] = res;
}

void solve() {
	printf( "Case %d:\n", now );
	PII ans = dfs( 0, w );
	printf( "%d\n%d\n", ans.first, ans.second );
}

int main() {
#ifdef WIN32
	printf( "Debug Mode\n" );
#endif
	while ( ~scanf( "%d", &w ) && w ) {
		now++;
		for ( int i = 0; i < 1001; i++ ) {
			for ( int j = 0; j < 1001; j++ ) {
				dp[ i ][ j ] = PII( -1, -1 );
			}
		}
		scanf( "%d", &n );
		v.resize( n );
		for ( int i = 0; i < n; i++ ) {
			scanf( "%d,%d", &v[ i ].first, &v[ i ].second );
		}
		solve();
	}
	return 0;
}