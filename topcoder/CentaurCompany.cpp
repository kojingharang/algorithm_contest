// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// The Centaur company has N servers, numbered 1 through N.
These servers are currently connected into a network.
The topology of the network is a tree.
In other words, there are exactly N-1 bidirectional cables, each connecting some two servers in such a way that the entire network is connected.

The Centaur company is about to split into two new companies: the Human company and the Horse company.
When this happens, the companies will divide the servers randomly.
More precisely, for each of the N servers the two companies will flip a fair coin, and the winner of the coin flip gets the server.
Once they divide the servers, each company will configure their own servers not to use the cables that lead to the servers of the other company.

Of course, it may then happen that some pairs of servers that belong to the same company will not be able to communicate any more.
Therefore, each of the new companies will then use new, additional cables to connect all of its servers to the same network.
New cables can be added for free.
However, each of the servers currently only has one empty slot into which an end of a cable can be inserted.
Adding one additional empty slot to a server costs 1.
If desired, it is possible to add multiple slots to the same server.
Each of the companies will connect their servers using a way with the smallest possible cost.

You are given two vector <int>s a and b, each containing N-1 elements.
These two arrays describe the original cables:
for each i, there is a cable that connects the servers a[i] and b[i].

Compute and return the expected value of the total cost paid by the two companies to connect their networks.
(The expectation is taken over all possible ways in which they can divide the N servers.)

DEFINITION
Class:CentaurCompany
Method:getvalue
Parameters:vector <int>, vector <int>
Returns:double
Method signature:double getvalue(vector <int> a, vector <int> b)


NOTES
-N can be determined as (1 + the length of a).
-The expected value of a variable can be seen as the average value of the variable, where the average is taken over many rounds of the experiment. See http://en.wikipedia.org/wiki/Expected_value for a formal definition.
-Your return value must have a relative or absolute error of at most 1e-9.


CONSTRAINTS
-N will be between 2 and 36, inclusive.
-a and b will contain exactly N-1 elements.
-Each element of a and b will be between 1 and N, inclusive.
-The network defined by a and b will be a tree (as explained in the problem statement).


EXAMPLES

0)
{1}
{2}

Returns: 0.0

Regardless of the result of the coin flips, the companies don't need additional cables to connect their own servers. Therefore, the expected cost is zero.

1)
{1,1,1}
{2,3,4}

Returns: 0.125

If the Horse company gets only the server 1 and the Human company gets the other servers, the Human company must add one empty slot. For example, the Human company can add one empty slot to the server 2 and add new cables to connect the server 2 with the servers 3 and 4. Similarly, if the Human company gets only the server 1 and the Horse company gets the other servers, the cost will also be 1. In all other cases the cost will be 0. The expected cost is 1/(2^4) + 1/(2^4) = 1/8.

2)
{1,2,3,2,2}
{2,3,4,5,6}

Returns: 0.375

For example, if the Horse company gets only the server 2 and the Human company gets the other servers, the Human company must add one empty slot. In the picture below, initially each server has one empty slot (blue). The Human company adds one extra slot (yellow) to the server 5. The Human company also adds cables that connect the servers 1 and 5, 3 and 5, and 4 and 6.




3)
{1,2,3,4,5,6,7,8,9}
{2,3,4,5,6,7,8,9,10}

Returns: 0.41796875



4)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
{2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36}

Returns: 15.500000001076842



5)
{10, 7, 2, 5, 6, 2, 4, 9, 7}
{8, 10, 10, 4, 1, 6, 2, 2, 3}

Returns: 0.646484375



*/
// END CUT HERE
#line 106 "CentaurCompany.cpp"

#include <vector>
#include <map>
#include <set>
#include <stack>
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
#define PRINT(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


double nCr(ll n, ll r) {
	double ans = 1;
	REP(i, r) ans *= n-i;
	REP(i, r) ans /= i+1;
	return ans;
}

class CentaurCompany {
	public:
	double getvalue(vector <int> A, vector <int> B) {
		int N = A.size()+1;
		VI ed(N);
		REP(i, A.size()) ed[A[i]-1]++, ed[B[i]-1]++;
		//REP(i, N) rank[i]/=2;
		cout<<ed<<endl;
		VI rank(N);
		REP(i, N) rank[ed[i]]++;
		cout<<rank<<endl;
		VI rn;
		VI si;
		ll to = 1;
		REP(i, N) if(rank[i]) {
			rn.PB(i);
			si.PB(rank[i]+1);
			to *= rank[i]+1;
		}
		cout<<rn<<endl;
		cout<<si<<endl;
		cout<<to<<endl;
		
		double ans = 0.0;
		double all = 0;
		REP(_bit, to) {
			int bit = _bit;
			VI w(si.size());
			ll Arank=0LL;
			ll Brank=0LL;
			double fa = 1;
			REP(i, si.size()) {
				w[i] = bit%si[i];
				bit/=si[i];
				Arank += w[i] * rn[i];
				Brank += (si[i]-1-w[i]) * rn[i];
				//cout<<i<<" "<<w[i]<<" "<<(si[i]-1-w[i])<<endl;
				//cout<<si[i]-1<<" "<<w[i]<<endl;
				fa *= nCr(si[i]-1, w[i]);
			}
			ll Anodes = accumulate(ALL(w), 0LL);
			ll Bnodes = N - Anodes;
			double addA = max(0LL, 2*(Anodes-1) - Arank);
			double addB = max(0LL, 2*(Bnodes-1) - Brank);
			ans += fa * (addA + addB);
			
			cout<<bit<<" ::: "<<w<<endl;
			//cout<<Anodes<<" = "<<Arank<<endl;
			//cout<<Bnodes<<" = "<<Brank<<endl;
			cout<<fa<<endl;
			cout<<addA<<" = "<<addB<<endl;
			all += fa;
		}
		
		//cout<<"ALL "<<all<<endl;
		REP(i, N) ans *= 0.5;
		
		return ans;
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
void verify_case(const double& Expected, const double& Received) {
 double diff = Expected - Received; if (diff < 0) diff = -diff; bool ok = (diff < 1e-9);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, CentaurCompany().getvalue(a, b));}
int main(){
CASE(3)
	int a_[] = {1,2,3,4,5,6,7,8,9};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {2,3,4,5,6,7,8,9,10};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	double _ = 0.41796875; 
END
return 0;

CASE(0)
	int a_[] = {1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {2};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	double _ = 0.0; 
END
CASE(1)
	int a_[] = {1,1,1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {2,3,4};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	double _ = 0.125; 
END
//return 0;
CASE(2)
	int a_[] = {1,2,3,2,2};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {2,3,4,5,6};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	double _ = 0.375; 
END
CASE(3)
	int a_[] = {1,2,3,4,5,6,7,8,9};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {2,3,4,5,6,7,8,9,10};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	double _ = 0.41796875; 
END
CASE(4)
	int a_[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	double _ = 15.500000001076842; 
END
CASE(5)
	int a_[] = {10, 7, 2, 5, 6, 2, 4, 9, 7};
	  vector <int> a(a_, a_+sizeof(a_)/sizeof(*a_)); 
	int b_[] = {8, 10, 10, 4, 1, 6, 2, 2, 3};
	  vector <int> b(b_, b_+sizeof(b_)/sizeof(*b_)); 
	double _ = 0.646484375; 
END

}
// END CUT HERE
