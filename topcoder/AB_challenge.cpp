// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// You are given two ints: N and K. Lun the dog is interested in strings that satisfy the following conditions:

The string has exactly N characters, each of which is either 'A' or 'B'.
The string s has exactly K pairs (i, j) (0 <= i < j <= N-1) such that s[i] = 'A' and s[j] = 'B'.

If there exists a string that satisfies the conditions, find and return any such string. Otherwise, return an empty string.

DEFINITION
Class:AB
Method:createString
Parameters:int, int
Returns:string
Method signature:string createString(int N, int K)


CONSTRAINTS
-N will be between 2 and 50, inclusive.
-K will be between 0 and N(N-1)/2, inclusive.


EXAMPLES

0)
3
2

Returns: "ABB"

This string has exactly two pairs (i, j) mentioned in the statement: (0, 1) and (0, 2).

1)
2
0

Returns: "BA"

Please note that there are valid test cases with K = 0.

2)
5
8

Returns: ""

Five characters is too short for this value of K.

3)
10
12

Returns: "BAABBABAAB"

Please note that this is an example of a solution; other valid solutions will also be accepted.

******************************/
// END CUT HERE
#line 61 "AB.cpp"
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

class AB {
	public:
	void check(string s, int N, int K) {
		cout<<"check "<<s<<" "<<N<<" "<<K<<endl;
		assert(N==s.size());
		REP(i, N) RANGE(j, i+1, N) if(s[i]=='A'&&s[j]=='B') K--;
		cout<<"check "<<s<<" "<<N<<" "<<K<<endl;
		assert(K==0);
	}
	string createString(const int N, const int K) {
		string ans;
		if(K==0) {
			REP(i, N) ans+="A";
		} else {
			RANGE(i, 1, N) {
				int tmp=K;
				vector<int>v(i);
				REP(j,i){
					v[j]=min(tmp,N-i);
					tmp-=v[j];
				}
				if(tmp==0) {
					reverse(ALL(v));
					REP(i,v.size()) {
						while(v[i]>tmp) {
							ans+="A";
							tmp++;
						}
						ans+="B";
					}
					if(ans.size()==N) break;
					else ans="";
				}
			}
		}
		if(ans.size()) check(ans, N, K);
		return ans;
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
#define END	 verify_case(_, AB().createString(N, K));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int N = 3; 
	int K = 2; 
	string _ = "ABB"; 
END
CASE(1)
	int N = 2; 
	int K = 0; 
	string _ = "BA"; 
END
CASE(2)
	int N = 5; 
	int K = 8; 
	string _ = ""; 
END
CASE(3)
	int N = 10; 
	int K = 12; 
	string _ = "BAABBABAAB"; 
END
RANGE(n, 2, 51) REP(k, n*(n-1)/2+1) {
	AB().createString(n, k);
}
//return 0;

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
	int N = UNIFORM_LL(0, 100); 
// param type: int
	int K = UNIFORM_LL(0, 100); 
	string _0 = AB().createString(N, K);
	string _1 = ABRef().createString(N, K);
	if(!verify_case(_0, _1, true)) {
print(N);
print(K);
	}
}
#endif

}
// END CUT HERE
