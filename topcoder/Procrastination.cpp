// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are working in the Huge Software Company.
The company is so huge that it has an infinite number of employees.
Employee number 1 is reserved for the Big Boss and Legendary Founder of the company, Mr. Z.
Ordinary employees are numbered using positive integers, starting from 2.

At the beginning of the day each employee is assigned a task they should accomplish:
for each x from 2 to infinity, employee number x is assigned task number x.
During the day some pairs of employees will swap the tasks they were assigned.
The swapping follows a precise schedule that is described below.

The working day in the Huge Software Company has infinitely many hours.
The hours are numbered using positive integers, starting from 1.
During hour 1 there are no swaps at all.
During each of the following hours there are infinitely many swaps.
These look as follows:



During hour 2 we have the following swaps: workers 4 and 5 swap their tasks, workers 6 and 7 swap their tasks, workers 8 and 9 swap their tasks, and so on.


During hour 3 we have the following swaps: workers 6 and 7 swap their tasks, workers 9 and 10 swap their tasks, workers 12 and 13 swap their tasks, and so on.


...


Formally, for each h greater than or equal to 2, during hour h we look at all workers that have numbers divisible by h and strictly greater than h. Each of these workers will swap the task they currently have with the worker with a number one larger than their own.



It can be shown that for each employee there is a finite number of hours after which the employee will never swap their current task with anyone.
It can also be shown that for each task there is a finite number of hours after which the task will remain with the current employee forever.

You are given a long long n.
Compute and return the number of employee who will have the task number n at the end of the day.

DEFINITION
Class:Procrastination
Method:findFinalAssignee
Parameters:long long
Returns:long long
Method signature:long long findFinalAssignee(long long n)


CONSTRAINTS
-n will be between 2 and 10^10, inclusive.


EXAMPLES

0)
3

Returns: 3

Employee 3 is never involved in any swaps: neither with employee 2, nor with employee 4.

1)
8

Returns: 11

Task 8 starts assigned to employee 8. During hour 2 this employee swaps it for another task with employee 9. During hour 3 employee 9 gives this task to employee 10. Finally, during hour 5 employee 10 gives this task to employee 11 where it will stay forever.

2)
20

Returns: 20

Task 20 goes from employee 20 to employee 21 (during hour 2), then to employee 22 (during hour 3), then back to employee 21 (during hour 7), and finally back to employee 20 (during hour 10). This is where it then remains forever.

3)
196248

Returns: 196259



4)
5587021440

Returns: 5587021440



*/
// END CUT HERE
#line 93 "Procrastination.cpp"

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
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }


ll nxt(ll N, ll cur) {
	ll s = sqrt(N);
	if((cur+1)*(cur+1)<=N) {
		for(ll d=cur+1; d*d<=N; d++) {
			if(N%d==0) {
				ll m = d;
				return m;
				cout<<"m "<<m<<endl;
				// (ここで約数１コみつけた)
			}
		}
		for(ll d=s*s==N?s-1:s; d>=1; d--) {
			if(N%d==0) {
				ll m = N/d;
				return m;
				cout<<"m "<<m<<endl;
				// (ここで約数１コみつけた)
			}
		}
	} else {
//		cout<<"> N cur "<<N<<" "<<cur<<endl;
		for(ll d=N/(cur+1); d>=1; d--) {
			if(N%d==0) {
				ll m = N/d;
				return m;
				cout<<"m "<<m<<endl;
				// (ここで約数１コみつけた)
			}
		}
	}
	cout<<"N cur "<<N<<" "<<cur<<endl;
	assert(0);
	return 0;
}

class Procrastination {
	public:
	long long findFinalAssignee(long long N) {
		ll cur = 1;
		cout<<"init "<<cur<<" "<<N<<endl;
		while((cur+1)*2<=N) {
			ll n0 = nxt(N-1, cur);
			ll n1 = nxt(N, cur);
//			cout<<"cur N "<<cur<<" "<<N<<endl;
//			cout<<" n01 "<<n0<<" "<<n1<<endl;
			if(n0<n1) {
				N--;
			} else {
				N++;
			}
			cur=min(n0, n1);
		}
		cout<<" "<<N<<endl;
		return N;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const long long& Expected, const long long& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, Procrastination().findFinalAssignee(n));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(1)
	long long n = 8LL; 
	long long _ = 11LL; 
END
//return 0;
CASE(0)
	long long n = 3LL; 
	long long _ = 3LL; 
END
CASE(1)
	long long n = 8LL; 
	long long _ = 11LL; 
END
//return 0;
CASE(2)
	long long n = 20LL; 
	long long _ = 20LL; 
END
CASE(3)
	long long n = 196248LL; 
	long long _ = 196259LL; 
END
//return 0;
CASE(4)
	long long n = 5587021440LL; 
	long long _ = 5587021440LL; 
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
	long long n = UNIFORM_LL(0, 100); 
	long long _0 = Procrastination().findFinalAssignee(n);
	long long _1 = ProcrastinationRef().findFinalAssignee(n);
	if(!verify_case(_0, _1, true)) {
print(n);
	}
}
#endif

}
// END CUT HERE
