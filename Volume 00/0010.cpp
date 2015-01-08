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

int n;
double x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4;

int main() {
	scanf( "%d", &n );
	for ( int i = 0; i < n; i++ ) {
		scanf( "%lf %lf %lf %lf %lf %lf", &x_1, &y_1, &x_2, &y_2, &x_3, &y_3 );
		double a1 = 2 * ( x_2 - x_1 );
		double b1 = 2 * ( y_2 - y_1 );
		double c1 = sq( x_1 ) - sq( x_2 ) + sq( y_1 ) - sq( y_2 );
		double a2 = 2 * ( x_3 - x_1 );
		double b2 = 2 * ( y_3 - y_1 );
		double c2 = sq( x_1 ) - sq( x_3 ) + sq( y_1 ) - sq( y_3 );
		double x = ( b1 * c2 - b2 * c1 ) / ( a1 * b2 - a2 * b1 );
		double y = ( c1 * a2 - c2 * a1 ) / ( a1 * b2 - a2 * b1 );

		double r = sqrt( sq( x - x_1 ) + sq( y - y_1 ) );
		printf( "%.3f %.3f %.3f\n", x, y, r );
	}
	return 0;
}