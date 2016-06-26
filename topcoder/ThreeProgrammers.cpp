// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
This problem is about three programmers who work together on a project.
The programmers' names are Alice, Bob, and Charles.
We will use 'A', 'B', and 'C' to denote them.





Each day exactly one of the three programmers works on the project.
The code history is a string that specifies who worked on which day.
For example, the string "AAC" means that Alice worked on the project for two days in a row and then Charles worked for a day.





Alice is always able to work on the project.
Each time Bob spends a day working, he needs to take at least one day off before he is able to work again.
Each time Charles spends a day working, he needs to take at least two days off.





The above information means that not all strings are valid code histories.
For example, the string "BB" is not a valid code history because Bob cannot work two days in a row.





You are given a string code.
This may or may not be a valid code history.
Find any permutation of letters of code that produces a valid code history, and return that code history.
If there are multiple solutions, you may return any of them.
If there are no solutions, return "impossible" instead.


DEFINITION
Class:ThreeProgrammers
Method:validCodeHistory
Parameters:string
Returns:string
Method signature:string validCodeHistory(string code)


CONSTRAINTS
-code will contain between 1 and 50 characters, inclusive.
-Each character in code will be one of 'A', 'B', and 'C'.


EXAMPLES

0)
"CAB"

Returns: "BCA"

The input is a valid code history.
In fact, any permutation of this input is a valid code history, and you may return any of them.

1)
"CBB"

Returns: "BCB"

Bob cannot work on two consecutive days.
Hence, "BCB" is the only valid code history that is a permutation of the given input.

2)
"BB"

Returns: "impossible"



3)
"BBA"

Returns: "BAB"



4)
"CAC"

Returns: "impossible"



5)
"ACAC"

Returns: "CAAC"



6)
"ACABC"

Returns: "ACABC"



7)
"BAABCABBCCACBAACABAABABBCCAACABCCAACCABCACACCBABAB"

Returns: "BACBABCAACBACABCBACBACABCBACBACABCABCAACBACAACABCA"



******************************/
// END CUT HERE
#line 119 "ThreeProgrammers.cpp"
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

int check(string s) {
	int N=s.size();
	REP(i, N) {
		if(s[i]=='C') {
			if(i+1<N) if(s[i+1]=='C') return 0;
			if(i+2<N) if(s[i+2]=='C') return 0;
		}
		if(s[i]=='B') {
			if(i+1<N) if(s[i+1]=='B') return 0;
		}
	}
	return 1;
}

string naive(string code) {
	sort(ALL(code));
	do {
		if(check(code)) return code;
	} while(next_permutation(ALL(code)));
	return "impossible";
}

string dp[2][52][52][3][3];

class ThreeProgrammers {
	public:
	string validCodeHistory(string code) {
		int N=code.size();
		int As=count(ALL(code), 'A');
		int Bs=count(ALL(code), 'B');
		int Cs=count(ALL(code), 'C');
		REP(a,2)REP(b,52)REP(c,52)REP(d,3)REP(e,3)dp[a][b][c][d][e]="";
		dp[0][0][0][0][0] = " ";
		int m=0;
		REP(i, N) {
			REP(b, Bs+1) REP(c, Cs+1) REP(l2, 3) REP(l1, 3) {
				if(dp[m][b][c][l2][l1].size()) {
					string& cur=dp[m][b][c][l2][l1];
					dp[1-m][b][c][l1][0] = cur+"A";
					if(l1!=1) dp[1-m][b+1][c][l1][1] = cur+"B";
					if(l1!=2 && l2!=2) dp[1-m][b][c+1][l1][2] = cur+"C";
				}
			}
			m=1-m;
		}
		REP(l2, 3) REP(l1, 3) {
			if(dp[m][Bs][Cs][l2][l1].size()) {
				return dp[m][Bs][Cs][l2][l1].substr(1);
			}
		}
		return "impossible";
	}
};

class ThreeProgrammersTrySample {
	public:
	string validCodeHistory(string code) {
		int N=code.size();
		int As=count(ALL(code), 'A');
		int Bs=count(ALL(code), 'B');
		int Cs=count(ALL(code), 'C');
		string s(N, ' ');
		int idx=0;
		idx=0;
		REP(i, Bs) {
			while(idx<N && s[idx]!=' ') idx++;
			if(idx>=N) return "impossible";
			s[idx]='B';
			idx+=2;
		}
		idx=0;
		REP(i, Cs) {
			while(idx<N && s[idx]!=' ') idx++;
			if(idx>=N) return "impossible";
			s[idx]='C';
			idx+=3;
		}
		idx=0;
		REP(i, As) {
			while(idx<N && s[idx]!=' ') idx++;
			if(idx>=N) return "impossible";
			s[idx]='A';
			idx+=1;
		}
		assert(As==count(ALL(s), 'A'));
		assert(Bs==count(ALL(s), 'B'));
		assert(Cs==count(ALL(s), 'C'));
		assert(0==count(ALL(s), ' '));
		return s;
	}
};

