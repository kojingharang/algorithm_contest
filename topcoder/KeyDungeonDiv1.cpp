// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// You are exploring a dungeon.
In the dungeon you found some locked doors.
Each locked door has some red and some green keyholes (zero or more of each kind).
In order to open a door, you must insert fitting keys into all its keyholes simultaneously.
All the keys used to open a door break in the process of opening it and you have to throw them away.
However, each door hides a small chamber that contains some new keys for you.
Once you open the door, you may take all of those keys and possibly use them to open new doors.
(Of course, it only makes sense to open each door at most once. If you open the same door again, there will be no new keys for you.) 

There are three kinds of keys: red, green, and white ones.
Each red key fits into any red keyhole.
Each green key fits into any green keyhole.
Each white key fits into any keyhole (both red and green ones). 

You are given vector <int>s doorR, doorG, roomR, roomG, and roomW.
These five vector <int>s all have the same length.
For each valid i, the values at index i describe one of the doors you found:
the door has doorR[i] red and doorG[i] green keyholes, and upon opening it you gain new keys: roomR[i] red ones, roomG[i] green ones, and roomW[i] white ones. 

You are also given the vector <int> keys with three elements:
keys[0] is the number of red keys, keys[1] the number of green keys, and keys[2] the number of white keys you have at the beginning. 

Your goal is to have as many keys as possible at the moment when you decide to stop opening doors.
(The colors of the keys do not matter.)
You are allowed to open the doors in any order you like, and to choose the keys used to open each of the doors.
You are also allowed to stop opening doors whenever you are satisfied with your current number of keys.
Compute and return the maximal total number of keys you can have at the end.

DEFINITION
Class:KeyDungeonDiv1
Method:maxKeys
Parameters:vector <int>, vector <int>, vector <int>, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int maxKeys(vector <int> doorR, vector <int> doorG, vector <int> roomR, vector <int> roomG, vector <int> roomW, vector <int> keys)


CONSTRAINTS
-doorR, doorG, roomR, roomG and roomW will each contain between 1 and 12 elements, inclusive.
-doorR, doorG, roomR, roomG and roomW will contain the same number of elements.
-Each element of doorR, doorG, roomR, roomG and roomW will be between 0 and 10, inclusive.
-keys will contain exactly 3 elements.
-Each element of keys will be between 0 and 10, inclusive.


EXAMPLES

0)
{1, 2, 3}
{0, 4, 9}
{0, 0, 10}
{0, 8, 9}
{1, 0, 8}
{3, 1, 2}

Returns: 8

First you have 3 red keys, 1 green key, 2 white keys. You can end with 8 keys as follows:


First, you open door 0 using 1 red key. From the opened chamber you gain 1 white key, so currently you have 2 red keys, 1 green key, and 3 white keys.


Second, you open door 1 using 2 red keys, 1 green key, and 3 white keys (all of them into green locks). Immediately after opening the door you have no keys: all the ones you had were just used and thus they broke. However, the chamber you just opened contains 8 green keys.


You can't end with more than 8 keys, so you should return 8.

1)
{1, 1, 1, 2}
{0, 2, 3, 1}
{2, 1, 0, 4}
{1, 3, 3, 1}
{1, 0, 2, 1}
{0, 4, 0}

Returns: 4

You have only green keys, while each door has at least 1 red keyhole. So you cannot open any of the doors.

2)
{2, 0, 4}
{3, 0, 4}
{0, 0, 9}
{0, 0, 9}
{8, 5, 9}
{0, 0, 0}

Returns: 27

Initially you have no key at all, but door 1 also has no key hole. Therefore, you can start by opening door 1.

3)
{5, 3, 0, 0}
{0, 1, 2, 1}
{0, 9, 2, 4}
{2, 9, 2, 0}
{0, 9, 1, 1}
{1, 1, 0}

Returns: 32



4)
{9,5,10,8,4,3,0,8,4,1,3,9}
{9,10,0,8,9,4,3,8,1,8,10,4}
{1,2,0,2,3,3,5,3,1,3,0,5}
{5,2,5,0,5,2,3,4,0,0,5,2}
{1,5,1,2,0,4,4,0,3,3,1,3}
{5,0,1}

Returns: 16



******************************/
// END CUT HERE
#line 122 "KeyDungeonDiv1.cpp"
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

