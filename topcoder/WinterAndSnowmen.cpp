// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
It's winter time!
Time for snowmen to play some games.




Two snowmen are playing a game.
In this game, the first snowman must choose a subset of the set {1, 2, ..., N}, and the second one must choose a subset of the set {1, 2, ..., M}.
The following two conditions must be fulfilled:


The two sets have an empty intersection.


The XOR of all elements in the first set is less than the XOR of all elements in the second set.






You are given two ints N and M.
Let X be the total number of different ways to choose the pair of sets.
Return the value (X modulo 1,000,000,007).


DEFINITION
Class:WinterAndSnowmen
Method:getNumber
Parameters:int, int
Returns:int
Method signature:int getNumber(int N, int M)


NOTES
-XOR (exclusive or) is a binary operation, performed on two numbers in binary notation. First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each bit where the numbers differ the result has 1 in its binary representation. It has 0 in all other positions.
-For example 42 XOR 7 is performed as follows. First, the numbers are converted to binary: 42 is 101010 and 7 is 111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 7 becomes 000111. Then 101010 XOR 000111 = 101101 (the result has ones only in the positions where the two numbers differ). Then the result can be converted back to decimal notation. In this case 101101 = 45, so 42 XOR 7 = 45.
-The XOR of an empty set is 0.


CONSTRAINTS
-N will be between 1 and 2000, inclusive.
-M will be between 1 and 2000, inclusive.


EXAMPLES

0)
2
2

Returns: 4

The following 4 pairs of subsets are possible in this case:


{} and {1}


{} and {2}


{} and {1, 2}


{1} and {2}



1)
1
1

Returns: 1

The only pair possible in this case is {} and {1}.

2)
3
5

Returns: 74



3)
7
4

Returns: 216



4)
47
74

Returns: 962557390



******************************/
// END CUT HERE
#line 109 "WinterAndSnowmen.cpp"
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
#define PRINT3(table, W, H, D) REP(x, W) { REP(y, H) { REP(d, D) cout<<table[x][y][d]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

const int mod=1000000007;
//int dp[2][2048][2048]; // dp[I][XA][XB] ... i in [0, I)
// same_bits diff_bit
// dp[I%2][PREFIX_XA_XOR_XB][DIFFBIT_XA][DIFFBIT_XB]
// ... i in [0, min(I, N)) の部分集合 SetA の xor を XA, 
//     i in [0, min(I, M)) の部分集合 SetB の xor を XB としたとき,
//     XA^XB の prefix 部分が PREFIX_XA_XOR_XB で,
//     XA の「違うビット位置」のビットが DIFFBIT_XA で, 
//     XB の「違うビット位置」のビットが DIFFBIT_XB のときの組み合わせ数
int dp[2][2048][2][2];
#define PLUS(a, b) (a) = ((ll)(a)+(b))%mod
class WinterAndSnowmen {
	public:
	int getNumber(int N, int M) {
		int bits = 1;
		while(1<<bits <= max(N, M)) bits++;
		
		int ans=0;
		REP(same_bits, bits) {
			CLEAR(dp, 0);
			int men=0;
			dp[men][0][0][0]=1;
			RANGE(i, 1, max(N, M)+1) {
				CLEAR(dp[men^1], 0);
				REP(prefix, 1<<same_bits) REP(diffA, 2) REP(diffB, 2) {
					if(dp[men][prefix][diffA][diffB]==0) continue;
					int iPrefix = i>>(bits-same_bits);
					int iDiff = (i>>(bits-same_bits-1))&1;
					PLUS(dp[men^1][prefix][diffA][diffB], dp[men][prefix][diffA][diffB]);
					if(i<N+1) PLUS(dp[men^1][prefix^iPrefix][diffA^iDiff][diffB], dp[men][prefix][diffA][diffB]);
					if(i<M+1) PLUS(dp[men^1][prefix^iPrefix][diffA][diffB^iDiff], dp[men][prefix][diffA][diffB]);
//					if(i<N+1) {
//						int xorPrefixA = iPrefix;
//						int xorPrefixB = 0;
//						int xorDiffA = iDiff;
//						int xorDiffB = 0;
//						PLUS(dp[men^1][prefix^xorPrefixA^xorPrefixB][diffA^xorDiffA][diffB^xorDiffB], dp[men][prefix][diffA][diffB]);
//					}
//					if(i<M+1) {
//						int xorPrefixA = 0;
//						int xorPrefixB = iPrefix;
//						int xorDiffA = 0;
//						int xorDiffB = iDiff;
//						PLUS(dp[men^1][prefix^xorPrefixA^xorPrefixB][diffA^xorDiffA][diffB^xorDiffB], dp[men][prefix][diffA][diffB]);
//					}
				}
				men^=1;
			}
			PLUS(ans, dp[men][0][0][1]);
		}
		return ans;
	}
};

