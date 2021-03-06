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
	int n, m;
	bool cpu[ 20000 ];
	vector<pair<int, PII> > d;
	while ( ~scanf( "%d %d", &n, &m ) && n ) {
		cpu[ 0 ] = true;
		CLR( cpu );
		cpu[ 0 ] = true;
		d.clear();
		for ( int i = 0; i < m; i++ ) {
			int time, from, to;
			scanf( "%d %d %d", &time, &from, &to );
			d.push_back( MP( time, MP( from - 1, to - 1 ) ) );
		}
		sort( d.begin(), d.end() );
		for ( int i = 0; i < m; i++ ) {
			if ( cpu[ d[ i ].second.first ] ) {
				cpu[ d[ i ].second.second ] = true;
			}
		}
		int ans = 0;
		for ( int i = 0; i < n; i++ ) {
			ans += cpu[ i ];
		}
		printf( "%d\n", ans );
	}
	return 0;
}