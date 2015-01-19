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

struct Union_Find {
	vector<int> par;
	vector<int> rank;

	void init( int n ) {
		for ( int i = 0; i < n; ++i ) {
			par.push_back( i );
			rank.push_back( 0 );
		}
	}

	int find( int s ) {
		if ( par[ s ] == s ) {
			return s;
		}
		return par[ s ] = find( par[ s ] );
	}

	void unite( int x, int y ) {
		int a = find( x ), b = find( y );
		if ( a == b ) {
			return;
		}
		if ( rank[ x ] < rank[ y ] ) {
			par[ x ] = y;
		}
		else {
			par[ y ] = x;
			if ( rank[ x ] == rank[ y ] ) {
				++rank[ x ];
			}
		}
	}

	bool same( int x, int y ) {
		return find( x ) == find( y );
	}
};

int main() {
	int n, m;
	while ( ~scanf( "%d", &n ) && n ) {
		scanf( "%d", &m );
		VVI root( n, VI( n, INF ) );
		for ( int i = 0; i < m; i++ ) {
			int a, b, c;
			scanf( "%d,%d,%d", &a, &b, &c );
			root[ a ][ b ] = root[ b ][ a ] = c / 100 - 1;
		}
		Union_Find u;
		u.init( n );
		int ans = 0;
		for ( int i = 1; i < n; i++ ) {
			int _min = INF, add;
			for ( int j = 0; j < n; j++ ) {
				if ( !u.same( 0, j ) ) {
					continue;
				}
				for ( int k = 1; k < n; k++ ) {
					if ( !u.same( 0, k ) && _min >= root[ j ][ k ] ) {
						add = k;
						_min = root[ j ][ k ];
					}
				}
			}
			u.unite( 0, add );
			ans += _min;
		}
		printf( "%d\n", ans );
	}
	return 0;
}