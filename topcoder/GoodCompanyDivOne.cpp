// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Shiny has a company.
There are N employees in her company.
The employees are numbered 0 through N-1 in order in which they joined the company.

Employee 0 is the only employee with no boss.
Every other employee has precisely one direct boss in the company.
You are given a vector <int> superior with N elements.
Element 0 of superior will be -1 to denote that employee 0 has no boss.
For each i between 1 and N-1, inclusive, element i of superior will be the number of the boss of employee i.

For each employee, their boss joined the company before them.
Formally, for each i between 1 and N-1, inclusive, superior[i] will be between 0 and i-1, inclusive.

At the moment, the employees of Shiny's company cannot do anything useful.
Shiny would like to change this.
She decided that she will pay for the employees' training.
More precisely, each employee will be trained to do two different types of work.
(The two types of work may be different for different employees.)

There are K types of work for which training is available.
You are given a vector <int> training with K elements.
For each i, training[i] is the cost of training any single employee to do work of type i.
If multiple employees are trained to do the same work type, Shiny must pay for each of them separately.

Each employee of the company has their own department.
The department of employee x is formed by employee x and all the employees such that x is their boss.
Formally, for any y different from x, employee y belongs into the department of employee x if and only if superior[y]=x.
Note that if superior[z]=y and superior[y]=x, employee z does not belong into the department of employee x.

Shiny likes diverse departments.
A department is diverse if:

Each employee in the department is doing something, and
no two employees in the department are doing the same type of work.


When Shiny comes to inspect a department, the employees in the department try to choose their work so that the department will be diverse.
If they can do that, Shiny says that the department is good.

Shiny considers her company good if all N departments are good.
(Note that the departments are not required to be diverse at the same time. A company is good as soon as each of its departments can be diverse at some point in time.)

Shiny now wants to choose, for each employee, the two work types they will be trained to do.
Shiny wants to have a good company, and also to spend as little money as possible.

If it is possible for Shiny to have a good company, return the smallest possible total amount of money spent on training the employees.
If it is impossible, return -1 instead.



DEFINITION
Class:GoodCompanyDivOne
Method:minimumCost
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minimumCost(vector <int> superior, vector <int> training)


NOTES
-Each employee must learn to perform exactly two different work types (even though they might never need to do one of those two types of work).


CONSTRAINTS
-superior will contain between 1 and 30 elements, inclusive.
-superior[0] will be -1.
-For each valid i>0, superior[i] will be between 0 and i-1, inclusive.
-training will contain between 2 and 30 elements, inclusive.
-Each element of training will be between 1 and 100, inclusive.


EXAMPLES

0)
{-1}
{1, 2}

Returns: 3

There is only one employee (employee 0) and two work types. Employee 0 has to be trained to do both work types. This costs 1+2 = 3. After the training, the company is clearly good.

1)
{-1, 0, 0}
{1, 2, 3}

Returns: 10

One optimal solution:

Employee 0 learns work types 0 and 1 which costs 1+2 = 3.
Employee 1 learns work types 0 and 1 which costs 1+2 = 3.
Employee 2 learns work types 0 and 2 which costs 1+3 = 4.

The total cost is 3+3+4 = 10.
The company is now good because:

The department of employee 0 is formed by employees 0, 1, and 2. This department is good because they can choose work types 0, 1, and 2, respectively.
The department of employee 1 is formed only by employee 1 and it is clearly good.
The department of employee 2 is formed only by employee 2 and it is clearly good.



2)
{-1, 0, 0, 0}
{1, 2, 3}

Returns: -1

There are only three work types, but there are four employees in employee 0's department.
Therefore, this department can never be good.

3)
{-1, 0, 0, 2, 2, 2, 1, 1, 6, 0, 5, 4, 11, 10, 3, 6, 11, 7, 0, 2, 13, 14, 2, 10, 9, 11, 22, 10, 3}
{4, 2, 6, 6, 8, 3, 3, 1, 1, 5, 8, 6, 8, 2, 4}

