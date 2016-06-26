// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Your language school is starting a new semester, and each student must select a time schedule.  You are given a vector <int> groups, where the i-th element is the number of students who selected the i-th schedule.  Your school has a rule stating that the number of students assigned to each schedule must be between minSize and maxSize, inclusive.  However, this rule was not enforced properly during the sign up phase.  It is your job to reassign students in such a way that the rule is satisfied.  A reassignment is defined as removing a student from one time schedule and placing him in a different time schedule.  Return the minimal number of students you must reassign, or return -1 if it is impossible to satisfy the rule.  Note that you may not create new schedules or delete existing schedules.

DEFINITION
Class:CreateGroups
Method:minChanges
Parameters:vector <int>, int, int
Returns:int
Method signature:int minChanges(vector <int> groups, int minSize, int maxSize)


CONSTRAINTS
-groups will contain between 1 and 50 elements, inclusive.
-Each element of groups will be between 1 and 1,000,000, inclusive.
-maxSize will be between 1 and 1,000,000, inclusive.
-minSize will be between 1 and maxSize, inclusive.


EXAMPLES

0)
{10,20}
10
15

Returns: 5

We can move 5 students from the second time schedule to the first. Both schedules will then have a size of 15, which is the maximum allowed size.

1)
{20,8,6}
10
15

Returns: 6

We can move 2 students from the first schedule to the second, and another 4 students from the first schedule to the third.  The sizes of the resulting schedules will be 14, 10 and 10.

2)
{10,20,30}
1
18

Returns: -1

There is no solution possible here.  We have 60 students in 3 time schedules, so it is impossible to have at most 18 students per schedule.

3)
{50,10,20,20,5}
15
30

Returns: 20



4)
{100,200,301}
200
200

Returns: -1



5)
{1,10,10}	
9
20

Returns: -1



6)
{55,33,45,71,27,89,16,14,61}
33
56

Returns: 53



7)
{49,60,36,34,36,52,60,43,52,59}
45
51

Returns: 31



8)
{5,5,5,5,5}
5
5

Returns: 0



*/
// END CUT HERE
#line 107 "CreateGroups.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class CreateGroups {
	public:
	int minChanges(vector <int> gr, int mi, int ma) {
		int musti=0, mustd=0, cani=0, cand=0;
		FOR(v, gr) {
			musti += max(0, mi-*v);
			mustd += max(0, *v-ma);
			cani  += max(0, ma-*v);
			cand  += max(0, *v-mi);
		}
		if(musti <= cani && musti <= cand && mustd <= cand && mustd <= cani) return max(musti, mustd);
		return -1;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, CreateGroups().minChanges(groups, minSize, maxSize));}
int main(){

CASE(0)
	int groups_[] = {10,20};
	  vector <int> groups(groups_, groups_+sizeof(groups_)/sizeof(*groups_)); 
	int minSize = 10; 
	int maxSize = 15; 
	int _ = 5; 
END
CASE(1)
	int groups_[] = {20,8,6};
	  vector <int> groups(groups_, groups_+sizeof(groups_)/sizeof(*groups_)); 
	int minSize = 10; 
	int maxSize = 15; 
	int _ = 6; 
END
//CASE(2)
//	int groups_[] = {10,20,30};
//	  vector <int> groups(groups_, groups_+sizeof(groups_)/sizeof(*groups_)); 
//	int minSize = 1; 
//	int maxSize = 18; 
//	int _ = -1; 
//END
//CASE(3)
//	int groups_[] = {50,10,20,20,5};
//	  vector <int> groups(groups_, groups_+sizeof(groups_)/sizeof(*groups_)); 
//	int minSize = 15; 
//	int maxSize = 30; 
//	int _ = 20; 
//END
//CASE(4)
//	int groups_[] = {100,200,301};
//	  vector <int> groups(groups_, groups_+sizeof(groups_)/sizeof(*groups_)); 
//	int minSize = 200; 
//	int maxSize = 200; 
//	int _ = -1; 
//END
//CASE(5)
//	int groups_[] = {1,10,10}	;
//	  vector <int> groups(groups_, groups_+sizeof(groups_)/sizeof(*groups_)); 
//	int minSize = 9; 
//	int maxSize = 20; 
//	int _ = -1; 
//END
CASE(6)
	int groups_[] = {55,33,45,71,27,89,16,14,61};
	  vector <int> groups(groups_, groups_+sizeof(groups_)/sizeof(*groups_)); 
	int minSize = 33; 
	int maxSize = 56; 
	int _ = 53; 
END
CASE(7)
	int groups_[] = {49,60,36,34,36,52,60,43,52,59};
	  vector <int> groups(groups_, groups_+sizeof(groups_)/sizeof(*groups_)); 
	int minSize = 45; 
	int maxSize = 51; 
	int _ = 31; 
END
CASE(8)
	int groups_[] = {5,5,5,5,5};
	  vector <int> groups(groups_, groups_+sizeof(groups_)/sizeof(*groups_)); 
	int minSize = 5; 
	int maxSize = 5; 
	int _ = 0; 
END

}
// END CUT HERE
