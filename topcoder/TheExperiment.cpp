// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Manao is conducting an experiment to measure the humidity level of some spongy material. The experiment is conducted in a closed room which is observed from a side, so we will consider it in two dimensions.

The room is N centimeters wide. There are N drop counters built in the ceiling of the room. Drop counter 0 is attached 0.5 centimeters from the left end of the room, and each next one is attached 1 centimeter to the right of the previous one. You are given a vector <string> intensity filled with digits. Concatenate its elements to obtain one string S of length N. The i-th (0-based index) drop counter drips exactly S[i] drops per minute, where S[i] is the digit at the i-th position in S.

Manao is going to place M sponges in the room. All sponges are exactly L centimeters long and their thickness is negligible.
Each sponge must be placed horizontally, it must be entirely within the room, and the distance between the left wall of the room and the sponge must be an integer.
In other words, the coordinate of its left end must be an integer between 0 and N-L, inclusive.
Different sponges must be attached at different heights.
Each sponge will totally absorb every drop that drips at it.
For example, in the following picture, the sponges (from top to bottom) absorb 12, 5, and 3 drops per minute.



The experiment requires the sponges to be attached in such a way that each of them absorbs between A and B drops per minute, inclusive.
Manao is interested in the number of ways in which this can be done.
Two ways P and Q of attaching the sponges are the same if and only if for each sponge S1 in P there exists a sponge S2 in Q such that S1 and S2 lie directly beneath the same sets of drop counters.
A sponge X lies directly beneath a drop counter Y if there is no other sponge between them.
That is, if there is some water dripping from the drop counter Y, it all lands on the sponge X.
Note that according to these definitions the sponges are indistinguishable.

You are given the vector <string> intensity and the ints M, L, A, and B.
Count the number of different ways to attach the sponges and return that count modulo 1,000,000,009.

DEFINITION
Class:TheExperiment
Method:countPlacements
Parameters:vector <string>, int, int, int, int
Returns:int
Method signature:int countPlacements(vector <string> intensity, int M, int L, int A, int B)


CONSTRAINTS
-intensity will contain between 1 and 6 elements, inclusive.
-Each element of intensity will be between 1 and 50 characters long, inclusive.
-Each element of intensity will consist of digits ('0'-'9') only.
-M will be between 1 and 300, inclusive.
-L will be between 1 and N, inclusive, where N is the total number of characters in intensity.
-A will be between 1 and 2700, inclusive.
-B will be between A and 2700, inclusive.


EXAMPLES

0)
{"341156"}
3
3
6
10

Returns: 2

Manao needs to place three sponges of length 3 in such a way that they absorb between 6 and 10 drops per minute. The valid ways to attach the sponges are the following:


In the first way, the sponges receive 8, 6 and 6 drops, from highest to lowest. In the second way, they absorb 7, 7 and 6. Note that Manao could interchange the heights of the lower two sponges in the second picture, but this would result in the same way.

1)
{"999112999"}
2
4
21
30

Returns: 2

One of the platforms should have its left end exactly at the left wall. The other's left end can be either 4 or 5 centimeters away from the left wall.

2)
{"111"}
2
2
2
3

Returns: 0

One of the platforms will never receive enough drops.

3)
{"59059", "110", "1132230231"}
1
5
10
20

Returns: 6



4)
{"111111111111111111111111", "111111111111111111111111111", "11111111111111111111111"}
12
8
4
2700

Returns: 418629948



*/
// END CUT HERE
#line 108 "TheExperiment.cpp"

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

#define MOD 1000000009LL

