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
		int R,C;
		cin>>R>>C;
		string v[R];
		REP(y, R)
		{
			cin>>v[y];
		}
		int ok=1;
		REP(y, R)
		{
			REP(x, C)
			{
				if(v[y][x]=='#')
				{
					if(y==R-1||x==C-1||v[y][x+1]!='#' || v[y+1][x]!='#' || v[y+1][x+1]!='#')
					{
						ok=0;
						goto END;
					}
					v[y][x]=v[y+1][x+1]='/';
					v[y+1][x]=v[y][x+1]='\\';
				}
			}
		}
		END:;
		cout<<"Case #"<<t+1<<":"<<endl;
		if(ok)
		{
			REP(y, R)
			{
				cout<<v[y]<<endl;
			}
		}
		else cout<<"Impossible"<<endl;
	}
	return 0;
}



