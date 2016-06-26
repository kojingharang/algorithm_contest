// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Some people are sitting in a row.
Each person came here from some country.
People from the same country are all sitting together.



A reporter has already approached some of the people and asked each of them the same question:
"How many people from your country (including you) are here?"
All the people who were asked the question gave her correct answers.



You are given a vector <int> a.
The elements of a correspond to the people in the row, in order.
For each i, element i of a is either 0 if the corresponding person was not asked the question, or a positive integer: the answer given by that person.



The reporter just realized that she might be able to reconstruct all the missing answers from the answers she already knows.
Return "Sufficient" if she can do that, or "Insufficient" if she cannot.


DEFINITION
Class:CountryGroupHard
Method:solve
Parameters:vector <int>
Returns:string
Method signature:string solve(vector <int> a)


CONSTRAINTS
-The number of elements in a will be between 1 and 100, inclusive.
-All numbers of a will be between 0 and 100, inclusive.
-There exist valid country assignment of people for input.


EXAMPLES

0)
{0,2,3,0,0}

Returns: "Sufficient"

The first two people must be from the same country. The last three people must also be from the same country. Thus, the only possible sequence of answers is {2,2,3,3,3}.

1)
{0,2,0}

Returns: "Insufficient"

There are still two different sequences of answers that are consistent with the reporter's information: the answers can be either {1,2,2} or {2,2,1}.

2)
{0,3,0,0,3,0}

Returns: "Sufficient"



3)
{0,0,3,3,0,0}

Returns: "Insufficient"



4)
{2,2,0,2,2}

Returns: "Sufficient"



******************************/
// END CUT HERE
#line 81 "CountryGroupHard.cpp"
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
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
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

class CountryGroupHard {
	public:
	string solve(vector <int> a) {
		vector<int> b(a);
		int N=a.size();
		VI dp(N);
		map<PII, int> done;
//		cout<<"a "<<a<<endl;
		REP(i, N) {
//			cout<<i<<endl;
			if(a[i]==0) {
				REP(L, N) RANGE(R, L, N) {
					if(!(L<=i&&i<=R)) continue;
					int az=1;
					RANGE(j, L, R+1) if(a[j]) az=0;
					if(!az) continue;
					if(!done.count(MP(L,R))) dp[R]+=L-1>=0 ? dp[L-1] : 1;
					done[MP(L,R)]=1;
				}
			}
			if(a[i]>0) {
				int LL = i-a[i]+1;
				RANGE(L, LL, i+1) {
					if(L<0) continue;
					int R=L+a[i]-1;
					if(R>=N) continue;
					int ok=1;
					if(L-1>=0 && !dp[L-1]) continue;
					RANGE(p, L, R+1) {
						if(!(a[p]==0 || a[p]==a[i])) ok=0;
					}
					if(ok) {
						if(!done.count(MP(L,R))) dp[R]+=L-1>=0?dp[L-1]:1;
						done[MP(L,R)]=1;
					}
				}
			}
//			cout<<"dp "<<dp<<endl;
		}
		return dp[N-1]==1 ? "Sufficient" : "Insufficient";
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
#define END	 verify_case(_, CountryGroupHard().solve(a));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int a_[] = {0,2,3,0,0};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	string _ = "Sufficient"; 
END
CASE(1)
	int a_[] = {0,2,0};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	string _ = "Insufficient"; 
END
CASE(2)
	int a_[] = {0,3,0,0,3,0};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	string _ = "Sufficient"; 
END
CASE(3)
	int a_[] = {0,0,3,3,0,0};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	string _ = "Insufficient"; 
END
CASE(4)
	int a_[] = {2,2,0,2,2};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	string _ = "Sufficient"; 
END
CASE(4)
	int a_[] = {1,0,1,0,1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	string _ = "Sufficient"; 
END
CASE(4)
	int a_[] = {0,0,0};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	string _ = "Insufficient"; 
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
	vector <int> a; 
	{
		int N=UNIFORM_LL(1, 51);
		a = vector <int>(N); 
		REP(i, N) {
			a[i] = UNIFORM_LL(0, 1000);
		}
	}
	string _0 = CountryGroupHard().solve(a);
	string _1 = CountryGroupHardRef().solve(a);
	if(!verify_case(_0, _1, true)) {
print(a);
	}
}
#endif

}
// END CUT HERE
