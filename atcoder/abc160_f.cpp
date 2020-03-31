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

template<ll MODVAL>
struct Modll {
	ll val;
	Modll() : val(0) {}
	Modll(ll v) : val(v) { normalize(); }
	void normalize() { val = (val+MODVAL) % MODVAL; }
	Modll  operator+ (ll v) { return Modll(val+v); }
	Modll& operator+=(ll v) { val+=v; normalize(); return *this; }
	Modll  operator- (ll v) { return Modll(val-v); }
	Modll& operator-=(ll v) { val-=v; normalize(); return *this; }
	Modll  operator* (ll v) { return Modll(val*v); }
	Modll& operator*=(ll v) { val*=v; normalize(); return *this; }
	Modll  operator^ (ll e) { Modll x(val); Modll v(1); for(;e;x=x*x,e>>=1) if(e&1) v = v * x; return v; } // pow
	Modll inv() { Modll x(val); return x^(MODVAL-2); } // MODVAL must be prime number when use this!
	static Modll inv(ll v) { return Modll(v).inv(); }
	operator ll() { return val; }
};
template<ll MODVAL>
std::ostream& operator<<(std::ostream& os, const Modll<MODVAL>& v) { os << v.val; return os; }
using modll = Modll<1000000007>;


#define MAXN 200010
modll facts[MAXN];
modll inv_facts[MAXN];
// Call gen_facts() before call this
ll modC(ll n, ll r) {
	assert(0<=n && n<MAXN); assert(0<=r && r<=n);
	return modll(facts[n]) * inv_facts[r] * inv_facts[n-r];
}
void gen_facts() {
	facts[0] = 1;
	inv_facts[0] = modll::inv(facts[0]);
	RANGE(i, 1, MAXN) facts[i] = facts[i-1] * modll(i);
	RANGE(i, 1, MAXN) inv_facts[i] = inv_facts[i-1] * modll::inv(i);
	REP(i, MAXN) assert((facts[i] * inv_facts[i])==1);
}

/*
https://github.com/key-moon/Library/blob/master/src/Algorithm/rerooting.csx
keymoon による C# の実装を noshi91 が C++ に移植したものです
verified with https://atcoder.jp/contests/abc160/tasks/abc160_f
*/

#include <functional>
#include <stack>
#include <vector>

template <class T> class ReRooting {
public:
    int NodeCount;

private:
    std::vector<std::vector<int>> Adjacents;
    std::vector<std::vector<int>> IndexForAdjacent;

    std::vector<T> Res;
    std::vector<std::vector<T>> DP;

    T Identity;
    std::function<T(T, T)> Operate;
    std::function<T(T, int)> OperateNode;

public:
    ReRooting(int nodeCount, std::vector<std::vector<int>> edges, T identity,
                std::function<T(T, T)> operate,
                std::function<T(T, int)> operateNode) {
        NodeCount = nodeCount;

        Identity = identity;
        Operate = operate;
        OperateNode = operateNode;

        std::vector<std::vector<int>> adjacents(nodeCount);
        std::vector<std::vector<int>> indexForAdjacents(nodeCount);

        for (int i = 0; i < edges.size(); i++) {
            auto &edge = edges[i];
            indexForAdjacents[edge[0]].push_back(adjacents[edge[1]].size());
            indexForAdjacents[edge[1]].push_back(adjacents[edge[0]].size());
            adjacents[edge[0]].push_back(edge[1]);
            adjacents[edge[1]].push_back(edge[0]);
        }

        Adjacents = std::vector<std::vector<int>>(nodeCount);
        IndexForAdjacent = std::vector<std::vector<int>>(nodeCount);
        for (int i = 0; i < nodeCount; i++) {
            Adjacents[i] = adjacents[i];
            IndexForAdjacent[i] = indexForAdjacents[i];
        }

        DP = std::vector<std::vector<T>>(Adjacents.size());
        Res = std::vector<T>(Adjacents.size());

        for (int i = 0; i < Adjacents.size(); i++)
            DP[i] = std::vector<T>(Adjacents[i].size());
        if (NodeCount > 1)
            Initialize();
        else if (NodeCount == 1)
            Res[0] = OperateNode(Identity, 0);
    }

    T Query(int node) { return Res[node]; }

private:
    void Initialize() {
        std::vector<int> parents(NodeCount);
        std::vector<int> order(NodeCount);

#pragma region InitOrderedTree
        int index = 0;
        std::stack<int> stack;
        stack.push(0);
        parents[0] = -1;
        while (stack.size() > 0) {
            auto node = stack.top();
            stack.pop();
            order[index++] = node;
            for (int i = 0; i < Adjacents[node].size(); i++) {
                auto adjacent = Adjacents[node][i];
                if (adjacent == parents[node])
                    continue;
                stack.push(adjacent);
                parents[adjacent] = node;
            }
        }
#pragma endregion

#pragma region fromLeaf
        for (int i = order.size() - 1; i >= 1; i--) {
            auto node = order[i];
            auto parent = parents[node];

            T accum = Identity;
            int parentIndex = -1;
            for (int j = 0; j < Adjacents[node].size(); j++) {
                if (Adjacents[node][j] == parent) {
                    parentIndex = j;
                    continue;
                }
                accum = Operate(accum, DP[node][j]);
            }
            DP[parent][IndexForAdjacent[node][parentIndex]] =
                OperateNode(accum, node);
        }
#pragma endregion

#pragma region toLeaf
        for (int i = 0; i < order.size(); i++) {
            auto node = order[i];
            T accum = Identity;
            std::vector<T> accumsFromTail(Adjacents[node].size());
            accumsFromTail[accumsFromTail.size() - 1] = Identity;
            for (int j = accumsFromTail.size() - 1; j >= 1; j--)
                    accumsFromTail[j - 1] = Operate(DP[node][j], accumsFromTail[j]);
            for (int j = 0; j < accumsFromTail.size(); j++) {
                DP[Adjacents[node][j]][IndexForAdjacent[node][j]] =
                    OperateNode(Operate(accum, accumsFromTail[j]), node);
                accum = Operate(accum, DP[node][j]);
            }
            Res[node] = OperateNode(accum, node);
        }
#pragma endregion
    }
};


struct NV {
	modll v;
	int size;
	bool div;
};
int main() {
	gen_facts();
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll N,A,B;
	while(cin>>N) {
		vector<vector<int>> edges;
		REP(i, N-1) {
			cin>>A>>B;
			A--;B--;
			edges.PB(vector<int>{(int)A, (int)B});
		}
		auto mergeFun = [&](NV a, NV b) -> NV {
			modll v = a.v * b.v;
			if(!a.div) v *= inv_facts[a.size];
			if(!b.div) v *= inv_facts[b.size];
			return NV{
				v,
				a.size + b.size,
				true,
			};
		};
		auto nodeFun = [&](NV a, int idx) -> NV {
			return NV{a.v * facts[a.size], a.size+1, false};
		};
		ReRooting<NV> rr(N, edges, NV{1LL, 0, false}, mergeFun, nodeFun);
		REP(i, N) {
			cout<<rr.Query(i).v<<endl;
		}
	}
	
	return 0;
}
