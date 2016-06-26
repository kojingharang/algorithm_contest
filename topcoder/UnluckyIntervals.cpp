// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are given a set of integers called luckySet.  An interval [A,B], where B is greater than A, and A and B are positive integers, is considered unlucky if none of the integers between A and B, inclusive, belongs to luckySet.

An integer x is considered to be luckier than another integer y if the number of unlucky intervals that contain x is smaller than the number of unlucky intervals that contain y.  In case both x and y belong to an equal number of unlucky intervals, or both belong to an infinite number of unlucky intervals, the smallest of them is considered to be luckier than the other.

Given a vector <int> luckySet, return the top n luckiest positive integers sorted in descending order by luckiness (in other words, each element of the vector <int> must be luckier than the next element).

DEFINITION
Class:UnluckyIntervals
Method:getLuckiest
Parameters:vector <int>, int
Returns:vector <int>
Method signature:vector <int> getLuckiest(vector <int> luckySet, int n)


CONSTRAINTS
-luckySet will contain between 1 and 50 elements, inclusive.
-Each element of luckySet will be between 1 and 1000000000, inclusive.
-Each element of luckySet will be distinct.
-n will be between 1 and 100, inclusive.


EXAMPLES

0)
{3}
6

Returns: {3, 1, 2, 4, 5, 6 }

0 unlucky intervals contain 3.
1 unlucky interval contains 1: [1,2].
1 unlucky interval contains 2: [1, 2].
Since 1 and 2 are inside an equal number of intervals, 1 is considered luckier because it is less than 2.
For every number greater than 3, there is an infinite number of unlucky intervals that contain it. However, 4 and 5 are considered to be the luckiest among them, as they are smallest.

1)
{5, 11, 18}
9

Returns: {5, 11, 18, 1, 4, 6, 10, 2, 3 }

3 unlucky intervals: [1,2], [1,3] and [1,4] include 1. 
3 unlucky intervals: [1,4], [2,4] and [3,4] include 4. 
4 unlucky intervals: [6,7], [6,8], [6,9] and [6,10] include 6. 
4 unlucky intervals: [6,10], [7,10], [8,10] and [9,10] include 10. 
5 unlucky intervals: [1,2], [1,3], [1,4], [2,3] and [2,4] include 2. 
5 unlucky intervals: [1,3], [1,4], [2,3], [2,4] and [3,4] include 3. 



2)
{7, 13, 18}
9

Returns: {7, 13, 18, 14, 17, 8, 12, 1, 6 }



3)
{1000, 1004, 4000, 4003, 5000}
19

Returns: {1000, 1004, 4000, 4003, 5000, 4001, 4002, 1001, 1003, 1002, 4004, 4999, 1, 999, 4005, 4998, 2, 998, 4006 }



4)
{1000000000}
8

Returns: {1000000000, 1, 999999999, 2, 999999998, 3, 999999997, 4 }



*/
// END CUT HERE
#line 81 "UnluckyIntervals.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }

ll nC2(int n) {
	if(n<2) return 0;
	return (ll)n*(n-1)/2;
}

ll lu(int L, int k) {
	//cout<<"lu "<<L<<" "<<k<<endl;
	return nC2(L)-nC2(k)-nC2(L-k-1);
}


class UnluckyIntervals {
	public:
	vector <int> getLuckiest(vector <int> ls, int n) {
		sort(ALL(ls));
		VI ans;
		VI tmp(ls);
		int bb=1;
		FOR(v, ls) {
			if(bb+1==*v) tmp.push_back(bb);
			bb=*v+1;
		}
		sort(ALL(tmp));
		FOR(v, tmp) {
			if(n--==0) break;
			ans.push_back(*v);
		}
		if(n<=0) return ans;
		
		vector<pair<ll, int> > w;
		int b=1;
		FOR(v, ls) {
			//cout<<b<<" "<<*v<<endl;
			int L=*v-b;
			int k=min(L, n);
			REP(i, k/2) {
				ll a0 = lu(L, i);
				ll a1 = lu(L, L-i-1);
				//cout<<" "<<a0<<"  "<<b+i<<endl;
				//cout<<" "<<a1<<"  "<<b+L-i-1<<endl;
				w.push_back(make_pair(a0, b+i));
				w.push_back(make_pair(a1, b+L-i-1));
			}
			if(k&1) {
				int i=k/2;
				ll a0 = lu(L, i);
				//cout<<" "<<a0<<"  "<<b+i<<endl;
				w.push_back(make_pair(a0, b+i));
			}
			b=*v+1;
		}
		sort(ALL(w));
		FOR(v, w) {
			if(n==0) break;
			int ok=1;
			FOR(vv, ans) if(*vv==v->second) ok=0;
			if(ok) {
				ans.push_back(v->second);
				n--;
			}
		}
		int rest=ls[ls.size()-1]+1;
		//cout<<n<<endl;
		while(n-->0) {
			ans.push_back(rest++);
		}
		
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	//void test_case_0() { int Arr0[] = {3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arr2[] = {3, 1, 2, 4, 5, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_0() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arr2[] = {1 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5, 11, 18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arr2[] = {5, 11, 18, 1, 4, 6, 10, 2, 3 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {7, 13, 18}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arr2[] = {7, 13, 18, 14, 17, 8, 12, 1, 6 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1000, 1004, 4000, 4003, 5000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; int Arr2[] = {1000, 1004, 4000, 4003, 5000, 4001, 4002, 1001, 1003, 1002, 4004, 4999, 1, 999, 4005, 4998, 2, 998, 4006 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, getLuckiest(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arr2[] = {1000000000, 1, 999999999, 2, 999999998, 3, 999999997, 4 }; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, getLuckiest(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	UnluckyIntervals ___test;

	___test.run_test(-1);
	//___test.test_case_1();

}

// END CUT HERE
