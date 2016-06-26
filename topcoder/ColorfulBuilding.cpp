// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// There are N skyscrapers standing in a line from left to right.
The buildings are numbered 1 through N, in some order (not necessarily from left to right).
You do not know this order.
For each i, the height of building i is i.
Thus, the heights of the N buildings form a permutation of 1 through N.

Each of the buildings is painted using a single color.
Multiple buildings may share the same color.
For each i, you know the color of building i.
(The technical details are specified below.)

You are standing far to the left of all the buildings.
From your location, you can only see parts of some buildings, because smaller buildings farther from you are obscured by taller ones that are closer.
Formally, you can see (some top part of) building X if and only if all of the buildings in front of X (that is, to the left of X in the row) are lower than building X.

Additionally, from where you are standing you cannot distinguish between two buildings that have the same color.
More precisely, whenever you see two buildings with heights H1 and H2 (H1 < H2) such that they both have the same color and you can see no building that stands between them, they seem to you as one building.
This also naturally extends to more than two buildings of the same color.

You think you now see L buildings.
In other words, as you look at the buildings from where you are standing, you see exactly L-1 places where the color changes.

You are given vector <string>s color1 and color2, and the int L.
The vector <string>s color1 and color2 can be used to determine the colors of buildings in the following way:
Concatenate all elements of color1 to obtain a string C1.
Concatenate all elements of color2 to obtain a string C2.
The strings C1 and C2 will each have exactly N characters.
Now, for each i and j: buildings i and j have the same color if and only if both C1[i-1]=C1[j-1] and C2[i-1]=C2[j-1].
In other words, for each i the color of building i is described by the two-character string C1[i-1] + C2[i-1].

Given this information, compute and return the number of possible orders of the N buildings, modulo 1,000,000,009.

DEFINITION
Class:ColorfulBuilding
Method:count
Parameters:vector <string>, vector <string>, int
Returns:int
Method signature:int count(vector <string> color1, vector <string> color2, int L)


CONSTRAINTS
-color1 and color2 will each contain between 1 and 36 elements, inclusive.
-color1 and color2 will contain the same number of elements.
-Each element of color1 and color2 will contain between 1 and 36 characters, inclusive.
-For each i, the i-th elements of color1 and color2 will contain the same number of characters.
-Each character of each element of color1 and color2 will be a lowercase or an uppercase letter ('a'-'z' or 'A'-'Z').
-L will be between 1 and N, where N is the total number of characters in color1.


EXAMPLES

0)
{"aaba"}
{"aaaa"}
3

Returns: 6

There are 4 buildings.
Buildings 1, 2, and 4 share the same color, building 3 is different.

There are 6 valid orders of buildings (from left to right):

1, 2, 3, 4
1, 3, 2, 4
1, 3, 4, 2
2, 1, 3, 4
2, 3, 1, 4
2, 3, 4, 1

Note that if the buildings stand in the order 1, 2, 3, 4, you can see all four buildings.
However, as buildings 1 and 2 have the same color, you regard them as one building.
Therefore, you think you see 3 buildings.

1)
{"aaba"}
{"aaba"}
4

Returns: 0

For each possible order of these buildings you will think you see at most 3 buildings.

2)
{"ab", "ba", "a", "aab"}
{"bb", "ba", "a", "aba"}
5

Returns: 432

Make sure to concatenate all the elements of color1 and color2.


3)
{"xxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxx"}
{"xxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxx"}
58

Returns: 619787617



