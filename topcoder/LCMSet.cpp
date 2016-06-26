// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// For any non-empty sequence of positive integers s1, s2, ..., sK their least common multiple is the smallest positive integer that is divisible by each of the given numbers.
We will use "lcm" to denote the least common multiple.
For example, lcm(3) = 3, lcm(4,6) = 12, and lcm(2,5,7) = 70.


Given a sequence S, we now define the set LCM(S) as follows:
LCM(S) = { lcm(s1, s2, ..., sk) | s1, s2, ..., sk belong to S, k > 0}.
In words: LCM(S) is the set of all values that can be obtained by selecting some elements of S and computing their least common multiple.
For example, for S={2,3,4} we have LCM(S)={2,3,4,6,12}.


You are given two vector <int>s A and B.
Return "Equal" if LCM(A) = LCM(B), and "Not equal" otherwise.

DEFINITION
Class:LCMSet
Method:equal
Parameters:vector <int>, vector <int>
Returns:string
Method signature:string equal(vector <int> A, vector <int> B)


CONSTRAINTS
-A will contain between 1 and 50 elements, inclusive.
-B will contain between 1 and 50 elements, inclusive.
-Each element in A will be between 2 and 1,000,000,000, inclusive.
-Each element in B will be between 2 and 1,000,000,000, inclusive.
-Elements in A will be distinct.
-Elements in B will be distinct.


EXAMPLES

0)
{2,3,4,12}
{2,3,4,6}

Returns: "Equal"

LCM(A) = LCM(B) = {2,3,4,6,12}

1)
{4,9}
{6,36}

Returns: "Not equal"

LCM(A) = {4,9,36}, LCM(B) = {6,36}

2)
{2,3,5,7,14,105}
{2,3,5,6,7,30,35}

Returns: "Equal"



3)
{2,3,5,7,14,105}
{2,3,5,6,7,30,36}

Returns: "Not equal"



4)
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}
{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}

Returns: "Equal"

Note that some of the numbers in the sets LCM(A) and LCM(B) can be huge.
In this case, the largest number in LCM(A) is 2305567963945518424753102147331756070.

5)
{999999999,1953125,512,1000000000}
{999999999,1953125,512}

Returns: "Equal"



6)
{999999998,999999999,1000000000}
{999999999,1000000000}

Returns: "Not equal"



******************************/
// END CUT HERE
#line 97 "LCMSet.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }



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

VI make_primes(int N) { // return all prime numbers less than N  memory: O(N) time: O(N^2)?
	VI p(N, 1), out;
	for(int i=2;i<N;i++) if(p[i]) { out.push_back(i); for(int j=i*2;j<N;j+=i) p[j]=0; }
	return out;
}

ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
VI h(vector<int>& A) {
	VI w0;
	REP(i, A.size()) {
        ll l = 1;
        REP(j, A.size()) {
            if(A[i] % A[j]==0 && A[j]<A[i]) l=lcm(l, A[j]);
        }
        if(A[i]!=l) w0.PB(A[i]);
	}
	return w0;
}

class LCMSet {
	public:
	string equal(vector <int> A, vector <int> B) {
		return h(A)==h(B) ? "Equal":"Not equal";
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
#define END	 verify_case(_, LCMSet().equal(A, B));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

/*
Dowxja
Fpecks
Gqrvld
Hwtbaf
Jeynsg
Krumdh
Ltizfj
Ayoxgk
Supchl
ky nq
nq

*/

string s = "dowxja ky nq c-kxkn";
REP(i, 26) {
	REP(j, s.size()) if(isalpha(s[j])) s[j] = ((s[j]-'a')+1)%26 +'a';
	cout<<s<<endl;
}
return 0;

CASE(0)
	int A_[] = {8, 585, 36, 73, 108, 634, 694, 330, 110, 85, 10, 90, 54, 23, 97, 346, 100, 3, 661, 13186, 7, 118, 239, 38, 11454, 16, 9, 13, 563, 83, 1406, 7740, 5, 53, 2, 6, 329, 4, 400, 1849860, 37, 498, 215, 450, 22};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {36, 239, 450, 85, 22, 4, 38, 37, 110, 9, 5, 634, 6, 100, 694, 563, 83, 346, 2, 90, 53, 54, 585, 97, 13, 7, 661, 3, 118, 23, 10, 215, 16, 73, 498, 550, 329, 8, 400};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string _ = "Not equal"; 
END
//return 0;



CASE(0)
	int A_[] = {2,3,4,12};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,3,4,6};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string _ = "Equal"; 
END
//return 0;
CASE(1)
	int A_[] = {4,9};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {6,36};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string _ = "Not equal"; 
END
CASE(2)
	int A_[] = {2,3,5,7,14,105};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,3,5,6,7,30,35};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string _ = "Equal"; 
END
CASE(3)
	int A_[] = {2,3,5,7,14,105};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,3,5,6,7,30,36};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string _ = "Not equal"; 
END
CASE(4)
	int A_[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string _ = "Equal"; 
END
CASE(5)
	int A_[] = {999999999,1953125,512,1000000000};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {999999999,1953125,512};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string _ = "Equal"; 
END
CASE(6)
	int A_[] = {999999998,999999999,1000000000};
	  vector <int> A(A_, A_+sizeof(A_)/sizeof(*A_)); 
	int B_[] = {999999999,1000000000};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string _ = "Not equal"; 
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
	vector <int> A; 
	{
		int N=UNIFORM_LL(1, 51);
		A = vector <int>(N); 
		REP(i, N) {
			A[i] = UNIFORM_LL(0, 1000000000);
		}
	}
// param type: int
	vector <int> B; 
	{
		int N=UNIFORM_LL(1, 51);
		B = vector <int>(N); 
		REP(i, N) {
			B[i] = UNIFORM_LL(0, 1000000000);
		}
	}
	string _0 = LCMSet().equal(A, B);
	string _1 = LCMSetRef().equal(A, B);
	if(!verify_case(_0, _1, true)) {
print(A);
print(B);
	}
}
#endif

}
// END CUT HERE
