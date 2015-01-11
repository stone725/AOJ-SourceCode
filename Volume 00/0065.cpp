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



string s;
map<int, int> b_m;
map<int, int> m;

int main() {
	while ( getline( cin, s ) && s != "" ) {
		int a = 0;
		for ( int i = 0; i < s.size(); i++ ) {
			if ( s[ i ] != ',' ) {
				a *= 10;
				a += s[ i ] - '0';
			}
			else {
				b_m[ a ]++;
			}
		}
	}
	while ( getline( cin, s ) && s != "" ) {
		int a = 0;
		for ( int i = 0; i < s.size(); i++ ) {
			if ( s[ i ] != ',' ) {
				a *= 10;
				a += s[ i ] - '0';
			}
			else {
				m[ a ]++;
			}
		}
	}
	for ( map<int, int>::iterator i = m.begin(); i != m.end(); i++ ) {
		int number = i->first;
		if ( b_m[ number ] ) {
			printf( "%d %d\n", number, m[ number ] + b_m[ number ] );
		}
	}
	return 0;
}