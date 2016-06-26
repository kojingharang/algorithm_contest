#include <string>
#include <vector>
#include <cmath>
#include <memory.h>
#include <numeric>
#include <cctype>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <queue>
#include <fstream>
#include <sstream>
#include <stack>
#include <cassert>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = m; i < n; i++)
#define sqr(x) ((x) * (x))
const int INF = 1 << 28;
const double EPS = 1e-10;
const ll mod = 1000 * 1000 * 1000 + 7;
 
int allwhite(vector<string> &grid){
  rep(i, grid.size())rep(j, grid[0].size()) if(grid[i][j] == 'B') return 0;
  return 1;
}
 
int allblack(vector<string> &grid){
  rep(i, grid.size())rep(j, grid[0].size()) if(grid[i][j] == 'W') return 0;
  return 1;
}
 
vector<string>  trans_grid(vector<string> &grid){
  int n = grid.size();
  int m = grid[0].size();
  vector<string> res = vector<string>(m, string(n, '?'));
  rep(i, m)rep(j, n){
    res[i][j] = grid[n-1-j][i];
  }
  cout << n << " " << m << endl;
  rep(i, m){
        cout  << res[i] << endl;
  }
  return res;
}
 
ll dp[100][100][2];
 
ll calc(int r, int pr, int f, int n, int m, const vector<string> &grid ){
  if(r == n){
    return f;
  }
  if(dp[r][pr][f] != -1) return dp[r][pr][f];
  ll &res = dp[r][pr][f] = 0;
  rep(i, pr + 1){
    bool ok = true;
    for(int j = 0; j < i; j++) if(grid[r][j] == 'W') ok = false;
    for(int j = i; j < m; j++) if(grid[r][j] == 'B') ok = false;
    if(ok && !(i == 0 && r == 0)){
      res += calc(r + 1, i, f || (i < pr && r > 0 ), n, m, grid);
      res %= mod;
    }
  }
  return res;
}
 
class TwoConvexShapes {
public:
  int countWays(vector <string> grid) {
    ll res = allwhite(grid) + allblack(grid);
    rep(i, 4){
      memset(dp, -1, sizeof(dp));
      ll num = calc(0, grid[0].size(), 0, grid.size(), grid[0].size(), grid);
      cout << num << endl;
      res += num;
      grid = trans_grid(grid); 
    }
    return res % mod;
  }
    
 
};
 
// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//mplate<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// os << "{ ";
// for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
// os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, TwoConvexShapes().countWays(grid));}
int main(){

CASE(0)
	string grid_[] = {"????"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 8; 
END
CASE(0)
	string grid_[] = {"??",
 "??"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 14; 
END
CASE(1)
	string grid_[] = {"B?",
 "??"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 7; 
END
CASE(2)
	string grid_[] = {"WWB",
 "WWW",
 "WWW",
 "WWW"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 1; 
END
CASE(3)
	string grid_[] = {"BBBBBB",
 "WWBBBB",
 "WBBBBB"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 0; 
END
CASE(4)
	string grid_[] = {"?BB?",
 "BBBB",
 "?BB?"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 5; 
END
CASE(5)
	string grid_[] = {"?WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "B?WWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BB?WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBB?WWWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBB?WWWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBB?WWWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBB?WWWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBB?WWWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBB?WWWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBB?WWWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBB?WWWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBB?WWWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBB?WWWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBB?WWWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBB?WWWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBB?WWWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBB?WWWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBB?WWWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBB?WWWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBB?WWWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBB?WWWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBB?WWWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBB?WWWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBB?WWWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBB?WWWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBB?WWWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBB?WWWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBB?WWW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBB?WW",
 "BBBBBBBBBBBBBBBBBBBBBBBBBBBBB?W"};
	  vector <string> grid(grid_, grid_+sizeof(grid_)/sizeof(*grid_)); 
	int _ = 73741817; 
END

}
// END CUT HERE
