// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Bob is using a peculiar text editor to write a sequence of lines of text.
The editor consists of three parts: a results window, a text buffer and an undo history.
More details about the three parts follow.

The results window contains a sequence of strings: the lines of text you already wrote. Initially, the results window is empty.
The text buffer contains a string: the line you are writing at the moment. Initially, the string in the text buffer is empty.
The undo history contains a sequence of strings: all the past states of the text buffer. Initially, the undo history contains a single element: an empty string.


You are given a vector <string> lines.
Bob would like to print the contents of lines into the results window.
(At the end, the sequence of strings stored in the results window must be precisely equal to lines. Order of elements matters.)
Additionally, Bob would like to do so as quickly as possible.
He is able to take the following actions:


Bob may type a lowercase letter. The letter is appended to the text buffer. The new text buffer is then added as a new element of the undo history. (For example, if the text buffer currently contains "do", then pressing 'g' changes the text buffer to "dog" and then stores "dog" into the undo history.)
Bob may press Enter. When he does so, the current content of the text buffer is printed to the results window as a new line, after the lines that were printed earlier. The text buffer remains unmodified. (For example, if the text buffer contains "dog" and Bob presses Enter, "dog" will be appended to the results window, and the results buffer still contains "dog".)
Bob may use two mouse clicks to restore any entry from the undo history to the text buffer. This operation does not modify the undo history.


Return the minimum total number of button presses (keyboard and mouse) that Bob needs to print all the given lines into the results window.

DEFINITION
Class:UndoHistory
Method:minPresses
Parameters:vector <string>
Returns:int
Method signature:int minPresses(vector <string> lines)


CONSTRAINTS
-lines will contain between 1 and 50 elements, inclusive.
-Each element of lines will contain between 1 and 50 characters, inclusive.
-Each element of lines will contain only lowercase letters ('a'-'z').


EXAMPLES

0)
{"tomorrow", "topcoder"}

Returns: 18


Type 't'. The text buffer now contains "t", and the undo history now contains "" and "t".
Type 'o'. The text buffer now contains "to", and the undo history now contains "", "t", and "to".
Using six more keypresses, type the letters in "morrow". The text buffer now contains "tomorrow" and the undo history contains all prefixes of "tomorrow". The results window is still empty.
Press Enter. The results window now contains one string: "tomorrow".
Click the mouse twice to restore "to" from undo history.
Using another six keypresses, type the letters in "pcoder".
Press Enter. The results window now contains "tomorrow" and "topcoder", in this order, and we are done.

The total number of button presses was 8 (typing "tomorrow") + 1 (Enter) + 2 (mouse) + 6 (typing "pcoder") + 1 (Enter) = 18.

1)
{"a","b"}

Returns: 6

After typing "a" and pressing enter, we need to restore the empty string (which is always present at the top of the undo buffer) before typing "b".

2)
{"a", "ab", "abac", "abacus" }

Returns: 10

There are times when it is not necessary to use the undo history at all.

3)
{"pyramid", "sphinx", "sphere", "python", "serpent"}

Returns: 39



4)
{"ba","a","a","b","ba"}


Returns: 13



*/
// END CUT HERE
#line 91 "UndoHistory.cpp"

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

#define f(i,m,n) for(int i=m;i<n;i++)

class UndoHistory {
	public:
	
	int minPresses(vector <string> lines) {
		string textBuffer="";
		set<string> undoHistory;
		int total=0;
		REP(i, lines.size()) {
			unsigned int minTyping=(textBuffer==""?0:2)+lines[i].size()+1;
			REP(j, lines[i].size()) {
				string prefix(lines[i].begin(), lines[i].begin()+j+1);
				if(textBuffer==prefix){
					minTyping=min(minTyping,lines[i].size()-textBuffer.size()+1);
				} else if (undoHistory.find(prefix)!=undoHistory.end())
				{
					minTyping=min(minTyping,2+lines[i].size()-prefix.size()+1);
				}else{
					undoHistory.insert(prefix);
				}
			}
			total+=minTyping;
			textBuffer=lines[i];
		}
		return total;
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
#define END	 verify_case(_, UndoHistory().minPresses(lines));}
int main(){

CASE(0)
	string lines_[] = {"tomorrow", "topcoder"};
	  vector <string> lines(lines_, lines_+sizeof(lines_)/sizeof(*lines_)); 
	int _ = 18; 
END
//return 0;
CASE(1)
	string lines_[] = {"a","b"};
	  vector <string> lines(lines_, lines_+sizeof(lines_)/sizeof(*lines_)); 
	int _ = 6; 
END
CASE(2)
	string lines_[] = {"a", "ab", "abac", "abacus" };
	  vector <string> lines(lines_, lines_+sizeof(lines_)/sizeof(*lines_)); 
	int _ = 10; 
END
CASE(3)
	string lines_[] = {"pyramid", "sphinx", "sphere", "python", "serpent"};
	  vector <string> lines(lines_, lines_+sizeof(lines_)/sizeof(*lines_)); 
	int _ = 39; 
END
CASE(4)
	string lines_[] = {"ba","a","a","b","ba"}
;
	  vector <string> lines(lines_, lines_+sizeof(lines_)/sizeof(*lines_)); 
	int _ = 13; 
END
CASE(4)
	string lines_[] = {"aaaaa","aaaa","aaa"}
;
	  vector <string> lines(lines_, lines_+sizeof(lines_)/sizeof(*lines_)); 
	int _ = 12; 
END

}
// END CUT HERE
