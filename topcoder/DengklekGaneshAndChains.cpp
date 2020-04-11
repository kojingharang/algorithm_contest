// BEGIN CUT HERE
/**
// PROBLEM STATEMENT
// Dengklek works as a chain maker. He currently owns N chains. Each chain is a circular chain that consists of K links. There is a letter engraved on each link of each chain.
You are given the vector <string> chains with N elements, each containing exactly K characters. Each element of chains contains the characters written on one of the chains, in order.

Ganesh is Dengklek's best friend. Tomorrow is his birthday. Dengklek wants to give Ganesh a straight (non-circular) chain as a present. He will do so by cutting and then combining some pieces of the chains he currently owns.

More precisely, you are given a vector <int> lengths that contains M elements. Dengklek will construct the new chain as follows:


  At the beginning, the chain for Ganesh is empty.
  For each i from 0 to M-1:
  
    Dengklek will pick one of his circular chains that has not been picked before.
    Dengklek will cut a contiguous sequence of lengths[i] links from the chain. He will keep the sequence and discard the remaining links. (In particular, if lengths[i] = K, Dengklek just splits the chosen chain at some point of his choice to turn it from a circular to a straight sequence. No links are lost while doing so.)
    Dengklek will attach the sequence he just produced to the end of the chain for Ganesh.
  
  


Note that Dengklek's current chains are circular, so the last link of each chain is adjacent to the first link of that chain. Dengklek may choose a sequence that contains this part of the chain.

Note that Dengklek's chains are not symmetric. This means that Dengklek is not allowed to reverse the order of the links in any of the sequences he chooses.

Return the lexicographically largest possible string that can appear on the chain Dengklek gives to Ganesh.


DEFINITION
Class:DengklekGaneshAndChains
Method:getBestChains
Parameters:vector <string>, vector <int>
Returns:string
Method signature:string getBestChains(vector <string> chains, vector <int> lengths)


NOTES
-Given two distinct strings of the same length, the lexicographically larger one is the one that has a larger character on the first position on which they differ.


CONSTRAINTS
-N and K will each be between 1 and 50, inclusive.
-chains will contain exactly N elements.
-Each element of chains will contain exactly K characters.
-Each character of chains will be a lowercase English letter ('a' to 'z').
-M will be between 1 and N, inclusive.
-lengths will contain exactly M elements, inclusive.
-Each element of lengths will be between 1 and K, inclusive.


EXAMPLES

0)
{"topc", "oder", "open", "twob"}
{2, 1, 3}

Returns: "wotrod"

The optimal solution is as follows:


Dengklek picks "twob" and cuts "wo" from it.
Dengklek picks "topc" and cuts "t" from it.
Dengklek picks "oder" and cuts "rod" from it. This is possible because the chain is circular, so 'r' and 'o' are adjacent.


The resulting chain is "wo" + "t" + "rod" = "wotrod".

1)
{"ssh", "she", "see", "sea"}
{2, 3, 2, 3}

Returns: "ssshesesee"

The optimal solution is as follows:


Dengklek picks "ssh" and cuts "ss" from it.
Dengklek picks "she" and cuts "she" from it.
Dengklek picks "sea" and cuts "se" from it.
Dengklek picks "see" and cuts "see" from it.


The resulting chain is "ss" + "she" + "se" + "see" = "ssshesesee".

2)
{"wri", "ter", "who", "are", "you"}
{3}

Returns: "you"



3)
{"harus", "imfyo"}
{5, 5}

Returns: "yoimfushar"



*/
// END CUT HERE
#line 105 "DengklekGaneshAndChains.cpp"

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
#include <cstdio>
#include <cassert>
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
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
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }


string neg(string s) {
	REP(i, s.size()) s[i] = 'z'-(s[i]-'a');
	return s;
}

string tx(string s) {
	int N=s.size();
	string ans=s;
	REP(i, N) {
		string temp;
		REP(j, N) temp+=s[(i+j)%N];
		if(temp>=ans) ans = temp;
	}
	return ans;
}

string get(string s, int sz) {
	string ans;
	REP(i, sz) ans+=s[i];
	return ans;
}

class DengklekGaneshAndChains {
	public:
	string getBestChains(vector <string> C, vector <int> L) {
		int N = C.size();
		int K = C[0].size();
		REP(i, N) {
			string Max = string(1, 'a'-1);
			REP(ki, K) {
				string s = (C[i]+C[i]).substr(ki, K);
				if(Max<s) Max=s;
			}
			C[i] = Max;
		}
		sort(ALL(C));
		DD(C);

		int M = L.size();
		vector<bool> done(N);
		string ans;
		REP(mi, M) {
			string Max = string(1, 'a'-1);
			int idx=-1;
			REP(i, N) if(!done[i]) {
				string s = C[i].substr(0, L[mi]);
				if(Max<s) {
					Max=s;
					idx=i;
				}
			}
			ans += Max;
			done[idx]=true;
		}
		return ans;
	}
};
//{"rv", "oo", "ey", "ve", "bi"}
//{1, 1, 2, 1}
//ans: yvveo
//ref: yvvro