4)
{"SJXcabKTWeUXhwxGixFepQaQlFxrAedNAtVP",
 "gorBIkcTlOFbLDbFeElYAyAqszQdMbpxSRdE",
 "SQVHPehlNtesbJDflyGxMqvgzjXisRnqDcQO",
 "pIAEBwbmpPWCooQAujbGXFGLvXxTmExLARkf",
 "AFnWyWKVObfxDGCjTxdZaObgwdxlPKtIxaAd",
 "uznMpJVNjAofbHJjOrZeSHgSagOCUMGbvkVR",
 "LBRrDbTAyKfVnedKiRfzgRzECpcsziqaTwdo",
 "JrJHvsEVVGDkNVGqLbpxyLDPloBuNDQKnReI",
 "SSYpbjKHSCnQhuyYrVauWDHDyhAoGyecrZMv",
 "UdetQfWEUWHHuAxRSdkJOOJSixKpQXpCFZHO",
 "KXVsQbuQtIgsULOMsTvPFNUqkBldMTLCipYK",
 "hoXConjnDWQkZVtyZlwSedvdVrNWqQhGUClQ",
 "TpsvvyoXsXmQpBAGGVDrXCkodoRHQZmpoQDW",
 "csiJspzTqeFBRmPgeEtTAzfrfCGlTZqcPuyO",
 "vsPDVBJVaJmUAtDdcsKoUkPEbDmAwtZKwjjP",
 "MOfoMhMiKIvGQoeIJXHzyClWRtRuKXMqxUAF",
 "KyyUCkRBjsYvmPFFEGBqqVhIUdtvIyyLacfu",
 "BfuwfSajSlcuTzhMufHSQLudvGEGlyHsEmBD",
 "PLpIXZkdyXveTMfSvqnDGKWOZrTBMUIlZrqF",
 "dzVMCqrSLbanRJTYpDJNHAOLPSzmvSEPQJYm",
 "rAjRkrSjouJyFaCSPPLYSzqDmMoADyWAbobJ",
 "eOCBrJNoyFnGpXpxiExXcoOHnVsaEPXhPfLe",
 "XMjRksnxWssPEINhdhbiLBSYpCLtwNshFjXS",
 "HnnDeUAbuswsgsYQuAaXySLkFYUwFXwYTreM",
 "uqLnwOEGbwZZDgAAWEdLRZxFlogDmlhjhgHM",
 "NcfaQsgPQfirkYDRFrLQpySmBGfRHumKULZf",
 "mOpmmgclsxRzXskEywfryqCRyATNoJwnlHiD",
 "AnoKoKAjrasttjNlHCROnvTJMhEHlVPVoVMo",
 "yegLyIuRkkENFAjwzDoPLKjgUHHEkfzYDIpo",
 "EcxRGGfuaBXUFXkSxctJWOLmmVbvoMkWtTvV",
 "nBMkOBHgaltEVzfyGxseGhmBscfGIbxFbqRn",
 "GvkEcLtqdOofGtsbWDafVMbNdJxsffKDzSiR",
 "jhZQUVzTzalrZcebvyqPWtOUUyniBKTWdyLi",
 "ODJLQPMdjDdTlxrfGsNmBfeGYjzeXApqKDhJ",
 "vlJkWMzdVQujKdLViQClOrJXMTBkuZEasFgg",
 "FAsbuzrLVIgaryqXBfuBRAbReleXSSgEKSvt"}
{"XAhlUHtfjOpOlQlowWppQcodMGUiqoLobxnD",
 "IDzGlKrHiVGdBjZxIcoxjwagbWieKvUwZrjg",
 "SkpkTVeIFeoNQzUUgmYAYskKONNZdgXxSiWd",
 "rXBGhTmqnvxkmqiutoDzPusDiOUggEFXGCzm",
 "fzrxVuTbFXunGbeEavjshmrIRlDorTuISCxn",
 "LsvIaxTkOBjcskiekmrKNNFEXqnfMNXLWqqu",
 "ekzxGIlbJPVEQPYAbTuMtZKsCiubDXDiBVzU",
 "hZuOCJxvBOYENGSFcUiKKAKfCdebutVmnyvB",
 "UveNkKRQmHnedrROQOpHJfrHjwcNLUShlDbn",
 "ptUkvbaGDryHRkYfHKLkSgVpjWCEcgazyxGK",
 "nVPYEqTTJsRPjzjfdOiULhnZPFeNcnbXaQlk",
 "IPXBXRhMQIkxpygsgbcRfMuvIcuzUPPHGOWX",
 "yWWlNyEyqZSIOXBFAybIuFpVqpvmKRaRFrAE",
 "EvBJVtHvKhjrFcmtpdBbFTdTVtXXZQKAglKT",
 "bCVjHzUvyINFkxXageZQMzCyNhcifACdJVDh",
 "lZITYcDSeIbLweyFtoMAfOQyBNupKlhcNpgo",
 "BduslNrJdWOUukYFFidEkMFaghfofpxVgvJd",
 "YrJpDZKqdjEPzdLsOQEdkcrBfNHPemXHokCW",
 "GjeUKSGjDlgKTyUGNrMQbBLxRUcgrWpkAwOD",
 "wgxTcswqdJHaDugNIRMvrhBsdDaJAssVbSRW",
 "qmVmqFEpvgGioMXDSFqEoQcDOAaUoGPEovSO",
 "KrukPlpfOhawaovCfteTSCIdLMrtImVtiMyQ",
 "ykwmxHsKMFzFHwcbyyedLvhZPnaNGqJMMCxd",
 "HUNYCXjNLQIFCLLGpCXHBCHLTxLynBxnHFbx",
 "uwjzbNbJepVFgMPUXVirxYHzExquBEtPmKju",
 "xXAxAbJePyUsVHeLytDvAxBGMRtnvCEiZZqe",
 "xMkQoIVxWPXPgaOYmDjTOXiMImVdzojERNxS",
 "dwICFwMAmdOIUxyAdXdshasnzwyhfnVWVqZJ",
 "etypXNVvSTEQvriGBZdSGmDEHhvpSqkFklCS",
 "YkxpFBCRYUueRcKaJUXVdaMoYMYEooPQVMOr",
 "DTrexDqclZNKdPuTRFHualJSFziCLPCZjpxo",
 "TfEijcAsSJPikkmBSbXMqYHAhPTcpcKVSkIX",
 "xKXHYPYMJxFpSbxltDKYuRiTkOLxpQKnXZPs",
 "YFYuvuYHfpFJcrLNIdlNfBxRnWdppsdalBkx",
 "NFTysBvNFjejdnlhRTclbcfGipNCxpFEOriY",
 "thkgVflJYmbUYbIlafNUMGePQWiZyYzYXvUR"}

