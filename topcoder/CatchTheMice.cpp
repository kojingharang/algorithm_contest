// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A fairground operator has designed a new game, called "Catch the Mice". This consists of a set of electronic "mice" that move around on a large board. The contestant controls a square cage, which is initially suspended above the board. The contestant can position the cage anywhere above the board and then drop it, the aim being to enclose some of the mice in the cage. The contestant wins a prize accoring to how many mice he managed to capture. If the contestant captures all of the mice, then he wins the grand prize, which is a sports car. However the fairground operator is not entirely honest, and wants your help to rig the game so that it is impossible to win the grand prize. He wants to make the cage sufficiently small that at no point in time are the mice close enough for it to capture them all.
Consider the mice as a set of points moving in an infinite 2D cartesian plane. Each mouse starts at a known position at time t = 0, then moves with constant velocity in time t ? 0. Consider the cage as a perfect square of side length L, that can be positioned anywhere in the plane with its sides parallel to the axes (i.e., the contestant can move, but cannot rotate the cage). The cage can be dropped at any time t ? 0 and it will capture a mouse if at that point in time the mouse's position is strictly contained within its boundary (mice exactly on the boundary are not considered to be captured). You should calculate the maximum value of L that doesn't allow all the mice to be captured.
You will be given 4 vector <int>s xp, yp, xv and yv. The position of the mouse with index i is given by (xp[i], yp[i]) and its velocity by (xv[i], yv[i]). The position of the mouse at time t will therefore be (xp[i] + xv[i]*t, yp[i] + yv[i]*t). Return a double giving the length of the side of the largest cage that cannot capture all the mice at any time t ? 0.

DEFINITION
Class:CatchTheMice
Method:largestCage
Parameters:vector <int>, vector <int>, vector <int>, vector <int>
Returns:double
Method signature:double largestCage(vector <int> xp, vector <int> yp, vector <int> xv, vector <int> yv)


NOTES
-Your return value must be accurate to an absolute or relative tolerance of 1e-9.


CONSTRAINTS
-xp, yp, xv and yv will contain between 2 and 50 elements, inclusive.
-xp, yp, xv and yv will contain the same number of elements.
-Each element of xp, yp, xv and yv will be between -1000 and 1000, inclusive.
-At no point in time t ? 0 will any two mice occupy the same point in space.


EXAMPLES

0)
{0,10}
{0,10}
{10,-10}
{0,0}

Returns: 10.0

A cage with side length greater than 10 would be able to catch both the mice at any time before t = 1.

1)
{0,10,0}
{0,0,10}
{1,-6,4}
{4,5,-4}

Returns: 3.0

At time t = 1, the mice are at positions (1, 4), (4, 5) and (4, 6). At this point in time any cage with an edge length larger than 3 would be able to catch them. This is the point in time when the mice are closest together.

2)
{50,10,30,15}
{-10,30,20,40}
{-5,-10,-15,-5}
{40,-10,-1,-50}

Returns: 40.526315789473685



3)
{0,10,10,0}
{0,0,10,10}
{1,0,-1,0}
{0,1,0,-1}

Returns: 10.0



4)
{13,50,100,40,-100}
{20,20,-150,-40,63}
{4,50,41,-41,-79}
{1,1,1,3,-1}

Returns: 212.78688524590163



5)
{0,10}
{0,0}
{5,5}
{3,3}

Returns: 10.0



6)
{-49,-463,-212,-204,-557,-67,-374,-335,-590,-4}
{352,491,280,355,129,78,404,597,553,445}
{-82,57,-23,-32,89,-72,27,17,100,-94}
{-9,-58,9,-14,56,75,-32,-98,-81,-43}

Returns: 25.467532467532468

*/
// END CUT HERE
#line 100 "CatchTheMice.cpp"

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

