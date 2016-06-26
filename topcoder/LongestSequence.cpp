// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Your task is to find the length of the longest sequence of real numbers that satisfies some conditions.


You are given a vector <int> C. Each element of C corresponds to one condition.

If C[i] is negative, the condition is:
"The sum of every consecutive -C[i] terms must be negative."

If C[i] is positive, the condition is:
"The sum of every consecutive C[i] terms must be positive."


You should return the maximal length of a sequence that satisfies all the conditions.
If there exists an infinitely long sequence that satisfies all the conditions, return -1.

DEFINITION
Class:LongestSequence
Method:maxLength
Parameters:vector <int>
Returns:int
Method signature:int maxLength(vector <int> C)


CONSTRAINTS
-C will contain between 1 and 50 elements, inclusive.
-Each element in C will be between -1,000 and 1,000, inclusive.
-All elements in C will be pairwise distinct.
-No element in C will be 0.


EXAMPLES

0)
{-2,3}

Returns: 3

The sequence {2, -3, 2} satisfies all the conditions and its length is 3.

It can be proved that there is no valid sequence with more terms.

1)
{524}

Returns: -1

Any infinite sequence in which all elements are positive satisfies all the conditions.

2)
{1, -1}

Returns: 0

No sequence with positive length can satisfy both conditions.

3)
{11,-7}

Returns: 16



4)
{-227,690,590,-524}

Returns: 713



*/
// END CUT HERE
#line 76 "LongestSequence.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
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

typedef vector<int> Edge;
typedef vector<Edge> Graph;

bool tsort(Graph& g, int i, vector<int>& status, vector<int>& topo) {
	//cout<<"visit "<<i<<endl;
	status[i]=1;
	for(int j=0;j<g[i].size();j++) {
		if(status[g[i][j]]==1) return false;
		if(!status[g[i][j]] && !tsort(g, g[i][j], status, topo)) return false;
	}
	topo.push_back(i);
	status[i]=2;
	return true;
}


bool tsort(Graph& g) {
	int vn = g.size();
	vector<int> status(vn, 0), topo;
	for(int i=0;i<vn;i++) {
		if(!status[i] && !tsort(g, i, status, topo)) return false;
	}
	//reverse(topo.begin(), topo.end());
	//for(int i=0;i<topo.size();i++) {
	//	cout<<topo[i]<<" ";
	//}
	//cout<<endl;
	return true;
}


class LongestSequence {
	public:
	int maxLength(vector <int> cst) {
		int cn = cst.size();
		if(*max_element(ALL(cst))<0 || *min_element(ALL(cst))>0) {
			return -1;
		}
		
		// S[i] = sum(A[0]..A[i])
		// sum(A[i-k+1]..A[i]) > 0 <==> S[i]-S[i-k] > 0
		// make edge i->j | S[i]>S[j]
		
		int low=0, high=10000;
		while(high-low>1) {
			int mid = (high+low)/2;
			Graph g(mid+1);
			
			// graph node 0..mid (mid+1)
			FOR(c, cst) {
				REP(i, mid+1-abs(*c)) {
					if(*c>0) g[i+abs(*c)].push_back(i);
					else    g[i].push_back(i+abs(*c));
				}
			}
			
			bool ret = tsort(g);
			//cout<<mid<<" "<<ret<<endl;
			if(ret) low=mid;
			else    high=mid;
		}
		return low;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, maxLength(Arg0)); }
	void test_case_1() { int Arr0[] = {524}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(1, Arg1, maxLength(Arg0)); }
	void test_case_2() { int Arr0[] = {1, -1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxLength(Arg0)); }
	void test_case_3() { int Arr0[] = {11,-7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(3, Arg1, maxLength(Arg0)); }
	void test_case_4() { int Arr0[] = {-227,690,590,-524}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 713; verify_case(4, Arg1, maxLength(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	LongestSequence ___test;

	___test.run_test(-1);

}

// END CUT HERE
