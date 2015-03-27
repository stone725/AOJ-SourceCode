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

string str[ 3 ];

void input() {
  for ( int i = 0; i < 3; i++ ) {
    cin >> str[ i ];
    if ( str[ i ] == "0" ) {
      break;
    }
  }
}

void solve() {
  if ( str[ 0 ][ 0 ] == str[ 1 ][ 1 ] && str[ 0 ][ 0 ] == str[ 2 ][ 2 ] && str[ 0 ][ 0 ] != '+' ) {
    cout << str[ 0 ][ 0 ] << "\n";
    return;
  }
  if ( str[ 0 ][ 2 ] == str[ 1 ][ 1 ] && str[ 0 ][ 2 ] == str[ 2 ][ 0 ] && str[ 0 ][ 2 ] != '+' ) {
    cout << str[ 0 ][ 2 ] << "\n";
    return;
  }

  for ( int i = 0; i < 3; i++ ) {
    if ( str[ i ][ 0 ] == str[ i ][ 1 ] && str[ i ][ 0 ] == str[ i ][ 2 ] && str[ i ][ 0 ] != '+' ) {
      cout << str[ i ][ 0 ] << "\n";
      return;
    }
    if ( str[ 0 ][ i ] == str[ 1 ][ i ] && str[ 0 ][ i ] == str[ 2 ][ i ] && str[ 0 ][ i ] != '+' ) {
      cout << str[ 0 ][ i ] << "\n";
      return;
    }
  }
  cout << "NA\n";
}

int main() {
  ios::sync_with_stdio( false );
  cin.tie( 0 );
  while ( true ) {
    input();
    if ( str[ 0 ] == "0" ) {
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