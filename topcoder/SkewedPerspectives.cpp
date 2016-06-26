// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

Cat Taro has the following building blocks:

cubes[0] red unit cubes,
cubes[1] yellow unit cubes,
cubes[2] blue unit cubes,
B black rectangular prisms with dimensions 2x1x1.


Cat Taro is using the blocks to build w adjacent towers of blocks (some possibly empty), as shown on the right side of the picture below. Taro will always place the rectangular prisms vertically. In other words, each prism will look like two black unit cubes placed one on top of the other. Taro is not required to use all of the blocks when building the towers. (In fact, he may even decide not to use any blocks at all.)

 

Rabbit Hanako is looking at Taro's towers from the left side of the room. To him, the towers seem as a single tower which we will call a view, as shown on the left side of the picture above. More precisely, at each height i Hanako sees the color of the block at height i in the leftmost tower that has such a block. Hanako's view can be described as a string of characters, giving the colors of each 1x1 square seen by Hanako in the order from bottom to top.
Black squares will be denoted 'b', and colored squares will be denoted '0', '1', and '2' (in the same order used in cubes).

You are given the vector <int> cubes, the int B, the int w, and a vector <string> views.
Each element of views specifies one view Taro wants Hanako to see, in the format specified above.
Return a vector <string> with the same number of elements as views.
If Taro can build the towers in such a way that Hanako will see the view views[i], the i-th element of the return value should be "valid", otherwise it should be "invalid" (quotes for clarity).

DEFINITION
Class:SkewedPerspectives
Method:areTheyPossible
Parameters:vector <int>, int, int, vector <string>
Returns:vector <string>
Method signature:vector <string> areTheyPossible(vector <int> cubes, int B, int w, vector <string> views)


CONSTRAINTS
-w will be between 1 and 50, inclusive.
-cubes will contain exactly 3 elements.
-Each element of cubes will be between 0 and 100, inclusive.
-B will be between 0 and 100, inclusive.
-views will contain between 1 and 50 elements, inclusive.
-Each element of views will contain between 1 and 50 characters, inclusive.
-Each character in each element of views will be one of 'b', '0', '1', and '2'.


EXAMPLES

0)
{1,1,1}
1
2
{ "012", "012bb", "bb0", "21bb", "21b", "1bb20" }

Returns: {"valid", "valid", "valid", "valid", "valid", "valid" }

The following picture shows a way to achieve each of the given views.


1)
{0,1,0}
3
2
{"b","bb","bbb","bbbb","bbbbb","bbbbbb",
 "1", "1b","1bb","1bbb","1bbbb","1bbbbb","1bbbbbb",
 "b1","b1b","b1bb","b1bbb","b1bbbb","b1bbbbb",
 "bb1","bb1b","bb1bb","bb1bbb","bb1bbbb",
 "bbb1","bbb1b","bbb1bb","bbb1bbb",
 "bbbb1","bbbb1b","bbbb1bb",
 "bbbbb1","bbbbb1b",
 "bbbbbb1" }

Returns: {"invalid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "invalid", "invalid", "invalid", "invalid", "invalid", "invalid", "valid", "valid", "valid", "invalid", "valid", "invalid", "invalid", "invalid", "invalid", "valid", "invalid", "valid", "invalid", "invalid", "valid" }



2)
{100,0,0}
20
3
{"00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000b00000000000000",
 "0000000000000000000000000000000000000000000000000b",
 "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000"}

Returns: {"valid", "valid", "valid", "valid" }



3)
{5,6,3}
0
1
{"00000111111222", "0000111111222", "0000011111222", "000001111111222", "0000011111122", "b"}

Returns: {"valid", "valid", "valid", "invalid", "valid", "invalid" }



4)
{100,100,100}
100
50
{"2",
 "bb1b012012012012012012012",
 "bb1b012012012012012012012b",
 "bb1b012012012b012b012b012012b",
 "bb1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "b1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
 "bbb1b012012012012012012012"
}

Returns: {"valid", "valid", "valid", "valid", "valid", "invalid", "valid" }



5)
{0,0,0}
0
1
{"0", "bb"}

Returns: {"invalid", "invalid" }

Taro has no cubes and no prisms, therefore he cannot create any non-empty view.

6)
{3,0,0}
4
3
{"00b0b", "bbbbbbbb", "000b"}

Returns: {"invalid", "valid", "valid" }



*/
// END CUT HERE
#line 137 "SkewedPerspectives.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
//template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
//template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
//template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
//template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
//template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }


int f(vector <int> CU, int B, int W, string& V) {
	int cur=0;
	REP(j, V.size()) {
		if(V[j]=='0') { if(CU[0]>0) CU[0]--; else return 0; }
		if(V[j]=='1') { if(CU[1]>0) CU[1]--; else return 0; }
		if(V[j]=='2') { if(CU[2]>0) CU[2]--; else return 0; }
		if(V[j]=='b') {
			//cout<<j<<" "<<V[j]<<endl;
			if(j+1<V.size()) {
				if(V[j+1]=='b') {
					if(B>0) { B--; j++;} else return 0;
				} else return 0;
			} else {
				// next line
				cur++;
				if(cur>=W) return 0;
			}
		}
	}
	return 1;
}

