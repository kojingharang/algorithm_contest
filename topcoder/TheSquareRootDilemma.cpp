// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Consider the function SSR (Squared Sum of square Roots) defined on two positive integer parameters: SSR(A, B) = (sqrt(A)+sqrt(B))^2. We are interested in the cases when the value of the function is also an integer.

Given ints N and M, return the number of ordered pairs (A, B) such that 1 <= A <= N, 1 <= B <= M and SSR(A, B) is an integer.

DEFINITION
Class:TheSquareRootDilemma
Method:countPairs
Parameters:int, int
Returns:int
Method signature:int countPairs(int N, int M)


NOTES
-The answer to the problem is guaranteed to fit into signed 32-bit integer type under the given constraints.


CONSTRAINTS
-N will be between 1 and 77,777, inclusive.
-M will be between 1 and 77,777, inclusive.


EXAMPLES

0)
2
2

Returns: 2

Out of the four possible pairs (A, B), only two yield an integer result: SSR(1, 1) = 4 and SSR(2, 2) = 8.
On the other hand, SSR(1, 2) = SSR(2, 1) = 3+2*sqrt(2), which is not an integer.

1)
10
1

Returns: 3

SSR(1, 1), SSR(4, 1) and SSR(9, 1) are integers.

2)
3
8

Returns: 5

The valid pairs are (1, 1), (1, 4), (2, 2), (2, 8) and (3, 3).

3)
100
100

Returns: 310



*/
// END CUT HERE
#line 63 "TheSquareRootDilemma.cpp"

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

VI make_primes(int N) { // return all prime numbers less than N  memory: O(N) time: O(N^2)?
	VI p(N, 1), out;
	for(int i=2;i<N;i++) if(p[i]) { out.push_back(i); for(int j=i*2;j<N;j+=i) p[j]=0; }
	return out;
}

VI primes;
pair<ll, ll> f(int n) {
	ll out = 0LL;
	REP(ii, primes.size()) {
		int i=primes.size()-1-ii;
		int odd = 0;
		while(n % primes[i] == 0) {
			n/=primes[i];
			odd = 1 - odd;
		}
		out = (out << 1) | odd;
	}
	return MP(n, out);
}

class TheSquareRootDilemma {
	public:
	int countPairs(int N, int M) {
		primes = make_primes(290);
		
		map<pair<ll, ll>, ll> ms;
		RANGE(i, 1, M+1) {
			ms[f(i)]++;
		}
		ll ans = 0;
		RANGE(i, 1, N+1) {
			ans += ms[f(i)];
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
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, TheSquareRootDilemma().countPairs(N, M));}
int main(){

CASE(0)
	int N = 24; 
	int M = 16236; 
	int _ = 1506; 
END
//return 0;
CASE(0)
	int N = 2; 
	int M = 2; 
	int _ = 2; 
END
//return 0;
CASE(1)
	int N = 10; 
	int M = 1; 
	int _ = 3; 
END
CASE(2)
	int N = 3; 
	int M = 8; 
	int _ = 5; 
END
CASE(3)
	int N = 100; 
	int M = 100; 
	int _ = 310; 
END
CASE(0)
	int N = 1; 
	int M = 1; 
	int _ = 1; 
END
CASE(0)
	int N = 77777; 
	int M = 77777; 
	int _ = 2; 
END

}
// END CUT HERE
