// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
Alien Fred wants to destroy the Earth.
But before he does that, he wants to eat some hamburgers.




You are given two vector <int>s: type and taste.
They describe all hamburgers available in the shop he found.
Each hamburger has a type (some positive integer) and a taste (some, possibly negative, integer).
For each i, type[i] represents the type of i-th hamburger (0-based index), and taste[i] represents the taste of i-th hamburger.
It is possible that different hamburgers have the same type but a different taste.




Fred wants to eat some subset of those hamburgers (possibly none or all of them).
Eating the chosen hamburgers will give him some amount of joy.
This amount can be computed as Y * A, where Y is the number of different types of hamburgers eaten, and A is their total taste.




Return the largest possible amount of joy he can get.


DEFINITION
Class:AlienAndHamburgers
Method:getNumber
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int getNumber(vector <int> type, vector <int> taste)


CONSTRAINTS
-type will contain between 1 and 50 elements, inclusive.
-type and taste will contain the same number of elements.
-Each element of type will be between 1 and 100, inclusive.
-Each element of taste will be between -100,000 and 100,000, inclusive.


EXAMPLES

0)
{1, 2}
{4, 7}

Returns: 22

In this case, the best choice is to choose both hamburgers. The number of different types is 2, and the total taste is 11. Thus, the answer is 2*11 = 22.

1)
{1, 1}
{-1, -1}

Returns: 0

Note that sometimes the best choice is not to eat any hamburgers. In such a case the amount of joy is 0.

2)
{1, 2, 3}
{7, 4, -1}

Returns: 30



3)
{1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1}
{1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0}

Returns: 54



4)
{30, 20, 10}
{100000, -100000, 100000}

Returns: 400000



******************************/
// END CUT HERE
#line 90 "AlienAndHamburgers.cpp"
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

int d[1000];
class AlienAndHamburgersTry {
	public:
	int getNumber(vector <int> TY, vector <int> TA) {
		int N=TY.size();
		REP(i, 1000)d[i]=-1000000000;
		REP(i, N) {
			if(TA[i]>=0) {
				if(d[TY[i]]>=0) d[TY[i]]+=TA[i];
				if(d[TY[i]]<0) d[TY[i]]=TA[i];
			} else {
				if(d[TY[i]]<TA[i]) d[TY[i]]=TA[i];
			}
		}
		sort(d+1,d+101);
		reverse(d+1,d+101);
		int m=0,u=0;
		RANGE(i, 1, 101) {
			if(d[i]==-1000000000)break;
			if(u*m<=(u+1)*(m+d[i])) {
				u++;
				m=m+d[i];
			} else break;
		}
		
		return u*m;
	}
};

class AlienAndHamburgers {
	public:
	int getNumber(vector <int> TY, vector <int> TA) {
		int N=TY.size();
		vector<PII> w;
		VI mi(110, -1000000);
		REP(i, N) {
			if(TA[i]>=0) {
				w.PB(MP(TA[i], TY[i]));
				mi[TY[i]]=1;
			}
		}
		REP(i, N) {
			if(mi[TY[i]]==1) continue;
			if(TA[i]<0) {
				mi[TY[i]]=max(mi[TY[i]], (ll)TA[i]);
			}
		}
		REP(i, 110) {
			if(mi[i]!=1 && mi[i]>-1000000) w.PB(MP(mi[i], i));
		}
		sort(ALLR(w));
//		cout<<w<<endl;
		int ans=0;
		int sum=0;
		map<int, int> hi;
		REP(i, w.size()) {
			hi[w[i].second]++;
			sum+=w[i].first;
			ans=max(ans, (int)hi.size()*sum);
		}
		return ans;
	}
};

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
#define END	 verify_case(_, AlienAndHamburgers().getNumber(type, taste));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	int type_[] = {1, 2};
	  vector <int> type(type_, type_+sizeof(type_)/sizeof(*type_)); 
	int taste_[] = {4, 7};
	  vector <int> taste(taste_, taste_+sizeof(taste_)/sizeof(*taste_)); 
	int _ = 22; 
END
CASE(1)
	int type_[] = {1, 1};
	  vector <int> type(type_, type_+sizeof(type_)/sizeof(*type_)); 
	int taste_[] = {-1, -1};
	  vector <int> taste(taste_, taste_+sizeof(taste_)/sizeof(*taste_)); 
	int _ = 0; 
END
CASE(2)
	int type_[] = {1, 2, 3};
	  vector <int> type(type_, type_+sizeof(type_)/sizeof(*type_)); 
	int taste_[] = {7, 4, -1};
	  vector <int> taste(taste_, taste_+sizeof(taste_)/sizeof(*taste_)); 
	int _ = 30; 
END
CASE(3)
	int type_[] = {1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1};
	  vector <int> type(type_, type_+sizeof(type_)/sizeof(*type_)); 
	int taste_[] = {1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0};
	  vector <int> taste(taste_, taste_+sizeof(taste_)/sizeof(*taste_)); 
	int _ = 54; 
END
CASE(4)
	int type_[] = {30, 20, 10};
	  vector <int> type(type_, type_+sizeof(type_)/sizeof(*type_)); 
	int taste_[] = {100000, -100000, 100000};
	  vector <int> taste(taste_, taste_+sizeof(taste_)/sizeof(*taste_)); 
	int _ = 400000; 
END
#if 01  // DO RANDOM TESTS
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<10;loop++) {
// param type: int
/*
-type will contain between 1 and 50 elements, inclusive.
-type and taste will contain the same number of elements.
-Each element of type will be between 1 and 100, inclusive.
-Each element of taste will be between -100,000 and 100,000, inclusive.
*/
start_time=clock();
	vector <int> type; 
	int N=UNIFORM_LL(1, 51);
	{
		type = vector <int>(N); 
		REP(i, N) {
			type[i] = UNIFORM_LL(1, 101);
		}
	}
// param type: int
start_time=clock();
	vector <int> taste; 
	{
		taste = vector <int>(N); 
		REP(i, N) {
			taste[i] = UNIFORM_LL(-100000, 100001);
		}
	}
	int _0 = AlienAndHamburgers().getNumber(type, taste);
	int _1 = AlienAndHamburgersTry().getNumber(type, taste);
	if(!verify_case(_0, _1, true)) {
print(type);
print(taste);
	}
}
#endif

}
// END CUT HERE
