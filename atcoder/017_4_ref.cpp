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
using namespace std;

#define EPS 1e-12
#define ull unsigned long long
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
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
 
using namespace std;
typedef long long ll;
 
inline ll zgcd(ll a, ll b){
	if(a == 0){ return b; }
	if(b == 0){ return a; }
	return __gcd(llabs(a), llabs(b));
}
 
struct GCDSegmentTreeTraits {
	typedef ll value_type;
	ll default_value() const { return 0; }
	ll operator()(const ll &a, const ll &b) const { return zgcd(a, b); }
};
 
template <typename Traits>
class SegmentTree {
 
public:
	typedef typename Traits::value_type value_type;
 
private:
	Traits m_traits;
	vector<value_type> m_data;
	size_t m_size;
 
	void initialize(){
		for(int i = static_cast<int>(m_size) - 2; i >= 0; --i){
			m_data[i] = m_traits(m_data[i * 2 + 1], m_data[i * 2 + 2]);
		}
	}
 
	value_type query(int a, int b, int k, int l, int r) const {
		if(r <= a || b <= l){ return m_traits.default_value(); }
		if(a <= l && r <= b){ return m_data[k]; }
		const value_type vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		const value_type vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return m_traits(vl, vr);
	}
 
public:
	explicit SegmentTree(size_t size = 0, const Traits &traits = Traits()) :
		m_size(1), m_traits(traits)
	{
		while(m_size < size){ m_size *= 2; }
		m_data.resize(m_size * 2 - 1, m_traits.default_value());
		initialize();
	}
 
	template <typename Iterator>
	SegmentTree(
		Iterator first, Iterator last, const Traits &traits = Traits()) :
		m_size(1), m_traits(traits)
	{
		const size_t n = distance(first, last);
		while(m_size < n){ m_size *= 2; }
		m_data.resize(m_size * 2 - 1, m_traits.default_value());
		copy(first, last, m_data.begin() + m_size - 1);
		initialize();
	}
 
	void update(size_t i, const value_type &val){
		i += m_size - 1;
		m_data[i] = val;
		while(i > 0){
			i = (i - 1) / 2;
			m_data[i] = m_traits(m_data[i * 2 + 1], m_data[i * 2 + 2]);
		}
	}
 
	value_type query(size_t a, size_t b) const {
		return query(a, b, 0, 0, m_size);
	}
 
};
 
typedef SegmentTree<GCDSegmentTreeTraits> GCDSegTree;
 
template <typename T>
class BinaryIndexedTree {
 
private:
	vector<T> data;
 
public:
	BinaryIndexedTree(int n = 0) : data(n + 1) { }
 
	T sum(int i){
		T s = T();
		for(; i > 0; i -= i & -i){ s += data[i]; }
		return s;
	}
 
	void add(int i, const T &x){
		for(++i; i < static_cast<int>(data.size()); i += i & -i){
			data[i] += x;
		}
	}
 
};
 
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n), b(n + 1);
	BinaryIndexedTree<ll> bit(n + 1);
	for(int i = 0; i < n; ++i){ cin >> a[i]; }
	b[0] = a[0];
	bit.add(0, a[0]);
	for(int i = 1; i < n; ++i){
		b[i] = a[i] - a[i - 1];
		bit.add(i, b[i]);
	}
	GCDSegTree st(b.begin(), b.end());
	int m;
	cin >> m;
	while(m--){
		int t, l, r;
		cin >> t >> l >> r;
		if(t == 0){
			const ll head = bit.sum(l);
			const ll body = st.query(l, r);
			REP(ii, 4) cout<<ii<<"  "<<bit.sum(ii)<<endl;
			
			cout<<"0 1 "<<st.query(0, 1)<<endl;
			cout<<"1 2 "<<st.query(1, 2)<<endl;
			cout<<"2 3 "<<st.query(2, 3)<<endl;
			cout<<"3 4 "<<st.query(3, 4)<<endl;
			cout<<"0 2 "<<st.query(0, 2)<<endl;
			cout<<"1 3 "<<st.query(1, 3)<<endl;
			cout<<"2 4 "<<st.query(2, 4)<<endl;
			cout<<"h b "<<head<<" "<<body<<endl;
			cout << zgcd(head, body) << endl;
		}else{
			b[l - 1] += t;
			b[r] -= t;
			bit.add(l - 1, t);
			bit.add(r, -t);
			st.update(l - 1, b[l - 1]);
			st.update(r, b[r]);
		}
		cout<<"B "<<b<<endl;
	}
	return 0;
}
 
 
 

