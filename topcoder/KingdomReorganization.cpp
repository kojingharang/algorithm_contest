// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// This problem statement contains subscripts and may not be shown properly outside of the applet.

The greatest king of all times, Michael IV, is going to make big changes in his kingdom. The kingdom is composed of N cities (for simplicity numbered from 0 to N-1). Some pairs of cities are connected by bidirectional roads. We say that there is a path between different cities A and B if there exists a sequence of unique cities {C1, C2, ..., CM}, such that C1 = A and CM = B and for each index i < M, there is a road between cities Ci and Ci+1.

The current state of the kingdom is miserable. Some pairs of cities are not connected by any path. On the other hand, other pairs of cities are connected by multiple different paths, and that leads to complicated traffic routing. Michael wants to build some new roads and destroy some of the already existing roads in the kingdom so that after the reconstruction there will exist exactly one path between every pair of distinct cities. As building new roads and destroying old ones costs a lot of money, Michael wants to minimize the total cost spent on the reconstruction.

You are given a vector <string> kingdom describing the current state of the kingdom. There is a road between the cities i and j if and only if kingdom[i][j] = '1' and kingdom[j][i] = '1'. You are also given a vector <string> build and a vector <string> destroy. If no road exists between cities i and j, then the cost of building it is encoded by build[i][j]. If there already is a road between cities i and j, then the cost of destroying it is encoded by destroy[i][j]. The costs in both vector <string>s are encoded as characters, where 'A', 'B', ..., 'Z' represent the costs 0, 1, ..., 25, respectively and 'a', 'b', ..., 'z' represent the costs 26, 27, ..., 51, respectively. Your task is to find and return the minimal cost needed for the kingdom reconstruction.

DEFINITION
Class:KingdomReorganization
Method:getCost
Parameters:vector <string>, vector <string>, vector <string>
Returns:int
Method signature:int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy)


NOTES
-N, the number of cities in the kingdom can be determined as the number of elements of kingdom.
-Two paths {A1, A2, ..., AR} and {B1, B2, ..., BS} are considered different if either R is not equal to S or there exists i <= R, such that Ai is not equal to Bi.
-There can never exist a road leading from some city to itself.
-The values in build that correspond to existing roads can simply be ignored. Similarly, ignore the values in destroy that correspond to nonexistent roads.


CONSTRAINTS
-N will be between 1 and 50, inclusive.
-kingdom, build and destroy will each contain N elements.
-Each of the elements of kingdom, build and destroy will contain N characters.
-Each character in each element of kingdom will be either '0' or '1'.
-For each i, kingdom[i][i] will be '0'.
-For each i and j, kingdom[i][j] will be equal to kingdom[j][i].
-Each character in each element of build and destroy will be either an uppercase letter ('A'-'Z') or a lowercase letter ('a'-'z').
-For each i, build[i][i] and destroy[i][i] will be 'A'.
-For each i and j, build[i][j] will be equal to build[j][i].
-For each i and j, destroy[i][j] will be equal to destroy[j][i].


EXAMPLES

0)
{"000","000","000"}
{"ABD","BAC","DCA"}
{"ABD","BAC","DCA"}

Returns: 3

There are three cities in the kingdom, totally disconnected. 
The only optimal solution is to build the roads between cities 0-1 (cost 1) and 1-2 (cost 2).

1)
{"011","101","110"}
{"ABD","BAC","DCA"}
{"ABD","BAC","DCA"}

Returns: 1

Now the three cities form a connected triangle and we need to destroy one road. 
Optimal solution is to destroy the road between the cities 0-1 (cost 1).

2)
{"011000","101000","110000","000011","000101","000110"}
{"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"}
{"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"}

Returns: 7

We have six cities forming two separate triangles. 
Like in the Example 1, destroy one road in each triangle (costs 1 for each road) and then join the triangles by a new road (costs 5).

3)
{"0"}
{"A"}
{"A"}

Returns: 0

One city is okay just as it is.

4)
{"0001","0001","0001","1110"}
{"AfOj","fAcC","OcAP","jCPA"}
{"AWFH","WAxU","FxAV","HUVA"}

Returns: 0

We have four cities, which are connected in such a way that there is exactly one path between each two cities. 
Thus there is nothing to reconstruct.

5)
{"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"}
{"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"}
{"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"}

Returns: 65

*/
// END CUT HERE
#line 101 "KingdomReorganization.cpp"

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


