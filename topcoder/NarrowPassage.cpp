// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// There is a narrow passage of length L.
We will use a coordinate system where 0 and L are the ends of the passage.


Inside the passage there are some wolves.
You are given two vector <int>s a and b with the same number of elements.
The elements of a are the current coordinates of all wolves.
For each wolf, the corresponding element of b is the coordinate where the wolf wants to go.
That is, for each valid i, wolf i wants to move from a[i] to b[i].


The passage is so narrow that wolves cannot pass by each other.
In other words, the relative order of the wolves cannot change while they are in the passage.
Luckily, there is a lot of empty space on each end of the passage.
If some wolves reach the same end of the passage, they can change their order arbitrarily before reentering the passage.


All wolves must finish at their desired coordinates.
Return the minimum total distance the wolves have to travel within the passage in order to reach their final configuration.
Note that the distance traveled while they are reordering at the ends of the passage does not count.

DEFINITION
Class:NarrowPassage
Method:minDist
Parameters:int, vector <int>, vector <int>
Returns:int
Method signature:int minDist(int L, vector <int> a, vector <int> b)


CONSTRAINTS
-L will be between 2 and 1,000,000, inclusive.
-a and b will each contain between 1 and 50 elements, inclusive.
-a and b will contain the same number of elements.
-Each element of a and b will be between 1 and L-1, inclusive.
-Elements in a will be pairwise distinct.
-Elements in b will be pairwise distinct.


EXAMPLES

0)
5
{1, 2}
{3, 4}

Returns: 4

We have two wolves.
One of them wants to go from 1 to 3, the other one from 2 to 4.
They can do this without passing each other.
(For example, they can both move simultaneously. 
Alternately, wolf 1 can move before wolf 0 does.
There are no restrictions on the movement of wolves other than they cannot pass each other within the passage.)
The total distance traveled in this case is |1-3| + |2-4| = 4.

1)
10
{3, 9}
{8, 6}

Returns: 14

One of the optimal ways looks as follows:

Wolf 1 moves from 9 to 10.
Wolf 0 moves from 3 to 10.
Wolf 1 moves from 10 to 6.
Wolf 0 moves from 10 to 8.



2)
265467
{133548, 103861, 29821, 199848, 92684, 219824, 215859, 62821, 172409, 109235,
38563, 148854, 24742, 174068, 205005, 75922, 87316, 5542, 57484, 40792,
25229, 152216, 21547, 22203, 84712, 231522, 235703, 184895, 100787, 174440,
156904, 84898, 185568, 108732, 260098, 89488, 221604, 104555, 165775, 90444,
81952, 149671, 209674, 22185, 45420, 41928, 16098, 65324, 90870, 35243}
{150289, 135139, 69841, 227226, 177427, 230314, 199175, 81572, 220468, 151049,
40009, 145963, 115246, 252932, 263651, 38434, 120096, 69576, 29789, 115046,
33310, 260771, 5723, 80733, 107864, 142447, 235490, 242149, 124564, 134602,
245962, 7078, 215816, 219864, 190499, 210237, 212894, 142760, 126472, 201935,
119308, 120211, 235235, 19446, 87314, 17286, 61990, 102050, 261812, 257}

Returns: 7148670



3)
1000000
{706292, 756214, 490048, 228791, 567805, 353900, 640393, 562496, 217533, 934149,
938644, 127480, 777134, 999144, 41485, 544051, 417987, 767415, 971662, 959022,
670563, 34065, 518183, 750574, 546576, 207758, 159932, 429345, 670513, 271901,
476062, 392721, 774733, 502586, 915436, 120280, 951729, 699859, 581770, 268966,
79392, 888601, 378829, 350198, 939459, 644983, 605862, 721305, 269232, 137587}
{322468, 673534, 83223, 551733, 341310, 485064, 885415, 927526, 159402, 28144,
441619, 305530, 883149, 413745, 932694, 214862, 677401, 104356, 836580, 300580,
409942, 748444, 744205, 119051, 999286, 462508, 984346, 887773, 856655, 245559,
418763, 840266, 999775, 962927, 779570, 488394, 760591, 326325, 206948, 13999,
285467, 401562, 786209, 169847, 171326, 2901, 296531, 572035, 364920, 939046}

Returns: 45670501



******************************/
// END CUT HERE
#line 112 "NarrowPassage.cpp"
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

class NarrowPassage {
	public:
	int minDist(int L, vector <int> a, vector <int> b) {
		
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
#define END	 verify_case(_, NarrowPassage().minDist(L, a, b));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int L = 5; 
	int a_[] = {1, 2};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {3, 4};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	int _ = 4; 
END
CASE(1)
	int L = 10; 
	int a_[] = {3, 9};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {8, 6};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	int _ = 14; 
END
CASE(2)
	int L = 265467; 
	int a_[] = {133548, 103861, 29821, 199848, 92684, 219824, 215859, 62821, 172409, 109235,
38563, 148854, 24742, 174068, 205005, 75922, 87316, 5542, 57484, 40792,
25229, 152216, 21547, 22203, 84712, 231522, 235703, 184895, 100787, 174440,
156904, 84898, 185568, 108732, 260098, 89488, 221604, 104555, 165775, 90444,
81952, 149671, 209674, 22185, 45420, 41928, 16098, 65324, 90870, 35243};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {150289, 135139, 69841, 227226, 177427, 230314, 199175, 81572, 220468, 151049,
40009, 145963, 115246, 252932, 263651, 38434, 120096, 69576, 29789, 115046,
33310, 260771, 5723, 80733, 107864, 142447, 235490, 242149, 124564, 134602,
245962, 7078, 215816, 219864, 190499, 210237, 212894, 142760, 126472, 201935,
119308, 120211, 235235, 19446, 87314, 17286, 61990, 102050, 261812, 257};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	int _ = 7148670; 
END
CASE(3)
	int L = 1000000; 
	int a_[] = {706292, 756214, 490048, 228791, 567805, 353900, 640393, 562496, 217533, 934149,
938644, 127480, 777134, 999144, 41485, 544051, 417987, 767415, 971662, 959022,
670563, 34065, 518183, 750574, 546576, 207758, 159932, 429345, 670513, 271901,
476062, 392721, 774733, 502586, 915436, 120280, 951729, 699859, 581770, 268966,
79392, 888601, 378829, 350198, 939459, 644983, 605862, 721305, 269232, 137587};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {322468, 673534, 83223, 551733, 341310, 485064, 885415, 927526, 159402, 28144,
441619, 305530, 883149, 413745, 932694, 214862, 677401, 104356, 836580, 300580,
409942, 748444, 744205, 119051, 999286, 462508, 984346, 887773, 856655, 245559,
418763, 840266, 999775, 962927, 779570, 488394, 760591, 326325, 206948, 13999,
285467, 401562, 786209, 169847, 171326, 2901, 296531, 572035, 364920, 939046};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	int _ = 45670501; 
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
	int L = UNIFORM_LL(0, 100); 
// param type: int
	vector <int> a; 
	{
		int N=UNIFORM_LL(1, 51);
		a = vector <int>(N); 
		REP(i, N) {
			a[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> b; 
	{
		int N=UNIFORM_LL(1, 51);
		b = vector <int>(N); 
		REP(i, N) {
			b[i] = UNIFORM_LL(0, 1000);
		}
	}
	int _0 = NarrowPassage().minDist(L, a, b);
	int _1 = NarrowPassageRef().minDist(L, a, b);
	if(!verify_case(_0, _1, true)) {
print(L);
print(a);
print(b);
	}
}
#endif

}
// END CUT HERE
