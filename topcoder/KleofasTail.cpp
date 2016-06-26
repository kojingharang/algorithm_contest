// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Let X be a nonnegative integer.
The Kleofas tail of X is an infinite sequence of nonnegative integers, defined as follows:


The first element is X.
After an even element Y, the next element of the sequence is Y/2.
After an odd element Z, the next element of the sequence is Z-1.


For example, the Kleofas tail of 60 starts as follows: 60, 30, 15, 14, 7, 6, ...


You are given long longs K, A, and B.
Return the number of integers X between A and B, inclusive, such that the Kleofas tail of X contains at least one occurrence of K.


DEFINITION
Class:KleofasTail
Method:countGoodSequences
Parameters:long long, long long, long long
Returns:long long
Method signature:long long countGoodSequences(long long K, long long A, long long B)


NOTES
-Zero is an even number.


CONSTRAINTS
-K will be between 0 and 10^18, inclusive.
-A will be between 0 and 10^18, inclusive.
-B will be between 0 and 10^18, inclusive.
-A will be less than or equal to B.


EXAMPLES

0)
3
4
8

Returns: 2

The value 3 occurs in the Kleofas tail of 6 and also in the Kleofas tail of 7.

1)
1
23457
123456

Returns: 100000

For each X between 23457 and 123456, inclusive, the Kleofas tail of X contains the value 1.

2)
1234567890123456
10
1000000

Returns: 0

Each Kleofas tail is a nonincreasing sequence.

3)
0
0
2

Returns: 3



4)
2
3
3

Returns: 1

The Kleofas tail of 3 is 3, 2, 1, 0, 0, 0, ...

5)
13
12345
67890123

Returns: 8387584



*/
// END CUT HERE
#line 99 "KleofasTail.cpp"

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


ll f(ll K, ll A, ll B) {
	if(K==0) return B-A+1;
	VI w(B+1);
	if(K<=B) w[K]=1;
	REP(i, B+1) {
		if(w[i]) {
			if(i*2<=B) {
				if(w[i*2]) cout<<"ERR "<<i*2<<endl;
				w[i*2]=1;
			}
			if((i&1)==0 && i+1<=B) {
				if(w[i+1]) cout<<"ERR "<<i+1<<endl;
				w[i+1]=1;
			}
		}
	}
	REP(i, A) {
		w[i]=0;
	}
	cout<<w<<endl;
	return accumulate(ALL(w), 0);
}

ll ff(ll K, ll B) {
	ll _K=K;
	if(K==0) return B+1;
	if(B<K) return 0;
	ll ans=0;
	while(K<=B) {
		ans++;
		K<<=1;
	}
	K=_K;
	while(K<=B) {
		//cout<<K<<endl;
		if((K&1)==0) ans+=ff(K+1, B);
		K<<=1;
	}
	cout<<"ff "<<_K<<" "<<ans<<endl;
	return ans;
}

class KleofasTail {
	public:
	long long countGoodSequences(long long K, long long A, long long B) {
		//return f(K, A, B);
		return f(K, 0, B)-f(K, 0, A-1);
		//return ff(K, B) - ff(K, A-1);
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
#define END	 verify_case(_, KleofasTail().countGoodSequences(K, A, B));}
int main(){

CASE(0)
	long long K = 3LL; 
	long long A = 4LL; 
	long long B = 8LL; 
	long long _ = 2LL; 
END
CASE(1)
	long long K = 1LL; 
	long long A = 23457LL; 
	long long B = 123456LL; 
	long long _ = 100000LL; 
END
CASE(2)
	long long K = 1234567890123456LL; 
	long long A = 10LL; 
	long long B = 1000000LL; 
	long long _ = 0LL; 
END
CASE(3)
	long long K = 0LL; 
	long long A = 0LL; 
	long long B = 2LL; 
	long long _ = 3LL; 
END
CASE(4)
	long long K = 2LL; 
	long long A = 3LL; 
	long long B = 3LL; 
	long long _ = 1LL; 
END
//CASE(5)
//	long long K = 13LL; 
//	long long A = 12345LL; 
//	long long B = 67890123LL; 
//	long long _ = 8387584LL; 
//END
CASE(6)
	long long K = 3LL; 
	long long A = 0LL; 
	long long B = 100LL; 
	long long _ = 7LL; 
END
//CASE(6)
//	long long K = 3LL; 
//	long long A = 0LL; 
//	long long B = 1000000000000000000LL; 
//	long long _ = 7LL; 
//END

}
// END CUT HERE
