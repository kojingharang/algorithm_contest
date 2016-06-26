// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are given ints n and m: the dimensions of a matrix.
A matrix M with n rows and m columns is called a mountain if it satisfies the following conditions:

All elements of M are positive integers.
There are integers a and b with the following properties:
  
  0 <= a <= n-1 and 0 <= b <= m-1.
  For each row i, M[i][0] < M[i][1] < ... < M[i][b-1] < M[i][b] > M[i][b+1] > ... > M[i][m-1].
  For each column j, M[0][j] < M[1][j] < ... < M[a-1][j] < M[a][j] > M[a+1][j] > ... > M[n-1][j].
  



In addition to n and m, you are given some elements of M.
More precisely, you are given the vector <int>s rowIndex, columnIndex and element.
For each valid k, M[rowIndex[k]][columnIndex[k]] has to be element[k].

Your task is to fill in the missing values so that M becomes a mountain.
Find and return the smallest possible sum of all elements in a mountain M that matches the given constraints.
If there is no mountain that matches the given constraints, return -1 instead.

DEFINITION
Class:TheMountain
Method:minSum
Parameters:int, int, vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int minSum(int n, int m, vector <int> rowIndex, vector <int> columnIndex, vector <int> element)


CONSTRAINTS
-n and m will each be between 1 and 200, inclusive.
-rowIndex will contain between 1 and min(n*m, 50) elements, inclusive.
-columnIndex and element will contain the same number of elements as rowIndex.
-Each element of rowIndex will be between 0 and n-1, inclusive.
-Each element of columnIndex will be between 0 and m-1, inclusive.
-Each element of element will be between 1 and 1,000, inclusive.
-No two indices represented by rowIndex and columnIndex will be the same.


EXAMPLES

0)
2
3
{0, 0, 0, 1, 1, 1}
{0, 1, 2, 0, 1, 2}
{4, 6, 9, 1, 3, 6}

Returns: 29

We are already given all elements of this matrix.
It looks as follows:

[4 6 9]
[1 3 6]

We can easily verify that this is a mountain for a=0 and b=2.
The sum of all elements is 4+6+9+1+3+6=29.

1)
2
3
{1, 0, 1}
{2, 2, 0}
{5, 7, 6}

Returns: 40

The matrix looks as follows.

[? ? 7]
[6 ? 5]

The optimal solution is as follows. The sum is 7+8+7+6+7+5=40.

[7 8 7]
[6 7 5]


2)
3
3
{0, 0, 2, 2}
{0, 2, 2, 0}
{1, 1, 1, 1}

Returns: 15

The matrix looks as follows:

[1 ? 1]
[? ? ?]
[1 ? 1]

The optimal solution is as follows.

[1 2 1]
[2 3 2]
[1 2 1]


3)
2
2
{0, 0, 1, 1}
{0, 1, 1, 0}
{5, 8, 5, 8}

Returns: -1

The given matrix is not a mountain.

[5 8]
[8 5]


4)
1
3
{0}
{1}
{1}

Returns: -1

This matrix looks as follows:

[? 1 ?]

It is not possible to make a mountain out of it, because in a mountain all elements have to be positive.
(Note that 0 is not positive.)

5)
123
45
{2, 3, 5, 7, 11}
{13, 17, 19, 23, 29}
{100, 200, 300, 400, 500}

Returns: 367047



6)
200
200
{5}
{8}
{666}

Returns: 5737554



7)
10
10
{0, 8, 7}
{3, 1, 9}
{5, 4, 7}

Returns: 593



*/
// END CUT HERE
#line 172 "TheMountain.cpp"

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
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<ll, ll> 
#define VVI vector<vector<int> >
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

#define INF (1LL<<30)

