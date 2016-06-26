// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Goose Tattarrattat has a machine that contains N gears (cogwheels).
The gears are numbered 0 through N-1.
Each of the gears has one of three colors: red, green, or blue.

Some pairs of gears mesh.
Let X and Y be two meshing gears.
Note that if X is turning, Y must clearly be turning in the opposite direction (clockwise vs. counter-clockwise).
Two gears with the same color never mesh.
Apart from that, do not assume anything about the pairs of meshing gears.

You are given a string color and a vector <string> graph.
For each i, character i of color represents the color of gear i: 'R' is red, 'G' is green, and 'B' is blue.
The vector <string> graph contains the information on meshing pairs of gears:
If the j-th character of the i-th element of graph is 'Y', gear i meshes with gear j.

We want all gears to turn at the same time.
Additionally, all gears of the same color must turn in the same direction.
Return the minimal number of gears that have to be removed from the machine in order to achieve this goal.

DEFINITION
Class:GearsDiv1
Method:getmin
Parameters:string, vector <string>
Returns:int
Method signature:int getmin(string color, vector <string> graph)


NOTES
-Removing a gear creates a gap between the other gears, no new meshing pairs of gears are created by removing a gear.
-The graph described by graph is not necessarily planar.


CONSTRAINTS
-color will contain between 2 and 50 characters, inclusive.
-Each character in color will be 'R' or 'G' or 'B'.
-graph will contain exactly N elements, where N is the number of characters in color.
-Each element of graph will contain exactly N characters, where N is the number of characters in color.
-Each character in graph will be either 'Y' or 'N'.
-For each i, the i-th character of the i-th element of graph will be 'N'.
-For each i and j, the i-th character of the j-th element of graph and the j-th character of the i-th element of graph will be same.
-For each i and j, if the i-th and the j-th character of color are equal, then the i-th character of the j-th element of graph will be 'N'.


EXAMPLES

0)
"RGB"
{"NYY","YNY","YYN"}

Returns: 1

We have three gears, each meshes with each of the others.
In this configuration the gears are not able to turn at all.
However, as soon as we remove any of the gears, the other two will be able to turn.

1)
"RGBR"
{"NNNN","NNNN","NNNN","NNNN"}

Returns: 0

Here, each of the gears can turn without interacting with the others.

2)
"RGBR"
{"NYNN","YNYN","NYNY","NNYN"}

Returns: 1

These are four gears arranged into a row. It is possible to turn all these gears at the same time, but the two red gears would turn in opposite directions. Thus we need to remove at least one gear.

3)
"RRRRRGRRBGRRGBBGGGBRRRGBRGRRGG"
{"NNNNNYNNNYNNYNNNYNNNNNNNNYNNYY",
 "NNNNNNNNYNNNYNYNNYNNNNYNNYNNYY",
 "NNNNNYNNNNNNNNNNNNYNNNNNNYNNNY",
 "NNNNNNNNNYNNYNNYYYNNNNYNNYNNNN",
 "NNNNNNNNNYNNYNNYYYNNNNYNNNNNNN",
 "YNYNNNYYYNNYNYYNNNNNYYNYNNYYNN",
 "NNNNNYNNNNNNNNNYYYNNNNYNNYNNYY",
 "NNNNNYNNNNNNNNNYNNNNNNNNNNNNYN",
 "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
 "YNNYYNNNYNNNNYYNNNYNYYNYNNNNNN",
 "NNNNNNNNNNNNYNNYNYNNNNYNNNNNNY",
 "NNNNNYNNNNNNYNNYYYNNNNNNNNNNYN",
 "YYNYYNNNYNYYNYYNNNYNYNNYNNNNNN",
 "NNNNNYNNNYNNYNNYYYNNNNYNNYNYYY",
 "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
 "NNNYYNYYYNYYNYYNNNYNYNNYYNYYNN",
 "YNNYYNYNYNNYNYYNNNYNNNNYYNNYNN",
 "NYNYYNYNYNYYNYYNNNNYYNNYYNYNNN",
 "NNYNNNNNNYNNYNNYYNNNNNYNNYNNNY",
 "NNNNNNNNNNNNNNNNNYNNNNYNNYNNNY",
 "NNNNNYNNNYNNYNNYNYNNNNYNNNNNYY",
 "NNNNNYNNNYNNNNNNNNNNNNYNNNNNNN",
 "NYNYYNYNYNYNNYYNNNYYYYNYYNYNNN",
 "NNNNNYNNNYNNYNNYYYNNNNYNNNNNNY",
 "NNNNNNNNNNNNNNNYYYNNNNYNNYNNYY",
 "YYYYNNYNYNNNNYYNNNYYNNNNYNYYNN",
 "NNNNNYNNNNNNNNNYNYNNNNYNNYNNYN",
 "NNNNNYNNNNNNNYNYYNNNNNNNNYNNYY",
 "YYNNNNYYYNNYNYYNNNNNYNNNYNYYNN",
 "YYYNNNYNYNYNNYYNNNYYYNNYYNNYNN"}

