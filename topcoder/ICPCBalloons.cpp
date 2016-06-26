// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// You are organizing a subregional ACM ICPC contest. The problemset at the contest will consist of M problems. According to an ACM ICPC tradition, when a team solves a problem, it gets awarded a balloon. To account for this, you've bought balloons of N different colors (conveniently numbered from 0 to N-1). The number of balloons of color i that you've bought is given by balloonCount[i]. Balloons come in two sizes: medium and large. All balloons of the same color have the same size. If the i-th character of balloonSize is 'M', then all balloons of color i have medium size, and if this character is 'L', then all balloons of color i have large size.

Today you've been at the meeting with the scientific committee of the contest. There, you learned that there are additional restrictions of which you were not aware. Here are those restrictions:

All balloons that get awarded for a particular problem must have the same color and size.
For any two problems, the colors of balloons awarded for solving them must be different. In other words, the color of balloons awarded for each problem must be unique.

These are definitely bad news, since you ordered balloons pretty much arbitrarily and it's possible that you won't be able to satisfy the restrictions with the balloons you currently have. However, the good news is that scientific committee members were able to evaluate the difficulty of each problem. More exactly, they told you that the maximum number of teams that can potentially solve the i-th problem is maxAccepted[i]. The scientific committee members are very clever and experienced, so their prediction is guaranteed to come true.

Your budget is limited and balloons are expensive, so buying more of them is not an option. Fortunately, there is a very cheap balloon repaint service at your city, so you are going to use it. The service offers repainting a given balloon into any other color. This can be one of the N colors you have, as well as any color that you don't have yet. However, it is not possible to change the size of a balloon.

You are given the vector <int>s balloonCount, maxAccepted and the string balloonSize. Return the minimum number of balloons that have to be repainted in order to guarantee that you will be able to award balloons to the teams properly. If it is impossible to achieve the goal using any number of balloon repaintings, return -1.

DEFINITION
Class:ICPCBalloons
Method:minRepaintings
Parameters:vector <int>, string, vector <int>
Returns:int
Method signature:int minRepaintings(vector <int> balloonCount, string balloonSize, vector <int> maxAccepted)


CONSTRAINTS
-balloonCount will contain between 1 and 50 elements, inclusive.
-Each element of balloonCount will be between 1 and 100, inclusive.
-balloonSize will contain the same number of characters as the number of elements in balloonCount.
-Each character of balloonSize will be 'M' or 'L'.
-maxAccepted will contain between 1 and 15 elements, inclusive.
-Each element of maxAccepted will be between 1 and 100, inclusive.


EXAMPLES

0)
{100}
"L"
{1,2,3,4,5}

Returns: 10

You have 100 large balloons of the same color. 5 of them can be used for problem 4 and 1+2+3+4=10 balloons need to be repainted in order to be used for remaining problems.

1)
{100}
"M"
{10,20,30,40,50}

Returns: -1

We don't have enough balloons. Repainting is not going to help.

2)
{5,6,1,5,6,1,5,6,1}
"MLMMLMMLM"
{7,7,4,4,7,7}

Returns: 6

(Note that all of the indices in this annotation are 0-based.)

Repaint one balloon of color 7 into color 1. Repaint one balloon of color 7 into color 4. Now large balloons can be awarded for problems 0, 1, and 2.

Repaint two balloons of colors 2 and 5 into color 0. Repaint two balloons of colors 6 and 8 into color 3. Now medium balloons of colors 0, 3, and 6 can be awarded for problems 3, 4, and 5.

3)
{100,100}
"ML"
{50,51,51}

Returns: -1

Even though we have 200 balloons overall and only at most 152 accepted solutions, there is still no way of dividing and repainting the balloons that works.

4)
{8,5,1,4,1,1,3,1,3,3,5,4,5,6,9}
"MMMLLLMMLLMLMLM"
{3,5,3,3,5,6,4,6,4,2,3,7,1,5,2}

Returns: 5



5)
{1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9}
"LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL"
{44,59,29,53,16,23,13,14,29,42,13,15,66,4,47}

Returns: 210



*/
// END CUT HERE
#line 97 "ICPCBalloons.cpp"

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
#define VI vector<int>
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



