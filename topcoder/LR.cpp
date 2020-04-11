// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// We have a cyclic array A of length n.
For each valid i, element i-1 the left neighbor of element i.
Additionally, element n-1 is the left neighbor of element 0.


You are given two vector<long long>s s and t, each with n elements.
Currently, we have A[i] = s[i] for each valid i.
Our goal is to have A[i] = t[i] for each valid i.


We can use two operations that modify the contents of A:

Operation L: Each element is increased by the value of its left neighbor.
Operation R: Each element is increased by the value of its right neighbor.


Note that all changes happen simultaneously. For example, if you use the operation L, the new value of A[7] is computed as the sum of the old value of A[7] and the old value of A[6].


If there is no way to reach the desired goal state, return "No solution".
Otherwise return any valid way of doing so by using at most 100 operations.
More precisely, return one valid sequence of operations encoded as a string of 'L's and 'R's.


If there are multiple valid solutions, you may return any of them.
In particular, you are not required to find the shortest valid solution.
Any valid solution will be accepted as long as its length does not exceed 100.
We can prove that if there is an valid solution then there must exist one with length at most 100.

DEFINITION
Class:LR
Method:construct
Parameters:vector<long long>, vector<long long>
Returns:string
Method signature:string construct(vector<long long> s, vector<long long> t)


CONSTRAINTS
-s will contain between 2 and 50 elements, inclusive.
-s and t will contain the same number of elements.
-Each element in s will be between 0 and 1,000,000,000,000,000 (10^15) inclusive.
-Each element in t will be between 0 and 1,000,000,000,000,000 (10^15) inclusive.


EXAMPLES

0)
{0,1,0,0,0}
{0,1,2,1,0}

Returns: "LL"

The first operation L will change A into {0,1,1,0,0} and then the second operation L will produce the array we wanted.

1)
{0,0,0,1}
{0,1,0,0}

Returns: "No solution"

Even though A is cyclic, the precise indices matter. Here, s and t are two different configurations, and there is no valid way to change this s into this t.

2)
{1,2,3,4,5,6,7,8,9,10}
{12,24,56,95,12,78,0,100,54,88}

Returns: "No solution"

Regardless of the type and order of operations all elements of A will always remain positive.
However, t contains a zero.
Therefore, t cannot be reached.

3)
{1,0,0}
{11,11,10}

Returns: "RRRRR"

The sequence of five operations R will change the array A as follows: 
{1,0,0} -> {1,0,1} -> {1,1,2} -> {2,3,3} -> {5,6,5} -> {11,11,10}.

4)
{1,1}
{562949953421312,562949953421312}

Returns: "RLLLRRRLLRRRLRLRRLLLLRLLRRLRRRLRRLRRLLRRRLLRRRLLL"

We start with A[0] = A[1] = 1, and we want A[0] = A[1] = 2^49.
We can easily verify that in this case each operation changes A from {x, x} into {2x, 2x}.
Therefore, any string of exactly 49 'L's and 'R's is a valid answer.

5)
{0,0,0,0,0}
{0,0,0,1,0}

Returns: "No solution"



6)
{123,456}
{123,456}

Returns: ""



*/
// END CUT HERE
#line 114 "LR.cpp"

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
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

// -1 L  1 R
VI rot(const VI& a, char d) {
	int lr = d=='L' ? -1 : 1;
	int N = a.size();
	VI rv(N);
	REP(i, N) rv[i] = a[(i+lr+N)%N]+a[i];
	return rv;
}

VI rotN(const VI& a, string d) {
	VI rv(a);
	for(auto c : d) rv = rot(rv, c);
	return rv;
}

VI shiftL(const VI& a) {
	int N = a.size();
	VI rv(N);
	REP(i, N) rv[i] = a[(i+1)%N];
	return rv;
}

