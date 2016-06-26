// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
You are given the vector <int> x: a list containing n integers.
Each element of x is a positive integer of the form 2^a * 3^b, where a and b are some nonnegative integers.
The elements of x are not necessarily distinct.



You are going to perform n-1 operations.
Each operation will consist of the following steps:

Choose two distinct indices into your list. Let X and Y be the numbers at those indices. Remove both of them from the list. (Note that X and Y are allowed to have the same value.)
Compute one of two possible values: either the greatest common divisor (gcd) of X and Y, or the least common multiple (lcm) of X and Y.
Append the computed value to your list.

Obviously, after n-1 operations you will be left with a single integer.



In addition to x you are given the int t.
You would like to know whether it is possible to perform the sequence of operations on x in such a way that the final integer will be t.
If it is possible, return "Possible", otherwise return "Impossible".


DEFINITION
Class:LCMGCD
Method:isPossible
Parameters:vector <int>, int
Returns:string
Method signature:string isPossible(vector <int> x, int t)


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-Each element of x will be between 1 and 10^9, inclusive.
-t will be between 1 and 10^9, inclusive.
-t and each element of x will be of the form 2^i*3^j for some nonnegative i,j.


EXAMPLES

0)
{2,3}
6

Returns: "Possible"

We can take the lcm to reach the goal.

1)
{4,9}
6

Returns: "Impossible"

We have lcm(4,9) = 36 and gcd(4,9) = 1. It's impossible to get 6.

2)
{6,12,24,18,36,72,54,108,216}
36

Returns: "Possible"



3)
{6,27,81,729}
6

Returns: "Impossible"



4)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
1

Returns: "Possible"



5)
{72,16,16,16,16,16,27,27,27,27,27,27,27,27,27}
72

Returns: "Possible"



6)
{100663296, 544195584, 229582512, 59049}
60466176

Returns: "Possible"

Watch out for integer overflow.
The intermediate results won't always fit into a 32-bit integer variable.

7)
{2,4,8,16,32,64}
256

Returns: "Impossible"



******************************/
// END CUT HERE
#line 113 "LCMGCD.cpp"
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
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<(v)<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

map<int, int> factorize(int n, const VI& primes) { // 60(==2**2 * 3**1 * 5**1), table -> ([2,3,5], [2,1,1])   time:
	map<int, int> out;
	REP(i, primes.size()) {
		int co=0;
		while(n%primes[i]==0) { n/=primes[i]; co++; }
		if(co) { out[primes[i]] = co; }
	}
	if(n>1) { out[n] = 1;}
	return out;
}

bool contains(map<int, int>& a, map<int, int>& b) {
	map<int, int> w(a);
	for(auto kv:b) {
		w[kv.first] -= kv.second;
	}
	for(auto kv:w) {
		if(kv.second<0) return false;
	}
	return true;
}

bool EQ(map<int, int>& a, map<int, int>& b) {
	DD(a);DD(b);
	vector<int> keys;
	for(auto kv:a) keys.PB(kv.first);
	for(auto kv:b) keys.PB(kv.first);
	for(auto k:keys) {
		DD(k);DD(a[k]);DD(b[k]);
		if(a[k] != b[k]) return false;
	}
	return true;
}

void OR(map<int, int>& a, map<int, int>& b) {
	for(auto kv:b) {
		a[kv.first] = max(a[kv.first], kv.second);
	}
}

void AND(map<int, int>& a, map<int, int>& b) {
	vector<int> keys;
	for(auto kv:a) keys.PB(kv.first);
	for(auto kv:b) keys.PB(kv.first);
	for(auto k:keys) {
		a[k] = min(a[k], b[k]);
	}
}

class LCMGCD {
	public:
	string isPossible2(vector <int> x, int t) {
		VI pr = {2,3};
//		DD(pr.size());
		auto ref = factorize(t, pr);
//		DD(ref);
		vector<map<int, int>> m2, m3, ands, ors;
		REP(i, x.size()) {
			auto h = factorize(x[i], pr);
//			DD(h);
			if(ref[2]>=h[2] && ref[3]<h[3]) {
				m2.PB(h);
			} else if(ref[2]<h[2] && ref[3]>=h[3]) {
				m3.PB(h);
			} else if(ref[2]<h[2] && ref[3]<h[3]) {
				ands.PB(h);
			} else {
				ors.PB(h);
			}
		}
		DD(m2);DD(m3);DD(ands);DD(ors);
		map<int, int> w2, w3;
		for(auto v:m2) OR(w2, v);
		for(auto v:m3) OR(w3, v);
		AND(w2, w3);
		for(auto v:ands) AND(w2, v);
		for(auto v:ors) OR(w2, v);
		DD(w2);DD(ref);
		return EQ(w2, ref) ? "Possible":"Impossible";
	}
	string isPossible(vector <int> x, int t) {
		string ans = isPossible2(x, t);
		if(ans=="Possible") return ans;

		VI pr = {2,3};
//		DD(pr.size());
		auto ref = factorize(t, pr);
//		DD(ref);
		vector<map<int, int>> m2, m3, ands, ors;
		REP(i, x.size()) {
			auto h = factorize(x[i], pr);
//			DD(h);
			if(ref[2]>=h[2] && ref[3]<=h[3]) {
				m2.PB(h);
			} else if(ref[2]<=h[2] && ref[3]>=h[3]) {
				m3.PB(h);
			} else if(ref[2]<h[2] && ref[3]<h[3]) {
				ands.PB(h);
			} else {
				ors.PB(h);
			}
		}
		DD(m2);DD(m3);DD(ands);DD(ors);
		map<int, int> w2, w3;
		for(auto v:m2) OR(w2, v);
		for(auto v:m3) OR(w3, v);
		AND(w2, w3);
		for(auto v:ands) AND(w2, v);
		for(auto v:ors) OR(w2, v);
		DD(w2);DD(ref);
		return EQ(w2, ref) ? "Possible":"Impossible";
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
#define END	 verify_case(_, LCMGCD().isPossible(x, t));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){
CASE(3)
	int x_[] = {6,27,81,729};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int t = 6; 
	string _ = "Impossible"; 
END
return 0;

CASE(0)
	int x_[] = {2,3};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int t = 6; 
	string _ = "Possible"; 
END
CASE(1)
	int x_[] = {4,9};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int t = 6; 
	string _ = "Impossible"; 
END
CASE(2)
	int x_[] = {6,12,24,18,36,72,54,108,216};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int t = 36; 
	string _ = "Possible"; 
END
CASE(3)
	int x_[] = {6,27,81,729};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int t = 6; 
	string _ = "Impossible"; 
END
CASE(4)
	int x_[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int t = 1; 
	string _ = "Possible"; 
END
CASE(5)
	int x_[] = {72,16,16,16,16,16,27,27,27,27,27,27,27,27,27};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int t = 72; 
	string _ = "Possible"; 
END
CASE(6)
	int x_[] = {100663296, 544195584, 229582512, 59049};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int t = 60466176; 
	string _ = "Possible"; 
END
CASE(7)
	int x_[] = {2,4,8,16,32,64};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int t = 256; 
	string _ = "Impossible"; 
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
	vector <int> x; 
	{
		int N=UNIFORM_LL(1, 51);
		x = vector <int>(N); 
		REP(i, N) {
			x[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	int t = UNIFORM_LL(0, 100); 
	string _0 = LCMGCD().isPossible(x, t);
	string _1 = LCMGCDRef().isPossible(x, t);
	if(!verify_case(_0, _1, true)) {
print(x);
print(t);
	}
}
#endif

}
// END CUT HERE
