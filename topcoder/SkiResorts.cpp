// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel is the owner of a ski resort. The ski resort has N places numbered 0 through N-1. There are some bidirectional roads between pairs of places. You are given a vector <string> roads. If the j-th character of the i-th element of roads is 'Y', there is a bidirectional road that connects place i and place j. If it is 'N', there's no road between them. You are also given a vector <int> altitude. The i-th element of altitude is the altitude of the place i.


You can go directly from the place i to the place j by skiing if there is a bidirectional road between them and the altitude of the place i is higher than or equal to the altitude of the place j. Ciel wants to reconstruct the ski resort so that place N-1 is reachable (not necessarily directly) from place 0 by skiing. In the reconstruction, Ciel can change the altitude of some places. The cost of changing the altitude of a place from x to y is |x - y| units of money, where || denotes the absolute value.


Return the minimal cost required for the reconstruction. If it is impossible to reach place N-1 from place 0 even after the reconstruction, return -1.

DEFINITION
Class:SkiResorts
Method:minCost
Parameters:vector <string>, vector <int>
Returns:long long
Method signature:long long minCost(vector <string> road, vector <int> altitude)


CONSTRAINTS
-road will contain between 2 and 50 elements, inclusive.
-Each element of road will contain exactly N characters, where N is the number of elements of road.
-Each character in road will be either 'Y' or 'N'.
-For each valid i, the i-th character of the i-th element of road will be 'N'.
-For each valid pair (i, j), the i-th character of the j-th element of road and the j-th character of the i-th element of road will be equal.
-altitude will contain exactly N elements.
-Each element of altitude will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{"NYN",
 "YNY",
 "NYN"}
{30, 20, 10}

Returns: 0

It is possible to reach place 2 from place 0 even without the reconstruction by following the path (place 0) -> (place 1) -> (place 2).

1)
{"NY",
 "YN"}
{10, 20}

Returns: 10

For example, Ciel can change the altitude of both places to 15. The cost is |10 - 15| + |20 - 15| = 10.

2)
{"NYN",
 "YNN",
 "NNN"}
{573, 573, 573}

Returns: -1

Place 2 is not reachable from place 0.

3)
{"NNYNNYYYNN",
 "NNNNYNYNNN",
 "YNNNNYYNNN",
 "NNNNNNYNYY",
 "NYNNNNNNYY",
 "YNYNNNNYNN",
 "YYYYNNNYNN",
 "YNNNNYYNNN",
 "NNNYYNNNNN",
 "NNNYYNNNNN"}
{7, 4, 13, 2, 8, 1, 8, 15, 5, 15}

Returns: 12



*/
// END CUT HERE
#line 81 "SkiResorts.cpp"

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



class SkiResorts {
	public:
	long long minCost(vector <string> R, vector <int> A) {
		int N=R.size();
		ll INF = 1LL<<60;
		VI po(N*N, INF);
		priority_queue<PII, vector<PII>, greater<PII> > q;
		REP(j, N) {
			po[j]=abs(A[j]-A[0]);
			q.push(MP(po[j], j));
		}
		int end=0;
		ll ans = INF;
		while(q.size()) {
			ll pot =  q.top().first;
			int cur = q.top().second;
			int cur_n = cur/N;
			int cur_h = cur%N;
			q.pop();
			if(pot > po[cur]) continue;
			end += cur_n==N-1;
			if(end==N) break;
			REP(i, N) {
				if(R[cur_n][i]=='Y') {
					REP(j, N) {
						if(A[cur_h] < A[j]) continue;
						int cost = abs(A[j]-A[i]);
						if(po[cur] + cost < po[i*N+j]) {
							po[i*N+j] = po[cur] + cost;
							q.push(MP(po[i*N+j], i*N+j));
						}
					}
				}
			}
		}
		
		REP(i, N) ans=min(ans, po[(N-1)*N+i]);
		return ans==INF ? -1 : ans;
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
#define END	 verify_case(_, SkiResorts().minCost(road, altitude));}
int main(){



CASE(0)
	string road_[] = {"NYN",
 "YNY",
 "NYN"};
	  vector <string> road(road_, road_+sizeof(road_)/sizeof(*road_)); 
	int altitude_[] = {30, 20, 10};
	  vector <int> altitude(altitude_, altitude_+sizeof(altitude_)/sizeof(*altitude_)); 
	long long _ = 0LL; 
END
//return 0;
CASE(1)
	string road_[] = {"NY",
 "YN"};
	  vector <string> road(road_, road_+sizeof(road_)/sizeof(*road_)); 
	int altitude_[] = {10, 20};
	  vector <int> altitude(altitude_, altitude_+sizeof(altitude_)/sizeof(*altitude_)); 
	long long _ = 10LL; 
END
//return 0;
CASE(2)
	string road_[] = {"NYN",
 "YNN",
 "NNN"};
	  vector <string> road(road_, road_+sizeof(road_)/sizeof(*road_)); 
	int altitude_[] = {573, 573, 573};
	  vector <int> altitude(altitude_, altitude_+sizeof(altitude_)/sizeof(*altitude_)); 
	long long _ = -1LL; 
END
CASE(3)
	string road_[] = {"NNYNNYYYNN",
 "NNNNYNYNNN",
 "YNNNNYYNNN",
 "NNNNNNYNYY",
 "NYNNNNNNYY",
 "YNYNNNNYNN",
 "YYYYNNNYNN",
 "YNNNNYYNNN",
 "NNNYYNNNNN",
 "NNNYYNNNNN"};
	  vector <string> road(road_, road_+sizeof(road_)/sizeof(*road_)); 
	int altitude_[] = {7, 4, 13, 2, 8, 1, 8, 15, 5, 15};
	  vector <int> altitude(altitude_, altitude_+sizeof(altitude_)/sizeof(*altitude_)); 
	long long _ = 12LL; 
END

}
// END CUT HERE
