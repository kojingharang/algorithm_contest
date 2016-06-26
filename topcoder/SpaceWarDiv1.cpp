// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Magical Girls are girls who have magical powers.
They fight against evil to protect the Earth.
Cosmic enemies have just attacked the Earth, and the Magical Girls are going to fight them.

You are given a vector <int> magicalGirlStrength that describes the Magical Girls:
for each i, magicalGirlStrength[i] is the strength of one of the girls.
You are also given a vector <int> enemyStrength and a vector<long long> enemyCount that describe their enemies:
for each i, there are enemyCount[i] enemies that each have strength enemyStrength[i].

Each Magical Girl will always fight one enemy at a time.
A Magical Girl will defeat her enemy if her strength is greater than or equal to the strength of that enemy.

At the beginning of the fight the fatigue of each Magical Girl is 0.
Each time a Magical Girl defeats an enemy, her fatigue increases by 1.

The Magical Girls want to defeat all the enemies.
That is, each of the enemies must be defeated by one of the Magical Girls.
Additionally, the Magical Girls want to minimize the maximum fatigue among them.

If it is impossible to defeat all of the enemies, return -1.
Otherwise, return the smallest F with the following property:
the Magical Girls can defeat all enemies in such a way that at the end the fatigue of each girl is at most F.

DEFINITION
Class:SpaceWarDiv1
Method:minimalFatigue
Parameters:vector <int>, vector <int>, vector<long long>
Returns:long long
Method signature:long long minimalFatigue(vector <int> magicalGirlStrength, vector <int> enemyStrength, vector<long long> enemyCount)


NOTES
-The elements of enemyStrength are not necessarily pairwise distinct.


CONSTRAINTS
-magicalGirlStrength will contain between 1 and 50 elements, inclusive.
-Each element of magicalGirlStrength will be between 1 and 10,000, inclusive.
-enemyStrength and enemyCount will each contain between 1 and 50 elements, inclusive.
-enemyStrength and enemyCount will contain the same number of elements.
-Each element of enemyStrength will be between 1 and 10,000, inclusive.
-Each element of enemyCount will be between 1 and 100,000,000,000,000 (10^14), inclusive.


EXAMPLES

0)
{2, 3, 5}
{1, 3, 4}
{2, 9, 4}

Returns: 7

There are 3 Magical Girls, their strength are 2, 3, and 5.
There are 3 kinds of enemies: 2 enemies with strength 1 each, 9 enemies with strength 3 each, and 4 enemies with strength 4 each.
This is one of the ways how to minimize the maximal fatigue:

Magical girl 0 defeats 2 enemies with strength 1.
Magical girl 1 defeats 7 enemies with strength 3.
Magical girl 2 defeats 2 enemies with strength 3 and 4 enemies with strength 4.


1)
{2, 3, 5}
{1, 1, 2}
{2, 9, 4}

Returns: 5

Each of the Magical Girls can defeat any of the enemies. The optimal strategy is that each girl should defeat 5 of the enemies.

2)
{14, 6, 22}
{8, 33}
{9, 1}

Returns: -1

None of the magical girls can defeat the enemy with strength 33.

3)
{869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417}
{789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307}
{20626770196420, 45538527263992, 52807114957507, 17931716090785, 65032910980630, 88711853198687, 26353250637092,
 61272534748707, 89294362230771, 52058590967576, 60568594469453, 23772707032338, 43019142889727, 39566072849912,
 78870845257173, 68135668032761, 36844201017584, 10133804676521, 6275847412927, 37492167783296}

Returns: 75030497287405



*/
// END CUT HERE
#line 98 "SpaceWarDiv1.cpp"

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



