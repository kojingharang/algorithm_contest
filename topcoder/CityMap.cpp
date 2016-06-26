// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Manao arrived to a city he's never been to. He bought a city map that depicts the city as a grid H squares high and W squares wide. Each square in this grid can either contain a street segment or a single point of interest of some type.

It was later when Manao noticed that the map lacked a legend. The map legend is the list of all types of points of interest (further referred to as POIs) present on the map. Each POI type is coupled with the corresponding symbol denoting this type on the map. For example, you might have seen an 'M' sign denoting a metro station or a fork-and-spoon sign denoting a restaurant on a city map.

Fortunately, not all is lost: the map contains a legend summary. The summary states how many POIs of each type are there on the map (for example, it could say: all in all, there are 9 restaurants and 4 metro stations on the map). Moreover, it turned out that all quantities are pairwise distinct. Manao realized that he could guess the signs using this information (for instance, if there were 4 triangle signs on the map Manao would know that triangle stands for a metro station).

You are given a vector <string> cityMap containing H elements, each of them W characters long. Each character of cityMap designates the corresponding square on Manao's city map and is '.' if there is a street segment in that square or an uppercase letter if the square contains a POI. Different types of POIs are denoted by different letters, two POIs of the same type are always denoted with the same letter. As you see, the letters just stand for the different signs on the map.

You are also given a vector <int> POIs. POIs[i] is the number of occurences of the i-th type POIs on the map. It is guaranteed that the information given is consistent, i.e. there are exactly as many different letters in cityMap as elements in POIs and there exists a valid assignment of letters to POI types.

For each POI type, determine the letter with which it is denoted on the map. Return a string of as many characters as elements in POIs, where the character at the i-th position is the letter corresponding to the i-th POI type.

DEFINITION
Class:CityMap
Method:getLegend
Parameters:vector <string>, vector <int>
Returns:string
Method signature:string getLegend(vector <string> cityMap, vector <int> POIs)


CONSTRAINTS
-cityMap will contain between 1 and 50 elements, inclusive.
-Each element of cityMap will be between 1 and 50 characters long, inclusive.
-The elements of cityMap will be of the same length.
-Elements of cityMap will consist of '.' and 'A'-'Z' characters only.
-POIs will contain between 1 and 26 elements, inclusive.
-Each element of POIs will be between 1 and 2500, inclusive.
-All elements of POIs will be distinct.
-There will exist a valid assignment of letters in cityMap to POI types.


EXAMPLES

0)
{"M....M",
 "...R.M",
 "R..R.R"}
{3, 4}

Returns: "MR"

The city map is 3 squares high and 6 squares wide. There are 3 'M' signs and 4 'R' signs on the map. The legend summary states that there are three POIs of type 0 and four POIs of type 1 on the map. Obviously, the former are denoted with 'M' on the map and the latter are denoted with 'R'.

1)
{"XXXXXXXZXYYY"}
{1, 8, 3}

Returns: "ZXY"

There is a single 'Z' on the map, thus the legend should state that POIs of type 0 are denoted with 'Z'. There are three 'Y's on the map, therefore POIs of type 2 are surely denoted with 'Y'. Finally, it's now obvious that 'X's stand for the POIs of type 1.

2)
{"...........",
 "...........",
 "...........",
 "..........T"}
{1}

Returns: "T"

The poor city has only one point of interest in the farmost corner.

3)
{"AIAAARRI.......GOAI.",
 ".O..AIIGI.OAAAGI.A.I",
 ".A.IAAAARI..AI.AAGR.",
 "....IAI..AOIGA.GAIA.",
 "I.AIIIAG...GAR.IIAGA",
 "IA.AOA....I....I.GAA",
 "IOIGRAAAO.AI.AA.RAAA",
 "AI.AAA.AIR.AGRIAAG..",
 "AAAAIAAAI...AAG.RGRA",
 ".J.IA...G.A.AA.II.AA"}

{16,7,1,35,11,66}


Returns: "GOJIRA"



*/
// END CUT HERE
#line 88 "CityMap.cpp"

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



class CityMap {
	public:
	string getLegend(vector <string> CM, vector <int> P) {
		map<char, int> hi;
		FOR(e, CM) FOR(c, *e) if(*c!='.') hi[*c]++;
		string ans;
		FOR(e, P) FOR(ee, hi) if(*e==ee->second) ans.PB(ee->first);
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
void verify_case(const string& Expected, const string& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, CityMap().getLegend(cityMap, POIs));}
int main(){

CASE(0)
	string cityMap_[] = {"M....M",
 "...R.M",
 "R..R.R"};
	  vector <string> cityMap(cityMap_, cityMap_+sizeof(cityMap_)/sizeof(*cityMap_)); 
	int POIs_[] = {3, 4};
	  vector <int> POIs(POIs_, POIs_+sizeof(POIs_)/sizeof(*POIs_)); 
	string _ = "MR"; 
END
CASE(1)
	string cityMap_[] = {"XXXXXXXZXYYY"};
	  vector <string> cityMap(cityMap_, cityMap_+sizeof(cityMap_)/sizeof(*cityMap_)); 
	int POIs_[] = {1, 8, 3};
	  vector <int> POIs(POIs_, POIs_+sizeof(POIs_)/sizeof(*POIs_)); 
	string _ = "ZXY"; 
END
CASE(2)
	string cityMap_[] = {"...........",
 "...........",
 "...........",
 "..........T"};
	  vector <string> cityMap(cityMap_, cityMap_+sizeof(cityMap_)/sizeof(*cityMap_)); 
	int POIs_[] = {1};
	  vector <int> POIs(POIs_, POIs_+sizeof(POIs_)/sizeof(*POIs_)); 
	string _ = "T"; 
END
CASE(3)
	string cityMap_[] = {"AIAAARRI.......GOAI.",
 ".O..AIIGI.OAAAGI.A.I",
 ".A.IAAAARI..AI.AAGR.",
 "....IAI..AOIGA.GAIA.",
 "I.AIIIAG...GAR.IIAGA",
 "IA.AOA....I....I.GAA",
 "IOIGRAAAO.AI.AA.RAAA",
 "AI.AAA.AIR.AGRIAAG..",
 "AAAAIAAAI...AAG.RGRA",
 ".J.IA...G.A.AA.II.AA"}
;
	  vector <string> cityMap(cityMap_, cityMap_+sizeof(cityMap_)/sizeof(*cityMap_)); 
	int POIs_[] = {16,7,1,35,11,66}
;
	  vector <int> POIs(POIs_, POIs_+sizeof(POIs_)/sizeof(*POIs_)); 
	string _ = "GOJIRA"; 
END

}
// END CUT HERE
