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

string str;

bool iscollect( string s, bool istwo ) {
  sort( s.begin(), s.end() );
  string copys = s;
  for ( char i = '1'; i <= '9'; i++ ) {
    if ( upper_bound( s.begin(), s.end(), i ) - lower_bound( s.begin(), s.end(), i ) > 4 ) {
      return false;
    }
  }
  for ( char i = 0; i < s.size(); i++ ) {
    if ( s[ i ] == '0' ) {
      continue;
    }
    char oplus = s[ i ] + 1;
    char tplus = s[ i ] + 2;
    if ( binary_search( s.begin(), s.end(), oplus ) && binary_search( s.begin(), s.end(), tplus ) ) {
      s[ i ] = '0';
      s[ lower_bound( s.begin(), s.end(), oplus ) - s.begin() ] = '0';
      s[ lower_bound( s.begin(), s.end(), tplus ) - s.begin() ] = '0';
      if ( iscollect( s, istwo ) ) {
        return true;
      }
      s = copys;
    }
    if ( upper_bound( s.begin(), s.end(), s[ i ] ) - lower_bound( s.begin(), s.end(), s[ i ] ) >= 3 ) {
      s[ i ] = '0';
      s[ i + 1 ] = '0';
      s[ i + 2 ] = '0';
      if ( iscollect( s, istwo ) ) {
        return true;
      }
      s = copys;
    }
    if ( !istwo && upper_bound( s.begin(), s.end(), s[ i ] ) - lower_bound( s.begin(), s.end(), s[ i ] ) >= 2 ) {
      s[ i ] = '0';
      s[ i + 1 ] = '0';
      if ( iscollect( s, true ) ) {
        return true;
      }
      s = copys;
    }
    return false;
  }
  return istwo;
}

void solve() {
  bool writed = false;
  sort( str.begin(), str.end() );
  for ( str += "1"; str[ str.size() - 1 ] <= '9'; str[ str.size() - 1 ]++ ) {
    //dump( str[ str.size() - 1 ] );
    if ( iscollect( str, false ) ) {
      if ( writed ) {
        cout << " ";
      }
      cout << str[ str.size() - 1 ];
      writed = true;
    }
  }
  cout << ( writed ? "\n" : "0\n" );
}

int main() {
  ios::sync_with_stdio( false );
  cin.tie( 0 );
  while ( cin >> str ) {
    solve();
  }
  return 0;
}