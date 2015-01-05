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
static const double EPS = 1e-10;
static const double PI = acos( -1.0 );
static const int mod = 1000000007;
static const int INF = 1 << 25;
static const LL LL_INF = 1152921504606846976;
static const int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
static const int dy[] = { 0, -1, 0, 1, 1, 1, -1, -1 };

static int dp[ 1000001 ];
static bool is_pm[ 1000001 ];
static int n, m;
static VI _array;

int solve( int now, int many ) {
	if ( dp[ many ] >= 0 ) {
		return dp[ many ];
	}
	if ( now == n ) {
		if ( is_pm[ many ] ) {
			return dp[many] = many;
		}
		return dp[many] = 0;
	}
	int res = 0;
	for ( int i = 0; many + _array[ now ] * i <= m; i++ ) {
		res = max( res, solve( now + 1, many + _array[ now ] * i ) );
	}
	return dp[ many ] = res;
}

int main() {
	NCLR( is_pm );
	for ( int i = 2; sq( i ) <= 1000000; i += 2 ) {
		if ( is_pm[ i ] ) {
			for ( int j = i * i; j <= 1000000; j += i ) {
				is_pm[ j ] = false;
				if ( i != 2 ) {
					j += i;
				}
			}
		}
		if ( i == 2 ) {
			--i;
		}
	}
	is_pm[ 0 ] = is_pm[ 1 ] = false;
	while ( ~scanf( "%d %d", &n, &m ) && n && m ) {
		_array.resize( n );
		for ( int i = 0; i < n; i++ ) {
			scanf( "%d", &_array[ i ] );
		}
		sort( _array.rbegin(), _array.rend() );
		_array.erase( unique( _array.begin(), _array.end() ), _array.end() );
		n = _array.size();
		NCLR( dp );
		int ans = solve( 0, 0 );
		if ( ans ) {
			printf( "%d\n", ans );
		}
		else {
			printf( "NA\n" );
		}
	}
	return 0;
}