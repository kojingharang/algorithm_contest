// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Jiro and Eel Saburo are good friends. One day Saburo found two interesting positive integers: A and B.

On the next day, Saburo met Jiro and wanted to tell him the two integers. However, he managed to forget their values. All Saburo could remember was their greatest common divisor G and their least common multiple L.

You are given two long longs: G and L. Find the original integers A and B, and return the value of A+B. If there are multiple pairs of A and B that correspond to G and L, pick the one that minimizes A+B. If it is impossible to find such A and B (i.e., Saburo made a mistake somewhere), return -1.

DEFINITION
Class:FoxAndGCDLCM
Method:get
Parameters:long long, long long
Returns:long long
Method signature:long long get(long long G, long long L)


NOTES
-The greatest common divisor of two integers a and b is the largest positive integer that divides both a and b without any remainder.
-The least common multiple of two integers a and b is the smallest positive integer that is a multiple of both a and b.


CONSTRAINTS
-G will be between 1 and 1,000,000,000,000 (10^12), inclusive.
-L will be between 1 and 1,000,000,000,000 (10^12), inclusive.


EXAMPLES

0)
2
20

Returns: 14

The possible pairs of A and B are {2, 20} and {4, 10}. We need to pick {4, 10} since 4+10 is the smallest sum of A and B.

1)
5
8

Returns: -1

There are no pairs of A and B such that their greatest common divisor is 5 and their least common multiple is 8.

2)
1000
100

Returns: -1



3)
100
1000

Returns: 700



4)
10
950863963000

Returns: 6298430



*/
// END CUT HERE
#line 73 "FoxAndGCDLCM.cpp"

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

int is_prime(ll n){
	ll i;
	if(n < 2) return 0;
	else if(n == 2) return 1;
	if(n % 2 == 0) return 0;
	for(i = 3; i * i <= n; i += 2) if(n % i == 0) return 0;
	return 1;
}
pair<VI, VI> factorize_p(int n, VI& primes) { // 60(==2**2 * 3**1 * 5**1), table -> ([2,3,5], [2,1,1])
	VI pf, count;
	REP(i, primes.size()) {
		int co=0;
		while(n%primes[i]==0) { n/=primes[i]; co++; }
		if(co) { pf.push_back(primes[i]); count.push_back(co); }
	}
	return MP(pf, count);
}

vector<ll> make_primes(ll N) { // return all prime numbers less than N
	vector<ll> p(N, 1), out;
	for(ll i=2;i<N;i++) if(p[i]) { out.push_back(i); for(ll j=i*2;j<N;j+=i) p[j]=0; }
	return out;
}
ll GCD( ll a, ll b ) {
	if(a<b) {
		ll tmp=a;
		a=b; b=tmp;
	}
	ll c;
	while ( a != 0 ) {
		c = a; a = b%a;  b = c;
	}
	return b;
}
ll LCM( ll a, ll b ) {
	return a/GCD(a, b)*b;
}

#define INF (1LL<<60)

class FoxAndGCDLCM {
	public:
	long long get(long long G, long long L) {
		if(L%G!=0) return -1;
		ll n = L/G;
		ll ans=INF;
		for(ll B=1;B*B<=n;B++) {
			if( n%B==0 ) {
				ll A=n/B;
				//cout<<A<<" "<<B<<endl;
				if(GCD(A, B)==1)
				{
					//cout<<A<<" "<<B<<endl;
					//if(ans==-1) ans=G*A+G*B;
					ans=min(ans, G*A+G*B);
				}
			}
		}
		return ans==INF?-1:ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const long long& Expected, const long long& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, FoxAndGCDLCM().get(G, L));}
int main(){

CASE(0)
	long long G = 2LL; 
	long long L = 20LL; 
	long long _ = 14LL; 
END
CASE(1)
	long long G = 5LL; 
	long long L = 8LL; 
	long long _ = -1LL; 
END
CASE(2)
	long long G = 1000LL; 
	long long L = 100LL; 
	long long _ = -1LL; 
END
CASE(3)
	long long G = 100LL; 
	long long L = 1000LL; 
	long long _ = 700LL; 
END
CASE(4)
	long long G = 10LL; 
	long long L = 950863963000LL; 
	long long _ = 6298430LL; 
END
CASE(4)
	long long G = 1000000000000LL; 
	long long L = 1000000000000LL; 
	long long _ = 2000000000000LL; 
END
CASE(4)
	long long G =  999999999997LL; 
	long long L = 1000000000000LL; 
	long long _ = -1LL; 
END

}
// END CUT HERE
/*

999999999997
1000000000000

*/

