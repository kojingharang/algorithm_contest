// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Marco likes strings.
In particular, he likes strings that have a lot of palindromic substrings.
For example, he really likes the string "aaa" because it has 6 palindromic substrings: "a" occurs three times, "aa" occurs twice, and "aaa" occurs once.

Right now, Marco has a string S composed of lowercase letters and question marks.
You are to reconstruct S from the given vector <string>s S1 and S2 as follows:

Concatenate all elements of S1 to make a string A.
Concatenate all elements of S2 to make a string B.
Finally, concatenate A and B to get S.



Marco is going to replace every question mark in S with a random lowercase letter ('a' - 'z').
Return the expected number of palindromic substrings in the resulting string.

DEFINITION
Class:PalindromicSubstringsDiv1
Method:expectedPalindromes
Parameters:vector <string>, vector <string>
Returns:double
Method signature:double expectedPalindromes(vector <string> S1, vector <string> S2)


NOTES
-For each question mark, the letter used to replace it is chosen uniformly at random. That is, the probability of choosing any particular letter is 1/26. All random choices are mutually independent.
-A palindromic string is a string that reads the same forwards and backwards.
-Your return value must have an absolute or a relative error of less than 1e-9.


CONSTRAINTS
-S1 and S2 will contain no more than 50 elements.
-Each element of S1 and S2 will contain no more than 50 characters.
-S will contain at least 1 character.
-S will contain only lowercase letters ('a' - 'z') and question marks ('?').


EXAMPLES

0)
{"a","a",""}
{"a"}

Returns: 6.0

This is the example given in the statement.

1)
{"z??"}
{}

Returns: 3.115384615384615

There are 26^2 = 676 equally likely possibilities for the letters used to replace the question marks.
Here are all possible outcomes:

The string "zzz" has 6 palindromic substrings.
Each of the 25 strings "zaz", "zbz", ..., "zyz" has 4 palindromic substrings.
Each of the 25 strings "zza", "zzb", ..., "zzy" has 4 palindromic substrings.
Each of the 25 strings "zaa", "zbb", ..., "zyy" has 4 palindromic substrings.
Each of the remaining 600 possible strings only has the 3 single-letter palindromic substrings.

The expected number of palindromic substrings can be computed simply as the average over all 676 possible cases.
Hence, the correct return value is (6 + 75*4 + 600*3) / 676.

2)
{"ab","c"}
{"??","a?"}

Returns: 7.315088757396449



3)
{}
{"?"}

Returns: 1.0



4)
{"ab?def","?"}
{"f??a"}

Returns: 12.545971779699588



******************************/
// END CUT HERE
#line 96 "PalindromicSubstringsDiv1.cpp"
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

double dp[5010][5010]; // [a][b] [a, b]


class PalindromicSubstringsDiv1 {
	public:
	double expectedPalindromes(vector <string> S1, vector <string> S2) {
		REP(i, 5000)REP(j, 5000)dp[i][j]=-1;
		string s = accumulate(ALL(S1), string(""))+accumulate(ALL(S2), string(""));
		int N=s.size();
		double ans=0;
		REP(i, N) {
			{
				double t=1;
				int j=1;
				ans+=t;
				while(i-j>=0 && i+j<N) {
					bool q=(s[i+j]=='?')||(s[i-j]=='?');
					if(s[i+j]==s[i-j]&&q) {
						t/=26.0;
						ans+=t;
						j++;
						continue;
					}
					if((s[i+j]!=s[i-j]&&q)){
						t/=26.0;
						ans+=t;
						j++;
						continue;
					}
					if((s[i+j]==s[i-j]&&!q)){
						ans+=t;
						j++;
						continue;
					}
					break;
				}
			}
			{
				double t=1;
				int j=0;
				while(i-j>=0 && i+1+j<N) {
					bool q=(s[i+1+j]=='?')||(s[i-j]=='?');
					if(s[i+1+j]==s[i-j]&&q) {
						t/=26.0;
						ans+=t;
						j++;
						continue;
					}
					if((s[i+1+j]!=s[i-j]&&q)){
						t/=26.0;
						ans+=t;
						j++;
						continue;
					}
					if((s[i+1+j]==s[i-j]&&!q)){
						ans+=t;
						j++;
						continue;
					}
					break;
				}
			}
		}
		return ans;
	}
};


