// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// King Dengklek has two N-sided dice. The dice are not necessarily equal. Each of the dice is fair: when rolled, each side will come up with probability 1/N. Some time ago, each side of each die was labeled by a positive integer between 1 and X, inclusive. The labels were all unique. In other words, exactly 2*N distinct integers were used to label the sides of the two dice.

King Dengklek has been playing with the first die for a long time. Therefore, some of its labels were scratched off. The corresponding sides of the die are now empty. The second die still has all of its labels.

The current labels on the first die are given in the vector <int> firstDie: if the i-th side has no label, firstDie[i] is 0, otherwise firstDie[i] is the label. The current labels on the second die are given in secondDie: the i-th side of the second die has the label secondDie[i].

In King Dengklek's favorite game, he takes one of the dice, his opponent takes the other, and they each roll the die they have. The one who throws a larger number is the winner. King Dengklek wants to fill in the missing labels on the first die. His goal is to fill them in such a way that his favorite game becomes as fair as possible.

When filling in the missing labels, King Dengklek wants to preserve the two properties mentioned above: first, each integer between 1 and X, inclusive, may only occur at most once on the two dice. Second, no other labels may be used. However, there is an exception to the second rule: King Dengklek is also allowed to use the label 0. Moreover, he may even use this label multiple times.

You are given the vector <int>s firstDie and secondDie, and the int X. For a particular way to fill in the missing labels, let P be the probability that the player with the first die wins in the king's game. Find the labeling that minimizes the value |P - 0.5| and return the corresponding value of P. If there are two possible solutions, return the smaller one.

DEFINITION
Class:KingdomAndDice
Method:newFairness
Parameters:vector <int>, vector <int>, int
Returns:double
Method signature:double newFairness(vector <int> firstDie, vector <int> secondDie, int X)


NOTES
-Your return value must have a relative or an absolute error of less than 1e-9.
-|x| denotes the the absolute value of x. For example, |3| = |-3| = 3.


CONSTRAINTS
-firstDie and secondDie will contain the same number of elements, between 2 and 50, inclusive.
-X will be between 2*N and 1,000,000,000, inclusive, where N is the number of elements in firstDie.
-Each element of firstDie will be between 0 and X, inclusive.
-Each element of secondDie will be between 1 and X, inclusive.
-Each integer between 1 and X, inclusive, will occur at most once in firstDie and secondDie together.


EXAMPLES

0)
{0, 2, 7, 0}
{6, 3, 8, 10}
12

Returns: 0.4375

One possible solution is to relabel the first die into {4, 2, 7, 11}. The probability of winning against the second die will be 7/16.

1)
{0, 2, 7, 0}
{6, 3, 8, 10}
10

Returns: 0.375

One possible solution is to relabel the first die into {9, 2, 7, 5}. The probability of winning against the second die will be 3/8.

2)
{0, 0}
{5, 8}
47

Returns: 0.5

One possible solution is to relabel the first die into {10, 0}.

3)
{19, 50, 4}
{26, 100, 37}
1000

Returns: 0.2222222222222222

The first die does not have any missing labels.

4)
{6371, 0, 6256, 1852, 0, 0, 6317, 3004, 5218, 9012}
{1557, 6318, 1560, 4519, 2012, 6316, 6315, 1559, 8215, 1561}
10000

Returns: 0.49



*/
// END CUT HERE
#line 87 "KingdomAndDice.cpp"

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
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class KingdomAndDice {
	public:
	double newFairness(vector <int> firstDie, vector <int> secondDie, int X) {
		
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
void verify_case(const double& Expected, const double& Received) {
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, KingdomAndDice().newFairness(firstDie, secondDie, X));}
int main(){

CASE(0)
	int firstDie_[] = {0, 2, 7, 0};
	  vector <int> firstDie(firstDie_, firstDie_+sizeof(firstDie_)/sizeof(*firstDie_)); 
	int secondDie_[] = {6, 3, 8, 10};
	  vector <int> secondDie(secondDie_, secondDie_+sizeof(secondDie_)/sizeof(*secondDie_)); 
	int X = 12; 
	double _ = 0.4375; 
END
CASE(1)
	int firstDie_[] = {0, 2, 7, 0};
	  vector <int> firstDie(firstDie_, firstDie_+sizeof(firstDie_)/sizeof(*firstDie_)); 
	int secondDie_[] = {6, 3, 8, 10};
	  vector <int> secondDie(secondDie_, secondDie_+sizeof(secondDie_)/sizeof(*secondDie_)); 
	int X = 10; 
	double _ = 0.375; 
END
CASE(2)
	int firstDie_[] = {0, 0};
	  vector <int> firstDie(firstDie_, firstDie_+sizeof(firstDie_)/sizeof(*firstDie_)); 
	int secondDie_[] = {5, 8};
	  vector <int> secondDie(secondDie_, secondDie_+sizeof(secondDie_)/sizeof(*secondDie_)); 
	int X = 47; 
	double _ = 0.5; 
END
CASE(3)
	int firstDie_[] = {19, 50, 4};
	  vector <int> firstDie(firstDie_, firstDie_+sizeof(firstDie_)/sizeof(*firstDie_)); 
	int secondDie_[] = {26, 100, 37};
	  vector <int> secondDie(secondDie_, secondDie_+sizeof(secondDie_)/sizeof(*secondDie_)); 
	int X = 1000; 
	double _ = 0.2222222222222222; 
END
CASE(4)
	int firstDie_[] = {6371, 0, 6256, 1852, 0, 0, 6317, 3004, 5218, 9012};
	  vector <int> firstDie(firstDie_, firstDie_+sizeof(firstDie_)/sizeof(*firstDie_)); 
	int secondDie_[] = {1557, 6318, 1560, 4519, 2012, 6316, 6315, 1559, 8215, 1561};
	  vector <int> secondDie(secondDie_, secondDie_+sizeof(secondDie_)/sizeof(*secondDie_)); 
	int X = 10000; 
	double _ = 0.49; 
END

}
// END CUT HERE
