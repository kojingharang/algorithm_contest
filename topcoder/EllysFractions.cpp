// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A positive common fraction is a fraction of the form A/B, where A and B are positive integers.
An irreducible fraction is a positive common fraction such that A and B are relatively prime. (In other words, the only positive integer that divides both A and B is 1.)
Elly recently invented the factor fractions: A factor fraction is an irreducible fraction such that the product A*B is a factorial number (see Notes for definition). We will only be interested in factor fractions that lie strictly between 0 and 1. (That is, A must be strictly smaller than B.)

Examples:

2/3, 4/6, 4/7, 7/7, 6/1, 42/49 are six positive common fractions
Out of those six, the following three are irreducible: 2/3, 4/7, 6/1.
The fraction 2/3 is a factor fraction, because 2*3 = 6 and that is a factorial number.
The fraction 4/7 is not a factor fraction, because 4*7 = 28 and that is not a factorial number.
The fraction 6/1 is a factor fraction, because 6*1 = 6 and that is a factorial number. However, as 6/1 does not lie strictly between 0 and 1, we are not interested in this fraction.
Note that 4/6 is not a factor fraction. (We do have 4*6=24, but a factor fraction has to be irreducible.)



You are given an int N.
Compute and return the number of factor fractions A/B such that 0 < A/B < 1 and A*B is one of the factorial numbers from 1! to N! (inclusive).

DEFINITION
Class:EllysFractions
Method:getCount
Parameters:int
Returns:long long
Method signature:long long getCount(int N)


NOTES
-The factorial of X, denoted X!, is the product of the first X positive integers. For example, 6! is 1*2*3*4*5*6 = 720. The factorial numbers are the numbers of the form X! for positive integer X. The smallest few: 1, 2, 6, 24, 120, 720, ...
-The answer will always fit in a 64-bit signed integer.


CONSTRAINTS
-N will be between 1 and 250, inclusive.


EXAMPLES

0)
1

Returns: 0

We are interested in factor fractions such that A*B = 1. The only positive common fraction with this property is the fraction 1/1. However, this fraction is not strictly between 0 and 1.

1)
2

Returns: 1

Here the only valid factor fraction is 1/2.

2)
3

Returns: 3

The three fractions are 1/2, 1/6, and 2/3. (We have 1*2 = 2! and 1*6 = 2*3 = 3!.)

3)
5

Returns: 9



4)
100

Returns: 177431885

Plenty of fractions here.

*/
// END CUT HERE
#line 79 "EllysFractions.cpp"

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

pair<VI, VI> factorize_p(int n, VI& primes) { // 60(==2**2 * 3**1 * 5**1), table -> ([2,3,5], [2,1,1])
	VI pf, count;
	REP(i, primes.size()) {
		int co=0;
		while(n%primes[i]==0) { n/=primes[i]; co++; }
		if(co) { pf.push_back(primes[i]); count.push_back(co); }
	}
	return MP(pf, count);
}

VI make_primes(int N) { // return all prime numbers less than N
	VI p(N, 1), out;
	for(int i=2;i<N;i++) if(p[i]) { out.push_back(i); for(int j=i*2;j<N;j+=i) p[j]=0; }
	return out;
}


class EllysFractions {
	public:
	long long getCount(int N) {
		VI primes = make_primes(N+1);
		map<int, int> w;
		ll ans=0;
		for(int i=1;i<=N;i++) {
			pair<VI, VI> a = factorize_p(i, primes);
			REP(j, a.first.size()) {
				w[a.first[j]]+=a.second[j];
			}
			if(w.size()>0) {
				ans += 1LL<<((int)w.size()-1);
			}
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// { os << "{ ";
//   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
//   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const long long& Expected, const long long& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, EllysFractions().getCount(N));}
int main(){

//CASE(0)
//	int N = 250; 
//	long long _ = 0LL; 
//END
//return 0;
CASE(0)
	int N = 1; 
	long long _ = 0LL; 
END
CASE(1)
	int N = 2; 
	long long _ = 1LL; 
END
CASE(2)
	int N = 3; 
	long long _ = 3LL; 
END
CASE(3)
	int N = 5; 
	long long _ = 9LL; 
END
CASE(4)
	int N = 100; 
	long long _ = 177431885LL; 
END

}
// END CUT HERE
