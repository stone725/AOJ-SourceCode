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
	int n;
	string str;
	string root;
	scanf( "%d", &n );
	while ( n-- ) {
		cin >> root;
		cin >> str;
		string copy_root = root;
		sort( copy_root.begin(), copy_root.end() );
		int move = ( upper_bound( copy_root.begin(), copy_root.end(), 'M' ) - lower_bound( copy_root.begin(), copy_root.end(), 'M' ) ) - ( upper_bound( copy_root.begin(), copy_root.end(), 'P' ) - lower_bound( copy_root.begin(), copy_root.end(), 'P' ) ) - 6;
		move %= 10;
		reverse( root.begin(), root.end() );
		for ( int i = 0; i < root.size(); i++ ) {
			if ( root[ i ] == 'A' ) {
				reverse( str.begin(), str.end() );
			}
			if ( root[ i ] == 'J' ) {
				str = str[ str.size() - 1 ] + str.substr( 0, str.size() - 1 );
			}
			if ( root[ i ] == 'C' ) {
				str = str.substr( 1, str.size() - 1 ) + str[ 0 ];
			}
			if ( root[ i ] == 'E' ) {
				if ( str.size() % 2 == 0 ) {
					str = str.substr( str.size() / 2, str.size() / 2 ) + str.substr( 0, str.size() / 2 );
				}
				else {
					str = str.substr( str.size() / 2 + 1, str.size() / 2 ) + str[ str.size() / 2 ] + str.substr( 0, str.size() / 2 );
				}
			}
		}
		for ( int i = 0; i < str.size(); i++ ) {
			if ( str[ i ] >= '0' && str[ i ] <= '9' ) {
				str[ i ] -= '0';
				str[ i ] += 10000;
				str[ i ] += move;
				str[ i ] %= 10;
				str[ i ] += '0';
			}
		}
		printf( "%s\n", str.c_str() );
	}
	return 0;
}