Returns: 3



*/
// END CUT HERE
#line 115 "GearsDiv1.cpp"

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



class GearsDiv1 {
	public:
	int getmin(string color, vector <string> graph) {
		int N=color.size();
		int ans = N;
		REP(pat, 8) {
			VI turn(N);
			REP(i, N) turn[i] = color[i]=='R' ? ((pat>>2)&1) : (color[i]=='G' ? ((pat>>1)&1) : ((pat)&1));
			vector<PII> dame;
			VI dameL(N);
			REP(i, N) {
				RANGE(j, i+1, N) {
					if(graph[i][j]=='Y' && turn[i]==turn[j]) {
						dameL[i]++, dameL[j]++;
						dame.PB(MP(i,j));
					}
				}
			}
			int rm=0;
			cout<<"dameL "<<dameL<<endl;
			REP(i, dameL.size()) {
				int mx=-1;
				int mxi=-1;
				REP(k, dameL.size()) if(mx<dameL[k]){mx=dameL[k];mxi=k;}
				if(dame.size()==0) break;
				vector<PII> ndame;
				REP(j, dame.size()) {
					if(!(dame[j].first==mxi || dame[j].second==mxi)) ndame.PB(dame[j]);
				}
				dame = ndame;
				rm++;
				dameL[mxi]=0;
			}
			cout<<"turn "<<turn<<endl;
			//cout<<"dame "<<dame<<endl;
			cout<<"rm "<<rm<<endl;
			ans = min(ans, rm);
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
#define END	 verify_case(_, GearsDiv1().getmin(color, graph));}
int main(){
//CASE(3)
//	string color = "RRRRRGRRBGRRGBBGGGBRRRGBRGRRGG"; 
//	string graph_[] = {"NNNNNYNNNYNNYNNNYNNNNNNNNYNNYY",
// "NNNNNNNNYNNNYNYNNYNNNNYNNYNNYY",
// "NNNNNYNNNNNNNNNNNNYNNNNNNYNNNY",
// "NNNNNNNNNYNNYNNYYYNNNNYNNYNNNN",
// "NNNNNNNNNYNNYNNYYYNNNNYNNNNNNN",
// "YNYNNNYYYNNYNYYNNNNNYYNYNNYYNN",
// "NNNNNYNNNNNNNNNYYYNNNNYNNYNNYY",
// "NNNNNYNNNNNNNNNYNNNNNNNNNNNNYN",
// "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
// "YNNYYNNNYNNNNYYNNNYNYYNYNNNNNN",
// "NNNNNNNNNNNNYNNYNYNNNNYNNNNNNY",
// "NNNNNYNNNNNNYNNYYYNNNNNNNNNNYN",
// "YYNYYNNNYNYYNYYNNNYNYNNYNNNNNN",
// "NNNNNYNNNYNNYNNYYYNNNNYNNYNYYY",
// "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
// "NNNYYNYYYNYYNYYNNNYNYNNYYNYYNN",
// "YNNYYNYNYNNYNYYNNNYNNNNYYNNYNN",
// "NYNYYNYNYNYYNYYNNNNYYNNYYNYNNN",
// "NNYNNNNNNYNNYNNYYNNNNNYNNYNNNY",
// "NNNNNNNNNNNNNNNNNYNNNNYNNYNNNY",
// "NNNNNYNNNYNNYNNYNYNNNNYNNNNNYY",
// "NNNNNYNNNYNNNNNNNNNNNNYNNNNNNN",
// "NYNYYNYNYNYNNYYNNNYYYYNYYNYNNN",
// "NNNNNYNNNYNNYNNYYYNNNNYNNNNNNY",
// "NNNNNNNNNNNNNNNYYYNNNNYNNYNNYY",
// "YYYYNNYNYNNNNYYNNNYYNNNNYNYYNN",
// "NNNNNYNNNNNNNNNYNYNNNNYNNYNNYN",
// "NNNNNYNNNNNNNYNYYNNNNNNNNYNNYY",
// "YYNNNNYYYNNYNYYNNNNNYNNNYNYYNN",
// "YYYNNNYNYNYNNYYNNNYYYNNYYNNYNN"};
//	  vector <string> graph(graph_, graph_+sizeof(graph_)/sizeof(*graph_)); 
//	int _ = 3; 
//END

//return 0;
CASE(0)
	string color = "RGB"; 
	string graph_[] = {"NYY","YNY","YYN"};
	  vector <string> graph(graph_, graph_+sizeof(graph_)/sizeof(*graph_)); 
	int _ = 1; 
END
//return 0;
CASE(1)
	string color = "RGBR"; 
	string graph_[] = {"NNNN","NNNN","NNNN","NNNN"};
	  vector <string> graph(graph_, graph_+sizeof(graph_)/sizeof(*graph_)); 
	int _ = 0; 
END
CASE(2)
	string color = "RGBR"; 
	string graph_[] = {"NYNN","YNYN","NYNY","NNYN"};
	  vector <string> graph(graph_, graph_+sizeof(graph_)/sizeof(*graph_)); 
	int _ = 1; 
END
CASE(3)
	string color = "RRRRRGRRBGRRGBBGGGBRRRGBRGRRGG"; 
	string graph_[] = {"NNNNNYNNNYNNYNNNYNNNNNNNNYNNYY",
 "NNNNNNNNYNNNYNYNNYNNNNYNNYNNYY",
 "NNNNNYNNNNNNNNNNNNYNNNNNNYNNNY",
 "NNNNNNNNNYNNYNNYYYNNNNYNNYNNNN",
 "NNNNNNNNNYNNYNNYYYNNNNYNNNNNNN",
 "YNYNNNYYYNNYNYYNNNNNYYNYNNYYNN",
 "NNNNNYNNNNNNNNNYYYNNNNYNNYNNYY",
 "NNNNNYNNNNNNNNNYNNNNNNNNNNNNYN",
 "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
 "YNNYYNNNYNNNNYYNNNYNYYNYNNNNNN",
 "NNNNNNNNNNNNYNNYNYNNNNYNNNNNNY",
 "NNNNNYNNNNNNYNNYYYNNNNNNNNNNYN",
 "YYNYYNNNYNYYNYYNNNYNYNNYNNNNNN",
 "NNNNNYNNNYNNYNNYYYNNNNYNNYNYYY",
 "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
 "NNNYYNYYYNYYNYYNNNYNYNNYYNYYNN",
 "YNNYYNYNYNNYNYYNNNYNNNNYYNNYNN",
 "NYNYYNYNYNYYNYYNNNNYYNNYYNYNNN",
 "NNYNNNNNNYNNYNNYYNNNNNYNNYNNNY",
 "NNNNNNNNNNNNNNNNNYNNNNYNNYNNNY",
 "NNNNNYNNNYNNYNNYNYNNNNYNNNNNYY",
 "NNNNNYNNNYNNNNNNNNNNNNYNNNNNNN",
 "NYNYYNYNYNYNNYYNNNYYYYNYYNYNNN",
 "NNNNNYNNNYNNYNNYYYNNNNYNNNNNNY",
 "NNNNNNNNNNNNNNNYYYNNNNYNNYNNYY",
 "YYYYNNYNYNNNNYYNNNYYNNNNYNYYNN",
 "NNNNNYNNNNNNNNNYNYNNNNYNNYNNYN",
 "NNNNNYNNNNNNNYNYYNNNNNNNNYNNYY",
 "YYNNNNYYYNNYNYYNNNNNYNNNYNYYNN",
 "YYYNNNYNYNYNNYYNNNYYYNNYYNNYNN"};
	  vector <string> graph(graph_, graph_+sizeof(graph_)/sizeof(*graph_)); 
	int _ = 3; 
END

}
// END CUT HERE
