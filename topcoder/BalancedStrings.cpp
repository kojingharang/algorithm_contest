#include <vector>
#include <map>
#include <set>
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
#include <cassert>
#include <cctype>
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
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT2(table, I, J) REP(i, I) { REP(j, J) cout<<table[i][j]<<" "; cout<<"\n"; }
#define PRINT3(table, I, J, K) REP(i, I) { REP(j, J) { REP(k, K) cout<<table[i][j][k]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<(v)<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

ll sim(string& a, string& b) {
	ll ans = 0;
	for(auto c : a)
	for(auto d : b)
	if(c==d) ans++;
	return ans;
}

ll SIM(vector<string>& w) {
	ll si = 0;
	REP(i, w.size()) RANGE(j, i+1, w.size()) {
		si += sim(w[i], w[j]);
	}
	return si;
}


void check(vector<string> w) {
	ll ins = 0;
	for(auto s : w) {
		REP(i, s.size()-1) {
			ins += s[i]!=s[i+1];
		}
	}
	ll si = SIM(w);
	DD(w);
	DD(ins);
	DD(si);
	assert(ins==si);
}

class BalancedStringsTry {
	public:
	vector<string> findAny(int N) {
		DD("begin");
		DD(N);
		vector<string> ans(N);
		if(N<=26) {
			ans = vector<string>(N);
			REP(i, N) ans[i] = 'a'+i;
		} else {
			string t1="ab";
			string t2="cd";
			string t3="ef";
			string t4="gh";
			int c1=2,c2=2,c3=2,c4=2;
			int tot=4;
			VI f(26);
			int req=N-4;
			int cur=0;
			int var=8;
			int now=0;
			while(req>0) {
				cur++;
				if(cur>6) {
					f[var]=cur-1;
					cur=1;
					var++;
					now+=15;
				}
				req--;
			}
			f[var]=cur;
			int x=cur*(cur-1);
			x/=2;
			now+=x;
			while(now>tot) {
				if(t1.size()<100) {
					if(t1.size()%2==1) t1+="b";
					else t1+="a";
				}
				else if(t2.size()<100) {
					if(t2.size()%2==1) t2+="d";
					else t2+="c";
				}
				else if(t3.size()<100) {
					if(t3.size()%2==1) t3+="f";
					else t3+="e";
				}
				else {
					if(t4.size()%2==1) t4+="h";
					else t4+="g";
				}
				now--;
			}
			ans[0]=t1;
			ans[1]=t2;
			ans[2]=t3;
			ans[3]=t4;
			int i=4;
			while(i<N) {
				for(int j=8;j<26&&i<N;) {
					if(f[j]>0) {
						f[j]--;
						char ch = j+97;
						string t(1, ch);
						ans[i]=t;
						i++;
					} else {
						j++;
					}
				}
			}
		}
		DD(ans);
		return ans;
	}
};


class BalancedStrings {
	public:
	vector<string> findAny(int N) {
		vector<string> ans;
		if(N<=26) {
			ans = vector<string>(N);
			REP(i, N) ans[i] = 'a'+i;
		} else {
			auto a = vector<string>(N, "a");
			REP(i, N) {
				a[i] = 'a' + (i%22);
			}
			DD(SIM(a));
			ll rest = SIM(a);
			REP(i, 99) {
				if(rest==0) break;
				rest--;
				a[0] += string(1, (i&1) ? 'z':'y');
			}
			REP(i, 99) {
				if(rest==0) break;
				rest--;
				a[1] += string(1, (i&1) ? 'w':'x');
			}
			check(a);
			ans = a;
		}
		return ans;
//		return vector<string>(N, "a");
//		return {"a"};
	}
};

// BEGIN CUT HERE
#include <ctime>
bool allOK=true;
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
bool verify_case(const int& Expected, const int& Received, bool noPASSmsg=false) {
 bool ok = (Expected == Received);
 allOK = allOK && ok;
 if(ok) { if(!noPASSmsg) cerr << "PASSED" << timer() << endl; } 
 else { cerr << "FAILED" << timer() << endl;
 cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } return ok;  }
#define CASE(N) {cerr << "Test Case #" << N << "..." << flush; start_time=clock();
#define END	 verify_case(_, RepeatString().minimalModify(s));}
template<class T> void print(const vector<T>& v) {cout<<"{";for(int i=0;i<(int)v.size();i++) {cout<<v[i];if(i<(int)v.size()-1) cout<<",";} cout<<"}"<<endl;}
template<class T> void print(const T& v) {cout<<v<<endl;}
int main(){

//check({"topcoder", "eertree", "arena"});
//check({"a"});
//check({"a", "b"});
//check({"a", "b", "c"});
//check({"a", "a", "a"});
//check({"a", "a", "a", "a"});
//check({"a", "a", "a", "a", "a"});
//check({"abcde", "a", "a", "a", "a"});
//check({"ac", "b", "ac", "b"});

RANGE(i, 1, 101) {
//	auto ans = BalancedStrings().findAny(i);
	auto ans = BalancedStringsTry().findAny(i);
	check(ans);
}

if(0)
{
	ll N = 99;
	auto a = vector<string>(N, "a");
	REP(i, N) {
		a[i] = 'a' + (i%22);
	}
	DD(SIM(a));
	ll rest = SIM(a);
	REP(i, 99) {
		if(rest==0) break;
		rest--;
		a[0] += string(1, (i&1) ? 'z':'y');
	}
	REP(i, 99) {
		if(rest==0) break;
		rest--;
		a[1] += string(1, (i&1) ? 'w':'x');
	}
	check(a);
}


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
	string s; 
	{
		int N=UNIFORM_LL(1, 51);
		s = string(N, ' '); 
		string tb = "abcde";
		REP(i, N) {
			s[i] = tb[UNIFORM_LL(0, tb.size())];
		}
	}
	int _0 = RepeatString().minimalModify(s);
	int _1 = RepeatStringRef().minimalModify(s);
	if(!verify_case(_0, _1, true)) {
print(s);
	}
}
#endif

}
// END CUT HERE
