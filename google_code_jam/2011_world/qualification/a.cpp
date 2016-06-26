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
	REP(t, T)
	{
		int ans = 0;
		VVI d;
		d.PB(VI());
		d.PB(VI());
		
		int N;
		cin>>N;
		
		REP(i, N)
		{
			char col;
			int loc;
			cin>>col>>loc;
			//cout<<col<<loc<<endl;
			int ci = col=='O'?0:1;
			d[ci].PB(i);
			d[ci].PB(loc);
		}
		//cout<<d<<endl;
		int pi = 0;
		int ci[2];
		int cur[2];
		ci[0]=ci[1]=0;
		cur[0]=cur[1]=1;
		REP(step, 100*100)
		{
			int pushed = 0;
			int end = 1;
			REP(col, 2)
			{
				if(ci[col]>=d[col].size()/2) continue;
				end = 0;
				
				int p = d[col][ci[col]*2+0];
				int loc = d[col][ci[col]*2+1];
				if(cur[col]==loc)
				{
					if(pi==p)
					{
						//cout<<col<<" push "<<cur[col]<<endl;
						pushed=1;
						ci[col]++;
					}
					else
					{
						//cout<<col<<" stay"<<endl;
					}
				}
				else
				{
					int dir = loc - cur[col] > 0 ? 1 : -1;
					cur[col]+=dir;
					//cout<<col<<" move to "<<cur[col]<<endl;
				}
			}
			if(pushed) pi++;
			if(end) break;
			ans++;
		}
		cout<<"Case #"<<t+1<<": "<<ans<<endl;;
	}
	return 0;
}



