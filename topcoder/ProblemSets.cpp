// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Cat Snuke came up with some problems. He wants to construct as many problem sets as possible using those problems.

Each problem set must contain exactly three problems: one for the Easy slot, one for the Medium slot, and one for the Hard slot. Each problem can only be assigned to a single slot in a single problem set. He came up with E + EM + M + MH + H problems in total. The distribution of the problems is as follows:


E problems can only be used in the Easy slot.
EM problems can be used either in the Easy slot or the Medium slot.
M problems can only be used in the Medium slot.
MH problems can be used either in the Medium slot or the Hard slot.
H problems can only be used in the Hard slot.


Return the maximal number of problem sets he can construct.

DEFINITION
Class:ProblemSets
Method:maxSets
Parameters:long long, long long, long long, long long, long long
Returns:long long
Method signature:long long maxSets(long long E, long long EM, long long M, long long MH, long long H)


CONSTRAINTS
-E, EM, M, MH, H will be between 0 and 1,000,000,000,000,000,000 (10^18), inclusive.


EXAMPLES

0)
2
2
1
2
2

Returns: 3

One of EM problems should be used for the Easy slot, and the other should be used for the Medium slot.
One of MH problems should be used for the Medium slot, and the other should be used for the Hard slot.

1)
100
100
100
0
0

Returns: 0

Unfortunately, no problem can be used for the Hard slot.

2)
657
657
657
657
657

Returns: 1095



3)
1
2
3
4
5

Returns: 3



4)
1000000000000000000
1000000000000000000
1000000000000000000
1000000000000000000
1000000000000000000

Returns: 1666666666666666666



******************************/
// END CUT HERE
#line 91 "ProblemSets.cpp"
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
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class ProblemSets {
	public:
	long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {
		ll tmp = (E+EM+M+MH+H)/3;
		if(E>=tmp)M+=EM,EM=0;
		if(H>=tmp)M+=MH,MH=0;
		if(M>=tmp) E+=EM,H+=MH,EM=0,MH=0;
		if(E+EM>=tmp&&M+EM+MH>=tmp && H+MH>=tmp) return tmp;
		{
			ll mid=(E+M+EM)/2;
			E=min(mid,E);
			M=min(mid,M);
			EM=0;
		}
		{
			ll mid=(M+H+MH)/2;
			M=min(mid,M);
			H=min(mid,H);
			MH=0;
		}
		cout<<"ANS "<<min(E,min(M,H))<<endl;
		return min(E,min(M,H));
	}
};

class ProblemSetsRef {
	public:
	long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {
		ll lo=0, hi=1LL<<62;
		while(lo+1<hi) {
			ll mid = (lo+hi)/2;
			bool ok=true;
			ll em = EM, mh = MH;
			if(E+em<mid) ok=false;
			em-=max(0LL, mid-E);
			if(M+em+mh<mid) ok=false;
			mh-=max(0LL, mid-(M+em));
			if(H+mh<mid) ok=false;
			if(ok) lo=mid; else hi=mid;
		}
		return lo;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const long long& Expected, const long long& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, ProblemSets().maxSets(E, EM, M, MH, H));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	long long E = 2LL; 
	long long EM = 2LL; 
	long long M = 1LL; 
	long long MH = 2LL; 
	long long H = 2LL; 
	long long _ = 3LL; 
END
CASE(1)
	long long E = 100LL; 
	long long EM = 100LL; 
	long long M = 100LL; 
	long long MH = 0LL; 
	long long H = 0LL; 
	long long _ = 0LL; 
END
CASE(2)
	long long E = 657LL; 
	long long EM = 657LL; 
	long long M = 657LL; 
	long long MH = 657LL; 
	long long H = 657LL; 
	long long _ = 1095LL; 
END
CASE(3)
	long long E = 1LL; 
	long long EM = 2LL; 
	long long M = 3LL; 
	long long MH = 4LL; 
	long long H = 5LL; 
	long long _ = 3LL; 
END
CASE(4)
	long long E = 1000000000000000000LL; 
	long long EM = 1000000000000000000LL; 
	long long M = 1000000000000000000LL; 
	long long MH = 1000000000000000000LL; 
	long long H = 1000000000000000000LL; 
	long long _ = 1666666666666666666LL; 
END
#if 01  // DO RANDOM TESTS

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
	long long E = UNIFORM_LL(0, 100); 
// param type: long
	long long EM = UNIFORM_LL(0, 100); 
// param type: long
	long long M = UNIFORM_LL(0, 100); 
// param type: long
	long long MH = UNIFORM_LL(0, 100); 
// param type: long
	long long H = UNIFORM_LL(0, 100); 
	long long _0 = ProblemSets().maxSets(E, EM, M, MH, H);
	long long _1 = ProblemSetsRef().maxSets(E, EM, M, MH, H);
	if(!verify_case(_0, _1, true)) {
print(E);
print(EM);
print(M);
print(MH);
print(H);
	}
}
#endif

}
// END CUT HERE
