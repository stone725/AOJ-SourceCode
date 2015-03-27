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

int N;
int info[ 50 ][ 9 ];
string name[ 50 ];

void solve() {
  vector<pair<double, string> > v( N );
  for ( int i = 0; i < N; i++ ) {
    v[ i ] = MP( info[ i ][ 0 ], name[ i ] );
    int cnt = 0;
    for ( int j = 1; j < 4; j++ ) {
      cnt += info[ i ][ j ];
    }
    for ( int k = 4; k < 6; k++ ) {
      cnt += info[ i ][ k ] * info[ i ][ 8 ];
    }
    v[ i ].first -= info[ i ][ 6 ] * info[ i ][ 7 ] * info[i][ 8 ];
    v[ i ].first /= cnt;
  }
  sort( v.begin(), v.end() );
  for ( int i = 0; i < N; i++ ) {
    cout << v[ i ].second << "\n";
  }
  cout << "#\n";
}

int main() {
	ios::sync_with_stdio( false );
	cin.tie( 0 );
  while ( cin >> N && N ) {
    for ( int i = 0; i < N; i++ ) {
      cin >> name[ i ];
      for ( int j = 0; j < 9; j++ ) {
        cin >> info[ i ][ j ];
      }
    }
    solve();
  }
	return 0;
}