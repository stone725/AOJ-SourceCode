#include <bits/stdc++.h>
using namespace std;
#define FOR(i, s, n) for(int i = s; i < (int)n; ++i)
#define per(i, n) for(int i = n; i >= 0; i--)
#define ROF(i, s, n) for(int i = s; i >= (int)n; i--)
#define FORIT(i, A) for (auto i : A)
#define PRINT(x) cout << (x) << "\n"
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MP make_pair
#define PB push_back
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
typedef complex<double> Point;
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

int d, n;
VI t;
vector<pair<PII, int> > a;
int dp[ 201 ][ 201 ];

void input() {
	cin >> d >> n;
	t.resize( d );
	for ( int i = 0; i < d; i++ ) {
		cin >> t[ i ];
	}
	a.resize( n );
	for ( int i = 0; i < n; i++ ) {
		cin >> a[ i ].first.first >> a[ i ].first.second >> a[ i ].second;
	}
}

int dfs( int now, int k ) {
	if ( now == d ) {
		return 0;
	}
	if ( dp[ now ][ k ] >= 0 ) {
		return dp[ now ][ k ];
	}
	int res = 0;
	if ( now ) {
		for ( int i = 0; i < n; i++ ) {
			if ( t[ now ] >= a[ i ].first.first && a[ i ].first.second >= t[ now ] ) {
				res = max( res, dfs( now + 1, i ) + abs( a[ i ].second - a[ k ].second ) );
			}
		}
	}
	else {
		for ( int i = 0; i < n; i++ ) {
			if ( t[ now ] >= a[ i ].first.first && a[ i ].first.second >= t[ k ] ) {
				res = max( res, dfs( now + 1, i ) );
			}
		}
	}
	return dp[ now ][ k ] = res;
}

void solve() {
	NCLR( dp );
	cout << dfs( 0, 0 ) << "\n";
}

int main() {
  ios::sync_with_stdio( false );
  cin.tie( 0 );
  input();
#ifdef WIN32
  clock_t stime = clock();
#endif
  solve();
#ifdef WIN32
  clock_t etime = clock();
  cout << "TIME : " << ( double ) ( etime - stime ) / CLOCKS_PER_SEC << "\n";
#endif
  return 0;
}