// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// In a normal election, one expects the percentages received by each of the candidates to sum to exactly 100 percent.  There are two ways this might not be the case: if the election is fraudulent, or if the reported percentages are rounded.
For example, in an election with 3 voters and 3 candidates, if each voter chooses a different candidate the final percentages would be reported as 33, 33, 33, which only sum to 99.  Conversely, in an election with 7 voters and 3 candidates, if the candidates receive 2, 2, and 3 votes, respectively, the final percentages would be reported as 29, 29, and 43, which sum to 101.
The ministry of voting wants you to help them determine if an election was run fairly or not.  You'll be given a vector <int> percentages, giving the percentage of the vote that went to each candidate, rounded to the nearest whole number (in the case a number lies halfway between 2 consecutive integers, it will be rounded up).  If the election could be legitimate, return the minimum number of voters that could have participated in this election.  If the election is definitely fraudulent, return -1.

DEFINITION
Class:ElectionFraudDiv1
Method:MinimumVoters
Parameters:vector <int>
Returns:int
Method signature:int MinimumVoters(vector <int> percentages)


NOTES
-You may assume that whenever the election may be legitimate, the smallest possible number of voters will fit into a int.


CONSTRAINTS
-percentages will contain between 1 and 50 elements, inclusive.
-Each element of percentages will be between 0 and 100, inclusive.


EXAMPLES

0)
{33, 33, 33}

Returns: 3

The first example from the problem statement.

1)
{29, 29, 43}

Returns: 7

The second example from the problem statement.

2)
{12, 12, 12, 12, 12, 12, 12, 12}

Returns: -1

These results are impossible.

3)
{13, 13, 13, 13, 13, 13, 13, 13}

Returns: 8



4)
{0, 1, 100}

Returns: 200

The only possibility is that the candidates received 0, 1, and 199 votes, respectively.

5)
{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4}

Returns: 97



*/
// END CUT HERE
#line 72 "ElectionFraudDiv1.cpp"

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


int f(int A, int B) {
	return (int)((double)A/B+0.5);
}

class ElectionFraudDiv1 {
	public:
	int MinimumVoters(vector <int> P) {
		int N=P.size();
		for(int A=1;A<5000;A++) {
			int sum = 0;
			int ok=1;
			//cout<<"A="<<A<<endl;
			REP(i, N) {
				int voted = A*P[i]/100 -2;
				int lok=0;
				//cout<<voted<<endl;
				REP(j, 10) {
					//cout<<"  "<<j<<" "<<(double)(voted+j)*100/A<<"  "<<f((voted+j)*100, A)<<endl;
					if( voted+j>=0 && f((voted+j)*100, A)==P[i]) {
						//cout<<voted+j<<endl;
						sum+=voted+j;
						lok=1;
						break;
					}
				}
				if(!lok) {
					ok=0;break;
				}
			}
			if(ok) {
				//cout<<"total "<<A<<" "<<sum<<endl;
				if(A==sum) {
					return A;
				}
			}
		}
		return -1;
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
#define END	 verify_case(_, ElectionFraudDiv1().MinimumVoters(percentages));}
int main(){

CASE(0)
	int percentages_[] = {33, 33, 33};
	  vector <int> percentages(percentages_, percentages_+sizeof(percentages_)/sizeof(*percentages_)); 
	int _ = 3; 
END
CASE(1)
	int percentages_[] = {29, 29, 43};
	  vector <int> percentages(percentages_, percentages_+sizeof(percentages_)/sizeof(*percentages_)); 
	int _ = 7; 
END
//return 0;
CASE(2)
	int percentages_[] = {12, 12, 12, 12, 12, 12, 12, 12};
	  vector <int> percentages(percentages_, percentages_+sizeof(percentages_)/sizeof(*percentages_)); 
	int _ = -1; 
END
CASE(3)
	int percentages_[] = {13, 13, 13, 13, 13, 13, 13, 13};
	  vector <int> percentages(percentages_, percentages_+sizeof(percentages_)/sizeof(*percentages_)); 
	int _ = 8; 
END
CASE(4)
	int percentages_[] = {0, 1, 100};
	  vector <int> percentages(percentages_, percentages_+sizeof(percentages_)/sizeof(*percentages_)); 
	int _ = 200; 
END
CASE(5)
	int percentages_[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4};
	  vector <int> percentages(percentages_, percentages_+sizeof(percentages_)/sizeof(*percentages_)); 
	int _ = 97; 
END

}
// END CUT HERE
