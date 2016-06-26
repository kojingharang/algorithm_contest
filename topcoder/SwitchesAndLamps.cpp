// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There are N switches and N lamps in Cucumberman's house. Each switch is connected to a single lamp. Different switches are connected to different lamps. Switches are numbered 0 through N-1. Lamps are also numbered 0 through N-1, but not necessarily in the same order as their corresponding switches. Switches and lamps have two states: ON and OFF. When a switch is in the ON state, the lamp connected to the switch is ON. When a switch is in the OFF state, the lamp connected to the switch is OFF.


Cucumberman decided to perform some experiments in order to figure out the connection between switches and lamps. In each experiment he first sets the states of all switches as he wants to, and then he writes down the states of all lamps.


He has already performed some experiments. You are given the results in two vector <string>s switches and lamps. If the j-th character of the i-th element of switches is 'Y', the j-th switch was ON in the i-th experiment. If the j-th character of the i-th element of switches is 'N', the j-th switch was OFF in the i-th experiment. lamps gives the information of lamps in the same format.


If the results of experiments are inconsistent, return -1. (I.e., return -1 if no way of assigning switches to lamps matches all the experiments.) Otherwise, return the minimal number of additional experiments required to figure out the connection between switches and lamps. In other words, return the smallest nonnegative integer X with the following property: It is possible to design X additional experiments in such a way that after Cucumberman executes them and tells you the results you will surely be able to match each switch to its corresponding lamp.


DEFINITION
Class:SwitchesAndLamps
Method:theMin
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int theMin(vector <string> switches, vector <string> lamps)


CONSTRAINTS
-switches will contain between 1 and 50 elements, inclusive.
-Each element of switches will contain between 1 and 50 characters, inclusive.
-Each element of switches will contain the same number of characters.
-lamps will contain the same number of elements as switches.
-Each element of lamps will contain the same number of characters, and it will be equal to the number of characters of elements in switches.
-Each character in switches and lamps will be 'Y' or 'N'.
-For each i, the number of 'Y' in switches[i] and the number of 'Y' in lamps[i] will be equal.


EXAMPLES

0)
{"NYNN", "NNYN"}
{"NNNY", "NNYN"}

Returns: 1

He can figure out that switch 1 is connected to lamp 3 and switch 2 is connected to lamp 2. He needs one more experiment to figure out which of the switches 0 and 3 is connected to lamp 0.

1)
{"YYN", "YNY", "YYN"}
{"YNY", "NYY", "YNY"}

Returns: 0

He can figure out that switch 0 is connected to lamp 2, switch 1 is connected to lamp 0, and switch 2 is connected to lamp 1. No additional experiments are necessary.


2)
{"NYYYNYNNYYYNYNNNNY", "NYYYNYNNYYYNYNNNNY"}
{"YYYNNNYNNYNYNYNYNY", "YYYNNNYNNYNYYNNYNY"}

Returns: -1

The same experiment cannot give different results when executed twice.

3)
{"YYNNN", "NNYYN"}
{"NYNNY", "NNNYY"}

Returns: -1



4)
{"YNNYNNYNYY", "NYNNYNYNYN", "YNYNYYYYYN", "NNYYNYNYNN"}
{"NYYNYNNYNY", "NYYYNNYNNN", "YYYYNYNNYY", "YNNNNYNYYN"}

Returns: 2



*/
// END CUT HERE
#line 80 "SwitchesAndLamps.cpp"

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

#define EPS 1e-12
#define ll long long
#define VI vector<int>
#define PII pair<int, int> 
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T> v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


int f(VVI& can, int N) {
	REP(lo, N)
	{
		REP(i, N) {
			int co2 = 0;
			int idx2=0;
			REP(j, N) if(can[j][i]){idx2=j; co2++;}
			if(co2==0) return -1;
			if(co2==1) {
				REP(k, N) if(k!=i) can[idx2][k]=0;
			}
			
			int co = accumulate(ALL(can[i]), 0);
			if(co==0) return -1;
			if(co==1) {
				REP(j, N) if(can[i][j]) REP(k, N) if(k!=i) can[k][j]=0;
			}
		}
	}
	return 0;
}

class SwitchesAndLamps {
	public:
	int theMin(vector <string> SW, vector <string> LA) {
		int N=SW[0].size();
		VVI can(N, VI(N, 1));
		REP(i, SW.size()) {
			REP(j, N) {
				REP(k, N) {
					if(SW[i][j]!=LA[i][k]) can[j][k]=0;
				}
			}
		}
		//cout<<can<<endl;
		int ans=0;
		map<VI, int> hi;
		if(-1==f(can, N)) return -1;
		cout<<ans<<endl;
		cout<<can<<endl;
		REP(i, N) {
			hi[can[i]]++;
		}
		FOR(e, hi) ans=max(ans, e->second);
		REP(i, 100) if(1<<i >= ans) return i;
		//cout<<can<<endl;
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
#define END	 verify_case(_, SwitchesAndLamps().theMin(switches, lamps));}
int main(){

CASE(0)
	string switches_[] = {"NYNN", "NNYN"};
	  vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
	string lamps_[] = {"NNNY", "NNYN"};
	  vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
	int _ = 1; 
END
CASE(1)
	string switches_[] = {"YYN", "YNY", "YYN"};
	  vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
	string lamps_[] = {"YNY", "NYY", "YNY"};
	  vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
	int _ = 0; 
END
CASE(2)
	string switches_[] = {"NYYYNYNNYYYNYNNNNY", "NYYYNYNNYYYNYNNNNY"};
	  vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
	string lamps_[] = {"YYYNNNYNNYNYNYNYNY", "YYYNNNYNNYNYYNNYNY"};
	  vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
	int _ = -1; 
END
CASE(3)
	string switches_[] = {"YYNNN", "NNYYN"};
	  vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
	string lamps_[] = {"NYNNY", "NNNYY"};
	  vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
	int _ = -1; 
END
CASE(4)
	string switches_[] = {"YNNYNNYNYY", "NYNNYNYNYN", "YNYNYYYYYN", "NNYYNYNYNN"};
	  vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
	string lamps_[] = {"NYYNYNNYNY", "NYYYNNYNNN", "YYYYNYNNYY", "YNNNNYNYYN"};
	  vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
	int _ = 2; 
END
CASE(4)
	string switches_[] = {"NNN", };
	  vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
	string lamps_[] = {"NNN",};
	  vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
	int _ = 2; 
END
CASE(4)
	string switches_[] = {"N", };
	  vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
	string lamps_[] = {"N",};
	  vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
	int _ = 0; 
END
CASE(4)
	string switches_[] = {"YYNN", "NYYN", "NNYY", };
	  vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
	string lamps_[] = {"YYNN", "NYYN", "NNYY"};
	  vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
	int _ = 0; 
END
CASE(4)
	string switches_[] = {"YYYY", };
	  vector <string> switches(switches_, switches_+sizeof(switches_)/sizeof(*switches_)); 
	string lamps_[] = {"YYYY",};
	  vector <string> lamps(lamps_, lamps_+sizeof(lamps_)/sizeof(*lamps_)); 
	int _ = 0; 
END

}
// END CUT HERE
