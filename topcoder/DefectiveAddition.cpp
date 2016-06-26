// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Cucumber Boy is very young.  He is too young for base 10, so he does all his calculations in base 2.  Additionally, he did not learn to add yet. When adding two numbers, he always forgets to do the carries, he just adds each digit independently. As you probably guessed already, the result of his calculation is in fact the bitwise xor of the two input numbers. For example, for Cucumber Boy 1+1 is 0, 1+2 is 3, 2+3 is 1, and 4+7 is 3. (All the numbers in this example are in base 10.)

Cucumber Boy has a sequence of cards.  Each card contains a positive integer. You are given a vector <int> cards containing those integers.

You are also given a int n. Cucumber Boy wants to choose a sequence of integers b with the following properties:

For each i, the integer b[i] is greater than or equal to 0.
For each i, the integer b[i] is less than or equal to cards[i].
The "Cucumber Boy sum" (i.e., the bitwise xor) of all elements of the sequence b is equal to n.


Return the number of such sequences, modulo 1,000,000,007.

DEFINITION
Class:DefectiveAddition
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> cards, int n)


CONSTRAINTS
-cards will contain between 1 and 50 elements, inclusive.
-Each element of cards will be between 1 and 1,000,000,000, inclusive.
-n will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{2,3}
2

Returns: 3

Cucumber Boy can choose 12 different sequences: b[0] can be between 0 and 2, inclusive, and b[1] can be between 0 and 3, inclusive.
Out of those 12 sequences, 3 have the required "Cucumber Boy sum": 0+2 = 2, 1+3 = 2, and 2+0 = 2.

1)
{1,2,3}
1

Returns: 6

The six good sequences are (0,0,1), (0,1,0), (0,2,3), (1,0,0), (1,1,1), and (1,2,2).

2)
{4, 5, 7, 11}
6

Returns: 240



3)
{1,2,3,4,5,6,7,8,9,10}
15

Returns: 1965600



4)
{1,2,3,4,5,6,7,8,9,10}
16

Returns: 0



5)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
1

Returns: 949480669



*/
// END CUT HERE
#line 85 "DefectiveAddition.cpp"

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



class DefectiveAddition {
	public:
	int count(vector <int> cards, int n) {
		
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
#define END	 verify_case(_, DefectiveAddition().count(cards, n));}
int main(){

CASE(0)
	int cards_[] = {2,3};
	  vector <int> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	int n = 2; 
	int _ = 3; 
END
CASE(1)
	int cards_[] = {1,2,3};
	  vector <int> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	int n = 1; 
	int _ = 6; 
END
CASE(2)
	int cards_[] = {4, 5, 7, 11};
	  vector <int> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	int n = 6; 
	int _ = 240; 
END
CASE(3)
	int cards_[] = {1,2,3,4,5,6,7,8,9,10};
	  vector <int> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	int n = 15; 
	int _ = 1965600; 
END
CASE(4)
	int cards_[] = {1,2,3,4,5,6,7,8,9,10};
	  vector <int> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	int n = 16; 
	int _ = 0; 
END
CASE(5)
	int cards_[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	  vector <int> cards(cards_, cards_+sizeof(cards_)/sizeof(*cards_)); 
	int n = 1; 
	int _ = 949480669; 
END

}
// END CUT HERE
