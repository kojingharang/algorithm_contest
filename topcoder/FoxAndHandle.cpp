// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// We say that a string Z can be obtained by shuffling two strings X and Y together, if it is possible to interleave the letters of X and Y so that Z is obtained. It is not allowed to change the order of letters in X and Y.
For example, you can shuffle the strings X="abcd" and Y="efg" to produce any of the strings "abcdefg", "aebfcgd", "abcefgd", or "eabcfdg", but you cannot produce the string "bacdefg".



Formally, let Shuffle(X,Y) be the set of all strings that can be produced by shuffling X and Y together.
We can define Shuffle inductively as follows:

for any string X: Shuffle("",X) = Shuffle(X,"") = { X }
for any letters a, b and any strings X, Y:
Shuffle(aX,bY) = { aZ : Z belongs to Shuffle(X,bY) } united with { bZ : Z belongs to Shuffle(aX,Y) }.




Fox Ciel wants to register on TopCoder.
In order to do that, she has to pick a handle.
Ciel has a pet cat called S.
As her handle, Ciel wants to use a string H with the following property:
S can be obtained by shuffling H and some permutation of H together.
For example, if S="ceiiclel", one possible handle would be H="ciel":
she can permute H to obtain H'="eicl", and then shuffle these H and H' together to produce S.



You are given the string S.
The constraints guarantee that there is at least one possible handle H with the above property.
Find and return the lexicographically smallest valid H.

DEFINITION
Class:FoxAndHandle
Method:lexSmallestName
Parameters:string
Returns:string
Method signature:string lexSmallestName(string S)


CONSTRAINTS
-S will contain between 2 and 50 characters, inclusive.
-Each character of S will be a lowercase letter ('a'-'z').
-Each letter ('a'-'z') will occur in S an even number of times.


EXAMPLES

0)
"foxfox"

Returns: "fox"

There are five possible handles for Fox Ciel in this test case: "fox", "fxo", "ofx", "oxf", and "xfo".
The lexicographically smallest one is "fox".

1)
"ccieliel"

Returns: "ceil"

Note that "ciel" is also a valid handle, but "ceil" is lexicographically smaller.

2)
"abaabbab"

Returns: "aabb"



3)
"bbbbaaaa"

Returns: "bbaa"



4)
"fedcbafedcba"

Returns: "afedcb"



5)
"nodevillivedon"

Returns: "deilvon"



*/
// END CUT HERE
#line 95 "FoxAndHandle.cpp"

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



class FoxAndHandle {
	public:
	string lexSmallestName(string S) {
		int N=S.size();
		VVI hi(N+1, VI(256));
		REP(i, N) {
			hi[N-1-i] = hi[N-1-i +1];
			hi[N-1-i][S[N-1-i]]++;
		}
		string Hs;
		{
			VI w(256);
			REP(i, N) w[S[i]]++;
			REP(i, 256) {
				while(w[i]) {
					Hs.PB((char)i);
					w[i]-=2;
				}
			}
		}
		string H;
		int Si = 0;
		while(Hs.size()) {
			VI lhi(256);
			REP(j, Hs.size()) lhi[Hs[j]]++;
			
			REP(k, Hs.size()) {
				int idx=0;
				RANGE(i, Si, N) if(S[i]==Hs[k]) {idx=i;break;}
				
				int ok=1;
				REP(j, 256) if(hi[idx][j]<lhi[j]) ok=0;
				
				if(ok) {
					//cout<<"OK "<<Hs[k]<<endl;
					H.PB(Hs[k]);
					string nHs;
					int removed=0;
					REP(z, Hs.size()) {
						if(!removed && Hs[k]==Hs[z]) removed=1;
						else nHs.PB(Hs[z]);
					}
					Hs=nHs;
					Si=idx+1;
					break;
				}
			}
		}
		return H;
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
void verify_case(const string& Expected, const string& Received) {
 bool ok = (Expected == Received);
 if(ok) cerr << "PASSED" << timer() << endl;  else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, FoxAndHandle().lexSmallestName(S));}
int main(){
CASE(5)
	string S = "bkbkaajaajkkmfmfliffajaelhihlihajaeohggholihoggo"; 
	string _ = "baaaajkkfmfehhlihjgglioo"; 
END
//return 0;
CASE(0)
	string S = "foxfox"; 
	string _ = "fox"; 
END
//return 0;
CASE(1)
	string S = "ccieliel"; 
	string _ = "ceil"; 
END
CASE(2)
	string S = "abaabbab"; 
	string _ = "aabb"; 
END
CASE(3)
	string S = "bbbbaaaa"; 
	string _ = "bbaa"; 
END
CASE(4)
	string S = "fedcbafedcba"; 
	string _ = "afedcb"; 
END
CASE(5)
	string S = "nodevillivedon"; 
	string _ = "deilvon"; 
END
CASE(5)
	string S = "zzyyxxwwvvuuttssrrqqppoonnmmllkkjjiihhggffeeddccbb"; 
	string _ = "zyxwvutsrqponmlkjihgfedcb"; 
END





}
// END CUT HERE
