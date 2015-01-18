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


map<PII, int> m;
int main() {
	vector<pair<PII, int> > team;
	int t, r, p;
	while ( ~scanf( "%d %d %d", &t, &p, &r ) && t && p && r ) {
		team.resize( t );
		for ( int i = 0; i < t; i++ ) {
			team[ i ] = pair<PII, int>( PII( 0, 0 ), -i - 1 );
		}
		for ( int i = 0; i < r; i++ ) {
			int tid, pid, time;
			string str;
			cin >> tid >> pid >> time >> str;
			if ( str == "WRONG" ) {
				m[ make_pair( tid, pid ) ]++;
			}
			else {
				team[ tid - 1 ].first.first++;
				team[ tid - 1 ].first.second -= ( m[ make_pair( tid, pid ) ] * 1200 ) + time;
			}
		}
		sort( team.rbegin(), team.rend() );
		for ( int i = 0; i < team.size(); i++ ) {
			printf( "%d %d %d\n", -team[ i ].second, team[ i ].first.first, -team[ i ].first.second );
		}

		m.clear();
	}
	return 0;
}