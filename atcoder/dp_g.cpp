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
#include <functional>
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

#define MOD 1000000007LL
#define INF (1LL<<60)

struct modll {
	static const ll MODVAL;
	ll val;
	modll() : val(0) {}
	modll(ll v) : val(v) { normalize(); }
	void normalize() { val = (val+MODVAL) % MODVAL; }
	modll  operator+ (ll v) { return modll(val+v); }
	modll& operator+=(ll v) { val+=v; normalize(); return *this; }
	modll  operator- (ll v) { return modll(val-v); }
	modll& operator-=(ll v) { val-=v; normalize(); return *this; }
	modll  operator* (ll v) { return modll(val*v); }
	modll& operator*=(ll v) { val*=v; normalize(); return *this; }
	modll  operator^ (ll e) { modll x(val); modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; } // pow
	modll inv() { modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
	static modll inv(ll v) { return modll(v).inv(); }
	operator ll() { return val; }
};
const ll modll::MODVAL = 1000000007;
std::ostream& operator<<(std::ostream& os, const modll& v) { os << v.val; return os; }

template<typename T>
class SubSeq {
public:
	// 部分列すべて
	T countAllDP1(const string& S) {
		ll N = S.size();
		dp = vector<T>(N+1);
		// [i] : S[idx] : idx in [0, i) の範囲で何通りあるか
		dp[0] = T(1LL);
		RANGE(i, 1, N+1) dp[i] = dp[i-1] * T(2LL);
		DD(dp);
		return dp[N];
	}
	// 部分列すべて
	T countAllDP2(const string& S) {
		ll N = S.size();
		genNext(S);
		// [i] : S[i-1] は使うとして, S[idx] : idx in [0, i) の範囲で何通りあるか
		dp = vector<T>(N+1, T(1LL));
//		dp[0] = T(1LL);
		REP(i, N+1) {
			REP(ci, 26) {
				ll I = i-1; // 今見てるのは S[I]
				// 今見てるとこの次以降の ci のところ*すべて*に配る -> coutAllDP1 と同じ結果になる
				RANGE(ni, I+1, N) if(S[ni]-'a'==ci) {
					dp[ni+1] += dp[i];
					cout<<ni+1<<" += "<<i<<" ("<<dp[i]<<")"<<endl;
				}
			}
			DD(dp);
		}
		return dp[N];
	}
	// ユニークな部分列(辞書順, 空文字含む)
	vector<string> elements;
	// ユニークな部分列すべて
	T countUniqNaive(const string& S) {
		auto se = set<string>();
		REP(bi, 1<<S.size()) {
			string s;
			REP(i, S.size()) if(bi>>i&1) s.PB(S[i]);
			se.insert(s);
		}
		elements = vector<string>(ALL(se));
//		DD(elements);
		REP(i, elements.size()) cout<<i<<" "<<elements[i]<<endl;
		return T(se.size());
	}
	VVI next;
	vector<T> dp;
	void genNext(const string& S) {
		ll N = S.size();
		// [i][ci] : i <= j に対して S[j]==ci+'a' となる最小の j. なければ N
		next = VVI(N+1, VI(26, N));
		for(int i=N-1;0<=i;i--) {
			REP(ci, 26) next[i][ci] = next[i+1][ci];
			next[i][S[i]-'a'] = i;
		}
//		DD(next);
	}
	// ユニークな部分列すべて
	T countUniqL(const string& S) {
		ll N = S.size();
		genNext(S);
		// [i] : S[i-1] は使うとして, S[idx] : idx in [0, i) の範囲で何通りあるか
		dp = vector<T>(N+1, T(1LL));
		REP(i, N) {
			REP(ci, 26) {
				ll I = i-1; // 今見てるのは S[I]
				// 今見てるとこの次以降の ci のところに配る
				if(next[I+1][ci] < N) {
					dp[next[I+1][ci]+1] += dp[i];
					cout<<next[i][ci]+1<<" += "<<i<<" ("<<dp[i]<<")"<<endl;
				}
			}
			DD(dp);
		}
		return dp[N];
	}
	// ユニークな部分列すべて
	T countUniqR(const string& S, T upto=1LL<<62) {
		ll N = S.size();
		genNext(S);
		// [i] : S[i-1] は使うとして, S[idx] : idx in [i-1, N) までで何通りあるか
		// 最低1通りはある
		dp = vector<T>(N+1, T(1LL));
		for(int i=N;0<=i;i--) {
			REP(ci, 26) {
				ll I = i-1; // 今見てるのは S[I]
				// 今見てるとこの次以降の ci のところから持ってくる
				if(next[I+1][ci] < N) {
					dp[i] += dp[next[I+1][ci]+1];
					dp[i] = min(dp[i], upto);
//					cout<<i<<" ("<<dp[i]<<")"<<" += "<<next[i][ci]+1<<endl;
				}
			}
//			DD(dp);
		}
		return dp[0];
	}
};

string ref(const string& S, ll K) {
	auto ss = SubSeq<modll>();
	ss.countUniqNaive(S);
	return K<ss.elements.size() ? ss.elements[K] : "Eel";
}

string solve(const string& S, ll K) {
	auto ss = SubSeq<ll>();
	ss.countUniqR(S, K+1);
	ll idx = 0, k = 0;
	string ans;
//	DD(ss.dp);
	while(k<K) {
		ll upd = 0;
		REP(ci, 26) {
			ll nidx = ss.next[idx][ci];
			if(nidx==S.size()) continue;
			ll cnt = ss.dp[nidx+1];
//			DD("------------------");
//			DD(string(1, ci+'a'));
//			DD(k);
//			DD(idx);
//			DD(nidx);
//			DD(cnt);
			if(K <= k+cnt) {
				ans.PB(ci+'a');
//				cout<<"PUSHED. ans: "<<ans<<endl;
				idx = nidx + 1;
				upd = 1;
				k++;
				break;
			}
			k += cnt;
		}
		if(!upd) {
			ans = "Eel";
			break;
		}
	}
	return ans;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cout<<SubSeq<ll>().countUniqR("abcbc")<<endl;
	cout<<SubSeq<ll>().countUniqNaive("abcbc")<<endl;
	return 0;

	ll K;
	string S;
	if(0)
	{
		S = "lexicographical";
		RANGE(k, 1, 10000) {
			string a = ref(S, k);
			string b = solve(S, k);
			if(a!=b) {
				DD(a);DD(b);
				assert(0);
			}
		}
		return 0;
	}
	while(cin>>S>>K) {
//		if(0)
		{
			auto ss = SubSeq<ll>();
			cout<<"countAllDP1 "<<ss.countAllDP1(S)<<endl;
			cout<<"countAllDP2 "<<ss.countAllDP2(S)<<endl;
			cout<<"countUniqNaive "<<ss.countUniqNaive(S)<<endl;
			cout<<"countUniqL "<<ss.countUniqL(S)<<endl;
			cout<<"countUniqR "<<ss.countUniqR(S)<<endl;
		}

		string ans = solve(S, K);
		cout<<ans<<endl;
//		break;
	}
	
	return 0;
}
