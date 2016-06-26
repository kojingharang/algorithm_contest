// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Tanya has a rectangular table filled with letters.

First, she makes four copies of this table, and arranges the copies as a 2Å~2 rectangle.

Then she lists all subrectangles of the resulting table.

For example, for the following original table:
OK
she will arrange the copies like this:

OKOK
OKOK

and then she will list the following 30 subrectangles (dots for clarity only):

OKOK .... OKOK OKO. .... OKO. .KOK .... .KOK
OKOK OKOK .... OKO. OKO. .... .KOK .KOK ....

OK.. .... OK.. .KO. .... .KO. ..OK .... ..OK 
OK.. OK.. .... .KO. .KO. .... ..OK ..OK .... 

O... .... O... .K.. .... .K.. ..O. .... ..O. ...K .... ...K 
O... O... .... .K.. .K.. .... ..O. ..O. .... ...K ...K ....

(Note that she is considering all subrectangles based on their positions rather than their content, so the same subrectangle might appear multiple times in the list.  In this case, subrectangle "K" appears four times because it occurs at four different positions.)

Tanya wonders how frequently each letter of the alphabet occurs among all these subrectangles.  You are given a vector <string> table, where the j-th character of the i-th element is the letter at row i, column j of the original table.  Return a vector<long long> containing exactly 26 elements, where the i-th element is the number of occurrences of the i-th letter in the alphabet among all of Tanya's subrectangles.  'A' is the 0-th letter, 'B' is the 1-st letter, etc.


DEFINITION
Class:SubrectanglesOfTable
Method:getQuantity
Parameters:vector <string>
Returns:vector<long long>
Method signature:vector<long long> getQuantity(vector <string> table)


CONSTRAINTS
-table will contain between 1 and 50 elements, inclusive.
-Each element of table will contain between 1 and 50 characters, inclusive.
-Each element of table will contain the same number of characters.
-Each element of table will contain only uppercase letters ('A'-'Z').


EXAMPLES

0)
{"OK"}

Returns: {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

The 30 Tanya's rectangles are listed above. There is a total of 40 Ks and 40 Os in these rectangles.

1)
{"GOOD", "LUCK"}

Returns: {0, 0, 320, 280, 0, 0, 280, 0, 0, 0, 280, 280, 0, 0, 640, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0 }

The four copies form the following table:
GOODGOOD
LUCKLUCK
GOODGOOD
LUCKLUCK

Tanya lists 360 rectangles that contain a total of 320 Cs, 280 Ds, 280 Gs, 280 Ks, 280 Ls, 640 Os, and 320 Us.

2)
{"TANYA",
 "HAPPY",
 "BIRTH",
 "DAYYY"}

Returns: {5168, 1280, 0, 1120, 0, 0, 0, 2560, 1472, 0, 0, 0, 0, 1344, 0, 3008, 0, 1536, 0, 2592, 0, 0, 0, 0, 6320, 0 }



*/
// END CUT HERE
#line 83 "SubrectanglesOfTable.cpp"

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

#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



vector<ll> foo(vector< vector< vector<ll> > >& acc, int W, int H, int x0, int x1) {
	vector<ll> ans(26);
	REP(y0, H) for(int y1=y0;y1<H;y1++) {
		REP(i, 26) ans[i] += acc[y1][x1][i];
		if(0<x0) REP(i, 26) ans[i]-=acc[y1][x0-1][i];
		if(0<y0) REP(i, 26) ans[i]-=acc[y0-1][x1][i];
		if(0<x0&&0<y0) REP(i, 26) ans[i]+=acc[y0-1][x0-1][i];
		//printf("%d %d %d %d  ", x0, y0, x1, y1);
		cout<<"foo "<<ans<<endl;
	}
	return ans;
}

class SubrectanglesOfTable {
	public:
	vector<long long> getQuantity(vector <string> tb) {
		int W=tb[0].size()*2, H=tb.size()*2;
		vector<ll> ans(26);
		//vector< vector< vector<ll> > > acc(H, vector< vector<ll> >(W, vector<ll>(26)));
		//REP(y, H) REP(x, W) {
		//	acc[y][x][tb[y%Ho][x%Wo]-'A']++;
		//	if(0<x) REP(i, 26) acc[y][x][i]+=acc[y][x-1][i];
		//	if(0<y) REP(i, 26) acc[y][x][i]+=acc[y-1][x][i];
		//	if(0<x&&0<y) REP(i, 26) acc[y][x][i]-=acc[y-1][x-1][i];
		//}
		//vector< vector< vector<ll> > > acc0(H+1, vector< vector<ll> >(W+1, vector<ll>(26)));
		//REP(y, H) REP(x, W) {
		//	acc0[y+1][x+1][tb[y%Ho][x%Wo]-'A']++;
		//	REP(i, 26) acc0[y+1][x+1][i]+=acc0[y+1][x-1+1][i] + acc0[y-1+1][x+1][i] - acc0[y-1+1][x-1+1][i];
		//}
		//int ok=1;
		//REP(y, H) REP(x, W) ok &= acc[y][x]==acc0[y+1][x+1];
		//if(ok) cout<<"YES"<<endl;
		
		REP(y,H)REP(x,W)ans[tb[y%(H/2)][x%(W/2)]-'A']+=(y+1)*(x+1)*(W-x)*(H-y);
		
		//VI k(H);
		//REP(y0, H) for(int y1=y0;y1<H;y1++) REP(i, H) if(y0<=i && i<=y1) k[i]++;
		//cout<<"k "<<k<<endl;
		//
		//int x0=0, x1=0;
		//REP(y, H) {
		//	vector<ll> line(26);
		//	REP(x0, W) for(int x1=x0;x1<W;x1++) {
		//		for(int x=x0;x<=x1;x++) {
		//			line[tb[y%Ho][x%Wo]-'A']++;
		//		}
		//	}
		//	REP(i, 26) ans[i] += line[i]*k[y];
		//	//printf("%d %d %d %d  ", x0, y0, x1, y1);
		//	//cout<<"line "<<line<<endl;
		//	//cout<<ans<<endl;
		//}
		//cout<<"mine "<<ans<<endl;
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"OK"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getQuantity(Arg0)); }
	void test_case_1() { string Arr0[] = {"GOOD", "LUCK"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0, 0, 320, 280, 0, 0, 280, 0, 0, 0, 280, 280, 0, 0, 640, 0, 0, 0, 0, 0, 320, 0, 0, 0, 0, 0 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getQuantity(Arg0)); }
	void test_case_2() { string Arr0[] = {
 "TANYA",
 "HAPPY",
 "BIRTH",
 "DAYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {5168, 1280, 0, 1120, 0, 0, 0, 2560, 1472, 0, 0, 0, 0, 1344, 0, 3008, 0, 1536, 0, 2592, 0, 0, 0, 0, 6320, 0 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getQuantity(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	SubrectanglesOfTable ___test;

	___test.run_test(-1);
	//___test.test_case_2();

}

// END CUT HERE