class PalindromicSubstringsDiv1Try {
	public:
	double expectedPalindromes(vector <string> S1, vector <string> S2) {
		CLEAR(dp, 0);
		string s = accumulate(ALL(S1), string(""))+accumulate(ALL(S2), string(""));
		int N=s.size();
		double ans=0;
		RANGE(L, 1, N+1) REP(i, N-L+1) {
			char a=s[i], b=s[i+L-1];
			double lans=1.0/26;
			if(L==1) lans=1.0;
			else {
				if(a!='?' && b!='?' && a==b) lans = 1.0;
				if(a!='?' && b!='?' && a!=b) lans = 0.0;
			}
			double inner = L<=2 ? 1.0 : dp[i+1][i+L-1-1];
			dp[i][i+L-1] = lans * inner;
			ans += dp[i][i+L-1];
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const double& Expected, const double& Received, bool noPASSmsg=false) {
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, PalindromicSubstringsDiv1().expectedPalindromes(S1, S2));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string S1_[] = {"a","a",""};
	  vector <string> S1(S1_, S1_+sizeof(S1_)/sizeof(*S1_)); 
	string S2_[] = {"a"};
	  vector <string> S2(S2_, S2_+sizeof(S2_)/sizeof(*S2_)); 
	double _ = 6.0; 
END
CASE(1)
	string S1_[] = {"z??"};
	  vector <string> S1(S1_, S1_+sizeof(S1_)/sizeof(*S1_)); 
	vector <string> S2; 
	double _ = 3.115384615384615; 
END
//return 0;
CASE(2)
	string S1_[] = {"ab","c"};
	  vector <string> S1(S1_, S1_+sizeof(S1_)/sizeof(*S1_)); 
	string S2_[] = {"??","a?"};
	  vector <string> S2(S2_, S2_+sizeof(S2_)/sizeof(*S2_)); 
	double _ = 7.315088757396449; 
END
CASE(3)
	vector <string> S1; 
	string S2_[] = {"?"};
	  vector <string> S2(S2_, S2_+sizeof(S2_)/sizeof(*S2_)); 
	double _ = 1.0; 
END
CASE(4)
	string S1_[] = {"ab?def","?"};
	  vector <string> S1(S1_, S1_+sizeof(S1_)/sizeof(*S1_)); 
	string S2_[] = {"f??a"};
	  vector <string> S2(S2_, S2_+sizeof(S2_)/sizeof(*S2_)); 
	double _ = 12.545971779699588; 
END
#if 01  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: String
start_time=clock();
	vector <string> S1; 
	{
		int N=UNIFORM_LL(45, 50);
		S1 = vector <string>(N); 
		REP(i, N) {
			S1[i] = 'a'+UNIFORM_LL(0, 26);
			if(UNIFORM_LL(0, 100) > 10) S1[i]='?';
		}
	}
// param type: String
start_time=clock();
	vector <string> S2; 
	{
		int N=UNIFORM_LL(45, 50);
		S2 = vector <string>(N); 
		REP(i, N) {
			S2[i] = 'a'+UNIFORM_LL(0, 26);
			if(UNIFORM_LL(0, 100) > 0) S2[i]='?';
		}
	}
	double _0 = PalindromicSubstringsDiv1().expectedPalindromes(S1, S2);
	double _1 = PalindromicSubstringsDiv1Try().expectedPalindromes(S1, S2);
	if(!verify_case(_0, _1, true)) {
print(S1);
print(S2);
	}
}
#endif

}
// END CUT HERE
