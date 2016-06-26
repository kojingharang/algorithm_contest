// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
A lucky number is a positive integer such that each of its digits is a 4 or a 7.
A lucky sum is the sum of two (not necessarily distinct) lucky numbers.
Cat loves lucky sums!



Cat has a string note.
Each character in note is either a digit or a question mark.
A number matches note if it can be produced from note by changing each question mark to a single digit.
Note that the number produced this way must not have any leading zeros: after the changes, note[0] must be between '1' and '9', inclusive.



Find and return the smallest lucky sum that matches note.
If there are no lucky sums that match note, return -1.


DEFINITION
Class:LuckySum
Method:construct
Parameters:string
Returns:long long
Method signature:long long construct(string note)


CONSTRAINTS
-note will contain between 1 and 14 characters, inclusive.
-Each character of note will be either a digit ('0'-'9') or a question mark ('?').
-The first character of note will not be '0'.
-At least one character of note will be '?'.


EXAMPLES

0)
"?"

Returns: 8

4+4=8, which is the smallest lucky sum.

1)
"?1"

Returns: 11

4+7=11

2)
"4?8"

Returns: 448

4+444=448

3)
"2??"

Returns: -1

The numbers that match this note are the numbers 200 through 299. None of these numbers is a lucky sum.

4)
"??????????????"

Returns: 11888888888888



******************************/
// END CUT HERE
#line 77 "LuckySum.cpp"
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
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<(v)<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

ll values[] = {
8,
11,14,48,51,54,78,81,84,88,91,94,118,121,124,148,151,154,448,451,454,478,481,484,488,491,494,518,521,524,548,551,554,748,751,754,778,781,784,788,791,794,818,821
,824,848,851,854,888,891,894,

};

class LuckySum {
	public:
	ll value(int pat, int di) {
		ll v=0;
		ll p=1;
		REP(i, di) {
			v += ((pat&1) ? 7 : 4)*p;
			p*=10;
			pat>>=1;
		}
		return v;
	}
	long long construct(string note) {
		if(0)
		{
			VI one, w;
			RANGE(di, 1, 14)
			REP(i, 1<<di) {
	//			cout<<value(i, di)<<endl;
				one.PB(value(i, di));
			}
			REP(i, one.size()) REP(j, one.size()) {
				w.PB(one[i]+one[j]);
			}
			sort(ALL(w));
//			cout<<w.size()<<endl;
			w.erase(unique(ALL(w)), w.end());
//			cout<<w.size()<<endl;
			REP(i, w.size()) {
				cout<<w[i]<<",";
				if(i%1000==0) cout<<endl;
			}
			return 0;
		}
		
		int co=0;
		int N=note.size();
		for(ll v : values) {
//			cout<<v<<endl;
			ll vv = v;
			int ok=1;
			REP(i, N) {
				if(vv==0) {ok=0;break;}
				//cout<<"vv "<<vv<<" "<<i<<endl;
				if(note[N-1-i]!='?') {
					if(vv%10 != (note[N-1-i]-'0')) {ok=0;break;}
				}
				vv/=10;
			}
			if(ok && vv) ok=0;
			if(ok) return v;
			//if(vv) break;
			co++;
			//if(co>100) break;
		}
		return -1;
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
#define END	 verify_case(_, LuckySum().construct(note));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string note = "?"; 
	long long _ = 8LL; 
END
//return 0;
CASE(1)
	string note = "?1"; 
	long long _ = 11LL; 
END
	//return 0;
CASE(2)
	string note = "4?8"; 
	long long _ = 448LL; 
END
CASE(3)
	string note = "2??"; 
	long long _ = -1LL; 
END
CASE(4)
	string note = "??????????????"; 
	long long _ = 11888888888888LL; 
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
// param type: String
	string note; 
	{
		int N=UNIFORM_LL(1, 51);
		note = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			note[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	long long _0 = LuckySum().construct(note);
	long long _1 = LuckySumRef().construct(note);
	if(!verify_case(_0, _1, true)) {
print(note);
	}
}
#endif

}
// END CUT HERE