class SpaceWarDiv1 {
	public:
	long long minimalFatigue(vector <int> M, vector <int> ES, vector<long long> EC) {
		sort(ALL(M));
		ll ne = accumulate(ALL(EC), 0LL);
		ll lo=0, hi=1LL<<60;
		while(lo+1<hi) {
			ll F=(lo+hi)/2;
			ll doneAll = 0;
			REP(i, M.size()) {
				ll can = 0;
				REP(j, ES.size()) if(ES[j] <= M[i]) can+=EC[j];
				ll done = min(can - doneAll, F);
				doneAll += done;
			}
			if(doneAll >= ne) hi=F; else lo=F;
		}
		return hi==(1LL<<60) ? -1 : hi;
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
void verify_case(const long long& Expected, const long long& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, SpaceWarDiv1().minimalFatigue(magicalGirlStrength, enemyStrength, enemyCount));}
int main(){

CASE(0)
	int magicalGirlStrength_[] = {2, 3, 5};
	  vector <int> magicalGirlStrength(magicalGirlStrength_, magicalGirlStrength_+sizeof(magicalGirlStrength_)/sizeof(*magicalGirlStrength_)); 
	int enemyStrength_[] = {1, 3, 4};
	  vector <int> enemyStrength(enemyStrength_, enemyStrength_+sizeof(enemyStrength_)/sizeof(*enemyStrength_)); 
	long enemyCount_[] = {2, 9, 4};
	  vector<long long> enemyCount(enemyCount_, enemyCount_+sizeof(enemyCount_)/sizeof(*enemyCount_)); 
	long long _ = 7LL; 
END
//return 0;
CASE(1)
	int magicalGirlStrength_[] = {2, 3, 5};
	  vector <int> magicalGirlStrength(magicalGirlStrength_, magicalGirlStrength_+sizeof(magicalGirlStrength_)/sizeof(*magicalGirlStrength_)); 
	int enemyStrength_[] = {1, 1, 2};
	  vector <int> enemyStrength(enemyStrength_, enemyStrength_+sizeof(enemyStrength_)/sizeof(*enemyStrength_)); 
	long enemyCount_[] = {2, 9, 4};
	  vector<long long> enemyCount(enemyCount_, enemyCount_+sizeof(enemyCount_)/sizeof(*enemyCount_)); 
	long long _ = 5LL; 
END
CASE(2)
	int magicalGirlStrength_[] = {14, 6, 22};
	  vector <int> magicalGirlStrength(magicalGirlStrength_, magicalGirlStrength_+sizeof(magicalGirlStrength_)/sizeof(*magicalGirlStrength_)); 
	int enemyStrength_[] = {8, 33};
	  vector <int> enemyStrength(enemyStrength_, enemyStrength_+sizeof(enemyStrength_)/sizeof(*enemyStrength_)); 
	long enemyCount_[] = {9, 1};
	  vector<long long> enemyCount(enemyCount_, enemyCount_+sizeof(enemyCount_)/sizeof(*enemyCount_)); 
	long long _ = -1LL; 
END
CASE(3)
	int magicalGirlStrength_[] = {869, 249, 599, 144, 929, 748, 665, 37, 313, 99, 33, 437, 308, 137, 665, 834, 955, 958, 613, 417};
	  vector <int> magicalGirlStrength(magicalGirlStrength_, magicalGirlStrength_+sizeof(magicalGirlStrength_)/sizeof(*magicalGirlStrength_)); 
	int enemyStrength_[] = {789, 57, 684, 741, 128, 794, 542, 367, 937, 739, 568, 872, 127, 261, 103, 763, 864, 360, 618, 307};
	  vector <int> enemyStrength(enemyStrength_, enemyStrength_+sizeof(enemyStrength_)/sizeof(*enemyStrength_)); 
	long long enemyCount_[] = {20626770196420, 45538527263992, 52807114957507, 17931716090785, 65032910980630, 88711853198687, 26353250637092,
 61272534748707, 89294362230771, 52058590967576, 60568594469453, 23772707032338, 43019142889727, 39566072849912,
 78870845257173, 68135668032761, 36844201017584, 10133804676521, 6275847412927, 37492167783296};
	  vector<long long> enemyCount(enemyCount_, enemyCount_+sizeof(enemyCount_)/sizeof(*enemyCount_)); 
	long long _ = 75030497287405LL; 
END

}
// END CUT HERE
