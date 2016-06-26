// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Fox Ciel has a list of names on her computer. In this problem, a name is simply a non-empty string of lowercase letters. All names in her list are distinct.


One day, when she left her seat, she forgot to lock her computer.
Then, Lun the mischievous dog appeared, and randomly shuffled the order of the names in her list.


Now, Ciel has to restore the original order of names using her memory. You are given a vector <string> names, along with two vector <int>s info1 and info2. names contains all names in the shuffled list in the order they appear.
info1 and info2 describes Ciel's memory of the original list. She remembers that, for each valid i, the info1[i]-th (0-indexed) name in the original list was a prefix of the info2[i]-th name.


Let X be the number of possible orders of the names in the original list that are consistent
with Ciel's memory. Calculate and return the value (X modulo 1,000,000,007). X can be 0, which means
Ciel's memory is inconsistent with the names in the list.

DEFINITION
Class:SimilarNames
Method:count
Parameters:vector <string>, vector <int>, vector <int>
Returns:int
Method signature:int count(vector <string> names, vector <int> info1, vector <int> info2)


NOTES
-A prefix of a string is the result of erasing zero or more characters from the right end of that string.


CONSTRAINTS
-names will contain between 2 and 50 elements, inclusive.
-Each element of names will contain between 1 and 50 characters, inclusive.
-Each character of each element of names will be a lowercase letter ('a'-'z').
-Elements of names will be distinct.
-info1 and info2 will each contain between 0 and 8 elements, inclusive.
-info1 and info2 will contain the same number of elements.
-Each element of info1 and info2 will be between 0 and n-1, inclusive, where n is the number of elements in names.
-For each valid i, info1[i] and info2[i] will be distinct.
-All pairs (info1[i], info2[i]) will be distinct.


EXAMPLES

0)
{"kenta", "kentaro", "ken"}
{0}
{1}

Returns: 3

Here, Ciel's list contains 3 names. She remembers that the 0-th name was a prefix of the 1-th name in the original list. Here are the all possible orders of names in the original list:

ken, kenta, kentaro
ken, kentaro, kenta
kenta, kentaro, ken

Note that it is possible that the order of the names in the original list coincides with that of the shuffled list.

1)
{"hideo", "hideto", "hideki", "hide"}
{0, 0}
{1, 2}

Returns: 6

She remembers that the 0-th name was a prefix of both the 1-th name and 2-th name in the original list. The only thing we can be sure is that the 0-th name was "hide".

2)
{"aya", "saku", "emi", "ayane", "sakura", "emika", "sakurako"}
{0, 1, 3, 5}
{1, 2, 4, 6}

Returns: 2

This time, she remembers many facts. The only possible original orders are:

saku, sakura, sakurako, aya, ayane, emi, emika
saku, sakura, sakurako, emi, emika, aya, ayane


3)
{"taro", "jiro", "hanako"}
{0, 1}
{1, 0}

Returns: 0

According to her memory, the 0-th name and the 1-th name in the original list must be the same, but actually all names are distinct. Her memory is inconsistent.

4)
{"alice", "bob", "charlie"}
{}
{}

Returns: 6

Unfortunately she remembers nothing in this case.

5)
{"ryota", "ryohei", "ryotaro", "ryo", "ryoga", "ryoma", "ryoko", "ryosuke", "ciel", "lun",
 "ryuta", "ryuji", "ryuma", "ryujiro", "ryusuke", "ryutaro", "ryu", "ryuhei", "ryuichi", "evima"}
{17, 5, 6, 13, 5}
{9, 2, 14, 17, 14}

Returns: 994456648



******************************/
// END CUT HERE
#line 113 "SimilarNames.cpp"
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

class SimilarNames {
	public:
	int count(vector <string> names, vector <int> info1, vector <int> info2) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, SimilarNames().count(names, info1, info2));}
int main(){

CASE(0)
	string names_[] = {"kenta", "kentaro", "ken"};
	  vector <string> names(names_, names_+sizeof(names_)/sizeof(*names_)); 
	int info1_[] = {0};
	  vector <int> info1(info1_, info1_+sizeof(info1_)/sizeof(*info1_)); 
	int info2_[] = {1};
	  vector <int> info2(info2_, info2_+sizeof(info2_)/sizeof(*info2_)); 
	int _ = 3; 
END
CASE(1)
	string names_[] = {"hideo", "hideto", "hideki", "hide"};
	  vector <string> names(names_, names_+sizeof(names_)/sizeof(*names_)); 
	int info1_[] = {0, 0};
	  vector <int> info1(info1_, info1_+sizeof(info1_)/sizeof(*info1_)); 
	int info2_[] = {1, 2};
	  vector <int> info2(info2_, info2_+sizeof(info2_)/sizeof(*info2_)); 
	int _ = 6; 
END
CASE(2)
	string names_[] = {"aya", "saku", "emi", "ayane", "sakura", "emika", "sakurako"};
	  vector <string> names(names_, names_+sizeof(names_)/sizeof(*names_)); 
	int info1_[] = {0, 1, 3, 5};
	  vector <int> info1(info1_, info1_+sizeof(info1_)/sizeof(*info1_)); 
	int info2_[] = {1, 2, 4, 6};
	  vector <int> info2(info2_, info2_+sizeof(info2_)/sizeof(*info2_)); 
	int _ = 2; 
END
CASE(3)
	string names_[] = {"taro", "jiro", "hanako"};
	  vector <string> names(names_, names_+sizeof(names_)/sizeof(*names_)); 
	int info1_[] = {0, 1};
	  vector <int> info1(info1_, info1_+sizeof(info1_)/sizeof(*info1_)); 
	int info2_[] = {1, 0};
	  vector <int> info2(info2_, info2_+sizeof(info2_)/sizeof(*info2_)); 
	int _ = 0; 
END
CASE(4)
	string names_[] = {"alice", "bob", "charlie"};
	  vector <string> names(names_, names_+sizeof(names_)/sizeof(*names_)); 
	vector <int> info1; 
	vector <int> info2; 
	int _ = 6; 
END
CASE(5)
	string names_[] = {"ryota", "ryohei", "ryotaro", "ryo", "ryoga", "ryoma", "ryoko", "ryosuke", "ciel", "lun",
 "ryuta", "ryuji", "ryuma", "ryujiro", "ryusuke", "ryutaro", "ryu", "ryuhei", "ryuichi", "evima"};
	  vector <string> names(names_, names_+sizeof(names_)/sizeof(*names_)); 
	int info1_[] = {17, 5, 6, 13, 5};
	  vector <int> info1(info1_, info1_+sizeof(info1_)/sizeof(*info1_)); 
	int info2_[] = {9, 2, 14, 17, 14};
	  vector <int> info2(info2_, info2_+sizeof(info2_)/sizeof(*info2_)); 
	int _ = 994456648; 
END
#if 0  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: String
start_time=clock();
	vector <string> names; 
	{
		int N=UNIFORM_LL(1, 50);
		names = vector <string>(N); 
		REP(i, N) {
			names[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
start_time=clock();
	vector <int> info1; 
	{
		int N=UNIFORM_LL(1, 50);
		info1 = vector <int>(N); 
		REP(i, N) {
			info1[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
start_time=clock();
	vector <int> info2; 
	{
		int N=UNIFORM_LL(1, 50);
		info2 = vector <int>(N); 
		REP(i, N) {
			info2[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = SimilarNames().count(names, info1, info2);
	int _1 = SimilarNamesTry().count(names, info1, info2);
	verify_case(_0, _1);
}
#endif

}
// END CUT HERE
