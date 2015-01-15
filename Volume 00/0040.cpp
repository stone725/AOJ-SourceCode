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


int gcd( int n, int m ) {
	if ( m == 0 ) {
		return n;
	}
	return gcd( m, n % m );
}

string Affine(string str, int a, int b) {
	string res = "";
	for ( int i = 0; i < str.size(); i++ ) {
		if ( str[ i ] >= 'a' && str[ i ] <= 'z' ) {
			char y = str[ i ] - 'a';
			res += ( char ) ( ( a * y + b ) % 26 ) + 'a';
		}
		else {
			res += str[ i ];
		}
	}
	return res;
}

int main() {
	int n;
	scanf( "%d\n", &n );
	while ( n-- ) {
		string str;
		getline( cin, str );
		for ( int i = 0; i < 100; i++ ) {
			if ( gcd( i, 26 ) != 1 ) {
				continue;
			}
			for ( int j = 0; j < 26; j++ ) {
				string s = Affine( str, i, j );
				if ( s.find( "that" ) != string::npos || s.find( "this" ) != string::npos ) {
					printf( "%s\n", s.c_str() );
					goto fin;
				}
			}
		}
	fin:;
	}
	return 0;
}