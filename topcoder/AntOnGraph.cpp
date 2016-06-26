// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are given a directed graph with n vertices, labeled 0 to n-1. The edges of the graph contain values, and each time you traverse an edge, the value of that edge gets added to your total score. If the same edge is traversed multiple times, its value gets added every time. Values can be any number between -499 and 499, inclusive. There are no edges that connect a vertex to itself.

There's an ant at vertex 0 and it wants to get to vertex 1.  It must do this in an integer number of seconds between 1 and timeLimit, inclusive. The ant must make exactly stepsPerSecond steps each second, where each step consists of moving from its current vertex V to an adjacent vertex W (W is adjacent to V if there's a directed edge from V to W in the graph). The ant's goal is to get the highest score possible.

The graph is given as three vector <string>s p0, p1 and p2. Concatenate the j-th characters of the i-th elements of p0, p1 and p2 (in that order) to get a 3-digit String S. If S is "000", then there is no edge from vertex i to vertex j.  Otherwise, there is an edge from vertex i to vertex j, and its value is A - 500, where A is the integer value of S. For example, if S is "100", then the value is -400, and if S is "999", the value is 499.  Return the decimal representation of the highest possible score as a string with no extra leading zeroes.  If it is impossible to reach vertex 1 under the given constraints, return "IMPOSSIBLE" (quotes for clarity) instead.

DEFINITION
Class:AntOnGraph
Method:maximumBonus
Parameters:vector <string>, vector <string>, vector <string>, int, int
Returns:string
Method signature:string maximumBonus(vector <string> p0, vector <string> p1, vector <string> p2, int stepsPerSecond, int timeLimit)


CONSTRAINTS
-p0 will contain between 2 and 50 elements, inclusive.
-p1 and p2 will each contain the same number of elements as p0.
-Each element in p0, p1 and p2 will contain exactly n characters, where n is the number of elements in p0.
-Each character in p0, p1 and p2 will be a digit ('0'-'9').
-The i-th character of the i-th element of p0, p1 and p2 will be '0'.
-stepsPerSecond will be between 1 and 100, inclusive.
-timeLimit will be between 1 and 1000000000 (10^9), inclusive.


EXAMPLES

0)
{"05","50"}
{"00","00"}
{"01","10"}
3
2

Returns: "3"

Here, there are two vertices.  There's an edge from vertex 0 to vertex 1 and an edge from vertex 1 to vertex 0.  Both edges have a value of 1.  The ant must make exactly 3 steps per second, so during the first second, it will make the following moves: 0->1, 1->0, 0->1.  The time limit is 2, so there's time for 3 more moves.  However, that would place the ant back at vertex 0, so the ant should stop after the first second.

1)
{"05","50"}
{"00","00"}
{"01","10"}
2
3

Returns: "IMPOSSIBLE"

This is the same graph as the previous example, but this time, the ant must make exactly 2 steps per second.  The ant can therefore never reach vertex 1 because it will always return to vertex 0 after each second.

2)
{"0550","0000","0005","5000"}
{"0000","0000","0000","0000"}
{"0110","0000","0001","1000"}
7
9

Returns: "49"

In this case the ant can traverse cycle 0->2->3->0 and earn 3 points. The ant will keep moving along this cycle and finally go to vertex 1 and earn another point. Thus the number of points modulo 3 is 1. Among all multiple of 7 less than or equal to 63, 49 is the biggest one that satisfies the constraints.

3)
{"0540","0000","0004","4000"}
{"0090","0000","0009","9000"}
{"0190","0000","0009","9000"}
7
9

Returns: "-5"

This is the same as the previous example, but this time, the score for the cycle is -3.

4)
{"079269665406","506042219642","720809987956",
 "315099331918","952306192584","406390344278",
 "999241035142","370785209189","728363760165",
 "019367419000","279718007804","610188263490"}
{"038604914953","804585763146","350629473403",
 "028096403898","575205051686","427800322647",
 "655168017864","582553303278","980402170192",
 "620737714031","686142310509","092421645460"}
{"063231394554","109852259379","740182746422",
 "853015982521","476805512496","898530717993",
 "430534005863","440162807186","132879980431",
 "685312177072","780267345400","959947501200"}
