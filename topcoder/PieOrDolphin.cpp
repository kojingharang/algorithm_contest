// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// In this problem, some test cases have more than one correct output. We are using a special checker to verify that the output of your program is correct.

In a far away land, there are 50 programmers who work together in an office.
As it is usual among programmers, they are numbered 0 through 49.

Mr. Ivan is the town's celebrity.
The programmers like Mr. Ivan very much, so they invited him to the office.
Flattered, Ivan decided to visit the office each day for the next N days.
(We will number those days 0 through N-1, in order.)

Each day, Ivan brought two new toys with him to the office: one dolphin toy and one pie toy.
And each day, the programmers held a meeting in which two programmers were selected as the most productive ones that day.
One of them received a dolphin from Ivan, and the other one received a pie.
(Ivan made the choice who gets which toy.)

Today was the day of Ivan's last visit to the office.
After he handed over the last dolphin and the last pie, the programmers invited him to a farewell dinner.
During the dinner, each programmer calculated the absolute difference between the number of dolphins and the number of pies he or she received.
Then, they computed the sum of those differences.
Amazingly, it turned out to be the case that the sum of all those differences was the smallest sum possible (given the particular set of choices of pairs of programmers on each day).
The programmers were very amazed by Ivan's skill, but when they asked him about this, he modestly claimed that he just got lucky.

You are given two vector <int>s choice1 and choice2, each with N elements.
For each i, the programmers who received toys on day i were the programmers choice1[i] and choice2[i].

Find one way how to distribute the toys in such a way that the sum defined above is minimized.
Return a vector <int> with N elements.
For each i, element i of the returned vector <int> should be either 1 or 2.
The value 1 means that on day i the programmer choice1[i] should get the dolphin and the programmer choice2[i] should get the pie.
The value 2 is the opposite assignment of toys.

If there are multiple optimal distributions, you may return any of them.

DEFINITION
Class:PieOrDolphin
Method:Distribute
Parameters:vector <int>, vector <int>
Returns:vector <int>
Method signature:vector <int> Distribute(vector <int> choice1, vector <int> choice2)


CONSTRAINTS
-choice1 will contain between 1 and 1000 elements, inclusive.
-Each element in choice1 will be between 0 and 49, inclusive.
-choice2 will contain the same number of elements as choice1.
-Each element in choice2 will be between 0 and 49, inclusive.
-For each i, choice1[i] will not be equal to choice2[i].


EXAMPLES

0)
{10, 20, 10}
{20, 30, 20}

Returns: {2, 2, 1 }

According to the return value shown in the example, the toys were distributed as follows:

Day 0: programmer 10 gets a pie, programmer 20 gets a dolphin.
Day 1: programmer 20 gets a pie, programmer 30 gets a dolphin.
Day 2: programmer 10 gets a dolphin, programmer 20 gets a pie.

Here is what the programmers compute during the farewell dinner:

Programmer 10 got 1 dolphin and 1 pie. The absolute difference is |1-1| = 0.
Programmer 20 got 1 dolphin and 2 pies. The absolute difference is |1-2| = 1.
Programmer 30 got just 1 dolphin. The absolute difference is |1-0| = 1.
Each of the other 47 programmers did not receive anything, so they compute |0-0| = 0.

At the end of the dinner, they sum all those results and obtain the sum 2. This is the smallest possible sum for the given input, hence the return value is correct.

1)
{0, 0}
{1, 1}

Returns: {2, 1 }



2)
{0, 1, 2, 3, 5, 6, 7, 8}
{8, 7, 6, 5, 3, 2, 1, 0}

Returns: {2, 2, 2, 2, 2, 2, 2, 2 }



3)
{49, 0, 48, 1}
{3, 4, 5, 6}

Returns: {2, 2, 2, 2 }



4)
{21,4,14,0,31,46,1,34,2,3,27,19,47,46,17,11,41,12,31,0,34,18,8,14,23,40,0,18,48,35,42,24,25,32,25,44,17,6,44,34,12,39,43,39,26,
34,10,6,13,2,40,15,16,32,32,29,1,23,8,10,49,22,10,15,40,20,0,30,1,43,33,42,28,39,28,4,38,11,5,1,47,12,0,22,20,33,33,34,18,8,23,6}
{25,5,39,20,44,47,11,49,42,17,25,15,23,11,32,17,24,4,11,47,27,41,40,0,49,27,5,28,6,11,18,0,17,1,0,32,45,28,17,5,13,40,40,25,33,
7,8,32,12,0,39,30,8,39,23,9,8,34,34,37,5,1,24,23,0,29,11,42,29,40,24,18,37,1,21,0,31,47,23,33,45,48,31,11,40,45,24,22,19,26,37,39}

Returns: {2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 1, 2, 2, 1, 2, 1, 2, 1, 1, 2, 2, 1, 1, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1 }



