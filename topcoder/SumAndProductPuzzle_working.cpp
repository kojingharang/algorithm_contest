// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Consider the following story.



STORY STARTS HERE.



There were three mathematicians: Susan, Priscilla, and Bob.
Bob picked two positive integers x and y such that x <= y.
He then told their sum to Susan and their product to Priscilla.
Susan and Priscilla both knew all the facts listed above.
Then, Susan and Priscilla made the following statements:

Susan: "I am certain that you cannot determine my number."
Priscilla: "Thanks for telling me that. Now I'm sure that your number is S."




STORY ENDS HERE.



My friends Baska and Olivia are fond of puzzles.
Recently, Baska told Olivia the above story.
When telling the story, Baska used some specific positive integer (for example, 9) instead of S.
Then, she asked Olivia to determine x and y.
Olivia easily came up with the unique solution.



Of course, you don't know the integer Baska used instead of S.
Instead, you are given two ints A and B.
Find all S between A and B, inclusive, such that the above discussion between Baska and Olivia could have happened.
Return the sum of all such S.


DEFINITION
Class:SumAndProductPuzzle
Method:getSum
Parameters:int, int
Returns:long long
Method signature:long long getSum(int A, int B)


NOTES
-Watch out for overflow. The return value may overflow a 32-bit integer variable.


CONSTRAINTS
-A will be between 1 and 5,000,000, inclusive.
-B will be between A and 5,000,000, inclusive.


EXAMPLES

0)
30
33

Returns: 33

The only valid S in this range is 33.
The unique pair (x,y) that corresponds to S=33 is (1,32).

1)
8
11

Returns: 19



2)
40
43

Returns: 0

Sometimes the given range doesn't contain any valid S. In such case the correct return value is 0.

3)
47
74

Returns: 168



4)
1
2

Returns: 0



******************************/
// END CUT HERE
#line 106 "SumAndProductPuzzle.cpp"
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
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

