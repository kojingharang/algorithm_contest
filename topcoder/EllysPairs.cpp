// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// In one of her subjects at the university, Elly and her classmates have to prepare projects. The professor wants the students to work in pairs (groups of two). Each student must belong to exactly one pair and each pair should produce one project. You may assume that the number of people in the class is even.

You are given a vector <int> knowledge. Each element of knowledge is the amount of knowledge of one of the students. The quality of a project is the total knowledge of the students that work on it. That is, if students i and j form one of the pairs, the quality of their project will be knowledge[i] + knowledge[j].

This creates some problems. If there is a really strong group, their project will be of really high quality. The professor will then compare the other projects to it and will be disappointed by them, giving low grades to the other pairs. Thus, the students want to form the groups in such way that the difference between the quality of the best project and the quality of the worst project is as small as possible.

Return that minimal difference in the quality between the best and the worst project if the students split into pairs in the best possible way.

DEFINITION
Class:EllysPairs
Method:getDifference
Parameters:vector <int>
Returns:int
Method signature:int getDifference(vector <int> knowledge)


CONSTRAINTS
-knowledge will contain between 2 and 50 elements, inclusive.
-The number of elements of knowledge will be even.
-Each element of knowledge will be between 1 and 1000, inclusive.


EXAMPLES

0)
{2, 6, 4, 3}

Returns: 1

Here obviously grouping the two best people in the class (with knowledge 6 and 4) doesn't make sense.
If 6 pairs with 3 and 4 pairs with 2 they will get qualities of 9 and 6, respectively, leading to difference 3.
However, there is an even better grouping: 2 with 6 and 4 with 3 for qualities of 8 and 7, respectively. The difference then would be only 1.


1)
{1, 1, 1, 1, 1, 1}

Returns: 0

Some or even all students can have the same knowledge.

2)
{4, 2, 4, 2, 1, 3, 3, 7}

Returns: 2



3)
{5, 1, 8, 8, 13, 7, 6, 2, 1, 9, 5, 11, 3, 4}

Returns: 3



*/
// END CUT HERE
#line 62 "EllysPairs.cpp"

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



class EllysPairs {
	public:
	int getDifference(vector <int> K) {
		sort(ALL(K));
		int Min=1<<30,Max=0;
		REP(i, K.size()) {
			Min = min(Min, K[i]+K[K.size()-i-1]);
			Max = max(Max, K[i]+K[K.size()-i-1]);
		}
		return Max-Min;
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
#define END	 verify_case(_, EllysPairs().getDifference(knowledge));}
int main(){

CASE(0)
	int knowledge_[] = {2, 6, 4, 3};
	  vector <int> knowledge(knowledge_, knowledge_+sizeof(knowledge_)/sizeof(*knowledge_)); 
	int _ = 1; 
END
CASE(1)
	int knowledge_[] = {1, 1, 1, 1, 1, 1};
	  vector <int> knowledge(knowledge_, knowledge_+sizeof(knowledge_)/sizeof(*knowledge_)); 
	int _ = 0; 
END
CASE(2)
	int knowledge_[] = {4, 2, 4, 2, 1, 3, 3, 7};
	  vector <int> knowledge(knowledge_, knowledge_+sizeof(knowledge_)/sizeof(*knowledge_)); 
	int _ = 2; 
END
CASE(3)
	int knowledge_[] = {5, 1, 8, 8, 13, 7, 6, 2, 1, 9, 5, 11, 3, 4};
	  vector <int> knowledge(knowledge_, knowledge_+sizeof(knowledge_)/sizeof(*knowledge_)); 
	int _ = 3; 
END

}
// END CUT HERE