int dec(char c) {
	if('A'<=c&&c<='Z') return c-'A';
	if('a'<=c&&c<='z') return c-'a'+26;
	return -1;
}

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

class KingdomReorganization {
	public:
	int getCost(vector <string> ki, vector <string> build, vector <string> destroy) {
		int ans = 0;
		int N=ki.size();
		vector<pair<int, pair<int, int> > > bu;
		REP(i, N) REP(j, N) {
			if(ki[i][j]=='1') {
				bu.PB(MP(-dec(destroy[i][j]), MP(i, j)));
				ans += dec(destroy[i][j]);
				ki[i][j]=ki[j][i]='0';
			} else {
				bu.PB(MP(dec(build[i][j]), MP(i, j)));
			}
		}
		sort(ALL(bu));
		//cout<<bu<<endl;
		
		UnionFind uf(N);
		
		REP(ii, bu.size()) {
			int ei = bu[ii].second.first;
			int ej = bu[ii].second.second;
			int cost = bu[ii].first;
			
			if(uf.unionSet(ei, ej)) ans += cost;
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
//template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
// { os << "{ ";
//   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
//   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, KingdomReorganization().getCost(kingdom, build, destroy));}
int main(){

//if(0)
CASE(0)
	string kingdom_[] = {"000","000","000"};
	  vector <string> kingdom(kingdom_, kingdom_+sizeof(kingdom_)/sizeof(*kingdom_)); 
	string build_[] = {"ABD","BAC","DCA"};
	  vector <string> build(build_, build_+sizeof(build_)/sizeof(*build_)); 
	string destroy_[] = {"ABD","BAC","DCA"};
	  vector <string> destroy(destroy_, destroy_+sizeof(destroy_)/sizeof(*destroy_)); 
	int _ = 3; 
END
CASE(1)
	string kingdom_[] = {"011","101","110"};
	  vector <string> kingdom(kingdom_, kingdom_+sizeof(kingdom_)/sizeof(*kingdom_)); 
	string build_[] = {"ABD","BAC","DCA"};
	  vector <string> build(build_, build_+sizeof(build_)/sizeof(*build_)); 
	string destroy_[] = {"ABD","BAC","DCA"};
	  vector <string> destroy(destroy_, destroy_+sizeof(destroy_)/sizeof(*destroy_)); 
	int _ = 1; 
END
//return 1;
CASE(2)
	string kingdom_[] = {"011000","101000","110000","000011","000101","000110"};
	  vector <string> kingdom(kingdom_, kingdom_+sizeof(kingdom_)/sizeof(*kingdom_)); 
	string build_[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
	  vector <string> build(build_, build_+sizeof(build_)/sizeof(*build_)); 
	string destroy_[] = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
	  vector <string> destroy(destroy_, destroy_+sizeof(destroy_)/sizeof(*destroy_)); 
	int _ = 7; 
END
CASE(3)
	string kingdom_[] = {"0"};
	  vector <string> kingdom(kingdom_, kingdom_+sizeof(kingdom_)/sizeof(*kingdom_)); 
	string build_[] = {"A"};
	  vector <string> build(build_, build_+sizeof(build_)/sizeof(*build_)); 
	string destroy_[] = {"A"};
	  vector <string> destroy(destroy_, destroy_+sizeof(destroy_)/sizeof(*destroy_)); 
	int _ = 0; 
END
CASE(4)
	string kingdom_[] = {"0001","0001","0001","1110"};
	  vector <string> kingdom(kingdom_, kingdom_+sizeof(kingdom_)/sizeof(*kingdom_)); 
	string build_[] = {"AfOj","fAcC","OcAP","jCPA"};
	  vector <string> build(build_, build_+sizeof(build_)/sizeof(*build_)); 
	string destroy_[] = {"AWFH","WAxU","FxAV","HUVA"};
	  vector <string> destroy(destroy_, destroy_+sizeof(destroy_)/sizeof(*destroy_)); 
	int _ = 0; 
END
CASE(5)
	string kingdom_[] = {"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"};
	  vector <string> kingdom(kingdom_, kingdom_+sizeof(kingdom_)/sizeof(*kingdom_)); 
	string build_[] = {"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"};
	  vector <string> build(build_, build_+sizeof(build_)/sizeof(*build_)); 
	string destroy_[] = {"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"};
	  vector <string> destroy(destroy_, destroy_+sizeof(destroy_)/sizeof(*destroy_)); 
	int _ = 65; 
END

}
// END CUT HERE
