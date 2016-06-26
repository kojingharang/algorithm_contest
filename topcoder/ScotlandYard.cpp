// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel and Fox Jiro play a game called Scotland Yard.
Their version of the game is a bit simplified, so if you know the original game, make sure you read the problem statement carefully.


In the game Ciel and Jiro play, they use a map containing n cities.
The cities are numbered 0 through n-1.
The map also contains a bunch of arrows.
Each arrow leads from one city to another (different) city, and has one of three possible colors.
The colors represent three types of transportation: taxis, buses, and metro (subway).
Both Ciel and Jiro know all information in this map.


You are given three vector <string>s: taxi, bus, and metro.
The j-th character of the i-th element of taxi is 'Y' if it is possible to travel directly from city i to city j using a taxi, or 'N' if that is not possible.
In the same way, bus and metro encode the information about bus and subway travel.
Note that all transportation options are one-way. Also note that there are no additional restrictions.
(That is, it may be possible to travel between some pairs of cities in both directions, there may be more than one transportation option from city i to city j, and for each transport type there can be arbitrarily many options leaving a given city.)


The game starts by Ciel secretly choosing one of the n cities as her initial location.
The game then proceeds in turns.
In each turn, first Ciel moves to an adjacent location, then Jiro has the option to announce her new location.
More precisely, it looks as follows:
Whenever it is Ciel's turn to move, she has to move from her current city X to some other city Y.
If there are no transportation options that start in the city X, Ciel announces this and the game ends.
Otherwise, she chooses one of the available options and moves to its destination.
Additionally, Ciel announces to Jiro the type of the transportation system she used ("taxi", "bus", or "metro").
Whenever it is Jiro's turn, if he is certain of Ciel's current city, he announces it and the game ends.
Otherwise, Jiro passes and it's again Ciel's turn to move.
(Note that Jiro can use all the information he has: the layout of the map, and the sequence of transportation systems Ciel already announced.)


Ciel's score is the number of travels she made.
Return Ciel's score, assuming that she plays optimally.
If she can continue the game forever without being discovered by Jiro, return -1 instead.

DEFINITION
Class:ScotlandYard
Method:maxMoves
Parameters:vector <string>, vector <string>, vector <string>
Returns:int
Method signature:int maxMoves(vector <string> taxi, vector <string> bus, vector <string> metro)


NOTES
-The answer will always fit into a signed 32bit integer.


CONSTRAINTS
-taxi will contain between 2 and 50 elements, inclusive.
-taxi, bus, and metro will contain the same number of elements.
-Each element of taxi, bus, and metro will contain n characters, where n is the number of elements in taxi.
-Each character in taxi, bus, and metro will be either 'Y' or 'N'.
-The i-th character of the i-th element of taxi, bus, and metro will be 'N'.


EXAMPLES

0)
{"NYN",
 "NNY",
 "NNN"}
{"NNN",
 "NNN",
 "NNN"}
{"NNN",
 "NNN",
 "NNN"}

Returns: 2


Ciel starts in city 0.
In her first move, she announces "taxi" and moves from 0 to 1.
At that moment, Jiro is not certain of her location: she can be in city 1 or in city 2.
In her second move, Ciel announces "taxi" and moves from 1 to 2.
Jiro announces that Ciel is in city 2 and the game ends.

1)
{"NYY",
 "NNN",
 "NNN"}
{"NNN",
 "NNN",
 "NNN"}
{"NNN",
 "NNN",
 "NNN"}

Returns: 1


After Ciel's first move, Jiro doesn't know her location. Still, the game ends, because Ciel has no more moves.

2)
{"NYYY",
 "YNYY",
 "YYNY",
 "YYYN"}
{"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"}
{"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"}

Returns: -1


Ciel can use taxis to drive back and forth between the cities indefinitely. Jiro has no chance to discover her location.

3)
{"NNY",
 "NNY",
 "NNN"}
{"NYN",
 "NNY",
 "NNN"}
{"NNN",
 "NNN",
 "YNN"}

Returns: 2


Ciel starts by choosing her initial location and the first mode of transport.
Here is how Jiro will think after Ciel's first move:

Suppose that Ciel announced "taxi". She could have started in city 0 or in city 1, but either way she would take the taxi to city 2. Thus, Jiro knows that Ciel is in city 2 and the game ends.
Metro is even simpler. If Ciel announced she took the metro, she must have started in city 2 and then she took the metro to city 0. Jiro announces city 0 and the game ends.
If Ciel announed that she took the bus, Jiro is not sure about her location: she can be either in city 1, or in city 2.

Regardless of where Ciel started and what she does in the second step after taking a bus in the first step, Jiro will always be able to determine her location and the game ends.

4)
{"NNN",
 "YNY",
 "NNN"}
{"NNN",
 "YNN",
 "YNN"}
{"NNN",
 "NNN",
 "YYN"}

Returns: -1


If Ciel travels back and forth between cities 1 and 2, Jiro will never catch her.

