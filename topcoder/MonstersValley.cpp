// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Manao is traversing a valley inhabited by monsters. During his journey, he will encounter several monsters one by one. The scariness of each monster is a positive integer. Some monsters may be scarier than others. The i-th (0-based index) monster Manao will meet has scariness equal to dread[i].

Manao is not going to fight the monsters. Instead, he will bribe some of them and make them join him. To bribe the i-th monster, Manao needs price[i] gold coins. The monsters are not too greedy, therefore each value in price will be either 1 or 2.

At the beginning, Manao travels alone. Each time he meets a monster, he first has the option to bribe it, and then the monster may decide to attack him. A monster will attack Manao if and only if he did not bribe it and its scariness is strictly greater than the total scariness of all monsters in Manao's party. In other words, whenever Manao encounters a monster that would attack him, he has to bribe it. If he encounters a monster that would not attack him, he may either bribe it, or simply walk past the monster.



Consider this example: Manao is traversing the valley inhabited by the Dragon, the Hydra and the Killer Rabbit. When he encounters the Dragon, he has no choice but to bribe him, spending 1 gold coin (in each test case, Manao has to bribe the first monster he meets, because when he travels alone, the total scariness of monsters in his party is zero). When they come by the Hydra, Manao can either pass or bribe her. In the end, he needs to get past the Killer Rabbit. If Manao bribed the Hydra, the total scariness of his party exceeds the Rabbit's, so they will pass. Otherwise, the Rabbit has to be bribed for two gold coins. Therefore, the optimal choice is to bribe the Hydra and then to walk past the Killer Rabbit. The total cost of getting through the valley this way is 2 gold coins.

You are given the vector<long long> dread and the vector <int> price. Compute the minimum price Manao will pay to safely pass the valley.

DEFINITION
Class:MonstersValley
Method:minimumPrice
Parameters:vector<long long>, vector <int>
Returns:int
Method signature:int minimumPrice(vector<long long> dread, vector <int> price)


CONSTRAINTS
-dread will contain between 1 and 50 elements, inclusive.
-Each element of dread will be between 1 and 1,000,000,000,000 (10^12), inclusive.
-price will contain the same number of elements as dread.
-Each element of price will be either 1 or 2.


EXAMPLES

0)
{8, 5, 10}
{1, 1, 2}

Returns: 2

The example from the problem statement.

1)
{1, 2, 4, 1000000000}
{1, 1, 1, 2}

Returns: 5

Manao has to bribe all monsters in the valley.

2)
{200, 107, 105, 206, 307, 400}
{1, 2, 1, 1, 1, 2}

Returns: 2

Manao can bribe monsters 0 and 3.

3)
{5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333}
{2, 2, 1, 1, 1, 1, 2, 1, 2, 1}

Returns: 5

Bribing monsters 0, 1 and 5 is sufficient to pass safely.

*/
// END CUT HERE
#line 68 "MonstersValley.cpp"

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

#define INF (1<<30)

class MonstersValley {
	public:
	int minimumPrice(vector<long long> D, vector <int> P) {
		int N=D.size();
		int LIM=accumulate(ALL(P), 0)+1;
		VI w(LIM, -INF);
		w[0]=0;
		REP(i, N) {
			REP(jj, LIM) {
				int j=LIM-jj-1;
				if(j+P[i]<LIM && w[j]!=-INF) {
					w[j+P[i]] = max(w[j+P[i]], w[j]+D[i]);
				}
			}
			REP(j, LIM) {
				if(w[j]<D[i]) w[j]=-INF;
			}
			//cout<<w<<endl;
		}
		//cout<<w<<endl;
		ll ans=0;
		REP(j, LIM) {
			if(w[j]>-INF) {ans = j; break;}
		}
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
#define END	 verify_case(_, MonstersValley().minimumPrice(dread, price));}
int main(){

CASE(0)
	long dread_[] = {8, 5, 10};
	  vector<long long> dread(dread_, dread_+sizeof(dread_)/sizeof(*dread_)); 
	int price_[] = {1, 1, 2};
	  vector <int> price(price_, price_+sizeof(price_)/sizeof(*price_)); 
	int _ = 2; 
END
//return 0;
CASE(1)
	long dread_[] = {1, 2, 4, 1000000000};
	  vector<long long> dread(dread_, dread_+sizeof(dread_)/sizeof(*dread_)); 
	int price_[] = {1, 1, 1, 2};
	  vector <int> price(price_, price_+sizeof(price_)/sizeof(*price_)); 
	int _ = 5; 
END
CASE(2)
	long dread_[] = {200, 107, 105, 206, 307, 400};
	  vector<long long> dread(dread_, dread_+sizeof(dread_)/sizeof(*dread_)); 
	int price_[] = {1, 2, 1, 1, 1, 2};
	  vector <int> price(price_, price_+sizeof(price_)/sizeof(*price_)); 
	int _ = 2; 
END
CASE(3)
	long dread_[] = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333};
	  vector<long long> dread(dread_, dread_+sizeof(dread_)/sizeof(*dread_)); 
	int price_[] = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1};
	  vector <int> price(price_, price_+sizeof(price_)/sizeof(*price_)); 
	int _ = 5; 
END
CASE(1)
	ll dread_[] = {1000000000000LL, 1000000000000LL, 1000000000000LL, 1000000000000LL};
	  vector<long long> dread(dread_, dread_+sizeof(dread_)/sizeof(*dread_)); 
	int price_[] = {2, 1, 1, 1};
	  vector <int> price(price_, price_+sizeof(price_)/sizeof(*price_)); 
	int _ = 1; 
END

}
// END CUT HERE
