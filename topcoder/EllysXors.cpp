// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// XOR problems became very popular in TopCoder recently. (If you do not know the bitwise operation XOR, see the Notes section for an explanation.) That's why Elly decided to invent one of her own. Fortunately for you, the one she came up with is quite simple. You are given two long longs L and R. She wants you to find the XOR of all numbers between L and R, inclusive.

DEFINITION
Class:EllysXors
Method:getXor
Parameters:long long, long long
Returns:long long
Method signature:long long getXor(long long L, long long R)


NOTES
-XOR (exclusive or) is a binary operation, performed on two numbers in binary notation. First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each bit where the numbers differ the result has 1 in its binary representation. It has 0 in all other positions.
-For example 42 XOR 7 is performed as follows. First, the numbers are converted to binary: 42 is 101010 and 7 is 111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 7 becomes 000111. Then 101010 XOR 000111 = 101101 (the result has ones only in the positions where the two numbers differ). Then the result can be converted back to decimal notation. In this case 101101 = 45, so 42 XOR 7 = 45.
-One of the ways to calculate the XOR of more than two numbers A1, A2, ..., An is "A1 XOR (A2 XOR (... XOR An))..))". Since the function is commutative and associative, you can also express it as "A1 XOR A2 XOR ... XOR An" and group the operands in any way you like.
-It can be proved that the answer is always less than 2*R for the given constraints.


CONSTRAINTS
-L and R will be between 1 and 4,000,000,000, inclusive.
-L will be less than or equal to R.


EXAMPLES

0)
3
10

Returns: 8


((((((3 XOR 4) XOR 5) XOR 6) XOR 7) XOR 8) XOR 9) XOR 10 =
        (((((7 XOR 5) XOR 6) XOR 7) XOR 8) XOR 9) XOR 10 = 
                ((((2 XOR 6) XOR 7) XOR 8) XOR 9) XOR 10 = 
                        (((4 XOR 7) XOR 8) XOR 9) XOR 10 = 
                                ((3 XOR 8) XOR 9) XOR 10 =
                                       (11 XOR 9) XOR 10 =
                                                2 XOR 10 = 8.


1)
5
5

Returns: 5

The XOR of a single number is the number itself.

2)
13
42

Returns: 39

A bit larger example.

3)
666
1337

Returns: 0

The answer can be zero.

4)
1234567
89101112

Returns: 89998783



*/
// END CUT HERE
#line 79 "EllysXors.cpp"

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
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


ll ff(ll v) {
	ll ans=0;
	for(ll i=1;i<=v;i++) ans^=i;
	return ans;
}

ll fff(ll A, ll B) {
	unsigned ans=0;
	unsigned AA = A;
	unsigned BB = B;
	for(unsigned i=AA;i<=BB;i++) ans^=i;
	return ans;
}

ll f(ll v) {
	if(v<10) return ff(v);
	ll a=1;
	while(v>a) a=a<<1;
	a>>=1;
	return (((v-a)&1) ? 0 : a) ^ f(v^a);
}

class EllysXors {
	public:
	long long getXor(long long L, long long R) {
		//REP(i, 100) if(f(i+1)!=ff(i+1)) cout<<"ERRO"<<endl;
		//return f(R)^f(L-1);
		return fff(L, R);
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
void verify_case(const long long& Expected, const long long& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, EllysXors().getXor(L, R));}
int main(){

CASE(0)
	long long L = 1LL; 
	long long R = 2LL; 
	long long _ = 3LL; 
END
CASE(0)
	long long L = 3LL; 
	long long R = 10LL; 
	long long _ = 8LL; 
END
//return 0;
CASE(1)
	long long L = 5LL; 
	long long R = 5LL; 
	long long _ = 5LL; 
END
CASE(2)
	long long L = 13LL; 
	long long R = 42LL; 
	long long _ = 39LL; 
END
CASE(3)
	long long L = 666LL; 
	long long R = 1337LL; 
	long long _ = 0LL; 
END
CASE(4)
	long long L = 1234567LL; 
	long long R = 89101112LL; 
	long long _ = 89998783LL; 
END
CASE(4)
	long long L = 5LL; 
	long long R = 8LL; 
	long long _ = 89998783LL; 
END
CASE(4)
	long long L = 1LL; 
	long long R = 4LL; 
	long long _ = 89998783LL; 
END
CASE(4)
	long long L = 1LL; 
	long long R = 9LL; 
	long long _ = 89998783LL; 
END
CASE(4)
	long long L = 2LL; 
	long long R = 4000000000LL; 
	long long _ = 89998783LL; 
END

}
// END CUT HERE
