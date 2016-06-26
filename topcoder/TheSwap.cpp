// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
There is nothing more beautiful than just an integer number.



You are given an integer n.  Write down n in decimal notation with no leading zeroes, and let M be the number of written digits.  Perform the following operation exactly k times:

Choose two different 1-based positions, i and j, such that 1 &lt= i &lt j &lt= M. Swap the digits at positions i and j.  This swap must not cause the resulting number to have a leading zero, i.e., if the digit at position j is zero, then i must be strictly greater than 1.




Return the maximal possible number you can get at the end of this procedure.  If it's not possible to perform k operations, return -1 instead.



DEFINITION
Class:TheSwap
Method:findMax
Parameters:int, int
Returns:int
Method signature:int findMax(int n, int k)


CONSTRAINTS
-n will be between 1 and 1,000,000, inclusive.
-k will be between 1 and 10, inclusive.


EXAMPLES

0)
16375
1

Returns: 76315

The optimal way is to swap 1 and 7.

1)
432
1

Returns: 423

In this case the result is less than the given number.

2)
90
4

Returns: -1

We can't make even a single operation because it would cause the resulting number to have a leading zero.

3)
5
2

Returns: -1

Here we can't choose two different positions for an operation.

4)
436659
2

Returns: 966354



*/
// END CUT HERE
#line 78 "TheSwap.cpp"

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


int memo[1000001][11];

string i2s(int v) { stringstream ss; ss<<v; return ss.str(); }
int s2i(string s) { int v; stringstream ss; ss<<s; ss>>v; return v; }

class TheSwap {
	public:
	int findMax(int n, int k) {
		memset(memo, 0, sizeof(memo));
		int N=i2s(n).size();
		memo[n][0]=1;
		REP(lo, k) {
			cout<<"= "<<lo<<endl;
			for(int mi=1;mi<=1000000;mi++) {
				//if(memo[mi][lo]) cout<<mi<<" "<<memo[mi][lo]<<endl;
				if(memo[mi][lo]) {
					string s(i2s(mi));
					if(s.size()<N) continue;
					cout<<s<<endl;
					REP(i, N) for(int j=i+1;j<N;j++) {
						if(i==0 && s[j]=='0') continue;
						string ss(s);
						swap(ss[i], ss[j]);
						//cout<<"  "<<s2i(ss)<<endl;
						memo[s2i(ss)][lo+1]=1;
					}
				}
			}
		}
		int cnt=0;
		for(int mi=1000000;mi>0;mi--) {
			REP(i, k) if(memo[mi][i]) { cnt++; cout<<mi<<endl; }
		}
		cout<<cnt<<endl;
		for(int mi=1000000;mi>0;mi--) {
			if(memo[mi][k]) return mi;
		}
		return -1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 16375; int Arg1 = 1; int Arg2 = 76315; verify_case(0, Arg2, findMax(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 432; int Arg1 = 1; int Arg2 = 423; verify_case(1, Arg2, findMax(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 90; int Arg1 = 4; int Arg2 = -1; verify_case(2, Arg2, findMax(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 2; int Arg2 = -1; verify_case(3, Arg2, findMax(Arg0, Arg1)); }
	//void test_case_4() { int Arg0 = 436659; int Arg1 = 2; int Arg2 = 966354; verify_case(4, Arg2, findMax(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 35766; int Arg1 = 10; int Arg2 = 76653; verify_case(4, Arg2, findMax(Arg0, Arg1)); }
	//void test_case_4() { int Arg0 = 1299; int Arg1 = 2; int Arg2 = 9921; verify_case(4, Arg2, findMax(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	TheSwap ___test;

	___test.run_test(-1);

}

// END CUT HERE