1200

Returns: 396065426



*/
// END CUT HERE
#line 235 "ColorfulBuilding.cpp"

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

#define MOD 1000000009LL

ll fac(ll n) {
	ll v=1;
	RANGE(i, 1, n+1) v*=i;
	return v;
}

class ColorfulBuilding {
	public:
	int count(vector <string> C1, vector <string> C2, int L) {
		int N = C1.size() * C1[0].size();
		VI col(N+1);
		int co=1;
		col[0]=-1;
		REP(i, C1.size()) REP(j, C1[i].size()) col[co++] = C1[i][j]*256+C2[i][j];
		VVI dp(N+1, VI(N+1, 0));
		dp[0][0] = 1;
		RANGE(h, 1, N+1) {
			RANGE(c, 1, h+1) {
				RANGE(hh, 0, h) {
					//cout<<h<<" "<<c<<" "<<hh<<endl;
					ll cc = col[h]==col[hh] ? c : c-1;
					cout<<"dp["<<h<<"]["<<c<<"] += "<<dp[hh][cc]<<" * "<<fac(N-hh-1)<<" / "<<fac(N-h)<<endl;
					dp[h][c] += (dp[hh][cc]*fac(N-hh-1)/fac(N-h)) % MOD;
				}
			}
		}
		cout<<dp<<endl;
		return dp[N][L];
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
#define END	 verify_case(_, ColorfulBuilding().count(color1, color2, L));}
int main(){

CASE(0)
	string color1_[] = {"aaba"};
	  vector <string> color1(color1_, color1_+sizeof(color1_)/sizeof(*color1_)); 
	string color2_[] = {"aaaa"};
	  vector <string> color2(color2_, color2_+sizeof(color2_)/sizeof(*color2_)); 
	int L = 3; 
	int _ = 6; 
END
return 0;
CASE(1)
	string color1_[] = {"aaba"};
	  vector <string> color1(color1_, color1_+sizeof(color1_)/sizeof(*color1_)); 
	string color2_[] = {"aaba"};
	  vector <string> color2(color2_, color2_+sizeof(color2_)/sizeof(*color2_)); 
	int L = 4; 
	int _ = 0; 
END
CASE(2)
	string color1_[] = {"ab", "ba", "a", "aab"};
	  vector <string> color1(color1_, color1_+sizeof(color1_)/sizeof(*color1_)); 
	string color2_[] = {"bb", "ba", "a", "aba"};
	  vector <string> color2(color2_, color2_+sizeof(color2_)/sizeof(*color2_)); 
	int L = 5; 
	int _ = 432; 
END
CASE(3)
	string color1_[] = {"xxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOxxxxxxxxxxxxxxxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxxxxxxxxxxxxxxxOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxx"};
	  vector <string> color1(color1_, color1_+sizeof(color1_)/sizeof(*color1_)); 
	string color2_[] = {"xxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOxxxxxxxxxxxxOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxOOOOOOOOOOOOOOOOxx",
 "xxxxxxxxxxxxxxxxxxxx",
 "xxxxxxxxxxxxxxxxxxxx"};
	  vector <string> color2(color2_, color2_+sizeof(color2_)/sizeof(*color2_)); 
	int L = 58; 
	int _ = 619787617; 
END
CASE(4)
	string color1_[] = {"SJXcabKTWeUXhwxGixFepQaQlFxrAedNAtVP",
 "gorBIkcTlOFbLDbFeElYAyAqszQdMbpxSRdE",
 "SQVHPehlNtesbJDflyGxMqvgzjXisRnqDcQO",
 "pIAEBwbmpPWCooQAujbGXFGLvXxTmExLARkf",
 "AFnWyWKVObfxDGCjTxdZaObgwdxlPKtIxaAd",
 "uznMpJVNjAofbHJjOrZeSHgSagOCUMGbvkVR",
 "LBRrDbTAyKfVnedKiRfzgRzECpcsziqaTwdo",
 "JrJHvsEVVGDkNVGqLbpxyLDPloBuNDQKnReI",
 "SSYpbjKHSCnQhuyYrVauWDHDyhAoGyecrZMv",
 "UdetQfWEUWHHuAxRSdkJOOJSixKpQXpCFZHO",
 "KXVsQbuQtIgsULOMsTvPFNUqkBldMTLCipYK",
 "hoXConjnDWQkZVtyZlwSedvdVrNWqQhGUClQ",
 "TpsvvyoXsXmQpBAGGVDrXCkodoRHQZmpoQDW",
 "csiJspzTqeFBRmPgeEtTAzfrfCGlTZqcPuyO",
 "vsPDVBJVaJmUAtDdcsKoUkPEbDmAwtZKwjjP",
 "MOfoMhMiKIvGQoeIJXHzyClWRtRuKXMqxUAF",
 "KyyUCkRBjsYvmPFFEGBqqVhIUdtvIyyLacfu",
 "BfuwfSajSlcuTzhMufHSQLudvGEGlyHsEmBD",
 "PLpIXZkdyXveTMfSvqnDGKWOZrTBMUIlZrqF",
 "dzVMCqrSLbanRJTYpDJNHAOLPSzmvSEPQJYm",
 "rAjRkrSjouJyFaCSPPLYSzqDmMoADyWAbobJ",
 "eOCBrJNoyFnGpXpxiExXcoOHnVsaEPXhPfLe",
 "XMjRksnxWssPEINhdhbiLBSYpCLtwNshFjXS",
 "HnnDeUAbuswsgsYQuAaXySLkFYUwFXwYTreM",
 "uqLnwOEGbwZZDgAAWEdLRZxFlogDmlhjhgHM",
 "NcfaQsgPQfirkYDRFrLQpySmBGfRHumKULZf",
 "mOpmmgclsxRzXskEywfryqCRyATNoJwnlHiD",
 "AnoKoKAjrasttjNlHCROnvTJMhEHlVPVoVMo",
 "yegLyIuRkkENFAjwzDoPLKjgUHHEkfzYDIpo",
 "EcxRGGfuaBXUFXkSxctJWOLmmVbvoMkWtTvV",
 "nBMkOBHgaltEVzfyGxseGhmBscfGIbxFbqRn",
 "GvkEcLtqdOofGtsbWDafVMbNdJxsffKDzSiR",
 "jhZQUVzTzalrZcebvyqPWtOUUyniBKTWdyLi",
 "ODJLQPMdjDdTlxrfGsNmBfeGYjzeXApqKDhJ",
 "vlJkWMzdVQujKdLViQClOrJXMTBkuZEasFgg",
 "FAsbuzrLVIgaryqXBfuBRAbReleXSSgEKSvt"};
	  vector <string> color1(color1_, color1_+sizeof(color1_)/sizeof(*color1_)); 
	string color2_[] = {"XAhlUHtfjOpOlQlowWppQcodMGUiqoLobxnD",
 "IDzGlKrHiVGdBjZxIcoxjwagbWieKvUwZrjg",
 "SkpkTVeIFeoNQzUUgmYAYskKONNZdgXxSiWd",
 "rXBGhTmqnvxkmqiutoDzPusDiOUggEFXGCzm",
 "fzrxVuTbFXunGbeEavjshmrIRlDorTuISCxn",
 "LsvIaxTkOBjcskiekmrKNNFEXqnfMNXLWqqu",
 "ekzxGIlbJPVEQPYAbTuMtZKsCiubDXDiBVzU",
 "hZuOCJxvBOYENGSFcUiKKAKfCdebutVmnyvB",
 "UveNkKRQmHnedrROQOpHJfrHjwcNLUShlDbn",
 "ptUkvbaGDryHRkYfHKLkSgVpjWCEcgazyxGK",
 "nVPYEqTTJsRPjzjfdOiULhnZPFeNcnbXaQlk",
 "IPXBXRhMQIkxpygsgbcRfMuvIcuzUPPHGOWX",
 "yWWlNyEyqZSIOXBFAybIuFpVqpvmKRaRFrAE",
 "EvBJVtHvKhjrFcmtpdBbFTdTVtXXZQKAglKT",
 "bCVjHzUvyINFkxXageZQMzCyNhcifACdJVDh",
 "lZITYcDSeIbLweyFtoMAfOQyBNupKlhcNpgo",
 "BduslNrJdWOUukYFFidEkMFaghfofpxVgvJd",
 "YrJpDZKqdjEPzdLsOQEdkcrBfNHPemXHokCW",
 "GjeUKSGjDlgKTyUGNrMQbBLxRUcgrWpkAwOD",
 "wgxTcswqdJHaDugNIRMvrhBsdDaJAssVbSRW",
 "qmVmqFEpvgGioMXDSFqEoQcDOAaUoGPEovSO",
 "KrukPlpfOhawaovCfteTSCIdLMrtImVtiMyQ",
 "ykwmxHsKMFzFHwcbyyedLvhZPnaNGqJMMCxd",
 "HUNYCXjNLQIFCLLGpCXHBCHLTxLynBxnHFbx",
 "uwjzbNbJepVFgMPUXVirxYHzExquBEtPmKju",
 "xXAxAbJePyUsVHeLytDvAxBGMRtnvCEiZZqe",
 "xMkQoIVxWPXPgaOYmDjTOXiMImVdzojERNxS",
 "dwICFwMAmdOIUxyAdXdshasnzwyhfnVWVqZJ",
 "etypXNVvSTEQvriGBZdSGmDEHhvpSqkFklCS",
 "YkxpFBCRYUueRcKaJUXVdaMoYMYEooPQVMOr",
 "DTrexDqclZNKdPuTRFHualJSFziCLPCZjpxo",
 "TfEijcAsSJPikkmBSbXMqYHAhPTcpcKVSkIX",
 "xKXHYPYMJxFpSbxltDKYuRiTkOLxpQKnXZPs",
 "YFYuvuYHfpFJcrLNIdlNfBxRnWdppsdalBkx",
 "NFTysBvNFjejdnlhRTclbcfGipNCxpFEOriY",
 "thkgVflJYmbUYbIlafNUMGePQWiZyYzYXvUR"}
;
	  vector <string> color2(color2_, color2_+sizeof(color2_)/sizeof(*color2_)); 
	int L = 1200; 
	int _ = 396065426; 
END

}
// END CUT HERE
