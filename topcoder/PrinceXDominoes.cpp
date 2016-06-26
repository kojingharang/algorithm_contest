// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.

Ivy is the little princess of the Kingdom of Ducks, where slimes and ducks live in peace and harmony.

Today, the king gave Ivy several dominoes as presents. Each domino is a rectangle that consist of two numbers, both between 0 and M-1, inclusive. One number is written in red and the other one in black. For example, the following picture shows all possible domino types with M=3.



The king would like to arrange a big circular sequence of dominoes for Ivy, and he asks you for your help. A circular sequence of dominoes is a sequence of N dominoes such that the number written in red on the i-th domino is equal to the number written in black on the ((i+1) modulo N)-th domino (zero-based indexing). For example, this picture shows an example of a circular sequence of dominoes with N=4 elements.



Notice that the number written in red on the last domino must be equal to the number written in black on the first domino.

You are given the dominoes that Ivy has as a vector <string> dominoes, consisting of exactly M elements. More precisely, the character dominoes[i][j] encodes how many dominoes with a red number i and a black number j Ivy has. The characters in dominoes are to be interpreted as follows:

'.' - Ivy has no such domino.
'A' - 'Z' - Ivy has X dominoes of that type, where 'A' means X=1, 'B' means X=2, and so on.


If Ivy owns at least one domino of a particular domino type, that domino type is said to be available. The circular sequence of dominoes that you will create must contain at least one domino from each of the available domino types. Each domino that Ivy has can be included at most once in this sequence. Return the maximum number N of dominoes in a circular sequence of dominoes that you can construct for Ivy, or -1 if no such sequence exists.

DEFINITION
Class:PrinceXDominoes
Method:play
Parameters:vector <string>
Returns:int
Method signature:int play(vector <string> dominoes)


CONSTRAINTS
-dominoes will contain between 2 and 30 elements, inclusive.
-Each element of dominoes will contain exactly M characters, where M is the number of elements in dominoes.
-Each character in each element of dominoes will either be a period ('.') or an uppercase letter ('A'-'Z').
-For all numbers X between 0 and M-1, inclusive, Ivy will have at least one domino on which the number X is written in red.
-For all numbers X between 0 and M-1, inclusive, Ivy will have at least one domino on which the number X is written in black.


EXAMPLES

0)
{".A."
,"..B"
,"A.A"}

Returns: 4

Corresponds to the sequence shown in the second picture above.

1)
{"A.."
,".B."
,"..C"}

Returns: -1

It is not possible to use all of the three available
domino types in a single circular sequence of dominoes.

2)
{"ZZ"
,"ZZ"}

Returns: 104

Sometimes, it is possible to use all the dominoes Ivy has.

3)
{"THIS.SRM"
,"IS.SPONS"
,"ORED.BY."
,"CITI.THA"
,"NKS.FOR."
,"PARTICIP"
,"ATING.DO"
,"LPHINIGL"}

Returns: 612



4)
{"A.A.A.A.A."
,"DOLPHINIGL"
,"A.Z.X.D.F."
,"IVANMETELS"
,"T.W.W.X.M."
,"RNGRNGRNGR"
,"W.S.C.E.F."
,"FUSHARFUSH"
,"A.B.C.D.E."
,"CITICITICI"}

Returns: -1



*/
// END CUT HERE
#line 104 "PrinceXDominoes.cpp"

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
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class PrinceXDominoes {
	public:
	int play(vector <string> dominoes) {
		
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, PrinceXDominoes().play(dominoes));}
int main(){

CASE(0)
	string dominoes_[] = {".A."
,"..B"
,"A.A"};
	  vector <string> dominoes(dominoes_, dominoes_+sizeof(dominoes_)/sizeof(*dominoes_)); 
	int _ = 4; 
END
CASE(1)
	string dominoes_[] = {"A.."
,".B."
,"..C"};
	  vector <string> dominoes(dominoes_, dominoes_+sizeof(dominoes_)/sizeof(*dominoes_)); 
	int _ = -1; 
END
CASE(2)
	string dominoes_[] = {"ZZ"
,"ZZ"};
	  vector <string> dominoes(dominoes_, dominoes_+sizeof(dominoes_)/sizeof(*dominoes_)); 
	int _ = 104; 
END
CASE(3)
	string dominoes_[] = {"THIS.SRM"
,"IS.SPONS"
,"ORED.BY."
,"CITI.THA"
,"NKS.FOR."
,"PARTICIP"
,"ATING.DO"
,"LPHINIGL"};
	  vector <string> dominoes(dominoes_, dominoes_+sizeof(dominoes_)/sizeof(*dominoes_)); 
	int _ = 612; 
END
CASE(4)
	string dominoes_[] = {"A.A.A.A.A."
,"DOLPHINIGL"
,"A.Z.X.D.F."
,"IVANMETELS"
,"T.W.W.X.M."
,"RNGRNGRNGR"
,"W.S.C.E.F."
,"FUSHARFUSH"
,"A.B.C.D.E."
,"CITICITICI"};
	  vector <string> dominoes(dominoes_, dominoes_+sizeof(dominoes_)/sizeof(*dominoes_)); 
	int _ = -1; 
END

}
// END CUT HERE