class ICPCBalloons {
	public:
	int f(VI& bs, VI& s) {
		int mar=0;
		int lack=0;
		REP(i, max(bs.size(), s.size())) {
			if(i>=bs.size()) {
				lack+=s[i];
			}else
			if(i>=s.size()) {
				mar+=bs[i];
			}else {
				mar+=max(0, bs[i]-s[i]);
				lack+=max(0, s[i]-bs[i]);
			}
		}
		if(mar<lack) return -1;
		
		return lack;
	}
	int minRepaintings(vector <int> BC, string BS, vector <int> MA) {
		VI bls, bms;
		int N = BC.size();
		REP(i, N) {
			if(BS[i]=='L') bls.PB(BC[i]);
			else           bms.PB(BC[i]);
		}
		sort(ALLR(bls));
		sort(ALLR(bms));
		//cout<<bls<<endl;
		//cout<<bms<<endl;
		
		int ans = 100000;
		int M = MA.size();
		REP(bit, 1<<M) {
			//cout<<bit<<endl;
			VI Bls(bls);
			VI Bms(bms);
			VI ls, ms;
			REP(i, M) {
				if((bit>>i)&1) {
					ls.PB(MA[i]);
				} else {
					ms.PB(MA[i]);
				}
			}
			sort(ALLR(ls));
			sort(ALLR(ms));
			//cout<<"ls: "<<ls<<endl;
			//cout<<"ms: "<<ms<<endl;
			int cl= f(Bls, ls);
			//cout<<"L "<<bls<<" "<<ls<<" "<<cl<<endl;
			int cm= f(Bms, ms);
			//cout<<"M "<<bms<<" "<<ms<<" "<<cm<<endl;
			if(cl!=-1 && cm!=-1) ans=min(ans, cl+cm);
		}
		return ans==100000 ? -1 : ans;
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
#define END	 verify_case(_, ICPCBalloons().minRepaintings(balloonCount, balloonSize, maxAccepted));}
int main(){

CASE(0)
	int balloonCount_[] = {100};
	  vector <int> balloonCount(balloonCount_, balloonCount_+sizeof(balloonCount_)/sizeof(*balloonCount_)); 
	string balloonSize = "L"; 
	int maxAccepted_[] = {1,2,3,4,5};
	  vector <int> maxAccepted(maxAccepted_, maxAccepted_+sizeof(maxAccepted_)/sizeof(*maxAccepted_)); 
	int _ = 10; 
END
CASE(1)
	int balloonCount_[] = {100};
	  vector <int> balloonCount(balloonCount_, balloonCount_+sizeof(balloonCount_)/sizeof(*balloonCount_)); 
	string balloonSize = "M"; 
	int maxAccepted_[] = {10,20,30,40,50};
	  vector <int> maxAccepted(maxAccepted_, maxAccepted_+sizeof(maxAccepted_)/sizeof(*maxAccepted_)); 
	int _ = -1; 
END
//return 0;
CASE(2)
	int balloonCount_[] = {5,6,1,5,6,1,5,6,1};
	  vector <int> balloonCount(balloonCount_, balloonCount_+sizeof(balloonCount_)/sizeof(*balloonCount_)); 
	string balloonSize = "MLMMLMMLM"; 
	int maxAccepted_[] = {7,7,4,4,7,7};
	  vector <int> maxAccepted(maxAccepted_, maxAccepted_+sizeof(maxAccepted_)/sizeof(*maxAccepted_)); 
	int _ = 6; 
END
CASE(3)
	int balloonCount_[] = {100,100};
	  vector <int> balloonCount(balloonCount_, balloonCount_+sizeof(balloonCount_)/sizeof(*balloonCount_)); 
	string balloonSize = "ML"; 
	int maxAccepted_[] = {50,51,51};
	  vector <int> maxAccepted(maxAccepted_, maxAccepted_+sizeof(maxAccepted_)/sizeof(*maxAccepted_)); 
	int _ = -1; 
END
CASE(4)
	int balloonCount_[] = {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9};
	  vector <int> balloonCount(balloonCount_, balloonCount_+sizeof(balloonCount_)/sizeof(*balloonCount_)); 
	string balloonSize = "MMMLLLMMLLMLMLM"; 
	int maxAccepted_[] = {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2};
	  vector <int> maxAccepted(maxAccepted_, maxAccepted_+sizeof(maxAccepted_)/sizeof(*maxAccepted_)); 
	int _ = 5; 
END
CASE(5)
	int balloonCount_[] = {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9};
	  vector <int> balloonCount(balloonCount_, balloonCount_+sizeof(balloonCount_)/sizeof(*balloonCount_)); 
	string balloonSize = "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL"; 
	int maxAccepted_[] = {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47};
	  vector <int> maxAccepted(maxAccepted_, maxAccepted_+sizeof(maxAccepted_)/sizeof(*maxAccepted_)); 
	int _ = 210; 
END
CASE(3)
	int balloonCount_[] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,};
	  vector <int> balloonCount(balloonCount_, balloonCount_+sizeof(balloonCount_)/sizeof(*balloonCount_)); 
	string balloonSize = "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMLLLLL"; 
	int maxAccepted_[] = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,};
	  vector <int> maxAccepted(maxAccepted_, maxAccepted_+sizeof(maxAccepted_)/sizeof(*maxAccepted_)); 
	int _ = -1; 
END
CASE(0)
	int balloonCount_[] = {10,100};
	  vector <int> balloonCount(balloonCount_, balloonCount_+sizeof(balloonCount_)/sizeof(*balloonCount_)); 
	string balloonSize = "ML"; 
	int maxAccepted_[] = {1,2,3,4,5};
	  vector <int> maxAccepted(maxAccepted_, maxAccepted_+sizeof(maxAccepted_)/sizeof(*maxAccepted_)); 
	int _ = 10; 
END

}
// END CUT HERE
