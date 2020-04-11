// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
An ordered binary tree is a rooted binary tree in which each node X contains two pointers: X.left and X.right.
Each of these pointers either points to the corresponding child node, or it has a special value "None" meaning that node X doesn't have the corresponding child.



I just taught Antonio some tree traversal techniques on ordered binary trees.
I asked him to implement these tree traversals but I don't think he was paying attention, since he mixed them up and wrote the following pseudocode:



def order(v, mode):
    if v == None:
        return []
    if mode == "pre":
       return [v.label] + order(v.left, s[0]) + order(v.right, s[1])
    if mode == "in":
       return order(v.left, s[2]) + [v.label] + order(v.right, s[3])
    if mode == "post":
       return order(v.left, s[4]) + order(v.right, s[5]) + [v.label]



You are given the vector <string> s used in the pseudocode above.
You are guaranteed that among {s[0], s[2], s[4]} and also among {s[1], s[3], s[5]} each of the strings "pre", "in", and "post" appears exactly once.



I have a rooted binary tree with n nodes.
The nodes of the tree are labeled 1 through n, in no particular order.
The root of the tree is stored in a variable called root.



You are given strings e1 and e1.
It is guaranteed that these are two of the three strings "pre", "in", and "post".
Let e3 be the third, unused string.



You are also given vector <int>s a1 and a2, each of length n, and each containing a permutation of numbers 1 through n.



Consider the scenario in which we executed Antonio's code twice, as follows:


a1 = order(root, e1)
a2 = order(root, e2)



Is there a tree for which this scenario is possible?
If there is no tree that corresponds to the given a1, a2, e1, and e2, return an empty vector <int>.
Otherwise, suppose that we also executed the third matching command:



a3 = order(root, e3)



Find and return a3. If there are multiple solutions, you may return any of them.


DEFINITION
Class:PreInPost
Method:findMissing
Parameters:vector <string>, vector <int>, vector <int>, string, string
Returns:vector <int>
Method signature:vector <int> findMissing(vector <string> s, vector <int> a1, vector <int> a2, string e1, string e2)


CONSTRAINTS
-s will contain exactly 6 elements.
-Each element of s will be one of "pre", "in", "post".
-Among {s[0], s[2], s[4]} and {s[1], s[3], s[5]}, each of "pre", "in", "post" appears exactly once.
-a1 will have between 1 and 200 elements, inclusive.
-a2 will have the same length as a1.
-Both a1,a2 will be a permutation of 1 to len(a1).
-e1,e2 will each be one of "pre", "in", "post".
-e1 will be different from e2.


EXAMPLES

0)
{"post", "in", "pre", "post", "in", "pre"}
{1,2,3,4,5}
{2,4,3,5,1}

"pre"
"post"

Returns: {2, 1, 3, 5, 4 }

Here you are supposed to return the result of order(root, "in")

The returned result corresponds to the following rooted tree:
 




Another possible answer is {4,2,3,1,5}, which corresponds to the following tree:





1)
{"post", "in", "pre", "post", "in", "pre"}
{2,1,3,5,4}
{1,2,3,4,5}
"in"
"pre"

Returns: {2, 4, 3, 5, 1 }



2)
{"pre", "pre", "in", "in", "post", "post"}
{1,2,3,4,5,6,7,8,9,10}
{10,9,8,7,6,5,4,3,2,1}
"post"
"pre"

Returns: {10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }

It is allowed for nodes to have only one child.

3)
{"pre", "pre", "in", "in", "post", "post"}
{1}
{1}
"post"
"in"

Returns: {1 }



4)
{"pre", "in", "post", "pre", "in", "post"}
{9,3,4,1,6,5,2,7,8}
{3,9,1,4,2,7,8,5,6}
"in"
"post"

Returns: {6, 1, 9, 3, 4, 5, 8, 7, 2 }



5)
{"pre", "in", "in", "post", "post", "pre"}
{1,2,3}
{2,3,1}
"post"
"pre"

Returns: { }

In this case there is no solution.

*/
// END CUT HERE
#line 172 "PreInPost.cpp"

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