class SkewedPerspectives {
	public:
	vector <string> areTheyPossible(vector <int> CU, int B, int W, vector <string> V) {
		vector<string> ans(V.size());
		REP(i, V.size()) {
			int ok = f(CU, B, W, V[i]);
			ans[i] = ok ? "valid" : "invalid";
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const vector <string>& Expected, const vector <string>& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, SkewedPerspectives().areTheyPossible(cubes, B, w, views));}
int main(){

CASE(0)
	int cubes_[] = {1,1,1};
	  vector <int> cubes(cubes_, cubes_+sizeof(cubes_)/sizeof(*cubes_)); 
	int B = 1; 
	int w = 2; 
	string views_[] = { "012", "012bb", "bb0", "21bb", "21b", "1bb20" };
	  vector <string> views(views_, views_+sizeof(views_)/sizeof(*views_)); 
	string __[] = {"valid", "valid", "valid", "valid", "valid", "valid" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	int cubes_[] = {0,1,0};
	  vector <int> cubes(cubes_, cubes_+sizeof(cubes_)/sizeof(*cubes_)); 
	int B = 3; 
	int w = 2; 
	string views_[] = {"b","bb","bbb","bbbb","bbbbb","bbbbbb",
 "1", "1b","1bb","1bbb","1bbbb","1bbbbb","1bbbbbb",
 "b1","b1b","b1bb","b1bbb","b1bbbb","b1bbbbb",
 "bb1","bb1b","bb1bb","bb1bbb","bb1bbbb",
 "bbb1","bbb1b","bbb1bb","bbb1bbb",
 "bbbb1","bbbb1b","bbbb1bb",
 "bbbbb1","bbbbb1b",
 "bbbbbb1" };
	  vector <string> views(views_, views_+sizeof(views_)/sizeof(*views_)); 
	string __[] = {"invalid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "valid", "invalid", "invalid", "invalid", "invalid", "invalid", "invalid", "valid", "valid", "valid", "invalid", "valid", "invalid", "invalid", "invalid", "invalid", "valid", "invalid", "valid", "invalid", "invalid", "valid" };
	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
END
//CASE(2)
//	int cubes_[] = {100,0,0};
//	  vector <int> cubes(cubes_, cubes_+sizeof(cubes_)/sizeof(*cubes_)); 
//	int B = 20; 
//	int w = 3; 
//	string views_[] = {"00000000000000000000000000000000000000000000000000",
// "00000000000000000000000000000000000b00000000000000",
// "0000000000000000000000000000000000000000000000000b",
// "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb0000000000000"};
//	  vector <string> views(views_, views_+sizeof(views_)/sizeof(*views_)); 
//	string __[] = {"valid", "valid", "valid", "valid" };
//	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
//END
//CASE(3)
//	int cubes_[] = {5,6,3};
//	  vector <int> cubes(cubes_, cubes_+sizeof(cubes_)/sizeof(*cubes_)); 
//	int B = 0; 
//	int w = 1; 
//	string views_[] = {"00000111111222", "0000111111222", "0000011111222", "000001111111222", "0000011111122", "b"};
//	  vector <string> views(views_, views_+sizeof(views_)/sizeof(*views_)); 
//	string __[] = {"valid", "valid", "valid", "invalid", "valid", "invalid" };
//	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
//END
//CASE(4)
//	int cubes_[] = {100,100,100};
//	  vector <int> cubes(cubes_, cubes_+sizeof(cubes_)/sizeof(*cubes_)); 
//	int B = 100; 
//	int w = 50; 
//	string views_[] = {"2",
// "bb1b012012012012012012012",
// "bb1b012012012012012012012b",
// "bb1b012012012b012b012b012012b",
// "bb1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
// "b1b0b1b2b0b1b2b0b1b2bb012b012b012012b",
// "bbb1b012012012012012012012"
//};
//	  vector <string> views(views_, views_+sizeof(views_)/sizeof(*views_)); 
//	string __[] = {"valid", "valid", "valid", "valid", "valid", "invalid", "valid" };
//	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
//END
//CASE(5)
//	int cubes_[] = {0,0,0};
//	  vector <int> cubes(cubes_, cubes_+sizeof(cubes_)/sizeof(*cubes_)); 
//	int B = 0; 
//	int w = 1; 
//	string views_[] = {"0", "bb"};
//	  vector <string> views(views_, views_+sizeof(views_)/sizeof(*views_)); 
//	string __[] = {"invalid", "invalid" };
//	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
//END
//CASE(6)
//	int cubes_[] = {3,0,0};
//	  vector <int> cubes(cubes_, cubes_+sizeof(cubes_)/sizeof(*cubes_)); 
//	int B = 4; 
//	int w = 3; 
//	string views_[] = {"00b0b", "bbbbbbbb", "000b"};
//	  vector <string> views(views_, views_+sizeof(views_)/sizeof(*views_)); 
//	string __[] = {"invalid", "valid", "valid" };
//	  vector <string> _(__, __+sizeof(__)/sizeof(*__)); 
//END

}
// END CUT HERE
