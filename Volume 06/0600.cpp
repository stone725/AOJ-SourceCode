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
static const LL LL_INF = 1ll << 60;
static const int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
static const int dy[] = { 0, -1, 0, 1, 1, 1, -1, -1 };

#ifdef WIN32
#define dump(x) cout << #x << " = " << (x) << "\n"
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << "\n"
#else
#define dump(x)
#define debug(x)
#endif

int n;
VI manysize;

void solve() {
	int num = n / 3;
	LL size1 = 0, size2 = 0, size3 = 0;
	for ( int i = 0; i < num; i++ ) {
		size1 += manysize[ i ];
	}
	for ( int i = 0; i < num; i++ ) {
		size2 += manysize[ i + num ];
	}
	for ( int j = num * 2; j < n; j++ ) {
		size3 += manysize[ j ];
	}
	LL ans = min( size1, min( size2, size3 ) );
	int now1 = num, now2 = num * 2, now3 = 0;
	set < pair<int, PII> > s;
	while ( !s.count( MP( now1, MP( now2, now3 ) ) ) ) {
		s.insert( MP( now1, MP( now2, now3 ) ) );
		if ( size3 == min( size1, min( size2, size3 ) ) ) {
			ans = max( ans, size3 );
			size3 += manysize[ now3 ];
			size1 -= manysize[ now3 ];
			now3++;
			now3 %= n;
		}
		else if ( size2 == min( size1, min( size2, size3 ) ) ) {
			ans = max( ans, size2 );
			size2 += manysize[ now2 ];
			size3 -= manysize[ now2 ];
			now2++;
			now2 %= n;
		}
		else {
			ans = max( ans, size1 );
			size1 += manysize[ now1 ];
			size2 -= manysize[ now1 ];
			now1++;
			now1 %= n;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio( false );
	cin.tie( 0 );
#ifdef WIN32
	
#endif
	cin >> n;
	manysize.resize( n );
	for ( int i = 0; i < n; i++ ) {
		cin >> manysize[ i ];
	}
	solve();
	return 0;
}