// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Mr. Dengklek lives in the Kingdom of Ducks, where humans and ducks live together in peace and harmony. 



Mr. Dengklek works as a chain maker. Today, he would like to make a beautiful chain as a decoration for one of his lovely ducks. He will produce the chain from leftovers he found in his workshop. Each of the leftovers is a chain piece consisting of exactly 3 links. Each link is either clean or rusty. Different clean links may have different degrees of beauty.



You are given a vector <string> chains describing the leftovers. Each element of chains is a 3-character string describing one of the chain pieces. A rusty link is represented by a period ('.'), whereas a clean link is represented by a digit ('0'-'9'). The value of the digit in the clean link is the beauty of the link. For example, chains = {".15", "7..", "532", "..3"} means that Mr. Dengklek has 4 chain pieces, and only one of these ("532") has no rusty links.



All links have the same shape, which allows Mr. Dengklek to concatenate any two chain pieces. However, the link shape is not symmetric, therefore he may not reverse the chain pieces. E.g., in the above example he is able to produce the chain "532.15" or the chain ".15..37..", but he cannot produce "5323..".



To produce the chain, Mr. Dengklek will follow these steps:

Concatenate all chain pieces in any order.
Pick a contiguous sequence of links that contains no rusty links. Remove and discard all the remaining links.

The beauty of the new chain is the total beauty of all the links picked in the second step. Of course, Mr. Dengklek would like to create the most beautiful chain possible.



Return the largest possible beauty a chain can have according to the above rules.

DEFINITION
Class:DengklekMakingChains
Method:maxBeauty
Parameters:vector <string>
Returns:int
Method signature:int maxBeauty(vector <string> chains)


NOTES
-Mr. Dengklek is not allowed to remove and discard individual links before concatenating the chain pieces.
-If all links in the input are rusty, Mr. Dengklek is forced to select an empty sequence of links. The beauty of an empty sequence is 0.


CONSTRAINTS
-chains will contain between 1 and 50 elements, inclusive.
-Each element of chains will contain exactly 3 characters.
-Each character in each element of chains will be either a '.' or one of '0'-'9'.


EXAMPLES

0)
{".15", "7..", "402", "..3"}

Returns: 19

One possible solution:


In the first step, concatenate the chain pieces in the order "..3", ".15", "402", "7.." to obtain the chain "..3.154027..".
In the second step, pick the subsequence "154027".

The beauty of the chain in this solution is 1+5+4+0+2+7 = 19.

1)
{"..1", "7..", "567", "24.", "8..", "234"}

Returns: 36

One possible solution is to concatenate the chain pieces in this order:

"..1", "234", "567", "8..", "24.", "7.." -> "..12345678..24.7..",

and then to pick the subsequence "12345678". Its beauty is 1+2+3+4+5+6+7+8 = 36.

2)
{"...", "..."}

Returns: 0

Mr. Dengklek cannot pick any links.

3)
{"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}

Returns: 28



4)
{"..1", "3..", "2..", ".7."}

Returns: 7



5)
{"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}

Returns: 58



*/
// END CUT HERE
#line 107 "DengklekMakingChains.cpp"

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

int f(char c) {
	return c=='.'?-1:c-'0';
}

class DengklekMakingChains {
	public:
	int maxBeauty(vector <string> ch) {
		int single=0;
		int full=0;
		int left=0;
		int right=0;
		VI L(ch.size(), -1);
		VI R(ch.size(), -1);
		int hasL = 0;
		int hasR = 0;
		REP(i, ch.size()) {
			int a=f(ch[i][0]);
			int b=f(ch[i][1]);
			int c=f(ch[i][2]);
			if(a==-1&&b!=-1&&c==-1) {
				single = max(single, b);
			}
			if(a!=-1&&b!=-1&&c!=-1) {
				full += a+b+c;
			} else {
				if(a!=-1) {
					left = max(left, a+(b==-1?0:b));
					L[i] = a+(b==-1?0:b);
					hasL=1;
				}
				if(c!=-1) {
					right = max(right, c+(b==-1?0:b));
					R[i] = c+(b==-1?0:b);
					hasR=1;
				}
			}
		}
		int lr = 0;
		if(hasL && hasR) {
			REP(i, ch.size()) 
			REP(j, ch.size()) if(i!=j && L[i]!=-1 & R[j]!=-1) lr=max(lr, L[i]+R[j]);
			lr=max(lr, left);
			lr=max(lr, right);
		} else if(hasL) lr=left;
		else lr=right;
		return max(single, full+lr);
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
#define END	 verify_case(_, DengklekMakingChains().maxBeauty(chains));}
int main(){

CASE(0)
	string chains_[] = {".15", "7..", "402", "..3"};
	  vector <string> chains(chains_, chains_+sizeof(chains_)/sizeof(*chains_)); 
	int _ = 19; 
END
CASE(1)
	string chains_[] = {"..1", "7..", "567", "24.", "8..", "234"};
	  vector <string> chains(chains_, chains_+sizeof(chains_)/sizeof(*chains_)); 
	int _ = 36; 
END
CASE(2)
	string chains_[] = {"...", "..."};
	  vector <string> chains(chains_, chains_+sizeof(chains_)/sizeof(*chains_)); 
	int _ = 0; 
END
CASE(3)
	string chains_[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"};
	  vector <string> chains(chains_, chains_+sizeof(chains_)/sizeof(*chains_)); 
	int _ = 28; 
END
CASE(4)
	string chains_[] = {"..1", "3..", "2..", ".7."};
	  vector <string> chains(chains_, chains_+sizeof(chains_)/sizeof(*chains_)); 
	int _ = 7; 
END
CASE(5)
	string chains_[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"};
	  vector <string> chains(chains_, chains_+sizeof(chains_)/sizeof(*chains_)); 
	int _ = 58; 
END
CASE(5)
	string chains_[] = {"000", ".9."};
	  vector <string> chains(chains_, chains_+sizeof(chains_)/sizeof(*chains_)); 
	int _ = 9; 
END
CASE(5)
	string chains_[] = {"123", "9.9"};
	  vector <string> chains(chains_, chains_+sizeof(chains_)/sizeof(*chains_)); 
	int _ = 15; 
END

}
// END CUT HERE