class LR {
	public:
	string construct(vector<long long> s, vector<long long> t) {
		ll ss = accumulate(ALL(s), 0LL);
		ll st = accumulate(ALL(t), 0LL);
		if(ss>st) return "No solution";
		if(ss==st) {
			return s==t ? "" : "No solution";
		}
		if(ss==0) return "No solution";
		int cnt = 0;
		{
			bool ok = false;
			while(ss<=st) {
				if(ss==st) {
					ok=true;
					break;
				}
				ss*=2;
				cnt++;
			}
			if(!ok) return "No solution";
		}
		VI w(s);
		REP(i, cnt) {
			w = rot(w, 'L');
		}
		DD(w);
		bool ok = false;
		int R = 0;
		REP(i, s.size()) {
			if(w==t) {
				ok = true;
				break;
			}
			w = shiftL(w);
			R++;
		}
		if(ok && R<=cnt) {
			string ans(cnt, 'L');
			REP(i, R) ans[i] = 'R';
//			DD(s);
//			DD(t);
			DD(ans);
			DD(rotN(s, ans));
			assert(t==rotN(s, ans));
			return ans;
		}
		return "No solution";
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
#define END	 verify_case(_, LR().construct(s, t));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//VI w = {1,2,3,4,5};
////auto ds = {"LL", "LR", "RL", "RR"};
//auto ds = {"L", "R"};
//for(string s : ds) {
//	DD(rotN(w, s));
//}
//return 0;

CASE(0)
	long s_[] = {1,1};
	  vector<long long> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	long t_[] = {0,0};
	  vector<long long> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	string _ = "No solution"; 
END

CASE(0)
	long s_[] = {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	  vector<long long> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	long t_[] = {0,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	  vector<long long> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	string _ = "LL"; 
END

CASE(0)
	long s_[] = {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	  vector<long long> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	long t_[] = {1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	  vector<long long> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	string _ = "RL"; 
END

CASE(0)
	long s_[] = {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	  vector<long long> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	long t_[] = {0,0,1,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	  vector<long long> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	string _ = "No solution"; 
END

CASE(0)
	long s_[] = {0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	  vector<long long> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	long t_[] = {2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
	  vector<long long> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	string _ = "No solution"; 
END

CASE(0)
	long s_[] = {0,1,0,0,0};
	  vector<long long> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	long t_[] = {0,1,2,1,0};
	  vector<long long> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	string _ = "LL"; 
END
CASE(1)
	long s_[] = {0,0,0,1};
	  vector<long long> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	long t_[] = {0,1,0,0};
	  vector<long long> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	string _ = "No solution"; 
END
CASE(2)
	long s_[] = {1,2,3,4,5,6,7,8,9,10};
	  vector<long long> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	long t_[] = {12,24,56,95,12,78,0,100,54,88};
	  vector<long long> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	string _ = "No solution"; 
END
CASE(3)
	long s_[] = {1,0,0};
	  vector<long long> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	long t_[] = {11,11,10};
	  vector<long long> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	string _ = "RRRRR"; 
END
CASE(4)
	long s_[] = {1,1};
	  vector<long long> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	long t_[] = {562949953421312,562949953421312};
	  vector<long long> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	string _ = "RLLLRRRLLRRRLRLRRLLLLRLLRRLRRRLRRLRRLLRRRLLRRRLLL"; 
END
CASE(5)
	long s_[] = {0,0,0,0,0};
	  vector<long long> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	long t_[] = {0,0,0,1,0};
	  vector<long long> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	string _ = "No solution"; 
END
CASE(6)
	long s_[] = {123,456};
	  vector<long long> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	long t_[] = {123,456};
	  vector<long long> t(t_, t_+sizeof(t_)/sizeof(*t_)); 
	string _ = ""; 
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
// param type: long
	int N=UNIFORM_LL(1, 51);
	vector<long long> s; 
	{
		s = vector<long long>(N); 
		REP(i, N) {
			s[i] = UNIFORM_LL(0, 1000000);
		}
	}
// param type: long
	vector<long long> t; 
	{
		t = vector<long long>(N); 
		REP(i, N) {
			t[i] = UNIFORM_LL(0, 1000000);
		}
		if(UNIFORM_LL(0, 10) < 5) {
			t = vector<long long>(s); 
			string rs(UNIFORM_LL(3, 10), 'L');
			REP(i, rs.size()) rs[i] = UNIFORM_LL(0, 10) < 5 ? 'L' : 'R';
			t = rotN(t, rs);
		}
	}
	string _0 = LR().construct(s, t);
	string _1 = LRRef().construct(s, t);
	if(!verify_case(_0, _1, true)) {
print(s);
print(t);
	}
}
#endif

}
// END CUT HERE
