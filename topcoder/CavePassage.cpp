// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Several travelers are standing at the entrance of a dark cave.  The travelers must all pass through the cave and stand together at the exit.  Unfortunately, a variety of circumstances can make it impossible for them to all pass through the cave together at the same time.  Therefore, they may have to take turns going through the cave in smaller groups.  There is only one map though, and it is impossible to navigate the cave without it, so whenever a group of travelers is inside the cave, one member of that group must be holding the map.
When a group of travelers walks through the cave, either from the entrance or the exit, they must traverse an old bridge to get to the other side of the cave.  The entire group inside the cave must cross the bridge together at the same time.  The bridge cannot hold more than bridgeStrength kilograms, or it will collapse.  You are given a vector <int> travelersWeights, where the i-th element is the weight of the i-th traveler in kilograms.
Travelers may walk through the cave alone. Although, when travelers walk through the cave in a group of two or more, each traveler must trust at least one of the other travelers in the group. You are given a vector <string> trustTable, where the j-th character of the i-th element is 'Y' if traveler i trusts traveler j, and 'N' otherwise.  Note that the trust relation is not necessarily symmetric.
Travelers walk at different speeds, but when they go through the cave, they must stick together and walk at the same speed.  Therefore, when a group of travelers walks through the cave, they must walk at the speed of the slowest traveler in the group.  You are given a vector <int> travelersTimes, where the i-th element is the amount of time it takes the i-th traveler to walk through the cave in any direction.
Return the minimal total time required for all the travelers to end up together at the exit of the cave.  If it is impossible, return -1 instead.

DEFINITION
Class:CavePassage
Method:minimalTime
Parameters:vector <int>, vector <int>, vector <string>, int
Returns:int
Method signature:int minimalTime(vector <int> travelersWeights, vector <int> travelersTimes, vector <string> trustTable, int bridgeStrength)


CONSTRAINTS
-travelersWeights will contain between 1 and 13 elements, inclusive.
-Each element of travelersWeights will be between 1 and 1000, inclusive.
-travelersTimes will contain the same number of elements as travelersWeights.
-Each element of travelersTimes will be between 1 and 1000, inclusive.
-trustTable will contain the same number of elements as travelersWeights.
-Each element of trustTable will contain exactly n characters, where n is the number of elements in trustTable.
-Each element of trustTable will contain only uppercase letters 'Y' and 'N'.
-The i-th character of the i-th element of trustTable will always be 'Y'.
-bridgeStrength will be between 1 and 5000, inclusive.


EXAMPLES

0)
{ 1, 1, 1 }
{ 2, 3, 4 }
{ "YYY", "YYY", "YYY" }
2

Returns: 9

The travelers can achieve the goal as follows.  First, traveler 0 and traveler 2 go through the cave together.  It normally takes 2 time units for traveler 0 to go through the cave, and it takes 4 time units for traveler 2.  Since they are traveling together in a group, they must walk at the speed of the slower traveler.  So, after 4 time units, both travelers are at the exit.  Then, traveler 0 takes the map and goes back through the cave to the entrance.  This time, it only takes 2 time units because he is alone.  Finally, traveler 0 and traveler 1 go through the cave together in 3 time units and all the travelers end up together at the exit.  The total time is 4 + 2 + 3 = 9.

1)
{ 1, 1, 1 }
{ 2, 3, 4 }
{ "YYY", "YYY", "NYY" }
2

Returns: 10

Here things become a little bit more complicated, because traveler 2 doesn't trust traveler 0.

2)
{ 1, 1, 1 }
{ 7, 13, 19 }
{ "YYN", "NYY", "YNY" }
3

Returns: 19



3)
{ 43 }
{ 23 }
{ "Y" }
42

Returns: -1



*/
// END CUT HERE
#line 75 "CavePassage.cpp"

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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }


int N;
int memo[1<<13];
vector <int> WE;
vector <int> TI;
vector <string> TR;
int bS;

#define INF 10000000
int f(int pat) {
	if(pat==0) return 0;
	//if(memo[pat]) return memo[pat];
	
	cout<<"f "<<pat<<endl;
	int mem[13];
	int ans = INF;
	REP(p, 1<<N) {
		if((pat&p)!=p) continue;
		int co=0;
		REP(i, N) {
			if(p&1<<i) {
				mem[co]=i;
				co++;
			}
		}
		if(co==0) continue;
		if((pat&~p)>0 && co==1) continue;
		
		REP(i, co) {
			//cout<<mem[i]<<" ";
		}
		int ok=1;
		int slo=0;
		int w=0;
		REP(i, co) {
			w+=WE[mem[i]];
			int lok=0;
			//cout<<TR[mem[i]]<<endl;
			REP(j, co) lok|=TR[mem[i]][mem[j]]=='Y'&&i!=j;
			if(lok==0) {ok=0;break;}
			slo=max(slo, TI[mem[i]]);
		}
		//cout<<" co "<<co<<" p "<<p<<" slo "<<slo<<endl;
		//cout<<"w "<<w<<" ok "<<ok<<endl;
		if(ok && w<=bS) {
			REP(fi, co) {
				int lans = (pat&~p) == 0 ? slo : f(pat&~p|1<<fi)+slo+TI[fi];
				ans=min(ans, lans);
			}
		}
	}
	cout<<"f "<<pat<<" -> "<<ans<<endl;
	return memo[pat]=ans;
}

class CavePassage {
	public:
	int minimalTime(vector <int> _WE, vector <int> _TI, vector <string> _TR, int _bS) {
		WE=_WE; TI=_TI; TR=_TR; bS=_bS;
		memset(memo, 0, sizeof(memo));
		N=WE.size();
		int ans = f((1<<N)-1);
		return ans==INF ? -1 : ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = { 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "YYY", "YYY", "YYY" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 9; verify_case(0, Arg4, minimalTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = { 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 2, 3, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "YYY", "YYY", "NYY" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 10; verify_case(1, Arg4, minimalTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = { 1, 1, 1 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 7, 13, 19 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "YYN", "NYY", "YNY" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 19; verify_case(2, Arg4, minimalTime(Arg0, Arg1, Arg2, Arg3)); }
	//void test_case_3() { int Arr0[] = { 43 }; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 23 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { "Y" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 42; int Arg4 = -1; verify_case(3, Arg4, minimalTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() {
		int Arr0[] = {3, 3, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
		int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
		string Arr2[] = {"YYY", "YYY", "YYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0])));
		int Arg3 = 6; 
		int Arg4 = 5; verify_case(3, Arg4, minimalTime(Arg0, Arg1, Arg2, Arg3)); }

//{{3, 3, 6}, {1, 1, 1}, {"YYY", "YYY", "YYY"}, 6}

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	CavePassage ___test;

	___test.run_test(-1);

}

// END CUT HERE
