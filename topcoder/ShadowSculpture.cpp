// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// A shadow sculpture is a 3D object that seems amorphous but casts a beautiful shadow.



You want to create a simple shadow sculpture that will consist of unit cubes.
More precisely, imagine an n*n*n cube that is aligned with the coordinate axes and divided into unit cubes.
Your sculpture will consist of some of those unit cubes (possibly none or all of them).
The unit cubes have coordinates (x,y,z) where 0 <= x,y,z < n.



You have already determined three shadows your sculpture should cast: its orthogonal projections onto the XY, YZ, and ZX plane.
You are given their description in three vector <string>s: XY, YZ, and ZX.



Their meaning is as follows:
For each i and j, the character XY[i][j] is either 'Y' or 'N'.
The character 'Y' means that the unit square (i,j) of the projection is dark.
In other words, if XY[i][j] is 'Y', at least one of the cubes with coordinates (i,j,k) has to be a part of your sculpture.
On the other hand, if XY[i][j] is 'N', none of the cubes with coordinates (i,j,k) may belong into your sculpture.
YZ and ZX describe the other two projections in the same way.
E.g., if ZX[i][j] is 'Y', you have to use at least one of the cubes (j,k,i).



Finally, there is one last constraint:
Your entire sculpture has to be 6-connected.
(Formally: Your sculpture must form one connected component, given that two cubes are adjacent iff they share a common face.)



Return "Possible" if it is possible to construct a sculpture that matches all the given constraints.
Otherwise, return "Impossible".

DEFINITION
Class:ShadowSculpture
Method:possible
Parameters:vector <string>, vector <string>, vector <string>
Returns:string
Method signature:string possible(vector <string> XY, vector <string> YZ, vector <string> ZX)


CONSTRAINTS
-n will be between 1 and 10, inclusive.
-XY, YZ and ZX will contain exactly n elements.
-Each element of XY, YZ and ZX will contain exactly n characters.
-Each element of XY, YZ and ZX will contain only 'Y' and 'N'.


EXAMPLES

0)
{"YN","NN"}
{"YN","NN"}
{"YN","NN"}

Returns: "Possible"

It is possible: we only have one solid cell at (0, 0, 0).

1)
{"YN","NY"}
{"YN","NY"}
{"YN","NY"}

Returns: "Impossible"

Here it is impossible to make a valid sculpture.
Note that you can make all three projections look right by using exactly two cubes: (0,0,0) and (1,1,1).
However, this sculpture is not 6-connected.

2)
{"YYY","YNY","YYY"}
{"YYY","YNY","YYY"}
{"YYY","YNY","YYY"}

Returns: "Possible"



3)
{"YYY","YNY","YYY"}
{"NYY","YNY","YYY"}
{"YYY","YNY","YYN"}

Returns: "Impossible"



4)
{"N"}
{"N"}
{"N"}

Returns: "Possible"

A sculpture that consists of no cubes is connected.

******************************/
// END CUT HERE
#line 106 "ShadowSculpture.cpp"
#include <vector>
#include <map>
#include <set>
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
#include <cctype>
#include <cstdio>
#include <cassert>
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

int vis[11][11][11];
int w[11][11][11];
int ww[11][11][11];

ll N;
vector <string> XY, YZ, ZX;
void dfs(int x, int y, int z) {
	int dx[] = {-1,1,0,0,0,0};
	int dy[] = {0,0,-1,1,0,0};
	int dz[] = {0,0,0,0,-1,1};
	vis[x][y][z] = ww[x][y][z] = 1;
	REP(dir,6) {
		int nx=x+dx[dir]; int ny=y+dy[dir]; int nz=z+dz[dir];
		#define IN(x, A, B) ((A)<=(x) && (x)<(B))
		if(IN(nx, 0, N) && IN(ny, 0, N) && IN(nz, 0, N) && w[nx][ny][nz] && !vis[nx][ny][nz]) {
			dfs(nx, ny, nz);
		}
	}
}

bool check(int w[11][11][11]) {
	REP(i,N)REP(j,N){int co=0;REP(k,N)co+=w[i][j][k];if(XY[i][j]=='Y' ^ co>0)return false;}
	REP(i,N)REP(j,N){int co=0;REP(k,N)co+=w[k][i][j];if(YZ[i][j]=='Y' ^ co>0)return false;}
	REP(i,N)REP(j,N){int co=0;REP(k,N)co+=w[j][k][i];if(ZX[i][j]=='Y' ^ co>0)return false;}
	return true;
}

