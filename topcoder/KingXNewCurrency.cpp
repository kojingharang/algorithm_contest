// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// King Dengklek is the perfect king of Kingdom of Ducks, where slimes and ducks live together in peace and harmony.

Kingdom of Ducks has a pretty strange currency system. There are only two coin types: one with value A and one with value B, where A and B are different. This currency system is denoted by {A, B}. These two coin types are sufficient for daily transactions, because all prices in this kingdom are in the form of (A*p + B*q) for some non-negative integers p and q. Therefore, slimes and ducks can pay for any goods with a combination of the two coin types.

Bored with the current system, King Dengklek considered another currency system with two coin types: one with value X and one with value Y, where X and Y are different. Of course, with this new system, combinations of the two new coin types must make it possible to pay all the prices one could pay with currency system {A, B}. (Note that the new coin types may also make it possible to pay some additional prices.)

You are given ints A, B, and X. Return the number of different positive integers Y (other than X) such that the currency system {X, Y} can be used to replace the currency system {A, B}. If there is an infinite number of possible values for Y, return -1 instead.

DEFINITION
Class:KingXNewCurrency
Method:howMany
Parameters:int, int, int
Returns:int
Method signature:int howMany(int A, int B, int X)


CONSTRAINTS
-A, B, and X will each be between 1 and 200, inclusive.
-A and B will be different.


EXAMPLES

0)
5
8
5

Returns: 5

These are the 5 possible currency systems: {5, 1}, {5, 2}, {5, 3}, {5, 4}, and {5, 8}.

1)
8
4
2

Returns: -1

All prices are multiples of four. Since a coin type with value 2 alone can pay any price that is a multiple of four, there is an infinite number of possible values of Y.

2)
7
4
13

Returns: 1

The only possible currency system is {13, 1}.

3)
47
74
44

Returns: 2

The two possible currency systems are {44, 1} and {44, 3}.

4)
128
96
3

Returns: 65



*/
// END CUT HERE
#line 75 "KingXNewCurrency.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <climits>
#include <cstdlib>
#include <cstring>
using namespace std;

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class KingXNewCurrency {
	public:
	int howMany(int A, int B, int X) {
		VI w;
		int HMAX=200;
		if(A%X==0 && B%X==0) return -1;
		
		REP(i, HMAX) REP(j, HMAX) {
			//if(i==0||j==0) continue;
			w.push_back(A*i+B*j);
		}
		sort(ALL(w));
		w.erase(unique(ALL(w)), w.end());
		//cout<<w<<endl;
		int ans=0;
		int YMAX=2000;
		for(int Y=1;Y<=YMAX;Y++) {
			if(X==Y) continue;
			int ok=1;
			REP(i, w.size()) {
				
				int lok=0;
				for(int j=0;j<=w[i]/X;j++) {
					if((w[i]-X*j) >= 0 && ((w[i]-X*j) % Y) == 0) {
						//cout<<w[i]<<" = "<<X<<"*"<<j<<"+"<<Y<<"*"<<((w[i]-X*j) / Y)<<endl;
						//if(w[i] != X*j+Y*((w[i]-X*j) / Y)) {
						//	//cout<<"ERROR"<<endl;
						//}
						lok=1; break;
					}
				}
				if(!lok) {
					//cout<<Y<<" NG "<<endl;
					ok=0;
					break;
				}
			}
			if(ok) {
				//cout<<"OK "<<Y<<endl;
				ans++;
			}
		}
		return ans==YMAX-1 ? -1 : ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, KingXNewCurrency().howMany(A, B, X));}
int main(){

CASE(0)
	int A = 5; 
	int B = 8; 
	int X = 5; 
	int _ = 5; 
END
CASE(1)
	int A = 8; 
	int B = 4; 
	int X = 2; 
	int _ = -1; 
END
CASE(2)
	int A = 7; 
	int B = 4; 
	int X = 13; 
	int _ = 1; 
END
CASE(3)
	int A = 47; 
	int B = 74; 
	int X = 44; 
	int _ = 2; 
END
CASE(4)
	int A = 128; 
	int B = 96; 
	int X = 3; 
	int _ = 65; 
END

}
// END CUT HERE
