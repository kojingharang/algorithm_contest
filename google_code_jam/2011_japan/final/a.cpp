#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
//#define B begin()
//#define E end()
#define SZ size()
#define PB(v) push_back(v)
using namespace std;
#define REP(i, n) for(int i=0, _n=(n);(i)<_n;i++)
#define FOR(i, a, b) for(int i=(a),_b=(b);(i)<_b;i++)
#define FORD(i, a, b) for(int i=(a),_b=(b);(i)>=_b;i--)
#define CLR(a) memset(a, 0, sizeof(a))
#define SORT(v) sort(v.B, v.E)
template <typename T>
void UNIQ(T& v)
{
	typename T::iterator end = unique(v.B, v.E);
	v.erase(end, v.end());
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v)
{
	for( int i = 0; i < v.size(); i++ )
	{
		os << v[i] << " ";
	}
	return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const set<T>& v)
{
	vector<T> tmp(v.B, v.E);
	os << tmp;
	return os;
}


int main()
{
	int T;
	cin>>T;
	//cout<<T<<endl;
	REP(t, T)
	{
		int K;
		cin>>K;
		VI len(K);
		
		REP(i, K) cin>>len[i];
		sort(len.begin(), len.end());
		
		double theta = 360.0/K/180*3.1415926535;
		double ans = 0.0;
		
		VI nlen(K);
		int j=0;
		REP(i, K) {
			int idx = (i+1)/2 * (i%2==0 ? 1 : -1);
			idx = (idx + K) % K;
			//cout<<i<<" "<<idx<<endl;
			nlen[idx] = len[i];
		}
		
		{
			//cout<<len<<endl;
			double sum = 0.0;
			for(int i=0;i<K;i++)
			{
				int ni = (i+1)%K;
				sum += (double)nlen[i]*nlen[ni]*0.5*sin(theta);
			}
			ans = max(ans, sum);
		}
		
		printf("Case #%d: %.7f\n", t+1, ans);
	}
	return 0;
}



