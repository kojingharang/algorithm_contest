// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A long time ago in a galaxy far, far away the Jedi Academy conducted a test to detect children with high Force sensitivy which would then be trained to become Jedi. The test was conducted in the Jedi Temple which had several floors. For each i, students[i] children have initially gathered at floor i (0-based). A Jedi could only manage to cope with at most K children located at the same floor. So, if there were between K+1 and 2K children at a floor, two Jedi would be required there; if there were between 2K+1 and 3K children, three Jedi were neccessary and so on.

To minimize the number of Jedi needed to supervise the test, it was decided to relocate some children. However, to avoid the mess, each child was only allowed to be relocated by at most one floor, i.e. he or she could stay on the same floor, go one floor down or go one floor up. Note that it is not possible to go a floor down from the first floor or a floor up from the last floor.

Determine and return the minimum number of Jedi supervisors needed after the relocation.

DEFINITION
Class:TheJediTest
Method:minimumSupervisors
Parameters:vector <int>, int
Returns:int
Method signature:int minimumSupervisors(vector <int> students, int K)


CONSTRAINTS
-students will contain between 1 and 20 elements, inclusive.
-Each element of students will be between 0 and 100,000,000, inclusive.
-K will be between 1 and 100,000,000, inclusive.


EXAMPLES

0)
{3, 6, 3}
4

Returns: 3

If the children stay the way they are, 4 Jedi will be required. A possible solution with only 3 observers needed is to send all the children to floor 1. Another optimal solution is to send one child from floor 1 to floor 0 and the others to floor 2.

1)
{1, 1, 1, 1}
4

Returns: 2

A single observer can watch four children. However, to gather at the same floor, at least one child would have to move more than one floor away from his or her initial location.

2)
{0, 0, 0, 0}
12345

Returns: 0

For the Jedi Academy, a bad day it was.

3)
{15, 0, 13, 4, 29, 6, 2}
7

Returns: 10

An optimal solution is to gather the children from floor 0 and floor 2 at floor 1, move the children from floor 3 and one child from floor 5 to floor 4 and move the children from the last floor 6 down to floor 5. The quantities of students at each floor will be {0, 28, 0, 0, 34, 7, 0}.

4)
{1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68}
114

Returns: 102138



*/
// END CUT HERE
#line 69 "TheJediTest.cpp"

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
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
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



class TheJediTest {
	public:
	int minimumSupervisors(vector <int> S, int K) {
		int N = S.size();
		VI w(N), ca(N);
		ll refsum = accumulate(ALL(S), 0);
		ll ans = 1LL<<60;
		REP(bit, 1<<N) {
			REP(i, N) w[i]=S[i],ca[i]=0;
			int ok=1;
			ll lans = 0;
			ll sum=0;
			REP(i, N) {
				if(((bit>>i)&1) && i<N-1) {
					int c = min(w[i], (w[i]+ca[i])%K);
					ca[i+1]+=c;
					w[i] -= c;
					int cc = K-(w[i]+ca[i]%K);
					if(w[i+1]>=cc) {
						w[i+1]-=cc;
						w[i]+=cc;
					}
				}
				w[i]+=ca[i];
				if((w[i]%K==0) != ((bit>>i)&1)) {ok=0;break;}
				lans += ((ll)w[i]+K-1)/K;
				sum += w[i];
			}
			if(ok) assert(sum==refsum);
			if(ok) ans = min(ans, lans);
			//if(ok)
			//cout<<bit<<" "<<w<<" -> "<<ans<<" OK="<<ok<<endl;
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
#define END	 verify_case(_, TheJediTest().minimumSupervisors(students, K));}
int main(){

CASE(0)
	int students_[] = {3, 6, 3};
	  vector <int> students(students_, students_+sizeof(students_)/sizeof(*students_)); 
	int K = 4; 
	int _ = 3; 
END
//return 0;
CASE(1)
	int students_[] = {1, 1, 1, 1};
	  vector <int> students(students_, students_+sizeof(students_)/sizeof(*students_)); 
	int K = 4; 
	int _ = 2; 
END
CASE(2)
	int students_[] = {0, 0, 0, 0};
	  vector <int> students(students_, students_+sizeof(students_)/sizeof(*students_)); 
	int K = 12345; 
	int _ = 0; 
END
CASE(3)
	int students_[] = {15, 0, 13, 4, 29, 6, 2};
	  vector <int> students(students_, students_+sizeof(students_)/sizeof(*students_)); 
	int K = 7; 
	int _ = 10; 
END
CASE(4)
	int students_[] = {1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68};
	  vector <int> students(students_, students_+sizeof(students_)/sizeof(*students_)); 
	int K = 114; 
	int _ = 102138; 
END
CASE(4)
	int students_[] = {100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,};
	  vector <int> students(students_, students_+sizeof(students_)/sizeof(*students_)); 
	int K = 1; 
	int _ = 20; 
END

}
// END CUT HERE
