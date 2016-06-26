// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Your friend has invented a splendid cocktail consisting of N ingredients.  However, she has forgotten the amount of each ingredient that goes into the recipe.

For N-1 pairs of ingredients, she remembers the proportion in which the ingredients within each pair should be added to the cocktail. Fortunately, these N-1 proportions are sufficient to restore the recipe of the entire cocktail.

You are given a vector <string> proportions containing the N-1 proportions. Each element is formatted "# and # as :<q>" (quotes for clarity), which means that the mass of ingredient  divided by the mass of ingredient  in the cocktail must be equal to /<q> (all ingredients are 0-indexed). Return a vector <int> containing exactly N elements, where the i-th element is the mass of ingredient i, such that all the given proportions are satisfied and the total mass is as small as possible.  The total mass must be greater than 0.

DEFINITION
Class:IngredientProportions
Method:getMasses
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> getMasses(vector <string> proportions)


CONSTRAINTS
-proportions will contain between 1 and 9 elements, inclusive.
-proportions will contain exactly N-1 elements, where N is the number of ingredients in the cocktail.
-Each element of proportions will contain exactly 16 characters.
-Each element of proportions will be formatted as described in the statement.
-Each  will be between 0 and N-1, inclusive.
-Each  will be between 0 and N-1, inclusive.
-Each  will be between 1 and 9, inclusive.
-Each <q> will be between 1 and 9, inclusive.
-The information given in proportions will be sufficient to restore the recipe of the cocktail uniquely up to a constant factor.


EXAMPLES

0)
{"#0 and #1 as 6:4"}

Returns: {3, 2 }

Taking 6 units of ingredient #0 and 4 units of ingredient #1 would satisfy the proportion, but it wouldn't give the smallest possible total mass. To minimize the total mass, divide the masses by 2.

1)
{"#0 and #1 as 9:8","#1 and #2 as 9:8"}


Returns: {81, 72, 64 }



2)
{"#4 and #0 as 1:1", "#4 and #1 as 3:1", "#4 and #2 as 5:1", "#4 and #3 as 7:1"}

Returns: {105, 35, 21, 15, 105 }

The mass of ingredient #4 should be divisible by 3, 5 and 7. The smallest such number is 105.

3)
{"#2 and #3 as 6:8", "#0 and #1 as 9:3", "#3 and #0 as 7:5"}

Returns: {60, 20, 63, 84 }



*/
// END CUT HERE
#line 64 "IngredientProportions.cpp"

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
#define VVI vector<vector<int> >
#define PII pair<ll, ll> 
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }


ll GCD ( ll a, ll b ) {
	if(a<b) {
		ll tmp=a;
		a=b; b=tmp;
	}
	ll c;
	while ( a != 0 ) {
		c = a; a = b%a;  b = c;
	}
	return b;
}
ll LCM( ll a, ll b ) {
	return a/GCD(a, b)*b;
}

class IngredientProportions {
	public:
	vector <int> getMasses(vector <string> pr) {
		int N=pr.size()+1;
		vector<vector< PII > > w(N, vector<PII >(N, make_pair(0, 0)));
		FOR(v, pr) {
			int a=(*v)[1]-'0';
			int b=(*v)[8]-'0';
			int p=(*v)[13]-'0';
			int q=(*v)[15]-'0';
			int g = GCD(p, q);
			p/=g; q/=g;
			cout<<"- "<<a<<" "<<b<<" "<<p<<" "<<q<<" "<<g<<endl;
			w[a][b]=make_pair(p, q);
			w[b][a]=make_pair(q, p);
		}
		cout<<w<<endl;
		REP(tt, N)
		REP(i, N)
		REP(j, N)
		REP(k, N) {
			//if(w[i][j].first>0) continue;
			ll a = w[i][k].first*w[k][j].first;
			ll b = w[i][k].second*w[k][j].second;
			//cout<<i<<" "<<j<<" "<<k<<"  "<<a<<" "<<b<<endl;
			if(w[i][k].first==0||w[k][j].first==0) continue;
			ll g = GCD(a, b);
			w[i][j] = make_pair(a/g, b/g);
			w[j][i] = make_pair(b/g, a/g);
		}
		cout<<w<<endl;
		
		int g=w[0][0].first;
		REP(i, N) g=LCM(g, w[0][i].first);
		cout<<g<<endl;
		
		VI ans(N);
		REP(i, N) ans[i] = (ll)w[0][i].second*g/w[0][i].first;
		return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"#0 and #1 as 6:4"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getMasses(Arg0)); }
	void test_case_1() { string Arr0[] = {"#0 and #1 as 9:8","#1 and #2 as 9:8"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {81, 72, 64 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getMasses(Arg0)); }
	void test_case_2() { string Arr0[] = {"#4 and #0 as 1:1", "#4 and #1 as 3:1", "#4 and #2 as 5:1", "#4 and #3 as 7:1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {105, 35, 21, 15, 105 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getMasses(Arg0)); }
	//void test_case_3() { string Arr0[] = {"#2 and #3 as 6:8", "#0 and #1 as 9:3", "#3 and #0 as 7:5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {60, 20, 63, 84 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMasses(Arg0)); }
	void test_case_3() { string Arr0[] = {
"#0 and #1 as 9:8", "#1 and #2 as 9:8", "#2 and #3 as 9:8", "#3 and #4 as 9:8", "#4 and #5 as 9:8", "#5 and #6 as 9:8", "#6 and #7 as 9:8", "#7 and #8 as 9:8", "#8 and #9 as 9:8"
//"#0 and #1 as 1:5", 
//"#5 and #4 as 4:2", 
//"#2 and #1 as 3:3", 
//"#3 and #4 as 4:2", 
//"#1 and #4 as 5:1"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {387420489, 344373768, 306110016, 272097792, 241864704, 214990848, 191102976, 169869312, 150994944, 134217728}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getMasses(Arg0)); }



// END CUT HERE

};

// BEGIN CUT HERE 

int main() {

	IngredientProportions ___test;

	___test.run_test(-1);

}

// END CUT HERE
