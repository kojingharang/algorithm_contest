// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// John takes part in a regional olympiad in informatics together with other participants.
At the contest each participant gains some nonnegative integer score.
Each participant (except for John) is assigned to one of the N contest rooms (numbered from 0 to N-1) and John is the only contestant in the room number N.
John has no idea how many participants are in the other rooms.
For each of the other rooms he only knows the sum of scores of all participants in it.


You are given a vector <int> sums containing N elements and an int k.
The i-th element of sums is the sum of participants' scores in the i-th contest room.
Return the minimal score John has to gain to be sure that there are at most k participants with strictly higher scores.


DEFINITION
Class:TheOlympiadInInformatics
Method:find
Parameters:vector <int>, int
Returns:int
Method signature:int find(vector <int> sums, int k)


CONSTRAINTS
-sums will contain between 1 and 47 elements, inclusive.
-Each element of sums will be between 0 and 1,000,000,000, inclusive.
-k will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{4, 7, 0, 5}
0

Returns: 7

John has to gain at least 7 points, because there might be a competitor with 7 points in room number 1 (0-based index).

1)
{4, 7}
2

Returns: 3

It is possible that there are three contestants who scored more than 2 points: there can be one in room 0 and two more in room 1.
There can only be at most two contestants who scored more than 3 points: there can be at most one such contestant in each of the two rooms.
(Note that the score of each contestant has to be an integer.)
Therefore, John has to score at least 3 points.


2)
{999999999}
1000000000

Returns: 0

Here it is enough to gain 0 points.

3)
{95, 23, 87, 23, 82, 78, 59, 44, 12}
70

Returns: 6



*/
// END CUT HERE
#line 71 "TheOlympiadInInformatics.cpp"

#include <vector>
#include <map>
#include <set>
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
#include <cctype>
#include <cstdio>
#include <cassert>
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class TheOlympiadInInformatics {
	public:
	int find(vector <int> sums, int k) {
		ll lo=0, hi=1LL<<50;
		while(lo+1<hi) {
			ll mid = (lo+hi)/2;
			ll nn = 0;
			FOR(e, sums) {
				nn += *e/mid;
			}
			if(nn<=k) hi=mid; else lo=mid;
		}
		return hi-1;
	}
	int find2(vector <int> sums, int k) {
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
#define END	 verify_case(_, TheOlympiadInInformatics().find(sums, k));}
int main(){
int si=UNIFORM_INT(1, 47);
REP(i, si) {
	int el=UNIFORM_INT(0, 1000000000);
	int el=UNIFORM_INT(0, 1000000000);
}
CASE(0)
	int sums_[] = {4, 7, 0, 5};
	  vector <int> sums(sums_, sums_+sizeof(sums_)/sizeof(*sums_)); 
	int k = 0; 
	int _ = 7; 
END
CASE(1)
	int sums_[] = {4, 7};
	  vector <int> sums(sums_, sums_+sizeof(sums_)/sizeof(*sums_)); 
	int k = 2; 
	int _ = 3; 
END
CASE(2)
	int sums_[] = {999999999};
	  vector <int> sums(sums_, sums_+sizeof(sums_)/sizeof(*sums_)); 
	int k = 1000000000; 
	int _ = 0; 
END
CASE(3)
	int sums_[] = {95, 23, 87, 23, 82, 78, 59, 44, 12};
	  vector <int> sums(sums_, sums_+sizeof(sums_)/sizeof(*sums_)); 
	int k = 70; 
	int _ = 6; 
END
CASE(3)
	int sums_[] = {0, 0, 0};
	  vector <int> sums(sums_, sums_+sizeof(sums_)/sizeof(*sums_)); 
	int k = 0; 
	int _ = 0; 
END

}
// END CUT HERE
