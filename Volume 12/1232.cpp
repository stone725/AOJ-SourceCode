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
	VI pm;
	vector<bool> is_pm( 100000, true );
	is_pm[ 0 ] = is_pm[ 1 ] = false;
	for ( int i = 2; i * i < 100000; i += 2 ) {
		if ( is_pm[ i ] ) {
			for ( int j = i * i; j < 100000; j += i ) {
				is_pm[ j ] = false;
				if ( i == 2 ) {
					j += i;
				}
			}
			if ( i == 2 ) {
				--i;
			}
		}
	}
	for ( int i = 2; i < 100000; i += 2 ) {
		if ( is_pm[ i ] ) {
			pm.push_back( i );
			if ( i == 2 ) {
				i--;
			}
		}
	}
	int m, a, b;
	while ( ~scanf( "%d %d %d", &m, &a, &b ) && m && a && b ) {
		int ans_a = 0, ans_b = 0;
		for ( int i = 0; i < pm.size(); i++ ) {
			if ( sq( pm[ i ] ) > m ) {
				break;
			}
			for ( int j = i; j < pm.size(); j++ ) {
				if ( pm[ i ] * pm[ j ] > m || ( double ) a / b > ( double ) pm[ i ] / pm[ j ] ) {
					break;
				}
				if ( pm[ i ] * pm[ j ] > ans_a * ans_b ) {
					ans_a = pm[ i ];
					ans_b = pm[ j ];
				}
			}
		}
		printf( "%d %d\n", ans_a, ans_b );
	}
	return 0;
}