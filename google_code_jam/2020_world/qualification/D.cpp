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
#define FI first
#define SE second
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template<typename T>void maxUpdate(T& a, T b) {a = max(a, b);}
template<typename T>void minUpdate(T& a, T b) {a = min(a, b);}

/*
i < j < N/2 で i, j, N-1-j, N-1-i を read して
ABBB | BABB | BBAB | BBBA パターンならば
その後は
2つread->操作特定->8個readの繰り返しでOK
何回繰り返す? -> 96/8*10=120回
残り30回で上記パターンを見つければOK

i=0で s[i], s[N-1-i] が
AAの場合
	0<jでABパターンをみつければOK
	存在しない場合はすべてAの場合だけ
ABの場合
	0<jでAAパターンをみつければOK
	存在しない場合はAAAAABBBBBの場合だけ

左右5個ずつread 10x10回
各セクションの特徴bit(最大2こ)を読む 2x5 x2
-> これで2セクションになるので 2x2読んでおわり
最大124回

*/
void test(ll n) {
	auto rev = [](string s) {
		reverse(ALL(s));
		return s;
	};
	auto x = [](string s) {
		REP(i, s.size()) s[i] = s[i]=='0' ? '1':'0';
		return s;
	};
	ll goods=0;
	REP(bi, 1<<n) {
		string s(n, ' ');
		REP(i, n) s[i] = bi>>i&1 ? '1':'0';
		set<string> se;
		se.insert(s.substr(0, n/2));
		se.insert(rev(s).substr(0, n/2));
		se.insert(x(s).substr(0, n/2));
		se.insert(rev(x(s)).substr(0, n/2));
		goods += se.size()==4;
		cout<<s<<" "<<rev(s)<<" "<<x(s)<<" "<<rev(x(s))<<" "<<(se.size()==4?"GOOD":"")<<endl;
	}
	cout<<"GOOD ratio "<<((double)goods/(1<<n))<<endl;
}
struct Foo {
	ll si;
	VI q;
	map<VI, VI> res;
};
VI rev(VI s) {
	reverse(ALL(s));
	return s;
};
VI xo(VI s) {
	REP(i, s.size()) s[i] ^= 1;
	return s;
};
Foo make(ll idx, VI pat) {
	VVI es = {
		pat,
		rev(pat),
		xo(pat),
		rev(xo(pat)),
	};
	sort(ALL(es));
	es.erase(unique(ALL(es)), es.end());
	cerr<<"es "<<es<<endl;
	REP(i, pat.size()/2) {
		map<VI, VI> s;
		REP(ei, es.size()) {
			s[VI{es[ei][0], es[ei][i]}] = es[ei];
		}
		cerr<<"i "<<i<<" s "<<s<<endl;
		if(s.size()==es.size()) {
			cerr<<"idx 0, "<<i<<" map "<<s<<endl;
			return Foo{
				idx,
				VI{idx, idx+i},
				s,
			};
		}
	}
	return Foo{};
}
int main() {
//	test(2);
//	test(4);
//	return 0;

	cin.tie(0);
	ios::sync_with_stdio(false);
	int test_cases;
	cin>>test_cases;
	ll N;
	cin>>N;
	string res;
	REP(ttt, test_cases) {
		VI tb(N);
		cerr<<N<<endl;
		REP(si, N/10) {
			RANGE(i, si*5, si*5+5) {
				cout<<i+1<<endl;
				cin>>tb[i];
				cout<<N-1-i+1<<endl;
				cin>>tb[N-1-i];
			}
		}
		cerr<<tb<<endl;
		REP(si, N/5/2) {
			VI a;
			RANGE(i, si*5, si*5+5) a.PB(tb[i]);
			RANGER(i, si*5, si*5+5) a.PB(tb[N-1-i]);
			Foo foo = make(si*5, a);
			VI rs(foo.q.size());
			REP(i, foo.q.size()) {
				cout<<foo.q[i]+1<<endl;
				cin>>rs[i];
			}
			REP(i, 5) tb[foo.si+i] = foo.res[rs][i];
			REP(i, 5) tb[N-1-(foo.si+i)] = foo.res[rs][10-1-i];
		}
		REP(si, N/25/2) {
			VI a;
			RANGE(i, si*25, si*25+25) a.PB(tb[i]);
			RANGER(i, si*25, si*25+25) a.PB(tb[N-1-i]);
			Foo foo = make(si*25, a);
			VI rs(foo.q.size());
			REP(i, foo.q.size()) {
				cout<<foo.q[i]+1<<endl;
				cin>>rs[i];
			}
			REP(i, 25) tb[foo.si+i] = foo.res[rs][i];
			REP(i, 25) tb[N-1-(foo.si+i)] = foo.res[rs][50-1-i];
		}
		string ans(N, '0');
		REP(i, N) ans[i] = tb[i]+'0';
		cout<<ans<<endl;
		cin>>res;
		if(res=="N") break;
		cerr<<res<<endl;
//		return 0;
	}
	return 0;
}



