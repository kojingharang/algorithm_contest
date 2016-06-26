// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// This problem statement contains superscripts and/or subscripts. These may not display properly outside the applet.

Gobble City has a tree topology: There are N intersections, numbered 0 through N-1. The intersections are connected by N-1 bidirectional roads in such a way that it is possible to travel between any two intersections. More precisely, for each pair of intersections there is a unique path (a sequence of roads; see Notes for a formal definition) that connects them. You are given a vector <int> roads that describes the roads: for each i (0 <= i <= N-2), we have 0 <= roads[i] <= i and there is a road between intersections numbered roads[i] and i+1.

On each road there is a single lamp. The lamps are numbered 0 through N-2. For each i, lamp i is on the road that connects roads[i] and i+1. You are given a string initState that describes the initial states of all lamps: initState[i]='1' means that lamp i is initially on, and initState[i]='0' means that it is off.

Now you are at the Control Center for these lamps. The only way in which you can operate the lamps looks as follows: You enter the numbers of two intersections (X and Y) into the Control Center computer, and the computer toggles the state of all lamps on the path between X and Y. (Toggling the state of a lamp means that if the lamp was off it is now on, and vice versa.) You can perform arbitrarily many such operations, one after another.

Some of the lamps are important to you. You are given this information in the string isImportant: isImportant[i]='1' means that lamp i is important, and isImportant[i]='0' means that it is not.

Your goal is to turn on all important lamps at the same time. (We do not care about the state of the remaining lamps.) Return the minimum number of operations needed to achieve the goal.

DEFINITION
Class:TurnOnLamps
Method:minimize
Parameters:vector <int>, string, string
Returns:int
Method signature:int minimize(vector <int> roads, string initState, string isImportant)


NOTES
-In your solution some lamps may be toggled multiple times.
-A path between two intersection a and b is a sequence of intersections (v0=a, v1, v2, ..., vk=b) such that all v0, v1, ..., vk are pairwise distinct and for each i=0..k-1, there exists a road between vi and vi+1.


CONSTRAINTS
-roads will contain N-1 elements, where N is between 2 and 50, inclusive.
-For each i, the i-th (0-based index) element of roads will be between 0 and i, inclusive.
-initState will be N-1 characters long.
-initState will only contain the characters '0' and '1'.
-isImportant will be N-1 characters long.
-isImportant will only contain the characters '0' and '1'.


EXAMPLES

0)
{0,0,1,1}
"0001"
"0111"

Returns: 1

The figure below illustrates this test case and its optimal solution.

Red roads are the important ones. The optimal solution chooses the intersections 2 and 3. The path that corresponds to this choice is enclosed by the dashed line. All lamps on this path are toggled from 0 to 1.

1)
{0,0,1,1}
"0000"
"0111"

Returns: 2

This is almost the same test case as Example 0, but now the initial state of the lamp 3 (i.e., the lamp on the road that connects intersections 1 and 4) is now 0. As this is an important lamp, we now need two operations in order to turn all important lamps to 1.


2)
{0,0,1,1,4,4}
"000100"
"111111"

Returns: 2


Note that lamp on the road between intersections 1 and 4 was toggled twice: first from 1 to 0, and then from 0 back to 1.

3)
{0,0,1,1,4,4}
"100100"
"011101"

Returns: 2



4)
{0,0,2,2,3,1,6,3,1}
"010001110"
"000110100"

Returns: 1



5)
{0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15}
"0000000000010000000000000010000010100000000000000"
"1010111111111011011111000110111111111111111110111"

Returns: 14



*/
// END CUT HERE
#line 101 "TurnOnLamps.cpp"

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


// 0 is good
ll f(ll a, ll g) {
	return POPCOUNTLL(g)-POPCOUNTLL(a&g);
}

struct p3 {
	ll po, no, cost;
	bool operator<(const p3& b) const {
		return po<b.po;
	}
};