******************************/
// END CUT HERE
#line 113 "PieOrDolphin.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class PieOrDolphin {
	public:
	vector <int> Distribute(vector <int> c1, vector <int> c2) {
		int N=c1.size();
		map<int, int>hi;
		REP(i, N) {
			hi[c1[i]]++;
			hi[c2[i]]++;
		}
		vector<int>ans(N, 1);
		FOR(e, hi) {
		}
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const vector <int>& Expected, const vector <int>& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, PieOrDolphin().Distribute(choice1, choice2));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//CASE(4)
//	int choice1_[] = {21,4,14,0,31,46,1,34,2,3,27,19,47,46,17,11,41,12,31,0,34,18,8,14,23,40,0,18,48,35,42,24,25,32,25,44,17,6,44,34,12,39,43,39,26,
//34,10,6,13,2,40,15,16,32,32,29,1,23,8,10,49,22,10,15,40,20,0,30,1,43,33,42,28,39,28,4,38,11,5,1,47,12,0,22,20,33,33,34,18,8,23,6};
//	  vector <int> choice1(choice1_, choice1_+sizeof(choice1_)/sizeof(*choice1_)); 
//	int choice2_[] = {25,5,39,20,44,47,11,49,42,17,25,15,23,11,32,17,24,4,11,47,27,41,40,0,49,27,5,28,6,11,18,0,17,1,0,32,45,28,17,5,13,40,40,25,33,
//7,8,32,12,0,39,30,8,39,23,9,8,34,34,37,5,1,24,23,0,29,11,42,29,40,24,18,37,1,21,0,31,47,23,33,45,48,31,11,40,45,24,22,19,26,37,39};
//	  vector <int> choice2(choice2_, choice2_+sizeof(choice2_)/sizeof(*choice2_)); 
//	int __[] = {2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 1, 2, 2, 1, 2, 1, 2, 1, 1, 2, 2, 1, 1, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1 };
//	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
//END
//return 0;

CASE(0)
	int choice1_[] = {10, 20, 10};
	  vector <int> choice1(choice1_, choice1_+sizeof(choice1_)/sizeof(*choice1_)); 
	int choice2_[] = {20, 30, 20};
	  vector <int> choice2(choice2_, choice2_+sizeof(choice2_)/sizeof(*choice2_)); 
	int __[] = {2, 2, 1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	int choice1_[] = {0, 0};
	  vector <int> choice1(choice1_, choice1_+sizeof(choice1_)/sizeof(*choice1_)); 
	int choice2_[] = {1, 1};
	  vector <int> choice2(choice2_, choice2_+sizeof(choice2_)/sizeof(*choice2_)); 
	int __[] = {2, 1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	int choice1_[] = {0, 1, 2, 3, 5, 6, 7, 8};
	  vector <int> choice1(choice1_, choice1_+sizeof(choice1_)/sizeof(*choice1_)); 
	int choice2_[] = {8, 7, 6, 5, 3, 2, 1, 0};
	  vector <int> choice2(choice2_, choice2_+sizeof(choice2_)/sizeof(*choice2_)); 
	int __[] = {2, 2, 2, 2, 2, 2, 2, 2 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	int choice1_[] = {49, 0, 48, 1};
	  vector <int> choice1(choice1_, choice1_+sizeof(choice1_)/sizeof(*choice1_)); 
	int choice2_[] = {3, 4, 5, 6};
	  vector <int> choice2(choice2_, choice2_+sizeof(choice2_)/sizeof(*choice2_)); 
	int __[] = {2, 2, 2, 2 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(4)
	int choice1_[] = {21,4,14,0,31,46,1,34,2,3,27,19,47,46,17,11,41,12,31,0,34,18,8,14,23,40,0,18,48,35,42,24,25,32,25,44,17,6,44,34,12,39,43,39,26,
34,10,6,13,2,40,15,16,32,32,29,1,23,8,10,49,22,10,15,40,20,0,30,1,43,33,42,28,39,28,4,38,11,5,1,47,12,0,22,20,33,33,34,18,8,23,6};
	  vector <int> choice1(choice1_, choice1_+sizeof(choice1_)/sizeof(*choice1_)); 
	int choice2_[] = {25,5,39,20,44,47,11,49,42,17,25,15,23,11,32,17,24,4,11,47,27,41,40,0,49,27,5,28,6,11,18,0,17,1,0,32,45,28,17,5,13,40,40,25,33,
7,8,32,12,0,39,30,8,39,23,9,8,34,34,37,5,1,24,23,0,29,11,42,29,40,24,18,37,1,21,0,31,47,23,33,45,48,31,11,40,45,24,22,19,26,37,39};
	  vector <int> choice2(choice2_, choice2_+sizeof(choice2_)/sizeof(*choice2_)); 
	int __[] = {2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 1, 1, 2, 2, 1, 2, 1, 2, 1, 1, 2, 2, 1, 1, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 1, 1, 1, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
#if 0  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: int
	vector <int> choice1; 
	{
		int N=UNIFORM_LL(1, 51);
		choice1 = vector <int>(N); 
		REP(i, N) {
			choice1[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> choice2; 
	{
		int N=UNIFORM_LL(1, 51);
		choice2 = vector <int>(N); 
		REP(i, N) {
			choice2[i] = UNIFORM_LL(0, 1000);
		}
	}
	vector <int> _0 = PieOrDolphin().Distribute(choice1, choice2);
	vector <int> _1 = PieOrDolphinRef().Distribute(choice1, choice2);
	if(!verify_case(_0, _1, true)) {
print(choice1);
print(choice2);
	}
}
#endif

}
// END CUT HERE
