// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// A standard way of ordering words in a dictionary involves comparison of two words character by character, from left to right, until some two characters disagree. Jim thinks it's pretty boring, so he introduced a more complicated and less predictable scheme.

Given is a vector <string> words that contains N distinct words and each element is a single word. The length of each word is the same -- exactly L characters. To order words according to his scheme, Jim first generates a random permutation p[0], p[1], ..., p[L-1] of integers between 0 and L-1, inclusive. This permutation is generated only once and then considered to be fixed for the rest of the procedure. Using the permutation p, Jim can compare any two words as follows:


// returns -1, if A<B, 0, if A=B, and 1, if A>B
function Compare(Word A, Word B):
	for i = 0, 1, ..., L-1:
		a := character at position p[i] (0-based) in A
		b := character at position p[i] (0-based) in B
		if (a < b), return -1
		if (b < a), return 1

	return 0


Let Sorted be the list of the given words ordered according to Compare operator defined above. In other words, Compare(Sorted[i], Sorted[j]) = -1, for any i, j, 0 <= i < j < N.

Return a vector <double> that contains N elements and i-th element of the return is the probability that Sorted[0] is the same word as words[i]. Assume that permutation p is chosen uniformly at random.

DEFINITION
Class:StrangeDictionary2
Method:getProbabilities
Parameters:vector <string>
Returns:vector <double>
Method signature:vector <double> getProbabilities(vector <string> words)


NOTES
-Each element of the return value must have an absolute or relative error of less than 1e-9.


CONSTRAINTS
-words will contain between 1 and 16 elements, inclusive.
-Each element of words will contain between 1 and 50 characters, inclusive.
-All elements of words will contain the same number of characters.
-Each character in each element of words will be a lowercase letter ('a'-'z').
-All elements of words will be distinct.


EXAMPLES

0)
{"hardesttestever"}

Returns: {1.0 }

One word will always be at position 0 regardless of the permutation p.

1)
{"ab", "ba"}

Returns: {0.5, 0.5 }

If p = {0, 1}, then "ab" < "ba". If p = {1, 0}, then "ba" < "ab".

2)
{"aza", "aab", "bba"}

Returns: {0.3333333333333333, 0.5, 0.16666666666666666 }


p		Sorted
{0,1,2}		aab, aza, bba
{0,2,1}		aza, aab, bba
{1,0,2}		aab, bba, aza
{1,2,0}		aab, bba, aza
{2,0,1}		aza, bba, aab
{2,1,0}		bba, aza, aab


3)
{"abababab", "babababa", "acacacac", "cacacaca", "bcbcbcbc", "cbcbcbcb"}

Returns: {0.5, 0.5, 0.0, 0.0, 0.0, 0.0 }



*/
// END CUT HERE
#line 85 "StrangeDictionary2.cpp"

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
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }

VI used;
VI a;
vector<double> ans;
vector <string> w;
int f(int i, double K, int rest) {
	int N=w.size();
	int L=w[0].size();
	used[i]=1;
	
	int mi = -1;
	int m = 1000;
	REP(j, N) {
		if(!a[j]) continue;
		if(w[j][i]<m) {
			m = w[j][i];
			mi = j;
		}
	}
	cout<<"min "<<(char)m<<" "<<mi<<endl;
	int cnt = 0;
	REP(j, N) {
		if(!a[j]) continue;
		if(m==w[j][i]) cnt++;
		else a[j]=0;
	}
	cout<<"f "<<i<<" "<<cnt<<endl;
	if(cnt==1) ans[mi]+=K; // +=rest!
	else {
		REP(k, L) {
			if(!used[k]) f(k, K/rest, rest-1);
		}
	}
	return 0;
}

class StrangeDictionary2 {
	public:
	vector <double> getProbabilities(vector <string> _w) {
		w=_w;
		int N=w.size();
		int L=w[0].size();
		ans = vector<double>(N);
		REP(i, L) {
			used=VI(L);
			a = VI(N, 1);
			f(i, 1.0/L, L-1);
		}
		cout<<ans<<endl;
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
void verify_case(const vector <double>& Expected, const vector <double>& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: " << Expected << endl << "\tx: " << Received << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, StrangeDictionary2().getProbabilities(words));}
int main(){

CASE(0)
	string words_[] = {"hardesttestever"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	double __[] = {1.0 };
	  vector <double> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(1)
	string words_[] = {"ab", "ba"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	double __[] = {0.5, 0.5 };
	  vector <double> _(__, __+sizeof(__)/sizeof(*__)); 
END
CASE(2)
	string words_[] = {"aza", "aab", "bba"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	double __[] = {0.3333333333333333, 0.5, 0.16666666666666666 };
	  vector <double> _(__, __+sizeof(__)/sizeof(*__)); 
END
return 0;
CASE(3)
	string words_[] = {"abababab", "babababa", "acacacac", "cacacaca", "bcbcbcbc", "cbcbcbcb"};
	  vector <string> words(words_, words_+sizeof(words_)/sizeof(*words_)); 
	double __[] = {0.5, 0.5, 0.0, 0.0, 0.0, 0.0 };
	  vector <double> _(__, __+sizeof(__)/sizeof(*__)); 
END

}
// END CUT HERE
