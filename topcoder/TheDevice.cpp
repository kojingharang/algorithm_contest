// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Manao works at a laboratory on a highly classified project. From time to time, he is given a special device and has to determine its exact structure. Every such device operates on special plates. There are M bits written on each of the plates from left to right. The device has two inputs and a screen. Each input requires a plate. When two plates are connected to the device, M bits of output appear on the screen. Each bit of output is either a binary OR, AND or XOR of the corresponding bits of the input plates. Manao's task is to determine what operation is carried out for each of the bits.

Manao has N plates. He is going to test the device on each possible pair of these plates and determine its structure by the outputs on the screen. It might be that the plates Manao has are not enough to uniquely identify every possible device. You are given vector <string> plates, where each element describes a plate Manao has. Return the minimum number of additional plates Manao needs to be able to determine the structure of any device.

DEFINITION
Class:TheDevice
Method:minimumAdditional
Parameters:vector <string>
Returns:int
Method signature:int minimumAdditional(vector <string> plates)


CONSTRAINTS
-plates will contain between 1 and 50 elements, inclusive.
-Each element of plates will be between 1 and 50 characters long, inclusive.
-All elements of plates will be of equal length.
-Each element of plates will contain characters from the set {'0', '1'} only.


EXAMPLES

0)
{"010",
 "011",
 "101"}

Returns: 1

It is possible to find two different devices such that no pair of Manao's plates will distinguish between them. To fix this it is sufficient to add one more plate. An example of such a plate is "101". There are also other plates that would work in its place.


1)
{"0",
 "1",
 "0",
 "1"}

Returns: 0

With these plates, Manao can test the output for every possible pair of bits, which allows him to distinguish between AND, OR and XOR.

2)
{"01010101",
 "10101010"}

Returns: 1



3)
{"10010101011",
 "00010101001",
 "00100010111",
 "00101010101",
 "01010111101"}

Returns: 1



4)
{"1101001011010",
 "0010000010101",
 "1010101011110",
 "1101010100111",
 "1011111110111"}

Returns: 0



*/
// END CUT HERE
#line 78 "TheDevice.cpp"

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



class TheDevice {
	public:
	int minimumAdditional(vector <string> P) {
		ll ans = 0;
		REP(i, P[0].size()) {
			VI w(2);
			REP(j, P.size()) w[P[j][i]-'0']++;
			//cout<<w<<endl;
			ans = max(ans, max(0LL, 1-w[0])+max(0LL, 2-w[1]));
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
#define END	 verify_case(_, TheDevice().minimumAdditional(plates));}
int main(){

CASE(0)
	string plates_[] = {"010",
 "011",
 "101"};
	  vector <string> plates(plates_, plates_+sizeof(plates_)/sizeof(*plates_)); 
	int _ = 1; 
END
CASE(1)
	string plates_[] = {"0",
 "1",
 "0",
 "1"};
	  vector <string> plates(plates_, plates_+sizeof(plates_)/sizeof(*plates_)); 
	int _ = 0; 
END
CASE(2)
	string plates_[] = {"01010101",
 "10101010"};
	  vector <string> plates(plates_, plates_+sizeof(plates_)/sizeof(*plates_)); 
	int _ = 1; 
END
CASE(3)
	string plates_[] = {"10010101011",
 "00010101001",
 "00100010111",
 "00101010101",
 "01010111101"};
	  vector <string> plates(plates_, plates_+sizeof(plates_)/sizeof(*plates_)); 
	int _ = 1; 
END
CASE(4)
	string plates_[] = {"1101001011010",
 "0010000010101",
 "1010101011110",
 "1101010100111",
 "1011111110111"};
	  vector <string> plates(plates_, plates_+sizeof(plates_)/sizeof(*plates_)); 
	int _ = 0; 
END

}
// END CUT HERE
