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


ll gcd ( ll a, ll b )
{
	if(a<b)
	{
		ll tmp=a;
		a=b; b=tmp;
	}
	
	ll c;
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
	REP(ttt, T)
	{
		ll N;
		cin>>N;
		
		ll call0 = 0;
		{
			map<ll, int> m;
			for(ll i=1;i<=N;i++)
			{
				//cout<<"i "<<i<<endl;
				
				ll tmp = i;
				ll limit = (ll)sqrt((double)tmp);
				//cout<<limit<<endl;
				int htc=0;
				for(ll j=1; j<=tmp; j++)
				{
					int cc=0;
					if(j==1) cc++;
					else while(tmp%j==0) {
						//cout<<j<<" ";
						tmp/=j;
						cc++;
					}
					if(cc>0 && m.find(j)==m.end() || m[j]<cc)
					{
						if(m.find(j)==m.end()) m[j]=0;
						m[j]=cc;
						htc=1;
					}
				}
				if(htc) call0++;
				//cout<<endl;
				//cout<<m<<endl;
				//if(tmp!=total) mincall++;
				//cout<<" "<<call0<<endl;
			}
		}
		ll call1 = 0;
		{
			map<ll, int> m;
			for(ll i=N;i>=1;i--)
			{
				//cout<<"i "<<i<<endl;
				
				ll tmp = i;
				ll limit = (ll)sqrt((double)tmp);
				//cout<<limit<<endl;
				int htc=0;
				for(ll j=1; j<=tmp; j++)
				{
					int cc=0;
					if(j==1) cc++;
					else while(tmp%j==0) {
						//cout<<j<<" ";
						tmp/=j;
						cc++;
					}
					if(cc>0 && m.find(j)==m.end() || m[j]<cc)
					{
						if(m.find(j)==m.end()) m[j]=0;
						m[j]=cc;
						htc=1;
					}
				}
				if(htc) call1++;
				//cout<<endl;
				//cout<<m<<endl;
				//if(tmp!=total) mincall++;
				//cout<<" "<<call1<<endl;
			}
		}
		//cout<<"result ---  "<<maxcall<<" "<<mincall<<endl;
		cout<<"Case #"<<ttt+1<<": "<<(call0-call1)<<endl;
	}
	return 0;
}