class ShadowSculpture {
	public:
	string possible(vector <string> _XY, vector <string> _YZ, vector <string> _ZX) {
		XY=_XY;YZ=_YZ;ZX=_ZX;
		N = XY.size();
		REP(i,N)REP(j,N)REP(k,N)w[i][j][k]=1;
		REP(i,N)REP(j,N)REP(k,N)vis[i][j][k]=0;
		REP(x,N)REP(y,N)REP(z,N)if(XY[x][y]=='N' || YZ[y][z]=='N' || ZX[z][x]=='N')w[x][y][z]=0;
		if(!check(w)) return "Impossible";
		int total = 0;
		REP(i,N)REP(j,N)REP(k,N) total += w[i][j][k];
		if(total==0) return "Possible";
		REP(i,N)REP(j,N)REP(k,N) if(w[i][j][k] && !vis[i][j][k]) {
			REP(i,N)REP(j,N)REP(k,N)ww[i][j][k]=0;
			dfs(i, j, k);
			if(check(ww)) return "Possible";
		}
		return "Impossible";
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const string& Expected, const string& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, ShadowSculpture().possible(XY, YZ, ZX));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){
CASE(4)
	string XY_[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"};
	  vector <string> XY(XY_, XY_+sizeof(XY_)/sizeof(*XY_)); 
	string YZ_[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"};
	  vector <string> YZ(YZ_, YZ_+sizeof(YZ_)/sizeof(*YZ_)); 
	string ZX_[] = {"YYYYY", "YYNYY", "YYYYY", "YYNYY", "YYYYY"};
	  vector <string> ZX(ZX_, ZX_+sizeof(ZX_)/sizeof(*ZX_)); 
	string _ = "Possible"; 
END

//return 0;
CASE(0)
	string XY_[] = {"YN","NN"};
	  vector <string> XY(XY_, XY_+sizeof(XY_)/sizeof(*XY_)); 
	string YZ_[] = {"YN","NN"};
	  vector <string> YZ(YZ_, YZ_+sizeof(YZ_)/sizeof(*YZ_)); 
	string ZX_[] = {"YN","NN"};
	  vector <string> ZX(ZX_, ZX_+sizeof(ZX_)/sizeof(*ZX_)); 
	string _ = "Possible"; 
END
CASE(1)
	string XY_[] = {"YN","NY"};
	  vector <string> XY(XY_, XY_+sizeof(XY_)/sizeof(*XY_)); 
	string YZ_[] = {"YN","NY"};
	  vector <string> YZ(YZ_, YZ_+sizeof(YZ_)/sizeof(*YZ_)); 
	string ZX_[] = {"YN","NY"};
	  vector <string> ZX(ZX_, ZX_+sizeof(ZX_)/sizeof(*ZX_)); 
	string _ = "Impossible"; 
END
//return 0;
CASE(2)
	string XY_[] = {"YYY","YNY","YYY"};
	  vector <string> XY(XY_, XY_+sizeof(XY_)/sizeof(*XY_)); 
	string YZ_[] = {"YYY","YNY","YYY"};
	  vector <string> YZ(YZ_, YZ_+sizeof(YZ_)/sizeof(*YZ_)); 
	string ZX_[] = {"YYY","YNY","YYY"};
	  vector <string> ZX(ZX_, ZX_+sizeof(ZX_)/sizeof(*ZX_)); 
	string _ = "Possible"; 
END
CASE(3)
	string XY_[] = {"YYY","YNY","YYY"};
	  vector <string> XY(XY_, XY_+sizeof(XY_)/sizeof(*XY_)); 
	string YZ_[] = {"NYY","YNY","YYY"};
	  vector <string> YZ(YZ_, YZ_+sizeof(YZ_)/sizeof(*YZ_)); 
	string ZX_[] = {"YYY","YNY","YYN"};
	  vector <string> ZX(ZX_, ZX_+sizeof(ZX_)/sizeof(*ZX_)); 
	string _ = "Impossible"; 
END
CASE(4)
	string XY_[] = {"N"};
	  vector <string> XY(XY_, XY_+sizeof(XY_)/sizeof(*XY_)); 
	string YZ_[] = {"N"};
	  vector <string> YZ(YZ_, YZ_+sizeof(YZ_)/sizeof(*YZ_)); 
	string ZX_[] = {"N"};
	  vector <string> ZX(ZX_, ZX_+sizeof(ZX_)/sizeof(*ZX_)); 
	string _ = "Possible"; 
END
#if 0  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: String
	int N=UNIFORM_LL(1, 5);
	vector <string> XY; 
	{
		XY = vector <string>(N); 
		REP(i, N) {
			XY[i] = UNIFORM_DOUBLE(0, 1) > 0.5 ? 'Y':'N';
		}
	}
// param type: String
	vector <string> YZ; 
	{
		YZ = vector <string>(N); 
		REP(i, N) {
			YZ[i] = UNIFORM_DOUBLE(0, 1) > 0.5 ? 'Y':'N';
		}
	}
// param type: String
	vector <string> ZX; 
	{
		ZX = vector <string>(N); 
		REP(i, N) {
			ZX[i] = UNIFORM_DOUBLE(0, 1) > 0.5 ? 'Y':'N';
		}
	}
	string _0 = ShadowSculpture().possible(XY, YZ, ZX);
	string _1 = ShadowSculptureRef().possible(XY, YZ, ZX);
	if(!verify_case(_0, _1, true)) {
print(XY);
print(YZ);
print(ZX);
	}
}
#endif

}
// END CUT HERE
