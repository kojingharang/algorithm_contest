// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are the Incubator.
You have the ability to turn normal girls into magical girls.



There are n girls in the city.
The girls are conveniently numbered 0 through n-1.
Some girls love some other girls.
Love is not necessarily symmetric.
It is also possible for a girl to love herself.



You are given a vector <string> love.
Character j of element i of love is 'Y' if girl i loves girl j.
Otherwise, that character is 'N'.
In the rest of the problem statement, we will use love[i][j] to denote the truth value of the statement "girl i loves girl j".



Each girl has two boolean properties: isMagical (is she a magical girl?) and isProtected (is she protected by some girl?).
Initially, for each girl i we have isMagical[i] = False and isProtected[i] = False.



At any moment, you can choose an ordinary girl and turn her into a magical girl.
That is, you can take a girl i such that isMagical[i] = False, and change isMagical[i] to True.



Each such change will trigger a series of events:

Each magical girl will protect all girls she loves: if isMagical[i] and love[i][j], then isProtected[j] is set to True.
Each protected girl will also protect all girls she loves: if isProtected[i] and love[i][j], then isProtected[j] is set to True.

Note that some of these changes may in turn trigger other changes, as more and more girls become protected.



Once there are no more changes, you can again change another ordinary girl into a magical one, and so on.
Your goal is to reach a situation with many girls that are magical, but not protected.
That is, you are interested in girls such that isMagical[i] = True and isProtected[i] = False.
Return the maximum number of such girls in a situation that can be reached using the above process.

DEFINITION
Class:Incubator
Method:maxMagicalGirls
Parameters:vector <string>
Returns:int
Method signature:int maxMagicalGirls(vector <string> love)


CONSTRAINTS
-n will be between 1 and 50, inclusive.
-love will contain exactly n elements.
-Each element of love will contain exactly n characters.
-Each character in each element of love will be either 'Y' or 'N'.


EXAMPLES

0)
{"NY","NN"}

Returns: 1

One optimal solution is to change girl 0 to a magical girl.
Girl 0 will be magical and she will not be protected.
It is not possible to have two girls that are both magical and not protected:
if you change both girls to magical girls (in any order), you will get a situation in which girl 1 is protected.

1)
{"NYN", "NNY", "NNN"}

Returns: 1

Again, there is no way to create more than one unprotected magical girl.
For example, if we start by making girl 2 magical, and then make girl 0 magical, magical girl 0 will protect girl 1, and protected girl 1 will protect girl 2.
Thus, in this case girl 0 will be magical and unprotected, girl 1 will be ordinary and protected, and girl 2 will be magical and protected.

2)
{"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"}

Returns: 2



3)
{"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"}

Returns: 2



4)
{"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"}

Returns: 5



5)
{"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"}

Returns: 2



6)
{"Y"}

Returns: 0

Note that a girl may love herself.

*/
// END CUT HERE
#line 122 "Incubator.cpp"

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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << "\n"; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


class Incubator {
	public:
	int maxMagicalGirls(vector <string> love) {
		int N = love.size();
		VI done(N);
		REP(k, N) REP(i, N) REP(j, N) if(love[i][k]=='Y' && love[k][j]=='Y') love[i][j]='Y';
		//cout<<love<<endl;
		VI w(N);
		REP(i, N) w[i] = count(ALL(love[i]), 'Y');
		
		int ans = 0;
		REP(co, N+1) {
			REP(i, N) {
				if(co==w[i]) {
					int ok=1;
					if(love[i][i]=='Y') ok=0;
					REP(j, N) {
						if(love[i][j]=='Y' && done[j]) ok=0;
					}
					if(ok) {
						ans++;
						done[i]=1;
					}
				}
			}
		}
		cout<<ans<<endl;
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
#define END	 verify_case(_, Incubator().maxMagicalGirls(love));}
int main(){

CASE(0)
	string love_[] = {"NY","NN"};
	  vector <string> love(love_, love_+sizeof(love_)/sizeof(*love_)); 
	int _ = 1; 
END
CASE(1)
	string love_[] = {"NYN", "NNY", "NNN"};
	  vector <string> love(love_, love_+sizeof(love_)/sizeof(*love_)); 
	int _ = 1; 
END
CASE(2)
	string love_[] = {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"};
	  vector <string> love(love_, love_+sizeof(love_)/sizeof(*love_)); 
	int _ = 2; 
END
CASE(3)
	string love_[] = {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"};
	  vector <string> love(love_, love_+sizeof(love_)/sizeof(*love_)); 
	int _ = 2; 
END
CASE(4)
	string love_[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"};
	  vector <string> love(love_, love_+sizeof(love_)/sizeof(*love_)); 
	int _ = 5; 
END
CASE(5)
	string love_[] = {"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"};
	  vector <string> love(love_, love_+sizeof(love_)/sizeof(*love_)); 
	int _ = 2; 
END
CASE(6)
	string love_[] = {"Y"};
	  vector <string> love(love_, love_+sizeof(love_)/sizeof(*love_)); 
	int _ = 0; 
END

}
// END CUT HERE
