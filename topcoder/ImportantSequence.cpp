// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
This problem statement contains superscripts and/or subscripts. It may not display properly outside the applet.

Little Rudolph had an important sequence of positive integers. The sequence consisted of N positive integers a0, a1, .., aN-1.

Rudolph wrote the sequence onto the blackboard in the classroom. While Rudolph had gone out, little Arthur came into the classroom and saw the sequence. Arthur likes to play with numbers as much as he likes to give his friends puzzles. So he did the following:

First, he wrote a '+' or a '-' between each pair of consecutive numbers (possibly using different signs for different pairs of numbers).
	
Next, for each sign he computed the result of the corresponding operation and wrote it under the sign.
I.e., if he used the '+' sign between ai and ai+1, he would write the sum ai+ai+1 under this '+' sign.
Similarly, if he used the '-' sign between ai and ai+1, he would write the difference ai-ai+1. In this way he obtained a new sequence of N-1 numbers b0, b1, .., bN-2.
Finally, he erased the original sequence. Now there was only the operator sequence o0, o1, .., oN-2 and the resulting number sequence b0, b2, .., bN-2 left on the blackboard.

For example, if the original sequence was {1, 2, 3, 4}, and Arthur wrote operators {+, -, +}, then the content of the blackboard changed like this:

1   2   3   4    ->    1 + 2 - 3 + 4    ->    1 + 2 - 3 + 4    ->     +  -  +
                                                3  -1   7             3 -1  7

When Rudolph returned, he was shocked as his important sequence had disappeared. Arthur quickly told him what operations he had performed and that Rudolph has to simply reconstruct the orginal sequence.

Unfortunately, little Arthur did not realize that it is not necessarily possible to determine the original sequence uniquely. For example, both original sequences {1, 2, 3, 4} and {2, 1, 2, 5} lead to the same sequence {3, -1, 7} when operator sequence is {+, -, +}.

The only thing Rudolph remembers about his original sequence is that all the integers were positive. Rudolph now wants to count all sequences of positive integers that match the blackboard. You are given vector <int> B and string operators  both containing N-1 elements. The i-th element of B is the number bi and i-th element of operators will be '+' or '-', meaning that the i-th operator is + or -, respectively. Return the number of different positive integer sequences A that lead to sequence B when operators operators are used in the way described. If there are infinitely many such sequences, return -1. Note that there may be test cases where no valid sequence A exists. For such test cases the correct return value is 0.

DEFINITION
Class:ImportantSequence
Method:getCount
Parameters:vector <int>, string
Returns:int
Method signature:int getCount(vector <int> B, string operators)


NOTES
-It is guaranteed that the correct answer will always fit into the 32-bit signed integer type.
-The integer 0 (zero) is not positive. It may not occur in Rudolph's original sequence.


CONSTRAINTS
-B will contain between 1 and 50 elements, inclusive.
-operators will contain the same number of characters as the number of elements in B.
-Each element of B will be between -1000000000 (-109) and 1000000000 (109), inclusive.
-Each character in operators will be either '+' or '-' (quotes for clarity).


EXAMPLES

0)
{3, -1, 7}
"+-+"

Returns: 2

From the problem statement.

1)
{1}
"-"

Returns: -1

There are infinitely many pairs of positive integers that differ by one.

2)
{1}
"+"

Returns: 0

Note that all numbers ai have to be positive integers.

3)
{10}
"+"

Returns: 9

4)
{540, 2012, 540, 2012, 540, 2012, 540}
"-+-+-+-"

Returns: 1471

*/
// END CUT HERE
#line 90 "ImportantSequence.cpp"

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
#define VI vector<ll>
#define PII pair<ll, ll> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class ImportantSequence {
	public:
	PII f(int i, int op, ll v, vector <int>& B, string& OP) {
		if(i==0) return MP(op, v);
		op *= OP[i-1]=='-' ? 1 : -1;
		v *= (ll)(OP[i-1]=='-' ? 1 : -1);
		v += (ll)B[i-1];
		return f(i-1, op, v, B, OP);
	}
	int getCount(vector <int> B, string OP) {
		VI lb, ub;
		REP(i, B.size()+1) {
			PII p = f(i, 1, 0, B, OP);
			if(p.first== 1) lb.PB(p.second);
			if(p.first==-1) ub.PB(p.second);
		}
		//cout<<lb<<endl;
		if(lb.size()==0 || ub.size()==0) return -1;
		ll l = *max_element(ALL(lb));
		ll u = *min_element(ALL(ub));
		//cout<<l<<endl;
		//cout<<u<<endl;
		return max((ll)0, (u-1)-(l+1)+1);
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
#define END	 verify_case(_, ImportantSequence().getCount(B, operators));}
int main(){

CASE(0)
	int B_[] = {3, -1, 7};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string operators = "+-+"; 
	int _ = 2; 
END
CASE(1)
	int B_[] = {1};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string operators = "-"; 
	int _ = -1; 
END
CASE(2)
	int B_[] = {1};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string operators = "+"; 
	int _ = 0; 
END
CASE(3)
	int B_[] = {10};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string operators = "+"; 
	int _ = 9; 
END
CASE(4)
	int B_[] = {540, 2012, 540, 2012, 540, 2012, 540};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string operators = "-+-+-+-"; 
	int _ = 1471; 
END
CASE(4)
	int B_[] = {380363427, 583629335, -681431183, -219398108, 24128364, 933370503, 476023070, -401987717, -625916565, 496045772, 908035426, -895357751, 464638908, -115569799, -905531819, -393481688, 203364448, 48324176, -36670007, -531426289, -460125068, 629279122, -733410707, -159928285, -562938483, -878488131, 560719010, -466275382, -312074009, -445541791, 320972323, -477210673, 514950353, -252233737, -599779031, 819400249, 364282240, 530984231, 981313465, 353217366, 118458547, -491592609, 190379345, 187993123, 299990918, 968081798, 212935226, 448245418};
	  vector <int> B(B_, B_+sizeof(B_)/sizeof(*B_)); 
	string operators = "-++-+----+-++-+--++--+-+---++-------++-+--++-+-+"; 
	int _ = 0; 
END

}
// END CUT HERE
