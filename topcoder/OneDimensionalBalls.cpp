// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There is an infinite axis with N balls on it. The balls are moving with equal positive velocity, some of them in the positive direction of the axis and some in the opposite. The balls are small enough to be treated as points on the axis. If two balls meet at a point, they do not collide, and instead, they each continue moving in the same direction and at the same speed as before.

Manao is shown a picture of the axis taken at some moment of time. All the balls are at different points in the picture. The balls are numbered from 0 to N-1 and the i-th ball is at point firstPicture[i].

Some time after the first picture is taken, several balls are added to the axis and another picture is taken. Yet again, no two balls share a point in this picture. The balls seem indistinguishable and their coordinates are given in vector <int> secondPicture in ascending order.

For each ball in the second picture, Manao has to guess whether it is present on the first one as well, and if so, say its number. Sometimes, this can't be determined unambiguously, so any valid guess is welcome. A guess is valid if the balls could move in the way described above and appear in the named locations in the second picture. Two guesses are different if there is a ball in the second picture which Manao identifies differently in these guesses. Return the number of valid guesses for the given pictures.


DEFINITION
Class:OneDimensionalBalls
Method:countValidGuesses
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long countValidGuesses(vector <int> firstPicture, vector <int> secondPicture)


CONSTRAINTS
-firstPicture will contain N elements, where N is between 1 and 50, inclusive.
-Each element of firstPicture will be between 0 and 100,000,000, inclusive.
-Elements in firstPicture will be distinct.
-secondPicture will contain between N and 50 elements, inclusive.
-Each element of secondPicture will be between 0 and 100,000,000, inclusive.
-Elements in secondPicture will be in strictly ascending order.


EXAMPLES

0)
{12,11}
{10,11,13}

Returns: 3

There are 2 balls in the first picture at points 12 and 11, respectively. One more ball is added in the second picture. The following three guesses are valid:
1) The ball at point 10 is ball 0, the ball at point 11 is the new one, the ball at point 13 is ball 1.
2) The ball at point 10 is ball 1, the ball at point 11 is ball 0, the ball at point 13 is the new one.
3) The ball at point 10 is ball 1, the ball at point 11 is the new one, the ball at point 13 is ball 0.

1)
{1,2,3}
{1,2,3}

Returns: 0

Each picture contains the same number of balls, so they must contain the same set of balls.  However, given that some time has passed between the shots, and the balls move with equal positive velocity, there is no way for them to have interchanged positions.


2)
{1,3}
{1,3}

Returns: 1

If the balls move in opposite directions, they will interchange their positions at some moment.

3)
{7234}
{6316,689156,689160,689161,800000,1000001}

Returns: 6

Ball 0 could be any of the balls in the second picture.

4)
{6,2,4}
{1,2,3,4,5,7,8}

Returns: 7



*/
// END CUT HERE
#line 79 "OneDimensionalBalls.cpp"
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
class OneDimensionalBalls {
	public:
	ll do_try(vector <int>& fP, vector <int>& sP, int vel, int fi_b, set<int> se)
	{
		int fz = fP.SZ;
		int sz = sP.SZ;
		int ok = 1;
		ll lans = 0;
		// assert p in fp is sp as p+-vel
		if(fi_b==fz) {/*cout<<"back"<<endl;*/return 1;}
		int fi = fi_b;
		{
			cout<<"fi "<<fi<<" ::: "<<se<< endl;
			int exist = 0;
			REP(si, sz)
			{
				if(se.find(si)!=se.E) continue;
				//cout<<" si "<<si<<endl;
				if(fP[fi]+vel==sP[si]) {cout<<" "<<fi<<":"<<si<<endl; set<int> lse(se.B, se.E); lse.insert(si); lans += do_try(fP, sP, vel, fi+1, lse);}
				if(fP[fi]-vel==sP[si]) {cout<<" "<<fi<<":"<<si<<endl; set<int> lse(se.B, se.E); lse.insert(si); lans += do_try(fP, sP, vel, fi+1, lse);}
			}
		}
		if(lans) { cout<<"back += "<<lans<<endl; } else {cout<<"back NG"<<endl;}
		return lans;
	}
	long long countValidGuesses(vector <int> fP, vector <int> sP) {
printf("%s %d\n", __FILE__, __LINE__);
		cout<<fP<<endl;
		cout<<sP<<endl;
		ll ans = 0;
		int fz = fP.SZ;
		int sz = sP.SZ;
		VI vels;
		REP(fi, fz)
		REP(si, sz)
		{
			if(fP[fi]==sP[si]) continue;
			vels.PB(abs(fP[fi]-sP[si]));
		}
		SORT(vels);
		UNIQ(vels);
		//VI::iterator viend = unique(vels.B, vels.E);
		//vels.erase(viend, vels.end());
		cout<<vels<<endl;
		REP(i, vels.SZ)
		{
			set<int> se;
			cout<<"vel "<<vels[i]<<"--------------------"<<endl;
			ans += do_try(fP, sP, vels[i], 0, se);
			cout<<"ans "<<ans<<endl;
		}
		cout<<ans<<endl;
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {12,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,11,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 3LL; verify_case(0, Arg2, countValidGuesses(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(1, Arg2, countValidGuesses(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(2, Arg2, countValidGuesses(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {7234}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6316,689156,689160,689161,800000,1000001}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 6LL; verify_case(3, Arg2, countValidGuesses(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {6,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 7LL; verify_case(4, Arg2, countValidGuesses(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	OneDimensionalBalls ___test;

	___test.run_test(-1);

}

// END CUT HERE
