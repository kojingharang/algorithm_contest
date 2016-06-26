// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
The least common multiple (denoted "lcm") of a non-empty sequence of positive integers is the smallest positive integer that is divisible by each of them.
For example, lcm(2)=2, lcm(4,6)=12, and lcm(1,2,3,4,5)=60.



Alice had a positive integer N.
Then she chose some positive integer M that was strictly greater than N.
Afterwards, she computed two values:
the value A = lcm(N+1, N+2, ..., M) and the value B = lcm(1, 2, ..., M).
She was surprised when she saw that A = B.



You are given the int N.
Find and return the smallest M Alice could have chosen.
(Such an M will always exist.)


DEFINITION
Class:MissingLCM
Method:getMin
Parameters:int
Returns:int
Method signature:int getMin(int N)


CONSTRAINTS
-N will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
1

Returns: 2

Alice needs to choose an M > 1 such that lcm(2,...,M) = lcm(1,...,M). We can see M=2 is the minimum value that works, since lcm(1,2) = lcm(2) = 2.

1)
2

Returns: 4



2)
3

Returns: 6

We have lcm(4,5,6) = lcm(1,2,3,4,5,6) = 60.

3)
4

Returns: 8



4)
5

Returns: 10



5)
42

Returns: 82

Oh... that doesn't fit the pattern.

6)
999999

Returns: 1999966



******************************/
// END CUT HERE
#line 89 "MissingLCM.cpp"
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

// return all prime numbers in [0, N]  memory: O(N) time: O(NloglogN)
// make_primes(10^4).size() ==   1,229
// make_primes(10^5).size() ==   9,592
// make_primes(10^6).size() ==  78,498
// make_primes(10^7).size() == 664,579
VI make_primes(int N) {
	vector<bool> p(N, true);
	VI out;
	for(int i=2;i<=N;i++) if(p[i]) { out.PB(i); for(int j=i*2;j<N;j+=i) p[j]=false; }
	return out;
}
class MissingLCMRef {
	public:
	int getMin(int N) {
		VI P(make_primes(N));
		cout<<P.size()<<endl;
		map<int, int> C,A;
		RANGE(i, 1, N+1) {
			auto c = factorize(i, P);
//			cout<<"c "<<i<<" -> "<<c<<endl;
			for(auto& e: c) C[e.first]+=e.second;
		}
		cout<<"C "<<C<<endl;
		RANGE(i, N+1, 3*N) {
			auto c = factorize(i, P);
//			cout<<c<<endl;
			for(auto& e: c) A[e.first]+=e.second;
			int ok=1;
			for(auto& e: C) if(A[e.first] < e.second) ok=0;
			if(ok) {
				cout<<"OK "<<i<<endl;
				return i;
			}
		}
		return -1;
	}
};
class MissingLCM {
	public:
	int getMin(int N) {
		int upto = N*3;
		vector<bool> p(upto, true);
		ll ans = 2;
		RANGE(i, 2, N+1) {
			ll C=0, A=0;
			if(p[i]) {
				for(int j=i;j<upto;j+=i) {
					p[j]=false;
					int v = 0, J=j;
					while(J%i==0) {v++; J/=i;}
					if(j<=N) C=max<ll>(C, v);
					else A=max<ll>(A, v);
					if(i<j && A>=C) {
						ans=max<ll>(ans, j);
						break;
					}
				}
			}
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, MissingLCM().getMin(N));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int N = 1; 
	int _ = 2; 
END
CASE(1)
	int N = 2; 
	int _ = 4; 
END
CASE(2)
	int N = 3; 
	int _ = 6; 
END
CASE(3)
	int N = 4; 
	int _ = 8; 
END
CASE(4)
	int N = 5; 
	int _ = 10; 
END
CASE(5)
	int N = 42; 
	int _ = 82; 
END
//return 0;
CASE(6)
	int N = 999999; 
	int _ = 1999966; 
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
	int N = UNIFORM_LL(0, 100); 
	int _0 = MissingLCM().getMin(N);
	int _1 = MissingLCMRef().getMin(N);
	if(!verify_case(_0, _1, true)) {
print(N);
	}
}
#endif

}
// END CUT HERE