class ThreeProgrammersTry {
	public:
	string makeCode(map<char,int>&cnt) {
		int n = cnt['A']+cnt['B']+cnt['C'];
		string ans(n, 'A');
		if(cnt['C']*3-2==n) {
			for(int i=0;i<n;i+=3) {
				ans[i]='C';
				--cnt['C'];
			}
		} else if(cnt['B']*2-1==n) {
			for(int i=0;i<n;i+=2) {
				ans[i]='B';
				--cnt['B'];
			}
		}
		REP(i, n) {
			if(ans[i]!='A') continue;
			char work='A';
			if(cnt['C']>0 && (i-1<0||ans[i-1]!='C') && (i-2<0||ans[i-2]!='C')) work='C';
			else if(cnt['B']>0 && (i-1<0||ans[i-1]!='B')) work='B';
			--cnt[work];
			ans[i]=work;
		}
		return ans;
	}
	string validCodeHistory(string code) {
		int n=code.size();
		map<char,int> cnt;
		for(char c:code) ++cnt[c];
		if(cnt['C']*3-2>n) return "impossible";
		if(cnt['B']*2-1>n) return "impossible";
		return makeCode(cnt);
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
#define END	 verify_case(_, ThreeProgrammers().validCodeHistory(code));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//if(0)
{
	RANGE(N, 1, 20) {
		DD(N);
		REP(As, N+1) REP(Bs, N-As+1) {
			int Cs=N-As-Bs;
//			DD(As),DD(Bs),DD(Cs);
			string s(N, ' ');
			REP(i, As) s[i]='A';
			REP(i, Bs) s[As+i]='B';
			REP(i, Cs) s[As+Bs+i]='C';
			do {
//				DD(s);
//				string ref = naive(s);
				string ref = ThreeProgrammers().validCodeHistory(s);
				string ans = ThreeProgrammersTry().validCodeHistory(s);
//				DD(ref);
//				DD(ans);
				if(ref=="impossible") {
					if(ans!=ref) {
						DD(s);
						DD(ref);
						DD(ans);
					}
					assert(ans==ref);
				} else {
					if(ans=="impossible" || check(ans)==0) {
						DD(s);
						DD(ref);
						DD(ans);
					}
					assert(ans!="impossible");
					assert(1==check(ans));
				}
			} while(next_permutation(ALL(s)));
		}
	}
}

CASE(0)
	string code = "CAB"; 
	string _ = "BCA"; 
END
CASE(1)
	string code = "CBB"; 
	string _ = "BCB"; 
END
CASE(2)
	string code = "BB"; 
	string _ = "impossible"; 
END
CASE(3)
	string code = "BBA"; 
	string _ = "BAB"; 
END
CASE(4)
	string code = "CAC"; 
	string _ = "impossible"; 
END
CASE(5)
	string code = "ACAC"; 
	string _ = "CAAC"; 
END
CASE(6)
	string code = "ACABC"; 
	string _ = "ACABC"; 
END
CASE(7)
	string code = "BAABCABBCCACBAACABAABABBCCAACABCCAACCABCACACCBABAB"; 
	string _ = "BACBABCAACBACABCBACBACABCBACBACABCABCAACBACAACABCA"; 
END
CASE(6)
	string code = "A"; 
	string _ = "A"; 
END
CASE(6)
	string code = "B"; 
	string _ = "B"; 
END
CASE(6)
	string code = "C"; 
	string _ = "C"; 
END
CASE(6)
	string code = "AA"; 
	string _ = "AA"; 
END
CASE(6)
	string code = "CC"; 
	string _ = "impossible"; 
END
CASE(6)
	string code = "BCC"; 
	string _ = "impossible"; 
END
CASE(6)
	string code = "CBACB"; 
	string _ = "CBACB"; 
END
CASE(6)
	string code = "AAABBBCCC"; 
	string _ = "CBACBACBA"; 
END
CASE(6)
	string code = "CCBBBA"; 
	string _ = "CBABCB"; 
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
	string code; 
	{
		int N=UNIFORM_LL(1, 51);
		code = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			code[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	string _0 = ThreeProgrammers().validCodeHistory(code);
	string _1 = ThreeProgrammersRef().validCodeHistory(code);
	if(!verify_case(_0, _1, true)) {
print(code);
	}
}
#endif

}
// END CUT HERE