Returns: 71



******************************/
// END CUT HERE
#line 126 "GoodCompanyDivOne.cpp"
#include <vector>
#include <map>
#include <set>
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
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cassert>
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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

class GoodCompanyDivOne {
	public:
	vector <int> S, T;
	int f(int idx, int type) {
		int ti=-1;
		int sum=0, csum=0;
		
//		cout<<"f "<<idx<<endl;
		REP(i, S.size()) {
			if(S[i]==idx) {
				int learn = ti+1==type ? ti+2 : ti+1;
				if(learn>=T.size()) return -1;
//				cout<<"f child "<<idx<<" "<<i<<" "<<learn<<endl;
				ti = learn;
				sum += T[learn==0?1:0]+T[learn];
				
				int cost = f(i, learn);
				if(cost==-1) return -1;
				csum += cost;
			}
		}
//		cout<<"f "<<idx<<" sum csum "<<sum<<" "<<csum<<endl;
		return sum+csum;
	}
	int minimumCost(vector <int> _S, vector <int> _T) {
		S=_S;
		T=_T;
		sort(ALL(T));
		if(T.size()<2) return -1;
		int v = f(0, 0);
		if(v==-1) return -1;
		return T[0]+T[1]+v;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, GoodCompanyDivOne().minimumCost(superior, training));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(2)
	int superior_[] = {-1, 0, 0, 0};
	  vector <int> superior(superior_, superior_+sizeof(superior_)/sizeof(*superior_)); 
	int training_[] = {1, 2, 3};
	  vector <int> training(training_, training_+sizeof(training_)/sizeof(*training_)); 
	int _ = -1; 
END
//return 0;
CASE(0)
	int superior_[] = {-1};
	  vector <int> superior(superior_, superior_+sizeof(superior_)/sizeof(*superior_)); 
	int training_[] = {1, 2};
	  vector <int> training(training_, training_+sizeof(training_)/sizeof(*training_)); 
	int _ = 3; 
END
CASE(1)
	int superior_[] = {-1, 0, 0};
	  vector <int> superior(superior_, superior_+sizeof(superior_)/sizeof(*superior_)); 
	int training_[] = {1, 2, 3};
	  vector <int> training(training_, training_+sizeof(training_)/sizeof(*training_)); 
	int _ = 10; 
END
//return 0;
CASE(2)
	int superior_[] = {-1, 0, 0, 0};
	  vector <int> superior(superior_, superior_+sizeof(superior_)/sizeof(*superior_)); 
	int training_[] = {1, 2, 3};
	  vector <int> training(training_, training_+sizeof(training_)/sizeof(*training_)); 
	int _ = -1; 
END
CASE(3)
	int superior_[] = {-1, 0, 0, 2, 2, 2, 1, 1, 6, 0, 5, 4, 11, 10, 3, 6, 11, 7, 0, 2, 13, 14, 2, 10, 9, 11, 22, 10, 3};
	  vector <int> superior(superior_, superior_+sizeof(superior_)/sizeof(*superior_)); 
	int training_[] = {4, 2, 6, 6, 8, 3, 3, 1, 1, 5, 8, 6, 8, 2, 4};
	  vector <int> training(training_, training_+sizeof(training_)/sizeof(*training_)); 
	int _ = 71; 
END
#if 0  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: int
	vector <int> superior; 
	{
		int N=UNIFORM_LL(1, 51);
		superior = vector <int>(N); 
		REP(i, N) {
			superior[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> training; 
	{
		int N=UNIFORM_LL(1, 51);
		training = vector <int>(N); 
		REP(i, N) {
			training[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = GoodCompanyDivOne().minimumCost(superior, training);
	int _1 = GoodCompanyDivOneRef().minimumCost(superior, training);
	if(!verify_case(_0, _1, true)) {
print(superior);
print(training);
	}
}
#endif

}
// END CUT HERE
