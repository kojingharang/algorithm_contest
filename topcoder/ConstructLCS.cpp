// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A string S is a subsequence of a string T if we can obtain S from T by erasing some (possibly all or none) of its characters. For example, "000" is a subsequence of "01010".


The longest common subsequence (LCS) of two strings A and B is a string C that is a subsequence of each of them and has the largest length among all strings with this property. Let f(A,B) be the length of the LCS of strings A and B. For example, we have f("101", "111000") = 2, f("101", "110011") = 3, and f("00", "1111") = 0.


You are given three small positive integers ab, bc, and ca.
Please find three strings A, B, C such that:

Each of the strings contains only the characters '0' and '1'.
The length of each string is between 1 and 1,000, inclusive.
f(A, B) = ab
f(B, C) = bc
f(C, A) = ca


Return a string formed as follows: A + " " + B + " " + C.
(I.e., the returned string should contain the three strings A, B, C, separated by single spaces.)


You may assume that a solution always exist.
If there are multiple solutions you may return any of them.

DEFINITION
Class:ConstructLCS
Method:construct
Parameters:int, int, int
Returns:string
Method signature:string construct(int ab, int bc, int ca)


CONSTRAINTS
-ab will be between 1 and 50, inclusive.
-bc will be between 1 and 50, inclusive.
-ca will be between 1 and 50, inclusive.


EXAMPLES

0)
3
4
2

Returns: "101 1010101 1111"

The returned string corresponds to the following solution:

A = "1111"
B = "101"
C = "1010101"


We can easily verify that the only LCS of A and B is "11", the only LCS of B and C is "101", and the only LCS of C and A is "1111".

1)
7
4
4

Returns: "10101010 1010101 1011"

There are other solutions like: A = "1110000", B = "1110000", C = "0000".

2)
8
7
8

Returns: "110101001011 010101101 10101010"



3)
8
6
7

Returns: "110101010 10101010 1111010"



4)
15
17
19

Returns: "000100101101111011000 11110111010011101010 100100001010101001010101000011111"



5)
50
50
50

Returns: "11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111"



*/
// END CUT HERE
#line 107 "ConstructLCS.cpp"

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

#define MAX 1010
int LCS[MAX][MAX];

void ini(){
  for(int i=0;i<MAX;i++)
    for(int j=0;j<MAX;j++)
      LCS[i][j] = 0;
}

int lcs(string a,string b){
	ini();
  if(b.length() > a.length())
    swap(a,b);
  int I = a.length(),J=b.length();
  for(int i=1;i<=I;i++){
    for(int j=1;j<=J;j++){
      if( a[i-1]== b[j-1])LCS[i][j]=LCS[i-1][j-1]+1;
      else LCS[i][j] = max(LCS[i][j-1],LCS[i-1][j]);
    }
  }
  return LCS[I][J];
}

void test(const string& a, const string& b, const string& c, int ab, int bc, int ca) {
	assert(a.size()<=1000);
	assert(b.size()<=1000);
	assert(c.size()<=1000);
	int lab = lcs(a, b);
	int lbc = lcs(b, c);
	int lca = lcs(c, a);
//	DD(lab);
//	DD(lbc);
//	DD(lca);
	assert(ab==lab);
	assert(bc==lbc);
	assert(ca==lca);
}

void check(const string& ans, int ab, int bc, int ca) {
	stringstream ss(ans);
	string a, b, c;
	ss>>a>>b>>c;
	DD(ab);DD(bc);DD(ca);
	DD(a);DD(b);DD(c);
	test(a, b, c, ab, bc, ca);
}

void add(string&s, int times, char c) {
	while(times--) {
		s.push_back(c);
	}
}

