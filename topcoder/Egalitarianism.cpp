// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A kingdom has n citizens. Each one has some amount of money, a number of dollars denoted by a non-negative integer.

Citizens are numbered from 0 to n-1. Some citizens have friends. Their friendship network is described by a vector <string> called isFriend, such that if isFriend[i][j] == 'Y', the citizens numbered i and j are friends, and if isFriend[i][j] == 'N', these citizens are not friends.

The king decrees the following:

Each citizen's amount of money must be within d dollars of the amount of money belonging to any of his friends. In other words, a citizen with x dollars must not have any friends with less than x-d dollars or more than x+d dollars.

Given the number of citizens and their friendship network, what is the greatest possible money difference between any two people (not necessarily friends) in this kingdom? If there is a finite answer, return it. Otherwise, return -1.

DEFINITION
Class:Egalitarianism
Method:maxDifference
Parameters:vector <string>, int
Returns:int
Method signature:int maxDifference(vector <string> isFriend, int d)


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-d will be between 0 and 1,000, inclusive.
-isFriend will contain exactly n elements.
-Each element of isFriend will contain exactly n characters, each of which is either 'Y' or 'N'.
-For any i, isFriend[i][i] = 'N'.
-For any i and j, isFriend[i][j] = isFriend[j][i].


EXAMPLES

0)
{"NYN",
 "YNY",
 "NYN"}
10

Returns: 20

The kingdom has three citizens. Citizens 0 and 1 are friends. Also, citizens 1 and 2 are friends. The greatest possible money difference between any two citizens is $20, as in the following configuration: citizen 0 has $100; citizen 1 has $110; citizen 2 has $120.

1)
{"NN",
 "NN"}
1

Returns: -1

Since citizens 0 and 1 are not friends, there are no constraints between them.

2)
{"NNYNNN",
 "NNYNNN",
 "YYNYNN",
 "NNYNYY",
 "NNNYNN",
 "NNNYNN"}
1000

Returns: 3000



3)
{"NNYN",
 "NNNY",
 "YNNN",
 "NYNN"}
584

Returns: -1



4)
{"NYNYYYN",
 "YNNYYYN",
 "NNNNYNN",
 "YYNNYYN",
 "YYYYNNN",
 "YYNYNNY",
 "NNNNNYN"}
5

Returns: 20



5)
{"NYYNNNNYYYYNNNN",
 "YNNNYNNNNNNYYNN",
 "YNNYNYNNNNYNNNN",
 "NNYNNYNNNNNNNNN",
 "NYNNNNYNNYNNNNN",
 "NNYYNNYNNYNNNYN",
 "NNNNYYNNYNNNNNN",
 "YNNNNNNNNNYNNNN",
 "YNNNNNYNNNNNYNN",
 "YNNNYYNNNNNNNNY",
 "YNYNNNNYNNNNNNN",
 "NYNNNNNNNNNNNNY",
 "NYNNNNNNYNNNNYN",
 "NNNNNYNNNNNNYNN",
 "NNNNNNNNNYNYNNN"}

747

Returns: 2988



6)
{"NY",
 "YN"}
0

Returns: 0



*/
// END CUT HERE
#line 125 "Egalitarianism.cpp"

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



class Egalitarianism {
	public:
	int maxDifference(vector <string> F, int D) {
		int N=F.size();
		ll INF = 1LL<<50;
		VVI w(N, VI(N, INF));
		REP(i, N) w[i][i] = 0;
		REP(i, N) REP(j, N) if(F[i][j]=='Y') w[i][j] = 1;
		REP(k, N) REP(i, N) REP(j, N) w[i][j]=min(w[i][j], w[i][k]+w[k][j]);
		
		cout<<w<<endl;
		ll d = 0;
		REP(i, N) REP(j, N) d=max(d, w[i][j]);
		return d==INF ? -1 : d*D;
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
#define END	 verify_case(_, Egalitarianism().maxDifference(isFriend, d));}
int main(){

CASE(0)
	string isFriend_[] = {
 "NYN",
 "YNY",
 "NYN"};
	  vector <string> isFriend(isFriend_, isFriend_+sizeof(isFriend_)/sizeof(*isFriend_)); 
	int d = 10; 
	int _ = 20; 
END
//return 0;
CASE(1)
	string isFriend_[] = {"NN",
 "NN"};
	  vector <string> isFriend(isFriend_, isFriend_+sizeof(isFriend_)/sizeof(*isFriend_)); 
	int d = 1; 
	int _ = -1; 
END
CASE(2)
	string isFriend_[] = {"NNYNNN",
 "NNYNNN",
 "YYNYNN",
 "NNYNYY",
 "NNNYNN",
 "NNNYNN"};
	  vector <string> isFriend(isFriend_, isFriend_+sizeof(isFriend_)/sizeof(*isFriend_)); 
	int d = 1000; 
	int _ = 3000; 
END
CASE(3)
	string isFriend_[] = {"NNYN",
 "NNNY",
 "YNNN",
 "NYNN"};
	  vector <string> isFriend(isFriend_, isFriend_+sizeof(isFriend_)/sizeof(*isFriend_)); 
	int d = 584; 
	int _ = -1; 
END
CASE(4)
	string isFriend_[] = {"NYNYYYN",
 "YNNYYYN",
 "NNNNYNN",
 "YYNNYYN",
 "YYYYNNN",
 "YYNYNNY",
 "NNNNNYN"};
	  vector <string> isFriend(isFriend_, isFriend_+sizeof(isFriend_)/sizeof(*isFriend_)); 
	int d = 5; 
	int _ = 20; 
END
CASE(5)
	string isFriend_[] = {"NYYNNNNYYYYNNNN",
 "YNNNYNNNNNNYYNN",
 "YNNYNYNNNNYNNNN",
 "NNYNNYNNNNNNNNN",
 "NYNNNNYNNYNNNNN",
 "NNYYNNYNNYNNNYN",
 "NNNNYYNNYNNNNNN",
 "YNNNNNNNNNYNNNN",
 "YNNNNNYNNNNNYNN",
 "YNNNYYNNNNNNNNY",
 "YNYNNNNYNNNNNNN",
 "NYNNNNNNNNNNNNY",
 "NYNNNNNNYNNNNYN",
 "NNNNNYNNNNNNYNN",
 "NNNNNNNNNYNYNNN"}
;
	  vector <string> isFriend(isFriend_, isFriend_+sizeof(isFriend_)/sizeof(*isFriend_)); 
	int d = 747; 
	int _ = 2988; 
END
CASE(6)
	string isFriend_[] = {"NY",
 "YN"};
	  vector <string> isFriend(isFriend_, isFriend_+sizeof(isFriend_)/sizeof(*isFriend_)); 
	int d = 0; 
	int _ = 0; 
END

}
// END CUT HERE
