// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
This problem is related to the classic "Tower of Hanoi" puzzle.
The puzzle consists of three rods and n disks.
The rods are labeled A, B, and C.
The disks all have different sizes, and they are numbered 0 through n-1 from smallest to largest.



In a valid configuration, each disk is placed onto one of the three rods and on each rod the disks are ordered by size: smallest to largest from top to bottom.
In order to specify a configuration we just need to specify the rod for each disk, as the order of disks on each rod is uniquely determined by their sizes.



A valid move is a move in which we take the topmost disk from one of the rods and place it onto the top of the disks on another rod in a way that produces a valid configuration.
That is, given a valid configuration, a move is only valid if a) you are moving the topmost disk from one rod onto another rod that is currently empty, or b) the disk you are moving is smaller than the current topmost disk on the destination rod.



A solution is a sequence of valid moves that produces a configuration in which all n disks are in a single stack on an arbitrary rod.



You are given a vector <int> count with three elements and an int k.
Construct any valid configuration with the following properties:

There are exactly count[0] disks on rod A.
There are exactly count[1] disks on rod B.
There are exactly count[2] disks on rod C.
The shortest solution for this configuration consists of exactly k moves.




If there is no such configuration, return an empty string.
Otherwise, return a string with n = sum(count) characters.
For each valid i, character i of the return value should be the name of the rod where disk i is placed.
If there are multiple possible solutions, you may return any of them.


DEFINITION
Class:ClassicTowers
Method:findTowers
Parameters:long long, vector <int>
Returns:string
Method signature:string findTowers(long long k, vector <int> count)


CONSTRAINTS
-k will be between 0 and 2^50 - 1, inclusive.
-count will have exactly 3 elements.
-Each element of count will be between 0 and 50.
-The sum of elements in count will be between 1 and 50, inclusive.
-Elements in count will be in a non-decreasing order.


EXAMPLES

0)
4
{1,1,2}


Returns: "CCAB"

The returned value represents disk 0 and 1 on rod C, disk 2 on rod A, and disk 3 on rod B.

Here, we can put all disks onto rod B as follows:

 Move disk 2 onto rod B. 
 Move disk 0 onto rod A. 
 Move disk 1 onto rod B. 
 Move disk 0 onto rod B. 


1)
0
{0, 0, 50}


Returns: "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC"

The return value represents all disks on rod C.

2)
0
{10,20,20}

Returns: ""

This is impossible. A configuration with some disks on each rod clearly doesn't have any solution with 0 moves.


3)
123456123456123
{10,10,30}


Returns: "CCACCCACCABACCABBACCCBBCCBCCCBACCCCABBACCCCCACBCCC"



4)
314159265358979
{15,16,17}

Returns: ""



*/
// END CUT HERE
#line 116 "ClassicTowers.cpp"

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
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
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
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


/*

そもそも与えられた状態からの手数は?

f(X) ... X 以下のdiskが正しくならんでいる
f(1) = 0
f(N) =

N, N-1 が連続してたら f(N-1)

N, N-1 がちがうとこにあるとする。
(1) +f(N-2) + h(N-2)
	N, N-2, ??, ??
	N-1, ??, ??, ??
	??, ??, ??

(2) +f(N-2) + h(N-2)
	N, ??, ??, ??
	N-1, N-2, ??, ??, ??
	??, ??, ??

(3) +f(N-2)
	N, ??, ??, ??
	N-1, ??, ??, ??
	N-2, ??, ??

->
	N
	N-1
	N-2, ..., 1

次これ +1
	N, N-1
	empty
	N-2, N-3, ..., 1

あとは N-2 の山を移動。+h(N-2)回

h(N) = 2^N-1

*/

ll h(ll N) {
	return (1LL<<N) -1;
}

// N in [0, s.size())
ll f(ll N, const string& s) {
	if(N==0) return 0;
	if(s[N]==s[N-1]) return f(N-1, s);
	if(N==1) return h(N-1);

	ll ans = f(N-2, s);
	if(s[N]!=s[N-2]) ans += h(N-2);
	ans += 1 + h(N-2);
	return ans;
}

class ClassicTowers {
	public:
	string findTowers(long long k, vector <int> count) {
		return "";
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const string& Expected, const string& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, ClassicTowers().findTowers(k, count));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

DD(f(2, "AAA"));
DD(f(2, "AAB"));
return 0;

CASE(0)
	long long k = 4LL; 
	int count_[] = {1,1,2}
;
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	string _ = "CCAB"; 
END
CASE(1)
	long long k = 0LL; 
	int count_[] = {0, 0, 50}
;
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	string _ = "CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC"; 
END
CASE(2)
	long long k = 0LL; 
	int count_[] = {10,20,20};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	string _ = ""; 
END
CASE(3)
	long long k = 123456123456123LL; 
	int count_[] = {10,10,30}
;
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	string _ = "CCACCCACCABACCABBACCCBBCCBCCCBACCCCABBACCCCCACBCCC"; 
END
CASE(4)
	long long k = 314159265358979LL; 
	int count_[] = {15,16,17};
	  vector <int> count(count_, count_+sizeof(count_)/sizeof(*count_)); 
	string _ = ""; 
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
// param type: long
	long long k = UNIFORM_LL(0, 100); 
// param type: int
	vector <int> count; 
	{
		int N=UNIFORM_LL(1, 51);
		count = vector <int>(N); 
		REP(i, N) {
			count[i] = UNIFORM_LL(0, 1000);
		}
	}
	string _0 = ClassicTowers().findTowers(k, count);
	string _1 = ClassicTowersRef().findTowers(k, count);
	if(!verify_case(_0, _1, true)) {
print(k);
print(count);
	}
}
#endif

}
// END CUT HERE