class ConstructLCS {
	public:
	string solve(int t, int ab, int bc, int ca) {
		string A,B,C;
		if(t==0) {
			REP(i, max(ab,ca)) {
				A+='1';
			}
			REP(i, ab) B+='1';
			REP(i, ca) C+='1';
			int rest=bc-ab;
			REP(i, rest) {
				B+='0';
				C+='0';
			}
		}
		if(t==2) {
			REP(i, max(ab,ca)) {
				A+='1';
			}
			REP(i, ab) B+='1';
			REP(i, ca) C+='1';
			int rest=bc-ca;
			REP(i, rest) {
				B+='0';
				C+='0';
			}
		}
		if(t==1) {
			REP(i, max(ab,bc)) {
				B+='1';
			}
			REP(i, ab) A+='1';
			REP(i, bc) C+='1';
			int rest=ca-bc;
			REP(i, rest) {
				A+='0';
				C+='0';
			}
		}
		return A+" "+B+" "+C;
	}
	string construct(int ab, int bc, int ca) {
		int mini=ab;
		mini=min(mini,bc);
		mini=min(mini,ca);
		if(mini==ab) return solve(0, ab,bc,ca);
		if(mini==bc) return solve(1, ab,bc,ca);
		if(mini==ca) return solve(2, ab,bc,ca);
		return "-1";
	}
};


class ConstructLCSRef {
	public:
	string construct(int ab, int bc, int ca) {
//		DD(ab);
//		DD(bc);
//		DD(ca);
		vector<pair<int, string>> w = {
			{ab, "ab"},
			{bc, "bc"},
			{ca, "ca"},
		};
		sort(ALL(w));
		string order(3, ' ');
		REP(i, 3) {
			int ni = (i+1)%3;
			string cur = w[i].second;
			string nxt = w[ni].second;
			char common;
			REP(j, 3) {
				char c = 'a'+j;
				if(cur.find(c)!=string::npos && nxt.find(c)!=string::npos) {common = c;break;}
			}
			char aa;
			for(char c : cur) if(common!=c) aa=c;
//			DD(i);
//			DD(w[i].first);
//			DD(w[i].second);
//			DD(common);
//			DD(aa);
			order[i] = aa;
		}
		VI v(3);
		REP(i, 3) v[i] = w[i].first;
		map<char, string> h;
		vector<string> ss(3);
		ss[0] = string(v[0], '1');
		{
			string s = ss[0];
			if(v[0] < v[1]) s.push_back('1');
			REP(j, v[1]-v[0]-1) {
				s.PB('1');
			}
			ss[1] = s;
		}
		{
			string s = ss[1];
			REP(j, v[2]-v[0]) {
				ss[0] = "0" + ss[0];
				s = "0" + s;
			}
			ss[2] = s;
		}
//		DD(ss);
		REP(i, 3) h[order[i]] = ss[i];
		string ans = h['a']+" "+h['b']+" "+h['c'];
//		DD(ans);
		test(h['a'], h['b'], h['c'], ab, bc, ca);
		check(ans, ab, bc, ca);
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
#define END	 verify_case(_, ConstructLCS().construct(ab, bc, ca));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//DD(lcs("101", "101"));
//DD(lcs("1111", "101"));
//
//test("101", "1010101", "1111", 3, 4, 2);

RANGE(ab, 1, 51) RANGE(bc, 1, 51) RANGE(ca, 1, 51) {
	string ans = ConstructLCS().construct(ab, bc, ca);
	check(ans, ab, bc, ca);
}

CASE(0)
	int ab = 3; 
	int bc = 4; 
	int ca = 2; 
	string _ = "101 1010101 1111"; 
END
//return 0;
CASE(1)
	int ab = 7; 
	int bc = 4; 
	int ca = 4; 
	string _ = "10101010 1010101 1011"; 
END
CASE(2)
	int ab = 8; 
	int bc = 7; 
	int ca = 8; 
	string _ = "110101001011 010101101 10101010"; 
END
CASE(3)
	int ab = 8; 
	int bc = 6; 
	int ca = 7; 
	string _ = "110101010 10101010 1111010"; 
END
CASE(4)
	int ab = 15; 
	int bc = 17; 
	int ca = 19; 
	string _ = "000100101101111011000 11110111010011101010 100100001010101001010101000011111"; 
END
CASE(5)
	int ab = 50; 
	int bc = 50; 
	int ca = 50; 
	string _ = "11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111 11111111111111111111111111111111111111111111111111"; 
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
	int ab = UNIFORM_LL(0, 100); 
// param type: int
	int bc = UNIFORM_LL(0, 100); 
// param type: int
	int ca = UNIFORM_LL(0, 100); 
	string _0 = ConstructLCS().construct(ab, bc, ca);
	string _1 = ConstructLCSRef().construct(ab, bc, ca);
	if(!verify_case(_0, _1, true)) {
print(ab);
print(bc);
print(ca);
	}
}
#endif

}
// END CUT HERE
