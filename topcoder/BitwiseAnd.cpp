// BEGIN CUT HERE
/******************************
// PROBLEM STATEMENT
// 
For non-negative integers A and B, let A&B denote the bitwise AND operation.
That is, for each i, the i-th bit of A&B in binary representation is 1 if and only if the i-th bits of A and B are 1.



We call a set of non-negative integers S cool if the following conditions are satisfied.


For any two distinct elements A, B in S, A&B > 0.
For any three distinct elements A, B, C in S, A&B&C = 0.



You are given a vector<long long> subset and an int N.
All elements in subset are distinct.
Compute a cool set with N distinct elements such that the cool set contains each element of subset and each element is between 1 and 2^60 - 1, inclusive.
Return one such cool set as a vector<long long> with elements in increasing order.
If there are multiple solutions, return the lexicographically smallest one.
If there are no such cool sets, return an empty vector<long long> instead.




DEFINITION
Class:BitwiseAnd
Method:lexSmallest
Parameters:vector<long long>, int
Returns:vector<long long>
Method signature:vector<long long> lexSmallest(vector<long long> subset, int N)


CONSTRAINTS
-N will be between 3 and 50, inclusive.
-subset will contain between 0 and N elements, inclusive.
-Each element of subset will be between 1 and 2^60 - 1, inclusive.
-All the elements in subset will be distinct.
-Elements in subset will be sorted in increasing order.


EXAMPLES

0)
{14, 20}
3

Returns: {14, 18, 20 }
01110
10100
10010 *

There are several possible cool sets.
For example, the following sets are cool and each of them contains all the elements of subset.

{14, 18, 20}
{14, 20, 26}
{14, 20, 50}
...
  
Among these sets, the first one is the lexicographically smallest one.



1)
{11, 17, 20}
4

01011
10001
10100


Returns: { }

There is no cool set because (11&20) equals 0.

2)
{99, 157}
4

001100011
010011101
100000110
100101000



Returns: {99, 157, 262, 296 }




3)
{1152921504606846975}
3

Returns: { }

The element in subset equals to 2^60-1.
Note that each element of your cool set should be less than or equal to 2^60-1. 

4)
{}
5

Returns: {15, 113, 402, 676, 840 }



5)
{1, 3, 5, 7, 9, 11}
6

Returns: { }



******************************/
// END CUT HERE
#line 108 "BitwiseAnd.cpp"
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

class BitwiseAnd {
	public:
	ll add;
	VVI w;
	int N, M;
	VI S;
	bool check(bool init) {
		REP(bit, 60) {
			VI one;
			REP(i, S.size()) {
				if((S[i]>>bit)&1) one.PB(i);
			}
			if(one.size()>2) return false;
			if(one.size()==2) w[one[1]][one[0]] = w[one[0]][one[1]] = 1;
			if(!init && one.size()==1 && w[one[0]][S.size()]==0) {
				add |= 1LL<<bit;
				w[one[0]][S.size()] = w[S.size()][one[0]] = 1;
			}
		}
		if(!init) {
			S.PB(add);
//			sort(ALL(S));
//			cout<<"added "<<S<<endl;
		}
//		cout<<w<<endl;
		REP(i, S.size()) REP(j, S.size()) {
			if(i!=j && w[i][j]==0) {
				if(init) {
					return false;
				}
			}
		}
		return true;
	}
	vector<long long> lexSmallest(vector<long long> _S, int N) {
		S=_S;
		M=S.size();
		w = VVI(N, VI(N));
		if(!check(true)) return vector<ll>();
		while(S.size()<N) {
			add=0;
			if(!check(false)) return vector<ll>();
		}
		REP(i, S.size()) REP(j, S.size()) {
			if(i!=j && w[i][j]==0) {
//				cout<<"not "<<endl;
				if(i<M || j<M) continue;
				bool ok=false;
				REP(bit, 60) {
					bool lok=true;
					REP(k, S.size()) if((S[k]>>bit)&1) lok=false;
					if(lok) {
						ll a = 1LL<<bit;
						S[i] |= a;
						S[j] |= a;
						w[i][j]=w[j][i]=1;
//						cout<<"modify "<<S<<endl;
						ok=true;
					}
					if(ok) break;
				}
			}
		}
		if(!check(true)) return vector<ll>();
		sort(ALL(S));
		return S;
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
void verify_case(const vector<long long>& Expected, const vector<long long>& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, BitwiseAnd().lexSmallest(subset, N));}
int main(){
CASE(0)
	long subset_[] = {14, 20};
	  vector<long long> subset(subset_, subset_+sizeof(subset_)/sizeof(*subset_)); 
	int N = 3; 
	long __[] = {14, 18, 20 };
	  vector<long long> _(__, __+sizeof(__)/sizeof(*__)); 
END
//return 0;
CASE(1)
	long subset_[] = {11, 17, 20};
	  vector<long long> subset(subset_, subset_+sizeof(subset_)/sizeof(*subset_)); 
	int N = 4; 
	vector<long long> _; 
END
CASE(2)
	long subset_[] = {99, 157};
	  vector<long long> subset(subset_, subset_+sizeof(subset_)/sizeof(*subset_)); 
	int N = 4; 
	long __[] = {99, 157, 262, 296 };
	  vector<long long> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	long subset_[] = {1152921504606846975};
	  vector<long long> subset(subset_, subset_+sizeof(subset_)/sizeof(*subset_)); 
	int N = 3; 
	vector<long long> _; 
END
CASE(4)
	vector<long long> subset; 
	int N = 5; 
	long __[] = {15, 113, 402, 676, 840 };
	  vector<long long> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(5)
	long subset_[] = {1, 3, 5, 7, 9, 11};
	  vector<long long> subset(subset_, subset_+sizeof(subset_)/sizeof(*subset_)); 
	int N = 6; 
	vector<long long> _; 
END

}
// END CUT HERE
