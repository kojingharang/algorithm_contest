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
#define FOR(i, a, b) for (int i = (a), _##i = (b); i < _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define REP(i, a) for (int i = 0, _##i = (a); i < _##i; ++i)
#define REPD(i,n) for(int i = (n)-1; i >= 0; --i)
#define pb push_back

typedef long long LL;

string sa;
string s;
int a,b,l,r;
bool vis[30];

void init(){	
	REP(i,a){
		sa += string(1,'a' + i);
	}
	s = sa;
	string cur = sa;
	while(true){
		string sb;
		REP(i,b){
			sb += cur[cur.length()-1];
		}
		s+= sb;
		
		REP(i,26) vis[i] = 0;
		REP(i,a){
			vis[ s[ s.length()-1 -i ] - 'a'  ]  = true;
		}
		
		cur = "";
		int cnt = 0;
		REP(i,26){			
			if(!vis[i]){
				cnt++;	
				cur += string(1, 'a' + i);
				if(cnt == a) break;
			}			
		}		
		if(cur == sa) break;
		s+=cur;
	}
}

int cnt(string s, int start, int len){	
	REP(i,26) vis[i] = 0;
	int res = 0;
	REP(i,len){
	//	cout << start << " " << s[start] << endl;
		if(!vis[s[start] -'a' ]) res++;
		vis[s[start] -'a'] = true;
		start++;
		start %= s.length();
	}
	return res;
}

int main(){	
//	freopen("test.in","r",stdin);
	ios::sync_with_stdio(false);
	cin >> a >> b >> l >> r;
	l--,r--;
	init();
	cout << s << endl;	
	if(r-l+1 >= s.length() ) {
		cout << cnt(s,0,s.length() ) << endl;
	}else{
		cout << cnt(s,l%s.length(), r-l+1 ) << endl;
	}
	return 0;
}
	