#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class CatchTheMice {
	public:
	double largestCage(vector <int> xp, vector <int> yp, vector <int> xv, vector <int> yv) {
		int N=xp.size();
		long double lo=0, hi=2000;
		REP(tt, 100) {
			long double mid=(lo+hi)/2;
			vector<long double> ts;
			REP(i, N) {
				for(int j=i+1;j<N;j++) {
					long double t0 = xv[j]!=xv[i] ? ((long double)xp[i]-xp[j]+mid)/(xv[j]-xv[i]) : -1;
					long double t1 = xv[j]!=xv[i] ? ((long double)xp[i]-xp[j]-mid)/(xv[j]-xv[i]) : -1;
					long double t2 = yv[j]!=yv[i] ? ((long double)yp[i]-yp[j]+mid)/(yv[j]-yv[i]) : -1;
					long double t3 = yv[j]!=yv[i] ? ((long double)yp[i]-yp[j]-mid)/(yv[j]-yv[i]) : -1;
					if(t0>=0) ts.push_back(t0);
					if(t1>=0) ts.push_back(t1);
					if(t2>=0) ts.push_back(t2);
					if(t3>=0) ts.push_back(t3);
				}
			}
			ts.push_back(0);
			//cout<<ts<<endl;
			
			long double minL = 1e10;
			FOR(v, ts) {
				long double t = *v;
				long double xmi=1e10, xma=-1e10;
				long double ymi=1e10, yma=-1e10;
				REP(i, N) {
					long double xxp = xp[i]+t*xv[i];
					long double yyp = yp[i]+t*yv[i];
					xmi = min(xmi, xxp);
					ymi = min(ymi, yyp);
					xma = max(xma, xxp);
					yma = max(yma, yyp);
				}
				minL = min(minL, max(xma-xmi, yma-ymi));
			}
			//cout<<"L "<<minL<<endl;
			if(minL <= mid+1e-12) hi=mid; else lo=mid;
			//cout<<lo<<"  "<<hi<<" "<<mid<<endl;
		}
		return lo;
	}
	//double largestCage(vector <int> xp, vector <int> yp, vector <int> xv, vector <int> yv) {
	//	int N=xp.size();
	//	double lo=0, hi=2000;
	//	REP(tt, 100) {
	//		double mid=(lo+hi)/2;
	//		vector<double> ts;
	//		double tB=0, tE=1e10;
	//		int ok=1;
	//		REP(i, N) {
	//			for(int j=i+1;j<N;j++) {
	//				if(xv[j]!=xv[i]) {
	//					double t0 = ((double)xp[i]-xp[j]+mid)/(xv[j]-xv[i]);
	//					double t1 = ((double)xp[i]-xp[j]-mid)/(xv[j]-xv[i]);
	//					if(t0>t1) swap(t0, t1);
	//					tB=max(tB, t0);
	//					tE=min(tE, t1);
	//				} else {
	//					if(abs((double)xp[i]-xp[j]) >= mid) ok=0;
	//				}
	//				if(yv[j]!=yv[i]) {
	//					double t0 = ((double)yp[i]-yp[j]+mid)/(yv[j]-yv[i]);
	//					double t1 = ((double)yp[i]-yp[j]-mid)/(yv[j]-yv[i]);
	//					if(t0>t1) swap(t0, t1);
	//					tB=max(tB, t0);
	//					tE=min(tE, t1);
	//				} else {
	//					if(abs((double)yp[i]-yp[j]) >= mid) ok=0;
	//				}
	//			}
	//		}
	//		if(tB>=tE) ok=0;
	//		if(ok) hi=mid; else lo=mid;
	//	}
	//	return lo;
	//}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	//private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) {
		cerr << "Test Case #" << Case << "...";
		if (abs(Expected-Received)<1e-9) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; }
	}
	void test_case_0() { int Arr0[] = {0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10,-10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 10.0; verify_case(0, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {0,10,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,-6,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4,5,-4}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 3.0; verify_case(1, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {50,10,30,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-10,30,20,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-5,-10,-15,-5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {40,-10,-1,-50}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 40.526315789473685; verify_case(2, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {0,10,10,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,10,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,0,-1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0,1,0,-1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 10.0; verify_case(3, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {13,50,100,40,-100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {20,20,-150,-40,63}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,50,41,-41,-79}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {1,1,1,3,-1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 212.78688524590163; verify_case(4, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arr0[] = {0,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3,3}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 10.0; verify_case(5, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	//void test_case_6() { int Arr0[] = {-49,-463,-212,-204,-557,-67,-374,-335,-590,-4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {352,491,280,355,129,78,404,597,553,445}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-82,57,-23,-32,89,-72,27,17,100,-94}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {-9,-58,9,-14,56,75,-32,-98,-81,-43}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); double Arg4 = 25.467532467532468; verify_case(6, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { 
		int Arr0[] = {520, -706}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
		int Arr1[] = {-709, -150}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
		int Arr2[] = {0, 9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); 
		int Arr3[] = {9, -1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); 
		double Arg4 = 380.4736842105263; verify_case(6, Arg4, largestCage(Arg0, Arg1, Arg2, Arg3)); }
// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	CatchTheMice ___test;

	___test.run_test(-1);
	//___test.test_case_6();

}

// END CUT HERE
