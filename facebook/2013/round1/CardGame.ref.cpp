#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define MOD 1000000007

int C[10010][10010];

void pre(void){
	int i,j;
	REP(i,10010) REP(j,i+1){
		if(j == 0 || j == i) C[i][j] = 1;
		else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
}

ll a[10010];

void main2(void){
	int N,K,i;
	
	cin >> N >> K;
	REP(i,N) cin >> a[i];
	sort(a, a+N);
	
	ll ans = 0;
	for(i=K-1;i<N;i++){
		ll x = a[i] % MOD;
		ll coef = C[i][K-1];
		ans = (ans + x * coef) % MOD;
	}
	
	cout << ans << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int main(void){
	int TC,tc;
	pre();
	scanf("%d", &TC);
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
