// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


There are N trees arranged in a straight horizontal line. They are numbered 0 through N-1 from left to right. The distance between tree i and tree (i+1) is distance[i], and the initial vertical height of tree i is height[i]. Each tree is assumed to be a perfect vertical segment.


Your goal is to make the topmost points of all the trees collinear. To do this, you can choose any number of trees and have them travel back to a time when they were shorter. You can decrease the height of each chosen tree to any non-negative value (not necessarily an integer). You will operate on each tree individually, so the trees do not all have to decrease in height by the same amount. The trees that you do not choose will all remain at their original heights.


Return the minimum number of trees you must send back in time to achieve this goal.

DEFINITION
Class:TimeTravellingGardener
Method:determineUsage
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int determineUsage(vector <int> distance, vector <int> height)


NOTES
-Two or more points are collinear if they lie on a single straight line.


CONSTRAINTS
-distance will contain between 1 and 49 elements, inclusive.
-Each element of distance will be between 1 and 1000, inclusive.
-The number of elements in height will be one plus the number of elements in distance.
-Each element of height will be between 1 and 1000, inclusive.


EXAMPLES

0)
{2,2}
{1,3,10}

Returns: 1



1)
{3,3}
{3,1,3}

Returns: 2



2)
{1,3}
{4,4,4}

Returns: 0



3)
{4,2}
{9,8,5}

Returns: 1



4)
{476,465,260,484}
{39,13,8,72,80}

Returns: 3



5)
{173,36,668,79,26,544}
{488,743,203,446,444,91,453}

Returns: 5

6)
{2,4,2,2,4,2,4,2,2,4}
{2,2,10,10,10,16,16,22,22,28,28}

Returns: 6



*/
// END CUT HERE
#line 93 "TimeTravellingGardener.cpp"
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define B begin()
#define E end()
#define SZ size()
#define PB(v) push_back(v)
using namespace std;
#define REP(i, n) for(int i=0, _n=(n);(i)<_n;i++)
#define FOR(i, a, b) for(int i=(a),_b=(b);(i)<_b;i++)
#define FORD(i, a, b) for(int i=(a),_b=(b);(i)>=_b;i--)
#define CLR(a) memset(a, 0, sizeof(a))
#define SORT(v) sort(v.B, v.E)
template <typename T>
void UNIQ(T& v)
{
	typename T::iterator end = unique(v.B, v.E);
	v.erase(end, v.end());
}
template <typename T0, typename T1>
std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v)
{
	for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ )
	{
		os << p->first << ": " << p->second << " ";
	}
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v)
{
	for( int i = 0; i < v.size(); i++ )
	{
		os << v[i] << " ";
	}
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const set<T>& v)
{
	vector<T> tmp(v.B, v.E);
	os << tmp;
	return os;
}

vector<vector<int> > combination(vector<int> vi, int K)
{
	sort(vi.begin(), vi.end());

	set<vector<int> > se;
	do
	{
		vector<int> tm(vi.begin(), vi.begin()+K);
		sort(tm.begin(), tm.end());
		se.insert(tm);
	}
	while(next_permutation(vi.begin(), vi.end()));
	return vector< vector<int> >(se.begin(), se.end());
}


class TimeTravellingGardener {
	public:
	int tdist(int idx, vector <int> d)
	{
		int dist = 0;
		REP(i, idx) dist+=d[i];
		return dist;
	}
	int determineUsage(vector <int> d, vector <int> h) {
printf("%s %d\n", __FILE__, __LINE__);
		int ans = h.SZ;
		
		int mintv = 2000;
		REP(i, h.SZ) if(h[i]<mintv) {mintv=h[i];}
		
		REP(mint, h.SZ)
		{
			if(h[mint]!=mintv) continue;
			
			cout<<"mint "<<mint<<endl;
			
			VI rh(h.SZ);
			REP(ri, h.SZ+2)
			{
				if(ri==mint) continue;
				int rd = tdist(ri, d);
				int md = tdist(mint, d);
				int rh = h[ri];
				if(ri==h.SZ)
				{
					rd = 0;
					rh = 0;
					if(mint==0) continue;
				}
				if(ri==h.SZ+1)
				{
					rd = tdist(h.SZ-1, d);
					rh = 0;
					if(mint==h.SZ-1) continue;
				}
				double cA = (double)(rh-h[mint])/(rd-md);
				double cB = h[mint] - cA * md;
				cout<<ri<<" -> "<<cA<<" "<<cB<<endl;
				
				int ok=1;
				int cut=0;
				REP(ti, h.SZ)
				{
					if(ti==mint) continue;
					double tih = cA * tdist(ti, d) + cB;
					cout<<"tih: "<<tih<<endl;
					if(tih < -0.00001) {ok=0; cout<<"NG UG"<<ti<<endl;}
					if(tih > h[ti]+0.00001) {ok=0; cout<<"NG low"<<ti<<endl;}
					if(tih < h[ti]-0.00001) cut++;
				}
				if(ok)
				{
					ans = min(ans, cut);
					cout<<"ok cut "<<cut<<endl;
				}
			}
		}
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9,8,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(3, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {476,465,260,484}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {39,13,8,72,80}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(4, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {173,36,668,79,26,544}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {488,743,203,446,444,91,453}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(5, Arg2, determineUsage(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {2,4,2,2,4,2,4,2,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,2,10,10,10,16,16,22,22,28,28}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(6, Arg2, determineUsage(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	TimeTravellingGardener ___test;

	___test.run_test(-1);

}

// END CUT HERE