class DengklekGaneshAndChainsRef {
	public:
	string getBestChains(vector <string> C, vector <int> L) {
		int N = C.size();
		int K = C[0].size();
		REP(i, N) C[i] += C[i];

		int M = L.size();
		vector<bool> done(N);
		string ans;
		REP(mi, M) {
			vector<pair<string, pair<string, ll>>> w;
			REP(i, N) if(!done[i]) {
				string Max2 = string(1, 'a'-1);
				REP(ki, K) {
					string s = C[i].substr(ki, K);
					if(Max2<s) Max2=s;
				}
				Max2 = neg(Max2)+"_"+Max2;
//				Max2 = "";
				string Max = string(1, 'a'-1);
				REP(ki, K) {
					string s = C[i].substr(ki, L[mi]);
					if(Max<s) Max=s;
				}
				w.PB(MP(Max, MP(Max2, i)));
			}
			sort(ALLR(w));
//			DD(mi);
//			DD(w);
			ans += w[0].first;
			done[w[0].second.second]=true;
		}
		return ans;
	}
};

string gen1(int K) {
	string rv;
	REP(i, K) rv += 'a'+UNIFORM_LL(0, 26);
	return rv;
}

vector<string> gen(int N, int K) {
	vector<string> w(N);
	REP(i, N) {
		w[i] = gen1(K);
	}
	return w;
}

vector<int> genL(int M, int K) {
	vector<int> rv(M);
	REP(i, M) {
		rv[i] = UNIFORM_LL(1, K+1);
	}
	return rv;
}

string naive(vector <string> C, vector <int> L) {
	int N = C.size();
	int M = L.size();
	int K = C[0].size();
	REP(i, N) C[i]+=C[i];
	string w;
	sort(ALL(C));
	string ans = string(1, 'a'-1);
	do {
		string lans;
		REP(mi, M) {
			string Max = string(1, 'a'-1);
			REP(ki, K) {
				string s = C[mi].substr(ki, L[mi]);
				if(Max<s) Max=s;
			}
			lans += Max;
		}
		if(ans<lans) ans = lans;
	} while(next_permutation(ALL(C)));
	return ans;
}

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const string& Expected, const string& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, DengklekGaneshAndChains().getBestChains(chains, lengths));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

CASE(0)
	string chains_[] = {"topc", "oder", "open", "twob"};
	  vector <string> chains(chains_, chains_+sizeof(chains_)/sizeof(*chains_)); 
	int lengths_[] = {2, 1, 3};
	  vector <int> lengths(lengths_, lengths_+sizeof(lengths_)/sizeof(*lengths_)); 
	string _ = "wotrod"; 
END
CASE(1)
	string chains_[] = {"ssh", "she", "see", "sea"};
	  vector <string> chains(chains_, chains_+sizeof(chains_)/sizeof(*chains_)); 
	int lengths_[] = {2, 3, 2, 3};
	  vector <int> lengths(lengths_, lengths_+sizeof(lengths_)/sizeof(*lengths_)); 
	string _ = "ssshesesee"; 
END
CASE(2)
	string chains_[] = {"wri", "ter", "who", "are", "you"};
	  vector <string> chains(chains_, chains_+sizeof(chains_)/sizeof(*chains_)); 
	int lengths_[] = {3};
	  vector <int> lengths(lengths_, lengths_+sizeof(lengths_)/sizeof(*lengths_)); 
	string _ = "you"; 
END
CASE(3)
	string chains_[] = {"harus", "imfyo"};
	  vector <string> chains(chains_, chains_+sizeof(chains_)/sizeof(*chains_)); 
	int lengths_[] = {5, 5};
	  vector <int> lengths(lengths_, lengths_+sizeof(lengths_)/sizeof(*lengths_)); 
	string _ = "yoimfushar"; 
END
int N=8, K=8, M=7;
REP(i, 100) {
	auto C = gen(N, K);
	auto L = genL(M, K);
	auto ans = DengklekGaneshAndChains().getBestChains(C, L);
	auto ref = naive(C, L);
	DD(C);
	DD(L);
	DD(ans);
	DD(ref);
	assert(ans==ref);
}
/*
C: mx xb xn ni zm 
L: 1 1 2 1 
ans: zxxmx
ref: zxxnx

{"mx", "xb", "xn", "ni", "zm"}
{1, 1, 2, 1}
*/


#if 0  // DO RANDOM TESTS

// INIT GLOBAL VARIABLES IN TRIAL CODE !!!!!!!!!!!!!!
// 1. Copy my class 
// 2. Add `Ref` suffix to my original class 
// 3. Write someone's code into copied class 
// 4. Run and verify example test case and random tests

#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
if(!allOK) return 0;
srand((unsigned)time(NULL));
cerr<<endl;
cerr<<"RANDOM TESTS"<<endl;
for(int loop=0;loop<100;loop++) {
// param type: String
	vector <string> chains; 
	{
		int N=UNIFORM_LL(1, 51);
		chains = vector <string>(N); 
		REP(i, N) {
			chains[i] = UNIFORM_LL(0, 1000);
		}
	}
// param type: int
	vector <int> lengths; 
	{
		int N=UNIFORM_LL(1, 51);
		lengths = vector <int>(N); 
		REP(i, N) {
			lengths[i] = UNIFORM_LL(0, 1000);
		}
	}
	string _0 = DengklekGaneshAndChains().getBestChains(chains, lengths);
	string _1 = DengklekGaneshAndChainsRef().getBestChains(chains, lengths);
	if(!verify_case(_0, _1, true)) {
print(chains);
print(lengths);
	}
}
#endif

}
// END CUT HERE
