// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// This problem statement contains images. It may not display properly outside the applet.



Once upon a time, Little Wojtek had drawn a number of points with integer coordinates onto a sheet of paper.
Then he made zero or more steps.
Each step looked as follows:
Let's call all the points on Wojtek's paper old points.
For every four old points that formed the vertices of a 1x1 square, Wojtek would draw a point in the middle of that square.
Once he had drawn all such new points, he took an eraser and erased all the old points.



An example is shown in the picture below.
On the left is Wojtek's original paper.
In the middle is the same paper with the new points filled in.
(For clarity, the old points are black and the new ones are red.)
On the right is the paper after the old points were erased.



?
?




He has been playing for a while when he was called downstairs to dinner.
He looked at the paper with a surprised face and wondered how many steps he had made.



You are given two vector <int>s x, y of some equal length n. They describe all of the points that were drawn by Wojtek in the last step of his play. More precisely, you may assume that there are real numbers (not necessarily integers) dy and dx such that the following holds:

For each i between 0 and n-1, there is a point at coordinates (dx+x[i], dy+y[i]).
There are no other points anywhere on the paper, only those that follow from the previous statement.




Return the maximum number of steps Wojtek could have made.
If there is no maximum (that is, if the number of steps can be arbitrarily large), return -1 instead.


DEFINITION
Class:DrawingPointsDivOne
Method:maxSteps
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int maxSteps(vector <int> x, vector <int> y)


NOTES
-Note that the points drawn by Wojtek in the last step of his play could have non-integer coordinates.
-The paper used by Wojtek could have been arbitrarily large. In other words, ignore the paper size, it does not limit the number of steps in any way.


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-x and y will contain the same number of elements.
-Each element of x will be between -70 and 70, inclusive.
-Each element of y will be between -70 and 70, inclusive.
-No two points described by x and y will be the same.


EXAMPLES

0)
{0, 3}
{0, 0}

Returns: 1

An example scenario:


Wojtek draws the initial points at locations (100, 100), (100, 101), (101, 100), (101, 101), (103, 100), (104, 100), (103, 101), (104, 101), (315, 714).
In the first and only step, Wojtek draws points at locations (100.5, 100.5) and (103.5, 100.5). These locations correspond to x and y in this test case.


1)
{0,2}
{0,0}

Returns: 0



2)
{-70}
{3}

Returns: -1



3)
{-41,-40,1,-11,-32,-7,24,-11,49,-15,-22,20,-8,54,54,69,16,-30,36,-6,-30,40,64,20,-66,
 -37,-33,-18,-35,36,9,61,-43,45,5,60,-8,-58,65,-66,41,12,34,-11,-57,-38,46,63,-55,3}
{5,-24,-2,-4,23,14,1,70,-26,45,15,48,32,-41,54,-47,-67,-46,-9,-53,54,28,-61,11,53,68,
 -33,62,37,-8,-17,-17,48,19,-49,56,-41,16,17,-50,28,59,10,50,23,-16,56,31,-70,-44}

Returns: 9



*/
// END CUT HERE
#line 113 "DrawingPointsDivOne.cpp"

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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << ""; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool Union(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool Find(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

class DrawingPointsDivOne {
	public:
	int maxSteps(vector <int> x, vector <int> y) {
		int N=x.size();
		UnionFind uf(N);
		REP(i, N) RANGE(j, i, N) {
			if(abs(x[i]-x[j])<=1 && abs(y[i]-y[j])<=1) {
				uf.Union(i, j);
			}
		}
		//REP(i, N) {
		//	cout<<uf.root(i)<<endl;
		//}
		map<int, int> hi;
		REP(i, N) hi[uf.root(i)]++;
		if(hi.size()==1) return -1;
		
		int L=340;
		VVI w(L, VI(L, 0));
		REP(i, N) w[y[i]+70][x[i]+70] = 1;
		//cout<<w<<endl;
		VVI init = w;
		
		int ans = 0;
		while(1) {
			cout<<"ANS: "<<ans<<endl;
			//cout<<w<<endl;
			VVI wn = w;
			REP(y, L) REP(x, L) {
				if(w[y][x]) {
					wn[y][x]=1;
					if(x+1<L) wn[y][x+1]=1;
					if(y+1<L) wn[y+1][x]=1;
					if(x+1<L && y+1<L) wn[y+1][x+1]=1;
				}
			}
			
			{
				VVI aa = wn;
				int ok=0;
				while(1) {
					if(aa==init) {ok=1;break;}
					VVI an(L, VI(L, 0));
					REP(y, L-1) REP(x, L-1) {
						if(aa[y][x] && aa[y][x+1] && aa[y+1][x] && aa[y+1][x+1]) an[y][x]=1;
					}
					int co=0;
					REP(y, L) REP(x, L) co+=an[y][x];
					if(co==0) break;
					aa=an;
				}
				//cout<<"ANS: "<<ans<<" -> "<<ok<<endl;
				if(!ok) break;
			}
			ans++;
			w = wn;
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
#define END	 verify_case(_, DrawingPointsDivOne().maxSteps(x, y));}
int main(){

CASE(0)
	int x_[] = {-70, 70};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-70, 70};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 29; 
END
CASE(3)
	int x_[] = {-41,-40,1,-11,-32,-7,24,-11,49,-15,-22,20,-8,54,54,69,16,-30,36,-6,-30,40,64,20,-66,
 -37,-33,-18,-35,36,9,61,-43,45,5,60,-8,-58,65,-66,41,12,34,-11,-57,-38,46,63,-55,3};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {5,-24,-2,-4,23,14,1,70,-26,45,15,48,32,-41,54,-47,-67,-46,-9,-53,54,28,-61,11,53,68,
 -33,62,37,-8,-17,-17,48,19,-49,56,-41,16,17,-50,28,59,10,50,23,-16,56,31,-70,-44};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 9; 
END
//return 0;
CASE(0)
	int x_[] = {0, 3};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0, 0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 1; 
END
//return 0;
CASE(1)
	int x_[] = {0,2};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = 0; 
END
CASE(2)
	int x_[] = {-70};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {3};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	int _ = -1; 
END

}
// END CUT HERE
