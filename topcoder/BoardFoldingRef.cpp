// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// Little Petya likes puzzles a lot.
Recently he has received one as a gift from his mother.
The puzzle has the form of a rectangular sheet of paper that is divided into N rows by M columns of unit square cells.
Rows are numbered 0 through N-1 from top to bottom, and columns 0 through M-1 from left to right.
Each cell is colored either black or white.
You are given a description of the paper, the exact format is specified at the end of this problem statement.


The goal of the puzzle is to fold the paper.
This has to be done in a sequence of turns.
In each turn, Petya has to fold the paper according to the rules below.
He can end the process after any number of turns (including zero), even if there are still valid ways to fold the paper.


In each turn, Petya must follow these steps:
To start folding, he must choose a line that is parallel to one of the sides of the paper and passes between two rows/columns of cells.
He can then take the smaller part of the paper and fold it on top of the larger part.
(If the line divides the current paper in half, he can fold either half on top of the other.)
There is one additional restriction:
Petya may only perform the fold if all cells of the part that is being folded land on equally-colored cells of the part that remains in place.


For example, consider the following paper (with 0 and 1 representing white and black):

10010101
11110100
00000000
01101110



Here, Petya could choose the vertical line that goes between the two leftmost columns and the rest of the paper.
Note that this is a valid choice: as he makes the fold, the cells from the leftmost two columns will all match their counterparts in the right part of the
paper.
This is how the paper looks like after the fold (with periods representing empty spaces):

..010101
..110100
..000000
..101110



Clearly, even after multiple folds the paper will always look like a subrectangle of the original paper.
Two states of the game are considered the same if that rectangle has the same dimensions and the same offset with respect to the original top left corner of
the paper.
(Note that folding order does not matter. Two different sequences of folding may produce the same final state.)


You are given the ints N and M.
You are also given a description of the original state of the paper in a compressed form, as a vector <string> compressedPaper.
Compute and return the number of possible final states of the game.


The vector <string> compressedPaper will contain N elements with ceil(M/6) characters each. Each character (except possibly the last one) encodes six cells of the paper. The actual paper can be obtained from compressedPaper using the following pseudocode:



for i in 0..N-1:
    for j in 0..M-1:
        paper[i][j] = (tonumber(compressedPaper[i][j / 6]) >> (j modulo 6)) modulo 2



In the above pseudocode, "/" represents integer division (rounding down), ">>" is a bit shift to the right, and tonumber(x) maps the character x to a number between 0 and 63 as follows: the characters '0'-'9' map to integers 0-9, 'a'-'z' map to 10-35, 'A'-'Z' map to 36-61, '#' maps to 62, and '@' maps to 63.


If paper[i][j] = 0, then the cell (i,j) is white, otherwise it is black.

DEFINITION
Class:BoardFolding
Method:howMany
Parameters:int, int, vector <string>
Returns:int
Method signature:int howMany(int N, int M, vector <string> compressedPaper)


CONSTRAINTS
-N and M will be between 1 and 250, inclusive.
-compressedPaper will contain N elements.
-Each element of compressedPaper will contain ceil(M / 6) elements.
-compressedPaper will contain only characters '0'-'9', 'a'-'z', 'A'-'Z', '#' and '@'.


EXAMPLES

0)
2
2
{"1", "3"}

Returns: 1

The paper looks as follows:


10
11


There is no valid way to fold this paper, so there is just one possible outcome.

1)
2
7
{"@@", "@@"}

Returns: 84

In this case the paper looks like this:


1111111
1111111


We can fold it into any of the 84 possible subrectangles of the original rectangle.

2)
4
4
{"6", "9", "9", "6"}

Returns: 9

Here the paper is:

0110
1001
1001
0110


3)
6
1
{"0", "2", "6", "@", "4", "A"}

Returns: 6

Here the paper is:

0
0
0
1
0
0


4)
3
3
{"0", "2", "0"}


Returns: 1

In this case the paper looks like:

000
010
000


******************************/
// END CUT HERE
#line 172 "BoardFolding.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << "\n"; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
      out<<'('<<a.fr<<','<<a.sc<<')';
       return out;
    }
}
 
#define CLR(x) memset((x),0,sizeof(x))
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
using namespace std;
const int INF=5e8;
int buf[300][300],buf2[300][300];
int h,w;
int conv[300];
 
bool memo[300][300];
int sameL[300];
class BoardFolding {
    public:
  void rec(int l,int r){//[l...r)
    if(memo[l][r]) return;
    memo[l][r]=1;
    
    for(int i=l+1;i<r;++i){
      if(sameL[i]>=min(i-l,r-i)){
        if((i-l)==(r-i)){
          rec(l,i);
          rec(i,r);
        }else if(i-l<r-i){
          rec(i,r);
        }else{
          rec(l,i);
        }
      }
    }
  }
 
