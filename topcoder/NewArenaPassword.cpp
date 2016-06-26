// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are a huge fan of an online programming contest called SRM (Special Round Match). To participate in an SRM contest, you must first download an applet called Arena, log in to the Arena by entering your username and password, and start competing.

Recently, to avoid hackers' attacks on the Arena, SRM imposes a new rule for the users' passwords. From now on, the first K characters of each user's password must match its last K characters. In this way, if someone enters a password with different first and last K characters repeatedly, it can be considered an attack from hackers.

However, you love your old password and do not want to change many characters from it. You are given a string oldPassword representing your old password, and an int K. Return the minimum number of characters of oldPassword that must be changed so that the string containing the first K characters of oldPassword is equal to the string containing the last K characters of oldPassword.

DEFINITION
Class:NewArenaPassword
Method:minChange
Parameters:string, int
Returns:int
Method signature:int minChange(string oldPassword, int K)


CONSTRAINTS
-oldPassword will contain between 1 and 50 characters, inclusive.
-Each character of oldPassword will be a lowercase letter 'a' - 'z'.
-K will be between 1 and the number of characters of oldPassword, inclusive.


EXAMPLES

0)
"topcoderopen"
5

Returns: 3

A possible solution is changing your password into "topcndetopcn". To do this, you must change the 4th, 7th, and 10th characters (0-based) of "topcoderopen".

1)
"puyopuyo"
4

Returns: 0

Your old password already satisfies the new rule.

2)
"loool"
3

Returns: 1

The first and the last K characters can overlap. In this case, the only optimal solution is to change your password into "lolol".

3)
"arena"
5

Returns: 0



4)
"amavckdkz"
7

Returns: 5



*/
// END CUT HERE
#line 69 "NewArenaPassword.cpp"

#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <cmath>
#include <ctime>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<ll> >
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define RANGE(i,a,b) for(int i=(int)a,_b=(int)(b);(i)<_b;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class NewArenaPassword {
	public:
	int minChange(string P, int K) {
		int N=P.size();
		VVI w;
		REP(i, K) {
			int j=N-K+i;
			//cout<<i<<" :  "<<j<<endl;
			
			int ins=-1;
			REP(k, w.size()) {
				REP(l, w[k].size()) {
					if(w[k][l]==i) ins=k;
				}
			}
			if(ins==-1) {
				ins=w.size();
				VI a;
				a.PB(i);
				w.PB(a);
			}
			w[ins].PB(j);
		}
		//cout<<w<<endl;
		int ans = 0;
		REP(i, w.size()) {
			map<char, int> hi;
			REP(j, w[i].size()) {
				hi[P[w[i][j]]]++;
			}
			int mx=-1;
			FOR(e, hi) {
				mx=max(mx, e->second);
			}
			//cout<<hi<<endl;
			ans += w[i].size() - mx;
		}
		return ans;
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
#define END	 verify_case(_, NewArenaPassword().minChange(oldPassword, K));}
int main(){

CASE(0)
	string oldPassword = "topcoderopen"; 
	int K = 5; 
	int _ = 3; 
END
CASE(1)
	string oldPassword = "puyopuyo"; 
	int K = 4; 
	int _ = 0; 
END
CASE(2)
	string oldPassword = "loool"; 
	int K = 3; 
	int _ = 1; 
END
CASE(3)
	string oldPassword = "arena"; 
	int K = 5; 
	int _ = 0; 
END
//return 0;
CASE(4)
	string oldPassword = "amavckdkz"; 
	int K = 7; 
	int _ = 5; 
END
CASE(4)
	string oldPassword = "a"; 
	int K = 1; 
	int _ = 0; 
END
CASE(4)
	string oldPassword = "aba"; 
	int K = 2; 
	int _ = 1; 
END

}
// END CUT HERE


/*

1234 2
4321 1
1111 1
2222 0
3333 2
4444 0
5555 0
6666 0
7777 1
8888 0
9999 0

*/