class TurnOnLamps {
	public:
	int minimize(vector <int> R, string S, string G) {
		int N=R.size()+1;
		VI w;
		REP(i, N) REP(j, N) {
			if(i==j) continue;
			VI p0, p1;
			{
				int nid = i;
				while(nid) {
					p0.PB(nid-1);
					nid = R[nid-1];
				}
			}
			{
				int nid = j;
				while(nid) {
					p1.PB(nid-1);
					nid = R[nid-1];
				}
			}
			reverse(ALL(p0));
			reverse(ALL(p1));
			int k=0;
			while(k<p0.size() && k<p1.size() && p0[k]==p1[k]) k++;
			//VI ww;
			ll ww=0;
			RANGE(l, k, p0.size()) ww|=1LL<<p0[l];
			RANGE(l, k, p1.size()) ww|=1LL<<p1[l];
			//cout<<i<<" "<<j<<":  "<<ww<<endl;
			w.PB(ww);
		}
		//cout<<w<<endl;
		ll bS = 0;
		REP(i, S.size()) if(S[i]=='1') bS|=1LL<<i;
		ll bG = 0;
		REP(i, G.size()) if(G[i]=='1') bG|=1LL<<i;
		
		cout<<"start "<<bS<<endl;
		cout<<"goal "<<bG<<endl;
		if((bS & bG)==bG) return 0;
		priority_queue<p3> q;
		q.push((p3){-f(bS, bG), bS, 0});
		map<ll, ll> hi;
		hi[bS]=0;
		while(q.size()) {
			ll po = -q.top().po;
			ll no = q.top().no;
			ll cost = q.top().cost;
			q.pop();
			//if(hi[no]<cost) continue;
			//cout<<"pop "<<no<<endl;
			REP(i, w.size()) {
				ll nno = no ^ w[i];
				//cout<<"try "<<nno<<endl;
				if((nno & bG)==bG) return cost+1;
				ll npo = f(nno, bG);
				if(npo < po) {
					q.push((p3){-npo, nno, cost+1});
					hi[nno]=cost+1;
				}
			}
		}
		return -1;
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
#define END	 verify_case(_, TurnOnLamps().minimize(roads, initState, isImportant));}
int main(){

CASE(0)
	int roads_[] = {0,0,1,1};
	  vector <int> roads(roads_, roads_+sizeof(roads_)/sizeof(*roads_)); 
	string initState = "0001"; 
	string isImportant = "0111"; 
	int _ = 1; 
END
//return 0;
CASE(1)
	int roads_[] = {0,0,1,1};
	  vector <int> roads(roads_, roads_+sizeof(roads_)/sizeof(*roads_)); 
	string initState = "0000"; 
	string isImportant = "0111"; 
	int _ = 2; 
END
//return 0;
CASE(2)
	int roads_[] = {0,0,1,1,4,4};
	  vector <int> roads(roads_, roads_+sizeof(roads_)/sizeof(*roads_)); 
	string initState = "000100"; 
	string isImportant = "111111"; 
	int _ = 2; 
END
CASE(3)
	int roads_[] = {0,0,1,1,4,4};
	  vector <int> roads(roads_, roads_+sizeof(roads_)/sizeof(*roads_)); 
	string initState = "100100"; 
	string isImportant = "011101"; 
	int _ = 2; 
END
CASE(4)
	int roads_[] = {0,0,2,2,3,1,6,3,1};
	  vector <int> roads(roads_, roads_+sizeof(roads_)/sizeof(*roads_)); 
	string initState = "010001110"; 
	string isImportant = "000110100"; 
	int _ = 1; 
END
CASE(5)
	int roads_[] = {0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15};
	  vector <int> roads(roads_, roads_+sizeof(roads_)/sizeof(*roads_)); 
	string initState = "0000000000010000000000000010000010100000000000000"; 
	string isImportant = "1010111111111011011111000110111111111111111110111"; 
	int _ = 14; 
END

}
// END CUT HERE
