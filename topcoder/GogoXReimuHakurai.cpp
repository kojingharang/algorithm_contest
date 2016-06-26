// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Like all other software engineers, Gogo likes to "read" virtual novels. In particular, he's currently "reading" a novel titled Touhou, with Reimu Hakurai as its main protagonist. There are N stages in Touhou, numbered 0 through N-1. A playthrough of the novel always starts at the stage 0. The playthrough then may visit some other stages, based on the player's choices. The sequence of visited stages is always strictly ascending. A playthrough is successful if it terminates by reaching the stage N-1.

In each stage, Gogo can either finish the playthrough or choose one of the available options that advance Reimu to other stages. You are given a vector <string> choices. If there is a choice that advances Reimu from stage i to stage j, choices[i][j] will be 'Y', otherwise it will be 'N'. For each pair of stages i, j such that i < j the game contains at most one such choice.

Gogo wants to make as many successful playthroughs as possible, one after another. However, there is an additional constraint: Each playthrough must contain at least one choice Gogo never made in any of the previous playthroughs.

Return the maximum number of successful playthroughs that Gogo can play. If there are no such playthrough, return 0.

DEFINITION
Class:GogoXReimuHakurai
Method:solve
Parameters:vector <string>
Returns:int
Method signature:int solve(vector <string> choices)


CONSTRAINTS
-choices will contain between 2 and 50 elements, inclusive.
-Each element of choices will contain N characters, where N is the number of elements in choices.
-Each character in choices will be either 'Y', or 'N'.
-If i >= j then choices[i][j] will be 'N'.


EXAMPLES

0)
{
"NYY",
"NNY",
"NNN"}

Returns: 2

The two possible successful playthroughs:
0 -> 1 -> 2
0 -> 2
Gogo may play them both, in any order.

1)
{
"NYNY",
"NNYY",
"NNNY",
"NNNN"}

Returns: 3



2)
{"NNY"
,"NNY"
,"NNN"}

Returns: 1



3)
{"NN"
,"NN"}

Returns: 0



*/
// END CUT HERE
#line 73 "GogoXReimuHakurai.cpp"

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
#define REP(i,n) for(int i=0,_n=(n);(i)<(int)_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

class GogoXReimuHakurai {
	public:
	int solve(vector<string> ch){
		int N=ch.size();
		VVI w(N, VI(N, 0)); // w[i][j] ... can reach i to j
		REP(i, N) REP(j, N) w[i][j]=ch[i][j]=='Y';
		REP(i, N) w[i][i]=1;
		REP(k, N) REP(i, N) REP(j, N) w[i][j] |= w[i][k]&w[k][j]; // floyd-warshall
		if(!w[0][N-1]) return 0;
		//cout<<w<<endl;
		
		int ans=0;
		REP(i, N) REP(j, N) if(w[0][i] && ch[i][j]=='Y' && w[j][N-1]) ans++;
		ans+=2;
		REP(i, N) if(w[0][i] && w[i][N-1]) ans--;
		return ans;
	}
	//int solve(vector<string> choices){ 
	//	int dp[60]; 
	//	bool flag[60]; 
	//	for(int i=0;i<60;i++){ 
	//		 dp[i]=0; 
	//		 flag[i]=false; 
	//	} 
	//	int n=choices.size(); 
	//	flag[n-1]=true; 
	//		
	//	for(int i=n-1;i>=0;i--){ 
	//		for(int j=i;j<n;j++){ 
	//			if(choices[i][j]=='Y'&&flag[j]){ 
	//				 flag[i]=true; 
	//				 break; 
	//			}	 
	//		} 
	//	} 
	//	dp[0]=1; 
	//		
	//	for(int i=0;i<n;i++){ 
	//		for(int j=i+1;j<n;j++){ 
	//			if(flag[j]&&choices[i][j]=='Y'){ 
	//				dp[j]+=dp[i]; 
	//				if(dp[i]!=0) dp[i]=1; 
	//			} 
	//		} 
	//	} 
	//	
	//	return dp[n-1];		 
	//}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
//	void test_case_0() { string Arr0[] = {
//"NYY",
//"NNY",
//"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_0() { string Arr0[] = {
"NYY",
"NNN",
"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arr0[] = {
"NYNY",
"NNYY",
"NNNY",
"NNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, solve(Arg0)); }
//	void test_case_1() { string Arr0[] = {
//"NYYYY",
//"NNYYY",
//"NNNYY",
//"NNNNY",
//"NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arr0[] = {
 "NNY"
,"NNY"
,"NNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arr0[] = {
 "NN"
,"NN"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, solve(Arg0)); }
//	void test_case_3() { string Arr0[] = {
//"NYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY",
//"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN"
//}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	GogoXReimuHakurai ___test;

	___test.run_test(-1);

}

// END CUT HERE
