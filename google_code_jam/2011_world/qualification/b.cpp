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
	os<<"[";
	for( int i = 0; i < v.size(); i++ )
	{
		os << v[i] << (i==v.size()-1?"":", ");
	}
	os<<"]";
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
		vector<string> com;
		vector<string> del;
		string v;
		int nc, nd, nv;
		cin>>nc;
		REP(i, nc)
		{
			string tmp;
			cin>>tmp;
			com.PB(tmp);
		}
		cin>>nd;
		REP(i, nd)
		{
			string tmp;
			cin>>tmp;
			del.PB(tmp);
		}
		cin>>nv;
		cin>>v;
		//cout<<com<<del<<v<<endl;
		vector<char> w;
		REP(i, nv)
		{
			w.PB(v[i]);
			if(w.SZ>=2) REP(j, nc)
			{
				if(w[w.SZ-2]==com[j][0] && w[w.SZ-1]==com[j][1])
				{
					w.pop_back();
					w.pop_back();
					w.PB(com[j][2]);
				}
				if(w[w.SZ-2]==com[j][1] && w[w.SZ-1]==com[j][0])
				{
					w.pop_back();
					w.pop_back();
					w.PB(com[j][2]);
				}
			}
			if(w.SZ>=2) REP(j, nd)
			{
				if(w[w.SZ-1]==del[j][0])
				REP(k, w.SZ-1)
				{
					if(w[k]==del[j][1])
					{
						w.clear();
					}
				}
				if(w[w.SZ-1]==del[j][1])
				REP(k, w.SZ-1)
				{
					if(w[k]==del[j][0])
					{
						w.clear();
					}
				}
			}
		}
		cout<<"Case #"<<t+1<<": "<<w<<endl;;
	}
	return 0;
}

