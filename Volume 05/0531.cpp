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
#define PB push_back
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

int n, h, w;
int X1[ 1000 ], Y1[ 1000 ], X2[ 1000 ], Y2[ 1000 ];

bool fld[ 3001 ][ 3001 ];

int compress( int *x1, int *x2, int w ) {
  vector<int> xs;
  for ( int i = 0; i < n; i++ ) {
    for ( int d = -1; d <= 1; d++ ) {
      int tx1 = x1[ i ] + d, tx2 = x2[ i ] + d;
      if ( 0 <= tx1 && tx1 < w ) {
        xs.PB( tx1 );
      }
      if ( 0 <= tx2 && tx2 < w ) {
        xs.PB( tx2 );
      }
    }
  }
  sort( xs.begin(), xs.end() );
  xs.erase( unique( xs.begin(), xs.end() ), xs.end() );
  for ( int i = 0; i < n; i++ ) {
    x1[ i ] = find( xs.begin(), xs.end(), x1[ i ] ) - xs.begin();
    x2[ i ] = find( xs.begin(), xs.end(), x2[ i ] ) - xs.begin();
  }

  return xs.size();
}

void solve() {
  w = compress( X1, X2, w );
  h = compress( Y1, Y2, h );

  CLR( fld );

  for ( int i = 0; i < n; i++ ) {
    for ( int y = Y1[ i ]; y < Y2[ i ]; y++ ) {
      for ( int x = X1[ i ]; x < X2[ i ]; x++ ) {
        fld[ y ][ x ] = true;
      }
    }
  }
#ifdef _DEBUG
  for ( int y = 0; y < h; y++ ) {
    for ( int x = 0; x < w; x++ ) {
      cout << fld[ y ][ x ];
    }
    cout << "\n";
  }
#endif
  int ans = 0;
  for ( int y = 0; y < h; y++ ) {
    for ( int x = 0; x < w; x++ ) {
      if ( fld[ y ][ x ] ) {
        continue;
      }
      ans++;
      queue<PII> que;
      que.push( MP( x, y ) );
      while ( !que.empty() ) {
        int sx = que.front().first, sy = que.front().second;
        que.pop();

        for ( int i = 0; i < 4; i++ ) {
          int tx = sx + dx[ i ], ty = sy + dy[ i ];
          if ( tx < 0 || w == tx || ty < 0 || h == ty ) {
            continue;
          }
          if ( fld[ ty ][ tx ] ) {
            continue;
          }
          que.push( MP( tx, ty ) );
          fld[ ty ][ tx ] = true;
        }
      }
    }
  }
  cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio( false );
	cin.tie( 0 );
  while ( cin >> w >> h && h && w ) {
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
      cin >> X1[ i ] >> Y1[ i ] >> X2[ i ] >> Y2[ i ];
    }
    solve();
  }
	return 0;
}