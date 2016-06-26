#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
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


int main()
{
	int T;
	cin>>T;
	//cout<<T<<endl;
	REP(ttt, T)
	{
		ll L,t,N,C;
		cin>>L>>t>>N>>C;
		static int v[1000000];
		REP(i, C) cin>>v[i];
		FOR(i, C, N) v[i]=v[i-C];
		//REP(i, N) cout<<v[i]<<endl;;
		
		ll mintt = -1;
		if(L==0)
		{
			ll tt=0;
			REP(i, N)
			{
				tt+=v[i]*2;
			}
			//cout<<"tt "<<tt<<endl;
			if(mintt==-1 || tt<mintt) mintt=tt;
		}
		else
		{
			static int used[1000000];
			CLR(used);
			
			REP(put, L)
			{
				int minba=-1;
				int begin = 0;
				FOR(ba, begin, N)
				{
					if(used[ba]) continue;
					
					// use in ba
					ll tt=0;
					REP(i, N)
					{
						if(i==ba||used[i])
						{
							if(t<=tt) {tt+=v[i]; if(begin<ba)begin=ba;}
							else if(t<tt+v[i]*2) {tt+= (t-tt) + v[i]-(t-tt)/2;if(begin<ba)begin=ba;}
							else tt+=v[i]*2;
						}
						else
						{
							tt+=v[i]*2;
						}
						//cout<<"tt "<<tt<<endl;
					}
					if(mintt==-1 || tt<mintt) {mintt=tt;minba=ba;}
				}
				//cout<<"mintt "<<mintt<<endl;
				used[minba]=1;
			}
		}
		
		cout<<"Case #"<<ttt+1<<": "<<mintt<<endl;
	}
	return 0;
}



