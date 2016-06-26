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
#define PRINT2(table, W, H) REP(y, H) { REP(x, W) cout<<table[y][x]<<" "; cout<<"\n"; }
#define PRINT3(table, W, H, D) REP(d, D) { REP(y, H) { REP(x, W) cout<<table[d][y][x]<<" "; cout<<"\n"; } cout<<"\n"; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const pair<T0, T1>& v) { os << v.first << ": " << v.second << " "; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<vector<T> >& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << endl; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < (int)v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const deque<T>& v) { vector<T> tmp(v.begin(), v.end()); os << tmp; return os; }
//#pragma comment(linker,"/STACK:20000000")


#define MOD 1000000007LL
#define INF (1LL<<60)

typedef ll number;
//typedef double number;
typedef vector<number> array;
typedef vector<array> mat;
ll MATRIX_MOD = 0;

mat identity(int n) {
	mat A(n, array(n));
	//for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) A[i][j] = -INF;   // e for '+'
	for (int i = 0; i < n; ++i) A[i][i] = 1;  // e for '*'
	return A;
}
number inner_product(const array &a, const array &b) {
	number ans = 0;
	for (int i = 0; i < a.size(); ++i) ans += a[i] * b[i];
	return ans;
}
array operator*(const mat &A, const array &x) {
	array y(A.size());
	for (int i = 0; i < A.size(); ++i)
		for (int j = 0; j < A[0].size(); ++j) {
			y[i] += A[i][j] * x[j];
			if(MATRIX_MOD) y[i] = y[i] % MATRIX_MOD;
		}
	return y;
}
mat operator*(const mat &A, const mat &B) {
	mat C(A.size(), array(B[0].size(), 0 /* e for '+' */));
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j)
			for (int k = 0; k < A[i].size(); ++k) {
				C[i][j] = C[i][j] + A[i][k] * B[k][j];   // '+' and '*'
				//C[i][j] = max(C[i][j], A[i][k] + B[k][j]);
				if(MATRIX_MOD) C[i][j] = C[i][j] % MATRIX_MOD;
			}
	return C;
}
mat operator*(const number &A, const mat &B) {
	mat C(B.size(), array(B[0].size(), 0 /* e for '+' */));
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j) {
			C[i][j] = A * B[i][j];   // '+' and '*'
			if(MATRIX_MOD) C[i][j] = C[i][j] % MATRIX_MOD;
		}
	return C;
}
mat operator+(const mat &A, const mat &B) {
	mat C(A.size(), array(A[0].size(), 0 /* e for '+' */));
	for (int i = 0; i < C.size(); ++i)
		for (int j = 0; j < C[i].size(); ++j) {
			C[i][j] = A[i][j] + B[i][j];   // '+' and '*'
			//C[i][j] = max(A[i][k], B[k][j]);
			if(MATRIX_MOD) C[i][j] = C[i][j] % MATRIX_MOD;
		}
	return C;
}
// O( n^3 log e )
mat pow(const mat &A, int e) {
	return e == 0 ? identity(A.size()):
		 e % 2 == 0 ? pow(A*A, e/2) : A * pow(A, e-1);
}
mat powsum(const mat &A, int e) { // A^1+..+A^2n = (E+A^n)(A^1+..+A^n), 1+..+A(2n+1) = A(A^1+..+A^n)+A
	return e == 0 ? mat(A.size(), array(A.size())) : 
		 e % 2 == 0 ? (identity(A.size()) + pow(A, e/2)) * powsum(A, e/2) : A * powsum(A, e-1) + A;
}
bool operator==(const mat &A, const mat &B) {
	if(A.size()!=B.size()) return false;
	REP(i, A.size()) if(A[i].size()!=B[i].size()) return false;
	REP(i, A.size()) REP(j, A[i].size()) if(A[i][j]!=B[i][j]) return false;
	return true;
}
std::ostream& operator<<(std::ostream& os, const mat& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << "\n"; } return os; }

int main() {
	//ios::sync_with_stdio(false);
	ll N,M;
	while(cin>>N>>M) {
		//ll v=2;
		//REP(i, N-1) {
		//	v = (3*v+2)%M;
		//}
		//cout<<v<<endl;
		
		MATRIX_MOD = M;
		mat m(2, array(2));
		m[0][0]=3;
		m[0][1]=2;
		m[1][0]=0;
		m[1][1]=1;
		array i0(2);
		i0[0]=2;
		i0[1]=1;
		//REP(i, N-1) {
		//	i0 = m * i0;
		//	//cout<<i<<" "<<i0<<endl;
		//}
		i0 = pow(m, N-1) * i0;
		cout<<i0[0]<<endl;
	}
	
	return 0;
}
