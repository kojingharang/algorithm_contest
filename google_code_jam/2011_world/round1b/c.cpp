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
		int N,M;
		cin>>N>>M;
		int fr[M], to[M];
		CLR(fr);
		CLR(to);
		REP(i, M) cin>>fr[i];
		REP(i, M) cin>>to[i];
		
		VVI rooms;
		VI init;
		REP(i, N) init.PB(i+1);
		rooms.push_back(init);
		REP(j, M)
		{
			REP(i, rooms.size())
			{
				vector<int>::iterator pos0 = find(rooms[i].begin(), rooms[i].end(), to[j]);
				vector<int>::iterator pos1 = find(rooms[i].begin(), rooms[i].end(), fr[j]);
				if(pos0!=rooms[i].end() && pos1!=rooms[i].end())
				{
					// split
				}
			}
		}
		
		int min_edges = 10000000;
		REP(i, N)
		{
			int edges=2;
			REP(j, M)
			{
				//cout<<fr[j]<<" "<<to[j]<<endl;
				if(i+1==fr[j] || i+1==to[j])
				{
					edges++;
				}
			}
			if(min_edges>edges) min_edges=edges;
		}
		int col[N];
		REP(i, N) col[i]=-1;
		if(0)
		FORD(cols, min_edges+1, 1)
		{
			cout<<"cols "<<cols<<endl;
			ll all = 1;
			REP(i, N) all *= cols;
			cout<<"all "<<all<<endl;
			for(ll v=0; v<all; v++)
			{
				// try
				ll tmp=v;
				REP(i, N)
				{
					col[i] = tmp%cols;
					tmp/=cols;
				}
				REP(i, N) cout<<col[i]<<" ";
				cout<<endl;
				
				// valid?
				int ok0=1;
				REP(i, N)
				{
					int used[cols];
					CLR(used);
					int prev=(i-1+N)%N;
					int next=(i+1)%N;
					used[col[prev]]++;
					used[col[next]]++;
					REP(j, M)
					{
						//cout<<fr[j]<<" "<<to[j]<<endl;
						if(i+1==fr[j]) used[col[to[j]-1]]++;
						if(i+1==to[j]) used[col[fr[j]-1]]++;
					}
					int ok=1;
					cout<<"used: ";
					REP(j, cols)
					{
						cout<<used[j]<<" ";
						if(used[j]==0) ok=0;
					}
					cout<<endl;
					if(!ok)
					{
						ok0=0;
						break;
					}
				}
				if(ok0)
				{
					cout<<"Case #"<<t+1<<": "<<cols<<endl;;
					REP(j, N) cout<<col[j]+1<<" ";
					cout<<endl;
					goto found;
				}
			}
		}
found:;
		
		//cout<<"Case #"<<t+1<<": "<<min_edges<<endl;;
	}
	return 0;
}



