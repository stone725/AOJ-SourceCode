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

int n;
VVI a;
vector<vector<LL> > s;

void solve() {
	LL ans = -INF;
	for ( int i = 1; i <= n; i++ ) {
		for ( int j = 1; j <= n; j++ ) {
			for ( int k = 0; k < i; k++ ) {
				for ( int l = 0; l < j; l++ ) {
					ans = max( ans, s[ i ][ j ] - s[ k ][ j ] - s[ i ][ l ] + s[ k ][ l ] );
				}
			}
		}
	}
	printf( "%lld\n", ans );
}

int main() {
#ifdef WIN32
	printf( "Debug Mode\n" );
#endif
	scanf( "%d\n", &n );
	a.resize( n, VI( n ) );
	s.resize( n + 1, vector<LL>( n + 1, 0 ) );
	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ ) {
			scanf( "%d", &a[ i ][ j ] );
			s[ i + 1 ][ j + 1 ] = s[ i + 1 ][ j ] + s[ i ][ j + 1 ] - s[ i ][ j ] + a[ i ][ j ];
		}
	}
	solve();
	return 0;
}