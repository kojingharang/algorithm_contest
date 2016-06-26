// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You used to have only 30 rocks, but now you have plenty of them. In fact, we will assume that you have a potentially infinite supply of rocks. You would like to show that you own over 9000 rocks.
You have a set of boxes. You will choose a subset of those boxes and fill them with rocks so that the total number of rocks will be over 9000. Each box has a lower and an upper bound on the number of rocks it may contain.

You are given the vector <int>s lowerBound and upperBound. For each i, the values lowerBound[i] and upperBound[i] have the following meaning: If you decide to use box i, the number of rocks you may put inside the box must be between lowerBound[i] and upperBound[i], inclusive.

X is a positive integer that has two properties:

X is over 9000.
It is possible to select some of the boxes and fill them with appropriate numbers of rocks in such a way that the total number of rocks used is exactly X.

Compute and return the number of possible values of X.

DEFINITION
Class:Over9000Rocks
Method:countPossibilities
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int countPossibilities(vector <int> lowerBound, vector <int> upperBound)


CONSTRAINTS
-lowerBound will contain between 1 and 15, elements, inclusive.
-upperBound will contain the same number of elements as lowerBound.
-Each element of lowerBound will be between 1 and 1,000,000 (10^6), inclusive.
-Each element i of upperBound will be between lowerBound[i] and 1,000,000 (10^6), inclusive.


EXAMPLES

0)
{9000}
{9001}

Returns: 1

You can place 9000 or 9001 rocks in the single box. Of the allowed values, only 9001 is over 9000.

1)
{9000, 1, 10}
{9000, 2, 20}

Returns: 15

You have to choose box 0 and at least one other box, otherwise you have no chance of placing over 9000 rocks.
If you only choose boxes 0 and 1, you can place 9001 or 9002 rocks.
If you only choose boxes 0 and 2, you can place between 9010 and 9020 rocks, inclusive.
If you choose all three boxes, you can place between 9011 and 9022 rocks, inclusive.
Hence all possible values of X are 9001, 9002, and everything from 9010 to 9022, inclusive.

2)
{1001, 2001, 3001, 3001}
{1003, 2003, 3003, 3003}

Returns: 9



3)
{9000,90000,1,10}
{9000,90000,3,15}

Returns: 38



4)
{1,1,1,1,1,1}
{3,4,5,6,7,8}

Returns: 0



*/
// END CUT HERE
#line 80 "Over9000Rocks.cpp"

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
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }



class Over9000Rocks {
	public:
	int countPossibilities(vector <int> lb, vector <int> ub) {
		vector<PII> w;
		int N=lb.size();
		REP(i, 1<<N) {
			int l=0, u=0;
			REP(j, N) {
				if((i>>j)&1) {
					l+=lb[j];
					u+=ub[j];
				}
			}
			w.PB(MP(l, u));
		}
		sort(ALL(w));
		//cout<<w<<endl;
		VI r(15000001);
		int till = 0;
		REP(i, w.size()) {
			till = max(till, w[i].second);
			for(int j=w[i].first;j<=max(till,w[i].second);j++) {
				if(i+1<w.size() && w[i+1].first <= j) break;
				r[j]=1;
			}
		}
		int ans=0;
		for(int i=9001;i<r.size();i++) {
			ans += r[i];
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
#define END	 verify_case(_, Over9000Rocks().countPossibilities(lowerBound, upperBound));}
int main(){

CASE(0)
	int lowerBound_[] = {9000};
	  vector <int> lowerBound(lowerBound_, lowerBound_+sizeof(lowerBound_)/sizeof(*lowerBound_)); 
	int upperBound_[] = {9001};
	  vector <int> upperBound(upperBound_, upperBound_+sizeof(upperBound_)/sizeof(*upperBound_)); 
	int _ = 1; 
END
CASE(1)
	int lowerBound_[] = {9000, 1, 10};
	  vector <int> lowerBound(lowerBound_, lowerBound_+sizeof(lowerBound_)/sizeof(*lowerBound_)); 
	int upperBound_[] = {9000, 2, 20};
	  vector <int> upperBound(upperBound_, upperBound_+sizeof(upperBound_)/sizeof(*upperBound_)); 
	int _ = 15; 
END
CASE(2)
	int lowerBound_[] = {1001, 2001, 3001, 3001};
	  vector <int> lowerBound(lowerBound_, lowerBound_+sizeof(lowerBound_)/sizeof(*lowerBound_)); 
	int upperBound_[] = {1003, 2003, 3003, 3003};
	  vector <int> upperBound(upperBound_, upperBound_+sizeof(upperBound_)/sizeof(*upperBound_)); 
	int _ = 9; 
END
CASE(3)
	int lowerBound_[] = {9000,90000,1,10};
	  vector <int> lowerBound(lowerBound_, lowerBound_+sizeof(lowerBound_)/sizeof(*lowerBound_)); 
	int upperBound_[] = {9000,90000,3,15};
	  vector <int> upperBound(upperBound_, upperBound_+sizeof(upperBound_)/sizeof(*upperBound_)); 
	int _ = 38; 
END
CASE(4)
	int lowerBound_[] = {1,1,1,1,1,1};
	  vector <int> lowerBound(lowerBound_, lowerBound_+sizeof(lowerBound_)/sizeof(*lowerBound_)); 
	int upperBound_[] = {3,4,5,6,7,8};
	  vector <int> upperBound(upperBound_, upperBound_+sizeof(upperBound_)/sizeof(*upperBound_)); 
	int _ = 0; 
END
CASE(3)
	int lowerBound_[] = {177258, 439976, 996972, 281567, 782547, 998375, 491481, 707710, 146177, 889410};
	  vector <int> lowerBound(lowerBound_, lowerBound_+sizeof(lowerBound_)/sizeof(*lowerBound_)); 
	int upperBound_[] = {293261, 559909, 997946, 410135, 784021, 998581, 925665, 743314, 626775, 943659};
	  vector <int> upperBound(upperBound_, upperBound_+sizeof(upperBound_)/sizeof(*upperBound_)); 
	int _ = 7137090; 
END
//CASE(3)
//	int lowerBound_[] = {9000, 3, 11, 50, 100, 900007, 90007, 102, 7, 11, 307, 9007, 1, 997, 56};
//	  vector <int> lowerBound(lowerBound_, lowerBound_+sizeof(lowerBound_)/sizeof(*lowerBound_)); 
//	int upperBound_[] = {9000, 5, 13, 54, 100, 1000000, 100007, 104, 9, 11, 309, 9013, 1000000, 1009, 57};
//	  vector <int> upperBound(upperBound_, upperBound_+sizeof(upperBound_)/sizeof(*upperBound_)); 
//	int _ = 2110691; 
//END

}
// END CUT HERE