/*
class WinterAndSnowmen {
	public:
	int getNumber(int N, int M) {
		int bits = 1;
		while(1<<bits <= max(N, M)) bits++;
		int xors = 1<<bits;
//		cout<<"bits "<<bits<<endl;
		
		int ans=0;
		REP(same_bits, bits) {
			CLEAR(dp, 0);
			int men=0;
			dp[men][0][0]=1;
			RANGE(i, 1, max(N, M)+1) {
				CLEAR(dp[men^1], 0);
				REP(xa, xors) REP(xb, xors) {
					if(dp[men][xa][xb]==0) continue;
					PLUS(dp[men^1][xa][xb], dp[men][xa][xb]);
					if(i<N+1) PLUS(dp[men^1][xa^(i)][xb], dp[men][xa][xb]);
					if(i<M+1) PLUS(dp[men^1][xa][xb^(i)], dp[men][xa][xb]);
				}
				men^=1;
			}
			REP(xa, xors) REP(xb, xors) if(((xa^xb)>>(bits-same_bits))==0 && ((xa^xb)>>(bits-same_bits-1))&1 && xa<xb) PLUS(ans, dp[men][xa][xb]);
//			cout<<ans<<endl;
		}
		return ans;
	}
};
class WinterAndSnowmenSameBits {
	public:
	int getNumber(int N, int M) {
		CLEAR(dp, 0);
		int men=0;
		dp[men][0][0]=1;
		int xors = 1;
		while(xors <= max(N, M)) xors*=2;
		
		RANGE(i, 1, max(N, M)+1) {
			CLEAR(dp[men^1], 0);
			REP(xa, xors) REP(xb, xors) {
				if(dp[men][xa][xb]==0) continue;
				PLUS(dp[men^1][xa][xb], dp[men][xa][xb]);
				if(i<N+1) PLUS(dp[men^1][xa^(i)][xb], dp[men][xa][xb]);
				if(i<M+1) PLUS(dp[men^1][xa][xb^(i)], dp[men][xa][xb]);
			}
			men^=1;
		}
		int ans=0;
		REP(xa, xors) REP(xb, xors) if(xa<xb) PLUS(ans, dp[men][xa][xb]);
		REP(xa, xors) REP(xb, xors) if(xa<xb) cout<<"xa xb co "<<xa<<" "<<xb<<" "<<dp[men][xa][xb]<<endl;
		return ans;
	}
};
*/

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, WinterAndSnowmen().getNumber(N, M));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int N = 2; 
	int M = 2; 
	int _ = 4; 
END
//return 0;
CASE(1)
	int N = 1; 
	int M = 1; 
	int _ = 1; 
END
CASE(2)
	int N = 3; 
	int M = 5; 
	int _ = 74; 
END
CASE(3)
	int N = 7; 
	int M = 4; 
	int _ = 216; 
END
CASE(4)
	int N = 47; 
	int M = 74; 
	int _ = 962557390; 
END
CASE(4)
	int N = 2000; 
	int M = 2000; 
	int _ = 962557390; 
END
#if 0  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: int
start_time=clock();
	int N = UNIFORM_LL(0, 100); 
// param type: int
start_time=clock();
	int M = UNIFORM_LL(0, 100); 
	int _0 = WinterAndSnowmen().getNumber(N, M);
	int _1 = WinterAndSnowmenTry().getNumber(N, M);
	if(!verify_case(_0, _1, true)) {
print(N);
print(M);
	}
}
#endif

}
// END CUT HERE
