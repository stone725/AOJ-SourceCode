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
	int m, t, p, r;
	vector<pair<PII, int> > _team;
	map<PII, int> ma;
	while ( ~scanf( "%d %d %d %d", &m, &t, &p, &r ) && m && t && p ) {
		_team.resize( t );
		for ( int i = 0; i < t; i++ ) {
			_team[ i ] = make_pair( PII( 0, 0 ), i + 1 );
		}
		for ( int i = 0; i < r; i++ ) {
			int tid, pid, time, j;
			scanf( "%d %d %d %d", &time, &tid, &pid, &j );
			if ( j ) {
				ma[ PII( tid, pid ) ]++;
			}
			else {
				_team[ tid - 1 ].first.first++;
				_team[ tid - 1 ].first.second -= time + ma[ PII( tid, pid ) ] * 20;
			}
		}
		sort( _team.rbegin(), _team.rend() );
		for ( int i = 0; i < t - 1; i++ ) {
			printf( "%d", _team[ i ].second );
			if ( _team[ i ].first == _team[ i + 1 ].first ) {
				printf( "=" );
			}
			else {
				printf( "," );
			}
		}
		printf( "%d\n", _team[ t - 1 ].second );
		ma.clear();
	}
	return 0;
}