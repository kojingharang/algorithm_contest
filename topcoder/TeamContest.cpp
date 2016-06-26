// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Your university is holding a programming competition and your team is going to compete.

There are 3*N students in the university. They are numbered from 0 to 3*N-1. Each student has a certain strength which is a positive integer that characterizes his/her programming skills. You are given a vector <int> strength. The strength of student i is equal to strength[i].

Your team will consist of students 0, 1 and 2. Other 3*N-3 students will form N-1 more teams so that each team has exactly 3 members. The exact composition of other teams is not known yet. Each team has a strength that is calculated as follows: if it consists of members with strengths X, Y and Z, then the team's strength is equal to max{X, Y, Z} + min{X, Y, Z}.

You are interested how your team will rank by strength among the other teams. Formally, the rank of your team is defined as 1 + (the number of other teams that have a strictly greater strength than the strength of your team).

Return the maximum possible rank that your team may have after all students split into teams.

DEFINITION
Class:TeamContest
Method:worstRank
Parameters:vector <int>
Returns:int
Method signature:int worstRank(vector <int> strength)


CONSTRAINTS
-strength will contain between 3 and 48 elements, inclusive.
-The number of elements in strength will be divisible by 3.
-Each element of strength will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{5, 7, 3, 5, 7, 3, 5, 7, 3}

Returns: 2

The strength of your team is max{5, 7, 3} + min{5, 7, 3} = 10. It is possible that one of the other teams will be stronger than your team. For example, if it consists of students with strengths 5, 7 and 7, then its strength will be 12. However, it is not possible that both other teams will be stronger than your team.


1)
{5, 7, 3}


Returns: 1

Just your team. No rivals.

2)
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

Returns: 1

All teams (including yours) will have the same strength: 2.

3)
{3,9,4,6,2,6,1,6,9,1,4,1,3,8,5}


Returns: 3



4)
{53,47,88,79,99,75,28,54,65,14,22,13,11,31,43}


Returns: 3



*/
// END CUT HERE
#line 72 "TeamContest.cpp"

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



class TeamContest {
	public:
	int worstRank(vector <int> S) {
		sort(&S[0], &S[3]);
		int ref = S[0]+S[2];
		vector<int> SS(&S[3], &S[S.size()]);
		sort(ALLR(SS));
		//cout<<SS<<endl;
		int ans=1;
		int N = SS.size();
		VI w(N);
		REP(i, N) {
			w[i]=1;
			REP(j, N) {
				int jj=N-1-j;
				if(w[jj]) continue;
				if(!(i+1<jj)) continue;
				if(SS[i]+SS[jj]>ref) {
					//cout<<i<<" "<<jj<<endl;
					w[jj]=w[jj-1]=1;
					ans++;
					break;
				}
			}
		}
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
void verify_case(const int& Expected, const int& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, TeamContest().worstRank(strength));}
int main(){

CASE(0)
	int strength_[] = {5, 7, 3, 5, 7, 3, 5, 7, 3};
	  vector <int> strength(strength_, strength_+sizeof(strength_)/sizeof(*strength_)); 
	int _ = 2; 
END
CASE(1)
	int strength_[] = {5, 7, 3}
;
	  vector <int> strength(strength_, strength_+sizeof(strength_)/sizeof(*strength_)); 
	int _ = 1; 
END
CASE(2)
	int strength_[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	  vector <int> strength(strength_, strength_+sizeof(strength_)/sizeof(*strength_)); 
	int _ = 1; 
END
CASE(3)
	int strength_[] = {3,9,4,6,2,6,1,6,9,1,4,1,3,8,5}
;
	  vector <int> strength(strength_, strength_+sizeof(strength_)/sizeof(*strength_)); 
	int _ = 3; 
END
CASE(4)
	int strength_[] = {53,47,88,79,99,75,28,54,65,14,22,13,11,31,43}
;
	  vector <int> strength(strength_, strength_+sizeof(strength_)/sizeof(*strength_)); 
	int _ = 3; 
END

}
// END CUT HERE
