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
#define RANGE_R(i,a,b) for(int i=(int)b-1,_a=(int)(a);(i)>=_a;--i)
#define MIN_UPDATE(target, value) target = min(target, value)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define ALLR(c) (c).rbegin(), (c).rend()
#define PB push_back
#define MP(a, b) make_pair(a, b)
#define POPCOUNT(v) __builtin_popcountll((ll)(v))
#define IN_RANGE(v, a, b) ((a)<=(v) && (v)<(b))
#define CLEAR(table, v) memset(table, v, sizeof(table));
#define PRINT1(table, D0) REP(d0, D0) cout<<table[d0]<<" "; cout<<"\n";
#define PRINT2(table, D0, D1) REP(d0, D0) { REP(d1, D1) cout<<table[d0][d1]<<" "; cout<<"\n"; }
#define PRINT3(table, D0, D1, D2) REP(d0, D0) { REP(d1, D1) { REP(d2, D2) cout<<table[d0][d1][d2]<<" "; cout<<"\n"; } cout<<"\n"; }
#define DD(v) cout<<#v<<": "<<v<<endl
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }

int naive(const string& s) {
	struct El {
		int count;
		string s;
		bool finished() const {
			return std::count(ALL(s), '+')==s.size();
		}
	};
	queue<El> q;
	q.push(El{0, s});
	while(q.size()) {
		El el = q.front(); q.pop();
//		DD(el.count);
//		DD(el.s);
		if(el.finished()) return el.count;
		RANGE(nflip, 1, el.s.size()+1) {
			string flipped(el.s);
			REP(i, nflip) {
				flipped[i] = el.s[nflip-1-i]=='+' ? '-':'+';
			}
			if(el.s!=flipped) {
//				DD("push");
//				DD(s);
//				DD(nflip);
//				DD(flipped);
				q.push(El{el.count+1, flipped});
			}
		}
	}
	assert(0);
}

int f(const string& s) {
//	DD(s);
	if(count(ALL(s), '+')==s.size()) return 0;
	int lm = 0;
	int lp = 0;
	REP(i, s.size()) {
		if(s[i]!='-') break;
		lm++;
	}
	REP(i, s.size()) {
		if(s[i]!='+') break;
		lp++;
	}
	if(lp) {
		string ss(s);
		REP(i, lp) ss[i]='-';
		return 1+f(ss);
	}
	if(lm) {
		string ss(s);
		REP(i, lm) ss[i]='+';
		return 1+f(ss);
	}
	assert(0);
}

int ff(string s) {
	int ans = f(s);
	int nans = naive(s);
	if(ans!=nans) {
		DD(s);
		DD(ans);
		DD(nans);
		assert(0);
	}
	return ans;
}

int main() {
	int test_cases;
	cin>>test_cases;
	string s;
	REP(ttt, test_cases) {
		cin>>s;
		int ans = f(s);
		cout<<"Case #"<<ttt+1<<": "<<ans<<endl;
//		return 0;
	}
//	RANGE(di, 1, 11) {
//		string s(di, '-');
//		REP(bi, 1<<di) {
//			REP(i, di) s[i]=(bi>>i&1)?'+':'-';
//			DD(s);
//			DD(ff(s));
//		}
//	}
	return 0;
}