void verify(VVI& w, int W, int H, int tx, int ty) {
	int sum=0;
	int v0=0,v1=0,v2=0,v3=0;
	int wx=0,wy=0;
	int wxy=0;
	cout<<"Verify: "<<tx<<" "<<ty<<endl;
	if(tx==9 && ty==6) {
		cout<<w<<endl;
	}
	REP(y, H) REP(x, W) {
		if(0<x && x<=tx) assert(w[y][x-1]<w[y][x]);
		if(tx<x && x<W) assert(w[y][x-1]>w[y][x]);
		if(0<y && y<=ty) assert(w[y-1][x]<w[y][x]);
		if(ty<y && y<H) assert(w[y-1][x]>w[y][x]);
		sum += w[y][x];
		if(x<tx && y<ty) v0+=w[y][x];
		if(x>tx && y<ty) v1+=w[y][x];
		if(x<tx && y>ty) v2+=w[y][x];
		if(x>tx && y>ty) v3+=w[y][x];
		if(x==tx) wy+=w[y][x];
		if(y==ty) wx+=w[y][x];
		if(x==tx && y==ty) wxy+=w[y][x];
	}
	assert(sum==wx+wy-wxy+v0+v1+v2+v3);
	cout<<"Verify OK. sum = "<<sum<<" = "<<wx<<" + "<<wy<<" - "<<wxy<<" + ("<<v0<<" "<<v1<<" "<<v2<<" "<<v3<<")"<<endl;
}