class PreInPost {
	public:
	vector <int> findMissing(vector <string> s, vector <int> a1, vector <int> a2, string e1, string e2) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const vector <int>& Expected, const vector <int>& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, PreInPost().findMissing(s, a1, a2, e1, e2));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string s_[] = {"post", "in", "pre", "post", "in", "pre"};
	  vector <string> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int a1_[] = {1,2,3,4,5};
	  vector <int> a1(a1_, a1_+sizeof(a1_)/sizeof(*a1_)); 
	int a2_[] = {2,4,3,5,1}
;
	  vector <int> a2(a2_, a2_+sizeof(a2_)/sizeof(*a2_)); 
	string e1 = "pre"; 
	string e2 = "post"; 
	int __[] = {2, 1, 3, 5, 4 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	string s_[] = {"post", "in", "pre", "post", "in", "pre"};
	  vector <string> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int a1_[] = {2,1,3,5,4};
	  vector <int> a1(a1_, a1_+sizeof(a1_)/sizeof(*a1_)); 
	int a2_[] = {1,2,3,4,5};
	  vector <int> a2(a2_, a2_+sizeof(a2_)/sizeof(*a2_)); 
	string e1 = "in"; 
	string e2 = "pre"; 
	int __[] = {2, 4, 3, 5, 1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	string s_[] = {"pre", "pre", "in", "in", "post", "post"};
	  vector <string> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int a1_[] = {1,2,3,4,5,6,7,8,9,10};
	  vector <int> a1(a1_, a1_+sizeof(a1_)/sizeof(*a1_)); 
	int a2_[] = {10,9,8,7,6,5,4,3,2,1};
	  vector <int> a2(a2_, a2_+sizeof(a2_)/sizeof(*a2_)); 
	string e1 = "post"; 
	string e2 = "pre"; 
	int __[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	string s_[] = {"pre", "pre", "in", "in", "post", "post"};
	  vector <string> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int a1_[] = {1};
	  vector <int> a1(a1_, a1_+sizeof(a1_)/sizeof(*a1_)); 
	int a2_[] = {1};
	  vector <int> a2(a2_, a2_+sizeof(a2_)/sizeof(*a2_)); 
	string e1 = "post"; 
	string e2 = "in"; 
	int __[] = {1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(4)
	string s_[] = {"pre", "in", "post", "pre", "in", "post"};
	  vector <string> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int a1_[] = {9,3,4,1,6,5,2,7,8};
	  vector <int> a1(a1_, a1_+sizeof(a1_)/sizeof(*a1_)); 
	int a2_[] = {3,9,1,4,2,7,8,5,6};
	  vector <int> a2(a2_, a2_+sizeof(a2_)/sizeof(*a2_)); 
	string e1 = "in"; 
	string e2 = "post"; 
	int __[] = {6, 1, 9, 3, 4, 5, 8, 7, 2 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(5)
	string s_[] = {"pre", "in", "in", "post", "post", "pre"};
	  vector <string> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int a1_[] = {1,2,3};
	  vector <int> a1(a1_, a1_+sizeof(a1_)/sizeof(*a1_)); 
	int a2_[] = {2,3,1};
	  vector <int> a2(a2_, a2_+sizeof(a2_)/sizeof(*a2_)); 
	string e1 = "post"; 
	string e2 = "pre"; 
	vector <int> _; 
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
	vector <string> s; 
	{
		int N=UNIFORM_LL(1, 51);
		s = vector <string>(N); 
		REP(i, N) {
			s[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> a1; 
	{
		int N=UNIFORM_LL(1, 51);
		a1 = vector <int>(N); 
		REP(i, N) {
			a1[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> a2; 
	{
		int N=UNIFORM_LL(1, 51);
		a2 = vector <int>(N); 
		REP(i, N) {
			a2[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: String
	string e1; 
	{
		int N=UNIFORM_LL(1, 51);
		e1 = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			e1[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
// param type: String
	string e2; 
	{
		int N=UNIFORM_LL(1, 51);
		e2 = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			e2[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	vector <int> _0 = PreInPost().findMissing(s, a1, a2, e1, e2);
	vector <int> _1 = PreInPostRef().findMissing(s, a1, a2, e1, e2);
	if(!verify_case(_0, _1, true)) {
print(s);
print(a1);
print(a2);
print(e1);
print(e2);
	}
}
#endif

}
// END CUT HERE
