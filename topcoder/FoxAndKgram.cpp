// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Fox Ciel has some pencils.
Before she'll start writing her homework, she wants to place them into a mystic pattern for fun.
Different pencils she has may have different lengths.
You are given a vector <int> len. For each i, the length of i-th pencil is len[i]



The pattern she wants to create is called a k-gram.
A k-gram is a pattern consisting of k rows, each of length k.
There are only two types of valid rows:

Yang: A row containing a single pencil of length k.
Yin: A row containing two pencils such that the sum of their lengths is (k-1). The pencils will be separated by a space of length 1.




Compute and return the largest positive integer k such that Fox Ciel can use some of her pencils to form a k-gram.
If she is unable to form any k-grams, return 0 instead.

DEFINITION
Class:FoxAndKgram
Method:maxK
Parameters:vector <int>
Returns:int
Method signature:int maxK(vector <int> len)


CONSTRAINTS
-len will contain between 1 and 50 elements, inclusive.
-Each element in len will be between 1 and 50, inclusive.


EXAMPLES

0)
{1,1,1,1,3}

Returns: 3

All pencils can be used to form a 3-gram. One valid 3-gram follows:

- -
---
- -


1)
{2,2,1,3,5,5,5}

Returns: 5

One of the valid 5-grams:

-----
-- --
- ---
-----
-----


2)
{1}

Returns: 1



3)
{2,2,2,2,2,2,2,2,2,2}

Returns: 5



4)
{1,2,3,1,2,4,2,3,1}

Returns: 4

Note that it is not necessary to use all of the pencils.

5)
{2,3,5,7,11,13,17,19,23,29}

Returns: 0



*/
// END CUT HERE
#line 96 "FoxAndKgram.cpp"

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



class FoxAndKgram {
	public:
	int maxK(vector <int> len) {
		int N=len.size();
		for(int k=50;k>=0;k--) {
			VI used(N);
			int ok=1;
			int L=0;
			//cout<<k<<endl;
			REP(i, N) {
				if(used[i]) continue;
				if(len[i]==k) {used[i]=1;L++;continue;}
				REP(j, N) {
					if(used[j]||i==j) continue;
					if(len[i]+len[j]+1==k) {used[i]=used[j]=1;L++;break;}
				}
			}
			ok &= L>=k;
			//cout<<ok<<endl;
			if(ok) return k;
		}
		return 0;
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
#define END	 verify_case(_, FoxAndKgram().maxK(len));}
int main(){

CASE(0)
	int len_[] = {1,1,1,1,3};
	  vector <int> len(len_, len_+sizeof(len_)/sizeof(*len_)); 
	int _ = 3; 
END
//return 0;
CASE(1)
	int len_[] = {2,2,1,3,5,5,5};
	  vector <int> len(len_, len_+sizeof(len_)/sizeof(*len_)); 
	int _ = 5; 
END
CASE(2)
	int len_[] = {1};
	  vector <int> len(len_, len_+sizeof(len_)/sizeof(*len_)); 
	int _ = 1; 
END
CASE(3)
	int len_[] = {2,2,2,2,2,2,2,2,2,2};
	  vector <int> len(len_, len_+sizeof(len_)/sizeof(*len_)); 
	int _ = 5; 
END
CASE(4)
	int len_[] = {1,2,3,1,2,4,2,3,1,100};
	  vector <int> len(len_, len_+sizeof(len_)/sizeof(*len_)); 
	int _ = 4; 
END
CASE(5)
	int len_[] = {2,3,5,7,11,13,17,19,23,29};
	  vector <int> len(len_, len_+sizeof(len_)/sizeof(*len_)); 
	int _ = 0; 
END

}
// END CUT HERE


/*

k より大きな値があったら NG としているコードの場合、example 4 に 50 を追加してなげる


*/
