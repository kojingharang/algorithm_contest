// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Janusz is a young physicist.
He is currently playing with some electric circuits.

The simplest circuit consists of a single conductor (i.e., a single piece of wire).
Each such circuit is labeled using the string "X".

Janusz is using two different ways to connect two simpler circuits into one new, more complex circuit.
Note that these are not the standard two ways (connecting in series and in parallel), so read the following description carefully.

If Janusz uses the type-A connection, the resistance of the new circuit is the sum of the resistances of the two original circuits.
If Janusz uses the type-B connection, the resistance of the new circuit is the maximum of the resistances of the two original circuits.


Suppose that the two original circuits had labels C1 and C2.
Then we use the label "A"+C1+C2 for a new circuit constructed from them using the type-A connection, and the label "B"+C1+C2 if type-B connection was used.
For example, "AXX" is the label of the circuit obtained by using a type-A connection on two conductors.

You are given a string circuit with a valid label of a circuit.
You are also given a vector <int> conductors with as many elements as the number of occurrences of 'X' in circuit.
The elements of conductors are the resistances of all conductors you are going to use to construct the circuit described by circuit.
Each of the conductors can only be used once.
Each of the conductors can be used as each of the 'X's.
Return the largest possible resistance of the constructed circuit.


DEFINITION
Class:CircuitsConstruction
Method:maximizeResistance
Parameters:string, vector <int>
Returns:int
Method signature:int maximizeResistance(string circuit, vector <int> conductors)


NOTES
-There is no explicit constraint on the length of circuit. This is intentional, as it can be derived from the other constraints.


CONSTRAINTS
-Each character in circuit will be 'A', 'B', or 'X'.
-circuit will be a valid circuit label according to the problem statement.
-conductors will contain between 1 and 2,000 elements, inclusive.
-Each element of conductors will be between 1 and 100,000, inclusive.
-The number of occurrences of the character 'X' in circuit will be equal to the number of elements of conductors.


EXAMPLES

0)
"BXBXX"
{8, 2, 3}

Returns: 8

Regardless of the order in which we use the conductors, the final resistance will be the maximum of the resistances of our three conductors.

1)
"AAXXAXAXX"
{1, 1, 2, 8, 10}

Returns: 22

Regardless of the order in which we use the conductors, the final resistance will be the sum of the resistances of our five conductors.

2)
"AXBXX"
{8, 2, 3}

Returns: 11

One possible optimal solution looks as follows:

We take the conductors with resistance 2 and 3, and use a type-B connection to combine them into a new circuit.
We take the remaining conductor (with resistance 8) and the new circuit constructed in the previous step. We use a type-A connection to combine them into the resulting circuit.

The resistance of the circuit constructed in the first step is max(2,3) = 3.
The resistance of the whole circuit is 8 + 3 = 11, which is the largest value we can obtain.

3)
"BAAXBXXBXAXXBBAXXBXXAAXXX"
{17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30}

Returns: 454



******************************/
// END CUT HERE
#line 92 "CircuitsConstruction.cpp"
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

class CircuitsConstruction {
	public:
	int go(const string& C, int& i) {
		int v = 0;
		char c=C[i++];
		if(c=='X') {
			return 1;
		} else if(c=='A') {
			v = go(C, i);
			v += go(C, i);
		} else {
			v = go(C, i);
			v = max(v, go(C, i));
		}
		return v;
	}
	int maximizeResistance(string C, vector <int> Cs) {
		sort(ALLR(Cs));
		int i=0;
		return accumulate(Cs.begin(), Cs.begin()+go(C, i), 0);
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
#define END	 verify_case(_, CircuitsConstruction().maximizeResistance(circuit, conductors));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string circuit = "BXBXX"; 
	int conductors_[] = {8, 2, 3};
	  vector <int> conductors(conductors_, conductors_+sizeof(conductors_)/sizeof(*conductors_)); 
	int _ = 8; 
END
CASE(1)
	string circuit = "AAXXAXAXX"; 
	int conductors_[] = {1, 1, 2, 8, 10};
	  vector <int> conductors(conductors_, conductors_+sizeof(conductors_)/sizeof(*conductors_)); 
	int _ = 22; 
END
CASE(2)
	string circuit = "AXBXX"; 
	int conductors_[] = {8, 2, 3};
	  vector <int> conductors(conductors_, conductors_+sizeof(conductors_)/sizeof(*conductors_)); 
	int _ = 11; 
END
CASE(3)
	string circuit = "BAAXBXXBXAXXBBAXXBXXAAXXX"; 
	int conductors_[] = {17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30};
	  vector <int> conductors(conductors_, conductors_+sizeof(conductors_)/sizeof(*conductors_)); 
	int _ = 454; 
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
// param type: String
	string circuit; 
	{
		int N=UNIFORM_LL(1, 51);
		circuit = string(N, ' '); 
		string tb = "ABCDE";
		REP(i, N) {
			circuit[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
// param type: int
	vector <int> conductors; 
	{
		int N=UNIFORM_LL(1, 51);
		conductors = vector <int>(N); 
		REP(i, N) {
			conductors[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = CircuitsConstruction().maximizeResistance(circuit, conductors);
	int _1 = CircuitsConstructionRef().maximizeResistance(circuit, conductors);
	if(!verify_case(_0, _1, true)) {
print(circuit);
print(conductors);
	}
}
#endif

}
// END CUT HERE
