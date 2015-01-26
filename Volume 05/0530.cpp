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

int n, m, b;
vector<vector<PII> > a;
int dp[ 153 ][ 153 ][ 153 ];

int solve( int now, int e, int w ) {
	if ( now >= n || ( w && now >= n - 1 ) ) {
		return 0;
	}
	if ( dp[ now ][ e ][ w ] >= 0 ) {
		return dp[ now ][ e ][ w ];
	}
	int res = INF;
	for ( int i = 0; i < a[ now ].size(); i++ ) {
		if ( now == 0 ) {
			res = min( res, solve( now + 1, i, w ) );
		}
		else {
			res = min( res, solve( now + 1, i, w ) + abs( a[ now - 1 ][ e ].first - a[ now ][ i ].first ) * ( a[ now - 1 ][ e ].second + a[ now ][ i ].second ) );
		}
	}
	if ( w ) {
		for ( int i = 0; i < a[ now + 1 ].size(); i++ ) {
			if ( now == 0 ) {
				res = min( res, solve( now + 2, i, w - 1 ) );
			}
			else {
				res = min( res, solve( now + 2, i, w - 1 ) + abs( a[ now - 1 ][ e ].first - a[ now + 1 ][ i ].first ) * ( a[ now - 1 ][ e ].second + a[ now + 1 ][ i ].second ) );
			}
		}
	}
	return dp[ now ][ e ][ w ] = res;
}

int main() {
	while ( ~scanf( "%d %d", &n, &m ) && n ) {
		a.resize( n );
		for ( int i = 0; i < n; i++ ) {
			scanf( "%d", &b );
			a[ i ].resize( b );
			for ( int j = 0; j < a[ i ].size(); j++ ) {
				scanf( "%d %d", &a[ i ][ j ].first, &a[ i ][ j ].second );
			}
		}
		NCLR( dp );
		printf( "%d\n", solve( 0, 0, m ) );
	}
	return 0;
}