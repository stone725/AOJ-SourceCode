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
static const int INF = 1 << 30;
static const LL LL_INF = 1152921504606846976;
static const int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
static const int dy[] = { 0, -1, 0, 1, 1, 1, -1, -1 };

int n, m;
int dp[ 16 ][ 16 ];
int _array[ 16 ][ 16 ];
VI can_start;

int solve( int now, int x ) {
	if ( now >= m ) {
		return 1;
	}
	if ( _array[ now ][ x ] == 1 ) {
		return 0;
	}
	if ( now >= m - 1 ) {
		return 1;
	}
	if ( dp[ now ][ x ] >= 0 ) {
		return dp[ now ][ x ];
	}
	int res = 0;
	if ( _array[ now ][ x ] == 2 ) {
		res += solve( now + 2, x );
	}
	else {
		for ( int i = 0; i < 3; i++ ) {
			if ( x + dx[ i ] < 0 || x + dx[ i ] >= n || ( now + 1 != m && _array[ now + 1 ][ x + dx[ i ] ] == 2 && dx[ i ] != 0 ) ) {
				continue;
			}
			res += solve( now + 1, x + dx[ i ] );
		}
	}
	return dp[ now ][ x ] = res;
}

int main() {
	while ( ~scanf( "%d %d", &n, &m ) && n != 0 && m != 0 ) {
		for ( int i = 0; i < m; i++ ) {
			for ( int j = 0; j < n; j++ ) {
				scanf( "%d", &_array[ i ][ j ] );
				if ( i == 0 && _array[ i ][ j ] == 0 ) {
					can_start.push_back( j );
				}
			}
		}
		NCLR( dp );
		int ans = 0;
		for ( int i = 0; i < can_start.size(); i++ ) {
			ans += solve( 0, can_start[ i ] );
		}
		printf( "%d\n", ans );
		can_start.clear();
	}
	return 0;
}