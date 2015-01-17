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



int main() {
	const int money[] = { 10, 50, 100, 500 };
	int n;
	bool d = false;
	while ( ~scanf("%d", &n) && n ) {
		if ( d ) {
			printf( "\n" );
		}
		d = true;
		int many[ 4 ];
		for ( int i = 0; i < 4; i++ ) {
			scanf( "%d", &many[ i ] );
		}
		int use[ 4 ] = {0, 0, 0, 0};
		for ( int i = 0; i < 4; i++ ) {
			while ( many[ i ] ) {
				n -= money[ i ];
				many[ i ]--;
				use[ i ]++;
			}
		}
		if ( n < 0 ) {
			while ( abs( n ) % 50 ) {
				n += money[ 0 ];
				use[ 0 ] = max( 0, use[ 0 ] - 1 );
			}
			while ( abs( n ) % 100 ) {
				n += money[ 1 ];
				use[ 1 ] = max( 0, use[ 1 ] - 1 );
			}
			while ( abs( n ) % 500 ) {
				n += money[ 2 ];
				use[ 2 ] = max( 0, use[ 2 ] - 1 );
			}
			while ( n ) {
				n += money[ 3 ];
				use[ 3 ] = max( 0, use[ 3 ] - 1 );
			}
		}
		for ( int i = 0; i < 4; i++ ) {
			if ( use[ i ] ) {
				printf( "%d %d\n", money[ i ], use[ i ] );
			}
		}
	}
	return 0;
}