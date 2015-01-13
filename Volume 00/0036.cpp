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
static const int INF = 1 << 30;
static const LL LL_INF = 1152921504606846976;
static const int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
static const int dy[] = { 0, -1, 0, 1, 1, 1, -1, -1 };

string s[7][4] =
{
	{
		"1100",
		"1100",
		"0000",
		"0000"
	},
	{
		"1000",
		"1000",
		"1000",
		"1000"
	},
	{
		"1111",
		"0000",
		"0000",
		"0000"
	},
	{
		"0100",
		"1100",
		"1000",
		"0000"
	},
	{
		"1100",
		"0110",
		"0000",
		"0000"
	},
	{
		"1000",
		"1100",
		"0100",
		"0000"
	},
	{
		"0110",
		"1100",
		"0000",
		"0000"
	}
};
string Add = "00000000000";

int main() {
	string str;
	while ( cin >> str ) {
		VS d;
		d.push_back( str + "000" );
		for ( int i = 0; i < 7; i++ ) {
			cin >> str;
			d.push_back( str + "000" );
		}
		d.push_back( Add );
		d.push_back( Add );
		d.push_back( Add );
		bool break_check = false;
		for ( int i = 0; i < 8; i++ ) {
			for ( int j = 0; j < 8; j++ ) {
				for ( int k = 0; k < 7; k++ ) {
					break_check = true;
					for ( int l = i; l < i + 4; l++ ) {
						if ( d[ l ].substr( j, 4 ) != s[ k ][ l - i ] ) {
							break_check = false;
							break;
						}
					}
					if ( break_check ) {
						printf( "%c\n", k + 'A' );
						break;
					}
				}
				if ( break_check ) {
					break;
				}
			}
			if ( break_check ) {
				break;
			}
		}
	}
	return 0;
}