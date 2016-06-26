// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There is a long narrow storehouse.
The storehouse is divided into a sequence of N identical sectors, labeled 0 through N-1.
Each sector is large enough to contain a single container.
Currently, some sectors are empty and some sectors are filled by containers.
The storehouse also contains a surveillance system that is described below.

We are going to break into the storehouse.
As a part of preparation for the heist, we already found out some information about the warehouse.
In particular, we know exactly how the containers are currently placed in the warehouse.
You are given a string containers consisting of N characters.
For each i, character i of containers is 'X' if sector i contains a container, and it is '-' if sector i is empty.

We also discovered some information about the surveillance system.
The system consists of several hidden cameras.
You are given a int L with the following meaning:
Each of the cameras monitors exactly L consecutive sectors.
The segments of sectors monitored by different cameras might overlap, but no two cameras watch exactly the same segment.
(In other words, each sector may be monitored by multiple cameras, but each camera monitors a different set of consecutive sectors.)

Finally, we know something about what the cameras currently see.
You are given a vector <int> reports.
Each element of reports corresponds to one of the cameras (in no particular order).
More precisely, reports[i] is the number of containers stored in the sectors monitored by the corresponding camera.

It is guaranteed that all our information is correct and consistent.

Your task is to use the provided information to deduce which sectors are monitored by at least one surveillance camera.
Return a string containing N characters.
For each i, character i of the return value should be one of '+', '?', and '-'.
Character '+' represents that sector i is certainly monitored by at least one camera.
Character '-' represents that sector i is certainly not monitored by any of the cameras.
Character '?' represents the remaining case: given the information we have, it is possible that sector i is monitored, but it is also possible that it is not monitored.

DEFINITION
Class:SurveillanceSystem
Method:getContainerInfo
Parameters:string, vector <int>, int
Returns:string
Method signature:string getContainerInfo(string containers, vector <int> reports, int L)


CONSTRAINTS
-containers will contain N elements, where N is between 1 and 50, inclusive.
-Each character in containers will be either 'X' or '-'.
-L will be between 1 and N, inclusive.
-reports will contain between 1 and N-L+1 elements, inclusive.
-Each element of reports will be between 0 and L, inclusive.
-The given information will be consistent.


EXAMPLES

0)
"-X--XX"
{1, 2}
3

Returns: "??++++"

This storehouse has 6 sectors.
There are containers in sectors 1, 4, and 5.
There are two cameras: camera #0 monitors 1 container, and camera #1 monitors 2 containers.
Clearly, camera #1 must be watching sectors 3, 4, and 5.
Camera #0 may be watching sectors (0, 1, 2), (1, 2, 3), or (2, 3, 4).
Thus, camera #0 is surely monitoring sector 2.
Sectors 0 and 1 may or may not be monitored.

1)
"-XXXXX-"
{2}
3

Returns: "???-???"

The camera is monitoring either the leftmost or the rightmost segment, thus the middle sector is surely not under surveillance.

2)
"------X-XX-"
{3, 0, 2, 0}
5

Returns: "++++++++++?"

We can deduce that cameras #1 and #3 are watching segments (0, 1, 2, 3, 4) and (1, 2, 3, 4, 5). Camera #2 is monitoring the segment (4, 5, 6, 7, 8), since this is the only segment with two occupied sectors. Camera #0 is either watching (5, 6, 7, 8, 9) or (6, 7, 8, 9, 10), thus the rightmost sector might have slipped from the surveillance.

3)
"-XXXXX---X--"
{2, 1, 0, 1}
3

Returns: "???-??++++??"



4)
"-XX--X-XX-X-X--X---XX-X---XXXX-----X"
{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}
7

Returns: "???++++?++++++++++++++++++++??????--"



*/
// END CUT HERE
#line 110 "SurveillanceSystem.cpp"

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



class SurveillanceSystem {
	public:
	string getContainerInfo(string C, vector <int> R, int L) {
		map<int, int> hi;
		int N=C.size();
		string ans(N, '-');
		REP(i, R.size()) hi[R[i]]++;
		FOR(e, hi) {
			int match=0;
			VI w(N);
			REP(i, N-L+1) {
				if(count(&C[i], &C[i+L], 'X')==e->first) {
					match++;
					REP(j, L) w[i+j]++;
				}
			}
			REP(i, N) {
				if(w[i]>=match-(e->second-1)) ans[i]='+';
				else if(w[i]>0 && ans[i]!='+') ans[i]='?';
			}
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
void verify_case(const string& Expected, const string& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, SurveillanceSystem().getContainerInfo(containers, reports, L));}
int main(){

CASE(0)
	string containers = "-X--XX"; 
	int reports_[] = {1, 2};
	  vector <int> reports(reports_, reports_+sizeof(reports_)/sizeof(*reports_)); 
	int L = 3; 
	string _ = "??++++"; 
END
//return 0;

CASE(1)
	string containers = "-XXXXX-"; 
	int reports_[] = {2};
	  vector <int> reports(reports_, reports_+sizeof(reports_)/sizeof(*reports_)); 
	int L = 3; 
	string _ = "???-???"; 
END
CASE(2)
	string containers = "------X-XX-"; 
	int reports_[] = {3, 0, 2, 0};
	  vector <int> reports(reports_, reports_+sizeof(reports_)/sizeof(*reports_)); 
	int L = 5; 
	string _ = "++++++++++?"; 
END
CASE(3)
	string containers = "-XXXXX---X--"; 
	int reports_[] = {2, 1, 0, 1};
	  vector <int> reports(reports_, reports_+sizeof(reports_)/sizeof(*reports_)); 
	int L = 3; 
	string _ = "???-??++++??"; 
END
CASE(4)
	string containers = "-XX--X-XX-X-X--X---XX-X---XXXX-----X"; 
	int reports_[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	  vector <int> reports(reports_, reports_+sizeof(reports_)/sizeof(*reports_)); 
	int L = 7; 
	string _ = "???++++?++++++++++++++++++++??????--"; 
END
CASE(4)
	string containers = "--XX----XX"; 
	int reports_[] = {2,2,2,2};
	  vector <int> reports(reports_, reports_+sizeof(reports_)/sizeof(*reports_)); 
	int L = 4; 
	string _ = "------"; 
END

}
// END CUT HERE
