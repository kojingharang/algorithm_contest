#line 90 "MagicWords.cpp"

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define REP(i,n) for(int i=0,_n=(n);(i)<_n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
template <typename T0, typename T1> std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v) { for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ ){os << p->first << ": " << p->second << " ";} return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& v) { for( int i = 0; i < v.size(); i++ ) { os << v[i] << " "; } return os; }
template <typename T> std::ostream& operator<<(std::ostream& os, const set<T>& v) { vector<T> tmp(v.B, v.E); os << tmp; return os; }



class MagicWords {
	public:
	int count(vector <string> S, int K) {
		int N=S.size();
		VI p(N);
		REP(i, N) p[i]=i;
		int L = 0;
		REP(i, N) L+=S[i].size();
		if(L%K==0) {
			int ans = 0;
			do {
				string s = "";
				REP(i, N) s+=S[p[i]];
				for(int l=1;l<=L;l++) {
					if(L%l!=0) continue;
					int k=L/l;
					int ok=1;
					REP(i, L/k) REP(j, k) if(s[i]!=s[j*L/k+i]) ok=0;
					if(ok) {
						if(k==K) ans++;
						break;
					}
				}
				//cout<<s<<"  "<<ok<<endl;
			} while(next_permutation(ALL(p)));
			return ans;
		}
		return 0;
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
