// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// 
Tomek thinks that smartphones are overrated.
He plans to release a new cellphone with an old-school keyboard, which may require you to tap a key multiple times to type a single letter.
For example, if the keyboard has two keys, one with the letters "adef" and the other one with the letters "zyx", then typing 'a' requires one keystroke, typing 'f' requires four keystrokes, typing 'y' requires two keystrokes, and so on.



Tomek has already designed the keyboard's layout.
That is, he already knows the number of keys on the keyboard, and for each key he knows the maximum number of letters it may hold.
He now wants to create a specific keyboard for a language that uses N different letters.
He has a large body of text in this language, and he already analyzed it to find the frequencies of all N letters of its alphabet.



You are given a vector <int> frequencies with N elements.
Each element of frequencies is the number of times one of the letters in Tomek's alphabet appears in the text he has.
Each element of frequencies will be strictly positive.
(I.e., each of the N letters occurs at least once in Tomek's text.)



You are also given a vector <int> keySize.
The number of elements of keySize is the number of keys on Tomek's keyboard.
Each element of keySize gives the maximal number of letters on one of the keys.



Find an assignment of letters to keys that minimizes the number of keystrokes needed to type Tomek's entire text.
Return that minimum number of keystrokes.
If there is not enough room on the keys and some letters of the alphabet won't fit, return -1 instead.


DEFINITION
Class:TomekPhone
Method:minKeystrokes
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int minKeystrokes(vector <int> occurences, vector <int> keySizes)


CONSTRAINTS
-frequencies will contain between 1 and 50 elements, inclusive.
-Each element of frequencies will be between 1 and 1,000, inclusive.
-keySizes will contain between 1 and 50 elements, inclusive.
-Each element of keySizes will be between 1 and 50, inclusive.


EXAMPLES

0)
{7,3,4,1}
{2,2}

Returns: 19

Tomek's language has four letters.
Let us call them A, B, C, and D.
Tomek's text contains seven As, three Bs, four Cs, and one D.
The keyboard has two keys, each of them may contain at most two letters.
One optimal solution is to use the keys "AD" and "CB".
We can then type each A and each C using a single keystroke, and we need two keystrokes for each B and each D.
Therefore, the total number of keystrokes when typing the entire text will be 7*1 + 3*2 + 4*1 + 1*2 = 19.


1)
{13,7,4,20}
{2,1}

Returns: -1

There is not enough space on the keys to fit all four letters.

2)
{11,23,4,50,1000,7,18}
{3,1,4}

Returns: 1164



3)
{100,1000,1,10}
{50}

Returns: 1234



4)
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50}
{10,10,10,10,10,10,10,10}

Returns: 3353



*/
// END CUT HERE
#line 103 "TomekPhone.cpp"

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



class TomekPhone {
	public:
	int minKeystrokes(vector <int> O, vector <int> K) {
		if(O.size() > accumulate(ALL(K), 0)) return -1;
		sort(ALLR(O));
		VI w;
		REP(i, K.size()) {
			RANGE(j, 1, K[i]+1) {
				w.PB(j);
			}
		}
		sort(ALL(w));
		ll ans = 0;
		REP(i, O.size()) {
			ans += O[i]*w[i];
		}
		return ans;
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
#define END	 verify_case(_, TomekPhone().minKeystrokes(occurences, keySizes));}
int main(){

CASE(0)
	int occurences_[] = {7,3,4,1};
	  vector <int> occurences(occurences_, occurences_+sizeof(occurences_)/sizeof(*occurences_)); 
	int keySizes_[] = {1,1};
	  vector <int> keySizes(keySizes_, keySizes_+sizeof(keySizes_)/sizeof(*keySizes_)); 
	int _ = 19; 
END
CASE(0)
	int occurences_[] = {7,3,4,1};
	  vector <int> occurences(occurences_, occurences_+sizeof(occurences_)/sizeof(*occurences_)); 
	int keySizes_[] = {2,2};
	  vector <int> keySizes(keySizes_, keySizes_+sizeof(keySizes_)/sizeof(*keySizes_)); 
	int _ = 19; 
END
CASE(1)
	int occurences_[] = {13,7,4,20};
	  vector <int> occurences(occurences_, occurences_+sizeof(occurences_)/sizeof(*occurences_)); 
	int keySizes_[] = {2,1};
	  vector <int> keySizes(keySizes_, keySizes_+sizeof(keySizes_)/sizeof(*keySizes_)); 
	int _ = -1; 
END
CASE(2)
	int occurences_[] = {11,23,4,50,1000,7,18};
	  vector <int> occurences(occurences_, occurences_+sizeof(occurences_)/sizeof(*occurences_)); 
	int keySizes_[] = {3,1,4};
	  vector <int> keySizes(keySizes_, keySizes_+sizeof(keySizes_)/sizeof(*keySizes_)); 
	int _ = 1164; 
END
CASE(3)
	int occurences_[] = {100,1000,1,10};
	  vector <int> occurences(occurences_, occurences_+sizeof(occurences_)/sizeof(*occurences_)); 
	int keySizes_[] = {50};
	  vector <int> keySizes(keySizes_, keySizes_+sizeof(keySizes_)/sizeof(*keySizes_)); 
	int _ = 1234; 
END
CASE(4)
	int occurences_[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
	  vector <int> occurences(occurences_, occurences_+sizeof(occurences_)/sizeof(*occurences_)); 
	int keySizes_[] = {10,10,10,10,10,10,10,10};
	  vector <int> keySizes(keySizes_, keySizes_+sizeof(keySizes_)/sizeof(*keySizes_)); 
	int _ = 3353; 
END

}
// END CUT HERE
