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
static const int INF = 1 << 30;
static const LL LL_INF = 1152921504606846976;
static const int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
static const int dy[] = { 0, -1, 0, 1, 1, 1, -1, -1 };



int ans;
string str;
set<string> can_str;

int main() {
	while ( cin >> str && str != "0" ) {
		int ans = -1;
		queue<pair<string, int> > q;
		q.push( make_pair( str, 0 ) );
		while ( q.size() ) {
			string s = q.front().first;
			int n = q.front().second;
			q.pop();
			if ( can_str.count( s ) ) {
				continue;
			}
			can_str.insert( s );
			bool can_break = true;
			for ( int i = 1; i < s.size(); i++ ) {
				if ( s[ i ] != s[ i - 1 ] ) {
					can_break = false;
					break;
				}
			}
			if ( can_break ) {
				ans = n;
				break;
			}
			for ( int i = 1; i < s.size(); i++ ) {
				if ( s[ i ] != s[ i - 1 ] ) {
					string s_copy = s;
					if ( s[ i ] == 'r' ) {
						if ( s[ i - 1 ] == 'g' ) {
							s[ i ] = s[ i - 1 ] = 'b';
						}
						else {
							s[ i ] = s[ i - 1 ] = 'g';
						}
					}
					else if ( s[ i ] == 'g' ) {
						if ( s[ i - 1 ] == 'r' ) {
							s[ i ] = s[ i - 1 ] = 'b';
						}
						else {
							s[ i ] = s[ i - 1 ] = 'r';
						}
					}
					else if ( s[ i ] == 'b' ) {
						if ( s[ i - 1 ] == 'g' ) {
							s[ i ] = s[ i - 1 ] = 'r';
						}
						else {
							s[ i ] = s[ i - 1 ] = 'g';
						}
					}
					q.push( make_pair( s, n + 1 ) );
					s = s_copy;
				}
			}
		}
		if ( ans < 0 ) {
			printf( "NA\n" );
		}
		else {
			printf( "%d\n", ans );
		}
		can_str.clear();
	}
	return 0;
}