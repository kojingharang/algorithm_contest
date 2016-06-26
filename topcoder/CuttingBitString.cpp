// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// We are in a distant future.
After the downfall of mankind, the Earth is now ruled by fairies.
The "Turing game Online" website is hot among fairies right now.
On this website, everyone can play the programming puzzle "Turing game".

Fairies love powers of 5, that is, the numbers 1, 5, 25, 125, 625, and so on.
In the Turing game, the player is given a string of bits (zeros and ones).
The ideal situation is when the string is represents a power of 5 in binary, with no leading zeros.
If that is not the case, the fairy player tries to cut the given string into pieces, each piece being a binary representation of a power of 5, with no leading zeros.
Of course, it may be the case that even this is impossible.
In that case, the fairy player becomes depressed, and bad things happen when a fairy gets depressed.
You, as one of the surviving humans, are in charge of checking the bit strings to prevent the bad things from happening.

You are given a string S that consists of characters '0' and '1' only.
S represents the string given to a player of the Turing game.
Return the smallest positive integer K such that it is possible to cut S into K pieces, each of them being a power of 5.
If there is no such K, return -1 instead.

DEFINITION
Class:CuttingBitString
Method:getmin
Parameters:string
Returns:int
Method signature:int getmin(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be either '0' or '1'.


EXAMPLES

0)
"101101101"

Returns: 3

We can split the given string into three "101"s.
Note that "101" is 5 in binary.

1)
"1111101"

Returns: 1

"1111101" is 5^3.

2)
"00000"

Returns: -1

0 is not a power of 5.

3)
"110011011"

Returns: 3

Split it into "11001", "101" and "1".

4)
"1000101011"

Returns: -1



5)
"111011100110101100101110111"

Returns: 5



*/
// END CUT HERE
#line 83 "CuttingBitString.cpp"

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
#include <cassert>
#include <cctype>
#include <iomanip>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VS vector<string>
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

vector<string> w;

string f(ll v) {
	string s;
	while(v) {
		s = ((v&1)?"1":"0") + s;
		v>>=1;
	}
	return s;
}

int ff(const string& s, int idx) {
	if(idx==(int)s.size()) {
		return 0;
	}
	if(idx>(int)s.size()) return -1000;
	//cout<<"ff "<<idx<<endl;
	int rest = s.size() - idx;
	int ans = 1000;
	REP(i, w.size()) {
		if((int)w[i].size() <= rest) {
			int ok=1;
			REP(j, w[i].size()) {
				if(w[i][j]!=s[idx+j]) {ok=0;break;}
			}
			if(ok) {
				int lans = 1+ff(s, idx+w[i].size());
				if(lans >= 0) ans = min(ans, lans);
			}
		}
	}
	return ans;
}

class CuttingBitString {
	public:
	int getmin(string S) {
		ll v = 1;
		w = vector<string>();
		while(v < (1LL<<50)) {
			//cout<<v<<endl;
			w.PB(f(v));
			v*=5;
		}
		//REP(i, w.size()) cout<<w[i]<<endl;
		int ans = ff(S, 0);
		if(ans == 1000) ans = -1;
		if(ans < 0) ans = -1;
		return ans;
	}
};

/*
1
101
11001
1111101
1001110001
110000110101
11110100001001
10011000100101101
1011111010111100001
111011100110101100101
100101010000001011111001
10111010010000111011011101
1110100011010100101001010001
1001000110000100111001110010101
101101011110011000100000111101001
11100011010111111010100100110001101
10001110000110111100100110111111000001
1011000110100010101111000010111011000101
110111100000101101101011001110100111011001
100010101100011100100011000001001000100111101
10101101011110001110101111000101101011000110001
1101100011010111001001101011011100010111011110101
*/

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
#define END	 verify_case(_, CuttingBitString().getmin(S));}
int main(){

CASE(0)
	string S = "101101101"; 
	int _ = 3; 
END
CASE(1)
	string S = "1111101"; 
	int _ = 1; 
END
CASE(2)
	string S = "00000"; 
	int _ = -1; 
END
CASE(3)
	string S = "110011011"; 
	int _ = 3; 
END
CASE(4)
	string S = "1000101011"; 
	int _ = -1; 
END
CASE(5)
	string S = "111011100110101100101110111"; 
	int _ = 5; 
END
CASE(5)
	string S = "111111111111111111111111111111111"; 
	int _ = 1; 
END

}
// END CUT HERE
