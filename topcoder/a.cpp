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