VI make_primes(int N) { // return all prime numbers in [0, N)  memory: O(N) time: <20N
	vector<bool> p(N, true);
	VI out;
	for(int i=2;i<N;i++) if(p[i]) { out.PB(i); for(int j=i*2;j<N;j+=i) p[j]=false; }
	return out;
}
class SumAndProductPuzzle {
	public:
	long long getSum(int A, int B) {
		int N = 5000000;
//		N=1000;
		vector<bool> isp(N+1, true);
		RANGE(p, 2, N+1) {
			if(isp[p])for(int q=p*2;q<N+1;q+=p) isp[q]=false;
		}
		// motivation: S を p * q に分けて、p+q-1が合成数になるものが1コかどうかを知りたい。
		// p in [2, N], S in p*[2,3,4,...] とすると (1, S) 以外の全ての p, q の組み合わせが列挙できる。
		// 
		// 850ms (arena)
		vector<bool> ref(N+1, true); // 素数であるまたは p+q-1 が合成数なpqが1コある
		RANGE(p, 2, N+1) {
			// S を p * q に分ける. pは素数とは限らない
			{
				// p=S, q=1 のときは !isp[p+q-1] == !isp[p] == false
//				cout<<p<<" "<<isp[p]<<"  "<<isp[p+1-1]<<endl;
				for(int S=p*2;S<N+1;S+=p) {
					int q=S/p;
					if(!isp[p+q-1]) ref[S]=false;
				}
			}
		}
		
//		vector<bool> pok(N+1, true);
		// N の約数すべてについて何かしらする
		// 82sec
//		REP(i, N+1)if(!isp[i]) {
//			int co=0;
//			for(ll d=1; d*d<=i; d++)if(i%d==0) {
//				if(!isp[d+i/d-1]) co++;
//			}
//			if(co!=1) pok[i]=false;
//		}
		// 1.4sec (arena)
//		vector<int> cnt(N+1);
//		RANGE(p, 1, N+1) {
//			// S を p * q に分ける. pは素数とは限らない
//			for(int S=p;S<N+1;S+=p) {
//				int q=S/p;
//				if(p<=q && !isp[p+q-1]) cnt[S]++;
//			}
//		}
//		REP(i, N+1) pok[i] = cnt[i]==1;
//		REP(i, N+1) if(ref[i]!=pok[i]) cout<<"DIFF "<<i<<" "<<ref[i]<<endl;
		
		
//		cout<<vector<bool>(ref.begin(), ref.begin()+50)<<endl;
//		REP(i, N+1) if(isp[i]) if(!ref[i]) cout<<i<<endl;
//		vector<bool> r(N+1, true);
//		RANGE(p, 2, N+1) {
//			{
//				// pが合成数の場合、p=S, q=1 のときは !isp[p+q-1] == !isp[p] == true
//				// p+q-1が合成数なS=pqを１こみつけたことになる(point)
//				// S=[2,S-1]x[S/2, ...2]
//				if(p==20) cout<<"20 1: "<<!isp[p]<<endl;
////				cout<<p<<" "<<isp[p]<<"  "<<isp[p+1-1]<<endl;
//				for(int S=p*2;S<N+1;S+=p) {
//					assert(!isp[S]);
//					int q=S/p;
//					// p==1 or q==1 じゃない S=pq はすべてこのループにでてくる
//					if(S==20) cout<<p<<" "<<q<<endl;
//					if(p<=q && !isp[p+q-1]) r[S]=false;
//				}
//			}
//		}
//		int co=0;
//		REP(i, N+1) if(ref[i]!=r[i]) co++;
//		REP(i, 100) if(ref[i]!=r[i])cout<<i<<" "<<ref[i]<<" "<<r[i]<<endl;
//		cout<<"DIFF "<<co<<endl;
//		cout<<endl;
//		cout<<isp<<endl;
		ll ans=0;
//		RANGE(i, 2, 35) cout<<i<<" "<<isp[i-1]<<endl;
		RANGE(S, A, B+1) {
			if(!isp[S-1]) {
				if(ref[S-1]) {
					// なんで S -> 1, S-1 に分解するだけでいいのか？ 全通り試すんでなく。
					// Sから推測できるいくつかあるPのうち、「P=pq のうち p+q-1 が合成数のものが1コある」ようなPがあればいい
					// S=1+(S-1)と分解してP=1*(S-1) としたときに"p+q-1が合成数"が１コならOK
					// P=1*(S-1)では満たさなくて他の S=a+b では満たすということがないのはなぜか？
					// P=2*(S-2)のpqは例えば 2,S-2 -> p+q-1=S
					ans+=S;
				} else {
					// 例 S=40
					// Pとしては1*39 2*38 3*37 などがある. ここにきたので 1*39 は"p+q-1が合成数"が１こじゃない。
					// P は
					// 2*38 =  1*76 or 2*38 or 4*19
					// p+q-1 = 76      39      22
					// 合成数は3つ
					// 3*37 = 1*111 or 3*37
					// p+q-1 = 111 or (39)
					// 4*36 = 1*152 or ... or 4*36
					// p+q-1 =  152 or        (39)
					// K(>=2) * (S-K) = 1*P ... or K*(S-K) or ...
					//                1+P-1 = P, K+(S-K)+1 = S-1 ... !isp[S-1] なので S-1 は合成数
					// Sを (K, S-K) (K>=2)にわけたとき、どうわけても
					//  P = K(S-K) = 1 * K(S-K) と分けると p+q-1 = 1+K(S-K)-1 = K(S-K) は合成数
					//  P = K(S-K) = K * (S-K) と分けると p+q-1 = K+(S-K)-1 = S-1 →合成数
//					cout<<S<<endl;
//					RANGE(k, 1, S/2+1) {
//						ll pi = (ll)k*(S-k);
//						if(S-k>=1 && pi<ref.size()) {
//							if(ref[pi]) cout<<"!pok[S-1] but pok k*(S-k) "<<k<<" "<<S-k<<endl;
//						}
//					}
				}
			}
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const long long& Expected, const long long& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, SumAndProductPuzzle().getSum(A, B));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int A = 30; 
	int B = 33; 
	long long _ = 33LL; 
END
//return 0;
CASE(1)
	int A = 8; 
	int B = 11; 
	long long _ = 19LL; 
END
CASE(2)
	int A = 40; 
	int B = 43; 
	long long _ = 0LL; 
END
CASE(3)
	int A = 47; 
	int B = 74; 
	long long _ = 168LL; 
END
CASE(4)
	int A = 1; 
	int B = 2; 
	long long _ = 0LL; 
END
//return 0;
CASE(0)
	int A = 1; 
	int B = 5000000; 
	long long _ = 392026464258LL; 
END
return 0;
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
	int A = UNIFORM_LL(0, 100); 
// param type: int
	int B = UNIFORM_LL(0, 100); 
	long long _0 = SumAndProductPuzzle().getSum(A, B);
	long long _1 = SumAndProductPuzzleRef().getSum(A, B);
	if(!verify_case(_0, _1, true)) {
print(A);
print(B);
	}
}
#endif

}
// END CUT HERE
