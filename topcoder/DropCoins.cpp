// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There is a rectangle divided into 1x1 cells. Each cell is either empty or it contains a single coin. 

You can apply the following operation repeatedly.

First, choose one of the directions: up, down, left, or right. 
Then, move all coins in the chosen direction by exactly 1 cell. If this would cause a coin to move out of the rectangle, the coin drops out from the rectangle and disappears. 

Your objective in this problem is to apply the operations so that the number of coins remaining on the rectangle becomes exactly K.

You are given the int K and a vector <string> board that describes the initial state of the rectangle. More precisely, character j of element i of board is 'o' if i-th row of j-th column of the rectangle contains a coin, and it is '.' otherwise.

Return the minimum number of operations you have to perform. If the objective is impossible, return -1.

DEFINITION
Class:DropCoins
Method:getMinimum
Parameters:vector <string>, int
Returns:int
Method signature:int getMinimum(vector <string> board, int K)


CONSTRAINTS
-board will contain between 1 and 30 elements, inclusive.
-Each element of board will contain between 1 and 30 characters, inclusive.
-All elements of board will contain the same number of characters.
-Each character in each element of board will be either '.' or 'o'.
-K will be between 1 and 900, inclusive.


EXAMPLES

0)
{".o.."
,"oooo"
,"..o."}

3

Returns: 2

One of the optimal solutions is to move coins to the right twice.

1)
{".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}

12

Returns: 3

One of the optimal solutions:

move coins up (1 coin drops, 13 remain) 
move coins down 
move coins down again (1 coin drops, 12 remain) 


2)
{"...."
,".oo."
,".oo."
,"...."}

3

Returns: -1

It is impossible to make the number of remaining coins exactly 3.

3)
{"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}

12

Returns: 4



4)
{"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}

58

Returns: 6



*/
// END CUT HERE
#line 113 "DropCoins.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <numeric>
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



class DropCoins {
	public:
	int getMinimum(vector <string> board, int K) {
		int W = board[0].size();
		int H = board.size();
		//cout<<W<<" "<<H<<endl;
		VVI v(H);
		REP(i, H) REP(j, W) v[i].push_back(0);
		REP(y, H) REP(x, W) {
			REP(yy, y+1) REP(xx, x+1) {
				v[y][x] += board[yy][xx]=='o' ? 1:0;
			}
		}
		VI ans;
		for(int sy=H;sy>0;sy--) {
			for(int sx=W;sx>0;sx--) {
				REP(by, H-sy+1) {
					REP(bx, W-sx+1) {
						int ax=bx-1;
						int ay=by-1;
						int ex=bx+sx-1;
						int ey=by+sy-1;
						int co=v[ey][ex];
						if(ay>=0) co-=v[ay][ex];
						if(ax>=0) co-=v[ey][ax];
						if(ax>=0 && ay>=0) co+=v[ay][ax];
						//cout<<" try "<<co<<" "<<bx<<" "<<by<<" "<<ex<<" "<<ey<<" area "<<sx<<" "<<sy<<endl;
						if(co==K) {
							int lans = 2*(bx+W-ex-1)-max(bx, W-ex-1) + 2*(by + H-ey-1) - max(by, H-ey-1);
							//cout<<"found "<<lans<<" "<<bx<<" "<<by<<" "<<ex<<" "<<ey<<" area "<<sx<<" "<<sy<<endl;
							ans.push_back(lans);
						}
					}
				}
			}
		}
		if(ans.size()==0) return -1;
		sort(ALL(ans));
		return ans[0];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".o.."
,"oooo"
,"..o."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(0, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {
 ".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 3; verify_case(1, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"...."
,".oo."
,".oo."
,"...."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = -1; verify_case(2, Arg2, getMinimum(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {
 "......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; int Arg2 = 4; verify_case(3, Arg2, getMinimum(Arg0, Arg1)); }

//	void test_case_4() { string Arr0[] = {
// "................."
//,".ooooooo...oooo.."
//,".ooooooo..oooooo."
//,".oo.......oo..oo."
//,".oo.......oo..oo."
//,".ooooo.....oooo.."
//,".ooooooo...oooo.."
//,".....ooo..oo..oo."
//,"......oo..oo..oo."
//,".ooooooo..oooooo."
//,".oooooo....oooo.."
//,"................."}
//; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; int Arg2 = 6; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }

//	void test_case_4() { string Arr0[] = {
// "oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//,"oooooooooooooooooooooooooooooo"
//}
//; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 58; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }

	void test_case_4() { string Arr0[] = {
 "o.o.o.o"
,".o.o.o."
}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 2; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }

//	void test_case_4() { string Arr0[] = {
// ".............................."
//,".o............................"
//,"..o..........................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,".............................."
//,"............................o."
//,".............................."
//}
//; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = -1; verify_case(4, Arg2, getMinimum(Arg0, Arg1)); }


// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	DropCoins ___test;

	___test.run_test(-1);

}

// END CUT HERE