  int solve(){
    for(int i=1;i<w;++i){
      int len=INF;
      REP(j,h){
        int x0=i-1,x1=i;
        int cnt=0;
        while(x0>=0 && x1<w && buf[j][x0]==buf[j][x1]){
          ++cnt;
          --x0;
          ++x1;
        }
        chmin(len,cnt);
      }
      sameL[i]=len;
	  cout<<"sameL "<<i<<" = "<<len<<endl;
    }
 
 
    CLR(memo);
 
    rec(0,w);
 
    int res=0;
	map<int, int>hi;
    REP(i,w+1) REP(j,w+1) if(memo[i][j]) {
		hi[(i+j)/2]++;
		++res;
		cout<<i<<" "<<j<<" OK "<<endl;
	}
	FOR(e, hi) {
		cout<<e->first<<" "<<e->second<<" OK "<<endl;
	}
    return res;
  }
    int howMany(int h2, int w2, vector<string> mat) {
    h=h2;
    w=w2;
 
    REP(i,10) conv['0'+i]=i;
    REP(i,26) conv['a'+i]=10+i;
    REP(i,26) conv['A'+i]=36+i;
    conv['#']=62;
    conv['@']=63;
 
    REP(i,h) REP(j,w){
      buf[i][j]=(conv[mat[i][j/6]]>>(j%6)&1);
    }
 
    REP(i,h) {REP(j,w) {cout<<buf[i][j];}cout<<endl;}
    int A=solve(),B;
 
    REP(i,h) REP(j,w) buf2[j][i]=buf[i][j];
    swap(h,w);
    REP(i,h) REP(j,w) buf[i][j]=buf2[i][j];
 
    B=solve();
 
 cout<<A<<" "<<B<<endl;
    return A*B;
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
#define END	 verify_case(_, BoardFolding().howMany(N, M, compressedPaper));}
//#define END	 verify_case(_, BoardFoldingRef().howMany(N, M, compressedPaper));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int N = 64; 
	int M = 64; 
	string compressedPaper_[] = {
"mCmqmCCBmC6", "FpFBFppqFp9", "FpFBFppqFp9", "mCmqmCCBmC6", "FpFBFppqFp9", "mCmqmCCBmC6", "mCmqmCCBmC6", "FpFBFppqFp9", "FpFBFppqFp9", "mCmqmCCBmC6", "mCmqmCCBmC6", "FpFBFppqFp9", "mCmqmCCBmC6", "FpFBFppqFp9", "FpFBFppqFp9", "mCmqmCCBmC6", "FpFBFppqFp9", "mCmqmCCBmC6", "mCmqmCCBmC6", "FpFBFppqFp9", "mCmqmCCBmC6", "FpFBFppqFp9", "FpFBFppqFp9", "mCmqmCCBmC6", "mCmqmCCBmC6", "FpFBFppqFp9", "FpFBFppqFp9", "mCmqmCCBmC6", "FpFBFppqFp9", "mCmqmCCBmC6", "mCmqmCCBmC6", "FpFBFppqFp9", "FpFBFppqFp9", "mCmqmCCBmC6", "mCmqmCCBmC6", "FpFBFppqFp9", "mCmqmCCBmC6", "FpFBFppqFp9", "FpFBFppqFp9", "mCmqmCCBmC6", "mCmqmCCBmC6", "FpFBFppqFp9", "FpFBFppqFp9", "mCmqmCCBmC6", "FpFBFppqFp9", "mCmqmCCBmC6", "mCmqmCCBmC6", "FpFBFppqFp9", "mCmqmCCBmC6", "FpFBFppqFp9", "FpFBFppqFp9", "mCmqmCCBmC6", "FpFBFppqFp9", "mCmqmCCBmC6", "mCmqmCCBmC6", "FpFBFppqFp9", "FpFBFppqFp9", "mCmqmCCBmC6", "mCmqmCCBmC6", "FpFBFppqFp9", "mCmqmCCBmC6", "FpFBFppqFp9", "FpFBFppqFp9", "mCmqmCCBmC6"
	};
	  vector <string> compressedPaper(compressedPaper_, compressedPaper_+sizeof(compressedPaper_)/sizeof(*compressedPaper_)); 
	int _ = 21316; 
END
return 0;
CASE(0)
	int N = 2; 
	int M = 2; 
	string compressedPaper_[] = {"1", "3"};
	  vector <string> compressedPaper(compressedPaper_, compressedPaper_+sizeof(compressedPaper_)/sizeof(*compressedPaper_)); 
	int _ = 1; 
END
return 0;


CASE(1)
	int N = 2; 
	int M = 7; 
	string compressedPaper_[] = {"@@", "@@"};
	  vector <string> compressedPaper(compressedPaper_, compressedPaper_+sizeof(compressedPaper_)/sizeof(*compressedPaper_)); 
	int _ = 84; 
END
CASE(2)
	int N = 4; 
	int M = 4; 
	string compressedPaper_[] = {"6", "9", "9", "6"};
	  vector <string> compressedPaper(compressedPaper_, compressedPaper_+sizeof(compressedPaper_)/sizeof(*compressedPaper_)); 
	int _ = 9; 
END
CASE(3)
	int N = 6; 
	int M = 1; 
	string compressedPaper_[] = {"0", "2", "6", "@", "4", "A"};
	  vector <string> compressedPaper(compressedPaper_, compressedPaper_+sizeof(compressedPaper_)/sizeof(*compressedPaper_)); 
	int _ = 6; 
END
CASE(4)
	int N = 3; 
	int M = 3; 
	string compressedPaper_[] = {"0", "2", "0"}
;
	  vector <string> compressedPaper(compressedPaper_, compressedPaper_+sizeof(compressedPaper_)/sizeof(*compressedPaper_)); 
	int _ = 1; 
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
	int N = UNIFORM_LL(0, 100); 
// param type: int
	int M = UNIFORM_LL(0, 100); 
// param type: String
	vector <string> compressedPaper; 
	{
		int N=UNIFORM_LL(1, 51);
		compressedPaper = vector <string>(N); 
		REP(i, N) {
			compressedPaper[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = BoardFolding().howMany(N, M, compressedPaper);
	int _1 = BoardFoldingRef().howMany(N, M, compressedPaper);
	if(!verify_case(_0, _1, true)) {
print(N);
print(M);
print(compressedPaper);
	}
}
#endif

}
// END CUT HERE
