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
static const int mod = 10007;
static const int INF = 1 << 25;
static const LL LL_INF = 1152921504606846976;
static const int dx[] = { 1, -1, 0, 0,  1, -1,  1, -1 };
static const int dy[] = { 0, 0, 1, -1 , 1,  1, -1, -1 };
static const char Move[] = { 'E', 'W', 'N', 'S' };

int N, sum_tree[ 101 ][ 101 ], tree_mp[ 101 ][ 101 ], X, Y, ans = 0, W, H;

int main() {
	while ( ~scanf( "%d", &N ) && N ) {
		scanf( "%d %d", &W, &H );
		for ( int i = 0; i < N; i++ ) {
			scanf( "%d %d", &X, &Y );
			tree_mp[ Y ][ X ]++;
		}
		for ( int i = 1; i <= H; i++ ) {
			for ( int j = 1; j <= W; j++ ) {
				sum_tree[ i ][ j ] = sum_tree[ i - 1 ][ j ] + sum_tree[ i ][ j - 1 ] - sum_tree[ i - 1 ][ j - 1 ] + tree_mp[ i ][ j ];
			}
		}
		scanf( "%d %d", &X, &Y );
		for ( int i = Y; i <= H; i++ ) {
			for ( int j = X; j <= W; j++ ) {
				ans = max( ans, sum_tree[ i ][ j ] - sum_tree[ i - Y ][ j ] - sum_tree[ i ][ j - X ] + sum_tree[ i - Y ][ j - X ] );
			}
		}
		printf( "%d\n", ans );
		ans = 0;
		memset( tree_mp, 0, sizeof( tree_mp ) );
		memset( sum_tree, 0, sizeof( sum_tree ) );
	}
	return 0;
}