// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// F is a function that is defined on all real numbers from the closed interval [1,N].
You are given a vector <int> Y with N elements.
For each i (1 <= i <= N) we have F(i) = Y[i-1].
Additionally, you know that F is piecewise linear: for each i, on the interval [i,i+1] F is a linear function.
The function F is uniquely determined by this information.
For example, if F(4)=1 and F(5)=6 then we must have F(4.7)=4.5.

As another example, this is the plot of the function F for Y = {1, 4, -1, 2}.



Given a real number y, we can count the number of solutions to the equation F(x)=y.
For example, for the function plotted above there are 0 solutions for y=7, there is 1 solution for y=4, and there are 3 solutions for y=1.1.
We are looking for the largest number of solutions such an equation can have.
For the function plotted above the answer would be 3: there is no y such that F(x)=y has more than 3 solutions.

If there is an y such that the equation F(x)=y has infinitely many solutions, return -1.
Otherwise, return the maximum possible number of solutions such an equation may have.


DEFINITION
Class:PiecewiseLinearFunction
Method:maximumSolutions
Parameters:vector <int>
Returns:int
Method signature:int maximumSolutions(vector <int> Y)


CONSTRAINTS
-Y will contain between 2 and 50 elements, inclusive.
-Each element of Y will be between -1,000,000,000 and 1,000,000,000, inclusive.


EXAMPLES

0)
{3, 2}

Returns: 1

The graph of this function is a line segment between (1, 3) and (2, 2). For any y such that 2 ? y ? 3 the equation F(x)=y has 1 solution, and for any other y it has 0 solutions.

1)
{4, 4}

Returns: -1

The function's plot is a horizontal line segment between points (1, 4) and (2, 4). For y=4, F(x)=y has infinitely many solutions.

2)
{1, 4, -1, 2}

Returns: 3

This is the example from the problem statement. Three solutions are obtained for any value of y between 1 and 2, inclusive:



3)
{2, 1, 2, 1, 3, 2, 3, 2}

Returns: 5



4)
{125612666, -991004227, 0, 6, 88023, -1000000000, 1000000000, -1000000000, 1000000000}

Returns: 6



*/
// END CUT HERE
#line 79 "PiecewiseLinearFunction.cpp"

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



class PiecewiseLinearFunction {
	public:
	int maximumSolutions(vector <int> Y) {
		REP(i, Y.size()) Y[i]*=2;
		int offset[] = {-1, 0, 1};
		ll ans = 0;
		REP(i, Y.size()) {
			REP(oi, 3) {
				ll y = Y[i]+offset[oi];
				ll cnt = 0;
				REP(i, Y.size()) if(Y[i]==y) cnt++;
				REP(i, Y.size()-1) {
					if(Y[i]==Y[i+1]) return -1;
					if(min(Y[i], Y[i+1])<y && y<max(Y[i], Y[i+1])) cnt++;
				}
				ans = max(ans, cnt);
			}
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
#define END	 verify_case(_, PiecewiseLinearFunction().maximumSolutions(Y));}
int main(){

CASE(0)
	int Y_[] = {3, 2};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int _ = 1; 
END
CASE(1)
	int Y_[] = {4, 4};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int _ = -1; 
END
CASE(2)
	int Y_[] = {1, 4, -1, 2};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int _ = 3; 
END
CASE(3)
	int Y_[] = {2, 1, 2, 1, 3, 2, 3, 2};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int _ = 5; 
END
CASE(4)
	int Y_[] = {125612666, -991004227, 0, 6, 88023, -1000000000, 1000000000, -1000000000, 1000000000};
	  vector <int> Y(Y_, Y_+sizeof(Y_)/sizeof(*Y_)); 
	int _ = 6; 
END

}
// END CUT HERE
