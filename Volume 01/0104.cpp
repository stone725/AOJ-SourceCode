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

VS mp;
int n, m, x, y;
char mp_input[ 200 ];
bool gone[ 200 ][ 200 ];

int main() {
	while ( ~scanf( "%d %d", &n, &m ) && n && m ) {
		mp.resize( n );
		for ( int i = 0; i < n; i++ ) {
			scanf( "%s", mp_input );
			mp[ i ] = ( string ) mp_input;
		}
		memset( gone, 0, sizeof( gone ) );
		x = y = 0;
		while ( mp[ y ][ x ] != '.' ){
			if ( gone[ y ][ x ] ) {
				break;
			}
			gone[ y ][ x ] = true;
			if ( mp[ y ][ x ] == '>' ) {
				x++;
			}
			else if ( mp[ y ][ x ] == '<' ) {
				x--;
			}
			else if ( mp[ y ][ x ] == '^' ) {
				y--;
			}
			else if ( mp[ y ][ x ] == 'v' ) {
				y++;
			}
		}
		if ( gone[ y ][ x ] ) {
			printf( "LOOP\n" );
		}
		else {
			printf( "%d %d\n", x, y );
		}
	}
	return 0;
}