class KeyDungeonDiv1 {
	public:
	int maxKeys(vector <int> doorR, vector <int> doorG, vector <int> roomR, vector <int> roomG, vector <int> roomW, vector <int> keys) {
		
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
#define END	 verify_case(_, KeyDungeonDiv1().maxKeys(doorR, doorG, roomR, roomG, roomW, keys));}
int main(){

CASE(0)
	int doorR_[] = {1, 2, 3};
	  vector <int> doorR(doorR_, doorR_+sizeof(doorR_)/sizeof(*doorR_)); 
	int doorG_[] = {0, 4, 9};
	  vector <int> doorG(doorG_, doorG_+sizeof(doorG_)/sizeof(*doorG_)); 
	int roomR_[] = {0, 0, 10};
	  vector <int> roomR(roomR_, roomR_+sizeof(roomR_)/sizeof(*roomR_)); 
	int roomG_[] = {0, 8, 9};
	  vector <int> roomG(roomG_, roomG_+sizeof(roomG_)/sizeof(*roomG_)); 
	int roomW_[] = {1, 0, 8};
	  vector <int> roomW(roomW_, roomW_+sizeof(roomW_)/sizeof(*roomW_)); 
	int keys_[] = {3, 1, 2};
	  vector <int> keys(keys_, keys_+sizeof(keys_)/sizeof(*keys_)); 
	int _ = 8; 
END
CASE(1)
	int doorR_[] = {1, 1, 1, 2};
	  vector <int> doorR(doorR_, doorR_+sizeof(doorR_)/sizeof(*doorR_)); 
	int doorG_[] = {0, 2, 3, 1};
	  vector <int> doorG(doorG_, doorG_+sizeof(doorG_)/sizeof(*doorG_)); 
	int roomR_[] = {2, 1, 0, 4};
	  vector <int> roomR(roomR_, roomR_+sizeof(roomR_)/sizeof(*roomR_)); 
	int roomG_[] = {1, 3, 3, 1};
	  vector <int> roomG(roomG_, roomG_+sizeof(roomG_)/sizeof(*roomG_)); 
	int roomW_[] = {1, 0, 2, 1};
	  vector <int> roomW(roomW_, roomW_+sizeof(roomW_)/sizeof(*roomW_)); 
	int keys_[] = {0, 4, 0};
	  vector <int> keys(keys_, keys_+sizeof(keys_)/sizeof(*keys_)); 
	int _ = 4; 
END
CASE(2)
	int doorR_[] = {2, 0, 4};
	  vector <int> doorR(doorR_, doorR_+sizeof(doorR_)/sizeof(*doorR_)); 
	int doorG_[] = {3, 0, 4};
	  vector <int> doorG(doorG_, doorG_+sizeof(doorG_)/sizeof(*doorG_)); 
	int roomR_[] = {0, 0, 9};
	  vector <int> roomR(roomR_, roomR_+sizeof(roomR_)/sizeof(*roomR_)); 
	int roomG_[] = {0, 0, 9};
	  vector <int> roomG(roomG_, roomG_+sizeof(roomG_)/sizeof(*roomG_)); 
	int roomW_[] = {8, 5, 9};
	  vector <int> roomW(roomW_, roomW_+sizeof(roomW_)/sizeof(*roomW_)); 
	int keys_[] = {0, 0, 0};
	  vector <int> keys(keys_, keys_+sizeof(keys_)/sizeof(*keys_)); 
	int _ = 27; 
END
CASE(3)
	int doorR_[] = {5, 3, 0, 0};
	  vector <int> doorR(doorR_, doorR_+sizeof(doorR_)/sizeof(*doorR_)); 
	int doorG_[] = {0, 1, 2, 1};
	  vector <int> doorG(doorG_, doorG_+sizeof(doorG_)/sizeof(*doorG_)); 
	int roomR_[] = {0, 9, 2, 4};
	  vector <int> roomR(roomR_, roomR_+sizeof(roomR_)/sizeof(*roomR_)); 
	int roomG_[] = {2, 9, 2, 0};
	  vector <int> roomG(roomG_, roomG_+sizeof(roomG_)/sizeof(*roomG_)); 
	int roomW_[] = {0, 9, 1, 1};
	  vector <int> roomW(roomW_, roomW_+sizeof(roomW_)/sizeof(*roomW_)); 
	int keys_[] = {1, 1, 0};
	  vector <int> keys(keys_, keys_+sizeof(keys_)/sizeof(*keys_)); 
	int _ = 32; 
END
CASE(4)
	int doorR_[] = {9,5,10,8,4,3,0,8,4,1,3,9};
	  vector <int> doorR(doorR_, doorR_+sizeof(doorR_)/sizeof(*doorR_)); 
	int doorG_[] = {9,10,0,8,9,4,3,8,1,8,10,4};
	  vector <int> doorG(doorG_, doorG_+sizeof(doorG_)/sizeof(*doorG_)); 
	int roomR_[] = {1,2,0,2,3,3,5,3,1,3,0,5};
	  vector <int> roomR(roomR_, roomR_+sizeof(roomR_)/sizeof(*roomR_)); 
	int roomG_[] = {5,2,5,0,5,2,3,4,0,0,5,2};
	  vector <int> roomG(roomG_, roomG_+sizeof(roomG_)/sizeof(*roomG_)); 
	int roomW_[] = {1,5,1,2,0,4,4,0,3,3,1,3};
	  vector <int> roomW(roomW_, roomW_+sizeof(roomW_)/sizeof(*roomW_)); 
	int keys_[] = {5,0,1};
	  vector <int> keys(keys_, keys_+sizeof(keys_)/sizeof(*keys_)); 
	int _ = 16; 
END

}
// END CUT HERE
