#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <fstream>
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
#define VVVI vector<vector<vector<ll>>>
#define VVVVI vector<vector<vector<vector<ll>>>>
#define REP(i,n) for(ll i=0,_n=(n);(i)<(ll)_n;++i)
#define REPR(i,n) for(ll i=(ll)(n)-1;0<=(i);--i)
#define RANGE(i,a,b) for(ll i=(ll)a,_b=(ll)(b);(i)<_b;++i)
#define RANGER(i,a,b) for(ll i=(ll)(b)-1,_a=(ll)(a);(_a)<=i;--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT __builtin_popcount
#define POPCOUNTLL __builtin_popcountll
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define UNIFORM_DOUBLE(a, b) (((b-a)*(double)rand()/RAND_MAX)+a) // [a, b) 
#define UNIFORM_LL(a, b) (ll)UNIFORM_DOUBLE(a, b) // [a, b) 
#define IN(v, lo, hi) ((lo)<=(v) && (v)<(hi))
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

#define MOD 1000000007LL
#define INF (1LL<<60)

string i2s(ll v) {
	string s(16, ' ');
	REP(i, 16) s[i] = '0'+(v>>i&1);
	return s;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
//	ofstream ofs("log.txt");
//	auto& ofs = cerr;
	int test_cases;
	cin>>test_cases;
//	ofs<<">>> "<<test_cases<<endl;
	ll N,B,F;
	string s;
	vector<string> pat(4, string(16, '0'));
	REP(i, pat.size()) REP(j, 16) if((j/(1<<i))%2) pat[i][j] = '1';
//		DD(pat);
	map<vector<string>, string> h;
	REP(bi, 1<<16) if(POPCOUNTLL(bi)<=15) {
		vector<string> seen;
		REP(pi, pat.size()) {
			string v;
			REP(i, 16) if(!(bi>>i&1)) v += pat[pi][i];
			seen.PB(v);
		}
//			ofs<<"bi "<<i2s(bi)<<endl;
//			ofs<<"seen "<<seen<<endl;
		if(h.count(seen)) {
			DD("DUP");
			assert(0);
		}
		h[seen] = i2s(bi);
	}

	REP(ttt, test_cases) {
		cin>>N>>B>>F;
		
		string pat0(N, ' ');
		REP(i, N) pat0[i] = (i/16%2)+'0';
//		ofs<<">>> "<<N<<" "<<B<<" "<<F<<endl;
//		ofs<<"<<< "<<pat0<<endl;

		cout<<pat0<<endl;
		cin>>s;
//		ofs<<">>> "<<s<<endl;
		if(N<16) s += string(16-N, '0');
		VI bs;
		char last=' ';
		REP(i, s.size()) {
			if(last!=s[i]) bs.PB(0);
			bs[bs.size()-1]++;
			last=s[i];
		}
//		ofs<<"BS "<<bs<<endl;
		vector<vector<string>> seen(bs.size());
		REP(pi, 4) {
			string S;
			while(S.size() < N) S+=pat[pi];
			S = S.substr(0, N);
			cout<<S<<endl;
//			ofs<<"<<< "<<S<<endl;
			cin>>s;
//			ofs<<">>> "<<s<<endl;
			REP(i, 16) if(N<=i) s.PB(pat[pi][i]);
//			ofs<<"++ "<<s<<endl;
			// split into blocks
			ll last = 0;
			REP(bi, bs.size()) {
				seen[bi].PB(s.substr(last, bs[bi]));
				last += bs[bi];
			}
		}
//		ofs<<"seen "<<seen<<endl;
		VI ans;
		REP(bi, bs.size()) {
//			ofs<<"h[seen] "<<h[seen[bi]]<<endl;
			REP(i, h[seen[bi]].size()) if(h[seen[bi]][i]=='1') ans.PB(bi*16+i);
		}
//		ofs<<"<<< ";
		REP(i, B) {
			cout<<ans[i];
//			ofs<<ans[i];
			if(i<B-1) {
				cout<<" ";
//				ofs<<" ";
			}
		}
		cout<<endl;
//		ofs<<endl;

		cin>>s;
//		ofs<<">>> Judge "<<s<<endl;
		if(s=="-1") return 0;
//		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		return 0;
	}
//	ofs<<"END"<<endl;
	return 0;
}



