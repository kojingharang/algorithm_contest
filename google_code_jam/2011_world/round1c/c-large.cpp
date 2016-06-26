#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define VI vector<int>
#define VVI vector<vector<int> >
#define B begin()
#define E end()
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
template <typename T0, typename T1>
std::ostream& operator<<(std::ostream& os, const map<T0, T1>& v)
{
	for( typename map<T0, T1>::const_iterator p = v.begin(); p!=v.end(); p++ )
	{
		os << p->first << ": " << p->second << " ";
	}
	return os;
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

vector<vector<int> > combination(vector<int> vi, int K)
{
	sort(vi.begin(), vi.end());

	set<vector<int> > se;
	do
	{
		vector<int> tm(vi.begin(), vi.begin()+K);
		sort(tm.begin(), tm.end());
		se.insert(tm);
	}
	while(next_permutation(vi.begin(), vi.end()));
	return vector< vector<int> >(se.begin(), se.end());
}


int gcd ( int a, int b )
{
	if(a<b)
	{
		int tmp=a;
		a=b; b=tmp;
	}
	
	int c;
	while ( a != 0 ) {
	c = a; a = b%a;  b = c;
	}
	return b;
}


int main()
{
	int T;
	cin>>T;
	//cout<<T<<endl;
	REP(t, T)
	{
		ll N,L,H;
		cin>>N>>L>>H;
		ll v[N];
		REP(i, N) cin>>v[i];
		if(L<=1)
		{
			cout<<"Case #"<<t+1<<": "<<1<<endl;
			continue;
		}
		ll _gcd = 1;
		ll lcm = v[0];
		if(N>1)
		{
			_gcd = gcd(v[0], v[1]);
			FOR(i, 2, N) _gcd = gcd(_gcd, v[i]);
			
			lcm = v[0]*v[1]/gcd(v[0], v[1]);
			FOR(i, 2, N) lcm = lcm*v[i]/gcd(lcm, v[i]);
		}
		cout<<"gcd "<<_gcd<<endl;
		cout<<"lcm "<<lcm<<endl;
		
		int ok=0;
		ll ans = 1;
		
		if(_gcd<L)
		{
			if(lcm<=H) {ok=1; ans=lcm;goto END;}
		}
		else
		{
			ll tmp = _gcd;
			ll sq = (ll)sqrt((double)tmp);
			FOR(i, L, sq+1)
			{
				if(tmp%i==0) {ok=1; ans=i;goto END;}
			}
			ok=1; ans=_gcd;goto END;
		}
		
		END:;
		if(ok)
			cout<<"Case #"<<t+1<<": "<<ans<<endl;
		else
			cout<<"Case #"<<t+1<<": NO"<<endl;
	}
	return 0;
}



