// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Ms. Ciel loves rabbits. She has a large special cage for her rabbits. The special cage is protected by a secret password consisting of exactly X digits. Each digit of her password is one of '0'-'9'. (It is possible that the password starts with a '0'.)

There are N friends who want to guess the password. Each friend make a guess consisting of exactly X digits. This is given in vector <string> guesses that contains N elements, where guesses[i] is the guess of the i-th friend. The friends are so lucky that after they make their guesses, Ms. Ciel tells them that each person guessed the password correctly, except for exactly one digit.

You are given the vector <string> guesses. Return the number of different passwords that have the above property (i.e., differ from each element of guesses in exactly one digit). Note that it is possible that no such password exists. In such case, return 0.

DEFINITION
Class:PasswordXGuessing
Method:howMany
Parameters:vector <string>
Returns:long long
Method signature:long long howMany(vector <string> guesses)


NOTES
-The result is guaranteed to fit in a 64-bit signed integer data type.


CONSTRAINTS
-guesses will contain between 1 and 50 elements, inclusive.
-Each element of guesses will contain between 1 and 50 characters, inclusive.
-All elements of guesses will contain the same number of characters.
-Each character of each element of guesses will be one of '0'-'9'.


EXAMPLES

0)
{"58", "47"}

Returns: 2

The two possible passwords are "57" and "48".

1)
{"539", "540", "541"}

Returns: 1

The only possible password is "549".

2)
{"12", "34", "56", "78"}

Returns: 0

There is no possible password. Ms. Ciel must have forgotten her own password.

3)
{"2", "3", "5"}

Returns: 7



4)
{"4747", "4747", "4747", "4747"}

Returns: 36



*/
// END CUT HERE
#line 69 "PasswordXGuessing.cpp"

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



class PasswordXGuessing {
	public:
	long long howMany(vector <string> G) {
		int N=G.size();
		int X=G[0].size();
		ll ans=0;
		//cout<<endl;
		REP(wr, X) {
			VI can(X*10, 1);
			REP(j, X) {
				if(j==wr) {
					can[j*10+G[0][j]-'0']=0;
				} else {
					REP(z, 10) if(z!=G[0][j]-'0') can[j*10+z]=0;
				}
			}
			//cout<<can<<endl;
			int ok=1;
			for(int i=1;i<N;i++) {
				//cout<<i<<endl;
				int x=0;
				VI w(X);
				REP(j, X) {
					if(can[j*10+G[i][j]-'0']) {
						if(j!=wr) w[j]=1;
					} else {
						x++;
						w[j]=1;
					}
				}
				//cout<<i<<endl;
				if(x>1) {ok=0;break;}
				if(x==1) {
					REP(j, X) if(w[j]==0) REP(zz, 10) if(zz!=G[i][j]-'0') can[j*10+zz]=0;
				}
				if(x==0) {
					REP(j, X) if(w[j]==0) can[j*10+G[i][j]-'0']=0;
				}
				if(!ok) break;
			}
			if(!ok) continue;
			ll lans=1;
			REP(j, X) {
				ll a=0;
				REP(z, 10) a+=can[j*10+z];
				lans *= a;
			}
			//cout<<can<<endl;
			//cout<<"+ "<<lans<<endl;
			ans += lans;
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
void verify_case(const long long& Expected, const long long& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, PasswordXGuessing().howMany(guesses));}
int main(){

CASE(0)
	string guesses_[] = {"58", "47"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	long long _ = 2LL; 
END
//return 0;
CASE(1)
	string guesses_[] = {"539", "540", "541"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	long long _ = 1LL; 
END
CASE(2)
	string guesses_[] = {"12", "34", "56", "78"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	long long _ = 0LL; 
END
CASE(3)
	string guesses_[] = {"2", "3", "5"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	long long _ = 7LL; 
END
CASE(4)
	string guesses_[] = {"4747", "4747", "4747", "4747"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	long long _ = 36LL; 
END
CASE(4)
	string guesses_[] = {"0000000000"};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	long long _ = 36LL; 
END
CASE(3)
	string guesses_[] = {
		"0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", 
		"0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", 
		"0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", 
		"0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", 
		"0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", "0000000000", 
		};
	  vector <string> guesses(guesses_, guesses_+sizeof(guesses_)/sizeof(*guesses_)); 
	long long _ = 7LL; 
END

}
// END CUT HERE

/**
00000000000000000000000000000000000000000000000000

*/
