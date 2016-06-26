// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Magical Girl Lein is observing ants. 
There are N ants. At first, they have integer coordinates in the Cartesian plane. More precisely, ant i starts at the point (x[i], y[i]). 
All ants move at the same speed. Each ant moves in one of the four basic directions. (I.e., either parallel to the x axis or parallel to the y axis.) 
When 2 or more ants meet at the same time, these ants disappear. 
You are given two vector <int>s x and y, containing N elements each, 
and a string direction, containing N characters. 
Character i of direction encodes the direction in which ant i is going: 

 'N' means north (y coordinate increases), 
 'E' means east (x coordinate increases), 
 'S' means south (y coordinate decreases), 
 and 'W' means west (x coordinate decreases). 

Return the number of ants that still exist after the last meeting occurs.

DEFINITION
Class:AntsMeet
Method:countAnts
Parameters:vector <int>, vector <int>, string
Returns:int
Method signature:int countAnts(vector <int> x, vector <int> y, string direction)


CONSTRAINTS
-x will contain between 1 and 50 elements, inclusive.
-y will contain the same number of elements as x.
-The number of characters in direction will be the same as the number of elements in x.
-Each element of x and y will be between -1000 and 1000, inclusive.
-No pair of points in the input will be equal.
-Each character of direction will be one of 'N', 'E', 'W' and 'S'.


EXAMPLES

0)
{0,10,20,30}
{0,10,20,30}
"NWNE"

Returns: 2

The ants that start at (0,0) and (10,10) will meet at (0, 10) at time 10.
The remaining two ants will never meet.

1)
{-10,0,0,10}
{0,-10,10,0}
"NEWS"

Returns: 0

More than two ants can meet at the same time.

2)
{-1,-1,-1,0,0,0,1,1,1}
{-1,0,1,-1,0,1,-1,0,1}
"ESEWNNEWW"

Returns: 4

The ants that start at (-1,-1) and (0,-1) will meet at (-0.5,-1). 
The ants that start at (-1,1), (0,0) and (1,1) will meet at (0,1). 
Thus, 4 ants will remain after all meetings. 
Note that ants that start at (-1,0) and (0,-1) won't meet at (-1,1) because one of them will disappear before reaching the meeting point.

3)
{4,7,6,2,6,5,7,7,8,4,7,8,8,8,5,4,8,9,1,5,9,3,4,0,0,1,0,7,2,6,9,6,3,0,5,5,1,2,0,4,9,7,7,1,8,1,9,2,7,3}
{2,3,0,6,8,4,9,0,5,0,2,4,3,8,1,5,0,7,3,7,0,9,8,1,9,4,7,8,1,1,6,6,6,2,8,5,1,9,0,1,1,1,7,0,2,5,4,7,5,3}
"SSNWSWSENSWSESWEWSWSENWNNNESWSWSWWSSWEEWWNWWWNWENN" 

Returns: 25



4)
{478,-664,759,434,-405,513,565,-396,311,-174,56,993,251,-341,993,-112,242,129,383,513,-78,-341,-148,129,423
,493,434,-405,478,-148,929,251,56,242,929,-78,423,-664,802,251,759,383,-112,-591,-591,-248,660,660,735,493}
{-186,98,948,795,289,-678,948,-170,-195,290,-354,-424,289,-157,-166,150,706,-678,684,-294,-234,36,36,-294,-216
,-234,427,945,265,-157,265,715,275,715,-186,337,798,-170,427,706,754,961,286,-216,798,286,961,684,-424,337}
"WNSNNSSWWWEENWESNSWSWSEWWEWEWWWNWESNSSNNSNNWWWNESE"

Returns: 44



*/
// END CUT HERE
#line 92 "AntsMeet.cpp"

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
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class AntsMeet {
	public:
	int countAnts(vector <int> x, vector <int> y, string dir) {
		int N=x.size();
		VI live(N, 1);
		REP(i, N) {
			x[i]*=2;
			y[i]*=2;
		}
		REP(t, 4000) {
			VI nlive(live);
			REP(i, N) {
				if(!live[i]) continue;
				if(dir[i]=='N') y[i]++;
				if(dir[i]=='S') y[i]--;
				if(dir[i]=='E') x[i]++;
				if(dir[i]=='W') x[i]--;
			}
			REP(i, N) REP(j, N) if(i!=j && x[i]==x[j] && y[i]==y[j] && live[i] && live[j]) nlive[i]=nlive[j]=0;
			live=nlive;
		}
		return accumulate(ALL(live), 0);
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, AntsMeet().countAnts(x, y, direction));}
int main(){

CASE(0)
	int x_[] = {0,10,20,30};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,10,20,30};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	string direction = "NWNE"; 
	int _ = 2; 
END
CASE(1)
	int x_[] = {-10,0,0,10};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {0,-10,10,0};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	string direction = "NEWS"; 
	int _ = 0; 
END
CASE(2)
	int x_[] = {-1,-1,-1,0,0,0,1,1,1};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-1,0,1,-1,0,1,-1,0,1};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	string direction = "ESEWNNEWW"; 
	int _ = 4; 
END
CASE(3)
	int x_[] = {4,7,6,2,6,5,7,7,8,4,7,8,8,8,5,4,8,9,1,5,9,3,4,0,0,1,0,7,2,6,9,6,3,0,5,5,1,2,0,4,9,7,7,1,8,1,9,2,7,3};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {2,3,0,6,8,4,9,0,5,0,2,4,3,8,1,5,0,7,3,7,0,9,8,1,9,4,7,8,1,1,6,6,6,2,8,5,1,9,0,1,1,1,7,0,2,5,4,7,5,3};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	string direction = "SSNWSWSENSWSESWEWSWSENWNNNESWSWSWWSSWEEWWNWWWNWENN" ; 
	int _ = 25; 
END
CASE(4)
	int x_[] = {478,-664,759,434,-405,513,565,-396,311,-174,56,993,251,-341,993,-112,242,129,383,513,-78,-341,-148,129,423
,493,434,-405,478,-148,929,251,56,242,929,-78,423,-664,802,251,759,383,-112,-591,-591,-248,660,660,735,493};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-186,98,948,795,289,-678,948,-170,-195,290,-354,-424,289,-157,-166,150,706,-678,684,-294,-234,36,36,-294,-216
,-234,427,945,265,-157,265,715,275,715,-186,337,798,-170,427,706,754,961,286,-216,798,286,961,684,-424,337};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	string direction = "WNSNNSSWWWEENWESNSWSWSEWWEWEWWWNWESNSSNNSNNWWWNESE"; 
	int _ = 44; 
END
CASE(4)
	int x_[] = {478};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-186};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	string direction = "W"; 
	int _ = 1; 
END
CASE(4)
	int x_[] = {-1000, 1000};
	  vector <int> x(x_, x_+sizeof(x_)/sizeof(*x_)); 
	int y_[] = {-1000, 1000};
	  vector <int> y(y_, y_+sizeof(y_)/sizeof(*y_)); 
	string direction = "ES"; 
	int _ = 0; 
END

}
// END CUT HERE
