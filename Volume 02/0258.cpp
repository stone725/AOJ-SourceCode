#include <bits/stdc++.h>
using namespace std;
#define FOR(i, s, n) for(int i = s; i < (int)n; ++i)
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
typedef complex<double> Point;
static const double EPS = 1e-10;
static const double PI = acos( -1.0 );
static const int mod = 1000000007;
static const int INF = 1 << 29;
static const LL LL_INF = 1ll << 60;
static const int dx[] = { -1, 0, 1, 0, 1, -1, 1, -1 };
static const int dy[] = { 0, -1, 0, 1, 1, 1, -1, -1 };

#ifdef WIN32
#define dump(x) cerr << #x << " = " << (x) << "\n"
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << "\n"
#else
#define dump(x)
#define debug(x)
#endif

int n;
VI h;

void input() {
  cin >> n;
  h.resize( n + 1 );
  for ( int i = 0; i <= n && n; i++ ) {
    cin >> h[ i ];
  }
}

bool check( int elnum ) {
  int d;
  if ( !elnum ) {
    d = h[ 2 ] - h[ 1 ];
  }
  else if ( elnum == 1 ) {
    d = h[ 2 ] - h[ 0 ];
  }
  else {
    d = h[ 1 ] - h[ 0 ];
  }
  for ( int i = 2; i <= n; i++ ) {
    if ( elnum == i ) {
      continue;
    }
    if ( elnum == i - 1 ) {
      if ( d != h[ i ] - h[ i - 2 ] ) {
        return false;
      }
    }
    else {
      if ( d != h[ i ] - h[ i - 1 ] ) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  for ( int i = 0; i <= n; i++ ) {
    if ( check( i ) ) {
      cout << h[ i ] << "\n";
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio( false );
  cin.tie( 0 );
  while ( true ) {
    input();
    if ( !n ) {
      break;
    }
#ifdef WIN32
    clock_t stime = clock();
#endif
    solve();
#ifdef WIN32
    clock_t etime = clock();
    cerr << "TIME : " << ( double ) ( etime - stime ) / CLOCKS_PER_SEC << "\n";
#endif
  }
return 0;
}