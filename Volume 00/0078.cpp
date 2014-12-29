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
static const int mod = 10007;
static const int INF = 1 << 25;
static const LL LL_INF = 1152921504606846976;
static const int dx[] = { -1, 0, 1, 0,  1, -1,  1, -1 };
static const int dy[] = { 0, -1, 0, 1 , 1,  1, -1, -1 };

int n;
int magic_square[ 115 ][ 115 ];
int x, y;

int main() {
	while ( ~scanf( "%d", &n ) && n ) {
		memset( magic_square, 0, sizeof( magic_square ) );
		y = n / 2 + 1;
		x = n / 2;
		for ( int i = 1; i <= n * n - 1; i++ ) {
			magic_square[ y ][ x ] = i;
			y++;
			x++;
			y %= n;
			x %= n;
			while ( magic_square[ y ][ x ] != 0 ) {
				y++;
				x--;
				y %= n;
				if ( x < 0 ) {
					x += n;
				}
			}
			
		}
		magic_square[ y ][ x ] = n * n;
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < n; j++ ) {
				if ( magic_square[ i ][ j ] / 10 == 0 ) {
					printf( "   " );
				}
				else if ( magic_square[ i ][ j ] / 100 == 0 ) {
					printf( "  " );
				}
				else {
					printf( " " );
				}
				printf( "%d", magic_square[ i ][ j ] );
			}
			printf( "\n" );
		}
	}
	return 0;
}