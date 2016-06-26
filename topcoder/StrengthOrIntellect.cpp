// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Your character in a game has two properties: strength and intellect.  Initially, both are equal to 1.  There are several missions in the game, and to complete mission i, you must have strength of at least strength[i] or intellect of at least intellect[i].  After you complete mission i, you receive points[i] points that can be added to your properties.  You can distribute these points however you want between the two properties.  Each mission can be completed only once, and missions can be completed in any order.  Return the maximum number of missions you can complete.

DEFINITION
Class:StrengthOrIntellect
Method:numberOfMissions
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int numberOfMissions(vector <int> strength, vector <int> intellect, vector <int> points)


CONSTRAINTS
-strength will contain between 1 and 50 elements, inclusive.
-strength, intellect and points will contain the same number of elements.
-Each element of strength, intellect and points will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1, 2}
{1, 2}
{1, 2}

Returns: 2

Complete mission 0. After adding 1 point to either inlellect or strength you will be able to complete mission 1.

1)
{3}
{2}
{1}

Returns: 0

Only one mission and you can't complete it.

2)
{1, 3, 1, 10, 3}
{1, 1, 3, 20, 3}
{2, 1, 1, 5, 1}

Returns: 4



3)
{1, 2, 100, 5, 100, 10, 100, 17, 100}
{1, 100, 3, 100, 7, 100, 13, 100, 21}
{1, 2, 3, 4, 5, 6, 7, 8, 1}

Returns: 9



4)
{1, 10, 1, 2, 16, 12, 13, 19, 12, 8}
{1, 5, 1, 8, 3, 5, 3, 16, 19, 20}
{1, 1, 1, 2, 1, 1, 2, 3, 5, 1}

Returns: 7



*/
// END CUT HERE
#line 70 "StrengthOrIntellect.cpp"

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


//struct state {
//	int p0, p1, p2;
//	vector <int> st, in, po;
//	state(int p0, int p1, int p2, vector <int> st, vector <int> in, vector <int> po):
//		p0(p0), p1(p1), p2(p2), st(st), in(in), po(po) {}
//	bool operator<(const state& s) const {
//		if(p0<s.p0 || p1<s.p1 || p2<s.p2 || st<s.st || in<s.in || po<s.po) return true;
//		return false;
//	}
//};
struct state {
	ll use;
	int p0, p1, p2;
	state(ll use, int p0, int p1, int p2):
		use(use), p0(p0), p1(p1), p2(p2) {}
	bool operator<(const state& s) const {
		if(use<s.use || p0<s.p0 /*|| p1<s.p1 || p2<s.p2*/) return true;
		return false;
	}
};

//map<state, int> memo;
map<pair<ll, int>, int> memo;
VI S,I,P;
int N, ans;

class StrengthOrIntellect {
	public:
	int numberOfMissions(vector <int> st, vector <int> in, vector <int> po) {
		S=st; I=in; P=po;
		N=S.size();
		memo.clear();
		ans=0;
		f(0, 1, 1, 0);
		cout<<memo.size()<<endl;
		return ans;
	}
	
	void f(ll use, int p0, int p1, int p2) {
		//state s(use, p0, p1, p2);
		pair<ll, int> key(use, p0);
		if(memo.count(key)&&p1<=memo[key]) return;
		
		//cout<<"f "<<use<<" "<<p0<<" "<<p1<<" "<<p2<<endl;
		//int ans=0;
		REP(i, N) {
			if(use&1LL<<i) continue;
			if(S[i]<=p0 || I[i]<=p1) {
				//ans++;
				p2+=P[i];
				use |= 1LL<<i;
			}
		}
		int co=0; ll _co=use;
		while(_co) { co+=_co&1; _co>>=1; }
		ans=max(ans, co);
		//cout<<ans<<"  "<<p2<<endl;
		//cout<<st<<endl;
		//cout<<in<<endl;
		//cout<<po<<endl;
		//int lans=0;
		REP(i, N) {
			if(use&1LL<<i) continue;
			//if(p2-(S[i]-p0)>=0) lans = max(lans, f(use|1LL<<i, S[i], p1, p2-(S[i]-p0)+P[i])+1);
			//if(p2-(I[i]-p1)>=0) lans = max(lans, f(use|1LL<<i, p0, I[i], p2-(I[i]-p1)+P[i])+1);
			if(p2-(S[i]-p0)>=0) f(use|1LL<<i, S[i], p1, p2-(S[i]-p0)+P[i]);
			if(p2-(I[i]-p1)>=0) f(use|1LL<<i, p0, I[i], p2-(I[i]-p1)+P[i]);
		}
		//memo[s] = ans+lans;
		memo[key] = p1;
		//return ans+lans;
		return;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 3, 1, 10, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 3, 20, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 1, 1, 5, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(2, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 2, 100, 5, 100, 10, 100, 17, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 100, 3, 100, 7, 100, 13, 100, 21}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; verify_case(3, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
	//void test_case_4() { int Arr0[] = {1, 10, 1, 2, 16, 12, 13, 19, 12, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 5, 1, 8, 3, 5, 3, 16, 19, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 2, 1, 1, 2, 3, 5, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(4, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {25, 58, 19, 14, 34, 1, 62, 2, 38, 15, 12, 1, 8, 58, 50, 26, 21, 27, 1, 26, 9, 8, 15, 43, 42, 39, 19, 30, 61}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
	int Arr1[] = {17, 3, 14, 30, 47, 1, 13, 23, 2, 25, 16, 18, 31, 7, 8, 31, 41, 6, 1, 36, 35, 27, 9, 8, 36, 5, 43, 16, 39}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
	int Arr2[] = {4, 3, 4, 3, 2, 4, 2, 3, 2, 2, 5, 3, 1, 5, 2, 5, 3, 3, 3, 4, 2, 2, 1, 5, 3, 2, 2, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
	int Arg3 = 29; verify_case(4, Arg3, numberOfMissions(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	StrengthOrIntellect ___test;

	___test.run_test(-1);
	//___test.test_case_2();

}

// END CUT HERE
