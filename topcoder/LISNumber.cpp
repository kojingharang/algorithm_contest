// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Let A be a sequence of integers.
The LISNumber of A is the smallest positive integer L such that A can be obtained by concatenating L strictly increasing sequences.
For example, the LISNumber of A = {1, 4, 4, 2, 6, 3} is 4, since we can obtain A as {1, 4} + {4} + {2, 6} + {3}, and there is no way to create A by concatenating 3 (or fewer) strictly increasing sequences.
The LISNumber of a strictly increasing sequence is 1.

You have N types of cards.
For each i, 0 <= i < N, you have cardsnum[i] cards of the i-th type.
Each card of the i-th type contains the number i.

You are given the vector <int> cardsnum and an int K.
You want to arrange all the cards you have into a row in such a way that the resulting sequence of integers has LISNumber K.
Note that you must use all the cards you have, you can only choose their order.

Let X be the number of different valid sequences you can produce.
Compute and return the number X, modulo 1,000,000,007.

DEFINITION
Class:LISNumber
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> cardsnum, int K)


CONSTRAINTS
-cardsnum will contain between 1 and 36 elements, inclusive.
-Each element of cardsnum will be between 1 and 36, inclusive.
-K will be between 1 and 1296, inclusive.


EXAMPLES

0)
{1, 1, 1}
2

Returns: 4

In this case, there are 3 types of cards and you have one of each. Among the 6 sequences you can make, the following 4 have LISNumber 2:

{0, 2, 1}
{1, 0, 2}
{1, 2, 0}
{2, 0, 1}



1)
{2}
1

Returns: 0

The only sequence you can make is {0, 0} and its LISNumber is 2.

2)
{36, 36, 36, 36, 36}
36

Returns: 1

Only the sequence {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, ... (36 times) ... } has LISNumber 36.

3)
{3, 2, 11, 5, 7}
20

Returns: 474640725



4)
{31, 4, 15, 9, 26, 5, 35, 8, 9, 7, 9, 32, 3, 8, 4, 6, 26}
58

Returns: 12133719



5)
{27, 18, 28, 18, 28, 4, 5, 9, 4, 5, 23, 5,
 36, 28, 7, 4, 7, 13, 5, 26, 6, 24, 9, 7,
 7, 5, 7, 24, 7, 9, 36, 9, 9, 9, 5, 9}
116

Returns: 516440918



*/
// END CUT HERE
#line 96 "LISNumber.cpp"

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


#define MOD 1000000007LL
#define N_MAX 1300
#define K_MAX 1300
int comb[N_MAX][K_MAX];
ll combf(int n, int k) {
	if(!(0<=n && n<N_MAX)) return 0;
	if(!(0<=k && k<K_MAX)) return 0;
	//if(n>=N_MAX) {cout<<"N_MAX <= "<<n<<endl;return 0;}
	//if(k>=K_MAX) {cout<<"K_MAX <= "<<k<<endl;return 0;}
	//cout<<"comb "<<n<<" "<<k<<endl;
	return comb[n][k];
}

class LISNumber {
	public:
	int count(vector <int> CS, int K) {
		REP(n, N_MAX) comb[n][0] = 1;
		RANGE(n, 1, N_MAX) RANGE(m, 1, K_MAX) comb[n][m] = ((ll)comb[n-1][m-1] + comb[n-1][m]) % MOD;
		
		int N=CS.size();
		VVI dp(N+1, VI(K+1)); // dp[n][k] ... CS[i], i in [0, n) を使って k 個の LIS を作る方法の個数 % MOD
		dp[0][0] = 1;
		ll sum = 1;
		RANGE(i, 1, N+1) {
			RANGE(k, 1, K+1) {
				RANGE(pk, 0, k+1) {
					int add = k-pk; // in [0, k]
					int rest = CS[i-1] - add;
					ll plus = dp[i-1][pk] * combf(sum-(pk-rest)-1+add, add) % MOD * combf(pk, rest) % MOD;
					dp[i][k] += plus;
					dp[i][k] %= MOD;
				}
			}
			sum += CS[i-1];
		}
		return dp[N][K];
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
#define END	 verify_case(_, LISNumber().count(cardsnum, K));}
int main(){
//CASE(3)
//	int cardsnum_[] = {3, 2};
//	  vector <int> cardsnum(cardsnum_, cardsnum_+sizeof(cardsnum_)/sizeof(*cardsnum_)); 
//	int K = 4; 
//	int _ = 6; 
//END
//return 0;



CASE(0)
	int cardsnum_[] = {1, 1, 1};
	  vector <int> cardsnum(cardsnum_, cardsnum_+sizeof(cardsnum_)/sizeof(*cardsnum_)); 
	int K = 2; 
	int _ = 4; 
END
//return 0;
CASE(1)
	int cardsnum_[] = {2};
	  vector <int> cardsnum(cardsnum_, cardsnum_+sizeof(cardsnum_)/sizeof(*cardsnum_)); 
	int K = 1; 
	int _ = 0; 
END
CASE(2)
	int cardsnum_[] = {36, 36, 36, 36, 36};
	  vector <int> cardsnum(cardsnum_, cardsnum_+sizeof(cardsnum_)/sizeof(*cardsnum_)); 
	int K = 36; 
	int _ = 1; 
END
CASE(3)
	int cardsnum_[] = {3, 2, 11, 5, 7};
	  vector <int> cardsnum(cardsnum_, cardsnum_+sizeof(cardsnum_)/sizeof(*cardsnum_)); 
	int K = 20; 
	int _ = 474640725; 
END
//return 0;
CASE(4)
	int cardsnum_[] = {31, 4, 15, 9, 26, 5, 35, 8, 9, 7, 9, 32, 3, 8, 4, 6, 26};
	  vector <int> cardsnum(cardsnum_, cardsnum_+sizeof(cardsnum_)/sizeof(*cardsnum_)); 
	int K = 58; 
	int _ = 12133719; 
END
CASE(5)
	int cardsnum_[] = {27, 18, 28, 18, 28, 4, 5, 9, 4, 5, 23, 5,
 36, 28, 7, 4, 7, 13, 5, 26, 6, 24, 9, 7,
 7, 5, 7, 24, 7, 9, 36, 9, 9, 9, 5, 9};
	  vector <int> cardsnum(cardsnum_, cardsnum_+sizeof(cardsnum_)/sizeof(*cardsnum_)); 
	int K = 116; 
	int _ = 516440918; 
END

}
// END CUT HERE
