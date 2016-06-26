// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Note that the memory limit for all tasks in this SRM is 256 MB.
This problem statement contains subscripts that may not display properly if viewed outside of the applet.

Manao is playing a solitaire game called OR-solitaire. In this game, the player starts with a number X = 0 and should obtain the number goal in one or more moves. The set of valid moves is determined by a vector <int> numbers. In each move, the player chooses some element of numbers and replaces X with the bitwise OR of X and the chosen element.

Fox Ciel wants Manao to stop playing OR-solitaire and move on with his life. She decided to erase some of the elements from numbers in such a way that it becomes impossible to complete the game. Return the minimum number of elements that need to be removed to achieve this.

DEFINITION
Class:ORSolitaire
Method:getMinimum
Parameters:vector <int>, int
Returns:int
Method signature:int getMinimum(vector <int> numbers, int goal)


NOTES
-If a and b are single bits then a | b is defined as max(a, b). For two integers, A and B, in order to calculate A | B, they need to be represented in binary: A = (an...a1)2, B = (bn...b1)2 (if the lengths of their representations are different, the shorter one is prepended with the necessary number of leading zeroes). Then A | B = C = (cn...c1)2, where ci = ai | bi. For example, 10 | 3 = (1010)2 | (0011)2 = (1011)2 = 11.


CONSTRAINTS
-numbers will contain between 1 and 50 elements, inclusive.
-Each element of numbers will be between 1 and 1,000,000,000.
-The elements in numbers will be distinct.
-goal will be between 1 and 1,000,000,000.


EXAMPLES

0)
{1, 2, 4}
7

Returns: 1

The goal of the game is to obtain X = 7 from X = 0. The possible moves are to replace X with bitwise OR of X and 1, bitwise OR of X and 2 and bitwise OR of X and 4. X = 7 can be obtained only by using each of the three moves at least once, so removing any single element from numbers will make the game impossible to finish.

1)
{1, 2, 4, 7, 8}
7

Returns: 2

In this example, Fox Ciel should remove the number 7 and one of the numbers 1, 2, 4.

2)
{12571295, 2174218, 2015120}
1

Returns: 0

There is no need to remove elements from numbers, since the game cannot be completed in its initial version.

3)
{5,2,4,52,62,9,8,3,1,11,6}
11

Returns: 3



4)
{503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346}
510

Returns: 5



******************************/
// END CUT HERE
#line 75 "ORSolitaire.cpp"
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

class ORSolitaire {
	public:
	int getMinimum(vector <int> Ns, int G) {
		int N=Ns.size();
		int ans = 1<<30, must=0;
		REP(i, 30) {
			if(!((G>>i)&1)) {
				REP(j, N) if((Ns[j]>>i)&1) must++, Ns[j]=0;
			}
		}
		int v=0;
		REP(i, N) v|=Ns[i];
		if(v!=G) return 0;
		
//		cout<<Ns<<endl;
		REP(i, 30) {
			if((G>>i)&1) {
				int rm=0, v=0;
				REP(j, N) if((Ns[j]>>i)&1) rm++; else v|=Ns[j];
				ans=min(ans, rm);
			}
		}
		return ans;
	}
};

bool need[50];
class ORSolitaireTry {
	public:
	int getMinimum(vector <int> num, int goal) {
		int inf=1000000000;
		int g=goal,best=inf;
		REP(i, num.size()) need[i]=true;
		int n=num.size();
		REP(i, n) REP(j, 32) {
			ll bt=1LL<<j;
			if(((1LL*num[i])&bt)>0&&((1LL*goal)&bt)==0) need[i]=false;
			REP(j, 32) {
				ll bt=1LL<<j;
				if((goal&bt)){
					int local=0;
					REP(i, n) {
						if(need[i]) if((1LL))
					}
				}
			}
		}
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, ORSolitaire().getMinimum(numbers, goal));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int numbers_[] = {7|101, 7};
	  vector <int> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int goal = 7; 
	int _ = 1; 
END
CASE(0)
	int numbers_[] = {7};
	  vector <int> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int goal = 7; 
	int _ = 1; 
END
CASE(0)
	int numbers_[] = {1, 1,1};
	  vector <int> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int goal = 7; 
	int _ = 0; 
END
CASE(0)
	int numbers_[] = {1, 2, 4};
	  vector <int> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int goal = 7; 
	int _ = 1; 
END
CASE(1)
	int numbers_[] = {1, 2, 4, 7, 8};
	  vector <int> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int goal = 7; 
	int _ = 2; 
END
CASE(2)
	int numbers_[] = {12571295, 2174218, 2015120};
	  vector <int> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int goal = 1; 
	int _ = 0; 
END
CASE(3)
	int numbers_[] = {5,2,4,52,62,9,8,3,1,11,6};
	  vector <int> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int goal = 11; 
	int _ = 3; 
END
CASE(4)
	int numbers_[] = {503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346};
	  vector <int> numbers(numbers_, numbers_+sizeof(numbers_)/sizeof(*numbers_)); 
	int goal = 510; 
	int _ = 5; 
END
#if 01  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<1000;loop++) {
// param type: int
start_time=clock();
	vector <int> numbers; 
	{
		int N=UNIFORM_LL(1, 50);
		numbers = vector <int>(N); 
		REP(i, N) {
			numbers[i] = UNIFORM_LL(1, 1000000000);
		}
	}
// param type: int
start_time=clock();
	int goal = UNIFORM_LL(1, 100); 
	int _0 = ORSolitaire().getMinimum(numbers, goal);
	int _1 = ORSolitaireTry().getMinimum(numbers, goal);
	if(!verify_case(_0, _1, true)) {
print(numbers);
print(goal);
	}
}
#endif

}
// END CUT HERE
