// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// This problem statement contains superscripts and/or subscripts. It may not display properly outside the applet.


Wojtek and Tomek are playing darts. Unfortunately the dartboard is blurred and Wojtek can't read some of the numbers written on it. On the other hand, Tomek remembers the numbers written on the dartboard.


The dartboard is divided into N parts. Wojtek knows that for each integer x between 1 and N, inclusive, there is exactly one part that is worth x points. You are given a vector <int> points containing N integers. If points[i] is positive, the i-th part is worth points[i] points. If points[i] is zero, he can't read the number that indicates the point value of the i-th part.


Wojtek and Tomek will play the following game. First, Wojtek throws K darts. Wojtek is perfectly skilled at darts, so he will certainly hit the parts he wants to hit. He is allowed to hit the same part with multiple darts. After Wojtek throws all the darts, Tomek calculates Wojtek's total score. The total score is simply the sum of the points hit by each of the darts. (Note that each part of the dartboard may be counted multiple times if Wojtek hits it with multiple darts.) If the total score is at least P points, Wojtek wins. Otherwise, Tomek wins.


You are given the vector <int> points and the int P. Return the smallest K such that Wojtek is guaranteed to win the game if he follows the optimal strategy when throwing the darts.

DEFINITION
Class:BlurredDartboard
Method:minThrows
Parameters:vector <int>, int
Returns:int
Method signature:int minThrows(vector <int> points, int P)


CONSTRAINTS
-points will contain between 1 and 50 elements, inclusive.
-Each element of points will be between 0 and N, inclusive, where N is the number of elements in points.
-Each of the integers from 1 to N, inclusive, will appear at most once in points.
-P will be between 1 and 1,000,000,000 (109), inclusive.


EXAMPLES

0)
{0, 3, 4, 0, 0}
8

Returns: 2

Wojtek should hit part 2 twice. He will get 8 points.

1)
{0, 0, 0, 0, 0}
15

Returns: 5

Wojtek should hit each part exactly once. He doesn't know the point values, but the total score will be always 15.

2)
{4, 7, 8, 1, 3, 2, 6, 5}
2012

Returns: 252



3)
{0, 0, 5, 0, 0, 0, 1, 3, 0, 0}
2012

Returns: 307



4)
{0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0}
1000000000

Returns: 84656087



*/
// END CUT HERE
#line 78 "BlurredDartboard.cpp"

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
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class BlurredDartboard {
	public:
	int minThrows(vector <int> p, int P) {
		int N=p.size();
		
		VI vis(N, 0);
		int ma=-1;
		REP(i, N) {
			if(p[i]>0) {
				vis[p[i]-1]=1;
				ma=max(ma, p[i]);
			}
		}
		VI hid;
		REP(i, N) if(vis[i]==0) hid.PB(i+1);
		int hidsum = accumulate(ALL(hid), 0);
		sort(ALL(hid));
		
		int ans=0;
		if(ma==-1 || hidsum > ma*hid.size()) {
			ans += P/hidsum*hid.size();
			P -= P/hidsum*hidsum;
		} else {
			ans += P/ma;
			P -= P/ma*ma;
		}
		cout<<ans<<" "<<P<<endl;
		if(P==0) return ans;
		
		int lans=0;
		int PP=P;
		REP(i, hid.size()) {
			PP-=hid[i];
			lans++;
			if(PP<=0) break;
		}
		if(PP>0) lans = 10000;
		cout<<lans<<endl;
		if(ma!=-1) lans = min(lans, (P+ma-1)/ma);
		cout<<lans<<" "<<ma<<endl;
		
		return ans+lans;
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
#define END	 verify_case(_, BlurredDartboard().minThrows(points, P));}
int main(){

CASE(0)
	int points_[] = {0, 3, 4, 0, 0};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int P = 8; 
	int _ = 2; 
END
CASE(1)
	int points_[] = {0, 0, 0, 0, 0};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int P = 15; 
	int _ = 5; 
END
CASE(2)
	int points_[] = {4, 7, 8, 1, 3, 2, 6, 5};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int P = 2012; 
	int _ = 252; 
END
CASE(3)
	int points_[] = {0, 0, 5, 0, 0, 0, 1, 3, 0, 0};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int P = 2012; 
	int _ = 307; 
END
CASE(4)
	int points_[] = {0, 2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 6, 0, 0, 0, 4, 0, 0, 0};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int P = 1000000000; 
	int _ = 84656087; 
END
CASE(1)
	int points_[] = {0, 0, 0,};
	  vector <int> points(points_, points_+sizeof(points_)/sizeof(*points_)); 
	int P = 2; 
	int _ = 2; 
END

}
// END CUT HERE
