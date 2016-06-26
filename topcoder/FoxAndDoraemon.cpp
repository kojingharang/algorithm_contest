// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel has lots of homework to do.
The homework consists of some mutually independent tasks. Different tasks may take different amounts of time to complete.
You are given a vector <int> workCost. For each i, the i-th task takes workCost[i] seconds to complete.
She would like to attend a party and meet her friends, thus she wants to finish all tasks as quickly as possible.



The main problem is that all foxes, including Ciel, really hate doing homework.
Each fox is only willing to do one of the tasks.
Luckily, Doraemon, a robotic cat from the 22nd century, gave Fox Ciel a split hammer: 
a magic gadget which can split any fox into two foxes.



You are given an int splitCost.
Using the split hammer on a fox is instantaneous.
Once a hammer is used on a fox, the fox starts to split.
After splitCost seconds she will turn into two foxes -- the original fox and another completely new fox.
While a fox is splitting, it is not allowed to use the hammer on her again.



The work on a task cannot be interrupted: once a fox starts working on a task, she must finish it.
It is not allowed for multiple foxes to cooperate on the same task.
A fox cannot work on a task while she is being split using the hammer.
It is possible to split the same fox multiple times.
It is possible to split a fox both before and after she solves one of the tasks.



Compute and return the smallest amount of time in which the foxes can solve all the tasks.

DEFINITION
Class:FoxAndDoraemon
Method:minTime
Parameters:vector <int>, int
Returns:int
Method signature:int minTime(vector <int> workCost, int splitCost)


CONSTRAINTS
-workCost will contain between 1 and 50 elements, inclusive.
-Each element in workCost will be between 1 and 3,600, inclusive.
-splitCost will be between 1 and 3,600, inclusive.


EXAMPLES

0)
{1,2}
1000

Returns: 1002

Fox Ciel is only willing to do one task. She is given two tasks, therefore she must split once. 
The optimal strategy is to use the split hammer immediately.
After 1000 seconds we have two foxes. 
Each of them will do one of the tasks in parallel.

1)
{3,6,9,12}
1000

Returns: 2012



2)
{1000,100,10,1}
1

Returns: 1001

One optimal solution:

We start with a single fox A.
Immediatelly, we use the split hammer.
In 1 second we will have foxes A and B.
Fox A will start working on task 0.
At the same time, fox B will start working on task 1.
Fox B will be done 101 seconds from the start.
As she already solved a task, we need more foxes to do tasks 2 and 3.
Therefore we use the split hammer on B.
At 102 seconds from the start we will get a new fox C and let her solve task 2.
We use the split hammer on B again.
At 103 seconds from the start we will get a new fox D and let her solve task 3.


3)
{1712,1911,1703,1610,1697,1612}
100

Returns: 2012



4)
{3000,3000,3000,3000,3000,3000,3000,3000,3000,3000}
3000

Returns: 15000



5)
{58}
3600

Returns: 58



*/
// END CUT HERE
#line 119 "FoxAndDoraemon.cpp"

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
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


vector <int> WC;
int SC;
int N;
map<PII, int> memo;
class FoxAndDoraemon {
	public:
	// [i0, i1)
	int f(int i0, int i1) {
		PII key=MP(i0, i1);
		if(memo.count(key)) return memo[key];
		int rest = i1-i0;
		if(rest<=0) return memo[key] = 0;
		if(rest==1) return memo[key] = WC[i0];
		if(rest==2) return memo[key] = SC+max(WC[i0], WC[i0+1]);
		if(rest==3) return memo[key] = SC+max(WC[i0], SC+max/*min*/(WC[i0+1], WC[i0+2]));
		// >=4
		int ans = 1000000;
		for(int i=1;i<rest;i++) {
			int c = SC+max(f(i0, i0+i), f(i0+i, i1));
			ans = min(ans, c);
		}
		return memo[key] = ans;
	}
	int minTime(vector <int> _WC, int _SC) {
		sort(ALLR(_WC));
		WC=_WC;
		SC=_SC;
		memo.clear();
		N=WC.size();
		int ans = f(0, N);
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
#define END	 verify_case(_, FoxAndDoraemon().minTime(workCost, splitCost));}
int main(){

CASE(0)
	int workCost_[] = {1,2};
	  vector <int> workCost(workCost_, workCost_+sizeof(workCost_)/sizeof(*workCost_)); 
	int splitCost = 1000; 
	int _ = 1002; 
END
CASE(1)
	int workCost_[] = {3,6,9,12};
	  vector <int> workCost(workCost_, workCost_+sizeof(workCost_)/sizeof(*workCost_)); 
	int splitCost = 1000; 
	int _ = 2012; 
END
CASE(2)
	int workCost_[] = {1000,100,10,1};
	  vector <int> workCost(workCost_, workCost_+sizeof(workCost_)/sizeof(*workCost_)); 
	int splitCost = 1; 
	int _ = 1001; 
END
CASE(3)
	int workCost_[] = {1712,1911,1703,1610,1697,1612};
	  vector <int> workCost(workCost_, workCost_+sizeof(workCost_)/sizeof(*workCost_)); 
	int splitCost = 100; 
	int _ = 2012; 
END
CASE(4)
	int workCost_[] = {3000,3000,3000,3000,3000,3000,3000,3000,3000,3000};
	  vector <int> workCost(workCost_, workCost_+sizeof(workCost_)/sizeof(*workCost_)); 
	int splitCost = 3000; 
	int _ = 15000; 
END
CASE(5)
	int workCost_[] = {58};
	  vector <int> workCost(workCost_, workCost_+sizeof(workCost_)/sizeof(*workCost_)); 
	int splitCost = 3600; 
	int _ = 58; 
END
CASE(4)
	int workCost_[] = {3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,};
	  vector <int> workCost(workCost_, workCost_+sizeof(workCost_)/sizeof(*workCost_)); 
	int splitCost = 3600; 
	int _ = 25200; 
END
CASE(5)
	int workCost_[] = {3,2,1,1};
	  vector <int> workCost(workCost_, workCost_+sizeof(workCost_)/sizeof(*workCost_)); 
	int splitCost = 1; 
	int _ = 4; 
END
CASE(5)
	int workCost_[] = {3,3,1,1};
	  vector <int> workCost(workCost_, workCost_+sizeof(workCost_)/sizeof(*workCost_)); 
	int splitCost = 1; 
	int _ = 5; 
END

}
// END CUT HERE

/*

DP じゃないコードの場合、以下をなげる
3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600,3600
3600

*/
