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

#define MOD 1000000007LL
#define INF (1LL<<60)

/*
方針:

変化量 = 0
varDiff[i]: i 回目の始めに var が変化する分.
deltaDiff[i]: i 回目の始めに変化量が変化する分
var = rot0でのスコア
loop
	var += 変化量 + varDiff[i]
	変化量 += deltaDiff[i]


5
5 4 3 2 1
での想定動作

0
	-1 -1 -1 -1  1
	deltaDiff
	-1  0  0  0  1
1
	-1 -1  1  1 -1
	deltaDiff
	-1  0  2  0 -2
2
	 1  1  1 -1 -1
	deltaDiff
	 1  0  0 -2  0
3
	 1  1 -1  1  1
	deltaDiff
	 1  0 -2  2  0
4
	 1  1  1  1  1
	deltaDiff
	 1  0  0  0  0

sum
	 1  1  1  1  1



12
8
	12 += -5 +1
6
	8 += -3 +1
6
	6 += -1 +1
8
	6 += +1 +1


0
	p   o
	 p o
	  p
	 o p
	o   p

	delta
		0 -1
		1 -1
		2  1
		3  1
		4  1
		sum 1

1
	 p  o
	  po
	  op
	 o  p
	p

	delta
		0 -1
		1 -1
		2  1
		3  1
		4  1
		sum 1

2
	  p o
	   p
	  o p
	po   
	op

	delta
		0 -1
		1  1
		2  1
		3 -1
		4  1
		sum 1

3
	   po
	   op
	p o  
	 p   
	o p

	delta
		0 -1
		1  1
		2 -1
		3  1
		4  1
		sum 1

4
		p
	p  o 
	 po  
	 op  
	o  p

	delta
		0  1
		1 -1
		2 -1
		3  1
		4  1
		sum 1





*/

void naive(ll N, const VI& w, ll& minVar, ll& ans) {
	auto f = [&](int ci) {
		ll v = 0;
		REP(i, N) {
			int ni = (i+ci+N)%N+1;
//			DD(ni);
			v += abs(ni-w[i]);
		}
//		DD(v);
		return v;
	};
	minVar = 1LL<<60;
	REP(ci, N) {
		ll v = f(ci);
		DD(v);
		if(v < minVar) {
			minVar = v;
			ans = ci;
		}
	}
}

void solveSimple(ll N, const VI& ww, ll& minVar, ll& ans) {
	VI w(ww);
	REP(i, N) w[i]--;

	VI dd(N*2);
	ll geq = 0, le = 0;
	ll sum = 0;
	REP(i, N) {
		sum += abs(w[i]-i);
		if(w[i]>=i) geq++; else le++;
		if(w[i]>=i) dd[w[i]-i]++;
	}
	minVar = sum, ans = 0;
	REP(i, N) {
		geq-=dd[i]; le+=dd[i];
		sum = sum - geq + le;
		sum = sum - (N-w[N-1-i]) + w[N-1-i];
		if(sum<minVar) minVar=sum,ans=i+1;
		le--;geq++;
		dd[w[N-1-i]+i+1]++;
	}
}


