// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Goose Tattarrattat has a string S of lowercase letters.
Tattarrattat wants to change her string into a palindrome: a string that reads the same forwards and backwards.
(For example, "racecar" is a palindrome.)

She will do this in a series of steps.
In each step, Tattarrattat will choose two letters of the alphabet: X and Y.
She will then change each X in her string into a Y.
Changing each single character takes 1 second.

For example, if S="goose" and Tattarrattat chooses X='o' and Y='e' in the next step, the step will take 2 seconds (because there are two 'o's in S) and after the step she would have S="geese".

You are given the string S.
Return the smallest number of seconds in which Tattarrattat can change S into a palindrome.

DEFINITION
Class:GooseTattarrattatDiv1
Method:getmin
Parameters:string
Returns:int
Method signature:int getmin(string S)


NOTES
-Tattarrattat must always change all occurrences of the chosen letter into the other one; she is not allowed to change only some of the occurrences.


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"geese"

Returns: 2

There are many ways how Tattarrattat can change this S into a palindrome.
For example, she could do it in two steps as follows:

Change all 'g's to 'e's: this takes 1 second and produces the string "eeese".
Change all 'e's to 's's: this takes 4 seconds and produces the string "sssss".

This way took her 1+4 = 5 seconds.
However, there are faster ways.
The best one only takes 2 seconds.
For example, she can first change all 'g's to 'e's (1 second), and then change all 's's to 'e's (1 second), obtaining the palindrome "eeeee".

1)
"tattarrattat"

Returns: 0

This string is already a palindrome so no changes are needed.

2)
"xyyzzzxxx"

Returns: 2



3)
"xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"

Returns: 11



4)
"abaabb"

Returns: 3



*/
// END CUT HERE
#line 84 "GooseTattarrattatDiv1.cpp"

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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool Union(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool Find(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

class GooseTattarrattatDiv1 {
	public:
	int getmin(string S) {
		UnionFind uf(26);
		int N=S.size();
		REP(i, N/2) {
			uf.Union(S[i]-'a', S[N-1-i]-'a');
		}
		map<int, int> vis;
		int ans = 0;
		REP(i, 26) {
			int root = uf.root(i);
			if(vis[root]) continue;
			vis[root]=1;
			string same;
			VI cnt;
			REP(j, 26) {
				if(root==uf.root(j)) {
					same+=string(1, 'a'+j);
					int ct=0;
					REP(k, N) if(S[k]=='a'+j) ct++;
					cnt.PB(ct);
				}
			}
			//cout<<string(1, 'a'+i)<<" "<<same<<" "<<cnt<<endl;
			if(same.size()==0) continue;
			sort(ALLR(cnt));
			ans += accumulate(ALL(cnt), 0)-cnt[0];
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
#define END	 verify_case(_, GooseTattarrattatDiv1().getmin(S));}
int main(){

CASE(0)
	string S = "geese"; 
	int _ = 2; 
END
//return 0;
CASE(1)
	string S = "tattarrattat"; 
	int _ = 0; 
END
CASE(2)
	string S = "xyyzzzxxx"; 
	int _ = 2; 
END
CASE(3)
	string S = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"; 
	int _ = 11; 
END
CASE(4)
	string S = "abaabb"; 
	int _ = 3; 
END

}
// END CUT HERE
