#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define INF 100000000ll

int N;
ll X[800010],H[800010];
set <pair <ll, ll> > s;

void init(void){
	s.clear();
	s.insert(make_pair(-INF, 0));
	s.insert(make_pair(INF, 0));
}

double get_area(pair <ll, ll> L, pair <ll, ll> R){
	double HL = L.second;
	double HR = R.second;
	double D = R.first - L.first;
	
	if(D > HL + HR) return HL * HL / 2.0 + HR * HR / 2.0;
	
	double center = (HL - HR + D) / 2.0;
	double ans = 0.0;
	ans += (HL + HL - center) * center / 2.0;
	ans += (HL - center + HR) * (D - center) / 2.0;
	return ans;
}

double get_diff(pair <ll, ll> P){
	__typeof(s.begin()) itr = s.find(P);
	
	itr--;
	pair <ll, ll> L = (*itr);
	itr++; itr++;
	pair <ll, ll> R = (*itr);
	
	return get_area(L, P) + get_area(P, R) - get_area(L, R);
}

double query(ll x, ll y){ // cerr << x << ' ' << y << endl;
	double diff = 0.0;
	
	while(1){
		__typeof(s.begin()) itr;
		itr = s.lower_bound(make_pair(x, y));
		pair <ll, ll> R = (*itr);
		itr--;
		pair <ll, ll> L = (*itr);
		
		if(y <= R.second - (R.first - x)) return 0.0;
		if(y <= L.second - (x - L.first)) return 0.0;
		
		if(R.second <= y - (R.first - x)){
			diff += get_diff(R);
			s.erase(R);
			continue;
		}
		
		if(L.second <= y - (x - L.first)){
			diff += get_diff(L);
			s.erase(L);
			continue;
		}
		
		double old_area = get_area(L, R);
		
		pair <ll, ll> M = make_pair(x, y);
		s.insert(M);
		
		double new_area = get_area(L, M) + get_area(M, R);
		
		return new_area - (old_area + diff);
	}
}

/*
int a[20000];

void brute(void){
	int i,j;
	double ans = 0.0;
	
	REP(i,N){
		REP(j,20000) a[j] = 0;
		REP(j,i+1) a[X[j]+500] = max(a[X[j]+500], (int)H[j]);
		REP(j,19999) a[j+1] = max(a[j+1], a[j] - 1);
		REP(j,19999) a[19999-j-1] = max(a[19999-j-1], a[19999-j] - 1);
		REP(j,19999){
			int L = a[j];
			int R = a[j+1];
			ans += (L + R) / 2.0;
			if(L == R && L > 0) ans -= 0.25;
		}
	}
	
	printf("%.9f\n", ans);
}
*/

void main2(void){
	int i;
	
	s.clear();
	
	cin >> N;
	
	ll X1,AX,BX,CX;
	cin >> X1 >> AX >> BX >> CX;
	X[0] = X1;
	for(i=1;i<N;i++) X[i] = (X[i-1] * AX + BX) % CX + 1;
	
	ll H1,AH,BH,CH;
	cin >> H1 >> AH >> BH >> CH;
	H[0] = H1;
	for(i=1;i<N;i++) H[i] = (H[i-1] * AH + BH) % CH + 1;
	
	// testing
//	N = 800000;
//	REP(i,N) X[i] = rand() % 10000000;
//	REP(i,N) H[i] = rand() % 100000;
	// testing
	
	init();
	
	double ans = 0.0, area = 0.0;
	REP(i,N){
		double tmp = query(X[i], H[i]);
		area += tmp;
		ans += area;
	//	cerr << area << endl;
	}
	
	// testing
//	brute();
	// testing
	
	printf("%.9f\n", ans);
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc + 1);
		main2();
	}
	return 0;
}
