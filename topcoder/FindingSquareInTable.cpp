// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are given a vector <string> table representing a rectangular grid where each cell contains a digit.  The j-th character of the i-th element of table is the digit in the cell at row i, column j of the grid.

Consider a sequence of distinct cells in this table where the row numbers of the cells (in the order they appear in the sequence) form an arithmetic progression, and the column numbers also form an arithmetic progression.  Concatenate the digits in the cells of this sequence to obtain a number.

Among all numbers that can be obtained in this manner, find and return the largest perfect square (a square of an integer).  If there are no perfect squares, return -1 instead.

DEFINITION
Class:FindingSquareInTable
Method:findMaximalSquare
Parameters:vector <string>
Returns:int
Method signature:int findMaximalSquare(vector <string> table)


NOTES
-An arithmetic progression is a sequence of numbers where the difference between each number and the previous number is constant.


CONSTRAINTS
-table will contain between 1 and 9 elements, inclusive.
-Each element of table will contain between 1 and 9 characters, inclusive.
-All elements of table will be of the same length.
-Each element of table will contain only digits ('0'-'9').


EXAMPLES

0)
{"123",
 "456"}

Returns: 64

Several three-digit numbers can be obtained: 123, 321, 456, and 654, but none of them is a perfect square.
The largest obtainable perfect square is 64.

1)
{"00000",
 "00000",
 "00200",
 "00000",
 "00000"}

Returns: 0

0 is a perfect square. It is the largest one that can be obtained in this table.

2)
{"3791178",
 "1283252",
 "4103617",
 "8233494",
 "8725572",
 "2937261"}

Returns: 320356

Take the i-th digit of each row i, and you'll get 320356 = 566 Å~ 566.

3)
{"135791357",
 "357913579",
 "579135791",
 "791357913",
 "913579135"}


Returns: 9

It is known that a perfect square can't end with two odd digits. Therefore, the largest perfect square that contains only odd digits is 9.

4)
{"553333733",
 "775337775",
 "777537775",
 "777357333",
 "755553557",
 "355533335",
 "373773573",
 "337373777",
 "775557777"}

Returns: -1

There exists no perfect square that contains only digits 3, 5, and 7.

5)
{"257240281",
 "197510846",
 "014345401",
 "035562575",
 "974935632",
 "865865933",
 "684684987",
 "768934659",
 "287493867"}

Returns: 95481

The sequence of digits that forms 95481 is shown in bold:
257240281
197510846
014345401
035562575
974935632
865865933
684684987
768934659
287493867

*/
// END CUT HERE
#line 117 "FindingSquareInTable.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class FindingSquareInTable {
	public:
	int findMaximalSquare(vector <string> tb) {
		int W=tb[0].size();
		int H=tb.size();
		VI vs;
		REP(bx, W)
		REP(by, H)
		for(int sx=-W;sx<=W;sx++)
		for(int sy=-H;sy<=H;sy++)
		for(int ct=1;ct<=max(W,H);ct++) {
			if(sx==0&&sy==0) continue;
			int wx=bx;
			int wy=by;
			int v=0;
			int count=0;
			while(0<=wx && wx<W && 0<=wy && wy<H) {
				v=v*10+(tb[wy][wx]-'0');
				wx+=sx;
				wy+=sy;
				if(count++==ct) break;
			}
			vs.push_back(v);
		}
		sort(ALL(vs));
		reverse(ALL(vs));
		//cout<<vs<<endl;
		FOR(v, vs) {
			if((int)sqrt(*v)*(int)sqrt(*v)==*v) return *v;
		}
		return -1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	//void test_case_0() { string Arr0[] = {"123", "456"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 64; verify_case(0, Arg1, findMaximalSquare(Arg0)); }
	void test_case_0() { string Arr0[] = {"700000009"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9000000; verify_case(0, Arg1, findMaximalSquare(Arg0)); }
	void test_case_1() { string Arr0[] = {"00000",
 "00000",
 "00200",
 "00000",
 "00000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, findMaximalSquare(Arg0)); }
	void test_case_2() { string Arr0[] = {"3791178",
 "1283252",
 "4103617",
 "8233494",
 "8725572",
 "2937261"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 320356; verify_case(2, Arg1, findMaximalSquare(Arg0)); }
	void test_case_3() { string Arr0[] = {"135791357",
 "357913579",
 "579135791",
 "791357913",
 "913579135"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, findMaximalSquare(Arg0)); }
	void test_case_4() { string Arr0[] = {"553333733",
 "775337775",
 "777537775",
 "777357333",
 "755553557",
 "355533335",
 "373773573",
 "337373777",
 "775557777"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(4, Arg1, findMaximalSquare(Arg0)); }
	void test_case_5() { string Arr0[] = {"257240281",
 "197510846",
 "014345401",
 "035562575",
 "974935632",
 "865865933",
 "684684987",
 "768934659",
 "287493867"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 95481; verify_case(5, Arg1, findMaximalSquare(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	FindingSquareInTable ___test;

	___test.run_test(-1);

}

// END CUT HERE
