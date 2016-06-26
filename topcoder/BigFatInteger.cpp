// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// This problem statement contains superscipts that may not display properly outside the applet.

Lun the dog loves very large integers. Her favorite is AB (A to the power of B).


She has an integer variable X. Initially, the value of X is set to 1. She can perform the following two kinds of operations in any order, any number of times.

Operation 1: choose a prime number p, then multiply X by p.
Operation 2: choose a positive divisor d of the value of X at that point, then multiply X by d.



You are given two ints A and B. Return the minimum number of operations Lun needs to perform
in order to obtain X = AB from the initial state X = 1.

DEFINITION
Class:BigFatInteger
Method:minOperations
Parameters:int, int
Returns:int
Method signature:int minOperations(int A, int B)


CONSTRAINTS
-A will be between 2 and 1,000,000 (106), inclusive.
-B will be between 1 and 1,000,000 (106), inclusive.


EXAMPLES

0)
6
1

Returns: 2

Here, AB = 61 = 6. Here is one of the optimal sequences of operations:

Perform operation 1 by choosing p=2. X is now 1*2 = 2.
Perform operation 1 by choosing p=3. X is now 2*3 = 6.


1)
162
1

Returns: 4

One of the optimal sequences of operations:

Perform operation 1 by choosing p=3. X is now 1*3 = 3.
Perform operation 1 by choosing p=3. X is now 3*3 = 9.
Perform operation 2 by choosing d=9. X is now 9*9 = 81.
Perform operation 1 by choosing p=2. X is now 81*2 = 162.


2)
999983
9

Returns: 5

Here, A is prime. One of the optimal sequences of operations:

Perform operation 1 by choosing p=A. X is now A.
Perform operation 1 by choosing p=A. X is now A2.
Perform operation 1 by choosing p=A. X is now A3.
Perform operation 2 by choosing d=A3. X is now A6.
Perform operation 2 by choosing d=A3. X is now A9.


3)
360
8

Returns: 8



******************************/
// END CUT HERE
#line 86 "BigFatInteger.cpp"
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

VI make_primes(int N) {
	VI p(N, 1), out;
	for(int i=2;i<N;i++) if(p[i]) { out.push_back(i); for(int j=i*2;j<N;j+=i) p[j]=0; }
	return out;
}

class BigFatInteger {
	public:
	int minOperations(int A, int B) {
		VI p = make_primes(A+1);
		int ans=0;
		int Mx=0;
		REP(i, p.size()) {
			if(A==1) break;
			int v=0;
			while(A%p[i]==0) {
				A/=p[i];
				v++;
			}
			v*=B;
			if(v) {
				ans++;
				int vv=1, co=0;
				while(vv<v) {vv*=2;co++;}
				Mx=max(Mx, co);
			}
		}
		ans += Mx;
		return ans;
	}
};

class BigFatIntegerTry {
	public:
	int minOperations(int A, int B) {
		vector<int>pows;
		if(A%2==0){
			pows.PB(0);
			while(A%2==0){
				A/=2;
				pows.back()++;
			}
		}
		for(int i=3;i<=A;i+=2) {
			if(A%i==0){
				pows.PB(0);
				while(A%i==0){
					A/=i;
					pows.back()++;
				}
			}
		}
		sort(pows.begin(), pows.end());
		ll back=pows.back()*B;
		int answ=0;
		for(int z=63;z>=0;--z){
			if(((ll)1ull<<z)&back){
				answ=z+1;
				answ+=(back^(1l<<z))?1:0;
				break;
			}
		}
		answ+=pows.size()-1;
		return answ;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, BigFatInteger().minOperations(A, B));}
int main(){

CASE(0)
	int A = 7; 
	int B = 1; 
	int _ = 1; 
END
CASE(0)
	int A = 6; 
	int B = 1; 
	int _ = 2; 
END
CASE(1)
	int A = 162; 
	int B = 1; 
	int _ = 4; 
END
CASE(2)
	int A = 999983; 
	int B = 9; 
	int _ = 5; 
END
CASE(3)
	int A = 360; 
	int B = 8; 
	int _ = 8; 
END
#if 01  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: int
start_time=clock();
	int A = UNIFORM_LL(2, 10000); 
// param type: int
start_time=clock();
	int B = UNIFORM_LL(1, 10000); 
	int _0 = BigFatInteger().minOperations(A, B);
	int _1 = BigFatIntegerTry().minOperations(A, B);
	cout<<A<<" "<<B<<endl;
	verify_case(_0, _1);
}
#endif

}
// END CUT HERE
