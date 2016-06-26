// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// We say that the sequence of numbers {s[0], s[1], s[2], ..., s[N-1]} is sorted in ascending order if we have s[i] <= s[i+1] for each i between 0 and N-2, inclusive.

For example, the sequences {1,2,3}, {1,1,1}, and {2,2,4,4,6,6} are sorted in ascending order, but the sequences {1,2,1}, {7,4,6}, and {3,2,1} are not.

You are given the sequence of numbers as a vector <int> s. Your task is to order the elements of this sequence into a sequence that will NOT be sorted in ascending order. Find and return the lexicographically smallest sequence we can obtain. If there is no possibility to get a sequence that is not sorted in ascending order, return an empty vector <int> instead.

DEFINITION
Class:UnsortedSequence
Method:getUnsorted
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> getUnsorted(vector <int> s)


NOTES
-Sequence of numbers A is lexicographically smaller than B if A contains a smaller number on the first position on which they differ.
-The sequence s may contain duplicates.
-Note that the sequence consisting of only one element is always sorted.


CONSTRAINTS
-s will contain between 1 and 50 elements, inclusive.
-Each element of s will be between 1 and 1000, inclusive.


EXAMPLES

0)
{1,2}

Returns: {2, 1 }

There is only one possible sequence that is not in ascending order: {2,1}.

1)
{1,2,3}

Returns: {1, 3, 2 }

Out of all six possible sequences, five are not in ascending order. Here they are, in lexicographic order:

{1,3,2}
{2,1,3}
{2,3,1}
{3,1,2}
{3,2,1}


2)
{7,2,2}

Returns: {2, 7, 2 }

Remember, that the given sequence may contain duplicates.

3)
{1000}

Returns: { }

As mentioned in the Notes section, the sequence consisting of only one element is always sorted. So there is no possibility to unsort this sequence. 

4)
{1,1}

Returns: { }

There are also some longer sequences that cannot be unsorted.

5)
{1,2,4,3}

Returns: {1, 2, 4, 3 }



6)
{2,8,5,1,10,5,9,9,3,10,5,6,6,2,8,2,10}

Returns: {1, 2, 2, 2, 3, 5, 5, 5, 6, 6, 8, 8, 9, 10, 9, 10, 10 }



*/
// END CUT HERE
#line 90 "UnsortedSequence.cpp"

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



class UnsortedSequence {
	public:
	vector <int> getUnsorted(vector <int> s) {
		sort(ALL(s));
		return next_permutation(ALL(s)) ? s : VI();
		//VI ss(s);
		//next_permutation(ALL(s));
		//cout<<s<<endl;
		//return s==ss ? VI() : s;
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
void verify_case(const vector <int>& Expected, const vector <int>& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, UnsortedSequence().getUnsorted(s));}
int main(){

CASE(0)
	int s_[] = {1,2};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int __[] = {2, 1 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	int s_[] = {1,2,3};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int __[] = {1, 3, 2 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	int s_[] = {7,2,2};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int __[] = {2, 7, 2 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(3)
	int s_[] = {1000};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	vector <int> _; 
END
CASE(4)
	int s_[] = {1,1};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	vector <int> _; 
END
CASE(5)
	int s_[] = {1,2,4,3};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int __[] = {1, 2, 4, 3 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(6)
	int s_[] = {2,8,5,1,10,5,9,9,3,10,5,6,6,2,8,2,10};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int __[] = {1, 2, 2, 2, 3, 5, 5, 5, 6, 6, 8, 8, 9, 10, 9, 10, 10 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(7)
	int s_[] = {2,2,3};
	  vector <int> s(s_, s_+sizeof(s_)/sizeof(*s_)); 
	int __[] = {2, 3, 2 };
	  vector <int> _(__, __+sizeof(__)/sizeof(*__)); 
END

}
// END CUT HERE
