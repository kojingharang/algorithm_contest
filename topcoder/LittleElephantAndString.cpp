// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Little Elephant from the Zoo of Lviv likes strings.




You are given a string A and a string B of the same length. In one turn Little Elephant can choose any character of A and move it to the beginning of the string (i.e., before the first character of A). Return the minimal number of turns needed to transform A into B. If it's impossible, return -1 instead.


DEFINITION
Class:LittleElephantAndString
Method:getNumber
Parameters:string, string
Returns:int
Method signature:int getNumber(string A, string B)


CONSTRAINTS
-A will contain between 1 and 50 characters, inclusive.
-B will contain between 1 and 50 characters, inclusive.
-A and B will be of the same length.
-A and B will consist of uppercase letters ('A'-'Z') only.


EXAMPLES

0)
"ABC"
"CBA"

Returns: 2

The optimal solution is to make two turns. On the first turn, choose character 'B' and obtain string "BAC". On the second turn, choose character 'C' and obtain "CBA".

1)
"A"
"B"

Returns: -1

In this case, it's impossible to transform A into B.

2)
"AAABBB"
"BBBAAA"

Returns: 3



3)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"ZYXWVUTSRQPONMLKJIHGFEDCBA"

Returns: 25



4)
"A"
"A"

Returns: 0



5)
"DCABA"
"DACBA"

Returns: 2



******************************/
// END CUT HERE
#line 81 "LittleElephantAndString.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

class LittleElephantAndString {
	public:
	int getNumber(string A, string B) {
		string AA=A, BB=B;
		sort(ALL(AA));
		sort(ALL(BB));
		if(AA!=BB) return -1;
		
		int ans=0;
		int j=B.size()-1;
		for(int i=B.size()-1;i>=0;i--) {
			while(j>=0) {
				if(B[i]==A[j]) {
					j--;
					break;
				}
				ans++;
				j--;
			}
			if(j<0) break;
		}
		return ans;
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
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, LittleElephantAndString().getNumber(A, B));}
int main(){

CASE(0)
	string A = "ABC"; 
	string B = "CBA"; 
	int _ = 2; 
END
CASE(1)
	string A = "A"; 
	string B = "B"; 
	int _ = -1; 
END
CASE(2)
	string A = "AAABBB"; 
	string B = "BBBAAA"; 
	int _ = 3; 
END
CASE(3)
	string A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	string B = "ZYXWVUTSRQPONMLKJIHGFEDCBA"; 
	int _ = 25; 
END
CASE(4)
	string A = "A"; 
	string B = "A"; 
	int _ = 0; 
END
CASE(5)
	string A = "DCABA"; 
	string B = "DACBA"; 
	int _ = 2; 
END

}
// END CUT HERE
