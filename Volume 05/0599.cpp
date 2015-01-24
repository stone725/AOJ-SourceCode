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
#define dump(x) cout << #x << " = " << (x) << "\n";
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << "\n";
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
static const LL LL_INF = 1152921504606846976;
static const int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
static const int dy[] = { 0, -1, 0, 1, 1, 1, -1, -1 };

const int MAX_M = 10001, MAX_N = 501;

int dp[ 10001 ][ 501 ], m, n;
vector<PII> _box;
vector<int> p;
vector<int> s( 1, 0 );

int solve( int now, int box ) {
	if ( now >= m || box == n ) {
		return 0;
	}
	if ( dp[ now ][ box ] >= 0 ) {
		return dp[ now ][ box ];
	}
	int res = 0;
	res = max( res, solve( now, box + 1 ) );
	res = max( res, solve( min( m, now + _box[ box ].second ), box + 1 ) + s[ min( now + _box[ box ].second, m ) ] - s[ now ] - _box[ box ].first );
	return dp[ now ][ box ] = res;
}

int main() {
	scanf( "%d %d", &m, &n );
	p.resize( m );
	_box.resize( n );
	for ( int i = 0; i < m; i++ ) {
		scanf( "%d", &p[ i ] );
	}
	for ( int i = 0; i < n; i++ ) {
		scanf( "%d %d", &_box[ i ].second, &_box[ i ].first );
	}
	sort( p.rbegin(), p.rend() );
	for ( int i = 0; i < m; i++ ) {
		s.push_back( s[ i ] + p[ i ] );
	}
	NCLR( dp );
	printf( "%d\n", solve( 0, 0 ) );
	return 0;
}