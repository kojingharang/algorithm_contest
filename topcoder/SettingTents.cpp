// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Once upon a time, there lived a migrant barbarian tribe.  Every time it settled down, a tent was set for the chief of the tribe.  First, an area was selected and divided into NxM squares with side lengths of 1 unit.  Then, they chose a site for the tent in such a way that every vertex of its base coincided with some vertex of one of the squares.  According to an ancient tradition, the base had to be a rhomb.  For example, there are all 6 different possible sites for the tent in a 2x2 area:



???
???

???
???



An example of a tent in a 4x2 area:


???




For a given N and M, return the number of different possible sites for the chief's tent.  Two sites are different if there is at least one vertex which belongs to one site but not the other.	



DEFINITION
Class:SettingTents
Method:countSites
Parameters:int, int
Returns:int
Method signature:int countSites(int N, int M)


NOTES
-A rhomb is a four-sided polygon with sides of equal length.
-The tent must have non-zero area.


CONSTRAINTS
-N will be between 1 and 100, inclusive.
-M will be between 1 and 100, inclusive.


EXAMPLES

0)
2
2

Returns: 6

The example from the problem statement.

1)
1
6

Returns: 6

The only possible sites are the squares of the area themselves.

2)
6
8

Returns: 527

*/
// END CUT HERE
#line 74 "SettingTents.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
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

int gcd ( int a, int b )
{
	if(a<b)
	{
		int tmp=a;
		a=b; b=tmp;
	}
	
	int c;
	while ( a != 0 ) {
	c = a; a = b%a;  b = c;
	}
	return b;
}


class SettingTents {
	public:
	int countSites(int N, int M) {
		int ans=0;
		for(int x0=0;x0<=200;x0++)
		for(int y0=0;y0<=200;y0++)
		for(int x1=0;x1<=200;x1+=2)
		for(int y1=0;y1<=200;y1+=2) {
			if(x0==x1&&y0==y1) continue;
			int x2=x0-(x1-x0);
			int y2=y0-(y1-y0);
			if(y2<-200||200<y2||x2<-200||200<x2) continue;
			int g=gcd(x1-x0, y1-y0);
			if(y1-y0==0) g=x1-x0;
			if(x1-x0==0) g=y1-y0;
			int dx=(x1-x0)/g;
			int dy=(y1-y0)/g;
			for(int i=-200;i<=200;i++) {
				int x3=x0+dy*i;
				int y3=y0+dx*i;
				if(x0==x3&&y0==y3) continue;
				if(y3<-200||200<y3||x3<-200||200<x3) continue;
				if(x3&1||y3&1) continue;
				int x4=x0-(x3-x0);
				int y4=y0-(y3-y0);
				if(y4<-200||200<y4||x4<-200||200<x4) continue;
				ans++;
				//cout<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<" "<<endl;
			}
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 6; verify_case(0, Arg2, countSites(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 6; int Arg2 = 6; verify_case(1, Arg2, countSites(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 8; int Arg2 = 527; verify_case(2, Arg2, countSites(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	SettingTents ___test;

	___test.run_test(-1);

}

// END CUT HERE
