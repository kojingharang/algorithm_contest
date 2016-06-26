// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

We had a rectangular grid that consisted of W x H square cells.
We placed a robot on one of the cells.
The robot then followed the rules given below.


Initially, the robot is facing east.
The robot moves in steps. In each step it moves to the adjacent cell in the direction it currently faces.
The robot may not leave the grid.
The robot may not visit the same cell twice. (This also means that it may not reenter the starting cell.)
If a step forward does not cause the robot to break the above rules, the robot takes the step.
Otherwise, the robot rotates 90 degrees to the left (counter-clockwise) and checks whether a step forward still breaks the above rules.
  If not, the robot takes the step and continues executing this program (still rotated in the new direction).
If the rotation left did not help, the robot terminates the execution of this program.
We can also terminate the execution of the program manually, at any moment.

For example, the following seven images show a series of moves made by the robot in a 12 x 11 board:


We forgot the dimensions of the grid and the original (x,y) coordinates of the cell on which the robot was originally placed, but we do remember its movement. You are given a vector <int> moves. This sequence of positive integers shall be interpreted as follows:
The robot performed moves[0] steps eastwards, turned left, performed moves[1] steps northwards, turned left, and so on.
After performing the last sequence of steps, the robot stopped. (Either it detected that it should terminate, or we stopped it manually.) We are not sure if the sequence of moves is valid. If the sequence of moves is impossible, return -1. Else, return the minimum area of a grid in which the sequence of moves is possible.
(I.e., the return value is the smallest possible value of the product of W and H.).

DEFINITION
Class:RotatingBot
Method:minArea
Parameters:vector <int>
Returns:int
Method signature:int minArea(vector <int> moves)


CONSTRAINTS
-moves will contain between 1 and 50 elements, inclusive.
-Each element of moves will be between 1 and 50, inclusive.


EXAMPLES

0)
{15}

Returns: 16

The smallest valid board is a 16x1 board, with the robot starting on the west end of the board.

1)
{3,10}

Returns: 44

The smallest solution is to place the robot into the southwest corner of a 4 x 11 board.

2)
{1,1,1,1}

Returns: -1

This sequence of moves is not possible because the robot would return to its initial location which is forbidden.

3)
{9,5,11,10,11,4,10}

Returns: 132

These moves match the image from the problem statement.

4)
{12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15}

Returns: 420

5)
{8,6,6,1}

Returns: -1



6)
{8,6,6}

Returns: 63



7)
{5,4,5,3,3}

Returns: 30



*/
// END CUT HERE
#line 101 "RotatingBot.cpp"

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



class RotatingBot {
	public:
	int minArea(vector <int> M) {
		ll N=M.size();
		if(N==1) return M[0]+1;
		if(N==2) return (M[0]+1)*(M[1]+1);
		if(N==3) return max(M[0]+1, M[2]+1)*(M[1]+1);
		ll W=max(M[0]+1, M[2]+1);
		ll H=max(M[1]+1, M[3]+1);
		//cout<<MP(W, H)<<" "<<W*H<<endl;
		ll sX = W-M[0]-1;
		ll sY = M[1];
		VVI w(H+2, VI(W+2));
		REP(x, W+2) w[0][x]=w[H+1][x]=1;
		REP(y, H+2) w[y][0]=w[y][W+1]=1;
		w[sY+1][sX+1]=1;
		int dx[4]={1,0,-1,0};
		int dy[4]={0,-1,0,1};
		REP(i, N) {
			int dir=i%4;
			REP(j, M[i]) {
				sX += dx[dir];
				sY += dy[dir];
				if(w[sY+1][sX+1]) {
					//cout<<i<<" "<<j<<endl;
					//cout<<w<<endl;
					return -1;
				}
				w[sY+1][sX+1]=1;
			}
			if(i!=N-1 && w[sY+dy[dir]+1][sX+dx[dir]+1]==0) {
				//cout<<i<<" end "<<M[i]<<endl;
				//cout<<w<<endl;
				return -1;
			}
			//cout<<"result "<<MP(sX, sY)<<endl;
		}
		return W*H;
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
#define END	 verify_case(_, RotatingBot().minArea(moves));}
int main(){

CASE(0)
	int moves_[] = {15};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int _ = 16; 
END
CASE(1)
	int moves_[] = {3,10};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int _ = 44; 
END
CASE(2)
	int moves_[] = {1,1,1,1};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int _ = -1; 
END
CASE(3)
	int moves_[] = {9,5,11,10,11,4,10};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int _ = 132; 
END
CASE(4)
	int moves_[] = {12,1,27,14,27,12,26,11,25,10,24,9,23,8,22,7,21,6,20,5,19,4,18,3,17,2,16,1,15};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int _ = 420; 
END
CASE(5)
	int moves_[] = {8,6,6,1};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int _ = -1; 
END
CASE(6)
	int moves_[] = {8,6,6};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int _ = 63; 
END
CASE(7)
	int moves_[] = {5,4,5,3,3};
	  vector <int> moves(moves_, moves_+sizeof(moves_)/sizeof(*moves_)); 
	int _ = 30; 
END

}
// END CUT HERE
/*

50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1

*/