class TheMountain {
	public:
	int minSum(int H, int W, vector <int> IY, vector <int> IX, vector <int> IE) {
		int ans=INF;
		VVI init(H+2, VI(W+2, 0));
		VVI show(H, VI(W, 0));
		VVI w[4];
		REP(i, 4) w[i] = init;
		REP(i, IY.size()) init[IY[i]+1][IX[i]+1] = IE[i];
		//cout<<"init: "<<init<<endl;
		VVI dp[4];
		REP(i, 4) dp[i] = VVI(H+2, VI(W+2, 0));
		int sx[] = {0, W-1, 0, W-1};
		int sy[] = {0, 0, H-1, H-1};
		int dx[] = {1, -1, 1, -1};
		int dy[] = {1, 1, -1, -1};
		REP(dir, 4) {
			int Dx = dx[dir];
			int Dy = dy[dir];
			for(int y=sy[dir]; 0<=y && y<H; y+=Dy) for(int x=sx[dir]; 0<=x && x<W; x+=Dx) {
				w[dir][y +1][x +1] = -1;
				int v = max(init[y+1][x+1], max(w[dir][y +1][x-Dx +1], w[dir][y-Dy +1][x +1])+1);
				if((w[dir][y +1][x-Dx +1]!=-1 && w[dir][y-Dy +1][x +1]!=-1) && (init[y+1][x+1]==0 || init[y+1][x+1] == v)) {
					w[dir][y +1][x +1] = v;
				}
				
				dp[dir][y +1][x +1] = -1;
				int py = dp[dir][y-Dy +1][x +1];
				int px = dp[dir][y +1][x-Dx +1];
				int pxy = dp[dir][y-Dy +1][x-Dx +1];
				if(!(w[dir][y +1][x +1]==-1 || px==-1 || py==-1 || pxy==-1)) {
					dp[dir][y +1][x +1] = w[dir][y +1][x +1] + py + px - pxy;
				}
			}
			//cout<<"w"<<endl;
			//cout<<w<<endl;
		}
		//cout<<"w"<<endl;
		//REP(i, 4) cout<<w[i]<<endl;
		//cout<<"dp"<<endl;
		//REP(i, 4) cout<<dp[i]<<endl;
		//RANGE(ty, 99, 101) RANGE(tx, 8, 9) {
		REP(ty, H) REP(tx, W) {
			VI wx(W), wy(H);
			int ok=1;
			RANGE(x, 0, tx+1) { int a=w[0][ty+1][x+1], b=w[2][ty+1][x+1]; wx[x]=max(wx[x], max(a, b)); if(min(a, b)==-1) ok=0; }
			RANGE(x, tx, W)   { int a=w[1][ty+1][x+1], b=w[3][ty+1][x+1]; wx[x]=max(wx[x], max(a, b)); if(min(a, b)==-1) ok=0; }
			RANGE(y, 0, ty+1) { int a=w[0][y+1][tx+1], b=w[1][y+1][tx+1]; wy[y]=max(wy[y], max(a, b)); if(min(a, b)==-1) ok=0; }
			RANGE(y, ty, H)   { int a=w[2][y+1][tx+1], b=w[3][y+1][tx+1]; wy[y]=max(wy[y], max(a, b)); if(min(a, b)==-1) ok=0; }
			if(!ok) continue;
			
			int wx_sum=0, wy_sum=0;
			REP(x, W) wx_sum += wx[x];
			REP(y, H) wy_sum += wy[y];
			int wxy = wx_sum + wy_sum - min(wx[tx], wy[ty]);
			//REP(i, 4) cout<<"w4 "<<w[i][ty+1][tx+1]<<endl;
			//cout<<"xy  "<<wx[tx]<<" "<<wy[ty]<<endl;
			
			//REP(y, H) REP(x, W) {
			//	if(x<tx && y<ty) show[y][x] = w[0][y+1][x+1];
			//	if(x>tx && y<ty) show[y][x] = w[1][y+1][x+1];
			//	if(x<tx && y>ty) show[y][x] = w[2][y+1][x+1];
			//	if(x>tx && y>ty) show[y][x] = w[3][y+1][x+1];
			//	if(x==tx) show[y][x] = wy[y];
			//	if(y==ty) show[y][x] = wx[x];
			//	if(x==tx && y==ty) show[y][x] = max(wy[y], wx[x]);
			//}
			//
			//verify(show, W, H, tx, ty);
			
			int v0 = dp[0][ty-1 +1][tx-1 +1];
			int v1 = dp[1][ty-1 +1][tx+1 +1];
			int v2 = dp[2][ty+1 +1][tx-1 +1];
			int v3 = dp[3][ty+1 +1][tx+1 +1];
			if(v0==-1 || v1==-1 || v2==-1 || v3==-1) continue;
			int v4 = v0+v1+v2+v3;
			int lans = wxy + v4;
			//cout<<tx<<" "<<ty<<endl;
			//cout<<"wx "<<wx<<endl;
			//cout<<"wy "<<wy<<endl;
			//cout<<" - "<<wx_sum<<" + "<<wy_sum<<" - "<<wx[tx]<<" + ("<<v0<<" "<<v1<<" "<<v2<<" "<<v3<<") = "<<lans<<endl;
			ans = min(ans, lans);
		}
		return ans==INF ? -1 : ans;
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
#define END	 verify_case(_, TheMountain().minSum(n, m, rowIndex, columnIndex, element));}
int main(){

//CASE(6)
//	int n = 200; 
//	int m = 200; 
//	int rowIndex_[] = {5};
//	  vector <int> rowIndex(rowIndex_, rowIndex_+sizeof(rowIndex_)/sizeof(*rowIndex_)); 
//	int columnIndex_[] = {8};
//	  vector <int> columnIndex(columnIndex_, columnIndex_+sizeof(columnIndex_)/sizeof(*columnIndex_)); 
//	int element_[] = {666};
//	  vector <int> element(element_, element_+sizeof(element_)/sizeof(*element_)); 
//	int _ = 5737554; 
//END
//return 0;


CASE(0)
	int n = 2; 
	int m = 3; 
	int rowIndex_[] = {0, 0, 0, 1, 1, 1};
	  vector <int> rowIndex(rowIndex_, rowIndex_+sizeof(rowIndex_)/sizeof(*rowIndex_)); 
	int columnIndex_[] = {0, 1, 2, 0, 1, 2};
	  vector <int> columnIndex(columnIndex_, columnIndex_+sizeof(columnIndex_)/sizeof(*columnIndex_)); 
	int element_[] = {4, 6, 9, 1, 3, 6};
	  vector <int> element(element_, element_+sizeof(element_)/sizeof(*element_)); 
	int _ = 29; 
END
//return 0;
CASE(1)
	int n = 2; 
	int m = 3; 
	int rowIndex_[] = {1, 0, 1};
	  vector <int> rowIndex(rowIndex_, rowIndex_+sizeof(rowIndex_)/sizeof(*rowIndex_)); 
	int columnIndex_[] = {2, 2, 0};
	  vector <int> columnIndex(columnIndex_, columnIndex_+sizeof(columnIndex_)/sizeof(*columnIndex_)); 
	int element_[] = {5, 7, 6};
	  vector <int> element(element_, element_+sizeof(element_)/sizeof(*element_)); 
	int _ = 40; 
END

CASE(2)
	int n = 3; 
	int m = 3; 
	int rowIndex_[] = {0, 0, 2, 2};
	  vector <int> rowIndex(rowIndex_, rowIndex_+sizeof(rowIndex_)/sizeof(*rowIndex_)); 
	int columnIndex_[] = {0, 2, 2, 0};
	  vector <int> columnIndex(columnIndex_, columnIndex_+sizeof(columnIndex_)/sizeof(*columnIndex_)); 
	int element_[] = {1, 1, 1, 1};
	  vector <int> element(element_, element_+sizeof(element_)/sizeof(*element_)); 
	int _ = 15; 
END
CASE(3)
	int n = 2; 
	int m = 2; 
	int rowIndex_[] = {0, 0, 1, 1};
	  vector <int> rowIndex(rowIndex_, rowIndex_+sizeof(rowIndex_)/sizeof(*rowIndex_)); 
	int columnIndex_[] = {0, 1, 1, 0};
	  vector <int> columnIndex(columnIndex_, columnIndex_+sizeof(columnIndex_)/sizeof(*columnIndex_)); 
	int element_[] = {5, 8, 5, 8};
	  vector <int> element(element_, element_+sizeof(element_)/sizeof(*element_)); 
	int _ = -1; 
END
CASE(4)
	int n = 1; 
	int m = 3; 
	int rowIndex_[] = {0};
	  vector <int> rowIndex(rowIndex_, rowIndex_+sizeof(rowIndex_)/sizeof(*rowIndex_)); 
	int columnIndex_[] = {1};
	  vector <int> columnIndex(columnIndex_, columnIndex_+sizeof(columnIndex_)/sizeof(*columnIndex_)); 
	int element_[] = {1};
	  vector <int> element(element_, element_+sizeof(element_)/sizeof(*element_)); 
	int _ = -1; 
END
CASE(5)
	int n = 123; 
	int m = 45; 
	int rowIndex_[] = {2, 3, 5, 7, 11};
	  vector <int> rowIndex(rowIndex_, rowIndex_+sizeof(rowIndex_)/sizeof(*rowIndex_)); 
	int columnIndex_[] = {13, 17, 19, 23, 29};
	  vector <int> columnIndex(columnIndex_, columnIndex_+sizeof(columnIndex_)/sizeof(*columnIndex_)); 
	int element_[] = {100, 200, 300, 400, 500};
	  vector <int> element(element_, element_+sizeof(element_)/sizeof(*element_)); 
	int _ = 367047; 
END
CASE(6)
	int n = 200; 
	int m = 200; 
	int rowIndex_[] = {5};
	  vector <int> rowIndex(rowIndex_, rowIndex_+sizeof(rowIndex_)/sizeof(*rowIndex_)); 
	int columnIndex_[] = {8};
	  vector <int> columnIndex(columnIndex_, columnIndex_+sizeof(columnIndex_)/sizeof(*columnIndex_)); 
	int element_[] = {666};
	  vector <int> element(element_, element_+sizeof(element_)/sizeof(*element_)); 
	int _ = 5737554; 
END
CASE(7)
	int n = 10; 
	int m = 10; 
	int rowIndex_[] = {0, 8, 7};
	  vector <int> rowIndex(rowIndex_, rowIndex_+sizeof(rowIndex_)/sizeof(*rowIndex_)); 
	int columnIndex_[] = {3, 1, 9};
	  vector <int> columnIndex(columnIndex_, columnIndex_+sizeof(columnIndex_)/sizeof(*columnIndex_)); 
	int element_[] = {5, 4, 7};
	  vector <int> element(element_, element_+sizeof(element_)/sizeof(*element_)); 
	int _ = 593; 
END

}
// END CUT HERE