37
1221

Returns: "20992235"



*/
// END CUT HERE
#line 97 "AntOnGraph.cpp"

#include <climits>
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
#define INF LLONG_MAX
#define VI vector<int>
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



typedef ll number;
//typedef double number;
typedef vector<number> array;
typedef vector<array> matrix;

// O( n )
matrix identity(int n) {
	matrix A(n, array(n));
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) A[i][j] = -INF;
	for (int i = 0; i < n; ++i) A[i][i] = 0;
	return A;
}
// O( n^3 )
matrix mul(const matrix &A, const matrix &B) {
	//matrix C(A.size(), array(B[0].size()));
	matrix C(A.size(), array(B[0].size(), -INF));
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j)
			for (int k = 0; k < A[i].size(); ++k) {
				//C[i][j] += A[i][k] * B[k][j];
				ll vv = A[i][k] + B[k][j];
				if(A[i][k]==-INF || B[k][j]==-INF) vv=-INF;
				C[i][j] = max(C[i][j], vv);
				//cout<<A[i][k] <<"  "<< B[k][j]<<"  "<<vv<<"  "<<C[i][j]<<endl;
			}
	return C;
}
// O( n^3 log e )
matrix pow(const matrix &A, int e) {
	return e == 0 ? identity(A.size()):
		 e % 2 == 0 ? pow(mul(A, A), e/2) : mul(A, pow(A, e-1));
}
std::ostream& operator<<(std::ostream& os, const matrix& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << "\n"; } return os; }


class AntOnGraph {
	public:
	string maximumBonus(vector <string> p0, vector <string> p1, vector <string> p2, int st, int tl) {
		int N = p0.size();
		matrix m(N, array(N));
		REP(i, N) {
			REP(j, N) {
				int v = atoi( (string("")+p0[i][j]+p1[i][j]+p2[i][j]).c_str() );
				if(v) m[i][j] = v-500;
				else  m[i][j] = -INF;
			}
		}
		matrix mm = pow(m, st);
		mm[1][1] = max(0LL, mm[1][1]);
		//cout<<m<<endl;
		//cout<<mm<<endl;
		matrix mmm = pow(mm, tl);
		//cout<<mmm<<endl;
		if(mmm[0][1]==-INF) return string("IMPOSSIBLE");
		stringstream s;
		s<<mmm[0][1];
		return s.str();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"05","50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00","00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"01","10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; int Arg4 = 2; string Arg5 = "3"; verify_case(0, Arg5, maximumBonus(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { string Arr0[] = {"05","50"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"00","00"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"01","10"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; int Arg4 = 3; string Arg5 = "IMPOSSIBLE"; verify_case(1, Arg5, maximumBonus(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { string Arr0[] = {"0550","0000","0005","5000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0000","0000","0000","0000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0110","0000","0001","1000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; int Arg4 = 9; string Arg5 = "49"; verify_case(2, Arg5, maximumBonus(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { string Arr0[] = {"0540","0000","0004","4000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"0090","0000","0009","9000"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"0190","0000","0009","9000"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; int Arg4 = 9; string Arg5 = "-5"; verify_case(3, Arg5, maximumBonus(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { string Arr0[] = {"079269665406","506042219642","720809987956",
 "315099331918","952306192584","406390344278",
 "999241035142","370785209189","728363760165",
 "019367419000","279718007804","610188263490"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"038604914953","804585763146","350629473403",
 "028096403898","575205051686","427800322647",
 "655168017864","582553303278","980402170192",
 "620737714031","686142310509","092421645460"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"063231394554","109852259379","740182746422",
 "853015982521","476805512496","898530717993",
 "430534005863","440162807186","132879980431",
 "685312177072","780267345400","959947501200"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 37; int Arg4 = 1221; string Arg5 = "20992235"; verify_case(4, Arg5, maximumBonus(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	AntOnGraph ___test;

	___test.run_test(-1);
	//___test.test_case_0();

}

// END CUT HERE
