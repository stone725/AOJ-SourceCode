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
static const int INF = 1 << 30;
static const LL LL_INF = 1152921504606846976;
static const int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
static const int dy[] = { 0, -1, 0, 1, 1, 1, -1, -1 };

bool collision_detection( double x1, double y1, double x2, double y2, double x3, double y3, double xp, double yp ) {
	x2 -= x1;
	x3 -= x1;
	xp -= x1;
	y2 -= y1;
	y3 -= y1;
	yp -= y1;
	double t_size = fabs( ( x2 * y3 - y2 * x3 ) / 2 );
	t_size -= fabs( ( x2 * yp -  y2 * xp ) / 2 );
	t_size -= fabs( ( x3 * yp -  y3 * xp ) / 2 );
	x2 -= xp;
	x3 -= xp;
	y2 -= yp;
	y3 -= yp;
	yp = xp = 0;
	t_size -= fabs( ( x2 * y3 - y2 * x3 ) / 2 );
	return fabs( t_size ) < 1e-10;
}

int main() {
	double x[ 4 ], y[ 4 ];
	while ( ~scanf( "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &x[ 0 ], &y[ 0 ], &x[ 1 ], &y[ 1 ], &x[ 2 ], &y[ 2 ], &x[ 3 ], &y[ 3 ] ) ) {
		bool print_yes = true;
		for ( int i = 0; i < 4; i++ ) {
			if ( collision_detection( x[ ( i + 1 ) % 4 ], y[ ( i + 1 ) % 4 ], x[ ( i + 2 ) % 4 ], y[ ( i + 2 ) % 4 ], x[ ( i + 3 ) % 4 ], y[ ( i + 3 ) % 4 ], x[ i ], y[ i ] ) ) {
				print_yes = false;
				break;
			}
		}
		printf( "%s\n", print_yes ? "YES" : "NO" );
	}
	return 0;
}