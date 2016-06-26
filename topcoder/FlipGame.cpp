// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Eel Takahashikun is playing a simple game on a rectangular board.


The rectangular board is divided into H x W unit squares. Each unit square contains a 0 or a 1. In each operation, Takahashikun chooses a shortest path along edges of unit squares from the upper-left corner to the lower-right corner, and flips the numbers in all unit squares that are below the chosen path (i.e., changes all 0s into 1s and vice versa).


For example, the following picture shows a valid operation. The squares below the chosen path are highlighted in green.





The operation in the following picture is invalid because the path is not shortest.





You are given the initial state of the board in vector <string> board. The j-th character of the i-th element is the number written in the unit square at row i, column j. Rows are numbered from top to bottom, and columns are numbered from left to right. Return the minimal number of iterations required to change all numbers to 0s.


DEFINITION
Class:FlipGame
Method:minOperations
Parameters:vector <string>
Returns:int
Method signature:int minOperations(vector <string> board)


NOTES
-It is always possible to change all numbers to 0s by a finite number of operations.


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain between 1 and 50 characters, inclusive.
-Each element of board will contain the same number of characters.
-Each character in board will be '0' or '1'.


EXAMPLES

0)
{"1000",
 "1110",
 "1111"}

Returns: 1

Takahashikun can flip all 1s in one operation.


1)
{"1111",
 "1111",
 "1111"}

Returns: 1



2)
{"00",
 "00",
 "00"}

Returns: 0



3)
{"00000000",
 "00100000",
 "01000000",
 "00001000",
 "00000000"}

Returns: 4



4)
{"000000000000001100000000000000",
 "000000000000011110000000000000",
 "000000000000111111000000000000",
 "000000000001111111100000000000",
 "000000000011111111110000000000",
 "000000000111111111111000000000",
 "000000001100111111001100000000",
 "000000011000011110000110000000",
 "000000111100111111001111000000",
 "000001111111111111111111100000",
 "000011111111111111111111110000",
 "000111111111000000111111111000",
 "001111111111100001111111111100",
 "011111111111110011111111111110",
 "111111111111111111111111111111"}

Returns: 29



*/
// END CUT HERE
#line 109 "FlipGame.cpp"

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
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class FlipGame {
	public:
	int minOperations(vector <string> B) {
		int H=B.size();
		int W=B[0].size();
		int ans=0;
		while(1) {
			int col=0;
			int found1=0;
			REP(y, H) {
				for(int x=W-1;x>=col;x--) {
					if(B[y][x]=='1') {col=x+1;found1=1;break;}
				}
				//cout<<y<<" "<<col<<endl;
				for(int x=0;x<col;x++) B[y][x]=B[y][x]=='1'?'0':'1';
			}
			if(!found1) return ans;
			ans++;
		}
		return -1;
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
#define END	 verify_case(_, FlipGame().minOperations(board));}
int main(){

CASE(0)
	string board_[] = {"1000",
 "1110",
 "1111"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 1; 
END
CASE(1)
	string board_[] = {"1111",
 "1111",
 "1111"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 1; 
END
CASE(2)
	string board_[] = {"00",
 "00",
 "00"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 0; 
END
CASE(2)
	string board_[] = {"1",
};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 0; 
END
CASE(3)
	string board_[] = {"00000000",
 "00100000",
 "01000000",
 "00001000",
 "00000000"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 4; 
END
CASE(4)
	string board_[] = {"000000000000001100000000000000",
 "000000000000011110000000000000",
 "000000000000111111000000000000",
 "000000000001111111100000000000",
 "000000000011111111110000000000",
 "000000000111111111111000000000",
 "000000001100111111001100000000",
 "000000011000011110000110000000",
 "000000111100111111001111000000",
 "000001111111111111111111100000",
 "000011111111111111111111110000",
 "000111111111000000111111111000",
 "001111111111100001111111111100",
 "011111111111110011111111111110",
 "111111111111111111111111111111"};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 29; 
END
CASE(5)
	string board_[] = {
 "01010101010101010101010101010101010101010101010101",
 "00110011001100110011001100110011001100110011001100",
 "00110011001100110011001100110011001100110011001100",
 "00110011001100110011001100110011001100110011001100",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "00110011001100110011001100110011001100110011001100",
 "00110011001100110011001100110011001100110011001100",
 "00110011001100110011001100110011001100110011001100",
 "00110011001100110011001100110011001100110011001100",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "11111111111111111111111111111111111111111111111111",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",
 "01010101010101010101010101010101010101010101010101",

};
	  vector <string> board(board_, board_+sizeof(board_)/sizeof(*board_)); 
	int _ = 1; 
END

}
// END CUT HERE