5)
{"NNNNYNNNYY",
 "NNYNNYYYYY",
 "NNNNNNNNNN",
 "YYNNYYNNNY",
 "NNYNNNNNNN",
 "YNYNYNNNYN",
 "NNYNYNNNYN",
 "NNNNNNYNNN",
 "NNNNNNNNNN",
 "NNNNNNYNNN"}
{"NNYNNNYNNY",
 "YNYNNYYNYY",
 "NNNNNNNNNN",
 "YNYNNYNYNY",
 "NNYNNNNNYN",
 "YNYNYNYNYN",
 "NNYNNNNNNY",
 "YNYNNNNNNN",
 "NNNNNNNNNN",
 "NNYNYNNNNN"}
{"NNNNNNNYNN",
 "YNYNNNNNYN",
 "NNNNNNNNNN",
 "NYNNYNNNYY",
 "NNYNNNNNNN",
 "YNYNNNNNYY",
 "NNNNYNNNYN",
 "NNYNNNYNNN",
 "NNNNNNNNNY",
 "NNYNYNNNNN"}

Returns: 21



*/
// END CUT HERE
#line 195 "ScotlandYard.cpp"

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



class ScotlandYard {
	public:
	int maxMoves(vector <string> taxi, vector <string> bus, vector <string> metro) {
		
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
#define END	 verify_case(_, ScotlandYard().maxMoves(taxi, bus, metro));}
int main(){

CASE(0)
	string taxi_[] = {"NYN",
 "NNY",
 "NNN"};
	  vector <string> taxi(taxi_, taxi_+sizeof(taxi_)/sizeof(*taxi_)); 
	string bus_[] = {"NNN",
 "NNN",
 "NNN"};
	  vector <string> bus(bus_, bus_+sizeof(bus_)/sizeof(*bus_)); 
	string metro_[] = {"NNN",
 "NNN",
 "NNN"};
	  vector <string> metro(metro_, metro_+sizeof(metro_)/sizeof(*metro_)); 
	int _ = 2; 
END
CASE(1)
	string taxi_[] = {"NYY",
 "NNN",
 "NNN"};
	  vector <string> taxi(taxi_, taxi_+sizeof(taxi_)/sizeof(*taxi_)); 
	string bus_[] = {"NNN",
 "NNN",
 "NNN"};
	  vector <string> bus(bus_, bus_+sizeof(bus_)/sizeof(*bus_)); 
	string metro_[] = {"NNN",
 "NNN",
 "NNN"};
	  vector <string> metro(metro_, metro_+sizeof(metro_)/sizeof(*metro_)); 
	int _ = 1; 
END
CASE(2)
	string taxi_[] = {"NYYY",
 "YNYY",
 "YYNY",
 "YYYN"};
	  vector <string> taxi(taxi_, taxi_+sizeof(taxi_)/sizeof(*taxi_)); 
	string bus_[] = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"};
	  vector <string> bus(bus_, bus_+sizeof(bus_)/sizeof(*bus_)); 
	string metro_[] = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"};
	  vector <string> metro(metro_, metro_+sizeof(metro_)/sizeof(*metro_)); 
	int _ = -1; 
END
CASE(3)
	string taxi_[] = {"NNY",
 "NNY",
 "NNN"};
	  vector <string> taxi(taxi_, taxi_+sizeof(taxi_)/sizeof(*taxi_)); 
	string bus_[] = {"NYN",
 "NNY",
 "NNN"};
	  vector <string> bus(bus_, bus_+sizeof(bus_)/sizeof(*bus_)); 
	string metro_[] = {"NNN",
 "NNN",
 "YNN"};
	  vector <string> metro(metro_, metro_+sizeof(metro_)/sizeof(*metro_)); 
	int _ = 2; 
END
CASE(4)
	string taxi_[] = {"NNN",
 "YNY",
 "NNN"};
	  vector <string> taxi(taxi_, taxi_+sizeof(taxi_)/sizeof(*taxi_)); 
	string bus_[] = {"NNN",
 "YNN",
 "YNN"};
	  vector <string> bus(bus_, bus_+sizeof(bus_)/sizeof(*bus_)); 
	string metro_[] = {"NNN",
 "NNN",
 "YYN"};
	  vector <string> metro(metro_, metro_+sizeof(metro_)/sizeof(*metro_)); 
	int _ = -1; 
END
CASE(5)
	string taxi_[] = {"NNNNYNNNYY",
 "NNYNNYYYYY",
 "NNNNNNNNNN",
 "YYNNYYNNNY",
 "NNYNNNNNNN",
 "YNYNYNNNYN",
 "NNYNYNNNYN",
 "NNNNNNYNNN",
 "NNNNNNNNNN",
 "NNNNNNYNNN"};
	  vector <string> taxi(taxi_, taxi_+sizeof(taxi_)/sizeof(*taxi_)); 
	string bus_[] = {"NNYNNNYNNY",
 "YNYNNYYNYY",
 "NNNNNNNNNN",
 "YNYNNYNYNY",
 "NNYNNNNNYN",
 "YNYNYNYNYN",
 "NNYNNNNNNY",
 "YNYNNNNNNN",
 "NNNNNNNNNN",
 "NNYNYNNNNN"};
	  vector <string> bus(bus_, bus_+sizeof(bus_)/sizeof(*bus_)); 
	string metro_[] = {"NNNNNNNYNN",
 "YNYNNNNNYN",
 "NNNNNNNNNN",
 "NYNNYNNNYY",
 "NNYNNNNNNN",
 "YNYNNNNNYY",
 "NNNNYNNNYN",
 "NNYNNNYNNN",
 "NNNNNNNNNY",
 "NNYNYNNNNN"};
	  vector <string> metro(metro_, metro_+sizeof(metro_)/sizeof(*metro_)); 
	int _ = 21; 
END

}
// END CUT HERE