VI ful;
map<VI, int> fm;
vector< VVI > dp;
map< pair<int, pair<int, int> >, VI> dpful;
string s;
int MM, N, L, A, B;
// water valid in [S, E)
// hard limit: [0, N)
ll f(int M, int S, int E) {
	S=max(0, S);
	E=min(N, E);
	if(M==0) return 1;
	if(S>=E) return 0;
	if(dp[M][S][E]!=-1) return dp[M][S][E];
	
	VI ful;
	
	ll ans = 0;
	//cout<<"f "<<M<<" "<<S<<" "<<E<<endl;
	RANGE(i, max(0, S-L+1), min(N-L+1, E)) {
		ll lans = 0;
		//cout<<"M, i "<<M<<" "<<i<<endl;
		// put at pos i
		int co = 0;
		int fl = 0;
		REP(j, L) {
			if(S<=i+j && i+j<E) {
				co += s[i+j]-'0';
				fl++;
			}
		}
		//cout<<"co "<<co<<endl;
		if(!(A<=co && co<=B)) continue;
		if(fl==L) {
			ful.PB(i);
			VI w=ful;
			sort(ALL(w));
			//cout<<"ful: "<<w<<endl;
			if(fm.count(w)) {
				ful.pop_back();
				continue;
			}
			//cout<<" cont"<<endl;
			fm[w] = 1;
		}
		
		if(M>1) {
			ll sub = 0;
			REP(k, M-1+1) {
				sub += (f(k, S, i) * f(M-1-k, i+L, E)) % MOD;
				sub = sub % MOD;
			}
			lans = (lans + sub) % MOD;
		} else {
			lans++;
		}
		if(fl==L) {
			ful.pop_back();
		}
		//cout<<"M, i "<<M<<" "<<i<<" OK "<<lans<<endl;
		ans = (ans + lans) % MOD;
	}
	//cout<<"f "<<M<<" "<<S<<" "<<E<<" -> "<<ans<<endl;
	return dp[M][S][E] = ans;
}

class TheExperiment {
	public:
	
	int countPlacements(vector <string> intensity, int M, int LL, int AA, int BB) {
		s="";
		L=LL,A=AA,B=BB;
		FOR(e, intensity) s+=*e;
		N = s.size();
		MM=M;
		fm = map<VI, int>();
		ful = VI();
		dp = vector< VVI >(M+1, VVI(N+1, VI(N+1, -1)));
		int ret = f(M, 0, N);
		return ret;
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
#define END	 verify_case(_, TheExperiment().countPlacements(intensity, M, L, A, B));}
int main(){

CASE(4)
	string intensity_[] = {"1111111"};
	  vector <string> intensity(intensity_, intensity_+sizeof(intensity_)/sizeof(*intensity_)); 
	int M = 2; 
	int L = 3; 
	int A = 3; 
	int B = 3; 
	int _ = 3; 
END
//return 0;
CASE(1)
	string intensity_[] = {"999112999"};
	  vector <string> intensity(intensity_, intensity_+sizeof(intensity_)/sizeof(*intensity_)); 
	int M = 2; 
	int L = 4; 
	int A = 21; 
	int B = 30; 
	int _ = 2; 
END
//return 0;
CASE(0)
	string intensity_[] = {"341156"};
	  vector <string> intensity(intensity_, intensity_+sizeof(intensity_)/sizeof(*intensity_)); 
	int M = 3; 
	int L = 3; 
	int A = 6; 
	int B = 10; 
	int _ = 2; 
END
//return 0;
CASE(0)
	string intensity_[] = {"341156"};
	  vector <string> intensity(intensity_, intensity_+sizeof(intensity_)/sizeof(*intensity_)); 
	int M = 3; 
	int L = 3; 
	int A = 6; 
	int B = 10; 
	int _ = 2; 
END
//return 0;
CASE(1)
	string intensity_[] = {"999112999"};
	  vector <string> intensity(intensity_, intensity_+sizeof(intensity_)/sizeof(*intensity_)); 
	int M = 2; 
	int L = 4; 
	int A = 21; 
	int B = 30; 
	int _ = 2; 
END
CASE(2)
	string intensity_[] = {"111"};
	  vector <string> intensity(intensity_, intensity_+sizeof(intensity_)/sizeof(*intensity_)); 
	int M = 2; 
	int L = 2; 
	int A = 2; 
	int B = 3; 
	int _ = 0; 
END
CASE(3)
	string intensity_[] = {"59059", "110", "1132230231"};
	  vector <string> intensity(intensity_, intensity_+sizeof(intensity_)/sizeof(*intensity_)); 
	int M = 1; 
	int L = 5; 
	int A = 10; 
	int B = 20; 
	int _ = 6; 
END
CASE(4)
	string intensity_[] = {"111111111111111111111111", "111111111111111111111111111", "11111111111111111111111"};
	  vector <string> intensity(intensity_, intensity_+sizeof(intensity_)/sizeof(*intensity_)); 
	int M = 12; 
	int L = 8; 
	int A = 4; 
	int B = 2700; 
	int _ = 418629948; 
END

}
// END CUT HERE