void solve(ll N, const VI& w, ll& minVar, ll& ans) {
	VI varDiff(N+10), deltaDiff(N+10);
	ll var = 0;
	REP(i, N) {
//			VI dd(deltaDiff.size());
		VI& dd = deltaDiff;
		if(w[i]>i+1) {
			// 最初 -1 で idx1 のときに +1 になる. また idx3 で -1 になる
			dd[0] += -1;

			int idx1 = w[i]-(i+1);
			dd[idx1] += +2;

			int idx3 = N-(i+1)+1;
			dd[idx3] += -2;

//			cout<<"deltaDiff: 0 += -1"<<endl;
//			cout<<"deltaDiff: "<<idx1<<" += "<<2<<endl;
//			cout<<"deltaDiff: "<<idx3<<" += -2"<<endl;
		} else {
			// 最初 +1 で idx1 のときに -1 になる. また idx3 で +1 になる
			dd[0] += +1;

			int idx1 = N-((i+1)-w[i]);
			dd[idx1] += +2;

			int idx3 = N-(i+1)+1;
			dd[idx3] += -2;

//			cout<<"deltaDiff: 0 += +1"<<endl;
//			cout<<"deltaDiff: "<<idx1<<" += "<<2<<endl;
//			cout<<"deltaDiff: "<<idx3<<" += -2"<<endl;
		}
//			DD(dd);
//			VI acc(dd.size());
//			REP(i, dd.size()) {
//				acc[i] = (i-1>=0 ? acc[i-1] : 0) + dd[i];
//			}
//			DD(acc);
//			REP(i, deltaDiff.size()) deltaDiff[i] += dd[i];

		{
			// 回転した瞬間に var が調整される
			int idx = N-(i+1)+1;
			ll v = -(N-(w[i]-1)) + (w[i]-1);
			varDiff[idx] += v;
//				cout<<"varDiff: "<<idx<<" += "<<v<<endl;
		}
		var += abs(w[i]-(i+1));
	}
//		DD(var);
//		DD(varDiff);
//		DD(deltaDiff);
	minVar = var;
	ans = 0;
	ll delta = deltaDiff[0];
//	VI vars(N);
//	vars[0] = var;
	RANGE(i, 1, N) {
//			cout<<var<<" += "<<varDiff[i]<<" + "<<delta<<endl;
		var += varDiff[i] + delta;
		delta += deltaDiff[i];
//			DD(delta);
//			DD(var);
		if(var<minVar) {
			minVar = var;
			ans = i;
		}
//		vars[i] = var;
	}
	// 単調性はあるか実験してみたが、長さ 1000 くらいでやったら全然なかった。
//	DD(vars);
//	vector<bool> diffs(N-1);
//	RANGE(i, 1, N) {
//		ll diff = vars[i]-vars[i-1];
//		diffs[i-1] = diff >= 0;
//	}
//	DD(diffs);
//	diffs.erase(unique(ALL(diffs)), diffs.end());
//	DD(diffs);
}


int main() {
//	if(0)
	{
		int N = 100;
		VI w(N);
		ll ans, minVar;
		ll ans2, minVar2;
		REP(i, N) w[i]=i+1;
		REP(i, 1000) {
			random_shuffle(ALL(w));
			solve(N, w, minVar, ans);
			solveSimple(N, w, minVar2, ans2);
			DD(minVar);
			DD(ans);
			DD(minVar2);
			DD(ans2);
			assert(minVar==minVar2);
			assert(ans==ans2);
		}
		return 0;
	}

	ios::sync_with_stdio(false);
	ll N;
	while(cin>>N) {
		VI w(N);
		REP(i, N) cin>>w[i];
		ll minVar, ans;
		solve(N, w, minVar, ans);
		cout<<minVar<<" "<<ans<<endl;

//		naive(N, w, minVar, ans);
//		cout<<"NAIVE "<<minVar<<" "<<ans<<endl;

//		DD(w);
		
//		DD("aaaa");
//		ll ans = 0;
//		REP(zi, 3) {
//			VI h(3);
//			REP(i, 3) {
//				h[i] = f((N/3*(i+zi))%N);
//			}
////			DD(zi);
////			DD(h);
//			if(h[0]>=h[1] && h[1]<=h[2]) {
//				ll L = (N/3*(zi))%N;
//				ll R = L+N-1;
//				while(L+10<R) {
////					DD(L);DD(R);
//					ll a = f((L+(R-L+1)*1/3)%N);
//					ll b = f((L+(R-L+1)*2/3)%N);
////					DD(a);DD(b);
//					if(a<=b) {
//						R = L+(R-L+1)*2/3;
//					} else {
//						L = L+(R-L+1)*1/3;
//					}
//				}
////				DD(L);DD(R);
//				ll mi = 1LL<<60;
//				RANGE(i, L, R+1) {
//					ll v = f(i%N);
////					DD(i%N);
////					DD(v);
//					if(v<mi) {
//						mi = v;
//						ans = i%N;
//					}
//				}
////				DD(ans);
//				break;
//			}
//		}
		
//		cout<<f(ans%N)<<" "<<ans<<endl;
//		break;
	}
	
	return 0;
}
